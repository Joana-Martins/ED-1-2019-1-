#include "listahet.h"

#define IMOV 0
#define MOV 1
#define CLIE 2
#define VAZIO 22

typedef struct cliente{
  char *nome;
  int id;
}Cliente;

typedef struct movel{
int placa, ano;
float valor;
}Movel;

typedef struct imovel{
  int identificador, ano;
  float valor;
}Imovel;

typedef struct listahet{
  Cliente* dono;
  void* item;
  struct listahet* prox;
  int id;
}ListaHet;

/*Cria lista vazia
* inputs: nenhum
* output: lista vazia
* pre-condicao: nenhuma
* pos-condicao: lista criada e vazia
*/
ListaHet* cria (){
  ListaHet *Lista;
  Lista = (ListaHet*)malloc(sizeof(ListaHet));

  if(Lista == NULL){
    printf("Error ao criar. Tente novamente.\n");
    return NULL;
  }

  Lista-> prox = NULL;
  Lista -> id = VAZIO;
  Lista -> dono = NULL;
  Lista -> item = NULL;

  return Lista;
}

/*Cria uma estrutura do tipo Cliente
* inputs: nome do cliente e o identificador do cliente
* output: Endere�o da estrutura cliente criada
* pre-condicao: nome e id validos
* pos-condicao: estrutura cliente criada, com os campos nome e id corretamente atribuidos
*/
Cliente* cria_cliente (char* nome, int id){
  Cliente *cliente;
  cliente = (Cliente*)malloc(sizeof(Cliente));
  cliente -> nome = (char*)malloc(sizeof(char)*(strlen(nome)+1));
  strcpy(cliente->nome, nome);
  cliente -> id = id;

  return cliente;
}


/*Cria uma estrutura do tipo Movel
* inputs: placa, ano de fabricacao e valor do automovel
* output: Endere�o da estrutura movel criada
* pre-condicao: placa, ano e valor validos
* pos-condicao: estrutura movel criada
*/
Movel* cria_movel (int placa, int ano, float valor){
  Movel* movel = (Movel*) malloc (sizeof(Movel));
  movel -> placa = placa;
  movel -> ano = ano;
  movel ->valor = valor;

  return movel;
}

/*Cria uma estrutura do tipo Imovel
* inputs: identificador, ano de construcao e o valor do imovel
* output: Endere�o da estrutura imovel criada
* pre-condicao: id, ano e valor validos
* pos-condicao: estrutura imovel criada
*/
Imovel* cria_imovel (int id, int ano, float valor){
  Imovel* imovel = (Imovel*)malloc(sizeof(Imovel));
  imovel -> identificador = id;
  imovel -> ano = ano;
  imovel -> valor = valor;
}

/*Insere um item (do tipo Movel) na primeira posicao da lista
* inputs: a lista, o cliente dono do automovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e automovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_movel (ListaHet* lista, Cliente* dono, Movel* item){
  ListaHet* insere;
  if(lista == NULL){
    return NULL;
  }

      insere = cria();
      insere -> dono = cria_cliente(dono->nome, dono->id);
      insere -> item = cria_movel(item -> placa, item -> ano, item -> valor);
      insere -> id = MOV;
      if(lista->id = VAZIO){
        lista = insere;
        return lista;
      }

      insere-> prox = lista;
      return insere;
}


/*Insere um item (do tipo Imovel) na primeira posicao da lista
* inputs: a lista, o cliente dono do imovel e o item a ser inserido
* output: a lista atualizada
* pre-condicao: lista, cliente e imovel validos
* pos-condicao: lista atualizada com o item inserido na primeira posicao
*/
ListaHet* insere_imovel (ListaHet* lista, Cliente* dono, Imovel* item){
  ListaHet* insere;
  insere = cria();
  insere -> dono = cria_cliente(dono -> nome, dono -> id);
  insere -> item = cria_movel(item -> identificador, item -> ano, item -> valor);
  insere -> id = IMOV;

  if(lista -> id == VAZIO){
    lista = insere;
    return lista;
  }

  insere -> prox = lista;
  return insere;
}

/*Imprime os elementos da lista. Para cada elemento da lista, deve-se imprimir os dados do Cliente, seguido dos dados do im�vel (caso o item seja um im�vel) ou dos dados do autom�vel (caso o item seja um movel)
* inputs: a lista
* output: nao tem
* pre-condicao: lista valida
* pos-condicao: lista inalterada
*/
void imprimeItem(ListaHet* item){
  if(item != NULL){
    switch (item->id) {
      case MOV:
       printf("\tPlaca: %d, Ano: %d, Valor: %.2f\n_________________\n", ((Movel*)item->item)->placa, ((Movel*)item->item)->ano, ((Movel*)item->item)->valor);
      break;
      case IMOV:
      printf("Identificador: %d, Ano: %d, Valor: %.2f\n_________________\n", ((Imovel*)item->item)->identificador, ((Imovel*)item->item)->ano, ((Imovel*)item->item)->valor);
      break;
      default:
      printf("Tipo de item invalido\n");
    }
  }
}

void imprimeCliente(Cliente *cliente){
    if(cliente == NULL)
        return;
    printf("Cliente: %s\n ID: %d\n", cliente -> nome, cliente ->id);
}

void imprime (ListaHet *lista){
    if(lista != NULL)
        if(lista->id == VAZIO)
            return;

    ListaHet *s = lista;

    while(s != NULL){
        imprimeCliente(s->dono);
        imprimeItem(s);
        s = s-> prox;
    }
}

/*Retira da lista todos os itens assegurados de um dado cliente
* inputs: a lista e o identificador do cliente
* output: lista atualizada
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista nao contem itens do cliente cujo identificador eh id_cliente
*/
ListaHet* retira_cliente (ListaHet* lista, int id_cliente){
  if(lista == NULL){
    return NULL;
  }

  if(lista->id == VAZIO){
    return lista;
  }

  ListaHet *s, *anterior;
  s = lista;
  anterior = NULL;

  while(s != NULL &&  s->dono->id != id_cliente){
    anterior = s;
    s = s -> prox;
  }

  if(s == NULL){
    return lista;
  }
  if(anterior ==  NULL){
    lista = s -> prox;
  }else{
    anterior -> prox = s -> prox;
  }

  s = lista;

  while(s != NULL && s -> dono -> id != id_cliente){
    s = s -> prox;
    if(s != NULL){
      lista = retira_cliente(lista, id_cliente);
    }
  }

  return lista;
}

/*Calcula o valor total assegurado de um dado cliente (incluindo moveis e imoveis). Note que o valor assegurado depende da taxa estipulada para o tipo do item. O calculo do valor assegurado para UM dado item deve ser: valor_item*taxa_item
* inputs: a lista, o endereco do cliente, e as taxas para o calculo do valor assegurado.
* output: valor total assegurado, que deve ser a soma dos valores assegurados de todos os itens do dado cliente
* pre-condicao: lista e identificador do cliente validos
* pos-condicao: lista inalterada
*/
float calcula_valor_assegurado (ListaHet* lista, Cliente* dono, float taxa_movel, float taxa_imovel){
  float acumulador = 0;
      ListaHet *selecionada = lista;

  while(selecionada != NULL){
  if(selecionada->dono->id == dono->id)
          switch(selecionada->id){
          case MOV:
              acumulador += ((Movel*)selecionada->item)->valor * taxa_movel;
          break;
          case IMOV:
              acumulador += ((Imovel*)selecionada->item)->valor * taxa_imovel;
          break;
          default:
              printf("#HOL UP!#\n");
      }

      selecionada = selecionada->prox;
  }
return acumulador;
}
