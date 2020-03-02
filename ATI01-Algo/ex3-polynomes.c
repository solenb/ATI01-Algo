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
	


//int prompt_poly(int degre, int* poly){

