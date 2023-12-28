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
void inOrder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inOrder(node->left);
    cout << node->data << endl;
    inOrder(node->right);
}


int get_max(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
void delete_node(int key)
{
    Node *temp = root;
    Node *q = NULL;
    while (temp != NULL)
    {

        if (key == temp->data)
        {
            cout << "Key found" << endl;
            if (temp->left == NULL && temp->right == NULL)
            {
                if (temp == root)
                    root = NULL;
                else
                {
                    if (q->data < temp->data)
                        q->right = NULL;
                    else
                        q->left = NULL;
                }
            }
            else if (temp->left == NULL || temp->right == NULL)
            {
                if (q->data < temp->data && temp->left == NULL)
                    q->right = temp->right;
                else if (q->data < temp->data && temp->right == NULL)
                    q->right = temp->left;
                else if (q->data > temp->data && temp->right == NULL)
                    q->left = temp->left;
                else
                    q->left = temp->right;
            }
            else
            {
                Node *predecessor = temp->left;
                int value = get_max(predecessor);
                delete_node(value);
                temp->data = value;
            }
            break;
        }

        else if (key < temp->data)
        {
            q = temp;
            temp = temp->left;
        }

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
    inOrder(root);
    int key;
    cout << "Enter value to be deleted:";
    cin >> key;
    delete_node(key);
    inOrder(root);
    return 0;
}
