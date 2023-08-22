//Topological Sort  [using BFS]     Kahn's Algo. 
/*
    linear ordeing of vetices s.t. for every edge u -> v,
        u always appears before v in that ordering 
*/
//Can only be applied to DAGs {i.e., cant be applied if cycle exists.}

//If any valid topological order cant be obtained   =>  CYCLE exists.

//Used in DBMS : Transaction dependency for ViewS and ConflictS Precedence graphs 

/*
    1st calc. indegree of all vertices.

    add the node with 0 indegree to ans/stack.
        Chk its neighbour, 
        i.e.,   Reduce their indegree by 1
    Now repeat these steps untill stack gets emptied. {all vertices visited}
*/

//T.C. O(V+E)
//S.C. O(V+E)

#include <bits/stdc++.h>
using namespace std;
int n,e;
    

class Graph {
    public:
        int node_count = 0;
        unordered_map<int,vector<int>> adjList;
        unordered_map<int,bool> visited;
        vector<int> inDegree;
        vector<vector<int>> ans;
        
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
                cout<< i.first<< "-> ";

                for(auto j:i.second)
                    cout<<j<<", ";
                
                cout<<endl;
            }
        }

        void calc_inDegree(unordered_map<int,vector<int>> &adjList,vector<int> &inDegree) {
            cout<<endl;
            inDegree.resize(n);
            for(auto i:adjList) {
                for(auto neighbour:i.second) {
                    inDegree[neighbour]++;
                }
            }

            cout<<"\nIndegrees of vertices are as follows : "<<endl;
            for(int i=0;i<n;i++) {
                cout<<inDegree[i]<<" ";
            }

        }

        vector<int> topoSort() {
            calc_inDegree(adjList,inDegree);

            vector<int> topo_order;
            
            queue<int> q;

            //pushing all SOURCE nodes into Queue initially.
            for(auto i:adjList) {
                if(inDegree[i.first] == 0)
                {
                    // cout<<i.first<<" ";
                    q.push(i.first);
                }
            }
            
            while(!q.empty()){
                node_count++;
                int node = q.front();
                topo_order.push_back(node);
                q.pop();

                for(auto neighbour:adjList[node]){
                    inDegree[neighbour]--;
                    //pushing any of nodes neighbor if their indegree == 0,
                    //  after removing currrent node
                    if(inDegree[neighbour] == 0){
                        q.push(neighbour);
                        // topo_order.push_back(neighbour);
                    }    
                }
            }
            return topo_order;
        }
};

int main()
{
    Graph g;
    cout<<"\nEnter no. of vertices and edges : ";   //  6 7     or  9 9     or  6 5
    cin>>n>>e;
    //considering vertices are numbered starting from 0
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        //  0 1 0 2 1 3 2 3 5 3 3 4 4 5                     cycle
        //  0 1 1 4 1 3 3 8 3 6 8 4 4 7 6 7 5 2             no cycle
        //  0 1 0 2 1 3 2 3 5 4                             no cycle
        cin>>u>>v;
        g.addEdge(u,v,1);
    }

    g.printAdjList();

    vector<int> ans2 = g.topoSort();
    if(n == g.node_count) {
        cout<<"\n\nGraph doesnt contains any cycle.";
        
        cout<<"\n\nFollowing is the valid topological order :"<<endl;
        for(auto i:ans2) {
            if(i == ans2.back()){
                cout<<i;
                break;
            }
            cout<<i<<" ";
        }
    }

    else 
        cout<<"\n\nGraph contains cycle! Topological order cant be defined.";

    return 0;
}