t = []

for i in range(10):
    t.append(0)

for i in range(1,11):
    for j in range(1,11):
        for k in range(j):
            t[k] = i
        print(t)