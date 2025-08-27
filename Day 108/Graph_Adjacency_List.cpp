#include <iostream>
#include <vector> 
using namespace std;

// // Unidirected unweighted graph
// int main(){
//     int vertex, edges;
//     cout<<"Enter your vertex and edges :- ";
//     cin>>vertex>>edges;
//     //adjacency list
//     vector<int>AdjList[vertex];

//     int u,v;// for the edges 
//     for(int i=0 ;i<edges; i++){
//         cin>>u>>v;
//         AdjList[u].push_back(v);
//         AdjList[v].push_back(u);
//     }

//     //printing 
//     for(int i=0 ; i<vertex ; i++){
//         cout<<i<<" -> ";
//         for(int j=0 ; j<AdjList[i].size() ; j++)
//            cout<<AdjList[i][j]<<" ";

//         cout<<endl;
//     }
// }

// // Unidirected weighted graph
// int main(){
//     int vertex, edges;
//     cout<<"Enter your vertex and edges :- ";
//     cin>>vertex>>edges;
//     //adjacency list
//     vector<pair<int,int> >AdjList[vertex];

//     int u,v, weight;// for the edges 
//     for(int i=0 ;i<edges; i++){
//         cin>>u>>v>>weight;
//         AdjList[u].push_back(make_pair(v , weight));
//         AdjList[v].push_back(make_pair(u , weight));
//     }

//     //printing 
//     for(int i=0 ; i<vertex ; i++){
//         cout<<i<<" -> ";
//         for(int j=0 ; j<AdjList[i].size() ; j++)
//         // here first is the row and seconds is the edges
//            cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<" "; 

//         cout<<endl;
//     }
// }

// //directed unweighted graph
// int main(){
//     int vertex, edges;
//     cout<<"Enter your vertex and edges :- ";
//     cin>>vertex>>edges;
//     //adjacency list
//     vector<int>AdjList[vertex];

//     int u,v;// for the edges 
//     for(int i=0 ;i<edges; i++){
//         cin>>u>>v;
//         AdjList[u].push_back(v);
//     }

//     //printing 
//     for(int i=0 ; i<vertex ; i++){
//         cout<<i<<" -> ";
//         for(int j=0 ; j<AdjList[i].size() ; j++)
//         // here first is the row and seconds is the edges
//            cout<<AdjList[i][j]<<" "; 

//         cout<<endl;
//     }
// }

// directed weighted graph
int main(){
    int vertex, edges;
    cout<<"Enter your vertex and edges :- ";
    cin>>vertex>>edges;
    //adjacency list
    vector<pair<int,int> >AdjList[vertex];

    int u,v, weight;// for the edges 
    for(int i=0 ;i<edges; i++){
        cin>>u>>v>>weight;
        AdjList[u].push_back(make_pair(v , weight));
    }

    //printing 
    for(int i=0 ; i<vertex ; i++){
        cout<<i<<" -> ";
        for(int j=0 ; j<AdjList[i].size() ; j++)
        // here first is the row and seconds is the edges
           cout<<AdjList[i][j].first<<" "<<AdjList[i][j].second<<" "; 

        cout<<endl;
    }
}