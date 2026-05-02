#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNode(int value)
{
    Node* newnode = new Node;
    newnode->data = value;
    newnode->next = nullptr;
    return newnode;
}

Node* getNode(Node* head, int index)
{
    while (head != nullptr && index > 0)
    {
        head = head->next;
        index--;
    }
    return head;    
}

void inserted(Node** head, int value, int position)
{
    //logic is different for position = 0 and position > 0
    if (position == 0)
    {
        Node* newnode = createNode(value);
        newnode->next = *head;
        *head = newnode;
    }
    else
    {
        Node* newnode = createNode(value);
        Node* prev = getNode(*head, position - 1);
        newnode->next = prev->next;
        prev->next = newnode;
    }
    cout << "Inserted " << value << " at position " << position << endl;
}

void delete_At(Node** head, int position)
{
    if(*head == nullptr)
    {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }
    if (position == 0)
    {
        Node* temp = *head;
        *head = (*head)->next;      //Note: we are not deleting the node, just changing the head pointer to point to the next node. The old head node is still in memory, but we have lost the reference to it. We will delete it after changing the head pointer.
        //Now we can safely delete the old head node, as we have already updated the head pointer to point to the next node.
        //Node = temp -> next; //This line is not needed, as we have already updated the head pointer to point to the next node. We can directly delete the temp node without worrying about losing the reference to the next node.
        delete temp;
    }
    else
    {
        Node * prev = getNode(*head, position - 1);
        Node* temp = prev->next;
        prev->next = temp->next; //Note: we are not deleting the node, just changing the next pointer of the previous node to point to the next node of the node we want to delete. The node we want to delete is still in memory, but we have lost the reference to it. We will delete it after changing the next pointer of the previous node.
        //Now we can safely delete the node we want to delete, as we have already updated
        delete temp; 
    }
    cout << "Deleted node at position " << position << endl;
}

int search(Node* head , int key)
{
    int index = 0;
    while (head != nullptr)
    {
        if (head->data == key)
        {
            cout << "Key :" << key << " Found in the list at position : " << index << endl;
            return 1; // Found
        }
        index ++;
        head = head->next;
    }
    cout << key << " Not found in the list." << endl;
    return 0; // Not found
}

int size(Node* head)
{
    int count = 0;
    while (head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}

void empty(Node** head)
{
    while (*head != nullptr)
    {
        Node* temp = *head;
        *head = (*head)->next; //Note: we are not deleting the node, just changing the head pointer to point to the next node. The old head node is still in memory, but we have lost the reference to it. We will delete it after changing the head pointer.
        //Now we can safely delete the old head node, as we have already updated the head pointer to point to the next node.
        delete temp;
    }
    cout << "List is now empty." << endl;
}

void print(Node* head)
{    
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    //Can be implemented in two ways, one is using while loop with a counter while the head is not null prt and the other is using the size function in side of a for loop until the for control counter is less than size(head) - 1.
   
    //Using a while loop that iterates until the head pointer becomes NULL.
    //Using a for loop that runs up to size(head) - 1, where size() returns the number of nodes in the linked list.

    for (int i = 0; i < size(head) - 1 ; i++)
    {
        cout << "Data at Node # " << i << " is : " << head->data << endl;
        head = head->next;
    }
    
    // int nodecount = 0;
    // while (head != nullptr)
    // {
    //     cout << "Data at Node # " << nodecount << " is : " << head->data << endl;
    //     head = head->next;
    //     nodecount++;
    // }
    // cout << "NULL" << endl;
}

int main()
{
    Node* head = nullptr; // Initialize the head of the list to nullptr
    inserted(&head, 10, 0); // Insert 10 at position 0
    inserted(&head, 20, 1); // Insert 20 at position 1
    inserted(&head, 30, 2); // Insert 30 at position 2
    inserted(&head, 15, 1); // Insert 15 at position 1  
    print(head); // Print the list
    delete_At(&head, 1); // Delete node at position 1
    print(head); // Print the list after deletion
    search(head, 20); // Search for 20 in the list
    search(head, 40); // Search for 40 in the list
    cout << "Size of the list: " << size(head) << endl; // Print the size of the list
    empty(&head); // Empty the list
    print(head); // Print the list after emptying
    cout << "Size of the list after emptying: " << size(head) << endl; // Print the size of the list after emptying
    cout << "Printing the list after emptying: " << endl;
    print(head); // Print the list with positions

    

    return 0;    
}