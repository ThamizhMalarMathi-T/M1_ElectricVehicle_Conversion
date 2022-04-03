#include<stdio.h>
#include<malloc.h>

float **Mat_mul(float **A_mat, float **Trans, float **Inverse, int bus, int element)
{
	int i, j, k, c, d,n, sum = 0;
	n=bus-1;
	
	

  	float m[n][element],y_bus[n][n];
  	
  	printf("n= %d\n",n);
  	
  	for(i=0;i<bus;i++)
	{
		for(j=0;j<element;j++)
		{
          printf("%f ",Trans[i][j]);
		}
		printf("\n");
	}
	

 
   for(i=0;i<n;i++)    
	{    
	
		for(j=0;j<element;j++)    
		{    
			m[i][j]=0;    
			for(k=0;k<element;k++)    
			{    
			    
				m[i][j]+= (Trans[i+1][k]*Inverse[k][j]);  
				//printf("%f \t %f \t %f \n",m[i][j], Trans[i][k],Inverse[k][j]);
				//printf("%d \t %d \t %d \n",i,j,k);
			}    
		}    
	}
	
	
	for(i=0;i<n;i++)    
	{    
	
		for(j=0;j<n;j++)    
		{    
			y_bus[i][j]=0;    
			for(k=0;k<element;k++)    
			{    
				y_bus[i][j]+= (m[i][k]*A_mat[k][j+1]);  
				//printf("%f \t\n",y_bus[i][j]); 
			}    
		}    
	}
	
	
    printf("\nDisplay Y_bus:\n");
 float **Y_bus = (float**)malloc(sizeof(float*)*n);
    for (c = 0; c < n; c++) {
      Y_bus[c]=(float *)malloc(sizeof(float)*n);
	  for (d = 0; d < n; d++){
        Y_bus[c][d]=y_bus[c][d];
        printf("%f ",Y_bus[c][d]); }
      printf("\n");
    }
  
  return (Y_bus);

}

  