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

struct List
{
    node *pHead;
    node *pTail;
};

node *createNode(int data)
{
    node *pCur = new node;
    pCur->key = data;
    pCur->pNext = NULL;
    return pCur;
}

List *createList(node *&pNode)
{
    List *list = new List;
    list->pHead = pNode;
    list->pTail = pNode;
    pNode->pNext = NULL;
    return list;
}

bool addTail(List *&L, int data)
{
    node *pCur = createNode(data);
    if (L->pHead == NULL)
    {
        createList(pCur);
        return true;
    }
    else
    {
        L->pTail->pNext = pCur;
        L->pTail = pCur;
        return true;
    }
    return false;
}

void printList(List *L)
{
    if (L->pHead == NULL){
        cout << "There's NO item to print" << endl;
        return;
    }
    node *pCur = L->pHead;
    while (pCur)
    {
        cout << pCur->key << " ";
        pCur = pCur->pNext;
    }
    return;
}

bool addHead(List *&L, int data)
{
    node *pCur = createNode(data);
    if (L->pHead == NULL)
    {
        createList(pCur);
        return true;
    }
    else
    {
        pCur->pNext = L->pHead;
        L->pHead = pCur;
        return true;
    }
    return false;
}

void removeHead(List *&L)
{
    if (L->pHead == NULL)
        return;
    if (!L->pHead->pNext)
    {
        delete L->pHead;
        L->pHead = NULL;
        return;
    }
    node *pCur = L->pHead;
    L->pHead = L->pHead->pNext;

    delete pCur;
    pCur = nullptr;
    return;
}

void removeEnd(List *&L)
{
    if (L->pHead == NULL)
    {
        return;
        cout << "No more item to remove ";
    }

    if (!L->pHead->pNext)
    {
        delete L->pHead;
        L->pHead = NULL;
        return;
    }
    node *pCur = new node;
    pCur = L->pHead;

    while (pCur->pNext->pNext)
    {
        pCur = pCur->pNext;
    }
    pCur->pNext = NULL;
    L->pTail = pCur;
    delete pCur->pNext;
    return;
}

bool addPos(List *&L, int data, int pos)
{
    int countPos = 0;
    if (L->pHead == NULL)
        return 0;
    node *pCur = L->pHead;
    if (pos == 0)
        addHead(L, data);
    while (countPos != pos && pCur)
    {
        countPos++;
        if (countPos == pos)
        {
            node *tmp = createNode(data);
            node *nextNode = pCur->pNext;
            pCur->pNext = tmp;
            tmp->pNext = nextNode;
            return true;
        }
        else
        {
            pCur = pCur->pNext;
        }
    } //  0 1 2 3 4
    return false;
}

bool removeAtPos(List *&L, int pos)
{
    int countPos = 0;
    if (L->pHead == NULL)
        return 0;
    node *pCur = L->pHead;
    if (pos == 0)
        removeHead(L);
    while (pos != countPos && pCur)
    {
        countPos++;
        if (countPos == pos)
        {
            node *pDel = pCur->pNext;
            pCur->pNext = pDel->pNext;
            delete pDel;
            pDel = NULL;
            return true;
        }
        else
        {
            pCur = pCur->pNext;
        }
    }
    return false;
}
List *reverseLinkedList(List *L)
{
    node *pPrev = NULL;
    node *pCur = L->pHead;
    while (pCur)
    {
        node *current = pCur->pNext;
        pCur->pNext = pPrev;
        pPrev = pCur;
        pCur = current;
    }
    L->pHead = pPrev;
    return L;
}
// 1 2 3 4 2 2 4
// 1 1 3 2 2
void removeDup(List *&L)
{
    node *pCur = L->pHead, *pScan = pCur;
    while (pCur && pCur->pNext)
    {
        pScan = pCur;
        while (pScan->pNext)
        {
            if (pScan->pNext->key == pCur->key)
            {
                node *pTemp = pScan->pNext;
                pScan->pNext = pScan->pNext->pNext;
                pTemp = NULL;
            }
            else
            {
                pScan = pScan->pNext;
            }
        }
        pCur = pCur->pNext;
    }
}
// 1 1 3 2 2
void removeDup2(List *&L)
{
    node *pCur = L->pHead;
    while (pCur && pCur->pNext)
    {
        node *pScan = pCur->pNext;
        while (pScan)
        {
            if (pScan->key == pCur->key)
            {
                node *pTemp = pScan->pNext;
                pCur->pNext = pTemp;
                pScan = pCur->pNext;
            }
            else
                pScan = pScan->pNext;
        }
        pCur = pCur->pNext;
    }
}
List *listOfSum(List *L)
{
    List *newList = new List;
    newList = NULL;
    node *pCur = L->pHead;
    int sum = 0;
    while (pCur)
    // addTail(newList, sum);
    {
        sum += pCur->key;

        pCur = pCur->pNext;
    }
    return newList;
}
bool isLisEmpty(List *L)
{
    return L->pHead == NULL;
}
int main()
{
    node *a = createNode(1);
    List *list = createList(a);
    addTail(list, 2);
    addTail(list, 2);
    addTail(list, 4);
    addTail(list, 2);
    addTail(list, 6);
    // addTail(list, 0);
    // addTail(list, 2);
    // addHead(list, 0);
    // removeHead(list);
    // removeEnd(list);
    // addTail(list, 10);
    // addPos(list, 11, 7);
    // removeAtPos(list,2);
    // removeDup2(list);
    printList(list);
    cout << endl;
    removeHead(list);
    removeEnd(list);
    removeEnd(list);
    removeEnd(list);
    removeEnd(list);
    removeEnd(list);
    printList(list);
    // List *newList = reverseLinkedList(list);
    // printList(newList);
    return 0;
}