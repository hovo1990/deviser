#!/usr/bin/env python
#
# @file    BaseCppFile.py
# @brief   base class for cpp files to be generated
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


from . import BaseFile
from util import strFunctions, query, global_variables



class BaseJavaFile(BaseFile.BaseFile):
    """Common base class for all java files"""

    def __init__(self, name, extension, attributes):
        BaseFile.BaseFile.__init__(self, name, extension)

        # members that might get overridden if creating another library
        self.baseClass = global_variables.javaBaseClass

        # GSOC 2016 modifications


        # derived members for comments
        self.comment_start = '/**'
        self.comment = ' *'
        self.comment_end = '*/'


        # members that might get overridden if creating another library
        self.language = global_variables.javaLanguage
        self.library_name = global_variables.java_library_name
        self.cap_language = self.language.upper()


        # expand the information for the attributes
        if attributes:
            self.attributes = self.expand_attributes(attributes)
            self.child_elements = self.get_children()
            self.child_lo_elements = self.get_lo_children()
        else:
            self.attributes = []
            self.child_elements = []
            self.child_lo_elements = []

        self.num_children = \
            len(self.child_lo_elements) + len(self.child_elements)

        self.concretes = []

        # default values
        self.is_java_api = True

        self.class_object = {}

        # declare variables that will populate by the class object
        if not self.name:
            self.name = ''
        self.is_list_of = ''
        self.class_name = ''
        self.package = ''
        self.typecode = ''
        self.list_of_name = ''
        self.list_of_child = ''
        self.has_std_base = True
        self.std_base = global_variables.std_base
        self.sid_refs = ''
        self.unit_sid_refs = ''
        self.add_decls = None
        self.add_impl = None
        self.overwrites_children = False
        self.has_math = False
        self.has_children = False
        self.has_only_math = False
        self.has_non_std_children = False
        self.num_non_std_children = 0
        self.class_attributes = []
        self.has_parent_list_of = False
        self.is_plugin = False
        self.is_doc_plugin = False

    ########################################################################

    def expand_class(self, class_object):
        self.class_object = class_object
        self.is_list_of = class_object['is_list_of']
        self.has_parent_list_of = class_object['hasListOf']
        self.name = class_object['name']
        self.class_name = class_object['name']
        self.package = class_object['package']
        self.typecode = class_object['typecode']
        if class_object['is_list_of']:
            self.list_of_name = class_object['list_of_name']
            self.list_of_child = class_object['lo_child']
        else:
            self.list_of_name = ''
            self.list_of_child = ''
        # check case of things where we assume upper/lower
        if self.package[0].islower():
            self.package = strFunctions.upper_first(class_object['package'])

        # are we a plugin
        if 'is_plugin' in class_object:
            self.is_plugin = class_object['is_plugin']
        if 'is_doc_plugin' in class_object:
            self.is_doc_plugin = class_object['is_doc_plugin']

        # information about the base class
        self.baseClass = class_object['baseClass']
        if self.language != 'sbml':
            if not self.is_list_of:
                base = '{0}Base'.format(global_variables.prefix)
            else:
                base = '{0}ListOf'.format(global_variables.prefix)
            if base != self.baseClass:
                self.has_std_base = False

        elif not self.is_list_of and not self.is_plugin \
                and self.baseClass != 'SBase':
            self.has_std_base = False
        elif self.is_list_of and not self.is_plugin \
                and self.baseClass != 'ListOf':
            self.has_std_base = False
        elif self.is_plugin and not self.is_doc_plugin \
                and self.baseClass != 'SBasePlugin':
            self.has_std_base = False
        elif self.is_doc_plugin:
            self.has_std_base = True
            self.std_base = '{0}DocumentPlugin'.format(self.cap_language)
        self.class_object['has_std_base'] = self.has_std_base
        self.class_object['std_base'] = self.std_base

        # references
        self.sid_refs = class_object['sid_refs']
        self.unit_sid_refs = class_object['unit_sid_refs']
        if 'addDecls' in class_object:
            self.add_decls = class_object['addDecls']
        if 'addDefs' in class_object:
            self.add_impl = class_object['addDefs']
        # if 'childrenOverwriteElementName' in class_object:
        #     self.overwrites_children = \
        #         class_object['childrenOverwriteElementName']
        if 'root' in class_object:
            self.overwrites_children = \
                query.overwrites_name(class_object['root'],
                                      class_object['name'])
        self.class_object['overwrites_children'] = self.overwrites_children

        # child elements
        self.has_math = class_object['hasMath']
        self.has_children = query.has_children(class_object['attribs'])
        if self.has_math and \
                not query.has_children_not_math(class_object['attribs']):
            self.has_only_math = True

        # mark child elements as ML nodes
        for i in range(0, len(self.child_elements)):
            element = self.child_elements[i]
            if element['element'].endswith('Node') \
                    and not element['element'].endswith('CSGNode'):
                self.child_elements[i]['is_ml'] = True
                self.has_non_std_children = True
                self.num_non_std_children += 1
            else:
                self.child_elements[i]['is_ml'] = False

        if 'concrete' in class_object:
            self.concretes = query.get_concretes(class_object['root'],
                                                 class_object['concrete'])

        self.class_attributes = query.separate_attributes(self.attributes)

        # document class for other libraries
        self.document = False
        if 'document' in class_object:
            self.document = class_object['document']
        # add info back to the class_object so we can pass it on
        self.class_object['package'] = self.package
        self.class_object['class_attributes'] = self.class_attributes
        self.class_object['child_lo_elements'] = self.child_lo_elements
        self.class_object['child_elements'] = self.child_elements
        self.class_object['concretes'] = self.concretes
        self.class_object['has_array'] = query.has_array(self.class_attributes)
        self.class_object['has_vector'] = query.has_vector(self.class_attributes)
        self.class_object['has_math'] = self.has_math
        self.class_object['has_children'] = self.has_children
        self.class_object['has_only_math'] = self.has_only_math
        self.class_object['has_parent_list_of'] = self.has_parent_list_of
        self.class_object['num_children'] = self.num_children
        self.class_object['has_non_std_chilren'] = self.has_non_std_children
        self.class_object['num_non_std_children'] = self.num_non_std_children
        self.class_object['is_header'] = self.is_header
        self.class_object['document'] = self.document

    ########################################################################

    # Function to expand the attribute information
    def expand_attributes(self, attributes):
        for i in range(0, len(attributes)):
            capname = strFunctions.upper_first(attributes[i]['name'])
            attributes[i]['name'] = strFunctions.lower_first(capname)
            attributes[i]['capAttName'] = capname
            attributes[i]['memberName'] = 'm' + capname
            attributes[i]['pluralName'] = \
                strFunctions.plural(attributes[i]['name'])
            attributes[i]['isEnum'] = False
            attributes[i]['isArray'] = False
            attributes[i]['isVector'] = False
            attributes[i]['children_overwrite'] = False
            att_type = attributes[i]['type']
            if att_type == 'SId' or att_type == 'SIdRef' or att_type == 'IDREF':
                attributes[i]['attType'] = 'String'
                attributes[i]['attTypeCode'] = 'String'
                attributes[i]['CType'] = 'String'
                attributes[i]["JClassType"] = 'String'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = '""'
            elif att_type == 'UnitSId' or att_type == 'UnitSIdRef':
                attributes[i]['attType'] = 'String'
                attributes[i]['attTypeCode'] = 'String'
                attributes[i]['CType'] = 'String'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = '""'
            elif att_type == 'string':
                attributes[i]['attType'] = 'String'
                attributes[i]['attTypeCode'] = 'String'
                attributes[i]['CType'] = 'String'
                attributes[i]["JClassType"] = 'String'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = '""'
            elif att_type == 'double':
                attributes[i]['attType'] = 'double'
                attributes[i]['attTypeCode'] = 'double'
                attributes[i]['CType'] = 'double'
                attributes[i]["JClassType"] = 'Double'
                attributes[i]['isNumber'] = True
                attributes[i]['default'] = 'util_NaN()' #?
            elif att_type == 'int':
                attributes[i]['attType'] = 'integer'
                attributes[i]['attTypeCode'] = 'int'
                attributes[i]['CType'] = 'int'
                attributes[i]["JClassType"] = 'Integer'
                attributes[i]['isNumber'] = True
                attributes[i]['default'] = '{0}_INT_' \
                                           'MAX'.format(self.cap_language) #?
            elif att_type == 'uint':
                attributes[i]['attType'] = 'unsigned integer'
                attributes[i]['attTypeCode'] = 'int'
                attributes[i]['CType'] = 'int'
                attributes[i]["JClassType"] = 'Integer'
                attributes[i]['isNumber'] = True
                attributes[i]['default'] = '{0}_INT_' \
                                           'MAX'.format(self.cap_language)
            elif att_type == 'bool' or att_type == 'boolean':
                attributes[i]['attType'] = 'boolean'
                attributes[i]['attTypeCode'] = 'boolean'
                attributes[i]['CType'] = 'boolean'
                attributes[i]["JClassType"] = 'Boolean'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'False'
            elif att_type == 'enum': #This is tricky
                attributes[i]['isEnum'] = True
                attributes[i]['attType'] = 'enum'
                attributes[i]['attTypeCode'] = attributes[i]['element'] #+ '_t'
                attributes[i]['CType'] = attributes[i]['element'] # + '_t'
                attributes[i]["JClassType"] = attributes[i]['element']
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = \
                    query.get_default_enum_value(attributes[i])
            elif att_type == 'element':
                el_name = attributes[i]['element']
                at_name = attributes[i]['name']
                attributes[i]['attType'] = 'element'
                if attributes[i]['name'] == 'math':
                    if global_variables.is_package:
                        attributes[i]['attTypeCode'] = 'ASTNode' # 'ASTNode*'
                        attributes[i]['CType'] = 'ASTNode'  #'ASTNode_t*'
                        attributes[i]["JClassType"] = 'ASTNode'
                    # else:
                    #     attributes[i]['attTypeCode'] = 'LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode*'
                    #     attributes[i]['CType'] = 'LIBSBML_CPP_NAMESPACE_QUALIFIER ASTNode_t*'
                else:
                    attributes[i]['attTypeCode'] = attributes[i]['element']+'*'
                    attributes[i]['CType'] = attributes[i]['element']+'_t*'
                    attributes[i]["JClassType"] = attributes[i]['element']
                if attributes[i]['attTypeCode'] == 'XMLNode*' and not global_variables.is_package:
                    attributes[i]['attTypeCode'] = 'LIBSBML_CPP_NAMESPACE_QUALIFIER {0}*'.format(attributes[i]['element'])
                    attributes[i]['CType'] = 'LIBSBML_CPP_NAMESPACE_QUALIFIER {0}_t*'.format(attributes[i]['element'])
                    attributes[i]['JClassType'] = 'LIBSBML_CPP_NAMESPACE_QUALIFIER {0}_t*'.format(attributes[i]['element'])

                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'NULL'
                if strFunctions.compare_no_case(strFunctions.remove_prefix(el_name), at_name):
                    attributes[i]['children_overwrite'] = False
                else:
                    attributes[i]['children_overwrite'] = True
            elif att_type == 'lo_element' or att_type == 'inline_lo_element':
                name = strFunctions.list_of_name(attributes[i]['element'])
                plural = strFunctions.plural_no_prefix(attributes[i]['element'])
                attributes[i]['attType'] = 'lo_element'
                attributes[i]['attTypeCode'] = name
                attributes[i]['CType'] = 'ListOf'# _t'
                attributes[i]['JClassType'] = 'ListOf'  # _t'
                attributes[i]['memberName'] = 'm' + plural
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'NULL'
            elif att_type == 'array':
                attributes[i]['isArray'] = True
                attributes[i]['element'] = \
                    strFunctions.lower_first(attributes[i]['element'])
                attributes[i]['attType'] = 'array'
                attributes[i]['attTypeCode'] = attributes[i]['element'] # + '*'
                attributes[i]['CType'] = attributes[i]['attTypeCode']
                attributes[i]['JClassType'] = attributes[i]['attTypeCode']
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'NULL'
            elif att_type == 'vector':
                attributes[i]['isVector'] = True
                attributes[i]['element'] = \
                    strFunctions.lower_first(attributes[i]['element'])
                attributes[i]['attType'] = 'vector'
                attributes[i]['attTypeCode'] = 'ArrayList<{0}>'.format(attributes[i]['element'])
                print("YOLUS ",attributes[i]['attTypeCode'] )
                attributes[i]['CType'] = attributes[i]['attTypeCode']
                ttributes[i]['JClassType'] = ttributes[i]['attTypeCode']
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'NULL'
            else:
                global_variables.code_returned \
                    = global_variables.return_codes['unknown type used']
                attributes[i]['attType'] = 'FIXME_{0}'.format(att_type)
                attributes[i]['attTypeCode'] = 'FIXME_{0}'.format(att_type)
                attributes[i]['CType'] = 'FIXME_{0}'.format(att_type)
                attributes[i]['JClassType'] = 'FIXME_{0}'.format(att_type)
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'FIXME_{0}'.format(att_type)
        return attributes

    def create_lo_other_child_element_class(self, name, parent): #Critical becareful with it
        capname = strFunctions.upper_first(name)
        print('Yolo capname ',capname)
        element = dict({'isArray': False,
                        'name': strFunctions.lower_first(capname),
                        'attTypeCode': capname,
                        'CType': capname ,
                        'capAttName': capname,
                        'attType': 'element',
                        'memberName': 'm' + capname,
                        'isNumber': False,
                        'type': 'element',
                        'default': 'NULL',
                        'element': capname,
                        'is_ml': False,
                        'children_overwrite': False,
                        'abstract': False})
        child_class = dict({'name': parent,
                            'package': self.package,
                            'class_attributes': [],
                            'child_elements': [element]})
        return child_class

    def get_children(self):
        elements = []
        listed_elements = []
        for i in range(0, len(self.attributes)):
            att_type = self.attributes[i]['attType']
            name = self.attributes[i]['name']
            if att_type == 'element' and name not in listed_elements:
                elements.append(self.attributes[i])
                listed_elements.append(name)
        return elements

    def get_lo_children(self):
        elements = []
        listed_elements = []
        for i in range(0, len(self.attributes)):
            attribute = self.attributes[i]
            att_type = attribute['attType']
            name = attribute['name']
            if att_type == 'lo_element' and name not in listed_elements:
                # check for concrete instances
                if attribute['type'] == 'inline_lo_element':
                    capname = strFunctions.upper_first(name)
                    attrib_class = query.get_class(capname, attribute['root'])
                    if attrib_class and 'concrete' in attrib_class:
                        attribute['concrete'] = attrib_class['concrete']
                elements.append(attribute)
                listed_elements.append(name)
        return elements

    ########################################################################

    # Functions to overwrite base class settings
    def set_base_class(self, base):
        self.baseClass = base

    def set_std_base_class(self, base):
        self.std_base = base

    ########################################################################

    #   FUNCTIONS FOR WRITING STANDARD OPENING CLOSING ELEMENTS

    # functions cpp ns
    def write_cppns_begin(self):
        self.skip_line(2)
        self.write_line('{0}_CPP_NAMESPACE_BEGIN'
                        .format(self.library_name.upper()))
        self.skip_line(2)

    def write_cppns_end(self):
        self.skip_line(2)
        self.write_line('{0}_CPP_NAMESPACE_END'
                        .format(self.library_name.upper()))
        self.skip_line(2)

    def write_cppns_use(self):
        self.skip_line(2)
        self.write_line('{0}_CPP_NAMESPACE_USE'
                        .format(self.library_name.upper()))
        self.skip_line(2)

    # functions c declaration
    def write_cdecl_begin(self):
        self.skip_line(2)
        self.write_line('BEGIN_C_DECLS')
        self.skip_line(2)

    def write_cdecl_end(self):
        self.skip_line(2)
        self.write_line('END_C_DECLS')
        self.skip_line(2)

    # functions swig directive
    def write_swig_begin(self):
        self.skip_line(2)
        self.write_line('#ifndef SWIG')
        self.skip_line(2)

    def write_swig_end(self):
        self.skip_line(2)
        self.write_line('#endif  /*  !SWIG  */')
        self.skip_line(2)

    # functions cplusplus directive
    def write_cpp_begin(self):
        self.skip_line(2)
        self.write_line('#ifdef __cplusplus')
        self.skip_line(2)

    def write_cpp_end(self):
        self.skip_line(2)
        self.write_line('#endif  /*  __cplusplus  */')
        self.skip_line(2)

########################################################################

# FUNCTIONS FOR WRITING STANDARD FUNCTION DECLARATIONS

    def write_function_header(self,
                              function_name, arguments, return_type,
                              is_const=False, is_virtual=False,
                              is_abstract=False):
        is_java = self.is_java_api
        num_arguments = len(arguments)
        if not is_java:
            self.write_extern_decl()
            self.write_line(return_type)
            line = function_name + '('
        else:
            if return_type != '':
                if is_virtual:
                    line = 'virtual ' + return_type + ' ' + function_name + '('
                else:
                    line = return_type + ' ' + function_name + '('
            else:
                if is_virtual:
                    line = 'virtual ' + function_name + '('
                else:
                    line = function_name + '('

        if num_arguments == 0:
            if is_java and is_const:
                line += ') const;'
            elif is_abstract:
                line += ') = 0;'
            else:
                line += ');'
            self.write_line(line)
        elif num_arguments == 1:
            if is_java and is_const:
                line = line + arguments[0] + ') const;'
            elif is_abstract:
                line = line + arguments[0] + ') = 0;'
            else:
                line = line + arguments[0] + ');'
            self.write_line(line)
        else:
            saved_line = line
            line = line + arguments[0] + ', '
            # create the full line
            for n in range(1, num_arguments-1):
                line = line + arguments[n] + ', '
            if is_java and is_const:
                line = line + arguments[num_arguments-1] + '); const'
            else:
                line = line + arguments[num_arguments-1] + ');'
            # look at length and adjust
            if len(line) >= self.line_length:
                # do something else
                line = saved_line
                att_start = len(line)
                line += arguments[0]
                line += ','
                if len(line) > self.line_length:
                    self.write_line(saved_line)
                    line = '' + arguments[0] + ','
                    self.write_line(line, att_start)
                else:
                    self.write_line(line)
                for i in range(1, num_arguments - 1):
                    line = arguments[i] + ','
                    self.write_line(line, att_start)
                if is_java and is_const:
                    line = arguments[num_arguments - 1] + ');' # const
                else:
                    line = arguments[num_arguments - 1] + ');'
                self.write_line(line, att_start)
            else:
                self.write_line(line)

    def write_class_function_header(self, function_name, arguments,
                                    return_type, is_const=False,
                                    constructor_args=None):
        is_java = self.is_java_api
        num_arguments = len(arguments)
        if not is_java:
            self.write_extern_decl()
        #self.write_line(return_type) #Need to remove this part

        # TODO GSOC 2016 change
        line = 'public' + ' ' + return_type + ' ' + function_name + '('
        if num_arguments == 0:
            if is_java and is_const:
                line += ')' # const
            else:
                line += ')'
            self.write_line(line)
        elif num_arguments == 1:
            if is_java and is_const:
                line = line + arguments[0] + ')' # const
            else:
                line = line + arguments[0] + ')'
            self.write_line(line)
        else:
            saved_line = line
            line = line + arguments[0] + ', '
            # create the full line
            for n in range(1, num_arguments-1):
                line = line + arguments[n] + ', '
            if is_java and is_const:
                line = line + arguments[num_arguments-1] + ')' # const
            else:
                line = line + arguments[num_arguments-1] + ')'
            # look at length and adjust
            if len(line) >= self.line_length:
                # do something else
                line = saved_line
                att_start = len(line)
                line += arguments[0]
                line += ','
                if len(line) > self.line_length:
                    self.write_line(saved_line)
                    line = '' + arguments[0] + ','
                    self.write_line(line, att_start)
                else:
                    self.write_line(line)
                for i in range(1, num_arguments - 1):
                    line = arguments[i] + ','
                    self.write_line(line, att_start)
                if is_java and is_const:
                    line = arguments[num_arguments - 1] + ')' # const
                else:
                    line = arguments[num_arguments - 1] + ')'
                self.write_line(line, att_start)
            else:
                self.write_line(line)
        if constructor_args is not None:
            self.up_indent()
            for i in range(0, len(constructor_args)):
                self.write_line(constructor_args[i])
            self.down_indent()


########################################################################

# FUNCTIONS FOR WRITING STANDARD DOC COMMENTS

    def write_comment_header(self, title_line, params, return_line,
                             object_name, additional=None):
        if additional is None:
            additional = []
        self.open_comment()
        self.write_comment_line(title_line)
        for i in range(0, len(params)):
            self.write_blank_comment_line()
            self.write_comment_line(params[i])
        if len(return_line) > 0:
            self.write_blank_comment_line()
        for i in range(0, len(return_line)):
            self.write_comment_line((return_line[i]))
        if len(additional) > 0:
            self.write_blank_comment_line()
        # TODO maybe this part could be used for writing @Overrides?
        for i in range(0, len(additional)):
            if additional[i] == ' ':
                self.write_blank_comment_line()
            else:
                self.write_comment_line(additional[i])
        if object_name.endswith('_t'):
            self.write_blank_comment_line()
            self.write_comment_line('@memberof {0}'.format(object_name))
        self.close_comment()



    # Need to add tabs
    def write_brief_header(self, title_line):
        self.open_double_comment(self)
        self.write_comment_line(title_line)
        self.close_comment()

#########################################################################

# Function for writing a function definition with comment
    def write_function_declaration(self, code, exclude=False):
        if code is not None:
            if exclude:
                self.write_doxygen_start()
            self.write_comment_header(code['title_line'], code['params'],
                                      code['return_lines'], code['object_name'],
                                      code['additional'])
            if 'pure_abstract' in code and code['pure_abstract']:
                self.write_function_header(code['function'], code['arguments'],
                                           code['return_type'],
                                           code['constant'], code['virtual'],
                                           True)
            else:
                self.write_function_header(code['function'], code['arguments'],
                                           code['return_type'],
                                           code['constant'], code['virtual'])
            if exclude:
                self.write_doxygen_end()
                self.skip_line()
            else:
                self.skip_line(2)

    # Function for writing a function implementation
    def write_function_implementation(self, code, exclude=False):
        if code is not None:
            self.up_indent() #This is a problem

            if exclude:
                self.write_doxygen_start()
            self.write_brief_header(code['title_line'])
            function_name = code['function']


            #GSOC 2016 function name changes necessary -> u'QualitativeSpecies getId' Wrong

            if self.is_java_api:
                if not code['object_name']:
                    function_name = code['function']
                else:
                    function_name =  code['function'] #code['object_name'] + ' ' \  +
            if 'args_no_defaults' in code:
                arguments = code['args_no_defaults']
            else:
                arguments = code['arguments']
            constructor_args = None
            print('function_name ', function_name) #both for constructors and functions, not suitable for JSBML
            print('->-')
            if self.is_java_api:
                if 'constructor_args' in code:
                    constructor_args = code['constructor_args']
            self.write_class_function_header(function_name, arguments,
                                             code['return_type'],
                                             code['constant'],
                                             constructor_args)

            if 'implementation' in code and code['implementation'] is not None:
                self.write_implementation(code['implementation'])
                print("code implementation ",code['implementation'])
                print('---------------->')



            if exclude:
                self.write_doxygen_end()
                self.skip_line()
            else:
                self.skip_line(2)
            self.down_indent()

    # Function for writing a function implementation
    def write_inline_function_implementation(self, code, exclude=False):
        if code is not None:
            if exclude:
                self.write_doxygen_start()
            if len(code['title_line']) > 0:
                self.write_brief_header(code['title_line'])
            function_name = code['function']
            if self.is_java_api:
                function_name = code['function']
            if 'args_no_defaults' in code:
                arguments = code['args_no_defaults']
            else:
                arguments = code['arguments']
            constructor_args = None
            if self.is_java_api:
                if 'constructor_args' in code:
                    constructor_args = code['constructor_args']
            self.write_class_function_header(function_name, arguments,
                                             code['return_type'],
                                             code['constant'],
                                             constructor_args)

            if 'implementation' in code and code['implementation'] is not None:
                self.write_implementation(code['implementation'])
            if exclude:
                self.write_doxygen_end()
                self.skip_line()
            else:
                self.skip_line(2)

    # Function for writing a function implementation
    def write_function_verbatim(self, code):
        if code is not None:
            self.write_brief_header(code['title_line'])
            self.write_line(code['function'])

            if 'implementation' in code and code['implementation'] is not None:
                self.write_line('{')
                self.up_indent()
                for i in range(0, len(code['implementation'])):
                    self.write_line(code['implementation'][i])
                self.down_indent()
                self.write_line('};')
                self.skip_line(2)

    # Function to write the header about the typecode enumeration
    def write_type_code_enum_header(self, package):
        up_package = strFunctions.upper_first(package)
        self.open_comment()
        self.write_comment_line('@enum {0}{1}'
                                'TypeCode_t'.format(self.cap_language,
                                                    up_package))
        self.write_comment_line('@brief {0}{1}TypeCode_t Enumeration '
                                'of possible types in the lib{0} '
                                '&ldquo;{2}&rdquo; package '
                                'implementation.'.format(self.cap_language,
                                                         up_package,
                                                         package))
        self.write_blank_comment_line()
        self.write_comment_line('@copydetails doc_what_are_typecodes')
        self.write_blank_comment_line()
        self.write_comment_line('@copydetails doc_additional_typecode_details')
        self.close_comment()

    # Function to write the header about the typecode enumeration
    def write_enum(self, name, enum_no, enum_val, enum_str, length):
        number = len(enum_val)
        if len(enum_str) != number:
            return
        self.write_line('typedef enum')
        self.write_line('{')
        self.file_out.write('  {0:{width}}'.format(enum_val[0], width=length))
        if enum_no != 0:
            self.file_out.write('= {0:{width}}'.format(enum_no, width=5))
            enum_no += 1
        self.file_out.write('  /*!<{0} */\n'.format(enum_str[0]))
        for i in range(1, number):
            self.file_out.write(', {0:{width}}'.format(enum_val[i],
                                                      width=length))
            if enum_no != 0:
                self.file_out.write('= {0:{width}}'.format(enum_no, width=5))
                enum_no += 1
            self.file_out.write('  /*!<{0} */\n'.format(enum_str[i]))
        self.write_line('{0} {1};'.format('}', name))

    # Function to write the header about the typecode enumeration
    def write_enum_strings(self, name, enum_str):
        number = len(enum_str)
        self.write_line('static')
        self.write_line('const char* {0}[] ='.format(name))
        self.write_line('{')
        self.file_out.write('  \"{0}\"\n'.format(enum_str[0]))
        for i in range(1, number):
            self.file_out.write(', \"{0}\"\n'.format(enum_str[i]))
        self.write_line('};')

    ########################################################################

    # FUNCTIONS FOR WRITING STANDARD FUNCTION Implementation

    def write_implementation(self, implementation):
        self.write_line('{')
        self.write_nested_implementation(implementation)
        self.write_line('}')

    def write_implementation_block(self, code_type, code):
        if code_type == 'line':
            self.write_lines(code)
        elif code_type == 'comment':
            self.write_comments(code)
        elif code_type == 'if':
            self.write_block('if', code, True)
        elif code_type == 'if_else':
            self.write_if_else_block(code)
        elif code_type == 'else_if':
            self.write_else_if_block(code)
        elif code_type == 'for':
            self.write_block('for', code, True)
        elif code_type == 'while':
            self.write_block('while', code, True)
        elif code_type == 'try':
            self.write_try_block(code)

    def write_nested_implementation(self, implementation):
        num = len(implementation)
        self.up_indent()
        for i in range(0, num):
            this_impl = implementation[i]
            if len(this_impl) == 0:
                self.down_indent()
                return
            else:
                if 'code_type' in this_impl:
                    self.write_implementation_block(this_impl['code_type'],
                                                    this_impl['code'])
                    if i < num - 1:
                        self.skip_line()
                else:
                    self.write_line('{0};'.format(this_impl))
        self.down_indent()

    def write_lines(self, code):
        for i in range(0, len(code)):
            self.write_line('{0};'.format(code[i]))

    def write_comments(self, code):
        for i in range(0, len(code)):
            self.write_line('// {0}'.format(code[i]))

    def write_if_else_block(self, code):
        if_code = [code[0]]
        i = 1
        while i < len(code) and code[i] != 'else':
            if_code.append(code[i])
            i += 1
        self.write_block('if', if_code, True)
        self.write_block('else', code[i+1:len(code)], False)

    def write_else_if_block(self, code):
        if_code = [code[0]]
        i = 1
        while i < len(code) and code[i] != 'else if':
            if_code.append(code[i])
            i += 1
        self.write_block('if', if_code, True)
        i += 1
        else_if_code = [code[i]]
        i += 1
        while i < len(code):
            while i < len(code) and \
                    (code[i] != 'else if' and code[i] != "else"):
                else_if_code.append(code[i])
                i += 1
            self.write_block('else if', else_if_code, True)
            if i < len(code):
                flag_else = (code[i] == 'else')
                if not flag_else:
                    if i < len(code):
                        i += 1
                        else_if_code = [code[i]]
                        i += 1
                else:
                    self.write_block('else', code[i+1:len(code)], False)
                    break

    def write_try_block(self, code):
        try_code = [code[0]]
        i = 1
        while i < len(code) and code[i] != 'catch':
            try_code.append(code[i])
            i += 1
        self.write_block('try', try_code, False)
        self.write_block('catch', code[i+1:len(code)], True)

    def write_block(self, block_start, code, condition):
        if condition:
            self.write_line('{0} ({1})'.format(block_start, code[0]))
            self.write_line('{')
            self.write_nested_implementation(code[1:len(code)])
            self.write_line('}')
        else:
            self.write_line('{0}'.format(block_start))
            self.write_line('{')
            self.write_nested_implementation(code)
            self.write_line('}')

    ######################################################################

    # HELPER FUNCTIONS

    @staticmethod
    def open_single_comment(self):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0}{1}\n'.format(tabs, '/*'))


    @staticmethod
    def open_double_comment(self):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0}{1}\n'.format(tabs, '/**'))