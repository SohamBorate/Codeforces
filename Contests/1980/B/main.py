t = int(input(""))

def find(arr, number):
    for cube in arr:
        if cube == number:
            return True
    return False

for i in range(t):
    inp1 = input("").split(" ")
    n = int(inp1[0])
    f = int(inp1[1])
    k = int(inp1[2])

    inp2 = input("").split(" ")
    cubes = []
    for number in inp2:
        cubes.append(int(number))

    favourite = cubes[f - 1]

    # print(n,f,k,cubes,favourite)

    cubes.sort(reverse=True)

    # print(n,f,k,cubes,favourite)

    # check if fav still remains
    remains = find(cubes[k:len(cubes)], favourite)
    removed = find(cubes[0:k], favourite)

    if remains and removed:
        print("MAYBE")
    elif removed:
        print("YES")
    elif remains:
        print("NO")
