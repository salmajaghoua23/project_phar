#ifndef MEDICAMENT_H_INCLUDED
#define MEDICAMENT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medical {
    char id[6];
    char medi_name[20];
    int quantity;
    int id_ordonance;
    int quantity_vendu;
    float cost;
    float profit;
    float bye;
    char exp_date[15];
    char supp_name[30];
};
typedef struct medical medical;

typedef struct str2 {
    medical data;
    struct str2 *next;
} listem;

void inserer_medi(listem **l, medical m1) {
    FILE *p = fopen("medicament.txt", "a+");
    if (p == NULL) {
        printf("Le fichier est introuvable.\n");
        exit(1);
    }

    listem *nouveau = (listem *)malloc(sizeof(listem));
    if (nouveau == NULL) {
        printf("Échec de l'allocation mémoire.\n");
        fclose(p);
        return;
    }

    nouveau->data = m1;
    nouveau->next = NULL;

    if (*l == NULL) {
        *l = nouveau; // Premier élément de la liste
    } else {
        listem *temp = *l;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nouveau;
    }

    fprintf(p, "%s %s %d %d %d %.2f %.2f %.2f %s %s\n",
            m1.id, m1.medi_name, m1.quantity, m1.id_ordonance, m1.quantity_vendu,
            m1.cost, m1.profit, m1.bye, m1.exp_date, m1.supp_name);

    fclose(p);
}

void affichage2(listem *l) {
    if (l == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    printf("Liste des médicaments :\n");
    while (l != NULL) {
        printf("ID : %s | Nom : %s | Quantité : %d | ID Ordonnance : %d | Quantité Vendue : %d | Coût : %.2f | Profit : %.2f | Prix d'achat : %.2f | Expiration : %s | Fournisseur : %s\n",
               l->data.id, l->data.medi_name, l->data.quantity, l->data.id_ordonance,
               l->data.quantity_vendu, l->data.cost, l->data.profit, l->data.bye,
               l->data.exp_date, l->data.supp_name);
        l = l->next;
    }
    printf("Fin de la liste.\n");
}


void menu_medicament(){
    listem *liste = NULL;
    char choix;

    do {
        printf("\n--- Menu Administrateur ---\n");
        printf("1. Ajouter un médicament\n");
        printf("2. Afficher la liste des médicaments\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix : ");
        scanf(" %c", &choix);

        switch (choix) {
        case '1': {
            medical m1;

            printf("\n--- Ajout d'un médicament ---\n");
            printf("ID : ");
            scanf("%s", m1.id);

            printf("Nom du médicament : ");
            scanf("%s", m1.medi_name);

            printf("Quantité : ");
            scanf("%d", &m1.quantity);

            printf("ID ordonnance : ");
            scanf("%d", &m1.id_ordonance);

            printf("Quantité vendue : ");
            scanf("%d", &m1.quantity_vendu);

            printf("Coût (prix unitaire) : ");
            scanf("%f", &m1.cost);

            printf("Profit : ");
            scanf("%f", &m1.profit);

            printf("Prix d'achat : ");
            scanf("%f", &m1.bye);

            printf("Date d'expiration (MM/YYYY) : ");
            scanf("%s", m1.exp_date);

            printf("Nom du fournisseur : ");
            scanf("%s", m1.supp_name);

            // Insérer dans la liste et sauvegarder dans le fichier
            inserer_medi(&liste, m1);
            printf("Médicament ajouté avec succès !\n");
            break;
        }
        case '2':
            printf("\n--- Liste des médicaments ---\n");
            affichage2(liste);
            break;

        case '3':
            printf("Fermeture du programme.\n");
            break;

        default:
            printf("Choix invalide. Réessayez.\n");
            break;
        }
    } while (choix != '3');


}

#endif // MEDICAMENT_H_INCLUDED
