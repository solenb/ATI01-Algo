#include <stdio.h> 
#include <stdlib.h>
 
int lignes, colonnes;
int** create_tab(int nb_L, int nb_C){
	int** T;
	int i;
	T = (int**) malloc(nb_L * sizeof(double*));
	for (i=0; i < nb_L; i++){
		T[i] = (int*) malloc(nb_C * sizeof(double));
	}
return T;
}
void delete_tab (int** T, int nb_L, int nb_C){
	int i;
	for (i=0; i < nb_L; i++){
		free(T[i]);
	}
free(T);
}
void fill_tab(int** T,int  nb_L,int  nb_C){
	printf("Entrer le nombre de lignes : ");
	scanf("%d",&lignes);
	printf("Entrer le nombre de colonnes : ");
	scanf("%d",&colonnes);
	int i,j;
	for (i=0; i < nb_L; i++){
		for (j=0; j < nb_C; j++){
			printf("Adresse [%d][%d] : ",i,j);
			scanf("%d",&T[i][j]);
		}
	}
}

void prompt_tab(int** T, int nb_L, int nb_C){
	int i,j;
	for (i=0; i < nb_L; i++){
		for (j=0; j < nb_C; j++){
			printf(" %d ",T[i][j]);

		}
	printf("\n");
	}
}

	// void add_tab(int** T, int nb_L, int nb_C){

int main(){

char action;
printf("Que voulez vous faire ?\n- Addition\t\t-> a\n- Multiplication\t-> m\n- Affichage de Matrice\t-> p\n- Calcul de la Trace\t-> t\n- Calcul de Déterminant\t-> d\n");
scanf("%c",&action);
getchar();

if((action == 'm') || (action == 'a')){
	int** tab;
	int** tab2;
	tab=create_tab(lignes, colonnes);
	tab2=create_tab(lignes, colonnes);
	fill_tab(tab, lignes, colonnes);
	fill_tab(tab2, lignes, colonnes);
	prompt_tab(tab, lignes, colonnes);
	prompt_tab(tab2, lignes, colonnes);
	delete_tab(tab, lignes, colonnes);
	delete_tab(tab2, lignes, colonnes);
};
if(action == 'p'){
	int** tab;
	tab=create_tab(lignes,colonnes);
	fill_tab(tab, lignes, colonnes);
	prompt_tab(tab, lignes, colonnes);
	delete_tab(tab, lignes, colonnes);
};

}
