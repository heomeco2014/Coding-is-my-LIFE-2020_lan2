#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

struct node
{
    node *pNext;
    int key;
};

struct Queue
{
    // 1 2 3 4 5
    node *front; //1
    node *rear;  //5
};

node*createNode(int data){
    node*p = new node;
    p->key = data;
    p->pNext = NULL;
    return p;
}

Queue*InitQueue(int data)
{
    node*p = createNode(data);
    Queue*res = new Queue;
    res->front = p;
    res->rear = p;
    return res;
}


void enqueue(Queue*&q, int key) // Insert element at the rear of the Queue
{
    node*p = createNode(key);
    q->rear->pNext = p;
    q->rear = p;
}

node* pop(Queue*&q){
    node*pCur = q->front;
    q->front = q->front->pNext;
    return pCur;
}
int peek(Queue*q){
    return q->front->key;
}
int count(Queue*q){
    if(!q->front) return 0;
    int count = 0;
    node*pCur = q->front;
    while(pCur){
        count++;
        pCur = pCur->pNext;
    }
    return count;
}
bool isQueueEmpty(Queue*q){
    return q->front==NULL;
}

void printQueue(Queue*q){
    node*pCur = q->front;
    while(pCur){
        cout << pCur->key << " ";
        pCur = pCur->pNext;
    }
}
int main()
{
    Queue*a = InitQueue(0);
    enqueue(a,1);





    return 0;
}