//Cycle Detection in Undirected Graph using DFS
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;
int cc = 1;

class Graph {
    public:
        map<int,list<int>> adjList;
        map<int,bool> visited;
        map<int,int> parent;
        vector<vector<int>> res;
        bool cycle = false;

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

        void dfs(map<int,list<int>> &adjList, map<int,bool> &visited, vector<int> &component, int node, int parent) {
            component.push_back(node);
            visited[node] = true;

            for(auto neighbour:adjList[node]) {
                if(!visited[neighbour]){
                    dfs(adjList,visited,component,neighbour,node);
                }
                //visited == true but not parent
                // => CYCLE exists.
                else if(neighbour != parent) {
                    cycle = true;
                }
            }
        }

        vector<vector<int>> dfs_final_res(int source) {
            vector<int> component;         
            //returns pass1 component after performing DFS
            dfs(adjList,visited,component,source,-1);
            res.push_back(component);
            
            //chk if any other component exists.
            for(auto i: adjList) {
                if(!visited[i.first]) {
                    ++cc;
                    component.clear();
                    dfs(adjList,visited,component,i.first,-1);
                    res.push_back(component);
                }
            }
            return res;
        }
};

int main()
{
    Graph g;
    int n,e;
    // bool direction;
    cout<<"\nEnter no. of vertices and edges : ";       // 9  8
    cin>>n>>e;
    // cout<<"\nIs Graph directed? 1 yes 0 no : "<<endl;   // 0
    // cin>>direction;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        // 1 2 2 3 4 5 5 6 5 7 6 8 7 8 8 9
        cin>>u>>v;
        g.addEdge(u,v,0);
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
    
    if(g.cycle)
        cout<<"\n\nCycle exists in the Graph!!";
    else    
        cout<<"\n\nGraph doesnt contains any cycle!!";

    return 0;
}