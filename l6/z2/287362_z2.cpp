#include <iostream>
#include <algorithm>


using namespace std;

// wezel drzewa binarnego
struct Node
{
    int data; //wartosc wezel
    Node* left; //wskaznik do lewego dziecka
    Node* right; //wskaznik do prawego dziecka

    Node() //pusty wezel
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
    Node(int val) //wezel z wartoscia
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
    ~Node() //destruktor
    {
        delete left;
        delete right;
    }
};

/* PODPUNKT 1
ladne wyswietlanie drzewa;
indent - wciecie dla aktualnego poziomu; last - ostatnie dziecko rodzica
+-- - dla lewego dziecka
\-- - dla prawego dziecka

*/
void printTree(Node* node, string indent = "", bool last = true)
{
    if (node)
    {
        cout << indent;
        if (last)
        {
            cout << "\\--";
            indent += "   ";
        } else
        {
            cout << "+--";
            indent += "|  ";
        }
        cout << node->data << endl;

        printTree(node->left, indent, false);
        printTree(node->right, indent, true);
    }
}

// POPDUNKT 3 zbalansowane drzewo
Node* buildBalancedTree(int t[], int start, int end)
{
    if(start>end) return nullptr;
    int mid=start+(end-start)/2; //tutaj dla nieparzystych moga byc rozne wyniki?
    Node* node = new Node(t[mid]);

    node->left = buildBalancedTree(t, start, mid-1);
    node->right = buildBalancedTree(t, mid+1, end);

    return node;
}

//PODPUNKT 4
bool containsValue(Node* node, int value)
{
    if (!node) return false;
    if (node->data == value) return true;
    return containsValue(node->left, value) || containsValue(node->right, value);
}

//PODPUNKT 5
int treeHeight(Node* node)
{
    if (!node) return 0;
    return 1 + max(treeHeight(node->left), treeHeight(node->right));
}

//PODPUNKT 6
void countNodesAndLeaves(Node* node, int& totalNodes, int& leaves)
{
    if (!node) return;

    totalNodes++;
    if (!node->left && !node->right)
    {
        leaves++;
    }
    else
    {
        countNodesAndLeaves(node->left, totalNodes, leaves);
        countNodesAndLeaves(node->right, totalNodes, leaves);
    }
}



int main() {
    int n1, n2, r, s;
    cout << "podaj n1 ";
    cin >> n1;
    cout << "podaj n2 ";
    cin >> n2;
    cout << "podaj r ";
    cin >> r;
    cout << "podaj s ";
    cin >> s;

    int suma=n1+n2;
    int* t = new int[suma];

    //wczytanie elementow
    for(int i=0; i<suma; i++)
    {
        cout << "podaj " << i+1 << " element ";
        cin >> t[i];
    }

    //budowanie 1 drzewa
    Node* tree1=buildBalancedTree(t, 0, n1-1);

    //budowanie 2 drzewa
    Node* tree2=buildBalancedTree(t, n1, suma-1);


    //PODPUNKT 2 sklejanie drze
    Node* mergedTree = new Node(r);
    mergedTree->left = tree1;
    mergedTree->right = tree2;



    //PODPUNKT 1 ladne wyswietlanie
    cout << "drzewo: " << endl;
    printTree(mergedTree);

    //PODPUNKT 6
    int ilenodes=0, liscie=0;
    countNodesAndLeaves(mergedTree, ilenodes, liscie);
    cout << "liczba wezlow " << ilenodes << endl;
    cout << "liczba lisci " << liscie << endl;

    //PODPUNKT 5

    cout << "wysokosc drzewa " << treeHeight(mergedTree) << endl;

    //PODPUNKT 4

    cout << "wartosc " << s << (containsValue(mergedTree, s) ? " " : " nie ") << "wystepuje w drzewie ";


    delete[] t;
    delete mergedTree;
    return 0;
}
