#include<stdio.h>
#include<stdlib.h>

struct node {
  int data ;
  struct node *next ;
};

struct node *head = NULL ;

void insert(int p)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));  //creating new node 
    newNode->data = p;   //storing data into node 
    newNode->next = head;  //linking new node to 1st node 
    head = newNode; // linking head to new node 
}

void display()
{
  struct node *temp = head ;  //intialising temporary node temp
  
  while(temp != NULL)
  {
    printf("%d", temp->data ) ;    // printing data
    temp  = temp->next ;    //traversing linked list 
  }
}


int main()
{
  int n ;
  printf("Enter the size of Singly Linked List :- \n");   //taking size of linked list from user 
  scanf("%d", &n) ;
  
  while(n--)
  {
    int k ;
    printf("Enter the number :- \n");  // taking data from user 
    scanf("%d", &k);
    insert(k) ;   // inserting data into linked list
  }
  
  display() ;  //displaying the data of linked list 
  return ;
  
}