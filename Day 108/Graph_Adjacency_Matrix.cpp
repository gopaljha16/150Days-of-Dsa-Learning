// Graph Representation using Adjacency Matrix
#include <iostream>
#include <vector>
using namespace std;

// //unidirected graph unweighted graph
// int main(){
//     int vertex , edge;
//     cout<<"Enter number of vertices and edges: ";
//     cin>>vertex>>edge;

//     //adjacent matrix will be created by using the 2d array 
//     vector<vector<bool> >AdjMat(vertex , vector<bool>(vertex, 0));

//     int u , v;
//     for(int i=0 ; i<edge; i++){
//         cin>>u>>v; //this for the edge connection
//         AdjMat[u][v] = 1;
//         AdjMat[v][u] = 1;
//     }

//     //print the adjaceny matrix
//     for(int i=0 ; i<vertex ; i++){
//         for(int j=0 ; j<vertex ; j++)
//          cout<<AdjMat[i][j]<<" ";

//          cout<<endl;
//     }
// }


// //unidirected graph weighted graph
// int main(){
//     int vertex , edge;
//     cout<<"Enter number of vertices and edges: ";
//     cin>>vertex>>edge;

//     //adjacent matrix will be created by using the 2d array 
//     vector<vector<int> >AdjMat(vertex , vector<int>(vertex, 0));

//     int u , v, weight;
//     for(int i=0 ; i<edge; i++){
//         cin>>u>>v>>weight; //this for the edge connection
//         AdjMat[u][v] = weight;
//         AdjMat[v][u] = weight;
//     }

//     //print the adjaceny matrix
//     for(int i=0 ; i<vertex ; i++){
//         for(int j=0 ; j<vertex ; j++)
//          cout<<AdjMat[i][j]<<" ";

//          cout<<endl;
//     }
// }



// //directed unweighted  graph
// int main(){
//     int vertex , edge;
//     cout<<"Enter number of vertices and edges: ";
//     cin>>vertex>>edge;

//     //adjacent matrix will be created by using the 2d array 
//     vector<vector<bool> >AdjMat(vertex , vector<bool>(vertex, 0));

//     int u , v;
//     for(int i=0 ; i<edge; i++){
//         cin>>u>>v; //this for the edge connection
//         AdjMat[u][v] = 1; // directed graph so ony one driection 

//     }

//     //print the adjaceny matrix
//     for(int i=0 ; i<vertex ; i++){
//         for(int j=0 ; j<vertex ; j++)
//          cout<<AdjMat[i][j]<<" ";

//          cout<<endl;
//     }
// }


//directed weighted graph
int main(){
    int vertex , edge;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertex>>edge;

    //adjacent matrix will be created by using the 2d array 
    vector<vector<int> >AdjMat(vertex , vector<int>(vertex, 0));

    int u , v , weight; 
    for(int i=0 ; i<edge; i++){
        cin>>u>>v>>weight; //this for the edge connection
        AdjMat[u][v] = weight; // directed graph so ony one driection 

    }

    //print the adjaceny matrix
    for(int i=0 ; i<vertex ; i++){
        for(int j=0 ; j<vertex ; j++)
         cout<<AdjMat[i][j]<<" ";

         cout<<endl;
    }
}