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
  if(pilha == NULL){
    printf("Pilha inválida. Error.\n");
    exit(0);
  }
  Celula *aux;
  aux =malloc(sizeof(Celula));

  pilha->Topo->Item = n;
	aux->Prox = pilha->Topo;
	pilha->Topo = aux;
	pilha->tamanho++;
  free(aux);
}

void pop(Pilha* pilha, int item){
  if(pilha -> Fundo == pilha -> Topo){
    printf("Erro! Lista vazia\n");
    return;
  }
  Celula* q;
  q = pilha -> Topo -> Prox;
  pilha -> Topo -> Prox = q -> Prox;
  item = q -> Prox -> Item;
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
  free(Aux);
}

Pilha* destroi_pilha(Pilha* pilha){
  Celula* aux2, *aux;
  aux = pilha -> Fundo -> Prox;
  while (aux != NULL){
    aux2 = aux;
    free(aux2);
    aux = aux2 -> Prox;
  }
  free(pilha);
  return NULL;
}


void adicao_pilha(Pilha *pilha){
  pilha -> Topo -> Prox ->Prox -> Item = pilha -> Topo ->  Prox -> Item + pilha-> Topo ->Prox->Prox->Item;
  pop(pilha, pilha -> Topo -> Prox->Prox->Item);

}

void div_pilha(Pilha *pilha){
  pilha -> Topo -> Prox ->Prox -> Item = pilha -> Topo ->  Prox -> Item / pilha-> Topo ->Prox->Prox->Item;
  pop(pilha, pilha -> Topo -> Prox->Prox->Item);

}

void sub_pilha(Pilha *pilha){
  pilha -> Topo -> Prox ->Prox -> Item = pilha -> Topo ->  Prox -> Item - pilha-> Topo ->Prox->Prox->Item;
  pop(pilha, pilha -> Topo -> Prox->Prox->Item);

}

void multi_pilha(Pilha *pilha){
    pilha -> Topo -> Prox ->Prox -> Item = pilha -> Topo ->  Prox -> Item * pilha-> Topo ->Prox->Prox->Item;
    pop(pilha, pilha -> Topo -> Prox->Prox->Item);

}
