#include <stdio.h>
#include <stdlib.h>

//la liste chainée contenant les caracteres
typedef struct caract {
    char caractere;
    struct caract* suivant;
} caract;

//L'ajout d'un caractère a la fin de la liste 
void ajouterCaractere(caract** tete, char ch) {
    caract* nouveaucaract = (caract*)malloc(sizeof(caract));
    nouveaucaract->caractere = ch;
    nouveaucaract->suivant = NULL;

    if (*tete == NULL) {
        *tete = nouveaucaract;
    } else {
        caract* current = *tete;
        while (current->suivant != NULL) {
            current = current->suivant;
        }
        current->suivant = nouveaucaract;
    }
}

//chiffrer ou déchiffrer  la liste
char chiffreDeCesar(char ch, int decalage) {
    if (ch >= 'A' && ch <= 'Z') {
        ch = ((ch - 'A' + decalage) % 26) + 'A';
    }
    if (ch >= 'a' && ch <= 'z') {
    	ch = ((ch - 'a' + decalage) % 26) + 'a';
    }
    return ch ;
}
void chiffreListe(caract* tete, int decalage) {
    caract* current = tete;
    while (current != NULL) {
        current->caractere = chiffreDeCesar(current->caractere, decalage);
        current = current->suivant;
    }
}

//affichage de la liste
void afficherListe(caract* tete) {
    caract* current = tete;
    while (current != NULL) {
        printf("%c", current->caractere);
        current = current->suivant;
    }
    printf("\n");
}

int main() {
    caract* tete = NULL;
    int decalage;
    int choix;
    
	  printf(" Chiffre de Cesar \n");
    printf("1. Chiffrer un message\n");
    printf("2. Dechiffrer un message\n");
    printf("Choix : ");
    scanf("%d", &choix);
    getchar();
    
    if (choix == 1) {
        printf("Entrez le message a chiffrer : \n");
	      char ch;
        while ((ch = getchar()) != '\n'){
        ajouterCaractere(&tete, ch);
        }
    }
    else{
        printf("Entrez le message a dechiffrer : \n");
	      char ch;
        while ((ch = getchar()) != '\n'){
        ajouterCaractere(&tete, ch);
        }
    }
    

    printf("Entrez le decalage (nombre de positions) : \n");
    scanf("%d", &decalage);

    chiffreListe(tete, decalage);

    printf("Message chiffre ou déchiffre : ");
    afficherListe(tete);

    return 0;
}
