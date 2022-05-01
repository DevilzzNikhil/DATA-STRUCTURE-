#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int insert(int p)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // creating new node
    struct node *temp = head;
    newNode->data = p; // storing data into node
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return 0;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return 0;
}

int delete_list()
{
    struct node *current = head;
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List Empty");
    }
    else{
      while(1)
      {
        if(temp==NULL)
        {
          break;
        }
        temp = temp->next ;
        free(current);
        current = NULL ;
      }
    }
  return 0 ;
}

int reverse_list()
{
  struct node *current = head ;
  struct node *prev = NULL ;
  struct node *next = NULL ;
  
  while(current!=NULL)
  {
    next = current->next ;
    current->next = prev ; 
    prev= current ;
    current = next ;
  }
  head = prev ;
  return 0 ;
}

void display()
{
    struct node *temp1 = head; 
    if (temp1 == NULL)
    { printf("No Data To display \n"); }
    else
    {
        while (temp1 != NULL)
        {
            printf(" %d ", temp1->data); // printing data
            temp1 = temp1->next;         // traversing linked list
        }
        printf("\n");
    }
}

int main()
{

    printf("\n\n   ***** ENTER ***** \n");
    int n;
    printf("\nEnter the size of Singly Linked List :- "); // taking size of linked list from user
    scanf("%d", &n);

    while (n--)
    {
        int k;
        printf("Enter the number :- "); // taking data from user
        scanf("%d", &k);
        insert(k); // inserting data into linked list
    }
    printf("\nLinked List :-");
    display(); // displaying the data of linked list

    reverse_list() ;

        printf("\nLinked List :-");
        display(); // displaying the data of linked list

    return 0;
}