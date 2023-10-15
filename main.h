typedef struct Processus{
    char nompross[50];
    int ta;
    int te;
    int priorite;
}Processus;

void swap(Processus *xp, Processus *yp)
{
    Processus temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Processus arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
       for (j = 0; j < n-i-1; j++)
           if (arr[j].ta > arr[j+1].ta )
              swap(&arr[j], &arr[j+1]);
}
int nbpross(char *filename)
{
    FILE *fp;
    int n=0;
    char c;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }
  
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            n ++;
    fclose(fp);
    return n;
}
 Processus * LireProccesus(char source[]){
   int i=0;
    Processus * tablepross=malloc(nbpross(source) * sizeof(Processus));
    FILE* fichier = NULL;
    fichier = fopen(source, "r+");
    char * buffer = 0;
    long length;
    if (fichier)
    {
    fseek (fichier, 0, SEEK_END);
    length = ftell (fichier);
    fseek (fichier, 0, SEEK_SET);
    buffer = malloc (length+1);
    
    if (buffer)
  {
    fread (buffer, 1, length, fichier);//contient le fichier non triee 
   
  }
   buffer[length] = '\0';
    fclose(fichier);
    }
 if (buffer)
{  
    char *pt;
    char *end_str;
    pt =  strtok_r(buffer, "\n", &end_str);
    while (pt != NULL) {
    	Processus pross;
    	char *end_str2;
    	char *pt2;
    	pt2 = strtok_r(pt, "\t", &end_str2);//P1 P2 P3 P4
    	Processus pr;
    	strcpy(pr.nompross,pt2);
    	pt2 = strtok_r (NULL, "\t",&end_str2);//4 3 0 2 ta
    	pr.ta = atoi(pt2);	
    	pt2 = strtok_r (NULL, "\t",&end_str2);//te te te te
	pr.te = atoi(pt2);
	pt2 = strtok_r (NULL, "\t",&end_str2); //priorite
	tablepross[i]=pr;
	i++;
        pt = strtok_r (NULL, "\n",&end_str); 
} 
}
return tablepross;
}
void bubbleSort2(Processus arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
       for (j = 0; j < n-i-1; j++)
           if (arr[j].te > arr[j+1].te )
              swap(&arr[j], &arr[j+1]);
    
}

int Exist(Processus arr[],char nompross[],int n)
{
    int i;
    for(i=0;i<n;i++){
     if(strcmp(arr[i].nompross, nompross)==0)
       return 1;
}
return 0;
}