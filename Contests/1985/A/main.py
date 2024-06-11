t = int(input(""))

for i in range(t):
    inp = input("").split(" ")
    temp = inp[0][0]
    a = inp[1][0] + inp[0][1:]
    b = temp + inp[1][1:]
    print(a, b)