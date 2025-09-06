// Shortest path returning problem coding ninjas moderate problem

// vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int src , int dest){
	
// 	//create the adjancy
// 	vector<vector<int>>adj(n);
// 	for(int i=0 ; i<m ; i++){
// 		//it's in the pair so we should use the first and 0th based indexing
// 		adj[edges[i].first -1].push_back(edges[i].second-1);
// 		adj[edges[i].second -1].push_back(edges[i].first-1);
// 		//unidrected so 2 way
// 	}

// 	src--;
// 	dest--; //becuase 0th based in indexing
// 	vector<int>visited(n,0); //initally visited 0
// 	queue<int>q;
// 	q.push(src);
// 	visited[src] = 1; //source is 1;

// 	//parent array 
// 	vector<int>parent(n , -1); //initally -1
    
// 	while(!q.empty()){
// 		int node = q.front();
// 		q.pop();

// 		//look all the neigbours
// 		for(int i=0 ; i<adj[node].size() ; i++){
// 			//if already visited
// 			if(visited[adj[node][i]]) 
// 			 continue; 
			
// 			//not visited update as visited
// 			visited[adj[node][i]] =1 ;

// 			//pushed that to the queue
// 			q.push(adj[node][i]);

// 			//now update the parent here the node which goes to that node will be the parent we can take as the node
// 			parent[adj[node][i]] = node; //the node which from the queue and which is not visited..
// 		}
// 	}
	
// 	//now we have to return the path so we have create the path vector
// 	vector<int>path;
//     // loop that will till the -1 dest-1 the loop should be iterated
// 	while(dest!=-1){
// 		path.push_back(dest+1); // +1 becuase here the 0th based index
// 		dest = parent[dest]; //update from dest to destintation parent node
// 	}

// 	//reverse the path 
// 	reverse(path.begin() , path.end());
// 	return path;
	
// }
