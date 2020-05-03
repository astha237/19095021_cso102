#include <stdio.h>
int size = 0;
void swap(int *a, int *b)
{
  int t = *b;
  *b = *a;
  *a = t;
}

void heapify(int array[], int size, int i)
{
    int largest, lchild, rchild;
    largest = i;
    lchild = 2 * i + 1;
    rchild = 2 * i + 2;
    if (lchild < size && array[lchild] > array[largest])
    {
      largest = lchild;
    }
    if (rchild < size && array[rchild] > array[largest])
     {

      largest = rchild;
     }

    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }

void Insert(int array[], int data)
{
  int i;
  if (size == 0)
  {
    array[0] = data;
    size += 1;
  }
  else
  {
    array[size] = data;
    size += 1;
    for (i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}


void deleteRoot(int array[])
{
  int i=0;

  swap(&array[0], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
int maximum(int A[])
{
    int max=A[0];
    return max;
}

int main()
{
    int N,i,data,x,y,z;
    int A[100000];
    printf("Enter the number of elements to be inserted:\n");
    scanf("%d",&N);
    int max[N];
    printf("Enter the numbers\n");
     for(i=0;i<N;i++)
     {
        scanf("%d",&data);
        Insert(A,data);
        if(i<2)
            max[i]=-1;
        else

        {
            x=maximum(A);
            deleteRoot(A);
             y=maximum(A);
            deleteRoot(A);
             z=maximum(A);
             deleteRoot(A);
             Insert(A,x);
             Insert(A,y);
             Insert(A,z);
             max[i]=x*y*z;
        }



    }
    for(i=0;i<N;i++)
    {
        printf("%d\n",max[i]);
    }


return 0;
}
