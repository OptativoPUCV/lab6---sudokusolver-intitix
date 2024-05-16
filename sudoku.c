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

    return 1;
}


List* get_adj_nodes(Node* n){
  List* list=createList(); //LISTA DE ADJUNTOS
  int i,j,k; //INDEXADORES
  for(i=0;i<9;i++) { 
    for(j=0;j<9;j++) {
      if(n->sudo[i][j]==0) { //SI EL VALOR ES 0
        for(k=1;k<10;k++) { //RECORRE LOS VALORES DE 1 A 9
          Node* adj=copy(n); //CREA UN NUEVO NODO
          adj->sudo[i][j]=k; //LE ASIGNA EL VALOR DE K
          if(is_valid(adj)) { //SI EL VALOR ES VALIDO
            pushBack(list,adj); //LO AGREGA A LA LISTA
        }
          
      }
        
    }
  }

  }
  return list;
}


int is_final(Node* n){
    return 0;
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