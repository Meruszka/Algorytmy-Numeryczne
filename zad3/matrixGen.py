
initState = [1, -1, 0]
d = {
    "1,1": 0,
    "0,0": 0,
    "-1,-1": 0,
    "1,0": 0,
    "1,-1": 0,
    "0,-1": 0
}
for x in range(len(initState)):
    for y in range(x+1, len(initState)):

        if initState[x] == 1 and initState[y] == 1:
            d["1,1"] += 1

        if initState[x] == 0 and initState[y] == 0:
            d["0,0"] += 1

        if initState[x] == -1 and initState[y] == -1:
            d["-1,-1"] += 1

        if initState[x] == 1 and initState[y] == 0 or initState[x] == 0 and initState[y] == 1:
            d["1,0"] += 1

        if initState[x] == 1 and initState[y] == -1 or initState[x] == -1 and initState[y] == 1:
            d["1,-1"] += 1

        if initState[x] == 0 and initState[y] == -1 or initState[x] == -1 and initState[y] == 0:
            d["0,-1"] += 1

print(d)
sum = 0
for x in d.keys():
    sum += d[x]
print(sum)