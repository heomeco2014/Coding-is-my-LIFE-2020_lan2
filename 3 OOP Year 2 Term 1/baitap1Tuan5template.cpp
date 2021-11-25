
#include <ostream>
#include <stdexcept>
#include<iostream>
using namespace std;

struct Node {
  int info;
  Node* pNext;
  Node(int info, Node* pNext) : info(info), pNext(pNext) { }
};

class LinkedList {
  friend ostream& operator<<(ostream& os, const LinkedList& right);
public:
  LinkedList();
  LinkedList(const LinkedList& o);
  virtual ~LinkedList();
  Node* AddHead(const int& n);
  Node* AddTail(const int& n);
  Node* RemoveHead();
  Node* RemoveTail();
  LinkedList& operator=(const LinkedList&);
  int& operator[](const int& i);
  int getSize() const;
  bool isEmpty() const;
private:
  Node* pHead, * pTail;
  int size;
};
LinkedList::LinkedList() : size(0) {
  pHead = pTail = NULL;
}

LinkedList::LinkedList(const LinkedList& o) : size(0) {
  pHead = pTail = NULL;
  Node* p = o.pHead;
  for (; p != NULL; p = p->pNext)
    AddTail(p->info);
}

LinkedList::~LinkedList() {
  Node* p = pHead, * next = NULL;
  for (; p != NULL; p = next) {
    next = p->pNext;
    delete p;
  }
  size = 0;
}

Node* LinkedList::AddTail(const int& n) {
  if (pTail == NULL) pHead = pTail = new Node(n, NULL);
  else {
    pTail->pNext = new Node(n, NULL);
    pTail = pTail->pNext;
  }
  size++;
  return pTail;
}

Node* LinkedList::AddHead(const int& n) {
  if (pTail == NULL) pHead = pTail = new Node(n, NULL);
  else pHead = new Node(n, pHead);
  size++;
  return pHead;
}

Node* LinkedList::RemoveHead() {
  Node* p = pHead;
  if (pHead != NULL) {
    pHead = pHead->pNext;
    delete p;
    if (pHead == NULL) pTail = NULL;
    size--;
  }
  return p;
}

Node* LinkedList::RemoveTail() {
  Node* p = pTail;
  if (pTail != NULL) {
    if (pHead->pNext == NULL) {
      delete pHead;
      pHead = pTail = NULL;
    }
    else {
      Node* t = pHead;
      while (t->pNext != pTail) t = t->pNext;
      delete pTail;
      t->pNext = NULL;
      pTail = t;
    }
    size--;
  }
  return p;
}

ostream& operator<<(ostream& os, const LinkedList& right) {
  Node* p = right.pHead;
  if (p == NULL) os << "The list is empty!" << endl;
  for (; p != NULL; p = p->pNext)
    os << p->info;
  return os;
}

int& LinkedList::operator[](const int& i) {
  if (!size) throw out_of_range("");
  int index = i;
  if (index < 0) index = 0;
  if (index >= size) index = size - 1;
  Node* p = pHead;
  for (int k = 0; k < index; ++k, p = p->pNext) {}
  return p->info;
}

LinkedList& LinkedList::operator=(const LinkedList& src) {
  Node* p = pHead, * next = NULL;
  for (; p != NULL; p = next) {
    next = p->pNext;
    delete p;
  }
  pHead = pTail = NULL;
  p = src.pHead;
  for (; p != NULL; p = p->pNext)
    AddTail(p->info);
  return *this;
}

int LinkedList::getSize() const {
  return size;
}

bool LinkedList::isEmpty() const {
  return size == 0;
}

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
}