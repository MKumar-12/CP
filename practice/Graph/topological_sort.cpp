//Topological Sort  {Appl. of DFS}
/*
    linear ordeing of vetices s.t. for every edge u -> v,
        u always appears before v in that ordering 
*/
//Can only be applied to DAGs {i.e., cant be applied if cycle exists.}

//If any valid topological order cant be obtained   =>  CYCLE exists.

//Used in DBMS : Transaction dependency for ViewS and ConflictS Precedence graphs 

//T.C. O(V+E)
//S.C. O(V+E)

#include <bits/stdc++.h>
using namespace std;
int cc = 1;

class Graph {
    public:
        map<int,list<int>> adjList;
        map<int,bool> visited;
        map<int,int> parent;
        vector<vector<int>> res;
        stack<int> s;               // to store the SOURCE, SINK vertex for DFS calls-made

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

        void dfs(map<int,list<int>> &adjList, map<int,bool> &visited, vector<int> &component, int node) {
            component.push_back(node);
            visited[node] = true;

            for(auto neighbour:adjList[node]) {
                if(!visited[neighbour]){
                    dfs(adjList,visited,component,neighbour);
                }
            }

            s.push(node);
        }

        vector<vector<int>> dfs_final_res(int source) {
            vector<int> component;         
            //returns pass1 component after performing DFS
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

        vector<int> topoSort() {
            vector<int> topo_order;

            while(!s.empty()) {
                topo_order.push_back(s.top());
                s.pop();
            }

            return topo_order;
        }
};

int main()
{
    Graph g;
    int n,e;
    bool direction;
    cout<<"\nEnter no. of vertices and edges : ";   //  6 7
    cin>>n>>e;
    cout<<"\nIs Graph directed? 1 yes 0 no : "<<endl;
    cin>>direction;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        //  1 2 1 3 2 4 3 4 4 6 4 5 5 6
        cin>>u>>v;
        g.addEdge(u,v,direction);
    }

    g.printAdjList();

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

    vector<int> ans2 = g.topoSort();
    cout<<"\n\nFollowing is the valid topological order :"<<endl;
    for(auto i:ans2) {
        if(i == ans2.back()){
                cout<<i;
                break;
            }
            cout<<i<<" ";
    }
    
    return 0;
}