#include "pilha.h"


Pilha* cria_pilha(){
  Pilha *pilha;
  pilha = malloc(sizeof(Pilha));
  pilha -> topo = 0;
  return pilha;
}

 int Vazia(Pilha *pilha){
   return (pilha -> topo == 0);
 }

 Pessoa *inicializaPessoa(char* nome, int idade, char *endereco){
   Pessoa *pessoa;
   pessoa = malloc (sizeof(Pessoa));
   pessoa -> nome = malloc (strlen(nome)* sizeof(char));
   pessoa -> endereco = malloc (strlen(endereco)* sizeof(char));
   pessoa -> idade = idade;
   strcpy(pessoa -> nome, nome);
   strcpy(pessoa -> endereco, endereco);

   return pessoa;
 }
void push(Pessoa* pessoa, Pilha* pilha){
  if(pilha == NULL){
    printf("Essa pilha não existe!!\n");
    exit(0);
  }
if(pilha -> topo == 10){
  printf("Pilha cheia, não é possível inserir\n");
  }else{
    pilha -> pessoas[pilha -> topo] = pessoa;
    pilha -> topo++;
    }
}


Pessoa* pop(Pilha* pilha){
  if (pilha -> topo == 0){
    printf("Pilha já está vazia\n");
  }else{
    pilha -> topo--;
    return pilha -> pessoas[pilha -> topo];
  }
}

void imprime_pilha (Pilha* pilha){
  int i;
  for(i = pilha -> topo - 1; i >= 0; i--){
    printf( "Nome: %s \n Idade: %i \n Endereco: %s \n", pilha->pessoas[i] -> nome, pilha->pessoas[i] -> idade, pilha->pessoas[i] -> endereco);
  }
}

Pilha* destroi_pilha(Pilha* pilha){
  int i;
  for(i = 0; i < pilha -> topo; i++){
    free(pilha -> pessoas[i] -> nome);
    free(pilha -> pessoas [i] -> endereco);
    free(pilha -> pessoas[i]);
  }
  free(pilha);
  return NULL;
}
