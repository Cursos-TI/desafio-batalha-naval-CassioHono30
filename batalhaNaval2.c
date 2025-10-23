#include <stdio.h>

#define TAM 10        // tamanho fixo do tabuleiro 10x10
#define TAM_NAVIO 3   // tamanho fixo de cada navio
#define NAVIO 3       // valor que representa um navio no tabuleiro
#define AGUA 0        // valor que representa água

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // ==============================================
    // 1️⃣ INICIALIZAÇÃO DO TABULEIRO (TODAS AS POSIÇÕES COM 0)
    // ==============================================
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ==============================================
    // 2️⃣ POSICIONAMENTO DOS NAVIOS
    // ==============================================
    // ➤ Navio 1: Horizontal (linha 2, começando na coluna 3)
    int linha1 = 2, coluna1 = 3;
    if (coluna1 + TAM_NAVIO <= TAM) {
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linha1][coluna1 + j] = NAVIO;
        }
    }

    // ➤ Navio 2: Vertical (coluna 6, começando na linha 5)
    int linha2 = 5, coluna2 = 6;
    if (linha2 + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            // Garante que não sobrepõe outro navio
            if (tabuleiro[linha2 + i][coluna2] == AGUA)
                tabuleiro[linha2 + i][coluna2] = NAVIO;
        }
    }

    // ➤ Navio 3: Diagonal principal (↘) começando em (0,0)
    int linha3 = 0, coluna3 = 0;
    if (linha3 + TAM_NAVIO <= TAM && coluna3 + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha3 + i][coluna3 + i] == AGUA)
                tabuleiro[linha3 + i][coluna3 + i] = NAVIO;
        }
    }

    // ➤ Navio 4: Diagonal secundária (↙) começando em (0,9)
    int linha4 = 0, coluna4 = 9;
    if (linha4 + TAM_NAVIO <= TAM && coluna4 - TAM_NAVIO >= -1) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha4 + i][coluna4 - i] == AGUA)
                tabuleiro[linha4 + i][coluna4 - i] = NAVIO;
        }
    }

    // ==============================================
    // 3️⃣ EXIBIÇÃO DO TABULEIRO COMPLETO
    // ==============================================
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = água | 3 = navio\n");

    return 0;
}
