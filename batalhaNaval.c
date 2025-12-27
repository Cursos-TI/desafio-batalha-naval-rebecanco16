#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {

    /* ============================
       DECLARAÇÃO DO TABULEIRO
       ============================ */

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    /* Inicializa o tabuleiro com água (0) */
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    /* ============================
       DECLARAÇÃO DOS NAVIOS
       ============================ */

    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

    /* ============================
       COORDENADAS INICIAIS
       ============================ */

    /* Navio horizontal */
    int linhaH = 2;
    int colunaH = 3;

    /* Navio vertical */
    int linhaV = 5;
    int colunaV = 6;

    /* ============================
       POSICIONAMENTO DO NAVIO HORIZONTAL
       ============================ */

    if (colunaH + TAM_NAVIO <= TAM_TABULEIRO) {

        int podePosicionar = 1;

        /* Verifica sobreposição */
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA) {
                podePosicionar = 0;
            }
        }

        /* Posiciona o navio */
        if (podePosicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        }
    }

    /* ============================
       POSICIONAMENTO DO NAVIO VERTICAL
       ============================ */

    if (linhaV + TAM_NAVIO <= TAM_TABULEIRO) {

        int podePosicionar = 1;

        /* Verifica sobreposição */
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) {
                podePosicionar = 0;
            }
        }

        /* Posiciona o navio */
        if (podePosicionar) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        }
    }

    /* ============================
       EXIBIÇÃO DO TABULEIRO
       ============================ */

    printf("Tabuleiro Batalha Naval (0 = Água | 3 = Navio)\n\n");

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
