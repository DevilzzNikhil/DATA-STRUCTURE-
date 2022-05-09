

//including libraries
#include<stdio.h>
#include<stdlib.h>

void insert_at_start( int *a, int n, int num)
{
    for (int i = n; i > 0; i--)
    {
        *(a + i) = *(a + i - 1);
    }
    *(a) = num;
}

void insert_at_end( int *a, int n, int num)
{
    *(a+n) = num;
}

void insert_at_index( int *a, int n,int index, int num)
{
    for (int i = n; i > index-1; i--)
    {
        *(a + i) = *(a + i - 1);
    }
    *(a + index - 1) = num;
}

void insert_after_element( int *a, int n,int element, int num)
{

    int k ;
    for (int i = 0; i < n; i++)
    {
        if(*(a+i) == element)
        {
            k = i ;
            break ;
        }
        else if(i == n-1)
        {
            printf("\n\nNo element exists\n\n");
            return ;
        }
        
    }
    insert_at_index(a,n,k+2,num) ;
}

void delete_element( int *a, int n,int element)
{

    int k ;
    for (int i = 0; i < n; i++)
    {
        if(*(a+i) == element)
        {
            k = i ;
            break ;
        }
        else if(i == n-1)
        {
            printf("\n\nNo element exists\n\n");
            return ;
        }
        
    }
    for (int i = k; i < n; i++)
    {
        *(a + i) = *(a + i + 1);
    }
}





void display(int a[], int n)
{
    printf("\nDisplaying Element of Array :- \n");
    for(int i =0; i<n ;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    //Create an Array of N integers Defined by user at runtime 
    int N ; 
    printf("Enter the size of Array :- ");
    scanf("%d", &N);

    int A[N+10] ;


    for(int i =0 ;i<N; i++)
    {
        printf("Enter the %d element :- ", i+1);
        scanf("%d", &A[i]);
    }

    display(A,N);

    //Inserting element at start

    printf("\n\nInserting element at begining \n\n");
    int x ;

    printf("Enter the element :- ");
    scanf("%d", &x);
    insert_at_start(A,N,x) ;
    ++N;
    display(A,N);

    //Inserting element at end


    printf("\n\nInserting element at end \n\n");

    printf("Enter the element :- ");
    scanf("%d", &x);
    insert_at_end(A,N,x) ;
    ++N;
    display(A,N);

    //Inserting element at given index

    printf("\n\nInserting element at given index \n\n");

    int index ;
    printf("Enter the element and index :- ");
    scanf("%d %d", &x, &index);
    insert_at_index(A,N,index,x) ;
    ++N;
    display(A,N);

    //Inserting element after given element 

    printf("\n\nInserting element after given element \n\n");

    int element ;
    printf("Enter the element and  number to added :- ");
    scanf("%d %d", &element, &x);
    insert_after_element(A,N,element,x) ;
    ++N;
    display(A,N);

    // Deleting element

    printf("\n\nDeleting element \n\n");

    printf("Enter the element you want to delete :- ");
    scanf("%d", &element);
    delete_element(A,N,element) ;
    --N;
    display(A,N);

    return 0 ;
}
