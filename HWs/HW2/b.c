// In The Name Of God

#include <stdio.h>

int n;
int sz = 0;
const int mxsz = 50000;

struct Node
{
    int data;
    struct Node* xnode;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* XOR(struct Node *x, struct Node *y)
{
    return (struct Node*)((__intptr_t)(x) ^ (__intptr_t)(y));
}

void push_tail(int data)
{
    if(sz >= mxsz)
    {
        printf("No more space :(\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->xnode = tail;
    if(sz)
    {
        tail->xnode = XOR(newNode, tail->xnode);
        tail = newNode;
    }
    else
    {
        head = newNode;
        tail = newNode;
    }
    sz++;
}

void to_head(int data)
{
    if(sz >= mxsz)
    {
        printf("No more space :(\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->xnode = head;
    if(sz)
    {
        head->xnode = XOR(newNode, head->xnode);
        head = newNode;
    }
    else
    {
        head = newNode;
        tail = newNode;
    }
    sz++;
}

void get_head()
{
    struct Node** headptr = &head;
    if(!sz)
    {
        printf("No job :)\n");
        return;
    }
    else if(sz == 1)
    {
        printf("%d\n", head->data);
        free(*headptr);
        head = NULL;
        tail = NULL;
    }
    else
    {
        printf("%d\n", head->data);
        struct Node* newHead = head->xnode;
        newHead->xnode = XOR(newHead->xnode, head);
        free(*headptr);
        head = newHead;
    }
    sz--;
}

void get_tail()
{
    struct Node** tailptr = &tail;
    if(!sz)
    {
        printf("No job :)\n");
        return;
    }
    else if(sz == 1)
    {
        printf("%d\n", tail->data);
        free(*tailptr);
        head = NULL;
        tail = NULL;
    }
    else
    {
        printf("%d\n", tail->data);
        struct Node* newTail = tail->xnode;
        newTail->xnode = XOR(newTail->xnode, tail);
        free(*tailptr);
        tail = newTail;
    }
    sz--;
}

void lreverse()
{
    if(sz > 1)
    {
        struct Node* newHead = tail;
        tail = head;
        head = newHead;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        char s[20];
        int x;
        scanf("%s", s);
        if(!strcmp(s, "to_front"))
        {
            scanf("%d", &x);
            to_head(x);
        }
        if(!strcmp(s, "push_back"))
        {
            scanf("%d", &x);
            push_tail(x);
        }
        if(!strcmp(s, "front"))
        {
            get_head();
        }
        if(!strcmp(s, "back"))
        {
            get_tail();
        }
        if(!strcmp(s, "reverse"))
        {
            lreverse();
        }
    }
}








