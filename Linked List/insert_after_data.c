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

void insert_after(int p, int c)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // creating new node
    struct node *temp = head;
    newNode->data = p; // storing data into node
    newNode->next = NULL;

    while (temp->data != c)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display()
{
    struct node *temp1 = head; // intialising temporary node temp

    while (temp1 != NULL)
    {
        printf(" %d ", temp1->data); // printing data
        temp1 = temp1->next;         // traversing linked list
    }
    printf("\n");
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

    while(1)
    {
        int a,o;
        printf("Enter the number and -1 for exit :- ");
        scanf("%d", &a);
        if(a==-1)
        {
            printf("\n\n   ***** EXIT ***** \n");
            break;
        }

        printf("Enter the number after which u want to insert :- ");
        scanf("%d", &o);
        insert_after(a, o);

        printf("\nLinked List :-");
        display(); // displaying the data of linked list
    }

    

    return 0;
}