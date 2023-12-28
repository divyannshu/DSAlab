// #include <bits-stdc++.h>
// #include <amp.h>
// #include <bits/stdc++.h>
#include <fstream>
// #include<bits-stdc++.h>
#include <iostream>

// #include <iostream>
using namespace std;

int main()
{
    cout<<"IDHA";
    int value;
    ofstream file("number.txt");
    file.open("number.txt", ios::out | ios::app);
    int i = 0;
    while (i <= 18000)
    {
        value = rand();
        file << value;
    }
    file.close();
}
