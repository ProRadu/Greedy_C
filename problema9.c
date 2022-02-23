#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a, const void *b)
{
int va=*(int*)a;
int vb=*(int*)b;
return (vb-va);
}
int main()
{
    int NA, NB, i, j, negA, negB, p=0, nrmax, nrmax2, toate=1;
    FILE* f=fopen("date.in","r");
    fscanf(f,"%d",&NA);
    fscanf(f,"%d",&NB);
    int *A=(int)malloc((NA+1)*sizeof(int));
    int *B=(int)malloc((NB+1)*sizeof(int));
    for(i=0;i<NA;i++)
        fscanf(f,"%d",&A[i]);
    for(j=0;j<NB;j++)
        fscanf(f,"%d",&B[j]);
    fclose(f);
    qsort(A, NA, sizeof(int), cmpfunc);
    qsort(B, NB, sizeof(int), cmpfunc);
    for(i=0;i<NA;i++)
        if(A[i]<0)
    {
        negA=i;
        break;
    }
     for(j=0;j<NB;j++)
        if(B[j]<0)
    {
        negB=j;
        break;
    }
    if(NA>NB)
        {nrmax=NB;nrmax2=NA;}
    else {nrmax=NA;nrmax2=NB;}
    i=0;
    while((A[i]>0)&&(B[i]>0))
       {
           p=p+A[i]*B[i];
           i++;
           toate=0;
       }
    i=nrmax-1;
    j=nrmax2-1;
    if(NB>NA)
        while(A[i]<0&&B[j]<0)
    {
        p=p+A[i]*B[j];
        i--;
        j--;
        toate=0;
    }
    else while(A[j]<0&&B[i]<0)
    {
        p=p+A[j]*B[i];
        i--;
        j--;
        toate=0;
    }
    if(toate==1)
       {
           if(negA==0)
            p=A[0]*B[NB-1];
            else p=A[NA-1]*B[0];
       }

    FILE* g=fopen("date.out","w");
    fprintf(g,"%d",p);
    fclose(g);
    free(A);
    free(B);
    return 0;
}
