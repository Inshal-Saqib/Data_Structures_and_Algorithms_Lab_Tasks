#include <iostream>
using namespace std;

#define MAX_LIST_SIZE 100
#define FALSE 0
#define TRUE 1

typedef struct {
    int number;
    char *string;
} ELEMENT_TYPE;

typedef struct {
    int last;
    ELEMENT_TYPE a[MAX_LIST_SIZE];
} LIST_TYPE;

typedef int WINDOW_TYPE;


WINDOW_TYPE end(LIST_TYPE *list) {
    return(list->last + 1);
}

int is_list_empty(LIST_TYPE *list) {
    if (list->last == -1)
        return(TRUE);
    else
        return(FALSE);
}

WINDOW_TYPE last(LIST_TYPE *list) {
    return(list->last);
}

WINDOW_TYPE first(LIST_TYPE *list) {
    if (is_list_empty(list) == FALSE)
        return(0);
    else
        return(end(list));
}

WINDOW_TYPE next(WINDOW_TYPE w, LIST_TYPE *list) {

    if (w == last(list))
        return(end(list));

    else if (w == end(list)) {
        cout << "can't find next after end of list\n";
        return(w);
    }

    else
        return(w+1);
}

WINDOW_TYPE previous(WINDOW_TYPE w, LIST_TYPE *list) {

    if (w > first(list))
        return(w-1);

    else {
        cout << "can't find previous before first element of list\n";
        return(w);
    }
}


LIST_TYPE *insert(ELEMENT_TYPE e, WINDOW_TYPE w, LIST_TYPE *list) {

    int i;

    if (list->last >= MAX_LIST_SIZE-1) {
        cout << "Cant insert - list is full\n";
        return list;
    }

    else if ((w > list->last + 1) || (w < 0)) {
        cout << "Position does not exist\n";
        return list;
    }

    else {
        for (i=list->last; i>= w; i--) {
            list->a[i+1] = list->a[i];
        }

        list->a[w] = e;
        list->last = list->last + 1;

        return(list);
    }
}


LIST_TYPE *delete_element(WINDOW_TYPE w, LIST_TYPE *list) {

    int i;

    if ((w > list->last) || (w < 0)) {
        cout << "Position does not exist\n";
        return list;
    }

    else {
        list->last = list->last - 1;

        for (i=w; i <= list->last; i++) {
            list->a[i] = list->a[i+1];
        }

        return(list);
    }
}


ELEMENT_TYPE retrieve(WINDOW_TYPE w, LIST_TYPE *list) {

    ELEMENT_TYPE temp;

    if ((w < 0) || (w > list->last)) {
        cout << "Position does not exist\n";
        temp.number = -1;
        temp.string = NULL;
        return temp;
    }

    else {
        return(list->a[w]);
    }
}


/* DRIVER FUNCTION */

int main() {

    LIST_TYPE list;
    list.last = -1;   // initialize empty list

    cout << "Checking if list is empty: ";
    if(is_list_empty(&list))
        cout << "List is empty\n";
    else
        cout << "List is not empty\n";

    ELEMENT_TYPE e1 = {10, (char*)"Apple"};
    ELEMENT_TYPE e2 = {20, (char*)"Banana"};
    ELEMENT_TYPE e3 = {30, (char*)"Cherry"};

    /* Insert elements */
    insert(e1, end(&list), &list);
    insert(e2, end(&list), &list);
    insert(e3, end(&list), &list);

    cout << "\nElements after insertion:\n";
    for(int i=0; i<=last(&list); i++) {
        cout << list.a[i].number << " " << list.a[i].string << endl;
    }

    /* First element */
    WINDOW_TYPE f = first(&list);
    cout << "\nFirst position: " << f << endl;

    /* Last element */
    WINDOW_TYPE l = last(&list);
    cout << "Last position: " << l << endl;

    /* Next element */
    WINDOW_TYPE n = next(f, &list);
    cout << "Next position after first: " << n << endl;

    /* Previous element */
    WINDOW_TYPE p = previous(n, &list);
    cout << "Previous position before " << n << ": " << p << endl;

    /* Retrieve element */
    ELEMENT_TYPE r = retrieve(1, &list);
    cout << "\nRetrieved element at position 1: ";
    cout << r.number << " " << r.string << endl;

    /* Delete element */
    delete_element(1, &list);

    cout << "\nElements after deletion:\n";
    for(int i=0; i<=last(&list); i++) {
        cout << list.a[i].number << " " << list.a[i].string << endl;
    }

    return 0;
}