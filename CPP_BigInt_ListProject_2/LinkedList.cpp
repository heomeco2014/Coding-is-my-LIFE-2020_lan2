#include "LinkedList.h"
#include <ostream>
#include <stdexcept>

LinkedList::LinkedList() : size(0) {
  pHead = pTail = NULL;
}

LinkedList::LinkedList(const LinkedList& o) : size(0) {
  pHead = pTail = NULL;
  Node *p = o.pHead;
  for (; p != NULL; p = p->pNext)
    addTail(p->info);
}

LinkedList::~LinkedList() {
  Node *p = pHead, *next = NULL;
  for (; p != NULL; p = next) {
    next = p->pNext;
    delete p;
  }
  size = 0;
}

Node* LinkedList::addTail(const int& n) {
  if (pTail == NULL) pHead = pTail = new Node(n, NULL);
  else {
    pTail->pNext = new Node(n, NULL);
    pTail = pTail->pNext;
  }
  size++;
  return pTail;
}

Node* LinkedList::addHead(const int& n) {
  if (pTail == NULL) pHead = pTail = new Node(n, NULL);
  else pHead = new Node(n, pHead);
  size++;
  return pHead;
}

Node* LinkedList::removeHead() {
  Node *p = pHead;
  if (pHead != NULL) {
    pHead = pHead->pNext;
    delete p;
    if (pHead == NULL) pTail = NULL;
    size--;
  }
  return p;
}

Node* LinkedList::removeTail() {
  Node *p = pTail;
  if (pTail != NULL) {
    if (pHead->pNext == NULL) {
      delete pHead;
      pHead = pTail = NULL;
    } else {
      Node *t = pHead;
      while(t->pNext != pTail) t = t->pNext;
      delete pTail;
      t->pNext = NULL;
      pTail = t;
    }
    size--;
  }
  return p;
}

ostream & operator<<(ostream& os, const LinkedList & right) {
  Node *p = right.pHead;
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
  Node *p = pHead;
  for (int k = 0; k < index; ++k, p = p->pNext) { }
  return p->info;
}

LinkedList& LinkedList::operator=(const LinkedList& src) {
  Node *p = pHead, *next = NULL;
  for (; p != NULL; p = next) {
    next = p->pNext;
    delete p;
  }
  pHead = pTail = NULL;
  p = src.pHead;
  for (; p != NULL; p = p->pNext)
    addTail(p->info);
  return *this;
} 

int LinkedList::getSize() const {
  return size;
}

bool LinkedList::isEmpty() const {
  return size == 0;
}