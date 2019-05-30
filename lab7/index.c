#include "pilha.h"


void main(){

  Pilha *pilha1;
  pilha1 = cria_pilha();
  push(3, pilha1);
  push(4, pilha1);
  imprime_pilha(pilha1);
  adicao_pilha(pilha1);
  imprime_pilha(pilha1);
  push(2, pilha1);
  multi_pilha(pilha1);
  imprime_pilha(pilha1);
  destroi_pilha(pilha1);
}
