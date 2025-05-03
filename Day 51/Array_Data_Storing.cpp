#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr(5);

    cout << "Enter the input";
    for (int i = 0; i < 5; i++)
        cin >> arr[i];

    ofstream fout;
    // file open
    fout.open("zero.txt");

    //    data
    for (int i = 0; i < 5; i++)
    {
        fout << arr[i] << " ";
    }

    fout.close();
}