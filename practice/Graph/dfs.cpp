//DFS
//T.C. O(V+E)
//S.C. O(V+E)

#include <bits/stdc++.h>
using namespace std;
int cc = 1;
            

class Graph {
    public:
        map<int,list<int>> adjList;
        map<int,bool> visited; 
        vector<vector<int>> res;

        void addEdge(int u ,int v, bool dir) {
            adjList[u].push_back(v);
            
            if(!dir)
                adjList[v].push_back(u);
        }

        void printAdj() {
            for(auto i : adjList) {
                cout<<i.first<<" --> ";
                for(auto j : i.second) 
                    cout<<j<<" ";
                cout<<endl;
            }
        }

        void dfs(map<int,list<int>> &adjList, map<int,bool> &visited, vector<int> &component, int node) {
            component.push_back(node);
            visited[node] = true;

            for(auto i:adjList[node]) {
                if(!visited[i]){
                    dfs(adjList,visited,component,i);
                }
            }
        }

        vector<vector<int>> dfs_final_res(int source) {
            vector<int> component;         //returns pass1 component after performing DFS
            dfs(adjList,visited,component,source);
            res.push_back(component);
            
            //chk if any other component exists.
            for(auto i: adjList) {
                if(!visited[i.first]) {
                    ++cc;
                    component.clear();
                    dfs(adjList,visited,component,i.first);
                    res.push_back(component);
                }
            }
            return res;
        }
};

int main()
{
    int n,e;
    bool direction;
    cout<<"\nEnter no. of Vertices and Edges : ";               // 7 8 or   9 9
    cin>>n>>e;
    cout<<"\nGraph is : 0 undirected      1 directed :\n";      // 1
    cin>>direction;

    Graph g;
    //adding all edges of graph
    for(int i = 0; i < e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is btw nodes : ";     
        // 0 1 1 2 2 3 2 4 1 5 4 5 5 6 3 6
        // 0 1 1 2 1 5 2 3 2 4 4 5 5 6 3 6 8 7
        cin>>u>>v;
        g.addEdge(u,v,direction);
    }

    //printing adjacency list 
    cout<<"\n\nAdjacency List is as follows : \n";
    g.printAdj();
    
    int src;
    cout<<"\nEnter source node : ";
    cin>>src;
    //performing DFS for various components {if graph disconnected}
    vector<vector<int>> ans = g.dfs_final_res(src);
    cout<<"\n\nDFS traversal is as follows : \n";
    int ctr = 1;
    for(auto i:ans){
        cout<<"Pass "<<ctr<<" : "; 
        for(auto j:i){
            if(j == i.back()){
                cout<<j;
                break;
            }
            cout<<j<<" --> ";
        }
        ctr++;
        cout<<endl;
    }

    cout<<"\n\n#Connected Components = "<<cc;
    return 0;
}