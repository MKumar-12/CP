//Cycle Detection in Directed Graph using DFS

/*
    suppose we start DFS from src,
        we reach to an imm. node    {having an edge back to src}
        then,
            while traversing neighbours of imm. node,
                visited[true] && dfs_visit_active[true]  => CYCLE exists
*/
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;
int cc = 1;

class Graph {
    public:
        map<int,list<int>> adjList;
        map<int,bool> visited;
        map<int,bool> dfs_active_visit;         //stores the list of active nodes in current DFS call.
        // seperates out the cycle condition in directed G.
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

        void dfs(map<int,list<int>> &adjList, map<int,bool> &visited, map<int,bool> &dfs_active_visit,vector<int> &component, int node) {
            component.push_back(node);
            visited[node] = true;
            dfs_active_visit[node] = true;

            for(auto neighbour:adjList[node]) {
                if(!visited[neighbour]){
                    dfs(adjList,visited,dfs_active_visit,component,neighbour);
                }
                //visited == true and dfs_active_visit is also TRUE
                // => CYCLE exists.
                else if(dfs_active_visit[neighbour] == true) {
                    cycle = true;
                }
            }
            dfs_active_visit[node] = false;
        }

        vector<vector<int>> dfs_final_res(int source) {
            vector<int> component;         
            //returns pass1 component after performing DFS
            dfs(adjList,visited,dfs_active_visit,component,source);
            res.push_back(component);
            
            //chk if any other component exists.
            for(auto i: adjList) {
                if(!visited[i.first]) {
                    ++cc;
                    component.clear();
                    dfs(adjList,visited,dfs_active_visit,component,i.first);
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
    cout<<"\nEnter no. of vertices and edges : ";   //  8 9
    cin>>n>>e;
    // cout<<"\nIs Graph directed? 1 yes 0 no : "<<endl;
    // cin>>direction;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        // 1 2 2 4 2 3 4 5 5 6 3 8 8 7 3 7 4 6
        cin>>u>>v;
        g.addEdge(u,v,1);
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