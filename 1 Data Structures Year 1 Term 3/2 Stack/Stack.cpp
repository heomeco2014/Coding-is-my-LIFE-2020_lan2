#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

struct node
{
    int key;
    node *pNext;
};

struct stack
{
    node *pHead;
    node *pTop;
};

node *createNode(int data)
{
    node *pCur = new node;
    pCur->key = data;
    pCur->pNext = NULL;
    return pCur;
}

stack *createStack(node *pnode)
{
    stack *newStack = new stack;
    newStack->pHead = pnode;
    newStack->pTop = pnode;
    pnode->pNext = NULL;
    return newStack;
}

bool push(stack *&S, int data)
{
    node *pCur = createNode(data);
    if (S->pHead == NULL)
    {
        createStack(pCur);
        return true;
    }
    else
    {
        S->pTop->pNext = pCur;
        S->pTop = pCur;
        pCur->pNext = NULL;
        return true;
    }
    return false;
}

void pop(stack *&S)
{
    if (S->pHead == NULL)
        return;
    if (!S->pHead->pNext)
    {
        delete S->pHead;
        S->pHead = NULL;
        return;
    }
    node *pCur = new node;
    pCur = S->pHead;
    // 1 2 3
    while (pCur->pNext->pNext)
    {
        pCur = pCur->pNext;
    }
    pCur->pNext = NULL;
    S->pTop = pCur;
    delete pCur->pNext;
    return;
}

void printStack(stack *S)
{
    node *pCur = S->pHead;
    int count = 0;
    while (pCur)
    {
        count++;
        pCur = pCur->pNext;
    }
    pCur = S->pHead;
    int*a = new int[count];
    for(int i = 0 ; i < count; ++i){
        a[i] = pCur->key;
        pCur = pCur->pNext;
    }

    for(int i = count-1; i >=0; i--)
    {
        cout << a[i] << endl;
    }
    return;
}

int main()
{
    node *a = createNode(0);
    stack *Stsk = createStack(a);
    push(Stsk, 1);
    push(Stsk, 1);
    push(Stsk, 1);
    push(Stsk, 1);
    pop(Stsk);
    printStack(Stsk);
    return 0;
}