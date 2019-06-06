
#include "ArvoreBinaria.h"
int main(){
    int t_f, n_f, nos;
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    //Alterar o valor de p para testar valores que existem e não
    int p = 36;
    if (consulta_ArvBin(raiz, p))
	   printf("Achou o elemento %d\n",p);
    else
	   printf("Elemento %d nao encontrado\n", p);

s
    emOrdem_ArvBin(raiz);
    printf("\n");
    preOrdem_ArvBin(raiz);
    printf("\n");
    posOrdem_ArvBin(raiz);
    printf("\n");
    t_f = totalFolha_Arvbin(raiz);
    printf("%i\n", t_f);
    n_f = totalNaoFolha_Arvbin(raiz);
    printf("%i\n", n_f);
    nos = totalNO_ArvBin(raiz);
    printf("%i\n",nos);
    libera_ArvBin(raiz);

    return 0;
}
/*
                                         50
                                  30           100
                              20     40
                                  35   45
                                    37

  pre ordem: 50 30 20 40 35 37 25 100
  centr: 20 30 35 37 40 45 50 100
  pos ordem: 20 37 35 45 40 30 100 50
  */
