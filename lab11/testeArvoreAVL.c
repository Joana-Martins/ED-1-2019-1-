#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArvoreAVL.h"

int main(int argc, char *argv[ ]){

    ArvAVL* avl;
    int res,i;

    if(argc != 3){
     printf("Parametros incorretos. Use os parametros: "
     "<qtd de elementos a buscar>  \n");
     return -1;
   }
    int qtdBusca = atoi(argv[1]);
    int N;
    //int N = 10, dados[10] = {50,25,10,5,7,3,30,20,8,15};
    //int N = 11, dados[11] = {50,25,10,5,5,7,3,30,20,8,15};
    //int N = 10, dados[10] = {1,2,3,10,4,5,9,7,8,6};

    avl = cria_ArvAVL();
     int total;
     int j=0;
     FILE *l = fopen(argv[2], "r");  //   scanf("%d", &total);
     //int *aux =  malloc(sizeof(int)*(total+1));
     clock_t t;
     t = clock();
    while (1 == fscanf(l,"%d", &N)){
        j++;
        insere_ArvAVL(avl,N);

   }
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC;
   printf("Carregar: %f sec\n", time_taken);
    //printf("\nAVL tree:\n");
  //  emOrdem_ArvAVL(avl);
  //  printf("\n\n");
//
//    int NR = 4, dadosR[4] = {7,51,3,5};
//    for(i=0;i<NR;i++){
//        printf("\nRemovendo: %d\n",dadosR[i]);
//        res = remove_ArvAVL(avl,dadosR[i]);
//        printf("\n\nres = %d\n",res);
//        preOrdem_ArvAVL(avl);
//        //printf("\n\n");
//    }
//
//    printf("\nAVL tree:\n");
//    preOrdem_ArvAVL(avl);
//    printf("\n\n");

    remove_ArvAVL(avl,6);
    //printf("\nAVL tree:\n");
  //  emOrdem_ArvAVL(avl);
  //  printf("\n\n");

    remove_ArvAVL(avl,7);
  //  printf("\nAVL tree:\n");
  //  emOrdem_ArvAVL(avl);
  //  printf("\n\n");

    remove_ArvAVL(avl,4);
//    printf("\nAVL tree:\n");
    //emOrdem_ArvAVL(avl);
  //  printf("\n\n");

    libera_ArvAVL(avl);


    return 0;
}
