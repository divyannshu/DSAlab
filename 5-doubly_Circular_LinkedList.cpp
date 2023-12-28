

#include <iostream>
using namespace std;
struct Node
{
    struct data
    {
        int price;
        string type;
        string product;
    } d;
    struct Node *next;
    struct Node *prev;
};
class doublycircularLL
{
    Node *head = NULL;
    int count = 0;

public:
    void create(int price, string type, string product)
    {

        Node *p = new Node;
        count++;
        p->d.price = price;
        p->d.type = type;
        p->d.product = product;
        if (head == NULL)
        {
            head = p;
            cout << "First ";
        }
        else
        {
            Node *temp;
            temp = head;
            for (int i = 0; i < count - 1; i++)
            {
                if (i == count - 2)
                {
                    temp->next = p;
                    p->prev = temp;
                    p->next = head;
                    head->prev = p;
                }
                else
                {
                    if (temp->d.type == p->d.type)
                    {
                        p->next = temp->next;
                        temp->next->prev = p;
                        temp->next = p;
                        p->prev = temp;
                        break;
                    }
                }
                temp = temp->next;

                cout << "Node Created";
            }
        }
    }

    void dele()
    {
        string input;
        cout << "Enter type to be deleted ";
        cin >> input;
        Node *temp;
        temp = head;
        int count1 = count;

        for (int i = 0; i < count1; i++)
        {

            if (temp->d.type == input)
            {
                if (temp == head)
                {
                    head = temp->next;
                }
                else if (temp->next == head)
                {
                    temp->prev->next = head;
                    head->prev = temp->prev;
                }
                else
                {

                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                count--;
            }
            temp = temp->next;
        }
    }
    void search()
    {
        string input;
        cout << "Enter type to be searched ";
        cin >> input;
        Node *temp;
        temp = head;
        int count1 = count;
        int count2 = 0;
        for (int i = 0; i < count1; i++)
        {

            if (temp->d.type == input)
            {
                count2++;
                cout << "Price" << temp->d.price << endl;
                cout << "Type" << temp->d.type << endl;
                cout << "Product:" << temp->d.product << endl;
            }

            temp = temp->next;
        }
        if (count2 == 0)
        {
            cout << "Searched item not present" << endl;
        }
    }
    void display()
    {
        Node *temp;
        temp = head;
        for (int i = 0; i < count; i++)
        {

            cout << "Price" << temp->d.price << endl;
            cout << "Type" << temp->d.type << endl;
            cout << "Product:" << temp->d.product << endl;
            cout << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    int n;
    int price;
    string type;
    string product;
    doublycircularLL obj;

    cout << "Enter number of elements";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter price";
        cin >> price;
        cout << "Enter type";
        cin >> type;
        cout << "Enter product";
        cin >> product;
        obj.create(price, type, product);
    }
    obj.display();
    obj.dele();
    obj.display();
    obj.search();
}
