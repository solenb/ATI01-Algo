#include <stdio.h>
#include <stdlib.h>
int iter_fact(int fact){
	int i;
	int calc=1;
	for (i=1; i<=fact; i++){
		calc*=i;
	}
	return calc;
}
int rec_fact(int fact){
	if (fact == 0){
		return 1;
	}
	fact *= rec_fact(fact-1);
	return fact;
	}
int main(){
	int number;
	char action;
	printf("Sélectionner la méthode de calcul de la factorielle : \n\t-Itérative (i) \n\t-Récursive (r)\n");
	scanf("%c",&action);
	getchar();

	if (action == 'i'){
		printf("Factorielle à calculer : ");
		scanf("%d",&number);
		int fact_i = iter_fact(number);
		printf("Le résultat est : %d \n", fact_i);
	}
	if (action == 'r'){
		printf("Factorielle à calculer : ");
		scanf("%d",&number);
		int fact_r = rec_fact(number);
		printf("Le résultat est : %d \n", fact_r);
	}
}
