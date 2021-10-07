#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

struct avl
{
    double key;
    avl *left;
    avl *right;
};

void createNode(avl *&root, double val)
{
    if (root == NULL)
    {
        root = new avl;
        root->key = val;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
}

int height(avl *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

void leftRotate(avl *&root)
{
    avl *p = root->right;
    root->right = p->left;
    p->left = root;
    root = p;
}

void rightRotate(avl *&root)
{
    avl *p = root->left;
    root->left = p->right;
    p->right = root;
    root = p;
}

void Balance(avl *&root)
{
    int balance = height(root->right) - height(root->left);
    if (balance >= 2) // Lech phai
    {
        if (height(root->right->right) > height(root->right->left))
        {
            leftRotate(root);
        }
        else if (height(root->right->right) < height(root->right->left))
        {
            rightRotate(root->right);
            leftRotate(root);
        }
    }
    else if (balance <= -2)
    {
        if (height(root->left->left) > height(root->left->right))
        {
            rightRotate(root);
        }
        else if (height(root->left->left) < height(root->left->right))
        {
            leftRotate(root->left);
            rightRotate(root);
        }
    }
    return;
}

void insertNode(avl *&root, double val)
{
    if (root == NULL)
        createNode(root, val);
    else if (root->key > val)
        insertNode(root->left, val);
    else if (root->key < val)
        insertNode(root->right, val);
    Balance(root);
}

void deleteNode(avl *&root, double val)
{
    if (root == NULL)
        return;
    else if (val > root->key)
        deleteNode(root->right, val);
    else if (val < root->key)
        deleteNode(root->left, val);

    if (root->key == val)
    {
        if (!root->left && !root->right)
        {
            delete root;
            root = NULL;
            return;
        }
        else if (!root->left && root->right)
        {
            avl *pTemp = root;
            root = root->right;
            delete pTemp;
            pTemp = NULL;
            
        }
        else if (root->left && !root->right)
        {
            avl *pTemp = root;
            root = root->left;
            delete pTemp;
            pTemp = NULL;
        }
        else
        {
            avl *pTemp = root->right;
            while (pTemp->left)
                pTemp = pTemp->left;
            root->key = pTemp->key;
            deleteNode(root->right, root->key);
        }
    }
    Balance(root);
}
avl *createAVLTreeFromList(avl *&root, vector<double> a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        insertNode(root, a[i]);
    }
    return root;
}

void print(avl *root)
{
    if (root == NULL)
        return;
    queue<avl *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        avl *pFront = q.front();
        q.pop();
        if (pFront)
        {
            cout << pFront->key << " ";
            if (pFront->left)
                q.push(pFront->left);
            if (pFront->right)
                q.push(pFront->right);
        }
        else
        {
            if (!q.empty())
                q.push(NULL);
        }
    }
}

bool isFullBinaryTree(avl *root)
{
    if (root == NULL)
        return true;
    if (!root->left && !root->right)
        return true;
    if (root->left && root->right)
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);

    return false;
}

int main()
{
    // Cau a)
    ifstream f("input.txt", ios::in);
    int size;
    f >> size;
    vector<double> a;
    double temp;
    for (int i = 0; i < size; ++i)
    {
        f >> temp;
        a.push_back(temp);
    }
    avl *root = NULL;
    createAVLTreeFromList(root, a);
    print(root);
    cout << endl;
    // Xong cau a)

    // Cau b)
    string tam;
    getline(f,tam);// Doc xuong hang
    getline(f,tam);// Doc het dong
    stringstream ss(tam);
    double num;
    while(ss >> num){
        deleteNode(root,num);
    }
    print(root);
    cout << endl;
    // cau c)
    getline(f,tam);
    stringstream s(tam);
    avl*root2 = NULL;
    while(s >> num){
        insertNode(root2,num);
    }
    cout << isFullBinaryTree(root2);
    return 0;
}