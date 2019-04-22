#include "listaencadeada.h"

void FLVazia(TipoLista *Lista){
  Lista -> primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista->ultimo = Lista->primeiro;
  Lista -> primeiro -> Prox = NULL;
}
int Vazia(TipoLista Lista){
  return (Lista.primeiro == Lista.ultimo);
}
void Insere(Produto x, TipoLista *Lista){
  Lista->ultimo->Prox = (TipoApontador*)malloc(sizeof(TipoCelula));
  Lista->ultimo = Lista->ultimo->Prox;
  Lista->ultimo->Item = x;
  Lista->ultimo -> Prox = NULL;
}
TipoApontador BuscaCodigo(int codigo, TipoLista *Lista){
  TipoApontador aux;
  aux = Lista -> primeiro -> Prox;
    while(aux != NULL){
      if(aux -> Item.codigo == codigo){
        return aux;
        aux = aux -> Prox;
      }
    }
    return NULL;
  }
void Retira(int codigo, TipoLista *Lista, Produto *Item){
  TipoApontador aux, p;
  aux = BuscaCodigo(codigo, Lista);

    if(Vazia(*Lista) || aux == NULL || aux->Prox == NULL){
      printf("ERROR: LISTA VAZIA OU POSICAO NAO EXISTE\n");
      return 1;
    }

    q = Lista -> primeiro;
      while( q != p){
        q = q -> Prox;
      }

}
void ImprimeLista(TipoLista Lista){

}
int Quantidade(TipoLista Lista){
  return 0;
}
Produto criaProduto(int cod, char *nome, int qtd, float preco){
}
void ImprimeProduto(Produto p){

}

Produto maisBarato(TipoLista *Lista){

}
