for i in range(int(input(""))):
    n = int(input(""))
    s = input("")
    memory = []
    printed = []
    for i in range(n):
        if s[i] == "1":
            memory.append(i + 1)
        elif s[i] == "2":
            if len(memory) == 0:
                printed.append(i + 1)
            else:
                printed.append(memory.pop())
        elif s[i] == "3":
            printed.append(i + 1)
    print(n - len(printed))
    notprinted = []
    for i in range(n):
        if i + 1 not in printed:
            notprinted.append(i + 1)
    print(*notprinted)

