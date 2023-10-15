void bubbleSort2(Processus arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
       for (j = 0; j < n-i-1; j++)
           if (arr[j].te > arr[j+1].te )
              swap(&arr[j], &arr[j+1]);
    
}

void sjf(Processus arr[],int n){
 Processus tablefinale[20];
 int i=0,j,k=0,temptotal=0;
  while(k<n){
   Processus tabletemp[20];
   j=0;
   int temp=0;
  for(i=0;i<n;i++){
  if (arr[i].ta <= temptotal && Exist(tablefinale,arr[i].nompross,k)==0)
    {
	tabletemp[j++]=arr[i];
        temp+=arr[i].te;
    }

 }
 bubbleSort2(tabletemp,j);
 for(i=0;i<j;i++){
  	tablefinale[k++]=tabletemp[i];
 }
 if(temp==0){
	temp++;
 }
 temptotal+=temp;
 }
printf("n\tProcessus\tTA \tTE\n");
for(i=0;i<k;i++){		       
printf("%d\t%s\t\t%d\t%d\n",i+1,tablefinale[i].nompross,tablefinale[i].ta,tablefinale[i].te);
}
}
