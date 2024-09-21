for i in range(int(input(""))):
    inp1 = input("").split(" ")
    n = int(inp1[0])
    k = int(inp1[1])
    inp2 = input("").split(" ")
    a = []
    for j in range(len(inp2)):
        a.append(int(inp2[j]))
    #print(n, k)
    #print(a)
    #print("")

    gold = 0
    people = 0

    for money in a:
        if money >= k:
            gold = gold + money
            #print("take")
        elif money == 0:
            if gold > 0:
                #print("give")
                gold = gold - 1
                people = people + 1

    #print("")
    #print(gold)
    print(people)
    #print("\n")
