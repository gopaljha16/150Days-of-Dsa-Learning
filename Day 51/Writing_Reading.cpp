#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream fout;
    fout.open("z1.txt");
    fout<<"Hello world\n";
    fout<<"Hello bhai\n";
    fout<<"Hello Gopal\n";
 
    fout.close();
     
    // reading
    ifstream fin ;
    fin.open("z1.txt");
    string line;
    while(getline(fin , line)){ //here it will read full line and print it and loop will break until it reads all the lines
        cout<<line<<endl;
    }

    fin.close();
}