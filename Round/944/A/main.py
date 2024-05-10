n = int(input(""))

nums = []

for i in range(n):
    nums.append(input("").split(" "))

for g in nums:
    print(min(int(g[0]), int(g[1])), max(int(g[0]), int(g[1])))