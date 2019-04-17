#include "listaencadeada.h"

void FLVazia(TipoLista *Lista){
  Lista ->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
  Lista->Ultimo = Lista->Primeiro;
  Lista -> Primeiro -> Prox = NULL;

}
int Vazia(TipoLista Lista){
  return 0;
}
void Insere(Produto x, TipoLista *Lista){

}
TipoApontador BuscaCodigo(int codigo, TipoLista *Lista){
  }
void Retira(int codigo, TipoLista *Lista, Produto *Item){

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
