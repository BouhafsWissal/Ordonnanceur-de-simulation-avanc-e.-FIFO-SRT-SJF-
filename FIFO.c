#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<sched.h>
#include<unistd.h>
#include "FIFO.h"
#define TAILLE_MAX 1000 // Tableau de taille 1000


void fifo(Processus arr[],int n){
 bubbleSort(arr,n);
		printf("n\tProcessus\tTA \tTE\n");
		int i;

	for(i=0;i<n;i++){
		printf("%i\t%s\t\t%d\t%d\n",i+1,arr[i].nompross,arr[i].ta,arr[i].te);

	}

}