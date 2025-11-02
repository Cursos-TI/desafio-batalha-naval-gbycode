#include <stdio.h>


int main() {
    //Declaração das variáveis
    int tabuleiro[10][10];
    int navioHorizontal [3];
    int navioVertical[3];
    int navioDiagonal1[3];
    int navioDiagonal2[3];
    int i, j;
    int linhaH, colunaH;
    int linhaV, colunaV;
    int linhaD1, colunaD1;
    int linhaD2, colunaD2;


    //Pontos de origem das habilidades
    int origemConelinha = 0, origemConeColuna = 2;
    int origemCruzLinha = 5, origemCruzColuna = 2;
    int origemOctaedroLinha = 3, origemOctaedroColuna = 7;

    int tamanhoHabiliadade = 5;

    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    //Inicialização das variáveis
    linhaH = 1; //Linha inicial do navio horizontal
    linhaV = 5; //Linha inicial do navio vertical
    colunaH = 2; //coluna inicial do navio horizontal
    colunaV = 7; //coluna inicial do navio vertical
    linhaD1 = 3; //Linha inicial do navio diagonal
    linhaD2 = 6; //Linha inicial do navio diagonal
    colunaD1 = 3; //coluna inicial do navio diagonal
    colunaD2 = 5; //coluna inicial do navio diagonal

    //Inicialização do tabuleiro
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++){
            tabuleiro[i][j] = 0; //Todas as posições começam com água
        }
    }

    //Definição dos navios
    for (i = 0; i < 3; i++){
        navioHorizontal[i] = 3; //Valor 3 representa o navio
        navioVertical[i] = 3;
        navioDiagonal1[i] = 3;
        navioDiagonal2[i] = 3;
    }

    //Posicionamento dos navios

    //Navio horizontal
    for(i = 0; i < 3; i++){
        if (colunaH + i < 10)
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    
    
    //Navio Vertical
    for (i = 0; i < 3; i++) {
        if (linhaV + i < 10)
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    

    //Navio Diagonal Princiapal
    for (i = 0; i < 3; i++){
        if (linhaD1 + i < 10 && colunaD1 + i < 10)
            tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagonal1[i];
        }
    
    
    //Navio Diagonal Secundária
    for (i = 0; i < 3; i++){
        if (linhaD2 + i < 10 && colunaD2 - i >= 0)
            tabuleiro[linhaD2 + i][colunaD2 - i] = navioDiagonal2[i];
        }
    

    //Habilidades
    //Cone
    for (i = 0; i< tamanhoHabiliadade; i++){
        for (j = 0; j < tamanhoHabiliadade; j++)
            if (j >= 2 - i && j <= 2 + i)
                cone[i][j] = 1;
        }
    

    //Cruz
    for (i = 0; i < tamanhoHabiliadade; i++){
        for (j = 0; j < tamanhoHabiliadade; j++)
            if (i == 2 || j == 2)
                cruz[i][j] =1;
        }
    

    //Octaedro
    for (i = 0; i< tamanhoHabiliadade; i++){
        for (j = 0; j < tamanhoHabiliadade; j++)
            if ((i <= 2 && j >= 2 - i && j <= 2 + i) ||
                (i > 2 && j >= i - 2 && j <= 6 - i))
                octaedro[i][j] = 1;
        }
    

    //Sobreposição das habilidades no tabuleiro
    //Cone
    for (i = 0; i< tamanhoHabiliadade; i++){
        for (j = 0; j < tamanhoHabiliadade; j++){
            int linhaTab = origemConelinha + i;
            int colTab = origemConeColuna - 2 + j;
            if (linhaTab >= 0 && linhaTab < 10 && colTab >= 0 && colTab < 10){
                if (cone[i][j] == 1 && tabuleiro[linhaTab][colTab] == 0)
                        tabuleiro[linhaTab][colTab] = 5;

            }
        }
    }
    
    //Cruz
    for (i = 0; i < tamanhoHabiliadade; i++){
        for (j = 0; j < tamanhoHabiliadade; j++){
                int linhaTab = origemCruzLinha - 2 + i;
                int colTab = origemCruzColuna - 2 + j;
                if(linhaTab >= 0 && linhaTab < 10 && colTab >= 0 && colTab < 10){
                        if (cruz[i][j] == 1 && tabuleiro[linhaTab][colTab] == 0)
                            tabuleiro[linhaTab][colTab] = 5;
                }
        }
    }

    //Octaedro
    for (i = 0; i< tamanhoHabiliadade; i++){
        for (j = 0; j < tamanhoHabiliadade; j++){
            int linhaTab = origemOctaedroLinha - 2 + i;
            int colTab = origemOctaedroColuna - 2 + j;
            if (linhaTab >= 0 && linhaTab < 10 && colTab >= 0 && colTab < 10){
                if (octaedro[i][j] == 1 && tabuleiro[linhaTab][colTab] == 0)
                    tabuleiro[linhaTab][colTab] = 5;
            }
        }
    }

    //Exibição do tabuleiro
    printf("TABULEIRO BATALHA NAVAL MESTRE\n\n");

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]); //mostra a posição das matriz
        }
        printf("\n");
    }
    return 0;
}
