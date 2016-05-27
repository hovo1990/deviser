#!/usr/bin/env python
#
# @file    JavaHeaderFile.py
# @brief   class for generating header file for the given class
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2015 by the California Institute of Technology
# (California, USA), the European Bioinformatics Institute (EMBL-EBI, UK)
# and the University of Heidelberg (Germany), with support from the National
# Institutes of Health (USA) under grant R01GM070923.  All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#
# Neither the name of the California Institute of Technology (Caltech), nor
# of the European Bioinformatics Institute (EMBL-EBI), nor of the University
# of Heidelberg, nor the names of any contributors, may be used to endorse
# or promote products derived from this software without specific prior
# written permission.
# ------------------------------------------------------------------------ -->

from base_files import BaseJavaFile
from . java_functions import *
from util import query, global_variables


class JavaHeaderFile(BaseJavaFile.BaseJavaFile):
    """Class for all Cpp Header files"""

    def __init__(self, class_object, represents_class=True):

        self.brief_description = \
            'Definition of the {0} class.'.format(class_object['name'])
        BaseJavaFile.BaseJavaFile.__init__(self, class_object['name'], 'h',
                                         class_object['attribs'])

        # members from object
        self.represents_class = represents_class
        if represents_class:
            self.expand_class(class_object)
    ########################################################################

    # Functions for writing the class
    def write_class(self, base_class, class_name, attributes):
        self.write_forward_class()

        if base_class:
            self.write_line('class {0}_EXTERN {1} : public {2}'
                            .format(self.library_name.upper(),
                                    class_name, base_class))
        else:
            self.write_line('class {0}_EXTERN {1}'
                            .format(self.library_name.upper(),
                                    class_name))
        self.write_line('{')
        if len(attributes) > 0 or self.overwrites_children:
            self.write_line('protected:')
            self.up_indent()
            self.write_doxygen_start()
            self.write_data_members(attributes)
            self.write_doxygen_end()
            self.down_indent()
        else:
            self.skip_line()
        self.write_line('public:')
        self.skip_line()
        self.up_indent()
        self.write_constructors()
        self.write_attribute_functions()
        self.write_child_element_functions()
        self.write_listof_functions()
        self.write_child_lo_element_functions()
        self.write_concrete_functions()
        self.write_general_functions()
        self.write_functions_to_retrieve()
        if self.document:
            self.write_document_error_log_functions()
        self.down_indent()
        self.write_line('protected:')
        self.skip_line()
        self.up_indent()
        self.write_protected_functions()
        self.down_indent()
        if self.add_decls is not None and not self.is_list_of:
            self.copy_additional_file(self.add_decls)
            self.skip_line(2)
        self.write_line('};\n')

    def write_c_header(self):
        self.is_java_api = False
        if not self.is_list_of:
            self.write_constructors()
            self.write_attribute_functions()
            self.write_child_element_functions()
            self.write_child_lo_element_functions()
            self.write_concrete_functions()
            self.write_general_functions()
        else:
            self.write_attribute_functions()
            self.write_listof_functions()

    ########################################################################
    # Functions for writing specific includes and forward declarations

    def write_forward_class(self):
        if len(self.concretes) == 0:
            return
        for element in self.concretes:
            self.write_line('class {0};'.format(element['element']))
        self.skip_line()

    def write_common_includes(self):
        self.write_line_verbatim('#include <{0}/common/'
                                 'extern.h>'.format(self.language))
        if not self.is_plugin:
            self.write_line_verbatim('#include <{0}/common/{0}fwd.'
                                     'h>'.format(self.language))
            if global_variables.is_package:
                self.write_line_verbatim('#include <{0}/packages/{1}/common/'
                                         '{1}fwd.'
                                         'h>'.format(self.language,
                                                     self.package.lower()))

    def write_general_includes(self):
        pkg = self.package.lower()
        include_lines = []
        skip = False
        if not self.is_plugin:
            self.write_line_verbatim('#include <string>')
            skip = True
        if self.class_object['has_vector']:
            self.write_line_verbatim('#include <vector>')
            skip = True
        if skip:
            self.skip_line(2)

        # write the base class header
        if self.baseClass:
            base = self.baseClass
            if global_variables.is_package:
                if self.has_std_base:
                    if not self.is_plugin:
                        base_file = '{0}/{1}'.format(self.language, base)
                    else:
                        base_file = '{0}/extension/{1}'.format(self.language,
                                                               base)
                else:
                    base_file = '{0}/packages/{1}/{0}/{2}'.format(self.language,
                                                                  pkg, base)
            else:
                base_file = '{0}/{1}'.format(self.language, self.baseClass)
            include_lines += ['<{0}.h>'.format(base_file)]

        # work out if we need the extension header
        need_extension = False
        if global_variables.is_package:
            if self.is_doc_plugin:
                need_extension = True
            elif not self.is_plugin:
                need_extension = True
            elif self.is_plugin and not self.has_children:
                need_extension = True
        if need_extension:
            include_lines += ['<{0}/packages/{1}/extension/{2}Extension'
                              '.h>'.format(self.language, pkg, self.package)]

        # additional includes for child elements
        for i in range(0, len(self.child_elements)):
            child = self.child_elements[i]['element']
            if child != 'ASTNode' and child != 'XMLNode':
                if global_variables.is_package:
                    include_lines += ['<{0}/packages/{1}/{0}/{2}'
                                      '.h>'.format(self.language, pkg, child)]
                else:
                    include_lines += ['<{0}/{1}.h>'.format(self.language,
                                                           child)]
            else:
                if child == 'ASTNode':
                    include_lines += ['<sbml/math/ASTNode.h>']
                elif child == 'XMLNode':
                    include_lines += ['<sbml/xml/XMLNode.h>']

        for i in range(0, len(self.child_lo_elements)):
            child = self.child_lo_elements[i]['attTypeCode']
            if global_variables.is_package:
                include_lines += ['<{0}/packages/{1}/{0}/{2}'
                                  '.h>'.format(self.language, pkg, child)]
            else:
                include_lines += ['<{0}/{1}.h>'.format(self.language, child)]
            if self.is_plugin:
                child = self.child_lo_elements[i]['element']
                include_lines += ['<{0}/packages/{1}/{0}/{2}'
                                  '.h>'.format(self.language, pkg, child)]

        # if we are a list of we need the header of our child object
        if self.is_list_of:
            child = self.list_of_child
            if global_variables.is_package:
                include_lines += ['<{0}/packages/{1}/{0}/{2}'
                                  '.h>'.format(self.language, pkg, child)]
            else:
                include_lines += ['<{0}/{1}.h>'.format(self.language, child)]

        # if we are the document class for another library
        if not global_variables.is_package and self.document:
            include_lines += ['<{0}/{1}ErrorLog.h>'.format(self.language, global_variables.prefix)]

        # if we another library we need the libsbml ns qualifier
        if not global_variables.is_package:
            include_lines += ['<sbml/common/libsbml-namespace.h>']


        # write them out
        for line in include_lines:
            self.write_line_verbatim('#include {0}'.format(line))

    ########################################################################

    # function to write the data members
    def write_data_members(self, attributes):
        names_written = []
        for i in range(0, len(attributes)):
            name = attributes[i]['memberName']
            return_type = attributes[i]['attTypeCode']
            if name not in names_written:
                if attributes[i]['attType'] != 'string':
                    self.write_line('{0} {1};'.format(return_type, name))
                else:
                    self.write_line('std::string {0};'.format(name))
                if attributes[i]['isNumber'] is True \
                        or attributes[i]['attType'] == 'boolean':
                    self.write_line('bool mIsSet{0};'
                                    .format(attributes[i]['capAttName']))
                names_written.append(name)
        if self.overwrites_children:
            self.write_line('std::string mElementName;')
        if self.document:
            self.write_line('{0}ErrorLog mErrorLog;'.format(global_variables.prefix))

    ########################################################################

    # function to write the constructors
    def write_constructors(self):
        constructor = Constructors.Constructors(self.language,
                                                self.is_java_api,
                                                self.class_object)
        if self.is_java_api and not self.is_plugin:
            code = constructor.write_level_version_constructor()
            self.write_function_declaration(code)

            code = constructor.write_namespace_constructor()
            self.write_function_declaration(code)
        elif self.is_plugin:
            code = constructor.write_uri_constructor()
            self.write_function_declaration(code)
        elif self.has_std_base:
            for i in range(0, len(self.concretes)+1):
                code = constructor.write_level_version_constructor(i)
                self.write_function_declaration(code)
        else:
            code = constructor.write_level_version_constructor(-1)
            self.write_function_declaration(code)

        code = constructor.write_copy_constructor()
        self.write_function_declaration(code)

        code = constructor.write_assignment_operator()
        self.write_function_declaration(code)

        code = constructor.write_clone()
        self.write_function_declaration(code)

        code = constructor.write_destructor()
        self.write_function_declaration(code)

    ########################################################################

    # Functions for writing the attribute manipulation functions
    # these are for attributes and elements that occur as a single child

    # function to write the get/set/isSet/unset functions for attributes
    def write_attribute_functions(self):
        attrib_functions = SetGetFunctions.SetGetFunctions(self.language,
                                                           self.is_java_api,
                                                           self.is_list_of,
                                                           self.class_object)
        num_attributes = len(self.class_attributes)
        for i in range(0, num_attributes):
            code = attrib_functions.write_get(True, i)
            self.write_function_declaration(code)

            code = attrib_functions.write_get_string_for_enum(True, i)
            self.write_function_declaration(code)

        for i in range(0, num_attributes):
            code = attrib_functions.write_is_set(True, i)
            self.write_function_declaration(code)

            code = attrib_functions.write_get_num_for_vector(True, i)
            self.write_function_declaration(code)

        for i in range(0, num_attributes):
            code = attrib_functions.write_set(True, i)
            self.write_function_declaration(code)

            code = attrib_functions.write_set_string_for_enum(True, i)
            self.write_function_declaration(code)

            code = attrib_functions.write_add_element_for_vector(True, i)
            self.write_function_declaration(code)

        for i in range(0, num_attributes):
            code = attrib_functions.write_unset(True, i)
            self.write_function_declaration(code)

    # function to write the get/set/isSet/unset functions for single
    # child elements
    def write_child_element_functions(self, override=None):
        if override is None:
            if not self.has_children:
                return

            attrib_functions = SetGetFunctions.\
                SetGetFunctions(self.language, self.is_java_api,
                                self.is_list_of, self.class_object)
            num_elements = len(self.child_elements)
        else:
            attrib_functions = SetGetFunctions.SetGetFunctions(self.language,
                                                               self.is_java_api,
                                                               self.is_list_of,
                                                               override)
            num_elements = 1

        for i in range(0, num_elements):
            code = attrib_functions.write_get(False, i)
            self.write_function_declaration(code)

            code = attrib_functions.write_get(False, i, const=False)
            self.write_function_declaration(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_is_set(False, i)
            self.write_function_declaration(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_set(False, i)
            self.write_function_declaration(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_create(False, i)
            if override is None and code is None \
                    and 'concrete' in self.child_elements[i]:
                # need to write creates for the concrete
                concrete = self.child_elements[i]['concrete']
                concretes = query.get_concretes(self.class_object['root'],
                                                concrete)
                for j in range(0, len(concretes)):
                    code = attrib_functions\
                        .write_create_concrete_child(concretes[j])
                    self.write_function_declaration(code)
            else:
                self.write_function_declaration(code)

        for i in range(0, num_elements):
            code = attrib_functions.write_unset(False, i)
            self.write_function_declaration(code)

    ########################################################################

    # Functions for writing general functions

    def write_general_functions(self):
        gen_functions = GeneralFunctions.GeneralFunctions(self.language,
                                                          self.is_java_api,
                                                          self.is_list_of,
                                                          self.class_object)
        code = gen_functions.write_rename_sidrefs()
        self.write_function_declaration(code)

        if not self.is_plugin:
            code = gen_functions.write_get_element_name()
            self.write_function_declaration(code)

        code = gen_functions.write_set_element_name()
        self.write_function_declaration(code, exclude=True)

        if not self.is_plugin:
            code = gen_functions.write_get_typecode()
            self.write_function_declaration(code)

        code = gen_functions.write_get_item_typecode()
        self.write_function_declaration(code)

        code = gen_functions.write_has_required_attributes()
        self.write_function_declaration(code)

        code = gen_functions.write_has_required_elements()
        self.write_function_declaration(code)

        code = gen_functions.write_write_elements()
        self.write_function_declaration(code, exclude=True)

        code = gen_functions.write_accept()
        self.write_function_declaration(code, exclude=True)

        code = gen_functions.write_set_document()
        self.write_function_declaration(code, exclude=True)

        code = gen_functions.write_write()
        self.write_function_declaration(code, exclude=True)

        code = gen_functions.write_connect_to_child()
        self.write_function_declaration(code, exclude=True)

        if self.is_plugin:
            code = gen_functions.write_connect_to_parent()
            self.write_function_declaration(code, exclude=True)

        if global_variables.is_package:
            code = gen_functions.write_enable_package()
            self.write_function_declaration(code, exclude=True)

        if self.is_doc_plugin:
            code = gen_functions.write_is_comp_flat()
            self.write_function_declaration(code, exclude=True)

            code = gen_functions.write_check_consistency()
            self.write_function_declaration(code, exclude=True)

            self.write_swig_begin()
            code = gen_functions.write_read_attributes()
            self.write_function_declaration(code, exclude=True)
            self.write_swig_end()

    ########################################################################

    # Retrieve element functions

    def write_functions_to_retrieve(self):
        if not query.has_children(self.attributes):
            return

        gen_functions = \
            GlobalQueryFunctions.GlobalQueryFunctions(self.language,
                                                      self.is_java_api,
                                                      self.is_list_of,
                                                      self.class_object)
        code = gen_functions.write_get_by_sid()
        self.write_function_declaration(code)

        code = gen_functions.write_get_by_metaid()
        self.write_function_declaration(code)

        code = gen_functions.write_get_all_elements()
        self.write_function_declaration(code)

        if self.is_plugin:
            code = gen_functions.write_append_from()
            self.write_function_declaration(code, True)

    ########################################################################

    # Functions for writing the attribute manipulation functions
    # these are for attributes and elements that occur as a single child

    # function to write additional functions on a document for another library
    def write_document_error_log_functions(self):

        attrib_functions = SetGetFunctions.\
            SetGetFunctions(self.language, self.is_java_api,
                            self.is_list_of, self.class_object)
        num_elements = len(self.child_elements)
        # add error log and ns to child elements
        att_tc = 'XMLNamespaces*'
        if not global_variables.is_package:
            att_tc = 'LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*'
        element = dict({'name': 'Namespaces',
                        'isArray': False,
                        'attTypeCode': att_tc,
                        'capAttName': 'Namespaces',
                        'attType': 'element',
                        'memberName': 'm{0}Namespaces'.format(global_variables.prefix)})

        errelement = dict({'name': '{0}ErrorLog'.format(global_variables.prefix),
                           'isArray': False,
                           'attTypeCode': '{0}ErrorLog*'.format(global_variables.prefix),
                           'capAttName': 'ErrorLog',
                           'attType': 'element',
                           'memberName': 'mErrorLog'})

        self.child_elements.append(element)
        self.child_elements.append(errelement)

        code = attrib_functions.write_get(False, num_elements, True, True)
        self.write_function_declaration(code)

        code = attrib_functions.write_get(False, num_elements, False, True)
        self.write_function_declaration(code)

        code = attrib_functions.write_get(False, num_elements+1, True)
        self.write_function_declaration(code)

        code = attrib_functions.write_get(False, num_elements+1, False)
        self.write_function_declaration(code)

        self.child_elements.remove(errelement)
        self.child_elements.remove(element)

        # preserve existing values
        existing = dict()
        self.class_object['element'] = '{0}Error'.format(global_variables.prefix)
        self.class_object['parent'] = dict({'name': '{0}Document'.format(global_variables.prefix)})
        self.class_object['memberName'] = 'mErrorLog'
        lo_functions = ListOfQueryFunctions\
            .ListOfQueryFunctions(self.language, self.is_java_api,
                                  self.is_list_of,
                                  self.class_object)

        code = lo_functions.write_get_element_by_index(is_const=False)
        self.write_function_declaration(code)

        code = lo_functions.write_get_element_by_index(is_const=True)
        self.write_function_declaration(code)

        code = lo_functions.write_get_num_element_function()
        self.write_function_declaration(code)

        parameter = dict({'name': 'severity',
                          'type': 'unsigned int'})
        code = lo_functions.write_get_num_element_function(parameter)
        self.write_function_declaration(code)

    ########################################################################

    # concrete class functions

    def write_concrete_functions(self):
        conc_functions = \
            ConcreteClassFunctions.ConcreteClassFunctions(self.language,
                                                          self.is_java_api,
                                                          self.is_list_of,
                                                          self.class_object)
        for i in range(0, len(self.concretes)):
            code = conc_functions.write_is_foo(i)
            self.write_function_declaration(code)

    ########################################################################

    # Protected functions

    def write_protected_functions(self):
        protect_functions = \
            ProtectedFunctions.ProtectedFunctions(self.language,
                                                  self.is_java_api,
                                                  self.is_list_of,
                                                  self.class_object)
        exclude = True
        code = protect_functions.write_create_object()
        self.write_function_declaration(code, exclude)

        code = protect_functions.write_add_expected_attributes()
        self.write_function_declaration(code, exclude)

        code = protect_functions.write_read_attributes()
        self.write_function_declaration(code, exclude)
        if 'num_versions' in self.class_object \
                and self.class_object['num_versions'] > 1:
            for i in range(0, self.class_object['num_versions']):
                code = protect_functions.write_read_version_attributes(i+1)
                self.write_function_declaration(code, exclude)

        code = protect_functions.write_read_other_xml()
        self.write_function_declaration(code, exclude)

        code = protect_functions.write_write_attributes()
        self.write_function_declaration(code, exclude)
        if 'num_versions' in self.class_object \
                and self.class_object['num_versions'] > 1:
            for i in range(0, self.class_object['num_versions']):
                code = protect_functions.write_write_version_attributes(i+1)
                self.write_function_declaration(code, exclude)

        code = protect_functions.write_write_xmlns()
        self.write_function_declaration(code, exclude)

        code = protect_functions.write_is_valid_type_for_list()
        self.write_function_declaration(code, exclude)

        code = protect_functions.write_set_element_text()
        self.write_function_declaration(code, exclude)

    ########################################################################

    # Functions for writing functions for the main ListOf class

    def write_listof_functions(self):
        if not self.is_list_of:
            return

        lo_functions = ListOfQueryFunctions\
            .ListOfQueryFunctions(self.language, self.is_java_api,
                                  self.is_list_of,
                                  self.class_object)

        code = lo_functions.write_get_element_by_index(is_const=False)
        self.write_function_declaration(code)

        code = lo_functions.write_get_element_by_index(is_const=True)
        self.write_function_declaration(code)

        code = lo_functions.write_get_element_by_id(is_const=False)
        self.write_function_declaration(code)

        code = lo_functions.write_get_element_by_id(is_const=True)
        self.write_function_declaration(code)

        code = lo_functions.write_remove_element_by_index()
        self.write_function_declaration(code)

        code = lo_functions.write_remove_element_by_id()
        self.write_function_declaration(code)

        if self.is_java_api:
            code = lo_functions.write_add_element_function()
            self.write_function_declaration(code)

            code = lo_functions.write_get_num_element_function()
            self.write_function_declaration(code)

            for i in range(0, len(self.concretes)+1):
                code = lo_functions.write_create_element_function(i)
                self.write_function_declaration(code)

            for i in range(0, len(self.sid_refs)):
                code = \
                    lo_functions.write_get_element_by_sidref(self.sid_refs[i],
                                                             const=True)
                self.write_function_declaration(code)

                code = \
                    lo_functions.write_get_element_by_sidref(self.sid_refs[i],
                                                             const=False)
                self.write_function_declaration(code)

    # main function to write the functions dealing with a child listOf element
    def write_child_lo_element_functions(self):
        num_elements = len(self.child_lo_elements)
        for i in range(0, num_elements):
            element = self.child_lo_elements[i]
            element['std_base'] = self.std_base
            element['package'] = self.package
            element['is_header'] = self.is_header
            element['is_plugin'] = self.is_plugin
            if self.is_plugin:
                element['plugin'] = self.class_name
            if 'concrete' in element:
                element['concretes'] = query.get_concretes(
                    self.class_object['root'], element['concrete'])
            lo_functions = ListOfQueryFunctions\
                .ListOfQueryFunctions(self.language, self.is_java_api,
                                      self.is_list_of,
                                      element)
            code = lo_functions.write_get_list_of_function(is_const=True)
            self.write_function_declaration(code)

            code = lo_functions.write_get_list_of_function(is_const=False)
            self.write_function_declaration(code)

            code = lo_functions.write_get_element_by_index(is_const=False)
            self.write_function_declaration(code)

            code = lo_functions.write_get_element_by_index(is_const=True)
            self.write_function_declaration(code)

            code = lo_functions.write_get_element_by_id(is_const=False)
            self.write_function_declaration(code)

            code = lo_functions.write_get_element_by_id(is_const=True)
            self.write_function_declaration(code)

            sid_ref = query.get_sid_refs_for_class(element)
            for j in range(0, len(sid_ref)):
                code = \
                    lo_functions.write_get_element_by_sidref(sid_ref[j],
                                                             const=True)
                self.write_function_declaration(code)

                code = \
                    lo_functions.write_get_element_by_sidref(sid_ref[j],
                                                             const=False)
                self.write_function_declaration(code)

            code = lo_functions.write_add_element_function()
            self.write_function_declaration(code)

            code = lo_functions.write_get_num_element_function()
            self.write_function_declaration(code)

            if 'concretes' in element:
                for n in range(0, len(element['concretes'])):
                    code = lo_functions.write_create_element_function(n+1)
                    self.write_function_declaration(code)
            else:
                code = lo_functions.write_create_element_function()
                self.write_function_declaration(code)

            code = lo_functions.write_remove_element_by_index()
            self.write_function_declaration(code)

            code = lo_functions.write_remove_element_by_id()
            self.write_function_declaration(code)

            # this tackles the situation where a listOfFoo class also
            # contains an element of another type
            # eg qual:ListOfFunctionTerms contains a DefaultTerm
            if not self.is_plugin:
                element_children = query.\
                    get_other_element_children(self.class_object, element)

                for j in range(0, len(element_children)):
                    child_class = self.\
                        create_lo_other_child_element_class(element_children[0],
                                                            self.class_name)
                    self.write_child_element_functions(child_class)

    ########################################################################

    # Functions for writing definition declaration

    def write_defn_begin(self):
        self.skip_line(2)
        self.write_line('#ifndef {0}_H__'.format(self.name))
        self.write_line('#define {0}_H__'.format(self.name))
        self.skip_line(2)

    def write_defn_end(self):
        self.skip_line(2)
        self.write_line('#endif  /*  !{0}_H__  */'.format(self.name))
        self.skip_line(2)

    ########################################################################

    # Write file

    def write_file(self):
        BaseCppFile.BaseCppFile.write_file(self)
        self.write_defn_begin()
        self.write_common_includes()
        self.write_cpp_begin()
        self.write_general_includes()
        self.write_cppns_begin()
        self.write_class(self.baseClass, self.name, self.attributes)
        self.write_cppns_end()
        self.write_cpp_end()
        if not self.is_plugin:
            self.write_swig_begin()
            self.write_cppns_begin()
            self.write_cdecl_begin()
            self.write_c_header()
            self.write_cdecl_end()
            self.write_cppns_end()
            self.write_swig_end()
        self.write_defn_end()
