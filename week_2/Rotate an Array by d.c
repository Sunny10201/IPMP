#include<stdio.h>
#include<stdlib.h>

void rotate_arr(int a[],int n ,int d)
{
    for(int i=0;i<d;i++)
    {
        int temp=a[0];
        for(int j=0;j<n-1;j++)
        {
            a[j]=a[j+1];
        }
        a[n-1]=temp;
    }
}
int main()
{
    int a[10],n,d;
    printf("size of an array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",a[i]);
    }
    printf("rotate the array:");
    scanf("%d",&d);
    rotate_arr(a,n,d);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}