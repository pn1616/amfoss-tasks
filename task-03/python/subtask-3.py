#Write a program that takes a number n from user and generates a diamond pattern of asterisks (*) and prints it to the console.

n = int(input("enter the number: "))

for i in range(1,n+1):
    for j in range(n-i):
        print(" ", end=" ")
    for k in range(i):
        print("*", end = " ")
    for l in range(k):
        print("*", end = " ")
    print(" ")
for i in range(n-1,0,-1):
    for j in range(n,i,-1):
        print(" ", end=" " )
    for k in range(i):
        print("*",end=" ")
    for l in range(k):
        print("*",end=" ")
    print(" ")