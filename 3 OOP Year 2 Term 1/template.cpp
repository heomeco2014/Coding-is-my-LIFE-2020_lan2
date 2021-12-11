#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;

template <typename T>
void swapVars(T& var1, T& var2) {
    T temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

template <typename Item>

void selectionSort(Item a[], int l, int r) {
    for (int i = 0; i < r; i++)
    {
        int min = i;
        for (int j = i + 1; j <= r; j++)
        {
            if (a[j] < a[min]) {
                min = j;
            }
            swap(a[i], a[min]);
        }
    }
}

template <class Item>
void partiTion(Item A[], int left, int right) {
}
template <class Key, class Value>
class BST {
private:
    struct Node
    {
        Key key;
        Value value;
        Node* left, * right;
        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
        ~Node() {
            if (left) delete left;
            if (right) delete right;
        }
    };

    void Insert(link root, Key key, Value value) {

    }

};

template <class temp1 = int, class temp2 = double>

class HoldPairs {
private:
    temp1 T1;
    temp2 T2;
public:
    HoldPairs(const temp1& val1, const temp2& val2) {
        T1 = val1;
        T2 = val2;
    }
};

int main() {
    HoldPairs<int, string> pairIntandDouble(6, "Minh");
    HoldPairs<string, double> stringAndDouble("Hoang", 21.2);
    return 0;
}