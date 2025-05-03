#include <iostream>
#include <fstream>
using namespace std;

int main(){

    //  file opening 
    ofstream fout; //here ofsream is a class and fout is it's object
    fout.open("zoom.txt"); //here .open in this we have to give the path which you want to open if the path is not there then it will create the zoom.txt file

    // data writing 
    fout<<"Hello India";

    // closing the file the resources will be released which handles the files
    fout.close();
}