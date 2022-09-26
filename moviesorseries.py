ian = 29
hellen = 26

while True:
    A = int(input())
    if A == 0: break
    elif A == 98:
        ian = ian + 1
        print("IAN BIRTHDAY, GO OUT FOR DINNER")
        continue
    elif A == 99:
        hellen = hellen + 1
        print("HELLEN BIRTHDAY, GO OUT FOR DANCING")
        continue

    B = int(input())

    soma = A + B + ian + hellen
    if soma % 2 == 0: print("WATCH SERIES")
    else: print("WATCH MOVIE")