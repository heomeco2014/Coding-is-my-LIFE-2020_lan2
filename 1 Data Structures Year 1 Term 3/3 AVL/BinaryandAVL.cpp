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

void leftRotate(BST *&root)
{
    if (root == NULL)
        return;
    BST *pBST = root->right;
    root->right = pBST->left;
    pBST->left = root;
    root = pBST;
}
void rightRotate(BST *&root)
{
    if (root == NULL)
        return;
    BST *pBST = root->left;
    root->left = pBST->right;
    pBST->right = root;
    root = pBST;
}
void Balance(BST *&root)
{
    int balance = height(root->right) - height(root->left);
    // Cây lệch phải
    if (balance >= 2)
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
    else if (balance <= -2) // Cây lệch trái
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
    Balance(root);
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
    Balance(root);
}

void printCurrentLevel(BST *root, int level);
int height(BST *BST);
BST *newBST(int data);

/* Function to print level
order traversal a tree*/
void printLevelOrder(BST *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

/* Print BSTs at a current level */
void printCurrentLevel(BST *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
void print(BST *root)
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
bool isFullBinaryTree(BST *root)
{
    if (root == NULL)
        return true;
    if (!root->left && !root->right)
        return true;
    if (root->left && root->right)
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    return false;
}

void printNodeFullBinary(BST *root){
    if(root==NULL) return;
    if(isFullBinaryTree(root)) cout << root->data << " ";
    printNodeFullBinary(root->left);
    printNodeFullBinary(root->right);
}

BST*createTreeFromList(BST*&root, vector<double> a){
    for(int i = 0 ; i < a.size();i++){
        insert(root,a[i]);
    }
    return root;
}

 int main()
{
    ifstream f("input.txt",ios::in);
    int size; f >> size;
    double temp;
    vector<double> b;
    for(int i = 0 ; i < size; ++i){
        f >> temp;
        b.push_back(temp);
    }
    BST *root = new BST;
    root = NULL;
    // vector<int> a ={1,3,5,67,8};
    createTreeFromList(root,b);
    // insert(root, 15);
    // insert(root, 16);
    // insert(root, 14);
    // insert(root, 19);
    print(root);
    // cout << "Node with full binary";
    // printNodeFullBinary(root);
    cout << "DONE";
    return 0;
}