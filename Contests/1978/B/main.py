for i in range(int(input(""))):
    inp1 = input("").split(" ")
    n = int(inp1[0])
    a = int(inp1[1])
    b = int(inp1[2])
    sales = 0
    if b > a:
        k = b - a
        if k >= n:
            k = n
        sales += (k / 2) * (2 * b + ((k - 1) * -1))
        sales += (n - k) * a
        print(int(sales))
    else:
        sales += n * a
        print(int(sales))
