#include<iostream>

using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;
};


Node *insert_at_end(Node *head, int data)
{
    Node *temp = head ;
    Node *new_node = new Node() ;
    new_node->data = data ;
    new_node->next = NULL ;

    if(head == NULL)
    {
        head = new_node ;
        return head ;
    }

    while(temp->next != NULL)
    {
        temp = temp->next ;
    }
    temp->next = new_node ;
    return head ;
}

Node *insert_at_start(Node *head, int data)
{
    Node *temp = head ;
    Node *new_node = new Node() ;
    new_node->data = data ;
    new_node->next = head ;
    head = new_node ;

    return head ;
}

Node *insert_after_element(Node *head, int element, int data)
{
    Node *temp = head ;
    Node *new_node = new Node() ;
    new_node->data = data ;
    new_node->next = NULL ;

    while(temp->data != element)
    {
        temp = temp->next ;
    }

    new_node->next = temp->next ;
    temp->next = new_node ;

    return head ;
}

Node *delete_element(Node *head, int p)
{
    Node *current = head;
    Node *prev = head;

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

    return head ;
}



void display(Node *head)
{
    cout << endl << "Displaying Element" << endl;

    while(head != NULL)
    {
        cout << head->data << " " ;
        head = head->next ;
    }
    cout << endl << endl;
}

int main()
{
    Node *head = new Node() ;
    head = NULL ;

    int size ;
    cout << "Enter the size of Linked List " ;
    cin >> size ;
    
    int data ;

    while(size--)
    {
        cout << "Enter the data " ;
        cin >> data ;

        head = insert_at_end( head , data ) ;

    }
    display(head) ;

    cout << "Inserting Element at start " << endl ;
    cout << "Enter the data" << endl;
    cin >> data ;

    head = insert_at_start(head, data) ;

    display(head) ;

    int element ;


    cout << "Inserting Element after given element  " << endl ;
    cout << "Enter the element and data" << endl;
    cin >> element >> data ;

    head = insert_after_element(head, element , data) ;

    display(head) ;

    cout << "Deleting Element from list  " << endl ;
    cout << "Enter data" << endl;
    cin >>  data ;

    head = delete_element(head , data) ;

    display(head) ;







}