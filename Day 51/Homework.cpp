#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("test.txt");

    vector<int> arr;
    int x;

    while (fin >> x)
    {
        arr.push_back(x);
    }

    fin.close();
    sort(arr.begin(), arr.end());
    ofstream fout("test.txt", ios::app); // append mode
    fout << "\nSorted Array\n";

    for (int i = 0; i < 5; i++)
    {
        fout << arr[i] << " ";
    }

    fout.close();
}