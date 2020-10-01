#!/usr/bin/python3

def f_to_c(t):
    return (t - 32) * (5/9)

def c_to_f(t):
    return t * (9/5) + 32

def convert(input):
    input_scale = input[-1:].upper()
    input_value = input[0:-1]

    if not input_value.isnumeric():
        print('Invalid input!')
        return

    if input_scale == 'F':
        print(input_value + ' Fahrenheit equals ' + str(f_to_c(int(input_value))) + ' Celsius.')
    elif input_scale == 'C':
        print(input_value + ' Celsius equals ' + str(c_to_f(int(input_value))) + ' Fahrenheit.')
    else:
        print('Invalid input!')

i = input("Enter temperature to convert (e.g. 43F, 100C): ") 
convert(i)