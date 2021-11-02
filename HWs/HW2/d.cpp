// In The Name Of God

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,k;
int sz = 0;

struct Node
{
    int data;
    struct Node* xnode;
};

struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* r = NULL;
struct Node* pr = NULL;

struct Node* XOR(struct Node *x, struct Node *y)
{
    return (struct Node*)((uintptr_t)(x) ^ (uintptr_t)(y));
}

void push(int data)
{
    if(k <= 1)
    {
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
    }
    else
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->xnode = tail;
        if(sz)
        {
            if(sz == k-1)
            {
                r = head;
                tail->xnode = XOR(newNode, tail->xnode);
                tail = newNode;
            }
            else if(sz >= k)
            {
                struct Node* old_pr = pr;
                pr = r;
                tail->xnode = XOR(newNode, tail->xnode);
                tail = newNode;
                r = XOR(r->xnode, old_pr);
            }
            else
            {
                tail->xnode = XOR(newNode, tail->xnode);
                tail = newNode;
            }
        }
        else
        {
            head = newNode;
            tail = newNode;
        }
    }
    sz++;
}

void lreverse()
{
    if(k > 1 and sz >= k)
    {
        if(sz == k)
        {
            r = tail;
            tail = head;
            head = r;
        }
        else
        {
            struct Node* old_pr = pr;
            struct Node* old_r = r;
            struct Node* old_tail = tail;
            pr->xnode = XOR(XOR(pr->xnode, r), tail);
            r->xnode = XOR(r->xnode, old_pr);
            tail->xnode = XOR(tail->xnode, old_pr);
            r = old_tail;
            tail = old_r;
        }
    }
    else if(k > 1 and sz > 1)
    {
        struct Node* t = head;
        head = tail;
        tail = t;
    }
}

void printList()
{
    struct Node* cur = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while(cur != NULL)
    {
        cout<<cur->data<<" ";
        next = XOR(prev, cur->xnode);
        prev = cur;
        cur = next;
    }
    cout<<endl;
}




int main()
{
	cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        string s;
        int x;
        cin>>s;
        if(s == "REVERSE")
        {
            lreverse();
        }
        else if(s == "ADD")
        {
            cin>>x;
            push(x);
        }
    }
    printList();
}








