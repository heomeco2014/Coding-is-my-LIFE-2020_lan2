#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

struct node
{
    int key;
    node* pNext;
    node* prev;
};
struct node*head;
node* createNewnode(int val){
    node*temp = new node;
    temp->key = val;
    temp->prev = NULL;
    temp->pNext = NULL;
    return temp;
}

void insertAtHead(int val){
    node*tmp = createNewnode(val);
    if(head==NULL){
        head = tmp;
        return;
    }
    head->prev = tmp;
    tmp->pNext = head;
    head = tmp;
}

void printFromHead(){
    node*pCur = head;
    cout << pCur->key << " ";
    pCur = pCur->pNext;
    cout << pCur->prev->key << " ";
}

int main()
{
    insertAtHead(5);
    insertAtHead(4);
    insertAtHead(3);
    insertAtHead(2);
    printFromHead();

    return 0;
}