#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
}*front=NULL,*rear=NULL;

struct node* createNode(void);
void insertFront(int);
void insertRear(int);
void deleteFront(void);
void deleteRear(void);
void getRear(void);
void getFront(void);
void isEmpty(void);
int isFull(void);

int main()
{
  int m,i=0,n,x;
  printf("1.addFront\n2.addRear\n3.DrawFront\n4.DrawRear\n5.PeekFront\n6.PeekRear\n7.IsEmpty\n8.IsFull");
  printf("\nEnter the number of operations you wish to perform.");
  scanf("%d",&m);
  while(i!=m)
 {
     printf("\nEnter the index number of operation you wish to perform");
     scanf("%d",&n);
     switch(n)
     {


     case 1:
       {
           printf("\nEnter the card number.");
           scanf("%d",&x);
           insertFront(x);
        }break;
     case 2:
        {
            printf("\nEnter the card number.");
           scanf("%d",&x);
           insertRear(x);
        } break;
     case 3:
        {
            deleteFront();
        } break;
     case 4:
        {
            deleteRear();
        } break;
     case 5:
        {
            getFront ();
        } break;
     case 6:
        {
            getRear ();
        } break;
     case 7:
        {
            isEmpty ();
        } break;
     case 8:
        {
          n=isFull ();
          if(n)
            printf("yes");
          else
            printf("No");
        } break;
     default:
        printf("\nINVALID!");
     }
     i++;
 }
}
struct node* createNode()
{
 struct node *m;
 m=(struct node *)malloc(sizeof(struct node));
 return(m);
}
void insertFront(int x)
{
    struct node *newNode;
    if(isFull())
    {
        printf("Deck is full.");
    }
    else if(front==NULL&&rear==NULL)
    {
        newNode=createNode();
        newNode->prev=NULL;
        newNode->next=NULL;
        newNode->data=x;
        front=newNode;
        rear=newNode;
    }
    else
    {
        newNode=createNode();
        newNode->prev=NULL;
        newNode->data=x;
        newNode->next=front;
        front->prev=newNode;
        front=newNode;

    }
}
void insertRear (int x)
{
    struct node *newNode;
    if(isFull())
    {
        printf("Deck is full.");
    }
    else if(front==NULL&&rear==NULL)
    {
        newNode=createNode();
        newNode->prev=NULL;
        newNode->next=NULL;
        newNode->data=x;
        front=newNode;
        rear=newNode;
    }
    else
    {
        newNode=createNode();
        newNode->data=x;
        newNode->next=NULL;
        newNode->prev=rear;
        rear->next=newNode;
        rear=newNode;

    }

}
void deleteFront()
{
    struct node *temp;
    if(rear==NULL&&front==NULL)
        printf("\nDeck is empty.");
    else if(front==rear)
    {
        printf("%d",front->data);
        temp=front;
        front=NULL;
        rear=NULL;
        free(temp);
    }
    else
    {
        printf("%d",front->data);
        temp=front;
        front=front->next;
        free(temp);

    }
}
void deleteRear()
{
    struct node *temp;
    if(rear==NULL&&front==NULL)
        printf("\nDeck is empty.");
    else if(front==rear)
    {
        printf("%d",rear->data);
        temp=front;
        front=NULL;
        rear=NULL;
        free(temp);
    }
    else
    {
        printf("%d",rear->data);
        temp=rear;
        rear=rear->prev;
        free(temp);

    }
}
void getFront()
{
    if(rear==NULL&&front==NULL)
        printf("\nDeck is empty.");
    else
    printf("\n%d",front->data);
}
void getRear()
{
    if(rear==NULL&&front==NULL)
        printf("\nDeck is empty.");
    else
    printf("\n%d",rear->data);
}
void isEmpty()
{
      if(rear==NULL&&front==NULL)
        printf("\nYes");
      else
        printf("No");
}
int isFull()
{
  struct node *t;
  int i=1;
  t=front;
  while(t!=rear)
  {
      i=i+1;
      t=t->next;

  }
  if(i==52)
    return(1);
  else
    return(0);

}
