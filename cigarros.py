while True:
    [N, K] = [int(x) for x in input().split(' ')]
    if N + K == 0: break

    total = N
    bitucas = N

    while bitucas >= K:
        temp = bitucas // K
        resto = bitucas % K
        total = total + temp
        bitucas = temp + resto

    print(total)