#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct AVL {
	float data;
	AVL* left;
	AVL* right;
};
void createAVL(AVL*& root, float val)
{
	
		root = new AVL;
		root->data = val;
		root->left = nullptr;
		root->right = nullptr;
		return;
	
}
void levelOrder(AVL* pRoot)
{
	if (pRoot == nullptr)
		return;
	queue<AVL*>q;
	q.push(pRoot);
	while (!q.empty())
	{
		AVL* pCur = q.front();
		q.pop();
		if (pCur->left != nullptr)
			q.push(pCur->left);
		if (pCur->right != nullptr)
			q.push(pCur->right);
		cout << pCur->data << " ";
	}
}
void leftRotate(AVL*& root)
{
	if (root == NULL)
		return;
	AVL* pAVL = root->right;
	root->right = pAVL->left;
	pAVL->left = root;
	root = pAVL;
}
void rightRotate(AVL*& root)
{
	if (root == NULL)
		return;
	AVL* pAVL = root->left;
	root->left = pAVL->right;
	pAVL->right = root;
	root = pAVL;
}
void InsertButAVL(AVL*& pRoot, float x)
{
	if (pRoot == nullptr)
	{
		AVL* q = new AVL;
		q->data = x;
		q->left = q->right = nullptr;
		pRoot = q;
	}
	else
	{
		if (x < pRoot->data)
			InsertButAVL(pRoot->left, x);
		else if (x > pRoot->data)
			InsertButAVL(pRoot->right, x);
	}
}
int Height1(AVL* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int HL, HR;
	HL = Height1(pRoot->left);
	HR = Height1(pRoot->right);
	if (HL > HR)
		return(1 + HL);
	return(1 + HR);
}
void balanceBHT(AVL*& pRoot)
{
	int a = Height1(pRoot->left) - Height1(pRoot->right);
	if (a > 1)
	{
		if (Height1(pRoot->left->left) >= Height1(pRoot->left->right))
			rightRotate(pRoot);
		else if (Height1(pRoot->left->left) >= Height1(pRoot->left->right))
		{
			leftRotate(pRoot->left);
			rightRotate(pRoot);
		}
	}
	if (a < -1)
	{
		if (Height1(pRoot->right->right) > Height1(pRoot->right->left))
			leftRotate(pRoot);
		else if (Height1(pRoot->right->right) < Height1(pRoot->right->left))
		{
			rightRotate(pRoot->right);
			leftRotate(pRoot);
		}
	}
}
void insertAVL1(AVL* &root, float val)
{
	 if (root == NULL)
    {
        createAVL(root, val);
    }
    else if (val > root->data)
        insertAVL1(root->right, val);
    else if (val < root->data)
        insertAVL1(root->left, val);
	balanceBHT(root);
}
void removeAVL1(AVL*& pRoot, int val)
{
	if (pRoot == nullptr)
		return;
	if (pRoot->data > val)
		removeAVL1(pRoot->left, val);
	else if (pRoot->data < val)
		removeAVL1(pRoot->right, val);
	else if (pRoot->data == val)
	{
		if (pRoot->left == nullptr && pRoot->right == nullptr)
		{
			delete pRoot;
			pRoot = nullptr;
		}
		else if (pRoot->left != nullptr && pRoot->right == nullptr)
		{
			AVL* p = pRoot;
			pRoot = pRoot->left;
			delete pRoot;
		}
		else if ((pRoot->left == nullptr) && (pRoot->right != nullptr))
		{
			AVL* p = pRoot;
			pRoot = pRoot->right;
			delete p;
		}
		else if (pRoot->left != nullptr && pRoot->right != nullptr)
		{
			AVL* p = pRoot->right;
			while (p->left != nullptr)
			{
				p = p->left;
			}
			pRoot->data = p->data;
			removeAVL1(pRoot->right, pRoot->data);
		}
	}
	if (pRoot == nullptr)
		return;
	balanceBHT(pRoot);
}
AVL* createTree(float a[], int n)
{
	AVL* pRoot = new AVL;
	pRoot = nullptr;
	for (int i = 0; i < n; ++i)
		insertAVL1(pRoot, a[i]);
	return pRoot;
}
void printTree(AVL* pRoot)
{
	if (pRoot == nullptr)
		return;
	else
		cout << pRoot->data << " ";
	printTree(pRoot->left);
	printTree(pRoot->right);
}
int main()
{
	AVL* root = new AVL;
    root = nullptr;
	float a[] = { 10.3, 8.5, 7.1, 15.2, 11.3, 15.3, 15.1, 30.0, 42.5, 43.1, 47.2, 60.6 };
    cout << "H";
	root = createTree(a, 12);
    printTree(root);
	return 0;
}