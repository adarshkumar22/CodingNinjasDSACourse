#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int a[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = a[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void RDisplay(struct Node *p)
{
    printf("%d ", p->data);
    RDisplay(p->next);
}

int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
int Max(struct Node *p)
{
    int max = INT_MIN;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int RMax(struct Node *p)
{
    int x = 0;

    if (p == 0)
        return INT_MIN;
    x = RMax(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}
struct Node *RSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}
struct Node *LSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != 0)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }

        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node *RLSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    return RLSearch(p->next, key);
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node *));
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
void insertLast(int x)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node *));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
        last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
void sortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;
    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
int isSorted(struct Node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}
void removeDuplicates(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}
void reverse1(struct Node *p)
{
    int *a;
    a = (int *)malloc(sizeof(int) * count(p));
    struct Node *q = p;
    int i = 0;
    while (q != NULL)
    {
        a[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = a[i];
        q = q->next;
        i--;
    }
}
void reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}
void concat(struct Node *p, struct Node *q){
    third = p;
    while(p->next != NULL){
        p = p->next;
    }
    p -> next = q;
}
void merge(struct Node *p, struct Node *q) {
    struct Node *last;
    if(p -> data < q -> data) {
        third = last = p;
        p = p -> next;
        third -> next = NULL;
    }
    else {
        third = last = q;
        q = q -> next;
        third -> next = NULL;
    }
    while( p && q) {
        if(p -> data < q -> data) {
            last->next = p;
            last = p;
            p= p -> next;
            last -> next = NULL;
        }
        else {
            last -> next = q;
            last = q;
            q = q -> next;
            last -> next = NULL;
        }
    }
    if(p) last -> next = p;
    if(q) last -> next = q;
}

int isLoop(struct Node *f){
    struct Node *p, *q;
    p=q=f;
    do {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    }while(p && q && p != q);
    return p==q ? 1 : 0;
}
int main()
{
    struct Node *t1, *t2;
    int a[] = {2, 4, 6, 8, 10};
    int b[] ={};
    create(b,0);

    create(a, 5);
    merge(first, second);
    Display(third);
    
    return 0;
}







