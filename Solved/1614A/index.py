iterations = int(input(""))
bought = []

for i in range(iterations):
    ins = input("").split(" ")
    n = int(ins[0])
    l = int(ins[1])
    r = int(ins[2])
    k = int(ins[3])
    c = input("").split(" ")
    s = 0
    for i in range(len(c)):
        c[i] = int(c[i])
    c.sort()
    p = []
    for a in c:
        if l <= a and a <= r:
            if (s + a) <= k:
                p.append(a)
                s += a
            else:
                break
    bought.append(len(p))

for i in bought:
    print(i)