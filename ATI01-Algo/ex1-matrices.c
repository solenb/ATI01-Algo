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
	int i,j;
	for (i=0; i < nb_L; i++){
		for (j=0; j < nb_C; j++){
			printf("Adresse [%d][%d] : ",i,j);
			scanf("%d",&T[i][j]);
		}
	printf("\n");
	}
}

void prompt_tab(int** T, int nb_L, int nb_C){
	int i,j;
	for (i=0; i < nb_L; i++){
		for (j=0; j < nb_C; j++){
			printf(" %d ",T[i][j]);
		}
	}
	printf("\n");
}

void add_tab(int** tabCalc,int** tab, int ** tab2, int nb_L, int nb_C){
	int i,j;
	for (i=0; i < nb_L; i++){
		for (j=0; j < nb_C; j++){
			tabCalc[i][j]= tab[i][j] + tab2[i][j];
			printf(" %d ",tabCalc[i][j]);
		}
	}
}



int main(){

char action;
printf("Que voulez vous faire ?\n- Addition\t\t-> a\n- Multiplication\t-> m\n- Affichage de Matrice\t-> p\n- Calcul de la Trace\t-> t\n- Calcul de Déterminant\t-> d\n");
scanf("%c",&action);
getchar();

if((action == 'm') || (action == 'a')){
	int** tab;
	int** tab2;
	int** tabCalc;
	printf("Entrer le nombre de lignes : ");
	scanf("%d",&lignes);
	printf("Entrer le nombre de colonnes : ");
	scanf("%d",&colonnes);

////////// Création des 3 matrices
	tab=create_tab(lignes, colonnes);
	tab2=create_tab(lignes, colonnes);
	tabCalc=create_tab(lignes, colonnes);
////////// Remplissage des mactrices rentées par l'utilisateur
	fill_tab(tab, lignes, colonnes);
	fill_tab(tab2, lignes, colonnes);
////////// Affichage des mactrices rentées par l'utilisateur 
	printf("Matrice 1 : \n");
	prompt_tab(tab, lignes, colonnes);
	printf("Matrice 2 : \n");
	prompt_tab(tab2, lignes, colonnes);
	
	if((action == 'a')){
		add_tab(tabCalc, tab, tab2, lignes, colonnes);
		prompt_tab(tabCalc, lignes, colonnes);
		delete_tab(tab, lignes, colonnes);
		delete_tab(tab2, lignes, colonnes);
		delete_tab(tabCalc, lignes, colonnes);
	};
	if((action == 'm')){
		delete_tab(tab, lignes, colonnes);
		delete_tab(tab2, lignes, colonnes);
	};
};
if(action == 'p'){
	int** tab;
	printf("Entrer le nombre de lignes : ");
	scanf("%d",&lignes);
	printf("Entrer le nombre de colonnes : ");
	scanf("%d",&colonnes);
	tab=create_tab(lignes,colonnes);
	fill_tab(tab, lignes, colonnes);
	prompt_tab(tab, lignes, colonnes);
	delete_tab(tab, lignes, colonnes);
};

}
