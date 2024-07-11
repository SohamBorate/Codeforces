def min(arr):
    min = 100
    index = -1
    for i in range(len(arr)):
        if arr[i] < min:
            index = i
            min = arr[i]
    return index

for i in range(int(input(""))):
    inp1 = input("").split(" ")
    a = int(inp1[0])
    b = int(inp1[1])
    c = int(inp1[2])
    arr = [a, b, c]
    for i in range(5):
        arr[min(arr)] += 1
    total = arr[0] * arr[1] * arr[2]
    print(total)