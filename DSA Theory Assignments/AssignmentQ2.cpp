#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef struct {
    int number;
    char *string;
} ELEMENT_TYPE;

typedef struct node *NODE_TYPE;

typedef struct node {
    ELEMENT_TYPE element;
    NODE_TYPE next;
} NODE;

typedef NODE_TYPE LIST_TYPE;
typedef NODE_TYPE WINDOW_TYPE;

// Return the last node
WINDOW_TYPE end(LIST_TYPE *list) {
    if (*list == NULL) {
        cout << "Non-existent list\n";
        return NULL;
    }
    WINDOW_TYPE q = *list;
    while (q->next != NULL) q = q->next;
    return q;
}

// Check if list is empty
int is_list_empty(LIST_TYPE *list) {
    return (*list == NULL) ? TRUE : FALSE;
}

// Return first node
WINDOW_TYPE first(LIST_TYPE *list) {
    if (*list == NULL) return NULL;
    return *list;
}

// Return next node
WINDOW_TYPE next(WINDOW_TYPE w) {
    if (w == NULL) {
        cout << "No next node\n";
        return NULL;
    }
    return w->next;
}

// Return previous node
WINDOW_TYPE previous(WINDOW_TYPE w, LIST_TYPE *list) {
    if (*list == NULL || w == *list) {
        cout << "No previous node\n";
        return NULL;
    }
    WINDOW_TYPE p = *list;
    while (p != NULL && p->next != w) p = p->next;
    if (p == NULL) { cout << "Previous not found\n"; return NULL; }
    return p;
}

// Insert after node w
LIST_TYPE *insert(ELEMENT_TYPE e, WINDOW_TYPE w, LIST_TYPE *list) {
    if (*list == NULL && w == NULL) { // insert at start
        *list = new NODE;
        (*list)->element = e;
        (*list)->next = NULL;
        return list;
    }
    if (w == NULL) {
        cout << "Cannot insert after a null node\n";
        return list;
    }
    NODE_TYPE temp = new NODE;
    temp->element = e;
    temp->next = w->next;
    w->next = temp;
    return list;
}

// Delete node after w
LIST_TYPE *delete_element(WINDOW_TYPE w, LIST_TYPE *list) {
    if (*list == NULL || w == NULL || w->next == NULL) {
        cout << "Cannot delete\n";
        return list;
    }
    NODE_TYPE temp = w->next;
    w->next = w->next->next;
    delete temp;
    return list;
}

// Retrieve element after w
ELEMENT_TYPE retrieve(WINDOW_TYPE w) {
    ELEMENT_TYPE temp = {-1, NULL};
    if (w == NULL) {
        cout << "Cannot retrieve\n";
        return temp;
    }
    return w->element;
}

// DRIVER FUNCTION
int main() {
    LIST_TYPE list = NULL;

    // Insert first node
    ELEMENT_TYPE e1 = {10, (char*)"Apple"};
    insert(e1, NULL, &list);  // at start

    // Insert after first node
    ELEMENT_TYPE e2 = {20, (char*)"Banana"};
    insert(e2, list, &list);

    ELEMENT_TYPE e3 = {30, (char*)"Cherry"};
    insert(e3, end(&list), &list);

    // Print list
    cout << "List elements:\n";
    WINDOW_TYPE w = first(&list);
    while (w != NULL) {
        cout << w->element.number << " " << w->element.string << endl;
        w = next(w);
    }

    // Retrieve first element
    ELEMENT_TYPE r = retrieve(list);
    cout << "\nRetrieved first element: " << r.number << " " << r.string << endl;

    // Delete second element (after first)
    delete_element(list, &list);

    // Print after deletion
    cout << "\nList after deletion:\n";
    w = first(&list);
    while (w != NULL) {
        cout << w->element.number << " " << w->element.string << endl;
        w = next(w);
    }

    return 0;
}