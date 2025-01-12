#include<stdio.h>
#include<stdlib.h>
int equi(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int start=0;
        for(int j=0;j<i;j++)
        {
            start=start+a[j]
        }
        int end=0;;
        for(int j=i+1;j<n;j++)
        {
            end=end+a[j];
        }
        if(start==end)
        {
            return i;
        }
        
    }
    return -1;
    
}
int main()
{
    int n;
    printf("size of an array:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",a[i]);
    }
    equi(a,n);
    return 0;
}