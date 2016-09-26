#!/usr/bin/env python
#
# @file    insideJSBML_parser.py
# @brief   JSBML classes parser using javap for GSoC 2016
# @author  Hovakim Grabski
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

import os
import sys
from java_utils import insideJSBML_parser
from java_utils import jsbml_data_tree

# try:
#     import cPickle as pickle
# except:
import pickle
import json

jsbml_data = jsbml_data_tree.jsbml_data_tree

file_path = os.path.dirname(os.path.abspath(__file__)) + '/../java_utils/'





# print(jsbml_data)

def save_JSBML_data_to_pickle():
    '''The purpose of this script is to save JSBML parsed data tree
    from javap parser to pickle so that deviser would not depend on javap,
    generally. If new JSBML version comes out simply use this script to save
    pickle '''
    # Run twice : python2 and python3
    jsbml_parsed_data = {}
    # insideJSBML_parser.get_class_information(module) to get module info
    for module in jsbml_data:
        # print(module)
        data = insideJSBML_parser.get_class_information(module, extract_data=True)
        # print(data)
        if data is not None:
            jsbml_parsed_data.update({module: data})

    # print(jsbml_parsed_data)
    # just 400 kB can solve javap, ok technichally 800kB for py2 and py3 dependency problem
    python_version = sys.version_info
    print(python_version)
    if python_version[0] == 3:
        suffix = 'py3'
    elif python_version[0] == 2:
        suffix = 'py2'
    file_name = 'jsbml_parsed_data_{0}.pickle'.format(suffix)
    pickle.dump(jsbml_parsed_data, open(file_path + "/{0}".format(file_name), "wb"))




def save_JSBML_data_to_json():
    '''The purpose of this script is to save JSBML parsed data tree
    from javap parser to json so that deviser would not depend on javap,
    generally. If new JSBML version comes out simply use this script to save
    pickle '''
    # Run twice : python2 and python3
    jsbml_parsed_data = {}

    # a New prototype for extracting all names
    jsbml_class_names = insideJSBML_parser.extract_jsbml_class_names_from_jar()

    # new version where extract class data from jar classes
    # insideJSBML_parser.get_class_information(module) to get module info
    # There are some bugs afterwards
    # for module in jsbml_class_names:
    #     # print(module)
    #     data = insideJSBML_parser.get_class_information_jar(module, extract_data=True)
    #     # print(data)
    #     if data is not None:
    #         jsbml_parsed_data.update({module: data})



    # old version where extract data from jsbml data tree
    # insideJSBML_parser.get_class_information(module) to get module info
    for module in jsbml_data:
        # print(module)
        data = insideJSBML_parser.get_class_information(module, extract_data=True)
        # print(data)
        if data is not None:
            jsbml_parsed_data.update({module: data})


    file_name = 'jsbml_parsed_data.json'
    json.dump(jsbml_parsed_data, open(file_path + "/{0}".format(file_name), "w"), sort_keys=True, indent=4)


# save_JSBML_data_to_pickle()
save_JSBML_data_to_json()
