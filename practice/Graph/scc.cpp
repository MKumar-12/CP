//Counting #SCCs in a graph
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;
int n,e;

class Graph {
    public:
        unordered_map<int,list<int>> adjList;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        stack<int> st;
            

        //adds edge btw vertices u and v
        void addEdge(int u, int v, bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            adjList[u].push_back(v);

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


        //dfs 
        void dfs(int node, unordered_map<int,bool> &visited, stack<int> &st, unordered_map<int,list<int>> &adjList){
            visited[node] = true;

            for(auto neighbour: adjList[node]) {
                if(!visited(neighbour))
                    dfs(neighbour,visited,st,adjList);
            
            }
            st.push(node);
        }

        //topological sort
        void topo_sort(){
            
            for(int i = 0; i<n; i++){
                if(!visited[i]){
                    dfs(i, visited, st, adjList);
                }
            }
        }

        void trans() {
            unordered_map <int, list<int>> transpose;
            for 
        }
};

int main()
{
    Graph g;
    bool direction;
    cout<<"\nEnter no. of vertices and edges : ";
    cin>>n>>e;
    // cout<<"\nIs Graph directed? 1 yes 0 no : "<<endl;
    // cin>>direction;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        cin>>u>>v;
        g.addEdge(u,v,1);
    }

    g.printAdjList();
    
    return 0;
}