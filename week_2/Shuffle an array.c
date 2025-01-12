#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void  random(int a[],int n)
{
    srand (time(NULL));
    for(int i=n-1;i>0;i++)
    {
        int j = rand() % (i + 1);
        swap(&a[i], &a[j]);
    }
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
    swap(a,n);
    random(a,n);
    return 0;
}