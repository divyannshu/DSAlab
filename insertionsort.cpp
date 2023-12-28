#include <iostream>
using namespace std;

int main()
{
    int key;
    int n;
    cout << "Number of elements";
    cin >> n;
    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter elements";
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        key = arr[i + 1];
        while (i >= 0 && key < arr[i])
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}