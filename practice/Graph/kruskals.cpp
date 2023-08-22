//Kruskal's Algo.

/*
    Disjoint Sets
    **********************(Union by rank and path compression)***********************
        
        --> Can be used to check if given 2 vertices belong to same cc or diff
        --> Can be used to check if cycle exists in G or not
        --> Used in impl. of Kruskal's algo.
    
    2 major opr. :       
        UNION   --> for merging/combining 2 vertices belong to diff set.
                    (shorter tree is merged into the londer one)
        FIND    --> finds the parent of curr node

    *********************************************************************************

*/

//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;
int n,e;

class Graph {
    public:
        unordered_map<int,list<int>> adjList;
        
        unordered_map<int,bool> visited;
        vector<int> parent;
        vector<int> rank;
            
        
        //adds edge btw vertices u and v
        void addEdge(int u, int v, bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            adjList[u].push_back(v);

            if(dir == 0)
                adjList[v].push_back(u);
        }

        //printing adj. list
        void printAdjList() {
            cout<<"\n\nAdj. list are as follows : \n";
            for(auto i:adjList) {
                cout<< i.first<< " -> ";

                for(auto j:i.second)
                    cout<<j<<", ";
                
                cout<<endl;
            }
        }


        //initilizing parent and rank for UNION/FIND opr.
        void initilize(vector<int> &parent, vector<int> &rank) {
            for(int i = 0; i<n ; i++){
                parent[i] = i;
                rank[i] = 0;
            }
        }


        //UNION opr.
        int findParent(int node, vector<int> parent) {
            if(parent[node] == node) 
                return node;

            //Path Compression
            return parent[node] = findParent(parent[node], parent);
        }

        void unionSet(int u, int v, vector<int> parent) {
            //find parent of both nodes
            u = findParent(u, parent);
            v = findParent(v, parent);

            //if rank diff exists,   set 1 with lower rank as a child of other
            if(rank[u] < rank[v])
                parent[u] = v;
            else if(rank[u] > rank[v])
                parent[v] = u;
            else {
                parent[v] = u;              //if rank same, set anyone as parent
                rank[u]++;                  //and, inc. the rank of parent by 1 
            }
        }

        //Kruskal's Algo.
        void kruskals() {
            initilize(parent,rank);

        }
};

int main()
{
    Graph g;
    bool direction;
    cout<<"\nEnter no. of vertices and edges : ";
    cin>>n>>e;
    cout<<"\nIs Graph directed? 1 yes 0 no : "<<endl;
    cin>>direction;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        cin>>u>>v;
        g.addEdge(u,v,direction);
    }

    g.printAdjList();

    g.kruskals();
    
    return 0;
}