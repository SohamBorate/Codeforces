for i in range(int(input(""))):
    inp1 = input("").split(" ")
    n = int(inp1[0])
    k = int(inp1[1])
    result = (2 ** (n-k+1)) + ((k-1)*2)
    print(result)
