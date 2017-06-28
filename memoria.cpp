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
    int line_one,col_one;//linha um, coluna um
    int line_two,col_two;//linha dois, coluna dois
    time_t start,end;
    int tempo;
    srand(time(NULL));//Função "seedrandomico", pontoa randomizar
    system("clear");
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
//
//--------------------
//
//--------Mostra as cartas viradas para cima--------------
//
    start=time(NULL);
            printf("--------\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("[%i] ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("--------\n");
    usleep(5000000);
//-------------------Esconde elas agora --------------
//----------------------Fazendo ela funcionar-------------
    while(ponto<=p){//enquanto os pontos forem menores que a quantidade de pares
    system("clear");
    printf("--------\n");
    for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("[%i] ",mostra[i][j]);
        }
        printf("\n");
    }
        printf("--------\n");
        fflush(stdin);
        printf("Digite suas cordenadas para o primeiro elemento(Linha,Coluna): ");
        scanf("%i,%i",&line_one,&col_one);
        if(line_one==0 || col_one==0){
            break;
        }
        printf("Digite suas cordenadas para o segundo elemento(Linha,Coluna): ");
        scanf("%i,%i",&line_two,&col_two);
        line_one--;col_one--;line_two--;col_two--;
        system("clear");
        if(line_one>n || line_two>n || col_one>m || col_two>m){
            printf("Suas coordenadas sao invalidas. \n");
        }else
            if(line_one!=line_two || col_one!=col_two){//se as cordenadas nao forem numeros iguais
                if(mostra[line_one][col_one]==matriz[line_one][col_one] || mostra[line_two][col_two]==matriz[line_two][col_two]){//se os valores ja nao foram descobertos
                    printf("Não pode selecionar o mesmo ponto.\n");
                }else{
                    mostra[line_one][col_one]=matriz[line_one][col_one];//
                    mostra[line_two][col_two]=matriz[line_two][col_two];//atribui as cordenadas para o usuario ver os valores das cartas 
                    printf("--------\n");
                    for(i=0;i<n;i++){
                            for(j=0;j<m;j++){
                                printf("[%i] ",mostra[i][j]);
                        }
                        printf("\n");
                    }
                    printf("--------\n");
                    if(matriz[line_one][col_one]==matriz[line_two][col_two]){//se os valores das duas coordenadas forem iguais
                        system("clear");
                        ponto++;
                        printf("Sucesso!!\n");
                    
                    }else{//se os valores das duas coordenadas forem diferentes
                        mostra[line_one][col_one]=0;
                        mostra[line_two][col_two]=0;
                        printf("Suas cordenadas não conferem.\n");
                    }
                }
            }else{
                printf("Jogada invalida!!\n");
            }
        usleep(2000000);
        }
end=time(NULL);
tempo=difftime(end,start);
    printf("Seus pontos totalizam: %i\n",tempo/ponto);
return 0;
}
