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

int is_valid(Node* n) {
    int row[9][10] = {0}; // Array to mark numbers in each row
    int col[9][10] = {0}; // Array to mark numbers in each column
    int submatrix[9][10] = {0}; // Array to mark numbers in each submatrix
    // Check rows and columns for duplicates
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int num = n->sudo[i][j];
            // Check row
            if (row[i][num]) return 0; // Duplicate number in the row
            row[i][num] = 1;
            // Check column
            if (col[j][num]) return 0; // Duplicate number in the column
            col[j][num] = 1;
        }
    }
    // Check submatrices for duplicates
    for (int k = 0; k < 9; k++) {
        for (int p = 0; p < 9; p++) {
            int i = 3 * (k / 3) + (p / 3);
            int j = 3 * (k % 3) + (p % 3);
            int num = n->sudo[i][j];
            // Check submatrix
            if (submatrix[k][num]) return 0; // Duplicate number in the submatrix
            submatrix[k][num] = 1;
        }
    }
    return 1; // State/node is valid
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
				return list; // Retorna la lista una vez se han generado los adyacentes para el primer espacio vacío
			}
		}
	}
	return list; // Retorna la lista (puede estar vacía si no se encontró espacio vacío)
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