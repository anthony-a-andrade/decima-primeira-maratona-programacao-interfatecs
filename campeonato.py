N = int(input())
equipes = {}

for n in range(N):
    equipe = input().split(' ')
    equipes[equipe[0]] = [0, 0, 0, 0, equipe[1]]

K = int(input())
for k in range(K):
    jogo = input().split(' ')
    T1 = jogo[0]
    T2 = jogo[1]
    P1 = int(jogo[2])
    P2 = int(jogo[3])

    equipes[T1][2] = equipes[T1][2] + (P1 - P2)
    equipes[T2][2] = equipes[T2][2] + (P2 - P1)
    equipes[T1][3] = equipes[T1][3] + P1
    equipes[T2][3] = equipes[T2][3] + P2

    if P1 > P2:
        equipes[T1][0] = equipes[T1][0] + 3
        equipes[T1][1] = equipes[T1][1] + 1
    elif P2 > P1:
        equipes[T2][0] = equipes[T2][0] + 3
        equipes[T2][1] = equipes[T2][1] + 1
    else:
        equipes[T1][0] = equipes[T1][0] + 1
        equipes[T2][0] = equipes[T2][0] + 1

equipes = [equipes[key] for key in equipes.keys()]
equipes.sort(reverse=True)

print("%s CAMPEAO" % (equipes[0][4]))
print("%s SEGUNDO LUGAR" % (equipes[1][4]))
print("%s TERCEIRO LUGAR" % (equipes[2][4]))