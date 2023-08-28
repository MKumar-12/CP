//Adj. list of a WEIGHTED graph [Suitable for sparse graph]
//T.C. O(V+2E) or       O(V+E)
//S.C. O(V+E)

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Graph {
    public:
        unordered_map<int, vector<pair<int, int>>> adj;
         
        //adds edge btw vertices u and v
        void addEdge(int u, int v, int wt,bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            adj[u].push_back({v,wt});

            if(dir == 0)
                adj[v].push_back({u,wt});
        }

        void printAdjList() {
            cout<<"\n\nAdj. list are as follows : \n";
            for(auto i:adj) {
                cout<<i.first<<" : ";
                for(auto j:i.second)
                    cout<<"("<<j.first<<", "<<j.second<<"), ";
                cout<<endl;
            }
        }
};

int main()
{
    int n,m;
    bool direction;
    cout<<"\nEnter no. of vertices and edges : ";       // 4 5
    cin>>n>>m;
    cout<<"\nGraph directed? 1: yes 0:no \n"; 
    cin>>direction;

    Graph g;
    for(int i = 0; i<m; i++){
        int u,v,wt;
        cout<<"\nEdge "<<i+1<<" is between nodes with weight : ";
        // 0 1 5 0 2 8 1 2 9 1 3 2 2 3 6
        cin>>u>>v>>wt;

        g.addEdge(u,v,wt,direction);
    }

    g.printAdjList();

    return 0;
}