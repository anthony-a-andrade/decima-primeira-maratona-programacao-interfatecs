while True:
    N = int(input())
    if N == 0: break

    raiz = N ** 0.5

    if str(raiz).split('.')[1] != '0': print("PERA AI... TA LIDANDO ERRADO!")
    else:
        AN = 1 + (raiz - 1) * 2
        print(int(AN))
