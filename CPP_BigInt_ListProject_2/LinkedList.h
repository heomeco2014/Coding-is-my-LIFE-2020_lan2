#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <ostream>
using namespace std;

struct Node {
  int info;
  Node *pNext;
  Node(int info, Node* pNext) : info(info), pNext(pNext) { }
};

class LinkedList {
  friend ostream& operator<<(ostream& os, const LinkedList& right);
public:
  LinkedList();
  LinkedList(const LinkedList& o);
  virtual ~LinkedList();
  Node* addHead(const int& n);
  Node* addTail(const int& n);
  Node* removeHead();
  Node* removeTail();
  LinkedList& operator=(const LinkedList&);
  int& operator[](const int& i);
  int getSize() const;
  bool isEmpty() const;
private:
  Node *pHead, *pTail;
  int size;
};
#endif /* LINKEDLIST_H */

