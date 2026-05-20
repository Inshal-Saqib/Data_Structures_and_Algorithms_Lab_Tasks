#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
    int count;
};

void createQueue(Queue *q)
{
    q->front = nullptr;
    q->rear = nullptr;
    q->count = 0;
    cout << "Queue created!" << endl;
}

void enqueue (Queue * q , int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
    if (q->front == nullptr) // if (int count == 0) -- the count check does not exist in actual implementation of Queues
    {
        q -> front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
    cout << "Enqueued: " << value << endl;
}

void dequeue(Queue *q)
{
    if(q -> front == nullptr)
    {
        cout << "The List is Empty" << endl;
        return;
    }
    Node *temp = q -> front;
    q -> front = q -> front -> next;

    if(q -> front == nullptr)   //To handle the case when there is only one node in the queue and it gets dequeued, we need to set rear to nullptr as well.Indorder to avoid dangling pointer issue when rear is still pointing to the deleted node.
    {
        q -> rear = nullptr;
    }
    delete temp;
    q -> count--;
    cout << "Dequeued: " << temp->data << endl;
}

int frontofqueue(Queue *q)
{
    if(q -> front == nullptr)
    {
        cout << "The List is Empty" << endl;
        return -1; // Return -1 to indicate the queue is empty
    }
    return q -> front -> data;
    cout << "Front of Queue: " << q -> front -> data << endl;
}

int rearofqueue(Queue *q)
{
    if(q -> rear == nullptr)
    {
        cout << "The List is Empty" << endl;
        return -1; // Return -1 to indicate the queue is empty
    }
    return q -> rear -> data;
    cout << "Rear of Queue: " << q -> rear -> data << endl;
}

bool isempty(Queue *q)
{
    return (q->front == nullptr);
}

int size(Queue *q)
{
    return q-> count;
}

int main()
{
    Queue q;    
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    cout << "Front of Queue: " << frontofqueue(&q) << endl;
    cout << "Rear of Queue: " << rearofqueue(&q) << endl;
    cout << "Size of Queue: " << size(&q) << endl;
    dequeue(&q);
    cout << "Front of Queue after dequeue: " << frontofqueue(&q) << endl;
    cout << "Size of Queue after dequeue: " << size(&q) << endl;
    dequeue(&q);
    

    return 0;
}
