#include <stdio.h>

#define TAM 10   // tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3  // tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM];  // matriz que representa o tabuleiro
    int i, j;

    // ==============================
    // 1️⃣ INICIALIZAÇÃO DO TABULEIRO
    // ==============================
    // Todas as posições começam com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==============================
    // 2️⃣ POSICIONAMENTO DOS NAVIOS
    // ==============================

    // Navio 1 - Horizontal
    int linha1 = 2;   // linha inicial do navio 1
    int coluna1 = 4;  // coluna inicial do navio 1

    // Navio 2 - Vertical
    int linha2 = 5;   // linha inicial do navio 2
    int coluna2 = 7;  // coluna inicial do navio 2

    // Validação simples: garantir que os navios caibam no tabuleiro
    if (coluna1 + TAM_NAVIO <= TAM && linha2 + TAM_NAVIO <= TAM) {
        // Posiciona navio horizontal (valor 3 representa navio)
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linha1][coluna1 + j] = 3;
        }

        // Posiciona navio vertical
        for (i = 0; i < TAM_NAVIO; i++) {
            // Evita sobreposição: só coloca se a posição estiver livre
            if (tabuleiro[linha2 + i][coluna2] == 0)
                tabuleiro[linha2 + i][coluna2] = 3;
        }
    } else {
        printf("Coordenadas inválidas: os navios não cabem no tabuleiro.\n");
        return 1;
    }

    // ==============================
    // 3️⃣ EXIBIÇÃO DO TABULEIRO
    // ==============================
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);  // exibe cada posição (0 ou 3)
        }
        printf("\n");  // nova linha a cada linha da matriz
    }

    printf("\nLegenda: 0 = água | 3 = navio\n");

    return 0;
}
