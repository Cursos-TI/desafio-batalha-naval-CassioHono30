#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = 0; // tudo água inicialmente
        }
    }

    // Exemplo: adiciona alguns navios
    tabuleiro[2][3] = 3;
    tabuleiro[4][5] = 3;
    tabuleiro[7][8] = 3;
}

// Função para imprimir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ "); // água
            else if (tabuleiro[i][j] == 3)
                printf("N "); // navio
            else if (tabuleiro[i][j] == 5)
                printf("* "); // área afetada
        }
        printf("\n");
    }
    printf("\n");
}

// Função para criar matriz de habilidade tipo CONE (5x5)
void criarCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= 2 - i && j <= 2 + i)  // forma de cone apontando para baixo
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }
}

// Função para criar matriz de habilidade tipo CRUZ (5x5)
void criarCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

// Função para criar matriz de habilidade tipo OCTAEDRO (losango)
void criarOctaedro(int octa[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro)
                octa[i][j] = 1;
            else
                octa[i][j] = 0;
        }
    }
}

// Função para aplicar a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB],
                       int habilidade[TAM_HAB][TAM_HAB],
                       int origemX, int origemY) {
    int inicioX = origemX - TAM_HAB / 2;
    int inicioY = origemY - TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int x = inicioX + i;
                int y = inicioY + j;

                // Verifica se está dentro dos limites do tabuleiro
                if (x >= 0 && x < TAM_TAB && y >= 0 && y < TAM_TAB) {
                    if (tabuleiro[x][y] != 3) // não sobrescreve navio
                        tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

// Programa principal
int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    inicializarTabuleiro(tabuleiro);

    // Cria as habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Define pontos de origem
    int origemConeX = 2, origemConeY = 2;
    int origemCruzX = 5, origemCruzY = 5;
    int origemOctaX = 7, origemOctaY = 7;

    // Aplica as habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, origemConeX, origemConeY);
    aplicarHabilidade(tabuleiro, cruz, origemCruzX, origemCruzY);
    aplicarHabilidade(tabuleiro, octaedro, origemOctaX, origemOctaY);

    // Exibe o resultado final
    printf("=== TABULEIRO FINAL ===\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
