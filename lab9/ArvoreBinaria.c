#include "ArvoreBinaria.h"

ArvBin* cria_ArvBin(){
  ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
  if(raiz != NULL){
    *raiz = NULL;
  }
  return raiz;
}

int insere_ArvBin(ArvBin* raiz, int valor){
  if(*raiz == NULL){
    *raiz = malloc(sizeof(ArvBin));
    (*raiz) -> info = valor;
  }
  if(valor < (*raiz) -> info){
    return insere_ArvBin(&((*raiz)-> esq), valor);
  }
  if(valor > (*raiz) -> info){
    return insere_ArvBin(&((*raiz)-> dir), valor);
  }

  return 0;
}

int consulta_ArvBin(ArvBin *raiz, int valor){
  if(estaVazia_ArvBin(raiz)==0){
    return 0;
  }
    if(valor < (*raiz)->info){
      return consulta_ArvBin(&(*raiz)->esq,valor);
    }
    if(valor > (*raiz) -> info){
      return consulta_ArvBin(&(*raiz)->dir,valor);
    }
return 1;
}

int estaVazia_ArvBin(ArvBin *raiz){
  if(*raiz == NULL){
    return 0;
  }
}

int totalNaoFolha_Arvbin(ArvBin *raiz){

}

int totalFolha_Arvbin(ArvBin *raiz){

}

int totalNO_ArvBin(ArvBin *raiz){

}

void preOrdem_ArvBin(ArvBin *raiz){
  if(raiz == NULL){
    return;
  }
  if(*raiz != NULL){
    printf("%i ", (*raiz) -> info);
    emOrdem_ArvBin(&((*raiz)->esq));
    emOrdem_ArvBin(&((*raiz)->dir));
  }
}

void emOrdem_ArvBin(ArvBin *raiz){
  if(raiz == NULL){
    return;
  }
  if(*raiz != NULL){
    emOrdem_ArvBin(&((*raiz)->esq));
    printf("%i ", (*raiz) -> info);
    emOrdem_ArvBin(&((*raiz)->dir));
  }
}

void posOrdem_ArvBin(ArvBin *raiz){
  if(raiz == NULL){
    return;
  }
  if(*raiz != NULL){
    emOrdem_ArvBin(&((*raiz)->esq));
    emOrdem_ArvBin(&((*raiz)->dir));
    printf("%i ", (*raiz) -> info);
  }
}

void libera_NO(struct NO* no){
  if(no == NULL){
    return;
  }
  libera_NO(no ->esq);
  libera_NO(no->dir);
  free(no);
  no = NULL;
}

void libera_ArvBin(ArvBin *raiz){
  if(raiz == NULL){
    return;
  }
  libera_NO(*raiz);
  free(raiz);
}
