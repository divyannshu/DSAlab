#include <iostream>
#include <queue>
using namespace std;

struct edge
{
    edge *next;
    int data;
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
node *search(int value)
{

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
            return temp;
        temp = temp->nextNode;
    }
    return nullptr;
}
bool DFS_vis(node *Node, int parent)
{

    Node->vis = 1;
    cout << "Data:" << Node->data << endl;
    edge *edges = Node->next;
    while (edges != NULL)
    {
        int value = edges->data;
        node *temp1 = search(value);
        if (temp1->vis == 0)
        {

            if (DFS_vis(temp1, Node->data))

                return true;
        }
        else if (edges->data != parent)
            return true;
        edges = edges->next;
    }
    return false;
}
bool isCycle()
{

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->vis == 0)
            if (DFS_vis(temp, -1))
                return true;
        temp = temp->nextNode;
    }
    return false;
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

    if (isCycle())
        cout << "Cyclic Graph " << endl;
    else
        cout << "Not a cyclic graph" << endl;

    return 0;
}