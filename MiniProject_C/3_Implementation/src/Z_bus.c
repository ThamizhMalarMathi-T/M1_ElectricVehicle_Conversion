#include<stdio.h>
#include<malloc.h>


float **Z_bus(int bus, int element)
{
	int i, j, n_mutual, e1, e2;
	float z_mutual[element];
	
	float **z = (float**)malloc(sizeof(float*)*element);
	
	for(i=0;i<element;i++)
	{
		z[i]=(float *)malloc(sizeof(float)*element);
		for(j=0;j<element;j++)
		{
			if(i==j)
			{
				printf("Enter the primitive element:");
				scanf("%f",&z[i][j]);
			}
			else
				z[i][j]=0;
		}
	}
	
	printf("Enter the number of mutual impedences:\n");
	scanf("%d",&n_mutual);
	printf("The system has %d mutual impedences\n",n_mutual);

	if(n_mutual != 0)
	{
		for(i=0;i<n_mutual;i++)
		{
			printf("Enter the mutual impdence: \n");
			scanf("%f",&z_mutual[i]);
			printf("Z_mutual:%f\n",z_mutual[i]);
			
			printf("Enter the elements: \n");
			scanf("%d%d",&e1, &e2);
			printf("e1 =%d\ne2 = %d\n",e1,e2);
			
			z[e1][e2] = z_mutual[i];
			z[e2][e1] = z_mutual[i];
			printf("z[e1][e2]=%fz[e2][e1] =%f",z_mutual[i],z_mutual[i]);
		}
	}
	printf("\n Display the primitive impedence matrix: \n");
			for(i=0;i<n_mutual;i++)
			{
				for(j=0;j<n_mutual;j++)
				{
					
					printf("Z[][] = %f",z[i][j]);
					
			    }
			    printf("\n");
			}
		
			return(z);
}

	