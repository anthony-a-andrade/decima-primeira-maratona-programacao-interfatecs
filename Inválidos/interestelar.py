N = int(input())
[L, U] = [int(x) for x in input().split(' ')]

if L > U:
    temp = L
    L = U
    U = temp

Dados = [int(input()) for x in range(N)]

while True:
    try:
        [X, Y] = [int(x) for x in input().split(' ')]
        if X > Y:
            temp = X
            X = Y
            Y = temp
        
        DadosSelecionados = [Dados[x] for x in range(X, Y + 1)]
        Quantidade = len([x for x in DadosSelecionados if x >= L and x <= U])
        print(Quantidade)
    except:
        break