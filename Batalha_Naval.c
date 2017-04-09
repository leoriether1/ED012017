/*Universidade de Brasília
Instituto de Ciências Exatas
Departamento de Ciência da Computação

Aluno: Leonardo Riether
Disciplina: Estrutura de Dados
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int matriz[6][9];
char tabuleiro[6][9];
int pontos_player1 = 0, pontos_player2 = 0, contp1 = 0, contp2 = 0;
int linha, coluna;

/*Essa função imprime um tabuleiro inicial, como se fosse uma ''interface'' para ilustrar o jogo ''Batalha Naval*/
void imprimetabuleiro(){
		int i,j;

		printf(" \n\n ==========  =    BATALHA NAVAL 3.0   =  ==========");
        printf("\n\n          SEJA BEM VINDO, MARINHEIRO...     \n\n\n\n");

	for(i=0;i<6;i++){
		for(j=0;j<9;j++){
			tabuleiro[i][j] ='~';
		}
	}

	for(i=0;i<6;i++){
        for(j=0;j<9;j++){
            printf("    %c", tabuleiro[i][j]);
        }
        printf("\n\n");
	}
	InstrucoesJogo();

}

void InstrucoesJogo(){
    printf("\n\n ============= INSTRUCOES ==============\n\n\n");
    printf("      SEJAM BEM-VINDOS, MARINHEIROS... HAHAHA\n\n");
    printf(" -- O JOGO PRECISA DE DUAS PESSOAS JOGANDO PARA SER INICIADO\n\n");
    printf(" -- CADA PLAYER TEM 10 TIROS PARA TENTAR ACERTAR EMBARCACOES INIMIGAS\n\n");
    printf(" -- A CADA JOGADA, O JOGO IRA INFORMAR SUA PONTUACAO ATUAL\n    E QUAIS AS COORDENADAS DE SEU ULTIMO TIRO\n\n");
    printf(" -- BOA SORTE, MARINHEIROS...");
    printf("\n\n");
    system("pause");
}
//Essa função é responsável por inserir as embarcações no jogo de forma randômica
// 5 = Encouraçado
// 0 = Submarino
// 3 ou 2 = Água
void RandomizandoTabuleiro(){
    int i, j;

    //Inicia uma matriz randômica com números de 1 a 3.
    srand(time(NULL));
    for(i=0;i<6;i++){
        for(j=0;j<9;j++){
        matriz[i][j] = 1+(rand()%3);
        }
    }
    printf("\n\n");

    //Nessa validação são inseridas as embarcações do tipo ''encouraçado'' que dentro da matriz recebe o valor '5'.
    for(i=0;i<6;i++){
        for(j=0;j<9;j++){
            if(matriz[i][j] == 1){
                    if( j == 8 ){
                      matriz[i][j] = 3;
                    }
                    else if(j == 0){
                        matriz[i][j] = 3;
                    }
                    else{
                        matriz[i][j] = 5;
                        matriz[i][j+1] = 5;
                        matriz[i][j-1] = 5;
                    }
            }
        }
    }
    //Essa validação serve para não vir muitos encouraçados em uma mesma linha. Logo, se vier muitos, todos os elementos da matriz recebe 3 que vale água
    for(i=0;i<6;i++){
        for(j=0;j<9;j++){
            if(matriz[i][j] == 5 && matriz[i][j+1] != 5){
                matriz[i][j] = 3;

            }
        }
    }

       for(i=0;i<6;i++){
        for(j=0;j<9;j++){
            if(matriz[i][j] == 5 && matriz[i][j+1] != 5){
                matriz[i][j] = 3;

            }
        }
    }
    //Essa validação é para determinar os submarinos no jogo
    for(i=0;i<6;i++){
        for(j=0;j<9;j++){
            if(matriz[i][j] == 5 && matriz[i][j+1] != 5 && matriz[i][j-1] != 5){
                matriz[i][j] = 0;

            }
        }
    }
    //Essa validação é para impedir que os encouraçados não ultrapasse a margem da matriz
    for(i=0;i<6;i++){
        for(j=0;j<9;j++){
            if(matriz[i][j] == 2 && matriz[i][j+1] != 5){
                matriz[i][j+1]= 3;
                if( j == 8){
                    matriz[i][j] = 3;
                }
                else if(j == 0){
                    matriz[i][j] = 3;
                }
            }

        }
    }
}
//As funçoes para chamar o player1 e player 2 para o jogo
void Player1(){
    int i, j;

    while(contp1 < 2){
        printf("\n\n EH A SUA VEZ PLAYER 1!!!!\n\n");
        printf("\n\nInforme as coordenadas de tiro para linha de 0-5:\n");
        scanf("%d", &linha);
        printf("Informe as coordenadas de tiro para coluna de 0-8:\n");
        scanf("%d", &coluna);

        if(matriz[linha][coluna] == 1){
            printf("\n\n OPS!!! ESSA COORDENADA JÁ RECEBEU UM TIRO\n");
            Player1();
        }

        if( linha > 5 || coluna > 8){
            printf("\n      AS COORDENADAS PRECISAM ESTAR ENTRE 0-5 PARA LINHA E 0-8 PARA COLUNA !!!!\n\n");
            Player1();
        }

        if(matriz[linha][coluna] == 3 || matriz[linha][coluna] == 2){
            printf("              VOCE ACERTOU A AGUA!! \n");
            matriz[linha][coluna] = 1;
            printf("\n            Coordenadas de sua jogada: Linha = %d e Coluna = %d\n", linha, coluna);
            printf("\n            Voce tem %d pontos ate o momento.", pontos_player1);
        }
        else if(matriz[linha][coluna] == 5){
            printf("\n            PARABENS!!! Voce acertou uma das partes de um encouracado!\n");
            matriz[linha][coluna] = 1;
            pontos_player1++;
            printf("\n            Coordenadas de sua jogada: Linha = %d e Coluna = %d\n", linha, coluna);
            printf("\n            Voce tem %d pontos ate o momento\n", pontos_player1);
        }
        else{
            printf("\n            PARABENS!!! Voce acertou um submarino!\n");
            matriz[linha][coluna] = 1;
            pontos_player1++;
            printf("\n            Coordenadas de sua jogada: Linha = %d e Coluna = %d\n", linha, coluna);
            printf("\n            Voce tem %d pontos ate o momento\n\n\n", pontos_player1);
        }
        contp1++;
        Player2();
    }
}

void Player2(){
int i, j;

     while(contp2 < 10){
        printf("\n\n EH A SUA VEZ PLAYER 2!!! \n\n");
        printf("\n\nInforme as coordenadas de tiro para linha de 0-5:\n");
        scanf("%d", &linha);
        printf("Informe as coordenadas de tiro para coluna de 0-8:\n");
        scanf("%d", &coluna);
        //A CADA JOGADA, A MATRIZ PRINCIPAL RECEBE 1, PARA IMPEDIR QUE O USUÁRIO ATIRE NA MESMA COORDENADA DUAS VEZES
        if(matriz[linha][coluna] == 1){
            printf("\n\n OPS!!! ESSA COORDENADA JÁ RECEBEU UM TIRO\n");
            Player2();
        }

        if(linha > 5 || coluna > 8){
            printf("\n As coordenadas devem estar entre 0-6 para linha e 0-9 para coluna!!\n\n");
            Player2();
        }

        if(matriz[linha][coluna] == 3 || matriz[linha][coluna] == 2){
            printf("              VOCE ACERTOU A AGUA!! \n");
            matriz[linha][coluna] = 1;
            printf("\n            Coordenadas de sua jogada: Linha = %d e Coluna = %d\n", linha, coluna);
            printf("\n            Voce tem %d pontos ate o momento.", pontos_player2);
        }
        else if(matriz[linha][coluna] == 5){
            printf("\n            PARABENS!!! Voce acertou uma das partes de um encouracado!\n");
            matriz[linha][coluna] = 1;
            pontos_player2++;
            printf("\n            Coordenadas de sua jogada: Linha = %d e Coluna = %d\n", linha, coluna);
            printf("\n            Voce tem %d pontos ate o momento\n", pontos_player2);
        }
        else if(matriz[linha][coluna] == 0){
            printf("\n            PARABENS!!! Voce acertou um submarino!\n");
            matriz[linha][coluna] = 1;
            pontos_player2 ++;
            printf("\n            Coordenadas de sua jogada: Linha = %d e Coluna = %d\n", linha, coluna);
            printf("\n            Voce tem %d pontos ate o momento\n\n\n", pontos_player2);
        }
        contp2++;
        Player1();

    }
}
void ContagemDePontos(){
    printf("\n\n O Player 1 TERMINOU COM %d PONTOS...\n\n", pontos_player1);
    printf("\n\n O Player 2 TERMINOU COM %d PONTOS...\n\n", pontos_player2);
}

void Vencedor(){
    if(pontos_player1 > pontos_player2){
        printf("\n\nParabens Player1, VOCE VENCEU A BATALHA!!!\n\n");
    }
    else if(pontos_player1 == pontos_player2){
        printf("\n\nOHHH! A BATALHA ACABOU EMPATADA!!\n\n");
    }
    else{
        printf("\n\nParabens Player2, VOCE VENCEU A BATALHA!!!\n\n");
    }
}

int main(){
    int i,j;
    imprimetabuleiro();
    RandomizandoTabuleiro();
    Player1();
    system("cls");
    ContagemDePontos();
    Vencedor();
}
