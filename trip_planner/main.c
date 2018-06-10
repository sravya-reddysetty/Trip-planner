#include <stdio.h>
#include <stdlib.h>
int max(int a,int b,int c)
{

    int m;
    m=a>b?a:b;
    m=m>c?m:c;
    return m;
}
int main()
{
    long s1,s2,i,j,a,b,c,d;
    printf("Enter number of places in each plan for 2 friends\n");
    scanf("%ld%ld",&s1,&s2);
    if(s1==0||s2==0)
    {
        printf("Maximum places which both of them can travel together = 0 \n");
        return 0;
    }
    char* plan1=(char*)malloc(s1*sizeof(char));
    char* plan2=(char*)malloc(s2*sizeof(char));
    char res[s1>s2?s1:s2];
    printf("Enter 2 plan sequences\n");
    scanf("%s%s",plan1,plan2);
   // printf("%s %s \n",plan1,plan2);
    int** grid=(int**)malloc((s1+1)*sizeof(int*));
    for(i=0;i<=s1;i++)
    {
        grid[i]=(int*)malloc((s2+1)*sizeof(int));
    }
    for(i=0;i<=s1;i++)
    {
        for(j=0;j<=s2;j++)
        {
            grid[i][j]=0;
        }
    }
    for(i=1;i<=s1;i++)
    {
        for(j=1;j<=s2;j++)
        {
          if(plan1[i-1]==plan2[j-1])grid[i][j]=grid[i-1][j-1]+1;
         else
         {
            grid[i][j]=max(grid[i-1][j-1],grid[i-1][j],grid[i][j-1]);
         }
        }
    }
   /*  for(i=0;i<=s1;i++)
    {

        for(j=0;j<=s2;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    printf("%ld %ld",i,j);*/
    i=s1;j=s2;
    long k=-1;
    while(i!=0)
    { //printf("while entered i=%ld j=%ld plan1[i-1]=%c plan2[j-1]=%c\n",i,j,plan1[i-1],plan2[j-1]);
        if(plan1[i-1]==plan2[j-1])
        {
            res[++k]=plan1[i-1];
            i-=1;
            j-=1;
        }
        else
        {
            a=grid[i-1][j-1];
            b=grid[i-1][j];
            c=grid[i][j-1];
        //    printf("a=%ld b=%ld c=%ld",a,b,c);
            d=max(a,b,c);
          //  printf("d=%ld \n",d);
            if(d==a){ i=i-1,j=j-1;}
            else if(b==d){i=i-1;}
            else {j=j-1;}
        }
    }

    printf("Maximum places which both of them can travel together = %ld \n",grid[s1][s2]);
    printf("The sequence of places which are to be visited are : ");
    for(i=k;i>=0;i--)printf("%c ",res[i]);
    return 0;
}
