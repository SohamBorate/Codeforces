t = int(input(""))

for i in range(t):
    n = int(input(""))
    max = 0
    index = -1
    for x in range(2, n + 1):
        sum = 0
        k = 0
        while ((x * k) <= n):
            sum += x * k
            k += 1
        if (sum > max):
            max = sum
            index = x
    
    print(index)
