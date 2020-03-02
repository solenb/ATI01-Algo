#include <stdio.h>
#include <stdlib.h>
int create_poly(int degre){
	int* poly;
	poly = (int*) malloc(degre * sizeof(double*));
	return poly;
}

int fill_poly(int degre, int* poly){
	printf("Degré du polynome : ");
	scanf("%d",&degre);
	printf("Rentrez les %d paramètres du polynome : \n", degre);
	for (i=0; i < degre; i++){
		scanf("%d", &poly[i]);
	}
}	


//int prompt_poly(int degre, int* poly){

