#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char countryname[15];
    char memory[2];
    struct node *next;
};
struct node *start=NULL;
void ADD(struct node **s,char memo,char x)
{
    struct node *p,*t;
    p=(struct node*)malloc(sizeof(struct node));
    p-> memory[2]=memo;
    p-> countryname[15]=x;
    p-> next =NULL;
    if (*s==NULL)
        *s=p;
    else
        t=*s;
    while(t->next != NULL)
        t=t->next;
    t->next =p;
}
void DELETE(struct node **s)
{
    struct node *r,*t;
    t= *s;
    if(t==NULL)
        printf("empty");
        while(t!=NULL)
    {
        if (t->memory=="P")
        {
        r=t;
        t=t->next;
        free(r);
        }

    }
}
void DISPLAY(struct node **s)
{
    struct node *t;
    t=*s;
    while(t->next!=NULL)
    {
        printf("%c",t->countryname);
        t=t->next;
    }
}
int main()
{
    int n,i,c,x;
    printf("1.ADD");
    printf("2.DISPLAY");
    printf("3.DELETE");
    printf("Enter number of countries.");
    scanf("%d",&x);
    printf("Enter number of operations.");
    scanf("%d",&n);
    char country[15];
    char memorytype[2];
    for(i=1;i<=n;i++)
    {
        printf("Enter your choice");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            {


            printf("Enter country name.");
            scanf("%s",&country);
            printf("Enter P/NP.");
            scanf("%s",&memorytype);
            ADD(&start,country[15],memorytype[15]);
            }
            break;
         case 2:
             DISPLAY(&start);
             break;
         case 3:
            DELETE(&start);
            break;
         default:
            printf("Invalid choice.");
            break;
        }
    }
}
