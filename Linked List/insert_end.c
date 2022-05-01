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
    struct node* temp = head ;
    newNode->data = p;   //storing data into node 
    newNode->next = NULL ;
  
    if(head == NULL)
    {
      head = newNode ;
      return ;
    }
  
  while(temp->next !=NULL)
  {
    temp = temp->next ;
  }
  temp->next = newNode ;
}

void display()
{
  struct node *temp1 = head ;  //intialising temporary node temp
  
  while(temp1 != NULL)
  {
    printf("%d", temp1->data ) ;    // printing data
    temp1  = temp1->next ;    //traversing linked list 
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