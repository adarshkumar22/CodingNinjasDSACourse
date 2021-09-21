#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * head;

void Create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node *));
    head->data = a[0];
    head->next = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node *));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;

    } while (p != head);
    return len;
}
void Display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}
void RDisplay(struct Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        printf("%d ", p->data);
        RDisplay(p->next);
    }
    flag = 0;
}
void insert(int pos, int key)
{
    struct Node *t;
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node *));
    t = (struct Node *)malloc(sizeof(struct Node *));
    p = head;
    t->data = key;
    if (pos == 0)
    {
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            t->next = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;
    if (index < 0 || index > Length(head))
        return -1;
    if (index == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}
int main()
{
    int A[] = {2, 3, 4, 5, 6};
    Create(A, 5);
    int b = Delete(head, 1);
    RDisplay(head);
    return 0;
}