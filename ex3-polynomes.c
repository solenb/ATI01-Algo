#include <stdio.h>
#include <stdlib.h>
int create_poly(int degre){
	int* poly;
	poly = (int*) malloc(degre * sizeof(double*));
	return poly;
}

int fill_poly(int degre, int* poly){
	int i,degre;
	printf("Rentrez les %d paramètres du polynome : \n", degre);
	for (i=degre;i>0; i--){
		printf("X^%d : ", i);
		scanf("%d", &poly[i]);
	}
}	

//int prompt_poly(int degre, int* poly){

int main(){	
	int degre;
	int* poly;
	printf("Degré du polynome : ");
	scanf("%d",&degre);
	poly=create_poly(degre);
	fill_poly(degre, poly);
}
