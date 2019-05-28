#include "pilha.h"

Pilha* cria_pilha(){
  Pilha* p;
  p = malloc(sizeof(Pilha));
  p -> Topo = malloc(sizeof(Celula));
  p-> Fundo = malloc(sizeof(Celula));
  p -> Fundo -> Prox = malloc(sizeof(Celula));
  p -> Topo -> Prox = NULL;
  p -> tamanho = 0;

  return p;
}


void push (int n, Pilha* pilha){
  Celula *aux;
  aux =malloc(sizeof(Celula));
  if(pilha == NULL){
    printf("Pilha inválida. Error.\n");
    exit(0);
  }

  pilha->Topo->Item = n;
	aux->Prox = pilha->Topo;
	pilha->Topo = aux;
	pilha->tamanho++;
}

void pop(Pilha* pilha, int *item){
  Celula* q;
  q = malloc(sizeof(Celula));
  if(pilha -> Fundo == pilha -> Topo){
    printf("Erro! Lista vazia\n");
    return;
  }

  q = pilha -> Topo;
  pilha -> Topo = q -> Prox;
  *item = q -> Prox -> Item;
  free(q);
  pilha -> tamanho--;
}

void imprime_pilha(Pilha *pilha){
  Celula* Aux;
	Aux = pilha->Topo->Prox;
	printf ("Imprime Pilha Encadeada: \n");
	while (Aux != NULL)
	{
		printf ("%d\n", Aux->Item);
		Aux = Aux->Prox;
	}
}

Pilha* destroi_pilha(Pilha* pilha){
  Pilha* aux = pilha;
  Pilha * aux2;
  while (aux != NULL){
    aux2 = aux;
    aux = aux -> Prox;
    free(aux2);
  }
  free(aux2);
  free)(pilha);
  return NULL;
}


void adicao_pilha(Pilha *pilha){
  pilha -> prox -> prox -> item = pilha ->  prox -> item + pilha
}
