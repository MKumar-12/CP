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

//T.C. O(Elog E)
//S.C. O(V)

#include <bits/stdc++.h>
using namespace std;
int n,e;

class Graph {
    public:
        // AdjList is not required in Kruskal's ,i.e.,
        // can be stored in a LinearDS, where {wt u v} is stored for every edge
        // ordered by wt. ASSC.
        vector<vector<int>> edges;
        //map<int,list<pair<int,int>>> edges;
        
        vector<int> parent;
        vector<int> rank;
            
        
        //adds edge btw vertices u and v
        void addEdge(int u, int v, int wt, bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            edges.push_back({wt,u,v});
        }

        //printing adj. list
        void printEdgeList(vector<vector<int>> &edges) {
            sort(edges.begin(), edges.end());                   // Sorting T.C. O(Elog E)
            
            cout<<"\n\nEdges are as follows :\nwt : (u , v) \n\n";
            for(auto i:edges) {
                cout<<i[0]<<" : ("<<i[1]<<" , "<<i[2]<<"), "<<endl;
            }
        }

    
        //initilizing parent and rank for UNION/FIND opr.
        void initilize(vector<int> &parent, vector<int> &rank) {
            parent.resize(n);
            rank.resize(n);
            for(int i = 0; i<n ; i++){
                parent[i] = i;
                rank[i] = 0;
            }
        }


        //FIND opr.
        int findParent(int node, vector<int> parent) {                          //T.C. O(1)
            if(parent[node] == node) 
                return node;

            //Path Compression
            return parent[node] = findParent(parent[node], parent);
        }


        //UNION opr.
        void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {    //T.C. O(1)
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
        int kruskals() {
            initilize(parent,rank);
            int MinWeight = 0;

            /*  For FIND opr. on 2 vertices for each edge, 
                    parent : same   =>  both vertices are in same cc    -->  Ignore
                    else            =>  vertices exists in diff. cc     -->  MERGE
            */

           for(auto i: edges) {
                //to chk if u and v lie in same component or not
                int u = findParent(i[1], parent);
                int v = findParent(i[2], parent);
                int wt =i[0];

                //in diff component --> MERGE
                if(u != v) {
                    MinWeight += wt;
                    unionSet(u, v, parent ,rank);
                } 
           }

           return MinWeight;

        }
        
};

int main()
{
    Graph g;
    cout<<"\nEnter no. of vertices and edges : ";   //  6 9     or  5 6
    cin>>n>>e;
    //============= Vertices should be numbered from 0 =============
    for(int i = 0; i<e; i++){
        int u,v,wt;
        cout<<"\nEdge "<<i+1<<" is between nodes with wt : ";
        // 4 0 4 4 3 9 3 0 1 0 1 2 3 2 5 3 1 3 2 1 3 2 5 8 1 5 7 
        // 0 3 6 0 1 2 1 3 8 1 2 3 1 4 5 4 2 7 
        cin>>u>>v>>wt;
        g.addEdge(u,v,wt,0);
    }

    g.printEdgeList(g.edges);

    cout<<"\n\nMCST = "<<g.kruskals();

    return 0;
}