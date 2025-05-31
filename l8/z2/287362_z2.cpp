#include <iostream>

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

//nowe wartosci do drzewa
Node* insert_node(Node* root, int val)
{
    if (root == nullptr) return new Node(val);
    if (val < root->data)
        root->left = insert_node(root->left, val);
    else if (val > root->data)
        root->right = insert_node(root->right, val);
    return root;
}

// sprawdza czy drzewa s¹ izomorficzne
bool izomorfizm(Node* a, Node* b)
{
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return izomorfizm(a->left, b->left) && izomorfizm(a->right, b->right);
}

//dodaje wezly drzew
Node* add_trees(Node* a, Node* b)
{
    if (a == nullptr && b == nullptr)
    {
        return nullptr;
    }

    int val = 0;
    Node* left1 = nullptr;
    Node* right1 = nullptr;
    Node* left2 = nullptr;
    Node* right2 = nullptr;

    if (a != nullptr)
    {
        val += a->data;
        left1 = a->left;
        right1 = a->right;
    }

    if (b != nullptr)
   {
        val += b->data;
        left2 = b->left;
        right2 = b->right;
    }

    Node* nowy = new Node(val);
    nowy->left = add_trees(left1, left2);
    nowy->right = add_trees(right1, right2);
    return nowy;
}

//odejmuje wezly drzew
Node* subtract_trees(Node* a, Node* b)
{
    if (a == nullptr && b == nullptr)
    {
        return nullptr;
    }

    int val = 0;
    Node* left1 = nullptr;
    Node* right1 = nullptr;
    Node* left2 = nullptr;
    Node* right2 = nullptr;

    if (a != nullptr)
    {
        val += a->data;
        left1 = a->left;
        right1 = a->right;
    }

    if (b != nullptr)
    {
        val -= b->data;
        left2 = b->left;
        right2 = b->right;
    }

    Node* nowy = new Node(val);
    nowy->left = subtract_trees(left1, left2);
    nowy->right = subtract_trees(right1, right2);
    return nowy;
}

//wypisuje pokolei wwartosci
void print(Node* root) {
    if (!root) return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}


int main()
{
    int n1, n2;

    cin >> n1;
    Node* tree1 = nullptr;
    for (int i = 0; i<n1; i++)
    {
        int val;
        cin >> val;
        tree1 = insert_node(tree1, val);
    }

    cin >> n2;
    Node* tree2 = nullptr;
    for (int i = 0; i<n2; i++)
    {
        int val;
        cin >> val;
        tree2 = insert_node(tree2, val);
    }

    if (izomorfizm(tree1, tree2))
    {
        cout << "drzewa sa izomorficzne " << endl;

        //obliczanie sumy i roznicy drzew
        Node* sum_tree = add_trees(tree1, tree2);
        Node* diff_tree = subtract_trees(tree1, tree2);

        cout << "t1 + t2: ";
        print(sum_tree);
        cout << endl;

        cout << "t1 - t2: ";
        print(diff_tree);
        cout << endl;

        //dodatkowe obliczenia na rozmiarach drzew
        cout << "t1 + t2 = " << n1 + n2 << endl;
        cout << "t1 - t2^2 = " << n1 - (n2 * n2) << endl;

    } else
    {
        cout << "Drzewa nie sa izomorficzne" << endl;
    }

    return 0;
}
