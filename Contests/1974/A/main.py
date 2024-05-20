n = int(input(""))
#print(n, end="\n\n")

for i in range(n):
    inp = input("").split(" ")
    # 1x1
    y = int(inp[0])
    # 2x2
    x = int(inp[1])
    screens = 0
    #print(y, x)
    if (x == 0) and (y != 0):
        #print("Case 1")
        while (y > 0):
            screens += 1
            if (y >= 15):
                y -= 15
            else:
                y -= y
    elif (x != 0) and (y == 0):
        #print("Case 2")
        while (x > 0):
            screens += 1
            if (x >= 2):
                x -= 2
            elif (x == 1):
                x -= 1
    else:
        #print("Case 3")
        while (x > 0) or (y > 0):
            screens += 1
            if (x >= 2):
                x -= 2
                y -= 7
            elif (x == 1):
                x -= 1
                y -= 11
            elif (x == 0):
                y -= 15
            # print(y,x)
    print(screens)

