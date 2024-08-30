'''Write a program that reads a number n from a file named
input.txt and generates a diamond pattern of asterisks (*) in another file
named output.txt.'''

def read_number_from_file(filename):
    with open(filename, 'r') as inputfile:
        num = inputfile.read()
    return int(num.strip())

def write_number_to_file(filename, content):
    with open(filename, 'w') as infile:
        infile.write(content)

def generate_pattern(n):
    pattern = []

    for i in range(n):
        line = ' ' * (n - i - 1) + '*' * (2 * i + 1)
        pattern.append(line)
        
    for i in range(n - 2, -1, -1):
        line = ' ' * (n - i - 1) + '*' * (2 * i + 1)
        pattern.append(line)
        
    return "\n".join(pattern)

def write_pattern_to_file(filename, pattern):
    with open(filename, 'w') as outfile:
        outfile.write(pattern)

inputcontent = input("Enter the number: ")
write_number_to_file('input2.txt', inputcontent)
n = read_number_from_file('input2.txt')
result = generate_pattern(n)
write_pattern_to_file('output2.txt', result)
