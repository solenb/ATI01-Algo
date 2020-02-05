#include <stdio.h> 
#include <stdlib.h>

int main()
{ 
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
	int fill_tab(int** T,int  nb_L,int  nb_C){
		int i,j;
		for (i=0; i < nb_L; i++){
			for (j=0; j < nb_C; j++){
				scanf("%d",&T[i][j]);
			}
		}
	}


	int prompt_tab(int** T, int nb_L, int nb_C){
		int i,j;
		for (i=0; i < nb_L; i++){
			for (j=0; j < nb_C; j++){
				printf("%d",T[i][j]);
			}
		}
	}

	printf("Entrer le nombre de lignes : ");
	scanf("%d",&lignes);
	printf("Entrer le nombre de colonnes : ");
	scanf("%d",&colonnes);
	printf("Lignes : %d\n",lignes);
	printf("Colonnes : %d\n",colonnes);


	int** tab;
	tab=create_tab(lignes, colonnes);
	fill_tab(tab, lignes, colonnes);
	prompt_tab(tab, lignes, colonnes);
	delete_tab(tab, lignes, colonnes);

}
