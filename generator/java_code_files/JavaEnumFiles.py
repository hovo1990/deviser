#!/usr/bin/env python
#
# @file    CppFiles.py
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

import copy
# from . import JavaHeaderFile # No need for header files
from . import JavaEnumCodeFile
from util import strFunctions, query, global_variables


class JavaEnumFiles():
    """Class for all Java files"""

    def __init__(self, enum_object, original_package, verbose=False):
        # members from object
        self.enum_object = enum_object
        self.original_package = original_package
        # self.enum_object['is_list_of'] = False
        # self.enum_object['sid_refs'] = \
        #     query.get_sid_refs(enum_object['attribs'])
        # self.enum_object['unit_sid_refs'] = \
        #     query.get_sid_refs(enum_object['attribs'], unit=True)

        self.verbose = verbose

    def write_files(self):
        #self.write_header(self.class_object)
        self.write_code(self.enum_object, self.original_package)

    def write_list_enum_files(self):
        # self.write_header(self.class_object)
        self.write_list_enum_code(self.enum_object, self.original_package)

        # TODO what to do with listOf stuff
        # if self.class_object['hasListOf']:
        #     lo_working_class = self.create_list_of_description()
        #     #self.write_header(lo_working_class)
        #     self.write_code(lo_working_class)

    # def write_header(self, class_desc):
    #     fileout = JavaHeaderFile.JavaHeaderFile(class_desc)
    #     if self.verbose:
    #         print('Writing file {0}'.format(fileout.filename))
    #     fileout.write_file()
    #     fileout.close_file()

    def write_code(self, enum_object, original_object):
        fileout = JavaEnumCodeFile.JavaEnumCodeFile(enum_object, original_object)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
            print('---'*10)
        fileout.write_file()
        fileout.close_file()

    def write_list_enum_code(self, enum_object, original_object):
        fileout = JavaEnumCodeFile.JavaEnumCodeFile(enum_object, original_object)
        if self.verbose:
            print('Writing file {0}'.format(fileout.filename))
            print('---' * 10)
        fileout.write_list_enum_file()
        fileout.close_file()

    def create_list_of_description(self):
        # default list of name
        lo_name = strFunctions.list_of_name(self.enum_object['name'])
        # check that we have not specified this should be different
        if 'lo_class_name' in self.enum_object and \
                len(self.enum_object['lo_class_name']) > 0:
            lo_name = self.enum_object['lo_class_name']
        descrip = copy.deepcopy(self.enum_object)
        descrip['is_list_of'] = True
        descrip['attribs'] = self.enum_object['lo_attribs']
        descrip['child_base_class'] = self.enum_object['baseClass']
        if global_variables.is_package:
            descrip['baseClass'] = 'ListOf'
        else:
            descrip['baseClass'] = strFunctions.prefix_name('ListOf')
        descrip['list_of_name'] = lo_name
        descrip['lo_child'] = self.enum_object['name']
        descrip['name'] = lo_name
        return descrip

    def test_func(self):
        self.write_files()
