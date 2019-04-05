#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct matriz {
  int nlinha;
  int ncoluna;
  int** mat;
}Matriz;

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
  int i;
  Matriz *mat = ( Matriz*) malloc (sizeof(Matriz));
  mat -> nlinha = nlinhas;
  mat -> ncoluna = ncolunas;
  mat -> mat = (int**)malloc(nlinhas*sizeof(int*));
  for(i = 0 ; i < nlinhas; i++){
    mat -> mat[i] = (int*) malloc(ncolunas*sizeof(int));
  }
  for(i = 0; i < nlinhas; i++){
    for(int j = 0; j < ncolunas;j++){
      mat -> mat[i][j] = 0;
    }
  }

  return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){

  if((*mat).mat == NULL){
    printf("Matriz nao exite.");
    exit(1);
  }

  if ((*mat).nlinha < linha || (*mat).ncoluna < coluna){
    printf("Linha ou coluna invalida\n");
  } else if (linha < 0 || coluna < 0){
      printf("Linha ou coluna invalida\n");
  }else{
      (*mat).mat[linha][coluna] = elem;
  }


}

int recuperaElemento(Matriz* mat, int linha, int coluna){

  if((*mat).mat == NULL){
    printf("Matriz nao exite.");
    exit(1);
  }
  if ((*mat).nlinha < linha || (*mat).ncoluna < coluna){
    printf("Linha ou coluna invalida\n");
  } else if (linha < 0 || coluna < 0){
      printf("Linha ou coluna invalida\n");
  }else{
    printf("%i\n", (*mat).mat[linha][coluna]);
        }
return (*mat).mat[linha][coluna];
}Matriz* multi;

int recuperaNColunas (Matriz* mat){
    if((*mat).mat == NULL){
      printf("Matriz nao exite.");
      exit(1);
    }
return (*mat).ncoluna;
}
int recuperaNLinhas (Matriz* mat){
  if((*mat).mat == NULL){
    printf("Matriz nao exite.");
    exit(1);
  }
  return (*mat).nlinha;
}

Matriz* transposta (Matriz* mat){

    int i, j;
    Matriz* trans;
    trans = inicializaMatriz((*mat).ncoluna, (*mat).nlinha);
    if((*mat).mat == NULL){
      printf("Matriz nao exite.");
      exit(1);
    }

    for(i = 0; i < (*mat).ncoluna; i++){
      for(j = 0; j < (*mat).nlinha; j++){
        (*trans).mat[i][j] = (*mat).mat[j][i];
      }
    }

return trans;


}
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
  int i, j, k;
  Matriz* multi = inicializaMatriz((*mat1).nlinha, (*mat2).ncoluna);
  if((*mat1).mat == NULL){
    printf("Matriz 1 nao exite.");
    exit(1);
  }else if((*mat2).mat == NULL){
    printf("Matriz 2 nao exite.");
    exit(1);
  }else if ((*mat1).ncoluna != (*mat2).nlinha){
        printf("As matrizes nao sao validas para multiplicacao\n");
  }else{
      for(i = 0; i < (*mat2).nlinha; i++){
        for(j = 0; j < (*mat1).ncoluna; j++){
          for (k=0; k<(*mat1).ncoluna; k++) {
           (*multi).mat[i][j] = (*multi).mat[i][j] + ((*mat1).mat[i][k] * (*mat2).mat[k][j]);
          }
        }
      }
  }
return multi;

}
void imprimeMatriz(Matriz* mat){
  int i, j;
  if((*mat).mat == NULL){
    printf("Matriz nao exite.");
    exit(1);
  }

  for(i = 0; i < (*mat).nlinha; i++){
    for(j = 0; j < (*mat).ncoluna; j++){
      printf("%i ", (*mat).mat[i][j]);
    }
    printf("\n");
  }
}
void destroiMatriz(Matriz* mat){
  for(int i = 0; i < (*mat).ncoluna; i++){
    free((*mat).mat[i]);
  }
  free((*mat).mat);
  free(mat);
}

void giraMatriz(Matriz* mat){
  int N = (*mat).ncoluna;

  for (int x = 0; x < N / 2; x++)
    {
        for (int y = x; y < N-x-1; y++)
        {
            int temp = (*mat).mat[x][y];
            (*mat).mat[x][y] = (*mat).mat[y][N-1-x];
            (*mat).mat[y][N-1-x] = (*mat).mat[N-1-x][N-1-y];
            (*mat).mat[N-1-x][N-1-y] = (*mat).mat[N-1-y][x];
            (*mat).mat[N-1-y][x] = temp;
        }
    }
}
