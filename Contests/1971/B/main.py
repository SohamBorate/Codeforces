import random
n = int(input(""))

strs = []

for i in range(n):
    strs.append(input(""))

def find(s,c):
    found = False
    for n in s:
        if c == n:
            found = True
            break
    return found

for s in strs:
    chars = []
    for n in range(len(s)):
        if find(chars, s[n]) == False:
            chars.append(s[n])
    if len(chars) == 1:
        print("NO")
    else:
        updated = list(s)
        while (("".join(updated)) == s):
            index = random.randint(0, len(s) - 1)
            temp1 = updated[index]
            temp2 = updated[0]
            updated[0] = temp1
            updated[index] = temp2
        print("YES")
        print("".join(updated))