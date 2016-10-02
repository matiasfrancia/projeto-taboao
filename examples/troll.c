#include <stdio.h>
#include <stdlib.h>
#include "candidatos.h"

typedef struct atributos{

	int saude;
	int saneamento;
	int educacao;
	int seguranca;
	int cultura;

}at;

int main(){

	int *a;
	a = malloc(5 * sizeof(int));

	int i;
	for(i = 0; i < 5; i++){
		a[i] = 1 + (rand() % 50);
	}
	for(i = 0; i < 5; i++){
		
	}


	return 0;
}