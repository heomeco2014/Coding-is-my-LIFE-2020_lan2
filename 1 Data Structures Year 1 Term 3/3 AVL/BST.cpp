#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

struct BST
{
    BST *left;
    BST *right;
    double data;
};

BST*createNode(double value){
    BST*newNode = new BST;
    newNode->data = value;
    return newNode;
}

int height(BST *root)
{
    if (root == NULL)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return max(leftH, rightH) + 1;
}

void createBST(BST *&root, double val)
{
    if (root == NULL)
    {
        root = new BST;
        root->data = val;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
}
void insert(BST *&root, double val)
{
    if (root == NULL)
    {
        createBST(root, val);
    }
    else if (val > root->data)
        insert(root->right, val);
    else if (val < root->data)
        insert(root->left, val);
}

BST*createTreeFromList(BST*&root, vector<double> a){
    for(int i = 0 ; i < a.size();i++){
        insert(root,a[i]);
    }
    return root;
}

void printLevelOrder(BST *root)
{
    if (root == NULL)
        return;
    queue<BST *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BST *pTemp = q.front();
        q.pop();
        if (pTemp)
        {
            cout << pTemp->data << " ";
            if (pTemp->left)
                q.push(pTemp->left);
            if (pTemp->right)
                q.push(pTemp->right);
        }
        else
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
    }
}

void NLR(BST*root){
    cout << root->data << " ";
    NLR(root->left);
    NLR(root->right);
}


void removeBST(BST *&root, double val)
{
    if (root == NULL)
        return;

    else if (root->data > val)
        removeBST(root->left, val);
    else if (root->data < val)
        removeBST(root->right, val);
    if (root->data == val)
    {
        // BST lá
        if (!root->left && !root->right)
        {
            delete root;
            root = nullptr;
            return;
        }
        // BST có con trái
        else if (root->left && !root->right)
        {
            BST *pTemp = root;
            root = root->left;
            delete pTemp;
        }
        // BST có con phải
        else if (root->right && !root->left)
        {
            BST *pTemp = root;
            root = root->right;
            delete pTemp;
        }
        // BST có 2 con
        else if (root->right && root->left)
        {
            BST *leftSub = root->left;
            while (leftSub->right)
                leftSub = leftSub->right;
            root->data = leftSub->data;
            removeBST(root->left, root->data);
        }
    }
}


int main(){
    BST*root = new BST;
    root = NULL;
    vector<double> a = {10,3,11,5,12};
    createTreeFromList(root,a);
    printLevelOrder(root);
    return 0;
}