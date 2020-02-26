#include <stdio.h>
#include <stdlib.h>
void iter_fact(int n){
	int i;
	int calc=1;
	for (i=1; i<=n; i++){
		calc*=i;
	}
	printf("Le résultat est : %d", calc);
}
void rec_fact(int n){
	if (n == 0){
		return 1;
	}
	else{ 
		n *= rec_fact(n-1);
		printf("Le résultat est : %d", n);
}}
int main(){
	int fact;
	char action;
	printf("Sélectionner la méthode de calcul de la factorielle : \n\t-Itérative (i) \n\t-Récursive (r)\n");
	scanf("%c",&action);
	getchar();

	if (action == 'i'){
		printf("Factorielle à calculer : ");
		scanf("%d",&fact);
		iter_fact(fact);
	}
	if (action == 'r'){
		printf("Factorielle à calculer : ");
		scanf("%d",&fact);
		rec_fact(fact);
	}
}
