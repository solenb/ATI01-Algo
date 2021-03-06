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
	}
	printf("\n");
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

void add_tab(int** tabCalc,int** tab, int ** tab2, int nb_L, int nb_C){
	int i,j;
	for (i=0; i < nb_L; i++){
		for (j=0; j < nb_C; j++){
			tabCalc[i][j]= tab[i][j] + tab2[i][j];
		}
	}
}
void mul_tab(int** tabCalc,int** tab, int ** tab2, int nb_L, int nb_C){
	int i,j,k;
	for (i=0; i < nb_L; i++){
		for (j=0; j < nb_C; j++){
			for (k=0; k < nb_C; k++){
				tabCalc[i][j] += tab[i][k] * tab2[k][j];
			}
		}
	}
}


void trace_tab(int** tab, int nb_L, int nb_C){
	int i,j;
	int t=0;
	for (i=0; i < nb_L; i++){
		for (j=0; j < nb_C; j++){
			if (i == j){
				t += tab[i][j];
			}
		}
	}
	printf(" La trace résultante de la matrice : %d", t);
}

int** reduce_tab(int** T,int size,int del_L){
	int i,j,k=0,new_size=size-1;
	int** new_T;
	new_size=size-1;
	new_T=create_tab(new_size,new_size);
	for (i=1;i<size;i++){
			k=0;
			for (j=0;j<size;j++){
				if (j == del_L){
				}
				else{
					new_T[i-1][k]=T[i][j];
					k+=1;
				}
			}
	}
	return new_T;
}



int det_tab(int** tab, int nb_L){
	int i,det=0;
	if (nb_L == 2){
		det = tab[0][0]*tab[1][1]-(tab[0][1]*tab[1][0]);
	}
	else if (nb_L == 1){
		det=0;
	}
	else{
		for (i=0;i<nb_L;i++){
			if ( i%2 == 0){
				det=det - tab[0][i]*det_tab(reduce_tab(tab,nb_L,i),nb_L-1);
			}
			else{
				det=det + tab[0][i]*det_tab(reduce_tab(tab,nb_L,i),nb_L-1);
			}
		}
	}
	return det;
}	
 




int main(){

char action;
printf("Que voulez vous faire ?\n- Addition\t\t-> a\n- Multiplication\t-> m\n- Affichage de Matrice\t-> p\n- Calcul de la Trace\t-> t\n- Calcul de Déterminant\t-> d\n");
scanf("%c",&action);
getchar();

if((action == 'm') || (action == 'a') || (action == 'p') || (action == 't') || (action == 'd')){
	int** tab;
	printf("Création de la Matrice 1 : \n");
	printf("Entrer le nombre de lignes : ");
	scanf("%d",&lignes);
	printf("Entrer le nombre de colonnes : ");
	scanf("%d",&colonnes);
	
	tab=create_tab(lignes,colonnes);
	fill_tab(tab, lignes, colonnes);
	printf("Matrice 1 : \n");
	prompt_tab(tab, lignes, colonnes);

	if((action == 'a') || (action == 'm')){
		int** tab2;
		int** tabCalc;
		printf("Création de la Matrice 2 : \n");
		printf("Entrer le nombre de lignes : ");
		scanf("%d",&lignes);
		printf("Entrer le nombre de colonnes : ");
		scanf("%d",&colonnes);
		// Appels des fonctions pour créer, remplir et afficher le tableau
		tab2=create_tab(lignes,colonnes);
		fill_tab(tab2, lignes, colonnes);
		printf("Matrice 2 : \n");
		prompt_tab(tab2, lignes, colonnes);
		tabCalc=create_tab(lignes,colonnes);
		if (action == 'a'){
			// Appels des fonctions pour addictionner les matrices et afficher le résultat
			add_tab(tabCalc, tab, tab2, lignes, colonnes);
		}
		if((action == 'm')){
			mul_tab(tabCalc, tab, tab2, lignes, colonnes);
		}
		printf("Matrice résultant : \n ");
		prompt_tab(tabCalc, lignes, colonnes);
		delete_tab(tab2, lignes, colonnes);
		delete_tab(tabCalc, lignes, colonnes);
				
	
		
	}
	if ((action == 't')){
		trace_tab(tab, lignes, colonnes);
	}
	if (action == 'd'){
		if (lignes == colonnes){
			int det;
			det=det_tab(tab,lignes);
			printf("Determinant = %d",det);
		}
		else{
			printf("On ne peut pas calculer un déterminant avec une matrice non carrée.");
		}
	}
   	delete_tab(tab,lignes,colonnes);
	}
}
