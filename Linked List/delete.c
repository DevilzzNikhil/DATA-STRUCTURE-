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
}

int delete (int p)
{
    struct node *current = head;
    struct node *prev = head;
    if (head == NULL)
    {
        printf("List Empty");
    }
    else if (current->data == p)
    {
        head = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while (current->data != p)
        {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current);
        current = NULL;
    }
}

void display()
{
    struct node *temp1 = head; // intialising temporary node temp
    if (temp1 == NULL)
    {
        printf("No Data To display \n");
    }
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

    while (1)
    {
        int a;
        printf("Enter the number u need to delete and -1 for exit :- ");
        scanf("%d", &a);
        if (a == -1)
        {
            printf("\n\n   ***** EXIT ***** \n");
            break;
        }
        delete (a);

        printf("\nLinked List :-");
        display(); // displaying the data of linked list
    }

    return 0;
}