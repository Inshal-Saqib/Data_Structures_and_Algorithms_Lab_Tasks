#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct stack{
    Node *top;
    int count;
};

void createStack(stack *s)
{
    s->top = nullptr;
    s->count = 0;
    cout << "Stack Created" << endl;
}

void push(stack *s, int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
    cout << "Element " << value << " pushed to stack" << endl;
}

void pop(stack *s)
{
    if (s->count == 0 || s -> top == nullptr)
    {
        cout << "The List is empty.Pop Operation not possible" << endl;
        return;
    }

    Node *temp = s->top;
    s->top = s->top->next;
    delete temp; //we dont need to write temp = Nullptr as the function is called in stack so when the functions exists, the pointers are also automatically destroyed.
    s->count--;
    cout << "Element popped from stack" << endl;
}

int top (stack *s)
{
    if (s->count == 0 || s->top == nullptr)
    {
        cout << "Stack is empty" << endl;
        return -1; // Return -1 to indicate stack is empty
    }
    return s->top->data; // Return the data of the top element
}

void empty(stack *s)
{
    while (s->top != nullptr)
    {
        pop(s); //Or write the whole pop logic again - DRY coding
    }

    cout << "Stack Emptied" << endl;
}

int size(stack *s)
{
    return s->count;
}

int main()
{
    stack s;
    createStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    cout << "Top element: " << top(&s) << endl;
    cout << "Stack size: " << size(&s) << endl;
    pop(&s);
    cout << "Top element after pop: " << top(&s) << endl;
    empty(&s);
    cout << "Stack size after emptying: " << size(&s) << endl;

    return 0;
}