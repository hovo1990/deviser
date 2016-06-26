import os


# command = 'javap -p org.sbml.jsbml.CompartmentalizedSBase'

def print_output(output):
    for line in output:
        print(line)

def clean_line(data):
    temp = []
    for i in data:
        if i !='':
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

    if len(temp_data) == 1 and temp_data[-1] == '}':
        return 

    for i in range(len(temp_data)):
        if temp_data[0] == 'Compiled':
            return
        if len(temp_data) == 1 and temp_data[-1] == '}':
            return 
        # Function Arguments extracter
        if '(' in temp_data[i]:
            #print('i is ',i)
            function_name_step1  = temp_data[i].split('(')
            #print('function_name_step1 ',function_name_step1)
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
                        #print('y ',temp_data[y])
                        if ',' in temp_data[y]:
                            arg = function_name_step1[-1].split(',')[0]
                            arguments.append(arg)
                        elif ');' in function_name_step1[-1]:
                            arg = function_name_step1[-1].split(');')[0]
                            arguments.append(arg)
            elif function_name_step1[-1] == ');':
                break

            # else:
            #     arg = function_name_step1[-1].split(',')[0]
            #     arguments.append(arg)
            #     for y in range(len(temp_data[function_index+1:])):
            #         print('y is ',temp_data[y])
            # print(function_name,'--', function_index) # THis works
            # function_name_step2  = function_name_step1[-1].split(');')
            # print(function_name_step2)
        elif '<' in temp_data[i]:
            type_of_name_step1  = temp_data[i].split('<')
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
                        #print('y ',temp_data[y])
                        if ',' in temp_data[y]:
                            arg = type_of_name_step1[-1].split(',')[0]
                            of_type_args.append(arg)
                        elif '>' in type_of_name_step1[-1]:
                            arg = type_of_name_step1[-1].split('>')[0]
                            of_type_args.append(arg)

    if temp_data[0] in ['public', 'private', 'protected']:
        access_type = temp_data[0]

    

    if len(temp_data) > 1 and temp_data[1] == 'abstract':
        is_abstract = True 
        return_type = temp_data[2]
    elif temp_data[1] == 'void':
        return_type = temp_data[1]
    else:
        return_type = temp_data[1]


    if function_name == '':
        return

    # print('access_type ',access_type)
    # print('is_abstract ',is_abstract)
    # print('return_type ',return_type)
    # print('function_name ',function_name)
    # print('arguments ',arguments)

    # print('of_type ',of_type)
    # print('of_type_args ',of_type_args)
    

    return {'accessType':access_type,'isAbstract':is_abstract, 
            'returnType':return_type, 'functionName':function_name,
            'functionArgs':arguments, 'of_type':of_type, 
            'of_type_args':of_type_args, 'originalData':temp_data}
    # function_name = function_name_step2[0] 
    # print('function_name ',function_name)
    # print('------------------')           


def parse_output(output):
    output_data = []
    for line in output:
        #print(line) 
        data_stage1 = line.split('\n')
        # print(data_stage1)       
        data_stage2 = data_stage1[0].split(' ')
        temp_data = clean_line(data_stage2)
        # print(line)
        # print(temp_data)
    
        data = extract_data(temp_data)

        # print('data is ', data)
        # print('-----------')
        if data is not None:
            output_data.append(data)

        
        # if '{' in temp_data:
        #     output_data.update({'classInfo':temp_data[:-1]})
        # elif function_name in temp_data:
        #     output_data.update({'methods':temp_data})
        # print('->'*20)
        # print('\n')
    return output_data

def get_class_information(class_name=None):
    class_name = 'org.sbml.jsbml.{0}'.format(class_name)
    command = 'javap -package {0}'.format(class_name)
    class_output  = os.popen('{0}'.format(command)).readlines()
    # print_output(class_output)
    dict_data = parse_output(class_output)
    return dict_data




# get_class_information()

# class_name = 'org.sbml.jsbml.CompartmentalizedSBase'

# class_name = 'org.sbml.jsbml.AbstractNamedSBase'
# data = get_class_information(class_name)
# print(data)