#include <stdio.h>

int main() {

    //Inicializando e exibindo o tabuleiro vazio
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    printf("Exibindo tabuleiro vazio...\n");
    printf("    A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        i < 9 ? printf("%d | ", i + 1) : printf("%d| ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    // Inicializando navio de tamanho três
    int navio[3] = {3, 3, 3};

    // Inserindo o navio no tabuleiro na horizontal (posição aleatória)
    for (int i = 1, j = 0; i < 4 && j < 3; i++, j++) {
        tabuleiro[2][i] = navio[j];
    }

    // Inserindo o navio no tabuleiro na vertical (posição aleatória)
    for (int i = 4, j = 0; i < 7 && j < 3; i++, j++) {
        tabuleiro[i][7] = navio[j];
    }

    // Exibindo tabuleiro com os navios
    printf("Exibindo tabuleiro com dois navios. Posições B3:D3 e H5:H7:\n");
    printf("    A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        i < 9 ? printf("%d | ", i + 1) : printf("%d| ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    return 0;
}