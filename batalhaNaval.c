#include <stdio.h>


int main() {
    //Declaração das variáveis
    int tabuleiro[10][10];
    int navioHorizontal [3];
    int navioVertical[3];
    int i, j;
    int linhaH, colunaH;
    int linhaV, colunaV;

    //Inicialização das variáveis
    linhaH = 2; //Linha inicial do navio horizontal
    linhaV = 5; //Linha inicial do navio vertical
    colunaH = 4; //coluna inicial do navio horizontal
    colunaV = 7; //coluna inicial do navio vertical

    //Inicialização do tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0; //Todas as posições começam com água
        }
    }

    //Definição dos navios
    for (i = 0; i < 3; i++){
        navioHorizontal[i] = 3; //Valor 3 representa o navio
        navioVertical[i] = 3;
    }

    //Posicionamento dos navios

    //Navio horizontal
    for(i = 0; i < 3; i++){
        if (colunaH + i < 10){
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }
    
    //Navio Vertical
    for (i = 0; i < 3; i++) {
        if (linhaV + i < 10){
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }

    //Exibição do tabuleiro
    printf("TABULEIRO BATALHA NAVAL NOVATO\n\n");

    for (i =0; i < 10; i++) {
        for (j = 0; j< 10; j++){
            printf("%d ", tabuleiro[i][j]); //mostra a posição das matriz
        }
        printf("\n");
    }
    return 0;
}
