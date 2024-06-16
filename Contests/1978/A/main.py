def find(arr, num):
    for i in arr:
        if i == num:
            return True
    return False

for i in range(int(input(""))):
    n = int(input(""))
    pages = input("").split(" ")
    if n == 2:
        print(int(pages[0]) + int(pages[1]))
    else:
        pile1 = []
        pile2 = []
        db = 0
        for j in range(len(pages)):
            number = int(pages[j])
            if len(pile1) == n - 1:
                pile2.append(number)
            elif len(pile2) == n - 1:
                pile1.append(number)
            elif db == 0:
                if find(pile2, number) == False:
                    pile1.append(number)
                    db = 1
                else:
                    pile2.append(number)
            else:
                if find(pile1, number) == False:
                    pile2.append(number)
                    db = 0
                else:
                    pile1.append(number)
        print(pile1[-1] + pile2[-1])

