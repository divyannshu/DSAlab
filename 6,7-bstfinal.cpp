#include <iostream>

using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *root = NULL;
void create_node(int num)
{
    Node *p = new Node;
    p->data = num;

    if (root == NULL)
    {
        root = p;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        Node *temp = root;
        Node *q = NULL;

        while (temp != NULL)
        {
            q = temp;
            if (num < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (num < q->data)
            q->left = p;
        else
            q->right = p;
        p->left = NULL;
        p->right = NULL;
    }
}
class in
{

public:
    int count = 0;
    void inOrder(struct Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        if (node->left == NULL && node->right == NULL)
        {
            count++;
            // cout << count << endl;
        }
        inOrder(node->left);
        // cout << node->data << endl;
        inOrder(node->right);
    }
};

void preOrder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << endl;
    preOrder(node->left);
    preOrder(node->right);
}
void postorder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << endl;
}
void search(int key)
{
    Node *temp = root;
    Node *q = NULL;
    while (temp != NULL)
    {
        if (key == temp->data)
        {
            cout << "Key found" << endl;
            if (temp->left != NULL)
            {
                temp = temp->left;
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }
                cout << "Inorder predecessor" << temp->data << endl;
            }
            else if (q == NULL)
                cout << "Inorder predecessor does not exist" << endl;

            else
                cout << "Inorder predecessor" << q->data << endl;

            break;
        }

        else if (key < temp->data)
            temp = temp->left;

        else
        {
            q = temp;
            temp = temp->right;
        }
    }
    if (temp == NULL)
        cout << "Key not found" << endl;
}

int main()
{
    create_node(25);
    create_node(22);
    create_node(63);
    create_node(42);
    create_node(32);
    create_node(71);
    cout << "Inorder traversal" << endl;
    in i;
    i.inOrder(root);
    cout << i.count << endl;
    cout << "Pre Order traversal" << endl;
    preOrder(root);
    cout << "Post order traversal" << endl;
    postorder(root);
    int key;
    cout << "enter value to be searched";
    cin >> key;
    search(key);

    return 0;
}
