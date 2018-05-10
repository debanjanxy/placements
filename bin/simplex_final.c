#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int NumofC, NumofV, type;
char typ;
int pivotc;
int pivotr;

void data_max(double table[NumofC+1][NumofC+NumofV+2])
{
    int i,j,k;
    for(i=0;i<=NumofC;i++)
    {
        for(j=0;j<=NumofV+NumofC+1;j++)
           {
           table[i][j]=0;
           }
    }


    printf("Enter co-effcients for objective functions: \n");
    printf("-------------------------------------------\n");
        for(j=0;j<NumofV;j++)
        {
            printf("Co-efficient %d: ",j+1);
            scanf("%lf",&table[NumofC][j]);
            printf("\n");
            table[NumofC][j]=-1*table[NumofC][j];
        }
    printf("Right_Hand_Term: ");
    scanf("%lf",&table[NumofC][NumofV+NumofC+1]);
    printf("\n");
    for(i=0;i<NumofC;i++)
    {
        //printf("------ENTER COEFFECIENTS FOR CONSTRAINT #%d------- \n",i+1);
        printf("Enter co-effcients for constraint no.%d: \n",i+1);
    	printf("-------------------------------------------\n");
        for(j=0;j<NumofV;j++)
        {
            printf("Co-efficient %d: ",j+1);
            scanf("%lf",&table[i][j]);
            printf("\n");
        }
        printf("Right_Hand_Term: ");
        scanf("%lf",&table[i][NumofV+NumofC+1]);
        printf("\n");
    }


    k=NumofV;
    for(i=0;i<=NumofC;i++)
        table[i][k++]=1;

    printf("----------------------Initial Simplex Tableau---------------------\n");
    printf("------------------------------------------------------------------\n");
    for(i=0;i<=NumofC;i++)
    {
        for(j=0;j<=NumofV+NumofC+1;j++)
           {
            printf("%f       ",table[i][j]);
           }
           printf("\n");
    }
    printf("------------------------------------------------------------------\n");
    printf("\n");


}

void data_min(double table[NumofC+1][NumofC+NumofV+2],double aug_table[NumofC+1][NumofV+1],double trans_table[NumofC+1][NumofV+1])
{
    int i,j,k;
    for(i=0;i<=NumofC;i++)
    {
        for(j=0;j<=NumofV+NumofC+1;j++)
           {
           table[i][j]=0;
           }
    }

    for(i=0;i<=NumofC;i++)
    {
        for(j=0;j<=NumofV;j++)
           {
           aug_table[i][j]=0;
           trans_table[i][j]=0;
           }
    }

    //printf("------ENTER COEFFECIENTS FOR OBJECTIVE FUNCTION------ \n");
    printf("Enter co-effcients for objective functions: \n");
    printf("-------------------------------------------\n");
    
        for(j=0;j<NumofV;j++)
        {
            printf("Co-efficient %d: ",j+1);
            scanf("%lf",&table[NumofC][j]);
            printf("\n");

        }
    printf("Right_Hand_Term: ");
    scanf("%lf",&table[NumofC][NumofV+NumofC+1]);
    printf("\n");

    for(i=0;i<NumofC;i++)
    {
        printf("Enter co-efficients for constraints %d\n",i+1);
        printf("-------------------------------------------\n");
        for(j=0;j<NumofV;j++)
        {
            printf("Enter co-efficient %d: ",j+1);
            scanf("%lf",&table[i][j]);
            printf("\n");
        }
        printf("Right_Hand_Term: ");
        scanf("%lf",&table[i][NumofV+NumofC+1]);
        printf("\n");
    }


    k=NumofV;
    for(i=0;i<=NumofC;i++)
        table[i][k++]=1;

    for(i=0;i<=NumofC;i++)
    {
        for(j=0;j<NumofV;j++)
           {
           aug_table[i][j]=table[i][j];
           }
        aug_table[i][NumofV]=table[i][NumofV+NumofC+1];
    }

    for (i=0; i<=NumofC; i++)
       {
           for (j=0; j<=NumofV; j++)
            trans_table[i][j] = aug_table[j][i];
       }
    for(i=0;i<=NumofC;i++)
    {

         for(j=0;j<NumofV;j++)
        {
                table[i][j]=trans_table[i][j];
        }
        table[i][NumofV+NumofC+1]=trans_table[i][NumofV];
    }

    for(j=0;j<NumofV;j++)
        {
            table[NumofC][j]=-1*table[NumofC][j];
        }


    printf("--------Initial Simplex Tableau---------- \n");
    printf("-------------------------------------------\n");
    for(i=0;i<=NumofC;i++)
    {
        for(j=0;j<=NumofV+NumofC+1;j++)
           {

            printf("%f       ",table[i][j]);
           }
           printf("\n");
    }
    printf("\n");


}
void pivot(double table[NumofC+1][NumofC+NumofV+2],int coeff[NumofC])
{
    int i;
    double j,k;
    j=table[NumofC][0];
    pivotc=-1;
    for(i=1;i<=NumofV+NumofC;i++)
    {
        if(table[NumofC][i]<j)
        {
            j=table[NumofC][i];
            pivotc=i;
            break;
        }
    }
    if (pivotc==-1)
        pivotc=0;

    pivotr=-1;
    k=table[0][NumofV+NumofC+1]/table[0][pivotc];
    for(i=0;i<NumofC;i++)
    {

        if((j=table[i][NumofV+NumofC+1]/table[i][pivotc])<0)
            {
                k=table[i+1][NumofV+NumofC+1]/table[i+1][pivotc];
                continue;
            }
        else if(j<=k)
           {
            k=j;
            pivotr=i;
           }
          //  pivotr=i;
    }

    if(pivotr<0)
       {
        printf("Sorry, solution does not exist.\n");
        exit(0);
       }

       coeff[pivotr]=pivotc;
}

int optimal(double table[NumofC+1][NumofC+NumofV+2])
{
    int i;
    for(i=0;i<=NumofV+NumofC;i++)
    {
        if(table[NumofC][i]<0)
            return 0;
    }
    return 1;
}

void operations(double table[NumofC+1][NumofC+NumofV+2])
{
    int i,j;
    double k;
    double l=table[pivotr][pivotc];
    for(i=0;i<=NumofV+NumofC+1;i++)
    {
        table[pivotr][i]/=l;

    }
    for(i=pivotr-1;i>=0;i--)
    {
        k=table[i][pivotc];
         for(j=0;j<=NumofV+NumofC+1;j++)
        {
            table[i][j]+= -k*table[pivotr][j];

        }
    }
    for(i=pivotr+1;i<=NumofC;i++)
    {
        k=table[i][pivotc];
         for(j=0;j<=NumofV+NumofC+1;j++)
        {
            table[i][j]+= -k*table[pivotr][j];

        }
    }
    printf("----------Optimization Iteration-----------\n");
    printf("-------------------------------------------\n");
    for(i=0;i<=NumofC;i++)
    {
        for(j=0;j<=NumofV+NumofC+1;j++)
           {

            printf("%f       ",table[i][j]);
           }
           printf("\n");
           printf("\n");
    }
    printf("\n");
}
void main()
{


	printf("-------------------------------------------\n");
	printf("	      SIMPLEX ALGORITHM              \n");
	printf("-------------------------------------------\n");
	printf("Press 1 to Maximize or 2 to Minimize: ");
    //printf("\n ENTER \n 1.MAXIMIZE \n 2.MINIMIZE \n");
    scanf("%d",&type);
    printf("\nNo. of Variables in the Objective Function: "); scanf("%d", &NumofV);
    printf("\nNo. of Constraints: "); scanf("%d", &NumofC);
    printf("\n");
    double table[NumofC+1][NumofC+NumofV+2], aug_table[NumofC+1][NumofV+1], trans_table[NumofC+1][NumofV+1];
    int i,j,k,l;
    int coeff[NumofC];

    k=NumofV;
    for(i=0;i<NumofC;i++)
        coeff[i]=0;

    if(type==1)
        data_max(table);
    else
        data_min(table,aug_table,trans_table);

    while(!optimal(table))
    {
        pivot(table,coeff);
        operations(table);
    }

printf("---------------------Answers----------------------\n");
printf("--------------------------------------------------\n");
if(type==1)
  {

   for(i=0;i<NumofV;i++)
    {
        printf("\nThe optimal value for variable %d is: ",i+1);
        for(j=0;j<NumofC;j++)
        {
            if(coeff[j]==i)
                {
                    printf("%lf \n",table[j][NumofC+NumofV+1]);
                    break;
                }
        }

    }
  }
else
{
    l=0;
    for(i=NumofV;i<NumofV+NumofC;i++)
    {
        printf("\nThe optimal value for variable %d is: ",l);
        printf("%lf \n",table[NumofC][i]);
        l++;
    }
}
    printf("\n\nThe optimal value for the objective function is: %lf\n\n",table[NumofC][NumofC+NumofV+1]);
printf("---------------------------------------------------\n");

}

