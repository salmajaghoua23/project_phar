
#ifndef employer_H_INCLUDED
#define  employer_H_INCLUDED
#include <stdlib.h>
#include<stdio.h>

typedef struct Employe {
    int employeID;
    char nom[50];
    char role[50];
    char contact[100];
    int salaire;
    struct Employe *next;
} Employe;
typedef struct str{
Employe data;
struct str *suivant;
}*liste;
//insertion un ele ala fin

void insererfin(liste *l, Employe e1) {
    FILE *p = fopen("employer.txt", "a+");
    if (p == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    // Create a new list element
    liste b = (liste)malloc(sizeof(struct str));
    if (b == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    b->data = e1;
    b->suivant = NULL;

    if (*l == NULL) {
        *l = b;
        printf("Insertion at the beginning successful\n");
    } else {
        liste tp = *l;
        while (tp->suivant != NULL) {
            tp = tp->suivant;
        }
        tp->suivant = b;
    }

    fprintf(p, "%d %s %s %s %.2f\n", b->data.employeID, b->data.nom, b->data.role, b->data.contact, b->data.salaire);
    fclose(p);
}


void affichage(liste l) {
    FILE *p = fopen("employer.txt", "r");
    if (p == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    if (l != NULL) {
        while (l != NULL) {
            if (fscanf(p, "%d %s %s %s %f", &l->data.employeID, l->data.nom, l->data.role, l->data.contact, &l->data.salaire) != EOF) {
                printf("ID: %d, Name: %s, Role: %s, Contact: %s, Salary: %.2f\n",
                       l->data.employeID, l->data.nom, l->data.role, l->data.contact, l->data.salaire);
            }
            l = l->suivant;
        }
        printf("\n");
    }

    fclose(p);
    printf("Operation successful\n");
}
#endif
