//DFS for nodes present at depth of multiples of 3.
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
        vector<int> multiple3_pathlen;
        int ctr_3_pathlen = 0, depth = 0;

        void addEdge(int u ,int v, bool dir) {
            adjList[u].push_back(v);
        }

        void printAdj() {
            for(auto i : adjList) {
                cout<<i.first<<" --> ";
                for(auto j : i.second) 
                    cout<<j<<" ";
                cout<<endl;
            }
        }

        // void dfs(map<int,list<int>> &adjList, map<int,bool> &visited, vector<int> &component, int node) {
        //     component.push_back(node);
        //     visited[node] = true;

        //     for(auto neighbour:adjList[node]) {
        //         if(!visited[neighbour]){
        //             dfs(adjList,visited,component,neighbour);
        //         }
        //     }
        // }

        // vector<vector<int>> dfs_final_res(int source) {
        //     vector<int> component;         //returns pass1 component after performing DFS
        //     dfs(adjList,visited,component,source);
        //     res.push_back(component);
            
        //     //chk if any other component exists.
        //     for(auto i: adjList) {
        //         if(!visited[i.first]) {
        //             ++cc;
        //             component.clear();
        //             dfs(adjList,visited,component,i.first);
        //             res.push_back(component);
        //         }
        //     }
        //     return res;
        // }

        void dfs(map<int,list<int>> &adjList, map<int,bool> &visited, vector<int> &component, int depth,int node) {
            component.push_back(node);
            visited[node] = true;
            if(depth % 3 == 0){
                multiple3_pathlen.push_back(node);
                ctr_3_pathlen++;
            }

            for(auto neighbour:adjList[node]) {
                if(!visited[neighbour]){
                    dfs(adjList, visited, component, depth + 1, neighbour);
                }
            }
        }

        void dfs_final_res(int source) {
            vector<int> component;         //returns pass1 component after performing DFS
            dfs(adjList,visited,component,0,source);
            res.push_back(component);
            
            //chk if any other component exists.
            for(auto i: adjList) {
                if(!visited[i.first]) {
                    ++cc;
                    component.clear();
                    dfs(adjList,visited,component,depth,i.first);
                    res.push_back(component);
                }
            }
        }


        vector<int> finding_pathLenMult_3(int source) {
            dfs_final_res(source);
            return multiple3_pathlen;
        }
};

int main()
{
    int n,e;
    // bool direction;
    cout<<"\nEnter no. of Vertices and Edges : ";               // 7 8 or   9 9
    cin>>n>>e;
    // cout<<"\nGraph is : 0 undirected      1 directed :\n";      // 1
    // cin>>direction;

    Graph g;
    //adding all edges of graph
    for(int i = 0; i < e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is btw nodes : ";     
        // 0 1 1 2 2 3 2 4 1 5 4 5 5 6 3 6
        // 0 1 1 2 1 5 2 3 2 4 4 5 5 6 3 6 8 7
        cin>>u>>v;
        g.addEdge(u,v,1);
    }

    //printing adjacency list 
    cout<<"\n\nAdjacency List is as follows : \n";
    g.printAdj();
    
    int src;
    cout<<"\nEnter source node : ";
    cin>>src;
    //performing DFS for various components {if graph disconnected}
    // vector<vector<int>> ans = g.dfs_final_res(src);
    // cout<<"\n\nDFS traversal is as follows : \n";
    // int ctr = 1;
    // for(auto i:ans){
    //     cout<<"Pass "<<ctr<<" : "; 
    //     for(auto j:i){
    //         if(j == i.back()){
    //             cout<<j;
    //             break;
    //         }
    //         cout<<j<<" --> ";
    //     }
    //     ctr++;
    //     cout<<endl;
    // }

    cout<<"\n\nFollowing are the vertices present at path lengths of multiples of 3 : "<<endl;
    vector<int> mult3 = g.finding_pathLenMult_3(src);
    int count3 = g.ctr_3_pathlen;
    for(auto i : mult3)
        cout<<i<<" ";

    cout<<"\n#Paths to vertices having dist. in multples of 3 from source : "<<count3<<endl;
    
    cout<<"\n\n#Connected Components = "<<cc;
    return 0;
}