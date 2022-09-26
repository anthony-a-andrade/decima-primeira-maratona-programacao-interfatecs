#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Equipe {
    int ID;
    char Nome[20];
    int Vitorias;
    int Pontos;
    int SaldoGols;
    int GolsFeitos;
} Equipe;

void aumentar_equipe(Equipe equipes[], int N, int id, int vitorias, int pontos, int saldo, int gols) {
    int n;
    for (n = 0; n < N; n++) {
        if (equipes[n].ID == id) {
            equipes[n].Vitorias += vitorias;
            equipes[n].Pontos += pontos;
            equipes[n].SaldoGols += saldo;
            equipes[n].GolsFeitos += gols;
            break;
        }
    }
}

void ordenar(Equipe equipes[], int N) {
    int mudou = 0, n;
    do {
        mudou = 0;
        for (n = 0; n < N - 1; n++) {
            Equipe atual = equipes[n], prox = equipes[n + 1];
            int trocar = 0;

            if (atual.Pontos < prox.Pontos) trocar = 1;
            else if (atual.Pontos == prox.Pontos) {
                if (atual.Vitorias < prox.Vitorias) trocar = 1;
                else if (atual.Vitorias == prox.Vitorias) {
                    if (atual.SaldoGols < prox.SaldoGols) trocar = 1;
                    else if (atual.SaldoGols == prox.SaldoGols) {
                        if (atual.GolsFeitos < prox.GolsFeitos) trocar = 1;
                    }
                }
            }
            
            if (trocar) {
                Equipe temp = atual;
                equipes[n] = prox;
                equipes[n + 1] = temp;
                mudou = 1;
            }
        }
    } while (mudou != 0);
}

int main(void) {
    int N, n;
    scanf("%d", &N);
    getchar();

    Equipe equipes[N];
    for (n = 0; n < N; n++) {
        int ID;
        char Nome[20];
        scanf("%d %s", &ID, &Nome);
        getchar();      
        
        Equipe equipe;
        equipe.ID = ID;
        strcpy(equipe.Nome, Nome);
        equipe.Vitorias = 0;
        equipe.Pontos = 0;
        equipe.SaldoGols = 0;
        equipe.GolsFeitos = 0;
        equipes[n] = equipe;
    }
    
    int K, k;
    scanf("%d", &K);
    getchar();

    for (k = 0; k < K; k++) {
        int T1, T2, P1, P2;
        scanf("%d %d %d %d", &T1, &T2, &P1, &P2);
        getchar();

        aumentar_equipe(equipes, N, T1, 0, 0, P1 - P2, P1);
        aumentar_equipe(equipes, N, T2, 0, 0, P2 - P1, P2);

        if (P1 > P2) aumentar_equipe(equipes, N, T1, 1, 3, 0, 0);
        else if (P2 > P1) aumentar_equipe(equipes, N, T2, 1, 3, 0, 0);
        else {
            aumentar_equipe(equipes, N, T1, 0, 1, 0, 0);
            aumentar_equipe(equipes, N, T2, 0, 1, 0, 0);
        }
    }

    ordenar(equipes, N);
    
    printf("%s CAMPEAO\n", equipes[0].Nome);
    printf("%s SEGUNDO LUGAR\n", equipes[1].Nome);
    printf("%s TERCEIRO LUGAR\n", equipes[2].Nome);
    return 0;
}