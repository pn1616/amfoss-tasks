#Write a program that reads a string from a file named input.txt and writes that string to another file named output.txt

def subtask2():
    with open('input.txt', 'r') as infile:
        content = infile.read()
    with open('output.txt', 'w') as outfile:
        outfile.write(content)
    with open('output.txt', 'r') as outfile:
        final = outfile.read()
    return final

inputcontent = input("Content of the file: \n")

with open('input.txt', 'w') as infile:
    infile.write(inputcontent)


print("printing output.txt...")
result = subtask2()
print(result)
