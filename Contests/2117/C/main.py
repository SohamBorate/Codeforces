for i in range(int(input(""))):
    inp1 = input("").split(" ")
    n = int(inp1[0])
    dic = {
        "-1": -1
    }
    inp2 = input("").split(" ")
    max_val = "-1"
    max_num = 0
    for k in inp2:
        if dic.get(k):
            dic[k] = dic.get(k) + 1
        else:
            dic[k] = 1
        if dic.get(k) > dic.get(max_val):
            max_val = k
        # print(k, dic[k], max_val)
        if int(k) > max_num:
            max_num = int(k)
    if max_num > int(max_val):
        print(dic[max_val])
    else:
        print(1)
