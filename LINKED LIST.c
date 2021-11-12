#include<stdio.h>
#include<stdlib.h>
/****************************************/
struct node
{
    int info;
    struct node *next;
};
/****************************************/
Getnode()
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    return t;
}
/***************************************/
InsBeg(struct node **list,int x)
{
    struct node *p;
    p=Getnode();
    p->info = x;
    p->next = (*list);
    (*list) = p;
}
/****************************************/
InsAft(struct node **list,int y,int x)
{
    struct node *t,*p;
    t=*list;
    while(t!=NULL)
    {
        if(t->info==y)
            break;
        else
            t=t->next;
    }
    p=Getnode();
    p->info = x;
    p->next = t->next;
    t->next=p;
}
/****************************************/
InsEnd(struct node **list,int x)
{
    struct node *p,*q;
    p=*list;
    if((*list)==NULL)
    {
        InsBeg((*list),x);
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        q=Getnode();
        q->info=x;
        q->next=NULL;
        p->next=q;
    }
}
/****************************************/
Traverse(struct node *list)
{
    struct node *p;
    p=list;
    while(p!=NULL)
    {
        printf("%d\t",p->info);
        p=p->next;
    }
    printf("\n");
}
/****************************************/
DelBeg(struct node **list)
{
    if(*list==NULL)
    {
        printf("Deletion not possible");
        return;
    }
    else
    {
        int x;
        struct node *p;
        p=*list;
        (*list)=(*list)->next;
        x=p->info;
        free(p);
        return x;
    }
}
/******************************************************/
DelEnd(struct node **list)
{
    if(*list==NULL)
    {
        printf("Deletion is not possible");
        return;
    }
    else
    {
        struct node *p, *q;
        q=NULL;
        p=*list;
        while(p->next != NULL)
        {
            q=p;
            p=p->next;
        }
        if(q != NULL)
        {
            q->next = NULL;
        }
        else
        {
            *list = NULL;
            free(p);
        }
    }
}
/******************************************************/
DelAft(struct node *p)
{
    struct node *q;
    if(p!=NULL && p->next!=NULL)
    {
        q=p->next;
        p->next=q->next;
        free(q);
    }
}
/*******************************************************/
void main()
{
    struct node *START;
    START = NULL;
    InsBeg(&START,10);
    InsBeg(&START,20);
    InsBeg(&START,30);
    InsBeg(&START,40);
    InsBeg(&START,50);
    printf("After Insert Beginning :\n");
    Traverse(START);
    InsEnd(&START,35);
    InsEnd(&START,25);
    printf("After Insert End :\n");
    Traverse(START);
    InsAft(&START,30,38);
    printf("After Insert After :\n");
    Traverse(START);

    printf("After Deletion Beginning :\n");
    DelBeg(&START);
    Traverse(START);
    printf("After Deletion End :\n");
    DelEnd(&START);
    Traverse(START);
    printf("After Deletion After :\n");
    DelAft(START);
    Traverse(START);
    return 0;
}
