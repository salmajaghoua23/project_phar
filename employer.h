#ifndef EMPLOYER_H_INCLUDED
#define EMPLOYER_H_INCLUDED

#include <conio.h>
#include <string.h>
#include <math.h>
#include <dos.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Coordinate structure for console positioning
struct COORD {
    int X, Y;
};
COORD coord = {0, 0};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void box() {
    gotoxy(2, 2);
    printf("%c", 201);
    gotoxy(78, 2);
    printf("%c", 187);
    gotoxy(2, 24);
    printf("%c", 200);
    gotoxy(78, 24);
    printf("%c", 188);
    for (int i = 3; i < 78; i++) {
        gotoxy(i, 2);
        printf("%c", 205);
        gotoxy(i, 24);
        printf("%c", 205);
    }
    for (int i = 3; i < 24; i++) {
        gotoxy(2, i);
        printf("%c", 186);
        gotoxy(78, i);
        printf("%c", 186);
    }
}

typedef struct Employe {
    int employeID;
    char nom[50];
    char role[50];
    char contact[100];
    float salaire;
    struct Employe *next;
} Employe;

typedef struct str {
    Employe data;
    struct str *suivant;
} *liste;

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
                printf("ID: %d, Name: %s, Role: %s, Contact: %s,  Salary: %.2f\n",
                       l->data.employeID, l->data.nom, l->data.role, l->data.contact, l->data.salaire);
            }
            l = l->suivant;
        }
        printf("\n");
    }

    fclose(p);
    printf("Operation successful\n");
}

void supp(liste *l, int employeID) {
    if (*l == NULL) {
        printf("La liste est vide !!\n");
        return;
    }

    liste tp = *l;
    liste prev = NULL;

    if (tp != NULL && tp->data.employeID == employeID) {
        *l = tp->suivant;
        free(tp);
        printf("Element with ID %d deleted successfully!\n", employeID);
        return;
    }

    while (tp != NULL && tp->data.employeID != employeID) {
        prev = tp;
        tp = tp->suivant;
    }

    if (tp == NULL) {
        printf("Element with ID %d not found!\n", employeID);
        return;
    }

    prev->suivant = tp->suivant;
    free(tp);
    printf("Element with ID %d deleted successfully!\n", employeID);
}

void employer_menu() 
   { char ch;
    liste *l = NULL;
    Employe e1;
    system("cls");
    gotoxy(34, 3);
    textcolor(2);
    printf("*-+-+-+-+-+-+-+-*");
    gotoxy(35, 4);
    textcolor(2);
    printf("  Employer Menu  ");
    gotoxy(34, 5);
    textcolor(2);
    printf("*-+-+-+-+-+-+-+-*");
    gotoxy(25, 11);
    textcolor(15);
    printf("\n1-Add New Employer\n");
    gotoxy(25, 15);
    textcolor(15);
    printf("\n2-Update Employer");
    gotoxy(25, 19);
    textcolor(15);
    printf("\n3-Search Employer");
    gotoxy(25, 23);
    textcolor(15);
    printf( "4-Main Menu");
    box();
    gotoxy(10, 40);
    textcolor(15);
    printf("\t\n\nPress First Character for further Operations.....  ");
    gotoxy(10, 40);
    ch = toupper(getche());
    getc(ch);

    switch(ch) {
        case '1':
            insererfin(l, e1);
            break;
        case '2':
            printf("Enter ID of employee to delete:\n");
            int employeID;
            scanf("%d", &employeID);
            supp(l, employeID);
            break;
        case '3':
            affichage(*l);
            break;
        case '4':
            employer_menu();
            break;
        default:
            printf("Not found!!");
    }
   }
#endif // EMPLOYER_H_INCLUDED
