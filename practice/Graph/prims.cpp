// Prim's algo          {WEIGHTED + UNDIRECTED G}
//T.C. 
//S.C. 

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


        vector< pair<pair<int,int>,int> > prims(int source) {
            unordered_map<int,int> key (n,INT_MAX);
            unordered_map<int,bool> MST_visited (n);
            unordered_map<int,int> parent (n,-1);
        
            for(auto i : MST_visited) {
                i.second = false;
            }

            //initial step to set source 
            key[source] = 0;
            parent[source] = -1;

            for(int i = 0; i<n; i++) { 
                //find the min key in keys(map)
                int curr_min = INT_MAX;
                int min_index;
                for(int i = 0; i<n; i++){
                    if(key[i] < curr_min && MST_visited[curr_min] != true) {
                        min_index = i;
                        curr_min = key[i];          //least key value
                    }
                }

                //mark min key as MSTvisited
                MST_visited[min_index] = true;
                
                //chk its adjacent nodes
                for(auto neighbour: adjList[min_index]){
                        int v = neighbour.first;
                        int wt = neighbour.second;

                        if(MST_visited[v] != true && wt < curr_min) {
                            parent[v] = min_index;
                            key[v] = wt;
                        }
                }
            }

            vector<pair<pair<int,int>,int>> result;
            for(int i = 1; i<n; i++){
                result.push_back(make_pair( (make_pair(parent[i], i)), key[i]));
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
    
    cout<<"\nAfter Applying Prim's Algo. to obtain MST, we have : ";
    vector<pair<pair<int,int>,int>> ans = g.prims(src);
    
    return 0;
}