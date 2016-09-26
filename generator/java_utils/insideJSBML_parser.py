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
import time
import subprocess as sub

file_path = os.path.dirname(os.path.abspath(__file__))
jsbml_jar = 'jsbml-1.1-with-dependencies.jar'

curr_dir = os.getcwd()


def print_output(output):
    for line in output:
        print(line)


# Clean string line from '' and return list
def clean_line(data):
    temp = []
    for i in data:
        if i != '':
            temp.append(i)
    return temp


def extract_data(temp_data):
    # print('temp_data ',temp_data)
    # function_name_step1  = temp_data[-1].split(');')
    # print(function_name_step1)

    function_name = ''
    access_type = None
    is_abstract = False
    return_type = []
    arguments = []
    of_type = ''
    of_type_args = []

    # TODO this is the part that includes extends module
    if len(temp_data) == 1 and temp_data[-1] == '}':
        return

    for i in range(len(temp_data)):
        if temp_data[0] == 'Compiled':
            return
        if len(temp_data) == 1 and temp_data[-1] == '}':
            return
            # Function Arguments extracter
        if '(' in temp_data[i]:
            # print('i is ',i)
            function_name_step1 = temp_data[i].split('(')
            # print('function_name_step1 ',function_name_step1)
            function_name = function_name_step1[0]
            function_index = i
            if function_name_step1[-1] != ');':
                if ');' in function_name_step1[-1]:
                    arg = function_name_step1[-1].split(');')[0]
                    arguments.append(arg)
                else:
                    arg = function_name_step1[-1].split(',')[0]
                    arguments.append(arg)
                    for y in range(function_index, len(temp_data)):
                        # print('y ',temp_data[y])
                        if ',' in temp_data[y]:
                            arg = function_name_step1[-1].split(',')[0]
                            arguments.append(arg)
                        elif ');' in function_name_step1[-1]:
                            arg = function_name_step1[-1].split(');')[0]
                            arguments.append(arg)
            elif function_name_step1[-1] == ');':
                break
        elif '<' in temp_data[i]:
            type_of_name_step1 = temp_data[i].split('<')
            of_type = type_of_name_step1[0]
            type_index = i
            if type_of_name_step1[-1] != '>':
                if '>' in type_of_name_step1[-1]:
                    arg = type_of_name_step1[-1].split('>')[0]
                    of_type_args.append(arg)
                else:
                    arg = type_of_name_step1[-1].split(',')[0]
                    of_type_args.append(arg)
                    for y in range(type_index, len(temp_data)):
                        # print('y ',temp_data[y])
                        if ',' in temp_data[y]:
                            arg = type_of_name_step1[-1].split(',')[0]
                            of_type_args.append(arg)
                        elif '>' in type_of_name_step1[-1]:
                            arg = type_of_name_step1[-1].split('>')[0]
                            of_type_args.append(arg)

    if len(temp_data) > 0:
        if temp_data[0] in ['public', 'private', 'protected']:
            access_type = temp_data[0]

    if len(temp_data) > 1 and temp_data[1] == 'abstract':
        is_abstract = True
        return_type = temp_data[2]
    elif len(temp_data) > 1:
        if temp_data[1] == 'void':
            return_type = temp_data[1]
    else:
        # return_type = temp_data[1]
        return_type = None

    if function_name == '':
        return

    return {'accessType': access_type, 'isAbstract': is_abstract,
            'returnType': return_type, 'functionName': function_name,
            'functionArgs': arguments, 'of_type': of_type,
            'of_type_args': of_type_args, 'originalData': temp_data}


def parse_extends(extends):
    data_extends = {}
    data_extends.update({'accessType': extends[0]})

    if extends[1] == 'interface':
        is_interface = True
        data_extends.update({'extendsOriginal': extends[2]})
    else:
        is_interface = False
        data_extends.update({'extendsOriginal': extends[3]})
    data_extends.update({'isInterface': is_interface})

    if extends[1] == 'class':
        is_class = True
    else:
        is_class = False
    data_extends.update({'isClass': is_class})

    data_extends.update({'extendsFull': extends[-2]})

    extend_short = extends[-2].split('.')[-1]
    data_extends.update({'extendsShort': extend_short})

    data_extends.update({'fullText': extends})
    return data_extends


def parse_output(output):
    final_data = {}
    output_data = []
    for line in output:
        # print(line)
        data_stage1 = line.split('\n')
        # print(data_stage1)       
        data_stage2 = data_stage1[0].split(' ')
        # Need to catch extend here
        if 'extends' in data_stage2:
            final_data.update({'extends': parse_extends(data_stage2)})

        temp_data = clean_line(data_stage2)
        data = extract_data(temp_data)

        if data is not None:
            output_data.append(data)

    final_data.update({'modules': output_data})
    return final_data  # output_data


def parse_jar_output(jar_output):
    output_data = []
    for line in jar_output:
        # print(line)
        data_stage1 = line.split(' ')
        # print(data_stage1)
        # print(data_stage1[-1])

        data_stage2 = data_stage1[-1].split('/')

        temp_class = ''
        if 'sbml' in data_stage2 and 'jsbml' in data_stage2:
            if 'ext' not in data_stage2 and 'test' not in data_stage2:
                if 'parsers' not in data_stage2:
                    if 'compiler' not in data_stage2:
                        if 'class' in data_stage2[-1]:
                            data_stage2[-1] = data_stage2[-1].split('.')[0]
                            # print(data_stage2)
                            for i in data_stage2:
                                temp_class += i + '.'
                            output_data.append(temp_class[:-1])

    # Extract all jsbml class names
    return output_data  # output_data

def extract_jsbml_class_names_from_jar():
    comm1 = 'jar'
    comm2 = 'tvf'
    comm3 = '{0}{1}{2}'.format(file_path, os.sep, jsbml_jar)
    total_command = [comm1, comm2, comm3]
    print(total_command)

    try:
        class_info = sub.Popen(total_command, stdout=sub.PIPE, stderr=sub.PIPE)
        stdout, stderr = class_info.communicate()

        if stdout:
            # For debugging purposes
            # print(stdout)
            stdout_value = stdout.decode()  # decode("utf-8")
            class_output = stdout_value.split('\n')
            # print(class_output)
            class_data = parse_jar_output(class_output)
            print(class_data)
            return class_data
        elif stderr:
            error_txt = stderr.decode()
            # print('ERROR is', error_txt)
            if 'Error: class not found:' in error_txt:
                return
            else:
                if extract_data is False:
                    print('Check if Java SDK is installed, deviser requires javap')
                    sys.exit(0)
                else:
                    return
    except Exception as error:
        if extract_data is False:
            print('Error is ', error)
            print('Check if Java SDK is installed, deviser requires javap')
            sys.exit(0)


def get_class_information_jar(class_name=None, individual_run=False, extract_data=False):
    # if class_name == 'AbstractSBasePlugin':
    #     # class_name = 'org.sbml.jsbml.ext.{0}'.format(class_name)
    #     return
    # else:
    #     class_name = 'org.sbml.jsbml.{0}'.format(class_name)

    # Old version
    # command = 'javap -cp {0}{1}{2} -package {3}'.format(file_path, os.sep, jsbml_jar, class_name)

    # TODO inside JSBML parser debugging test
    # comm1 = 'javap_wrong'



    comm1 = 'javap'
    comm2 = '-cp'
    comm3 = '{0}{1}{2}'.format(file_path, os.sep, jsbml_jar)
    comm4 = '-package'
    comm5 = '{0}'.format(class_name)
    total_command = [comm1, comm2, comm3, comm4, comm5]

    try:
        class_info = sub.Popen(total_command, stdout=sub.PIPE, stderr=sub.PIPE)
        stdout, stderr = class_info.communicate()

        if stdout:
            # For debugging purposes
            # print(stdout)
            stdout_value = stdout.decode()  # decode("utf-8")
            class_output = stdout_value.split('\n')
            dict_data = parse_output(class_output)
            return dict_data
        elif stderr:
            error_txt = stderr.decode()
            print('ERROR is', error_txt)
            if 'Error: class not found:' in error_txt:
                return
            else:
                if extract_data is False:
                    print('Check if Java SDK is installed, deviser requires javap')
                    sys.exit(0)
                else:
                    return
    except Exception as error:
        if extract_data is False:
            print('Error is ', error)
            print('Check if Java SDK is installed, deviser requires javap')
            sys.exit(0)




def get_class_information(class_name=None, individual_run=False, extract_data=False):
    if class_name == 'AbstractSBasePlugin':
        # class_name = 'org.sbml.jsbml.ext.{0}'.format(class_name)
        return
    else:
        class_name = 'org.sbml.jsbml.{0}'.format(class_name)

    # Old version
    # command = 'javap -cp {0}{1}{2} -package {3}'.format(file_path, os.sep, jsbml_jar, class_name)

    # TODO inside JSBML parser debugging test
    # comm1 = 'javap_wrong'



    comm1 = 'javap'
    comm2 = '-cp'
    comm3 = '{0}{1}{2}'.format(file_path, os.sep, jsbml_jar)
    comm4 = '-package'
    comm5 = '{0}'.format(class_name)
    total_command = [comm1, comm2, comm3, comm4, comm5]

    try:
        class_info = sub.Popen(total_command, stdout=sub.PIPE, stderr=sub.PIPE)
        stdout, stderr = class_info.communicate()

        if stdout:
            # For debugging purposes
            # print(stdout)
            stdout_value = stdout.decode()  # decode("utf-8")
            class_output = stdout_value.split('\n')
            dict_data = parse_output(class_output)
            return dict_data
        elif stderr:
            error_txt = stderr.decode()
            print('ERROR is', error_txt)
            if 'Error: class not found:' in error_txt:
                return
            else:
                if extract_data is False:
                    print('Check if Java SDK is installed, deviser requires javap')
                    sys.exit(0)
                else:
                    return
    except Exception as error:
        if extract_data is False:
            print('Error is ', error)
            print('Check if Java SDK is installed, deviser requires javap')
            sys.exit(0)


# For testing purposes

# class_name = 'org.sbml.jsbml.AbstractNamedSBase'

# class_name = 'CompartmentalizedSBase'

# class_name = 'Compartment'
# class_name = 'SBaseWithDerivedUnit'
# class_name = 'NamedSBaseWithDerivedUnit'

# class_name = 'UniqueNamedSBase'


# TODO for individual tests of javap parser
# #Exist but no data
# class_name = 'AbstractSBasePlugin'
# data = get_class_information(class_name, individual_run=True)
# print(data)

# data = get_class_information(class_name, individual_run=True)
# print(data)
