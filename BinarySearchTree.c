#include <stdio.h>
# include <stdlib.h>

struct node
{
	char data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
void Find(char,struct node**,struct node**);
void Declare(char);
void case_a(struct node *,struct node * );
void case_b(struct node *,struct node * );
void case_c(struct node *,struct node* );
int Delete(char );

void Display(struct node*);
void preOrder(struct node*);
void postOrder(struct node*);
void inOrder(struct node*);
int main()
{
	int choice,N,i;
	char ch;
	 printf("1.Insert a variable.\n2.Delete a variable.\n3.Display the variables.\n");
		printf("Enter the number of operations you wish to perform.");
		scanf("%d",&N);
		for(i=0;i<N;i++)
        {


		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter the variable to be inserted : ");

			ch=getch();
			Declare(ch);
			break;
		 case 2:
			printf("Enter the variable to be deleted : ");
			ch=getch();
			Delete(ch);
			break;
		 case 3:
			Display(root);
			break;
		 default:
			printf("Invalid\n");
		}

		 printf("\n");
	}
}




void Find(char item,struct node **p,struct node **l)
{
	struct node *ptr,*t;

	if(root==NULL)
	{
		*l=NULL;
		*p=NULL;
		return;
	}
	if(item==root->data)
	{
		*l=root;
		*p=NULL;
		return;
	}

	if(item<root->data)
		ptr=root->left;
	else
		ptr=root->right;
	t=root;

	while(ptr!=NULL)
	{
		if(item==ptr->data)
		{       *l=ptr;
			*p=t;
			return;
		}
		t=ptr;
		if(item<ptr->data)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	 }
	 *l=NULL;
	 *p=t;
}

void Declare(char item)
{       struct node *newNode,*par,*loc;
	Find(item,&par,&loc);
	if(loc!=NULL)
	{
		printf("This variable is already declared in the program.");
		return;
	}

	newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=item;
	newNode->left=NULL;
	newNode->right=NULL;

	if(par==NULL)
		root=newNode;
	else
		if(item<par->data)
			par->left=newNode;
		else
			par->right=newNode;

}
void case_a(struct node *par,struct node *loc )
{
	if(par==NULL)
		root=NULL;
	else
		if(loc==par->left)
			par->left=NULL;
		else
			par->right=NULL;
}

void case_b(struct node *par,struct node *loc)
{
	struct node *child;


	if(loc->left!=NULL)
		child=loc->left;
	else
		child=loc->right;

	if(par==NULL )
		root=child;
	else
		if( loc==par->left)
			par->left=child;
		else
			par->right=child;
}

void case_c(struct node *par,struct node *loc)
{
	struct node *ptr,*ptrsave,*suc,*parsuc;


	ptrsave=loc;
	ptr=loc->right;
	while(ptr->left!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->left;
	}
	suc=ptr;
	parsuc=ptrsave;

	if(suc->left==NULL && suc->right==NULL)
		case_b(parsuc,suc);
	else
		case_b(parsuc,suc);

	if(par==NULL)
		root=suc;
	else
		if(loc==par->left)
			par->left=suc;
		else
			par->right=suc;

	suc->left=loc->left;
	suc->right=loc->right;
}
int Delete(char item)
{
	struct node *parent,*location;
	if(root==NULL)
	{
		printf("No element is present in tree.");
		return 0;
	}

	Find(item,&parent,&location);
	if(location==NULL)
	{
		printf("There is no such variable.");
		return 0;
	}

	if(location->left==NULL && location->right==NULL)
		case_a(parent,location);
	if(location->left!=NULL && location->right==NULL)
		case_b(parent,location);
	if(location->left==NULL && location->right!=NULL)
		case_b(parent,location);
	if(location->left!=NULL && location->right!=NULL)
		case_c(parent,location);
	free(location);
}


void Display(struct node *root)
{
    if(root==NULL)
    {
        printf("Tree is empty!");
    }
    else
    {
       printf("Preorder:");
       preOrder(root);
       printf("\nPostorder:");
       postOrder(root);
       printf("\nInorder:");
       inOrder(root);
    }
}
void preOrder(struct node *root)
{
    if(root)
    {
        printf("%c",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }

}
void postOrder(struct node *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%c",root->data);
    }

}
void inOrder(struct node *root)
{
    if(root)
    {
        inOrder(root->left);
        printf("%c",root->data);
        inOrder(root->right);

    }

}

