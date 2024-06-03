t = int(input(""))

for i in range(t):
    inp1 = input("").split(" ")
    n = int(inp1[0])
    m = int(inp1[1])

    inp2 = input("")

    problems = {
        "A": 0,
        "B": 0,
        "C": 0,
        "D": 0,
        "E": 0,
        "F": 0,
        "G": 0
    }

    for problem in inp2:
        problems[problem] += 1

    total = 0

    for problem in problems:
        number = problems[problem] - m
        if number < 0:
            total += number * -1

    print(total)


