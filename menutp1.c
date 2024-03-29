#include<stdio.h>



void saisirTableau(int T[], int n){
     int i;
    
    printf("Entrez les elements du tableau :\n");
    for (i = 0; i < n; i++) {
        printf("Element %d : ", i+1);
        scanf("%d", &T[i]);
    }
}

void afficherTableau(int T[], int n){
    int i;
     if (n == 0) {
    printf("Le tableau est vide.\n");
    return;
  }
    printf("Le tableau est : ");
    for (i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

int rechercherElement(int T[], int n, int x){
     int i;
    int frequence = 0;
    for (int i = 0; i < n; i++) {
        if (T[i] == x) {
            frequence++;
        }
    }
    return frequence;
}

void afficherElementPlusFrequent(int T[], int n){
     int i, j;
    int maxFrequence = 0;
    int elementPlusFrequent;

    for (i = 0; i < n; i++) {
        int frequence = 1; 
        for (j = i + 1; j < n; j++) {
            if (T[i] == T[j]) {
                frequence++;
            }
        }
        if (frequence > maxFrequence) {
            maxFrequence = frequence;
            elementPlusFrequent = T[i];
        }
    }

    printf("L'element le plus frequent est : %d avec une frequence de %d\n", elementPlusFrequent, maxFrequence);
}

void TriParInsertion(int T[], int n) {
    int i, j, temps;
    for (i = 1; i < n; i++) {
        temps = T[i];
        j = i - 1;
        while (j >= 0 && T[j] > temps) {
            T[j + 1] = T[j];
            j = j - 1;
        }
        T[j + 1] = temps;
    }

    printf("Tableau trier : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

void TriParSelection(int T[], int n) {
    int i, j, min, temps;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (T[i] < T[j]) {
                temps = T[i];
                T[i] = T[j];
                T[j] = temps;
            }
        }
    }

    printf("Tableau trier : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}








int main()
{
    
   int menu;
    int i,j,n,x;
    int T[30];
    int choix,frequence,choix2;
    

   
    do
    {
        printf("1.saisir le tableau\n");
        printf("2.afficher le tableau\n");  
        printf("3.rechercher un element et afficher sa frequence\n");  
        printf("4.afficher l'element le plus frequent et afficher sa frequence\n");  
        printf("5.trier le tableau\n");
        printf("6.Quitter\n"); 
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
            printf("Entrez la taille du tableau : ");
            scanf("%d", &n);
                saisirTableau(T, n);
                
                break;
            case 2:
                if (T == 0) {
                    printf("Le tableau est vide. Veuillez d'abord le remplir.\n");
                } else {
                    afficherTableau(T, n);
                }
                break;
            case 3:
                if (T == 0) {
                    printf("Le tableau est vide. Veuillez d'abord le remplir.\n");
                } else {
                    int x;
                    printf("Entrez l'element a rechercher : ");
                    scanf("%d", &x);
                    int frequence = rechercherElement(T, n, x);
                    printf("La frequence de %d dans le tableau est : %d\n", x, frequence);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("Le tableau est vide. Veuillez d'abord le remplir.\n");
                } else {
                    afficherElementPlusFrequent(T, n);
                }
                break;
            case 5:
                
                printf("1.tri par insertion\n");
                printf("2.tri par selection\n");
                scanf("%d",&choix2);
                if (choix2==1)
                {
                    TriParInsertion(T,n);
                }
                else if (choix2==2)
                {
                    TriParSelection(T,n);
                }
                else
                {
                    printf("erreur!!!");
                    return 1;
                }
                break;

            case 6:
                printf("Au revoir \n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir un numero de menu valide.\n");
        }
    }  while (choix != 6);
    return 0;
          

}