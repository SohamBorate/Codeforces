for i in range(int(input(""))):
    inp1 = input("").split(" ")
    n = int(inp1[0])
    x = int(inp1[1])
    inp2 = input("").split(" ")

    index = 0
    start = -1
    end = -1
    start_found = False

    for k in inp2:
        if k == "1":
            if not start_found:
                start_found = True
                start = index
            else:
                end = index
        index = index + 1
    # print(n,x,inp2,start,end)
    if (end - start + 1) <= x:
        print("yes")
    else:
        print("no")
