#include <iostream>
using namespace std;

int arr[100] = {3, 8, 40, 18, 76, 15};
int top = 6;

void display_array()
{
    for (int i = 0; i < top; i++)
    {
        cout << arr[i] << " ";
    }
}

void insert()
{

    int n;
    cout << "Enter number of elements to be inserted: ";
    cin >> n;
    while (n != 0)
    {
        cout << "Enter the element: ";
        cin >> arr[top];
        top++;
        n--;
    }
    display_array();
}

void delete_()
{
    int index_no;
    cout << "Enter Index Number of Element to be Removed :";
    cin >> index_no;
    for (int i = index_no; i < 100; i++)
    {
        arr[i] = arr[i + 1];
    }
    display_array();
}

void search()
{
    int input;
    cout << "Enter Number to be Searched :";
    cin >> input;
    for (int i = 0; i < 100; i++)
    {
        if (arr[i] == input)
            cout << "Element Found at Index Number : " << i << endl;
    }
    display_array();
}
void sort()
{
    for (int pass = 0; pass < top - 1; pass++)
    {
        for (int i = 0; i < top - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    cout << "Sorted Array : ";
    display_array();
}

int main()
{
    while (1)
    {
        int choice;
        cout << "Enter a number from 1 to 4: \nInsert Operation : 1 \nDelete Operation : 2 \nSearch Operation : 3 \nSort Operation: 4\nDisplay Array: 5 \nExit : 0\nEnter:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete_();
            break;
        case 3:
            search();
            break;
        case 4:
            sort();
            break;

        case 5:
            display_array();
            break;
        case 0:
            exit(1);
            break;
        }
        cout << endl;
    }
    return 0;
}