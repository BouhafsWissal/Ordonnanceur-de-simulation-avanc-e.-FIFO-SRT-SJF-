#ifndef RR_H_INCLUDED
#define RR_H_INCLUDED
void ordRR(Processus proc[],int n){
 int bt1[30];
 int index,k,j,tq,key1,c,r=0,f=0,key2;
 int ct[30];
 int rq[100][2]; 
 bubbleSort(proc,n);
 printf("Entrer time quantum: ");
	scanf("%d",&tq);
	
	for(int i=0; i<n; i++)
	{
          bt1[i]=proc[i].te;
	}
	printf("\n");

	for(int i=0; i<n; i++)
	{
		j=i-1;
		k=i-1;
		key1=proc[i].ta;
		key2=proc[i].te;
		while(j>=0 && key1<proc[j].ta)
		{
			proc[j+1].ta=proc[j].ta;
			proc[k+1].te=proc[k].te;
			j--;
			k--;
		}
		proc[j+1].ta=key1;
		proc[k+1].te=key2;
	}	
	
	// copy the contents of bt into bt1
	
	for(int i=0; i<n; i++)
		bt1[i]=proc[i].te;
	
	// printing the arrival and burst time
	printf("\nProcess\t\tArrival\t\tburst time\n");
	for(int j=0; j<n;j++)
	{       
		printf("%s\t\t %d\t\t %d\n",proc[j].nompross,proc[j].ta,proc[j].te);
		
		
	}
	printf("\n");
	
	
	// complete time
	
	if(proc[0].te>tq)
	{
		c=proc[0].ta+tq;
		proc[0].te=proc[0].te-tq;
		ct[0]=c;
		rq[r][0]=c;
		rq[r][1]=0;
		r++;
	}
	else{
		c=proc[0].ta+proc[0].te;
		ct[0]=c;
	}
	int i=1;
	while(i<n)
	{
		if(r!=0 && proc[i].ta<=rq[f][0])
		{  
			if(proc[i].te>tq){
				c=c+tq;
				ct[i]=c;
				proc[i].te=proc[i].te-tq;
				rq[r][0]=c;
				rq[r][1]=i;
				r++;
			}
			else{
				c=c+proc[i].te;
				ct[i]=c;
			}
			i++;
		}
		else if(r==0){
			if(proc[i].te>tq){
				c=c+tq;
				proc[i].te=proc[i].te-tq;
				rq[r][0]=ct[i];
				rq[r][1]=i;
				r++;
			}
			else{
				c=c+proc[i].te;
				ct[i]=c;
			}
			i++;
		}
		else{
			index=rq[f][1];
			f++;
			if(proc[index].te>tq){
				c=c+tq;
				ct[index]=c;
				proc[index].te=proc[index].te-tq;
				rq[r][0]=ct[index];
				rq[r][1]=index;
				r++;
			}
			else{
				c=c+proc[index].te;
				ct[index]=c;
			}
		}
	}
	      while(f<r)
	       {
               index=rq[f][1];
		f++;
		if(proc[index].te>tq)
		{
				c=c+tq;
				ct[index]=c;
				proc[index].te=proc[index].te-tq;
				rq[r][0]=ct[index];
				rq[r][1]=index;
				r++;
		}
		else{
				c=c+proc[index].te;
				ct[index]=c;
		}
	}
	
	int tt[30],tat[30];
	for(int i=0; i<n; i++)
	{
	  tat[i]=ct[i]-proc[i].ta;
	}
	
	
	int tempcourant=0;
i=0;
while(i<n){
if(tempcourant<proc[i].ta){
tempcourant++;
}
if(proc[i].ta<=tempcourant){
tempcourant+=tq;
i++;
}}
	
	
	int wt[30];
	for(int i=0; i<n; i++)
	{
		wt[i]=tat[i]-bt1[i];
	}
	
	printf("Process\t\tArrival\t\ttat\t\tWaiting\t\tsortie\n");
	for(int i=0; i<n; i++)
	{
	 printf("%s\t\t %d\t\t %d\t\t%d\t\t%d\n",proc[i].nompross,proc[i].ta,tat[i],tempcourant,ct[i]); 
	}
}



return 0;
}
#endif