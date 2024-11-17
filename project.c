
#include <stdlib.h>
//#include"employer.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>

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
//creation de l'element 
liste *creation(Employe x) {
    liste b = (liste *)malloc(sizeof(liste));
    if (b == NULL) {
      printf("insuffusant memoire ");
        return NULL;
    }
    b->data = x;
    b->suivant = NULL;
    return b;
}
void insertion (liste *l,Employe x)
{   FILE *p=fopen("employe.txt","w");
    liste b=creation(x);
    liste tp;
    if(*l==NULL)
      {
        l=b;
        printf("insertion au debut avec succes\n");
      }
    else{
     while(tp->suivant!=NULL)
     {
        tp=tp->suivant;
     }
     tp->suivant=b;
     b->suivant=NULL;
     fprintf(p,"%p ",b->data);

    } 
}
int main()
{ liste l;
 Employe x={1,"ali","gestion","ali09876",123.23};
   insertion(&l,x);  
}
