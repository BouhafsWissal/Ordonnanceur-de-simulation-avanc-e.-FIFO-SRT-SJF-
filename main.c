#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<sched.h>
#include<unistd.h>
#include "main.h"
#include "FIFO.h"
#include "sjf.h"
#include "rr.h"
int main(int argc, char *argv[])
{
 Processus * arr;
 int choix;
 char source[80];
 printf("Donner un fichier \n");
 scanf("%s",source);
 arr=LireProccesus(source);
 int n=nbpross("config.txt");
 printf("Algorithmes d'ordonnencement 1.FIFO 2.SJF 3.Tourniquet\n")
 printf("Donner votre choix \n");
 scanf("%d",&choix);

switch (choix) {
            case 1:
                fifo(arr,n);
                break;
            case 2:
                sjf(arr,n);
                break;
            case 3:
                ordRR(arr,n);
                break;
            default:
                printf("Erreur");
                break;
        }
 
 return 0;
}