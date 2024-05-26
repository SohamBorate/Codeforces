n = int(input(""))

for i in range(n):
    inp = input("").split(" ")
    n = int(inp[0])
    m = int(inp[1])

    if m > n:
        print("No")
    elif (n % 2) != (m % 2):
        print("No")
    else:
        print("Yes")
