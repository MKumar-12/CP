//Adj. list of a graph [Suitable for sparse graph]
//T.C. O(V+2E) or       O(V+E)
//S.C. 

#include<iostream>
#include<unordered_map>
#include<list>
//#include<map>
using namespace std;

class Graph {
    public:
        //map<int,list<int>> adj;
        unordered_map<int,list<int>> adj;
        
        //adds edge btw vertices u and v
        void addEdge(int u, int v, bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            adj[u].push_back(v);

            if(dir == 0)
                adj[v].push_back(u);
        }

        void printAdjList() {
            cout<<"\n\nAdj. list are as follows : \n";
            for(auto i:adj) {
                cout<< i.first<< "-> ";
                for(auto j:i.second)
                    cout<<j<<", ";
                
                cout<<endl;
            }
        }
};

int main()
{
    int n,m;
    bool direction;
    cout<<"\nEnter no. of vertices : ";
    cin>>n;
    cout<<"\nEnter no. of edges : ";
    cin>>m;
    cout<<"\nGraph directed? 1: yes 0:no \n"; 
    cin>>direction;

    Graph g;
    for(int i = 0; i<m; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        cin>>u>>v;
        g.addEdge(u,v,direction);
    }

    g.printAdjList();

    return 0;
}