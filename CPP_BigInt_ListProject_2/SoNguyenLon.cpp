#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
  long long info;
  Node* pNext;
  Node(int info, Node* pNext) {
    this->info = info;
    this->pNext = pNext;
  };
};

class LinkedList {
  friend ostream& operator<<(ostream& os, const LinkedList& right);
public:
  LinkedList();
  LinkedList(const LinkedList& o);
  Node* AddHead(const long long& n);
  Node* AddTail(const long long& n);
  Node* RemoveHead();
  Node* RemoveTail();
  LinkedList& operator=(const LinkedList&);
  long long& operator[](const long long& i);
  long long getSize() const;
  bool isEmpty() const;
private:
  Node* pHead, * pTail;
  long long size;
};
LinkedList::LinkedList() : size(0) {
  pHead = pTail = NULL;
}

LinkedList::LinkedList(const LinkedList& o) : size(0) {
  pHead = pTail = NULL;
  Node* pCur = o.pHead;

  while (pCur != NULL)
  {
    AddTail(pCur->info);
    pCur = pCur->pNext;
  }
}


Node* LinkedList::AddTail(const long long& n) {
  if (pTail == NULL) pHead = pTail = new Node(n, NULL);
  else {
    pTail->pNext = new Node(n, NULL);
    pTail = pTail->pNext;
  }
  size++;
  return pTail;
}

Node* LinkedList::AddHead(const long long& n) {
  if (pTail == NULL) pHead = pTail = new Node(n, NULL);
  else pHead = new Node(n, pHead);
  size++;
  return pHead;
}

Node* LinkedList::RemoveHead() {
  Node* pCur = pHead;
  if (pHead != NULL) {
    pHead = pHead->pNext;
    delete pCur;
    if (pHead == NULL) pTail = NULL;
    size--;
  }
  return pCur;
}

Node* LinkedList::RemoveTail() {
  Node* pCur = pTail;
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
  return pCur;
}

ostream& operator<<(ostream& os, const LinkedList& right) {
  Node* pCur = right.pHead;
  if (pCur == NULL) os << "The list is empty!" << endl;
  while (pCur != NULL) {
    os << pCur->info;;
    pCur = pCur->pNext;
  }
  return os;
}

long long& LinkedList::operator[](const long long& i) {
  if (!size) throw out_of_range("");
  long long index = i;
  if (index < 0) index = 0;
  if (index >= size) index = size - 1;
  Node* pCur = pHead;
  int k = 0;
  while (k < index)
  {
    pCur = pCur->pNext;
    k++;
  }

  return pCur->info;
}

LinkedList& LinkedList::operator=(const LinkedList& src) {
  Node* pCur = pHead, * next = NULL;
  for (; pCur != NULL; pCur = next) {
    next = pCur->pNext;
    delete pCur;
  }
  pHead = pTail = NULL;
  pCur = src.pHead;
  for (; pCur != NULL; pCur = pCur->pNext)
    AddTail(pCur->info);
  return *this;
}

long long LinkedList::getSize() const {
  return size;
}

bool LinkedList::isEmpty() const {
  return size == 0;
}

class SoNguyenLon {
public:
  SoNguyenLon();
  SoNguyenLon(long long n);
  SoNguyenLon(long long d, long long n);
  SoNguyenLon(const LinkedList& src);
  SoNguyenLon(const SoNguyenLon& other);
  const SoNguyenLon& operator=(const SoNguyenLon& right);
  long long compare(const SoNguyenLon& right) const;
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

SoNguyenLon::SoNguyenLon(long long n) {
  do list.AddHead(n % 10); while (n /= 10);
  if (compare(max) > 0) max = *this;
}

SoNguyenLon::SoNguyenLon(long long d, long long n) {
  for (long long i = 0; i < n; ++i)
    list.AddHead(d % 10);
  if (compare(max) > 0) max = *this;
}

SoNguyenLon::SoNguyenLon(const LinkedList& src) {
  list = src;
  if (compare(max) > 0) max = *this;
}

SoNguyenLon::SoNguyenLon(const SoNguyenLon& other) {
  list = other.list;
  if (compare(max) > 0) max = *this;
}


SoNguyenLon operator+(const SoNguyenLon& firstNum, const SoNguyenLon& secondNum) {
  long long c = 0;
  LinkedList r;
  LinkedList l1(firstNum.list);
  LinkedList l2(secondNum.list);
  while (!l1.isEmpty() && !l2.isEmpty()) {
    c = l1.RemoveTail()->info + l2.RemoveTail()->info + c;
    r.AddHead(c % 10);
    c /= 10;
  }
  while (!l1.isEmpty()) {
    c = l1.RemoveTail()->info + c;
    r.AddHead(c % 10);
    c /= 10;
  }
  while (!l2.isEmpty() > 0) {
    c = l2.RemoveTail()->info + c;
    r.AddHead(c % 10);
    c /= 10;
  }
  if (c) r.AddHead(1);
  return SoNguyenLon(r);
}

void subtract(long long& c, LinkedList& r) {
  if (c < 0) {
    r.AddHead((10 + c) % 10);
    c = 1;
  }
  else {
    r.AddHead(c % 10);
    c = 0;
  }
}

SoNguyenLon operator-(const SoNguyenLon& firstNum, const SoNguyenLon& secondNum) {
  if (firstNum.compare(secondNum) <= 0) return SoNguyenLon();
  long long c = 0;
  LinkedList r;
  LinkedList l1(firstNum.list);
  LinkedList l2(secondNum.list);
  while (!l1.isEmpty() && !l2.isEmpty()) {
    c = (l1.RemoveTail()->info) - ((l2.RemoveTail()->info) + c);
    subtract(c, r);
  }
  while (!l1.isEmpty()) {
    c = l1.RemoveTail()->info - c;
    subtract(c, r);
  }
  while (!l2.isEmpty()) {
    c = l2.RemoveTail()->info - c;
    subtract(c, r);
  }
  return SoNguyenLon(r);
}

SoNguyenLon operator*(const SoNguyenLon& firstNum, const SoNguyenLon& secondNum) {
  LinkedList r;
  LinkedList l1(firstNum.list);
  LinkedList l2(secondNum.list);
  long long i, j, k, n, m, c;
  i = l1.getSize() - 1;
  j = l2.getSize() - 1;
  n = i + j;
  c = 0;
  for (k = n; k >= 0; --k) {
    for (m = k; m >= 0; --m)
      if (m <= i && (k - m) <= j)
        c += l1[m] * l2[k - m];
    r.AddHead(c % 10);
    c /= 10;
  }
  if (c) r.AddHead(c);
  return SoNguyenLon(r);
}

const SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& right) {
  if (this == &right) return *this;
  list = right.list;
  return *this;
}

SoNguyenLon SoNguyenLon::SNLMax() {
  return max;
}

ostream& operator<<(ostream& os, const SoNguyenLon& n) {
  os << n.list;
  return os;
}

long long SoNguyenLon::compare(const SoNguyenLon& right) const {
  if (list.getSize() > right.list.getSize()) return 1;
  if (list.getSize() < right.list.getSize()) return -1;
  LinkedList l1(list);
  LinkedList l2(right.list);
  while (!l1.isEmpty() && l1[0] == l2[0]) {
    l1.RemoveHead();
    l2.RemoveHead();
  }
  if (l1.isEmpty()) return 0;
  if (l1[0] > l2[0]) return 1;
  if (l1[0] < l2[0]) return -1;
  return -2;
}
int main() {
  SoNguyenLon snl1;
  SoNguyenLon snl2(44667733);
  SoNguyenLon snl3(5, 9);
  SoNguyenLon snl4(7, 30);
  SoNguyenLon snl5 = snl3 - snl2;
  SoNguyenLon snl6 = 1098765432 - snl2;
  SoNguyenLon snl7 = snl4 - snl3 + 123456789;
  SoNguyenLon snl8 = snl2 * snl3;
  cout << snl1 << endl << snl2 << endl << snl3 << endl;
  cout << snl4 << endl << snl5 << endl << snl6 << endl;
  cout << snl7 << endl << snl8 << endl << endl;
  return 0;
}