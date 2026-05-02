#include <iostream>
using namespace std;

#define MAX 100

struct Stack
{
    int arr[MAX];
    int top;    
};

void createStack(Stack *s)
{
    s->top = -1;
    cout << "Stack Created" << endl;
}

void push(Stack * s, int value)
{

    if (s->top == MAX - 1)
    {
        cout << "Stack overflow" << endl;
        return;
    }
    s->top++;
    s->arr[s->top] = value; //Short Form = s->arr[++s->top] = value;
    cout << "Element " << value << " pushed to stack" << endl;
}

void pop(Stack * s)
{
    if (s->top == -1)
    {
        cout << "Stack underflow" << endl;
        return;
    }
    s->top--;
    cout << "Element popped from stack" << endl;
}

int top(Stack * s)
{
    if (s->top == -1)
    {
        cout << "Stack is empty" << endl;
        return -1; // Return -1 to indicate stack is empty
    }
    return s->arr[s->top];
}

void empty(Stack * s)
{
    s->top = -1;
    cout << "Stack is now empty" << endl;
}

int size(Stack * s)
{
    return s->top + 1;
}

int main()
{
    Stack s;
    createStack(&s);
    push(&s, 10);
    push(&s, 20);
    cout << "Top element: " << top(&s) << endl; // Output: 20
    cout << "Stack size: " << size(&s) << endl; // Output: 2
    pop(&s);
    cout << "Top element after pop: " << top(&s) << endl; // Output: 10
    cout << "Stack size after pop: " << size(&s) << endl; // Output: 1
    empty(&s);
    cout << "Stack size after empty: " << size(&s) << endl; // Output: 0
    
    return 0;
}