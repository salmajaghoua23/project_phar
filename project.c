#include <stdlib.h>
#include<stdio.h>
#include "employer.h"
int main(){
     liste l1 = NULL;  // Initialize the list to NULL
    Employe e1;

   /*printf("Enter your ID:\n");
    scanf("%d", &e1.employeID);
    getchar();  // Consume the newline character left by scanf

    printf("Enter your name, your role in the pharmacy, and your contact:\n");

    printf("Name:\t");
    fgets(e1.nom, sizeof(e1.nom), stdin);
    e1.nom[strcspn(e1.nom, "\n")] = '\0';  // Remove the newline character

    printf("Role:\t");
    fgets(e1.role, sizeof(e1.role), stdin);
    e1.role[strcspn(e1.role, "\n")] = '\0';  // Remove the newline character

    printf("Contact:\t");
    fgets(e1.contact, sizeof(e1.contact), stdin);
    e1.contact[strcspn(e1.contact, "\n")] = '\0';  // Remove the newline character

    printf("Enter your salary:\n");
    scanf("%f", &e1.salaire);
    fflush(stdin);

    insererfin(&l1, e1);

    printf("Displaying results:\n");
    affichage(l1);*/
    int id;
    printf("saisir l'id pour la suppresion\n");
    scanf("%d",&id);
    supp(&l1,id);
    affichage(l1);
    //employer_menu();
    return 0;
}
