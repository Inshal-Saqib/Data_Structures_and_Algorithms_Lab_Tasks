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
return(list->last+1);
}

int is_list_empty(LIST_TYPE *list) {
if (list->last == -1)
return(TRUE);
else
return(FALSE);

}
LIST_TYPE *insert(ELEMENT_TYPE e, WINDOW_TYPE w,

LIST_TYPE *list) {

int i;
if (list->last >= MAX_LIST_SIZE-1) {
    cout << "Cant insert - list is full";
}
else if ((w > list->last + 1) || (w < 0)) {
    cout << "Position does not exist";
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
    cout << "Position does not exist";
}
else {
/* delete it ... shift all after w to the left */
list->last = list->last - 1;
for (i=w; i <= list->last; i++) {
list->a[i] = list->a[i+1];
}
return(list);

}}

ELEMENT_TYPE retrieve(WINDOW_TYPE w, LIST_TYPE *list) {
if ( (w < 0) || (w > list->last)) 
{
    cout << "Position does not exist";
}
else 
{
return(list->a[w]);
}
}