#include<stdio.h>
#include<malloc.h>

float **incidence(int bus, int element)
{
	
	
	int i,j,n,s[element], t[element];
	n=bus-1;
	
	float **x = (float**)malloc(sizeof(float*)*element);

	
	for(i=0;i<element;i++)
	{
		printf("\n Enter the starting bus: \n");
		scanf("%d",&s[i]);
		printf("\n Starting bus is: %d \n", s[i]);

		printf("\n Enter the ending bus: \n");
		scanf("%d",&t[i]);
		printf("\n Ending bus is: %d \n", t[i]);
	}
	
	for(i=0;i<element;i++)
	{
		x[i]=(float *)malloc(sizeof(float)*bus);
		for(j=0;j<bus;j++)
		{
			if(s[i]==j)
				x[i][j]=1;
			else if(t[i]==j)
				x[i][j]=-1;
			else
				x[i][j]=0;
		}
	}
	for(i=0;i<element;i++)
	{
		for(j=0;j<bus;j++)
		{
			printf("\n Display bus incidence matrix: \n");
			printf("\n X[%d][%d]= %f",i,j,x[i][j]);
		}
	}
	return(x);
}


	
	