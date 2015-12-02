#!/usr/bin/env python
#
# @file    ValidationFiles.py
# @brief   class for generating cpp files
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

import CppHeaderFile
from base_files import BaseCppFile, BaseTexFile
from util import strFunctions, global_variables
from validation import ValidationRulesForPlugin, ValidationRulesForClass
from validation import ValidationRulesGeneral
import ValidatorHeaderFile
import ValidatorCodeFile


class ValidationFiles():
    """Class for all Cpp files"""

    def __init__(self, lib_object, verbose=False):
        # members from object
        self.lib_object = lib_object
        self.language = global_variables.language
        self.cap_language = self.language.upper()

        self.package = lib_object['name']
        self.up_package = strFunctions.upper_first(self.package)

        self.cap_lib = 'LIB{0}'.format(self.cap_language)

        self.offset = lib_object['offset']
        self.sbml_classes = lib_object['baseElements']
        self.enums = lib_object['enums']
        self.plugins = lib_object['plugins']
        self.fullname = lib_object['fullname']
        self.level = lib_object['base_level']
        self.version = lib_object['base_version']
        self.pkg_version = lib_object['pkg_version']
        self.pkg_ref = '{0} Level~{1} Package specification for {2}, ' \
                       'Version~{3}'.format(self.cap_language, self.level,
                                           self.fullname, self.pkg_version)

        self.error_file = None
        self.class_rules = []
        self.create_rule_structure()

        self.open_br = '{'
        self.close_br = '}'

        self.verbose = verbose

    ##########################################################################

    # initial populating lists
    def create_rule_structure(self):
        tex_file = BaseTexFile.BaseTexFile('', '', self.lib_object)
        tex_file.sort_class_names(self.sbml_classes)
        tex_file.sort_attribute_names(self.sbml_classes)
        tex_file.sort_enum_names(self.enums)
        number = self.offset
        rules = ValidationRulesGeneral\
            .ValidationRulesGeneral(self.fullname, number, self.package,
                                    self.pkg_ref, self.level, self.version,
                                    self.pkg_version)
        rules.determine_rules()
        self.class_rules += rules.rules
        number = self.offset + 20200
        for i in range(0, len(self.plugins)):
            rules = ValidationRulesForPlugin.ValidationRulesForPlugin(
                self.plugins[i], self.fullname, number,
                self.package, self.pkg_ref)
            rules.determine_rules()
            self.class_rules += rules.rules
            number += 100
        for i in range(0, len(self.sbml_classes)):
            # hack for render
            if self.sbml_classes[i]['name'] == 'RelAbsVector':
                continue
            rules = ValidationRulesForClass\
                .ValidationRulesForClass(self.sbml_classes[i],
                                         self.fullname, number, self.package,
                                         self.pkg_ref)
            rules.determine_rules()
            self.class_rules += rules.rules
            number += 100
        self.populate_error_list()

    def populate_error_list(self):
        if len(global_variables.error_list) > 0:
            return
        for rule in self.class_rules:
            global_variables.error_list.append(rule['typecode'])

    ##########################################################################

    def write_constraint_files(self):
        self.write_constraints()
        self.write_constraints('identifier')

    def write_files(self):
        self.write_error_header()
        self.write_error_table_header()
        self.write_validator_files()
        self.write_validator_files('identifier')

    def write_constraints(self, valid_type=''):
        fileout = ValidatorCodeFile.ValidatorCodeFile(self.language,
                                                      self.package,
                                                      'constraints',
                                                      valid_type)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.write_constraints_file()
        fileout.close_file()
        fileout = ValidatorCodeFile.ValidatorCodeFile(self.language,
                                                      self.package,
                                                      'declared',
                                                      valid_type)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.write_constraints_file('declared')
        fileout.close_file()

    def write_validator_files(self, valid_type=''):
        if valid_type == '':
            # write the main PkgValidator files
            fileout = ValidatorHeaderFile.ValidatorHeaderFile(self.language,
                                                              self.package,
                                                              'main',
                                                              valid_type)
            if self.verbose:
                print('Writing file {0}'.format(fileout.filename))
            fileout.write_main_file()
            fileout.close_file()
            fileout = ValidatorCodeFile.ValidatorCodeFile(self.language,
                                                          self.package,
                                                          'main',
                                                          valid_type,
                                                          self.sbml_classes)
            if self.verbose:
                print('Writing file {0}'.format(fileout.filename))
            fileout.write_main_file()
            fileout.close_file()

        # write the consistency validator files
        fileout = ValidatorHeaderFile.ValidatorHeaderFile(self.language,
                                                          self.package,
                                                          'consistency',
                                                          valid_type)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.write_file()
        fileout.close_file()
        fileout = ValidatorCodeFile.ValidatorCodeFile(self.language,
                                                      self.package,
                                                      'consistency',
                                                      valid_type)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
        fileout.write_file()
        fileout.close_file()

    def write_error_header(self):
        class_desc = ({})
        class_desc['name'] = '{0}{1}Error'.format(self.up_package,
                                                self.cap_language)
        class_desc['attribs'] = []
        self.error_file = CppHeaderFile.CppHeaderFile(class_desc, False)
        if self.verbose:
            print('Writing file {0}'.format(self.error_file.filename))
        self.write_error_file()
        self.error_file.close_file()

    def write_error_table_header(self):
        class_desc = ({})
        class_desc['name'] = '{0}{1}ErrorTable'.format(self.up_package,
                                                     self.cap_language)
        class_desc['attribs'] = []
        self.error_file = CppHeaderFile.CppHeaderFile(class_desc, False)
        if self.verbose:
            print('Writing file {0}'.format(self.error_file.filename))
        self.write_error_table_file()
        self.error_file.close_file()

    #########################################################################

    # Functions to write the error table file

    def write_error_table_file(self):
        BaseCppFile.BaseCppFile.write_file(self.error_file)
        self.error_file.write_defn_begin()
        self.error_file.write_line_verbatim('#include <{0}/packages/{1}/'
                                            'validator/{2}{3}Error'
                                            '.h>'.format(self.language,
                                                         self.package,
                                                         self.up_package,
                                                         self.cap_language))
        self.error_file.write_cppns_begin()
        self.error_file.write_doxygen_start()
        self.error_file.write_line('static const packageErrorTableEntry '
                                   '{0}ErrorTable[] '
                                   '='.format(self.package.lower()))
        self.error_file.write_line('{')
        for rule in self.class_rules:
            self.write_table_entry(rule)
        self.error_file.write_line('};')
        self.error_file.write_doxygen_end()
        self.error_file.write_cppns_end()
        self.error_file.write_defn_end()

    def write_table_entry(self, rule):
        self.error_file.up_indent()
        self.error_file.write_line('// {0}'.format(rule['number']))
        self.error_file.write_line('{0}  {1},'.format(self.open_br,
                                                    rule['typecode']))
        self.error_file.up_indent()
        self.error_file.write_line('\"{0}\",'.format(rule['short']))
        self.error_file.write_line('{0}_CAT_GENERAL_'
                                   'CONSISTENCY,'.format(self.cap_lib))
        self.error_file.write_line('{0},'.format(rule['lib_sev']))
        self.error_file.write_line_no_indent('\"{0}\",'.format(self.format_text(rule['text'])))
        self.error_file.write_line('{0}  \"{1}\"'.format(self.open_br,
                                                       rule['lib_ref']))
        self.error_file.write_line('{0}'.format(self.close_br))
        self.error_file.down_indent()
        self.error_file.write_line('},')
        self.error_file.down_indent()
        self.error_file.skip_line()

    def format_text(self, text_string):
        return_string = ''
        length = len(text_string)
        i = 0
        while i < length:
            letter = text_string[i]
            if letter == '\\':
                status = self.analyse_string(i, text_string, length)
                if status['is_uri']:
                    [i, ret_str] = self.replace_uri(i+4, text_string, length)
                elif status['is_number']:
                    ret_str = text_string[i+1:i+7]
                    i += 6
                elif status['is_sbml_l3']:
                    ret_str = 'SBML Level 3 Core'
                    i += 13
                elif status['is_token']:
                    [i, ret_str] = self.replace_token(i+6, text_string, length)
                elif status['is_class']:
                    [i, ret_str] = self.replace_class(i+6, text_string, length)
                elif status['is_type']:
                    [i, ret_str] = self.replace_type(i+9, text_string, length)
                elif status['is_val']:
                    [i, ret_str] = self.replace_type(i+4, text_string, length)
                elif status['is_package']:
                    [i, ret_str] = self.replace_package(i,
                                                        status['pkg_length'])
                else:
                    [i, ret_str] = self.replace_name(i, text_string, length)
                return_string += ret_str
            else:
                return_string += letter
            i += 1

        return return_string


    def analyse_string(self, i, text_string, length):
        state = dict({'is_uri': False,
                      'is_number': False,
                      'is_sbml_l3': False,
                      'is_token': False,
                      'is_class': False,
                      'is_type': False,
                      'is_val': False,
                      'is_package': False,
                      'pkg_length': 0})
        if text_string[i+1] == '#':
            state['is_number'] = True
            return state

        start_str = text_string[i:i+4]
        if start_str == '\\uri':
            state['is_uri'] = True
            return state

        start_str = text_string[i:i+4]
        if start_str == '\\val':
            state['is_val'] = True
            return state

        start_str = text_string[i:i+14]
        if start_str == '\\sbmlthreecore':
            state['is_sbml_l3'] = True
            return state

        start_str = text_string[i:i+6]
        if start_str == '\\token':
            state['is_token'] = True
            return state

        start_str = text_string[i:i+6]
        if start_str == '\\class':
            state['is_class'] = True
            return state

        start_str = text_string[i:i+9]
        if start_str == '\\primtype':
            state['is_type'] = True
            return state

        [is_package, pkg_len] = self.is_package(i, text_string, length)
        if is_package:
            state['is_package'] = True
            state['pkg_length'] = pkg_len
            return state

        return state


    def is_package(self, i, text_string, length):
        is_package = False
        word = ''
        while (i < length-1):
            letter = text_string[i]
            if letter == ' ' or letter == ',' or letter == '.':
                break;
            else:
                word += letter
                i += 1
                continue
        len_word = len(word)
        end_word = word[len_word-7:len_word]
        if end_word == 'Package':
            is_package = True
        return [is_package, len_word]


    def replace_name(self, i, text_string, length):
        in_name = True
        return_name_rep = ''
        while (in_name and i < length):
            letter = text_string[i]
            if i != length-1:
                next_letter = text_string[i+1]
            else:
                next_letter = ' '
            if letter == '\\':
                return_name_rep += '<{0}'.format(next_letter.lower())
                i += 1
            elif next_letter == ' ' or next_letter == '.':
                return_name_rep += '{0}>'.format(letter)
                in_name = False
            else:
                return_name_rep += letter
            i += 1
            continue
        return [i-1, return_name_rep]


    def replace_uri(self, i, text_string, length):
        in_uri = True
        return_uri_rep = ''
        while (in_uri and i < length):
            letter = text_string[i]
            if i != length-1:
                next_letter = text_string[i+1]
            else:
                next_letter = ' '
            if letter == '{':
                return_uri_rep += '\''
            elif letter == '}' or next_letter == ' ':
                return_uri_rep += '\''
                in_uri = False
            else:
                return_uri_rep += letter
            i += 1
            continue
        return [i-1, return_uri_rep]


    def replace_token(self, i, text_string, length):
        in_token = True
        return_token_rep = ''
        while (in_token and i < length):
            letter = text_string[i]
            if i != length-1:
                next_letter = text_string[i+1]
            else:
                next_letter = ' '
            if letter == '{':
                return_token_rep += '\''
            elif letter == '}' or next_letter == ' ':
                return_token_rep += '\''
                in_token = False
            elif letter == '\\' and next_letter == '-':
                i += 2
                continue
            else:
                return_token_rep += letter
            i += 1
            continue
        return [i-1, return_token_rep]


    def replace_class(self, i, text_string, length):
        in_class = True
        return_class_rep = ''
        while (in_class and i < length):
            letter = text_string[i]
            if i != length-1:
                next_letter = text_string[i+1]
            else:
                next_letter = ' '
            if letter == '{':
                return_class_rep += '<{0}'.format(next_letter.lower())
                i += 1
            elif letter == '}' or next_letter == ' ':
                return_class_rep += '>'
                in_class = False
            else:
                return_class_rep += letter
            i += 1
            continue
        # if we have <sBML> turn it back to just SBML
        if return_class_rep == '<sBML>':
            return_class_rep = '<sbml>'
        return [i-1, return_class_rep]


    def replace_type(self, i, text_string, length):
        in_type = True
        return_type_rep = ''
        while (in_type and i < length):
            letter = text_string[i]
            if i != length-1:
                next_letter = text_string[i+1]
            else:
                next_letter = ' '
            if letter == '{':
                return_type_rep += '\'{0}'.format(next_letter)
                i += 1
            elif letter == '}' or next_letter == ' ':
                return_type_rep += '\''
                in_type = False
            else:
                return_type_rep += letter
            i += 1
            continue
        return [i-1, return_type_rep]


    def replace_package(self, i, pkg_length):
        return_token_rep = '{0} Package'.format(self.fullname)
        return [i+pkg_length-1, return_token_rep]


    #########################################################################

    # Functions to write the error enumeration file

    def write_error_file(self):
        BaseCppFile.BaseCppFile.write_file(self.error_file)
        self.error_file.write_defn_begin()
        self.error_file.write_cppns_begin()
        self.error_file.write_cdecl_begin()
        self.error_file.write_line('typedef enum')
        self.error_file.write_line('{')
        first = True
        for rule in self.class_rules:
            self.write_rule(rule['typecode'], rule['number'], first)
            first = False
        self.error_file.file_out.write('} ')
        self.error_file.file_out.write('{0}{1}'
                                       'ErrorCode_t'
                                       ';\n'.format(self.up_package,
                                                    self.cap_language))
        self.error_file.write_cdecl_end()
        self.error_file.write_cppns_end()
        self.error_file.write_defn_end()

    def write_rule(self, tc, number, first):
        if first:
            self.error_file.file_out.write('  {0:{width}}'.format(tc, width=60))
        else:
            self.error_file.file_out.write(', {0:{width}}'.format(tc, width=60))
        self.error_file.file_out.write('= {0}\n'.format(number))
