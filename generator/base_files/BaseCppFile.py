#!/usr/bin/env python
#
# @file    BaseCppFile.py
# @brief   base class for cpp files to be generated
# @author  Frank Bergmann
# @author  Sarah Keating
#
# <!--------------------------------------------------------------------------
#
# Copyright (c) 2013-2014 by the California Institute of Technology
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


import BaseFile
from util import strFunctions


class BaseCppFile(BaseFile.BaseFile):
    """Common base class for all c++ files"""

    def __init__(self, name, extension, attributes):
        BaseFile.BaseFile.__init__(self, name, extension)

        # members that might get overridden if creating another library
        self.baseClass = 'SBase'

        # expand the information for the attributes
        self.attributes = self.expand_attributes(self, attributes)
        self.child_elements = self.get_children()
        self.child_lo_elements = self.get_lo_children()

        self.concretes = []

        # default values
        self.is_cpp_api = True

    ########################################################################

    # Function to expand the attribute information
    @staticmethod
    def expand_attributes(self, attributes):
        for i in range(0, len(attributes)):
            capname = strFunctions.upper_first(attributes[i]['name'])
            attributes[i]['capAttName'] = capname
            attributes[i]['memberName'] = 'm' + capname
            attributes[i]['pluralName'] = \
                strFunctions.plural(attributes[i]['name'])
            attributes[i]['isEnum'] = False
            attributes[i]['isArray'] = False
            att_type = attributes[i]['type']
            if att_type == 'SId' or att_type == 'SIdRef':
                attributes[i]['attType'] = 'string'
                attributes[i]['attTypeCode'] = 'std::string&'
                attributes[i]['CType'] = 'const char *'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = '""'
            elif att_type == 'UnitSId' or att_type == 'UnitSIdRef':
                attributes[i]['attType'] = 'string'
                attributes[i]['attTypeCode'] = 'std::string&'
                attributes[i]['CType'] = 'const char *'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = '""'
            elif att_type == 'string':
                attributes[i]['attType'] = 'string'
                attributes[i]['attTypeCode'] = 'std::string&'
                attributes[i]['CType'] = 'const char *'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = '""'
            elif att_type == 'double':
                attributes[i]['attType'] = 'double'
                attributes[i]['attTypeCode'] = 'double'
                attributes[i]['CType'] = 'double'
                attributes[i]['isNumber'] = True
                attributes[i]['default'] = 'util_NaN()'
            elif att_type == 'int':
                attributes[i]['attType'] = 'integer'
                attributes[i]['attTypeCode'] = 'int'
                attributes[i]['CType'] = 'int'
                attributes[i]['isNumber'] = True
                attributes[i]['default'] = 'SBML_INT_MAX'
            elif att_type == 'uint':
                attributes[i]['attType'] = 'unsigned integer'
                attributes[i]['attTypeCode'] = 'unsigned int'
                attributes[i]['CType'] = 'unsigned int'
                attributes[i]['isNumber'] = True
                attributes[i]['default'] = 'SBML_INT_MAX'
            elif att_type == 'bool' or att_type == 'boolean':
                attributes[i]['attType'] = 'boolean'
                attributes[i]['attTypeCode'] = 'bool'
                attributes[i]['CType'] = 'int'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'false'
            elif att_type == 'enum':
                attributes[i]['isEnum'] = True
                attributes[i]['attType'] = 'enum'
                attributes[i]['attTypeCode'] = attributes[i]['element'] + '_t'
                attributes[i]['CType'] = attributes[i]['element'] + '_t'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = \
                    self.get_default_enum_value(self, attributes[i])
            elif att_type == 'element':
                attributes[i]['attType'] = 'element'
                if attributes[i]['name'] == 'math':
                    attributes[i]['attTypeCode'] = 'ASTNode*'
                    attributes[i]['CType'] = 'ASTNode_t*'
                else:
                    attributes[i]['attTypeCode'] = attributes[i]['element']+'*'
                    attributes[i]['CType'] = attributes[i]['element']+'_t*'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'NULL'
            elif att_type == 'lo_element':
                name = strFunctions.list_of_name(attributes[i]['element'])
                plural = strFunctions.plural(attributes[i]['element'])
                attributes[i]['attType'] = 'lo_element'
                attributes[i]['attTypeCode'] = name
                attributes[i]['CType'] = name + '_t'
                attributes[i]['memberName'] = 'm' + plural
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'NULL'
            elif att_type == 'array':
                attributes[i]['isArray'] = True
                attributes[i]['element'] = \
                    strFunctions.lower_first(attributes[i]['element'])
                attributes[i]['attType'] = 'array'
                attributes[i]['attTypeCode'] = attributes[i]['element'] + '*'
                attributes[i]['CType'] = attributes[i]['attTypeCode']
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'FIX ME'
            else:
                attributes[i]['attType'] = 'FIX ME'
                attributes[i]['attTypeCode'] = 'FIX ME'
                attributes[i]['CType'] = 'FIX ME'
                attributes[i]['isNumber'] = False
                attributes[i]['default'] = 'FIX ME'
        return attributes

    def get_children(self):
        elements = []
        for i in range(0, len(self.attributes)):
            att_type = self.attributes[i]['attType']
            if att_type == 'element':
                elements.append(self.attributes[i])
        return elements

    def get_lo_children(self):
        elements = []
        for i in range(0, len(self.attributes)):
            att_type = self.attributes[i]['attType']
            if att_type == 'lo_element':
                elements.append(self.attributes[i])
        return elements
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
                              is_const=False, is_virtual=False):
        is_cpp = self.is_cpp_api
        num_arguments = len(arguments)
        if not is_cpp:
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
            if is_cpp and is_const:
                line += ') const;'
            else:
                line += ');'
            self.write_line(line)
        elif num_arguments == 1:
            if is_cpp and is_const:
                line = line + arguments[0] + ') const;'
            else:
                line = line + arguments[0] + ');'
            self.write_line(line)
        else:
            saved_line = line
            line = line + arguments[0] + ', '
            # create the full line
            for n in range(1, num_arguments-1):
                line = line + arguments[n] + ', '
            if is_cpp and is_const:
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
                if is_cpp and is_const:
                    line = arguments[num_arguments - 1] + ') const;'
                else:
                    line = arguments[num_arguments - 1] + ');'
                self.write_line(line, att_start)
            else:
                self.write_line(line)

    def write_class_function_header(self, function_name, arguments,
                                    return_type, is_const=False,
                                    constructor_args=None):
        is_cpp = self.is_cpp_api
        num_arguments = len(arguments)
        if not is_cpp:
            self.write_extern_decl()
        self.write_line(return_type)
        line = function_name + '('
        if num_arguments == 0:
            if is_cpp and is_const:
                line += ') const'
            else:
                line += ')'
            self.write_line(line)
        elif num_arguments == 1:
            if is_cpp and is_const:
                line = line + arguments[0] + ') const'
            else:
                line = line + arguments[0] + ')'
            self.write_line(line)
        else:
            saved_line = line
            line = line + arguments[0] + ', '
            # create the full line
            for n in range(1, num_arguments-1):
                line = line + arguments[n] + ', '
            if is_cpp and is_const:
                line = line + arguments[num_arguments-1] + ') const'
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
                if is_cpp and is_const:
                    line = arguments[num_arguments - 1] + ') const'
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
        for i in range(0, len(additional)):
            if additional[i] == ' ':
                self.write_blank_comment_line()
            else:
                self.write_comment_line(additional[i])
        if object_name.endswith('_t'):
            self.write_blank_comment_line()
            self.write_comment_line('@memberof {}'.format(object_name))
        self.close_comment()

    def write_brief_header(self, title_line):
        self.open_single_comment(self)
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
            self.write_function_header(code['function'], code['arguments'],
                                       code['return_type'], code['constant'],
                                       code['virtual'])
            if exclude:
                self.write_doxygen_end()
                self.skip_line()
            else:
                self.skip_line(2)

    # Function for writing a function implementation
    def write_function_implementation(self, code, exclude=False):
        if code is not None:
            if exclude:
                self.write_doxygen_start()
            self.write_brief_header(code['title_line'])
            function_name = code['function']
            if self.is_cpp_api:
                function_name = code['object_name'] + '::' + code['function']
            if 'args_no_defaults' in code:
                arguments = code['args_no_defaults']
            else:
                arguments = code['arguments']
            constructor_args = None
            if self.is_cpp_api:
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

    def write_nested_implementation(self, implementation):
        num = len(implementation)
        self.up_indent()
        for i in range(0, num):
            this_impl = implementation[i]
            if len(this_impl) == 0:
                return
            else:
                if 'code_type' in this_impl:
                    self.write_implementation_block(this_impl['code_type'],
                                                    this_impl['code'])
                    if i < num - 1:
                        self.skip_line()
                else:
                    self.write_line('{};'.format(this_impl))
        self.down_indent()

    def write_lines(self, code):
        for i in range(0, len(code)):
            self.write_line('{};'.format(code[i]))

    def write_comments(self, code):
        for i in range(0, len(code)):
            self.write_line('// {}'.format(code[i]))

    # def write_if_block(self, code):
    #     self.write_line('if ({})'.format(code[0]))
    #     self.write_line('{')
    #     self.write_nested_implementation(code[1:len(code)])
    #     self.write_line('}')
    #
    # def write_elif_block(self, code):
    #     self.write_line('else if ({})'.format(code[0]))
    #     self.write_line('{')
    #     self.write_nested_implementation(code[1:len(code)])
    #     self.write_line('}')
    #
    # def write_else_block(self, code):
    #     self.write_line('else')
    #     self.write_line('{')
    #     self.write_nested_implementation(code)
    #     self.write_line('}')

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
        while i < len(code) and code[i] != 'else if':
            else_if_code.append(code[i])
            i += 1
        self.write_block('else if', else_if_code, True)

    def write_block(self, block_start, code, condition):
        if condition:
            self.write_line('{} ({})'.format(block_start, code[0]))
            self.write_line('{')
            self.write_nested_implementation(code[1:len(code)])
            self.write_line('}')
        else:
            self.write_line('{}'.format(block_start))
            self.write_line('{')
            self.write_nested_implementation(code)
            self.write_line('}')

    ######################################################################

    # HELPER FUNCTIONS

    @staticmethod
    def get_default_enum_value(self, attribute):
        prefix = ''
        name = attribute['element']
        enums = attribute['root']['enums']
        for i in range(0, len(enums)):
            if name == enums[i]['name']:
                prefix = self.get_prefix(name)
        default = prefix + '_UNKNOWN'
        return default

    @staticmethod
    def get_prefix(name):
        prefix = ''
        first = True
        for i in range(0, len(name)):
            char = name[i]
            if char.isupper():
                if first:
                    prefix += char
                    first = False
                else:
                    prefix += '_{}'.format(char)
            else:
                prefix += char.upper()
        return prefix

    @staticmethod
    def open_single_comment(self):
        tabs = ''
        for i in range(0, int(self.num_tabs)):
            tabs += '  '
        self.file_out.write('{0}{1}\n'.format(tabs, '/*'))
