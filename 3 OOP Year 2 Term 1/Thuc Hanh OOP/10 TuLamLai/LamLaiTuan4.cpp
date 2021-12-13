#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;

struct Node
{
    int info;
    Node* pNext;
    Node(int info, Node* pNext) {
        this->info = info;
        this->pNext = pNext;
    }
};

class LinkedList {
private:
    Node* pHead, * pTail;
    int size;
public:
    LinkedList() {
        pHead = pTail = NULL;
        size = 0;
    }
    LinkedList(const LinkedList& list) {
        pHead = pTail = NULL;
        Node* pCur = list.pHead;
        while (!pCur) {
            AddTail(pCur->info);
            pCur = pCur->pNext;
        }
    }
    Node* AddHead(const int& n) {
        if (pTail == NULL) pHead = pTail = new Node(n, NULL);
        else pHead = new Node(n, pHead);
        size++;
        return pHead;
    }
    Node* AddTail(const int& n) {
        if (pTail == NULL) pHead = pTail = new Node(n, NULL);
        else {
            pTail->pNext = new Node(n, NULL);
            pTail = pTail->pNext;
        }
        size++;
        return pTail;
    }
    Node* RemoveHead() {
        Node* pCur = pHead;
        if (pHead != NULL) {
            pHead = pHead->pNext;
            delete pCur;
            if (pHead == NULL) pTail = NULL;
            size--;
        }
        return pCur;
    }
    Node* RemoveTail() {
        Node* pCur = pTail;
        if (pTail != NULL) {
            if (pHead->pNext == NULL) {
                delete pHead;
                pHead = pTail = NULL;
            }
            else {
                Node* tempNode = pHead;
                while (tempNode->pNext != pTail) tempNode = tempNode->pNext;
                delete pTail;
                tempNode->pNext = NULL;
                pTail = tempNode;
            }
            size--;
        }
        return pCur;
    }
    int& operator[](const int& i) {
        if (!size) throw out_of_range("");
        int index = i;
        if (index < 0)index = 0;
        if (index >= size)index = size - 1;
        Node* pCur = pHead;
        for (int k = 0; k < index; ++k, pCur = pCur->pNext) {}
        return pCur->info;
    }
    friend ostream& operator << (ostream& os, const LinkedList& right) {
        Node* pCur = right.pHead;
        if (!pCur)cout << "Empty list" << endl;
        while (pCur)
        {
            cout << pCur->info << " ";
            pCur = pCur->pNext;
        }
        return os;
    }
};


int main() {
    srand(1234);
    LinkedList l;
    for (int i = 0; i < 10; ++i)
    {
        if (rand() % 2 == 0)
        {
            l.AddHead(rand() % 1001);
        }
        else
        {
            l.AddTail(rand() % 1001);
        }
    }
    cout << l << endl;
    l.RemoveHead();
    l.RemoveTail();
    l[-1] = 9000;
    l[4] = 2000;
    l[100] = 10000;
    cout << l << endl;
    return 0;
}