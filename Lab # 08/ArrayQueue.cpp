#include <iostream>
using namespace std;

#define MAX_SIZE 100

struct Queue
{
    int arr[MAX_SIZE];
    int front;
    int rear;        
};

bool isEmpty(Queue *q)
{
    return (q->front > q->rear);

    //if (q->rear == -1) // q-> front > q-> rear
}

bool isFull(Queue *q)
{
    return (q->rear == MAX_SIZE - 1);
}

void createQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, int value)
{
    if(q->rear == MAX_SIZE - 1)
    {
        cout << "Queue is full!" << endl;
        return;
    }
    q->arr[q->rear] = value;
    q->rear++;
    cout << "Enqueued: " << value << endl;
}

void dequeue(Queue *q)
{
   if (q->rear == -1) // q-> front > q-> rear
   {    
    cout << "Queue is empty!" << endl;
    return;
   } 
   q->front++;
   cout << "Dequeued: " << q->arr[q->front - 1] << endl;
}

int frontofqueue(Queue *q)
{
    if (q->rear == -1) // q-> front > q-> rear
    {
        cout << "Queue is empty!" << endl;
        return -1; // Return -1 to indicate the queue is empty
    }
    return q->arr[q->front];
    cout << "Front of Queue: " << q->arr[q->front] << endl;
}

int rearofqueue(Queue *q)
{
    if (q->rear == -1) // q-> front > q-> rear
    {
        cout << "Queue is empty!" << endl;
        return -1; // Return -1 to indicate the queue is empty
    }
    return q->arr[q->rear - 1];
    cout << "Rear of Queue: " << q->arr[q->rear - 1] << endl;
}

int size(Queue *q)
{
    return ((q->rear - q->front) + 1);
}

int main()
{
    Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    cout << "Front of Queue: " << frontofqueue(&q) << endl;
    cout << "Rear of Queue: " << rearofqueue(&q) << endl;
    cout << "Size of Queue: " << size(&q) << endl;

    dequeue(&q);
    cout << "Front of Queue after dequeue: " << frontofqueue(&q) << endl;
    cout << "Size of Queue after dequeue: " << size(&q) << endl;
    

    return 0;
}





    