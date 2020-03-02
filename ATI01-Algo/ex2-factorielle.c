#include <stdio.h>
#include <stdlib.h>
void iter_fact(int fact){
	int i;
	int calc=1;
	for (i=1; i<=fact; i++){
		calc*=i;
	}
	printf("Le résultat est : %d", calc);
}
int rec_fact(int fact){
	if (fact == 0){
		return 1;
	}
	else{ 
		fact *= rec_fact(fact-1);
	}
	printf("Le résultat est : %d", fact);
	return 0;
}
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
