//Trabalho jogo da memória
//Disciplina:Algoritmos e Programação
//Professor: Dr. Alceu Britto
//Author: Muriel José Lima
//Data:21/06/2017
//
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#define n 4
#define m 4
#define p 8
int main(){
    int matriz[n][m],vetor[p];
    int i,j,var,num;
    int mostra[n][m],ponto=0;
    int l_um,c_um;//linha um, coluna um
    int l_dois,c_dois;//linha dois, coluna dois
    time_t start,end;
    int tempo;
    int jogar;
    system("cls");
    srand(time(NULL));//Função "seedrandomico", pontoa randomizar
    printf("==========Menu========\nDigite o numero correspondente:\n1.Instruções\n2.Jogar\n");
    scanf("%i",&jogar);
    switch(jogar){
        case 1: printf("======Instruções=======\n\n");system("cls");printf("=>Você precisa escolher duas cartas que sejam iguais e assim marcar ponto.\n=>Elas são escolhidas com as seguintes coordenadas: [Linha (1-%i),coluna (1-%i)]\n=>Digite 0,0 na primeira coordenada para finalizar e saber sua pontuação\nVamos jogar?\n",n,m);system("pause");
        case 2:
    system("cls");
//------------Zera matriz e o vetor-----------
    for(i=0;i<p;i++){
        vetor[i]=0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            matriz[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            mostra[i][j]=0;
        }
    }
//------------Até aqui zerei a matriz e o vetor---------

   
//
//Aqui está a lógica para deixa-la randomica sem repetir mais de duas vezes seus numeros
//
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            while(matriz[i][j]==0){
                num=rand() % p + 01;//randomiza os numeros de 1-20
                var=vetor[num-1];//deixa os indices randomizados de 0-19 pois o vetor tem somente esses indices e nao teria jeito de utilizar 1-20
                if(var<2){//testamos de a variavel anterior nao repetiu mais de duas vezes
                    matriz[i][j]=num;//se a condição for verdadeira a o indice da matriz recebe o randomico
                    vetor[num-1]++;//o vetor indices 0-19 recebe mais um, pois quando chegar a 2 significa que ele não poderá ser repetido por mais vezes
                }
            }
            
        }
    for(i=0;i<p;i++){
        vetor[i]=0;
    }

//
//--------------------
//
//--------Mostra as cartas viradas para cima--------------
//
            printf("--------\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("[%i] ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("--------\n");
    sleep(5);
//-------------------Esconde elas agora --------------
//----------------------Fazendo ela funcionar-------------
    while(ponto!=p){//enquanto os pontos forem menores que a quantidade de pares
    system("cls");
    fflush(stdin);
    fflush(stdout);
    printf("--------\n");
    for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("[%i] ",mostra[i][j]);
        }
        printf("\n");
    }
        printf("--------\n");
        printf("Digite suas cordenadas para o primeiro elemento(Linha,Coluna): ");
        scanf("%i,%i",&l_um,&c_um);
        if(l_um==0 || c_um==0){//Encerra o programa
            break;
        }
        l_um--;c_um--;
        mostra[l_um][c_um]=matriz[l_um][c_um];//para mostrar qual a carta que o usuario selecionou
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("[%i] ",mostra[i][j]);
            }
            printf("\n");
        }
        printf("Digite suas cordenadas para o segundo elemento(Linha,Coluna): ");
        scanf("%i,%i",&l_dois,&c_dois);
        l_dois--;c_dois--;
        system("cls");
        if(l_um>n || c_um>m || l_dois>n || c_dois>m){
            printf("Suas coordenadas sao invalidas. \n");
        }else
            if(l_um!=l_dois || c_um!=c_dois){//se as cordenadas nao forem numeros iguais
                if(mostra[l_dois][c_dois]==matriz[l_dois][c_dois]){//se os valores ja nao foram descobertos
                    printf("Não pode selecionar o mesmo ponto.\n");
                }else{
                    mostra[l_dois][c_dois]=matriz[l_dois][c_dois];//atribui as cordenadas para o usuario ver os valores das cartas 
                    printf("--------\n");
                    for(i=0;i<n;i++){
                            for(j=0;j<m;j++){
                                printf("[%i] ",mostra[i][j]);
                        }
                        printf("\n");
                    }
                    printf("--------\n");
                    if(matriz[l_um][c_um]==matriz[l_dois][c_dois]){//se os valores das duas coordenadas forem iguais
                        system("cls");
                        ponto++;
                        printf("Sucesso!!\n");
                    
                    }else{//se os valores das duas coordenadas forem diferentes
                        mostra[l_um][c_um]=0;
                        mostra[l_dois][c_dois]=0;
                        printf("Suas cordenadas não conferem.\n");
                    }
                }
            }else{
                printf("Jogada invalida!!\n");
            }
        sleep(2);
        }
    printf("Pontuação: %i\n",tempo/ponto);
    ;}//fecha o case 2 do switch
    system("pause");
return 0;
}