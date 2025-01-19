#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *createnode(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
void Intersection_point(struct node *head1,struct node *head2)
{
    struct node *temp1=head1;
    struct node *temp2=head2;
    int count1=0,count2=0;
    while(temp1!=NULL)
    {
        count1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        count2++;
        temp2=temp2->next;
    }
    int diff=abs(count1-count2);
    temp1=head1;
    temp2=head2;
    if(count1>count2)
    {
        for(int i=0;i<diff;i++)
        {
            temp1=temp1->next;
        }
    }
    else
    {
        for(int i=0;i<diff;i++)
        {
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1==temp2)
        {
            printf("Intersection point is %d",temp1->data);
            return;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    printf("No intersection point");
}
int main()
{
    struct node *head1=createnode(10);
    head1->next=createnode(20);
    head1->next->next=createnode(30);
    head1->next->next->next=createnode(40);
    head1->next->next->next->next=createnode(50);
    head1->next->next->next->next->next=createnode(60);
    struct node *head2=createnode(70);
    head2->next=createnode(80);
    head2->next->next=createnode(90);
    head2->next->next->next=head1->next->next->next;
    Intersection_point(head1,head2);
    return 0;
}