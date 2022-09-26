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

void merge(Equipe equipes[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m, i, j, k;

    Equipe L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = equipes[l + i];
    for (j = 0; j < n2; j++) R[j] = equipes[m + j + 1];

	i = 0;
	j = 0;
	k = l;

    while (i < n1 && j < n2) {
        int trocar = 0;
        Equipe atual = L[i], prox = R[j];

        if (atual.Pontos > prox.Pontos) trocar = 1;
        else if (atual.Pontos == prox.Pontos) {
            if (atual.Vitorias > prox.Vitorias) trocar = 1;
            else if (atual.Vitorias == prox.Vitorias) {
                if (atual.SaldoGols > prox.SaldoGols) trocar = 1;
                else if (atual.SaldoGols == prox.SaldoGols) {
                    if (atual.GolsFeitos > prox.GolsFeitos) trocar = 1;
                }
            }
        }

        if (trocar) { 
            equipes[k] = L[i]; 
            i++; 
        }
        else { 
            equipes[k] = R[j]; 
            j++; 
        }
		
        k++;
    }
    
    while (i < n1) {
		equipes[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		equipes[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(Equipe equipes[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(equipes, l, m);
        mergeSort(equipes, m + 1, r);
        merge(equipes, l, m, r);
    }
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

    mergeSort(equipes, 0, N - 1);
    
    printf("%s CAMPEAO\n", equipes[0].Nome);
    printf("%s SEGUNDO LUGAR\n", equipes[1].Nome);
    printf("%s TERCEIRO LUGAR\n", equipes[2].Nome);
    return 0;
}