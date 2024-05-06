import math
iterations = int(input(""))
print(iterations)

def distance(n1, m1, n, m):
    return math.sqrt((n1 - n)**2 + (m1 - m)**2)

def validate_move(move, n, m, grid):
    for i in range(len(move)):
        f = move[i]
        if f[0] < 1 or f[0] > n or f[1] < 1 or f[1] > m:
            move[i] = False
            continue
        if grid[f[0] - 1][f[1] - 1] != "#":
            move[i] = False

    return move

def pathfinding(grid, enemy, n, m):
    path = [[1,1]]
    while (enemy[0] != n or enemy[1] != m):
        move = []
        move.append([enemy[0] - 1, enemy[1]])
        move.append([enemy[0] + 1, enemy[1]])
        move.append([enemy[0], enemy[1] - 1])
        move.append([enemy[0], enemy[1] + 1])

        move = validate_move(move, n, m, grid)
        dist = distance(1, 1, n, m) * 10
        pos = []
        for i in move:
            if i:
                if [i[0],i[1]] != enemy[3]:
                    d = distance(i[0], i[1], n, m)
                    if d < dist:
                        dist = d
                        pos = [i[0], i[1]]

        enemy[3] = [enemy[0], enemy[1]]
        enemy[0] = pos[0]
        enemy[1] = pos[1]
        path.append([pos[0], pos[1]])

    return path

for i in range(iterations):
    ins = input("").split(" ")
    n = int(ins[0])
    m = int(ins[1])
    k = int(ins[2])
    print(n,m,k)

    grid = []
    for j in range(n):
        grid.append(input(""))
    print(grid)

    towers = []
    for j in range(k):
        ins = input("").split(" ")
        towers.append([
            int(ins[0]),
            int(ins[1]),
            int(ins[2])
        ])
    print(towers)

    enemy = [
        # position
        1,
        1,
        # health
        0,
        # previouse position
        [1,1]
    ]

    # pathfinding for enemy using pac man algorithm

    path = pathfinding(grid, enemy, n, m)
    print(path)

    # rank towers according to average distance

    for j in towers:
        s = 0
        for p in path:
            s += distance(p[0],p[1],j[0],j[1])

        j.append((s/len(path)) * j[2])

    def sortTowers(tower):
        return tower[3]

    towers.sort(reverse=True, key=sortTowers)
    print(towers)

    # tower ranges
    tr = []

    for i in range(len(towers)):
        tr.append(0)

    #for bh in range(1,9999999):
    for r in range(1,11):
        for j in range(0,len(towers)):
            for k in range(j + 1):
                tr[k] = r
            print(tr)
            # calculate
            d = 0
            rh = 0
            # calculate total damage possible with given range
            for k in range(len(tr)):
                tower = towers[k]
                set_range = tr[k]
                rh += 3 ** set_range
                for l in path:
                    if distance(l[0], l[1], tower[0], tower[1]) <= set_range:
                        d += tower[2]
            print(d,rh)

            

    print("\n\n=========================================\n\n")