#include <stdio.h>

#define TAM_TABULEIRO 8

void imprimir_tabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mover_bispo(int linha, int coluna) {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    for (int i = 1; i < TAM_TABULEIRO; i++) {
        if (linha+i < TAM_TABULEIRO && coluna+i < TAM_TABULEIRO)
            tabuleiro[linha+i][coluna+i] = 1;
        if (linha-i >= 0 && coluna-i >= 0)
            tabuleiro[linha-i][coluna-i] = 1;
        if (linha+i < TAM_TABULEIRO && coluna-i >= 0)
            tabuleiro[linha+i][coluna-i] = 1;
        if (linha-i >= 0 && coluna+i < TAM_TABULEIRO)
            tabuleiro[linha-i][coluna+i] = 1;
    }

    tabuleiro[linha][coluna] = 9;
    printf("Movimentos do Bispo:\n");
    imprimir_tabuleiro(tabuleiro);
}

void mover_torre(int linha, int coluna) {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (i != linha)
            tabuleiro[i][coluna] = 1;
        if (i != coluna)
            tabuleiro[linha][i] = 1;
    }

    tabuleiro[linha][coluna] = 9;
    printf("Movimentos da Torre:\n");
    imprimir_tabuleiro(tabuleiro);
}

void mover_rainha(int linha, int coluna) {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (i != linha)
            tabuleiro[i][coluna] = 1;
        if (i != coluna)
            tabuleiro[linha][i] = 1;
    }

    for (int i = 1; i < TAM_TABULEIRO; i++) {
        if (linha+i < TAM_TABULEIRO && coluna+i < TAM_TABULEIRO)
            tabuleiro[linha+i][coluna+i] = 1;
        if (linha-i >= 0 && coluna-i >= 0)
            tabuleiro[linha-i][coluna-i] = 1;
        if (linha+i < TAM_TABULEIRO && coluna-i >= 0)
            tabuleiro[linha+i][coluna-i] = 1;
        if (linha-i >= 0 && coluna+i < TAM_TABULEIRO)
            tabuleiro[linha-i][coluna+i] = 1;
    }

    tabuleiro[linha][coluna] = 9;
    printf("Movimentos da Rainha:\n");
    imprimir_tabuleiro(tabuleiro);
}

void mover_cavalo(int linha, int coluna) {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    int movimentos[8][2] = {
        {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
        {1, -2},  {1, 2},  {2, -1},  {2, 1}
    };

    for (int i = 0; i < 8; i++) {
        int nova_linha = linha + movimentos[i][0];
        int nova_coluna = coluna + movimentos[i][1];

        if (nova_linha >= 0 && nova_linha < TAM_TABULEIRO &&
            nova_coluna >= 0 && nova_coluna < TAM_TABULEIRO) {
            tabuleiro[nova_linha][nova_coluna] = 1;
        }
    }

    tabuleiro[linha][coluna] = 9;
    printf("Movimentos do Cavalo:\n");
    imprimir_tabuleiro(tabuleiro);
}

int main() {
    int linha = 3, coluna = 3;

    mover_bispo(linha, coluna);
    mover_torre(linha, coluna);
    mover_rainha(linha, coluna);
    mover_cavalo(linha, coluna);

    return 0;
}
