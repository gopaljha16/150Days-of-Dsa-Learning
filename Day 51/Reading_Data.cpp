#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin;  // here ifstream is class and fin is object name
    
    // open the first first
    fin.open("zoom.txt");
    char c;
    // fin>>c; // it will read the file one character by character
    c = fin.get(); // it will consider all the spaces and tabs spaces.

    // loop 
    while(!fin.eof()){  // here eof means end of the file if it reaches the end of file then it returns 1 if not then it will return 0

         cout<<c; // printing the character
         c = fin.get(); // now it will giving the output as  spaces..
    }
    // HelloIndia here we have getting the output without the space basically it's ignoring the  space so we have to use the fin.get() which will consider the space and tabs space as character.

    // closing the file
    fin.close();
}