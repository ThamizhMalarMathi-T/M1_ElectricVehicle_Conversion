#include<stdio.h>
#include "Inv_ybus.c"
#include "Inv_inverse.c"
#include "Inv_zbus.c"
#include "Matrix_mul_copy.c"
#include "header.h"

#include<malloc.h>

int main()
{
	int bus, element;
	int i, j, n;
	
	float k;
	
	n=bus-1;

	printf("Enter the total number of buses: \n");
	scanf("%d",&bus);
	
	printf("\n Enter the total number of elements: \n");
	scanf("%d",&element);
	
	float **r, d;
	float **A_mat;
	float **Inverse;
	float **Y_bus;
	
	A_mat = incidence(bus, element);
	
	printf("\nDisplay A matrix:\n");
	for(i=0;i<element;i++)
	{
		for(j=0;j<bus;j++)
		{
        	printf("%0.2f \t", A_mat[i][j]);
		}
		printf("\n");
	}
	
	float A_trans[bus][element];
	
	for (i = 0; i < bus; ++i)
	{
		for (j = 0; j < element; ++j) 
  		{
    		A_trans[i][j] = A_mat[j][i];
  		}
	}
	
	
	printf("Display A transpose:\n");
	for(i=0;i<bus;i++)
	{
		for(j=0;j<element;j++)
		{
        	printf("%0.2f \t", A_trans[i][j]);
		}
		printf("\n");
	}
	
	r = Z_bus(bus, element);
	
	printf("Display Z bus:\n");
	for(i=0;i<element;i++)
	{
		for(j=0;j<element;j++)
		{
        	printf("%f", r[i][j]);
		}
		printf("\n");
	}
	
	
	//INVERSE OF PRIMITIVE IMPEDENCE MATRIX
  	
  	d = determinant(r, element);
  	if (d == 0)
   	printf("\nInverse of Entered Matrix is not possible\n");
  	else
    Inverse = cofactor(r, element);
    
    printf("Display Inverse Matrix:\n");
	for(i=0;i<element;i++)
	{
		for(j=0;j<element;j++)
		{
        	printf("%f", Inverse[i][j]);
		}
		printf("\n");
	}
	float **Trans = (float**)malloc(sizeof(float*)*bus);
	for(i=0;i<bus;i++)
	{
		Trans[i]=(float *)malloc(sizeof(float)*element);
		for(j=0;j<element;j++)
		{
        	 Trans[i][j]=A_trans[i][j];
		}
		printf("\n");
	}
	
	Y_bus = Mat_mul(A_mat,Trans,Inverse,bus,element);
	
	free(r);
	free(A_mat);
	free(Trans);

}
