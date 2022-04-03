#include<stdio.h>
#include<math.h>

float **transpose(float **r, float **fac, int element);

float determinant(float **r, int element)
{
  float s = 1;
  int i, j, m, n, c;
  float det;
  float **b = (float**)malloc(sizeof(float*)*(element-1));
  if (element == 1)
      {
     return (r[0][0]);
    }
  	else
    {
     det = 0;
     for (c = 0; c < element; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < element; i++)
          {
          	b[i]=(float *)malloc(sizeof(float)*(element-1));
            for (j = 0 ;j < element; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = r[i][j];
                   if (n < (element - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (r[0][c] * determinant(b, element - 1));
          s = -1 * s;
          }
    }
     
    return (det);
}

float **cofactor(float **r, int element)
{
 float **b = (float**)malloc(sizeof(float*)*(element));
 int p, q, m, n, i, j;
 float **Inv;
 float **fac = (float**)malloc(sizeof(float*)*(element));
 
 for (q = 0;q < element; q++)
 {
   fac[q]=(float *)malloc(sizeof(float)*(element));
   for (p = 0;p < element; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < element; i++)
     {
     	b[i]=(float *)malloc(sizeof(float)*(element));
       for (j = 0;j < element; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = r[i][j];
            if (n < (element - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
          }
		}
  }  
      fac[q][p] = pow(-1, q + p) * determinant(b, element - 1);
    }
  }
  
  Inv = transpose(r, fac, element);
  return (Inv);
}

float **transpose(float **r, float **fac, int element)
{
  int i, j;
  float d;
  
  float **inverse = (float**)malloc(sizeof(float*)*(element-1));
  
  d = determinant(r, element);
  
  for (i = 0;i < element; i++)
    {
    inverse[i]=(float *)malloc(sizeof(float)*(element-1));
     for (j = 0;j < element; j++)
       {
        inverse[i][j] = fac[j][i] / d;
    	}
    }
     return (inverse);
}

