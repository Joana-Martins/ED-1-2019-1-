#include "fila.h"


Fila* cria_fila(void){
  Fila *f = malloc(sizeof(Fila));
  f -> pilha = cria_pilha();
  f -> aux = cria_pilha();
  return f;
}

void insere (Pessoa* pessoa, Fila* f){
  if( pessoa == NULL || f == NULL){
    return;
  }
  push(pessoa, f-> pilha);
}

Pessoa* retira (Fila* f){
  int i;
  Pessoa *aux, *retirada;

  if( f == NULL){
    return NULL;
  }

  while(!vazia_pilha(f -> pilha)){
    aux = pop(f -> pilha);
    push(aux, f -> aux);
  }

  retirada = pop(f -> aux);

while(!vazia_pilha(f -> aux)){
    aux = pop(f -> aux);
    push(aux, f -> pilha);
  }

  return retirada;
}

void imprime_fila (Fila* f){
  int i;
  Pessoa *aux;
  while(!vazia_pilha(f -> pilha)){
    aux = pop(f -> pilha);
    push(aux, f -> aux);
  }

  imprime_pilha(f -> aux);

  while(!vazia_pilha(f -> aux)){
    aux = pop(f -> aux);
    push(aux, f -> pilha);
  }

}

int Vazia_fila (Fila* f){
  if(f == NULL){
    return 2;
  }
  if(vazia_pilha(f -> pilha)){
    return 1;
  }else{
    return 0;
  }
}

void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores){
  Pessoa *aux;
  if(f == NULL){
    return;
  }

  while(!vazia_pilha(f -> pilha)){
    aux = pop(f -> pilha);
    if(retorna_idade(aux) >= 60){
      insere(aux, f_maiores);
    }else{
      insere(aux, f_menores);
    }
  }
}

Fila* destroi_fila (Fila* f){
  destroi_pilha(f -> pilha);
  destroi_pilha(f -> aux);
  free(f);
}
