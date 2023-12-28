
#include <queue>
#include <iostream>

using namespace std;

struct edge
{
    edge *next;
    int data;
    bool vis1 = 0;
};

struct node
{
    node *nextNode;
    edge *next;
    int data;
    bool vis = 0;
};
node *head = NULL;

void createNode(int value)
{
    node *p = new node;
    p->data = value;
    if (head == NULL)
    {
        head = p;
        p->nextNode = NULL;
    }
    else
    {
        node *temp = head;
        while (temp->nextNode != NULL)
        {
            temp = temp->nextNode;
        }
        temp->nextNode = p;
        p->nextNode = NULL;
    }
}
void createEdge()
{
    int linkage;

    node *temp = head;
    while (temp != NULL)
    {
        cout << "Enter number of linkages " << temp->data << ":";
        cin >> linkage;
        edge *temp1 = NULL;
        if (linkage == 0)
            temp->next = NULL;
        else
        {
            for (int i = 0; i < linkage; i++)
            {
                edge *p = new edge;
                cout << "Enter node value";

                cin >> p->data;
                p->next = NULL;

                if (i == 0)
                {
                    temp->next = p;
                }
                else
                {
                    temp1->next = p;
                }
                temp1 = p;
            }
        }
        temp = temp->nextNode;
    }
}
node *search(node *root, int value)
{
    if (root == NULL)
        return nullptr;
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == value)
            return temp;
        temp = temp->nextNode;
    }
    return nullptr;
}
void BFS(node *root)
{

    root->vis = 1;
    queue<int> q;
    int val = root->data;
    q.push(val);
    while (!q.empty())
    {
        int node_value = q.front();
        q.pop();
        node *Node = search(root, node_value);

        edge *edges = Node->next;
        if (Node->vis != 1)
            Node->vis = 1;
        while (edges != NULL)
        {
            int val1 = edges->data;
            if (edges->vis1 == 0)
            {
                edges->vis1 = 1;
                q.push(val1);
            }
            edges = edges->next;
        }
    }
    while (root != NULL)
    {
        if (root->vis == 0)
        {
            cout << "Disconnected" << endl;
            return;
        }
        root = root->nextNode;
    }
    cout << "Connected" << endl;
}

int main()
{
    int n;
    int value;
    int linkage;
    char input;
    cout << "Enter number of vertices";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value";
        cin >> value;
        createNode(value);
    }
    createEdge();

    BFS(head);
    return 0;
}
