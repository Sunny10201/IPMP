#include<stdio.h>
#include<stdlib.h>
{
    void pro_ext_itself(int a[], int n ,int prod[])
    {
        for(int i=0;i<n;i++)
        {
            prod[i]=1
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    prod[i]=prod[i]*a[j];
                }
            }
        }
    }
    int main()
    {
        int n;
        printf("size of the array:");
        scanf("%d",n);
        int a[n],prod[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        prod_ext_itself(a,n,prod);
        for(int i=0;i<n;i++)
        {
            printf("%d ",prod[i]);
        }
        return 0;

    }
}