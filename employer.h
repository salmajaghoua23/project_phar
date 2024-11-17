
#ifndef employer_H_INCLUDED
#define  employer_H_INCLUDED
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
}liste;
//creation de l'element 
liste * creation (liste *l,Employe x)
{

    
}


#endif 