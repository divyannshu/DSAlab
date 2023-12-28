#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void create(int value)
{

    Node *p = new Node;

    p->data = value;

    if (head == NULL)
    {
        head = p;
        head->next = NULL;
        cout << "First ";
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        p->next = NULL;
        cout << "Node Created";
    }
}
void reverse()
{
    Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void display()
{
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    int n;
    int value;
    cout << "Enter number of elements";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value";
        cin >> value;
        create(value);
        cout << i;
    }
    cout << "Elements:" << endl;
    display();
    reverse();
    cout << "Elements in reverse order:" << endl;
    display();

    return 0;
}