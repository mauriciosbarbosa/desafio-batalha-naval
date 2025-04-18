#include <stdio.h>

int main() {

    //Inicializando e exibindo o tabuleiro vazio
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    printf("\n---BATALHA NAVAL---\nExibindo tabuleiro vazio.\n");
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

    // Inserindo o navio no tabuleiro na horizontal (posição 3B:3D)
    for (int i = 1, j = 0; i < 4 && j < 3; i++, j++) {
        tabuleiro[2][i] = navio[j];
    }

    // Inserindo o navio no tabuleiro na vertical (posição 5H:7H)
    for (int i = 4, j = 0; i < 7 && j < 3; i++, j++) {
        tabuleiro[i][7] = navio[j];
    }

    // Inserindo navios no tabuleiro na diagonal (posições 5A:7C e 5E:3G)
    for (int i = 4, j = 0, k = 0; k < 3; i++, j++, k++) {
        tabuleiro[i][j] = navio[k];
    }
    for (int i = 4, j = 4, k = 0; k < 3; i--, j++, k++) {
        tabuleiro[i][j] = navio[k];
    }

    // Exibindo tabuleiro com os navios
    printf("Exibindo tabuleiro com 4 (quatro) navios inseridos. Posições 3B:3D; 5H:7H; 5A:7C e 5E:3G :\n");
    printf("    A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        i < 9 ? printf("%d | ", i + 1) : printf("%d| ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    // Inicializando matriz de habilidade de ataque em cone
    int cone[3][5];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            cone[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 2) {
                for (int x = i; x > -1; x--) {
                    cone[i][j + x] = 1;
                    cone[i][j - x] = 1;
                }
            }
        }
    }

    // Exibindo a habilidade de cone
    printf("Exibindo a habilidade de ataque em cone (1).\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    // Inicializando matriz de habilidade de ataque em cruz
    int cruz[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 2;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Exibindo a habilidade de cruz
    printf("\nExibindo a habilidade de ataque em cruz (2).\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }

    // Inicializando matriz de habilidade de ataque em octaedro
    int octa[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                octa[i][j] = 3;
            } else if ((i == 1 || i == 3) && (j == 1 || j == 3)) {
                octa[i][j] = 3;
            } else {
                octa[i][j] = 0;
            }
        }
    }

    // Exibindo a habilidade de octaedro
    printf("\nExibindo a habilidade de ataque em octaedro (3).\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", octa[i][j]);
        }
        printf("\n");
    }

    // Inserindo os ataques no tabuleiro
    // Será gerado um tabuleiro só com a imagem dos ataques
    int tabuComAtaq[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuComAtaq[i][j] = 0;
        }
    }

    for (int i = 0, k = 0; i < 3; i++, k++) {
        for (int j = 0, l = 0; j < 5; j++, l++) {
            if (cone[i][j] != 0) {
                tabuComAtaq[k][l] = cone[i][j];
            }
        }
    }

    for (int i = 0, k = 4; i < 5; i++, k++) {
        for (int j = 0, l = 1; j < 5; j++, l++) {
            if (cruz[i][j] != 0) {
                tabuComAtaq[k][l] = cruz[i][j];
            }
        }
    }

    for (int i = 0, k = 2; i < 5; i++, k++) {
        for (int j = 0, l = 4; j < 5; j++, l++) {
            if (octa[i][j] != 0) {
                tabuComAtaq[k][l] = octa[i][j];
            }
        }
    }

    // Exibindo tabuleiro com os ataques

    printf("\nExibindo tabuleiro com os ataques.\n");
    printf("(1) Ataque em cone.|(2) Ataque em cruz. |(3) Ataque em octaedro.\n");
    printf("    A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        i < 9 ? printf("%d | ", i + 1) : printf("%d| ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuComAtaq[i][j]);
        }
        printf("|\n");
    }
    printf("\n");


    // Aplicando ataques no tabuleiro com navios
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tabuComAtaq[i][j] != 0) {
                tabuleiro[i][j] = 5;
            }
        }
    }

    // Exibindo tabuleiro com navios e ataques
    printf("Exibindo tabuleiro com navios e ataques.\n");
    printf("(0) Água. (3) Navio. (5) Ataque.\n");
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