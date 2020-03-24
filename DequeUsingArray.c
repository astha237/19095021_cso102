#include<stdio.h>
#include<conio.h>

int deck[52];
int f=0,r=4; /*assuming there are 5 cards present initially from 1 to 5 in order. */

void insertFront(int);
void insertRear(int);
void deleteFront(void);
void deleteRear(void);
void getRear(void);
void getFront(void);
void isEmpty(void);
void isFull(void);

int main()
{
  int m,i=0,n,x;
  deck[f]=1;
  deck[1]=2;
  deck[2]=3;
  deck[3]=4;
  deck[r]=5;
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
            isFull ();
        } break;
     default:
        printf("\nINVALID!");
     }
     i++;
 }
}
void insertFront(int x)
{
    if(f == r+1)
     {
         printf("\nDeck is full.");
     }
    else if(f==0&&r==51)
     {
        printf("\nDeck is full.");
     }
     else if(r==-1&&f==-1)
     {
        r=0;
        f=0;
        deck[f]=x;
     }
    else if(f==0)
    {
        f=51;
        deck[f]=x;
    }
    else
    {
        f--;
        deck[f]=x;
    }
}
void insertRear (int x)
{
    if(f == r+1)
     {
         printf("\nDeck is full.");
     }
    else if(f==0&&r==51)
     {
        printf("\nDeck is full.");
     }
    else if(r==51)
    {
        r=0;
        deck[r]=x;
    }
    else if(r==-1&&f==-1)
    {
        r=0;
        f=0;
        deck[r]=x;
    }
    else
    {
        r++;
        deck[r]=x;
    }

}
void deleteFront()
{
    if(f==-1&&r==-1)
    {
        printf("\nDeck is empty.");
    }
    else if(f==r)
    {
        printf("%d",deck[f]);
        f=-1;
        r=-1;
    }
    else if(f==51)
    {
        printf("%d",deck[f]);
        f=0;
    }
    else
    {
        printf("%d",deck[f]);
        f++;
    }
}
void deleteRear()
{
    if(f==-1&&r==-1)
    {
        printf("\nDeck is empty.");
    }
    else if(f==r)
    {
        printf("\n%d",deck[f]);
        f=-1;
        r=-1;
    }
    else if(r==0)
    {
        printf("\n%d",deck[r]);
        r=51;
    }
    else
    {
        printf("\n%d",deck[r]);
        r--;
    }
}
void getFront()
{
    printf("\n%d",deck[f]);
}
void getRear()
{
    printf("\n%d",deck[r]);
}
void isEmpty()
{
     if(f==-1&&r==-1)
        printf("\nYes");
     else
        printf("\nNo");
}
void isFull()
{
     if(f == r+1)
     {
         printf("\nYes");
     }
    else if(f==0&&r==51)
     {
        printf("\nYes");
     }
     else
        printf("\nNo");
}
