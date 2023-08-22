// Prim's algo          {WEIGHTED + UNDIRECTED G}
//T.C. O(n^2)       Brute force approach
/*
    T.C. can be improved/optimized to O(nlog n) using PRIORITY QUEUE implementation
            Thus, we can fetch the minKey in O(1) in PR.Q.
*/
//S.C. O(V+E) 

#include <bits/stdc++.h>
using namespace std;
int n,e;

class Graph {
    public:
        map<int,list<pair<int,int>>> adjList;
        
        //adds an weighted edge btw vertices u and v
        void addEdge(int u, int v, int wt,bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            adjList[u].push_back(make_pair(v,wt));

            if(dir == 0)
                adjList[v].push_back(make_pair(u,wt));
        }

        //printing adj. list
        void printAdjList() {
            cout<<"\n\nAdj. list are as follows : \n";
            for(auto i:adjList) {
                cout<< i.first<< " -> ";

                for(auto j:i.second)
                    cout<<"("<<j.first<<", "<<j.second<<"), ";
                
                cout<<endl;
            }
        }


        //prim's algo
        vector< pair<pair<int,int>,int> > prims(int source) {
            //stores min. dist to ith node
            vector<int> key (n);
            //to chk if a node is included in MST or not
            vector<int> MST_visited (n);
            vector<int> parent (n);
        
            for(int i = 0; i<n; i++) {
                key[i] = INT_MAX;
                MST_visited[i] = false;
                parent[i] = -1;
            }

            //initial step to set source 
            key[source] = 0;
            parent[source] = -1;

            for(int i = 0; i<n; i++) {                      //T.C O(n^2)    Brute force                              
                //find the min key in keys(map)
                int curr_minK = INT_MAX;
                int minK_index;
                for(int i = 0; i<n; i++){                   //T.C. O(n)     to find min key
                    if(key[i] < curr_minK && MST_visited[i] != true) {
                        minK_index = i;
                        curr_minK = key[i];          //least key value
                    }
                }

                //mark min key as MSTvisited
                MST_visited[minK_index] = true;
                
                //chk its adjacent nodes
                for(auto neighbour: adjList[minK_index]){
                        int v = neighbour.first;            // its neighbour
                        int wt = neighbour.second;          // wt. for connecting edge

                        //chking if that vertex has already been parsed for MST or not
                        //if not, and the distance/wt is also lower than earlier present, 
                        //    then update it, to minimize further. 
                        if(MST_visited[v] != true && wt < key[v]) {
                            parent[v] = minK_index;
                            key[v] = wt;
                        }
                }
            }

            // returning the edges(along with wt.) in the resulting MST
            vector<pair<pair<int,int>,int>> result;
            for(int i = 1; i<n; i++){
                result.push_back({{parent[i], i}, key[i]});
                // result.push_back(make_pair( (make_pair(parent[i], i)), key[i]));
            }
            return result;
        }
};

int main()
{
    Graph g;
    cout<<"\nEnter no. of vertices and edges : ";   //  5 6
    cin>>n>>e;
    for(int i = 0; i<e; i++){
        int u,v,wt;
        cout<<"\nEdge "<<i+1<<" is between nodes with wt : ";
        // 0 3 6 0 1 2 1 3 8 1 2 3 1 4 5 4 2 7
        cin>>u>>v>>wt;
        g.addEdge(u,v,wt,0);
    }

    g.printAdjList();

    int src;
    cout<<"\nEnter source vertex : ";
    cin>>src;
    
    cout<<"\nAfter Applying Prim's Algo., we have the following edges in MST: "<<endl;
    vector<pair<pair<int,int>,int>> ans = g.prims(src);
    for(auto it: ans) 
        cout<<it.first.first<<" -> ("<<it.first.second<<", "<<it.second<<")"<<endl;
    
    return 0;
}