#include <iostream>
#include <cstdlib>
#include <ctime>
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
    friend ostream& operator << (ostream& os, const LinkedList& right);
public:
    LinkedList();
    LinkedList(const LinkedList& o);
    Node* AddHead(const int& n);
    Node* AddTail(const int& n);
    Node* RemoveHead();
    Node* RemoveTail();
    LinkedList& operator = (const LinkedList&);
    int& operator [](const int& i);
    int getSize() const;
    bool isEmpty() const;
private:
    Node* pHead, * pTail;
    int size;
};

LinkedList::LinkedList(const LinkedList& o) :size(0) {
    pHead = pTail = NULL;
}

LinkedList::LinkedList(const LinkedList& o) : size(0) {
    pHead = pTail = NULL;
    Node* pCur = o.pHead;
    while (!pCur)
    {
        AddTail(pCur->info);
        pCur = pCur->pNext;
    }
}

Node* LinkedList::AddTail(const int& tail) {
    if (pTail == NULL) pHead = pTail = new Node(tail, NULL);
    else {
        pTail->pNext = new Node(tail, NULL);
        pTail = pTail->pNext;
    }
    size++;
    return pTail;
}
Node* LinkedList::AddHead(const int& head) {
    if (pHead == NULL) pHead = pTail = new Node(head, NULL);
    else {
        pHead = new Node(head, pHead);
    }
    size++;
    return pHead;
}
Node* LinkedList::RemoveHead() {
    Node* pCur = pHead;
    if (pCur != NULL) {
        pHead = pHead->pNext;
        delete pCur;
        if (pHead == NULL) pTail = NULL;
        size--;
    }
    return pCur;
}

Node* LinkedList::RemoveTail() {
    Node* pCur = pTail;
    if (pTail != NULL && pHead->pNext == NULL) {
        delete pTail;
        pHead = pTail = NULL;
    }
    else {
        Node* tmp = pHead;
        while (tmp->pNext != pTail) tmp = tmp->pNext;
        delete pTail;
        tmp->pNext = NULL;
        pTail = tmp;
    }
    size--;
    return pCur;
}

ostream& operator <<(ostream& os, const LinkedList& right) {
    Node* pCur = right.pHead;
    if (!pCur)    os << "The list is empty" << endl;
    while (!pCur)
    {
        os << pCur->info;
        pCur = pCur->pNext;
    }
    return os;
}

int& LinkedList::operator[](const int& i) {
    if (!size) throw out_of_range("");
    int index = i;
    if (index < 0) index = 0;
    if (index >= size) index = size - 1;
    Node* pCur = pHead;
    int k = 0;
    while (k < index) {
        pCur = pCur->pNext;
        k++;
    }
    return pCur->info;
}

LinkedList& LinkedList::operator=(const LinkedList& src) {
    Node* pCur = pHead, * next = NULL;
    for (;pCur != NULL;pCur = next) {
        next = pCur->pNext;
        delete pCur;
    }
    pHead = pTail = NULL;
    pCur = src.pHead;
    for (; pCur != NULL; pCur = pCur->pNext)
        AddTail(pCur->info);
    return *this;
}
int LinkedList::getSize() const {
    return size;
}

bool LinkedList::isEmpty() const {
    return size == 0;
}

class SoNguyenLon {
    SoNguyenLon();
    SoNguyenLon(int n);
    SoNguyenLon(int d, int n);
    SoNguyenLon(const LinkedList& src);
    SoNguyenLon(const SoNguyenLon& other);
    const SoNguyenLon& operator= (const SoNguyenLon& right);
    int compare(const SoNguyenLon& right) const;
    static SoNguyenLon SNLMax();

    friend SoNguyenLon operator+(const SoNguyenLon& firstNum, const SoNguyenLon& secondNum);
    friend SoNguyenLon operator-(const SoNguyenLon& firstNum, const SoNguyenLon& secondNum);
    friend SoNguyenLon operator*(const SoNguyenLon& firstNum, const SoNguyenLon& secondNum);
    friend ostream& operator<<(ostream& os, const SoNguyenLon& n);
private:
    LinkedList list;
    static SoNguyenLon max;
};
SoNguyenLon SoNguyenLon::max = SoNguyenLon();
SoNguyenLon::SoNguyenLon() {
    list.AddTail(0);
}
SoNguyenLon::SoNguyenLon(int n){
    
}
