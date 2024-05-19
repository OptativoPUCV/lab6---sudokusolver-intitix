#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int i,j,k;
  for(i=0;i<9;i++) { //RECORREMOS LAS FILAS
    for(j=0;j<9;j++) { // LAS COLUMNAS
      if(n->sudo[i][j]!=0) { //SI NO ES CERO (NULO)
        for(k=0;k<9;k++) { //CICLO DEL 1 AL 9
          if(k!=j) { 
            if(n->sudo[i][k]==n->sudo[i][j]) return 0; //COMPARAMOS
          }
        }
      }
    }
  }
  return 1;
}


List* get_adj_nodes(Node* n) {
    List* list = createList(); // Lista de nodos adyacentes
    int i, j, k; // Indexadores

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (n->sudo[i][j] == 0) { // Si el valor es 0
                for (k = 1; k < 10; k++) { // Recorre los valores de 1 a 9
                    Node* adj = copy(n); // Crea un nuevo nodo
                    adj->sudo[i][j] = k; // Le asigna el valor de k
                    if (is_valid(adj)) { // Si el valor es válido
                        pushBack(list, adj); // Lo agrega a la lista
                    } else {
                        free(adj); // Libera la memoria si no es válido
                    }
                }
            }
        }
    }
    return list; // Retorna la lista una vez se han generado los adyacentes para el primer espacio vacío
}


int is_final(Node* n){
  int i,j;
  for(i=0;i<9;i++) {
    for(j=0;j<9;j++) {
      if(n->sudo[i][j]==0) return 0; //SI ES 0, NO ES FINAL
    }
  }
  return 1;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/