//Shortest path len to all vertices in a DAG {DIRECTED + WEIGHTED}

/*
    Input adj. list
    Calc. Topological sort using DFS
    Remove stk_top 1 by 1 and calc dist from stk_top to its neighbours using adj_list
*/
//T.C. O(V+E)
//S.C. O(V+E)

#include <bits/stdc++.h>
using namespace std;
int n,e;

class Graph {
    public:
        //storing adj. elements along with their weights
        unordered_map<int,list<pair<int,int>>> adjList;

        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        vector<int> component;
        vector<vector<int>> DFS_res;
        stack<int> topo;

        //adds edge btw vertices u and v
        void addEdge(int u, int v, int weight, bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph

            pair<int,int> p = make_pair(v,weight);
            adjList[u].push_back(p);

            if(dir == 0){
                pair<int,int> p_rev = make_pair(u,weight);
                adjList[v].push_back(p_rev);
            }
        }

        //printing adj. list
        void printAdjList() {
            cout<<"\n\nAdj. list are as follows : \n";
            for(auto i:adjList) {
                cout<<i.first<< " -> ";

                for(auto j:i.second)
                    cout<<"("<<j.first<<", "<<j.second<<"), ";
            
                cout<<endl;
            }
        }

        void init_DFS(int node, unordered_map<int,int> &parent, unordered_map<int,bool> &visited, unordered_map<int,list<pair<int,int>>> adjList, vector<int> &component) {
            visited[node] = true;
            component.push_back(node);
            for(auto i :adjList[node]) {
                if(!visited[i.first]){
                    parent[i.first] = node;
                    init_DFS(i.first,parent,visited,adjList,component);
                }
            }
            topo.push(node);
        }

        vector<vector<int>> DFScall(int source) {
            parent[source] = -1;
            init_DFS(source, parent, visited, adjList, component);
            DFS_res.push_back(component);

            for(auto i:adjList){
                if(!visited[i.first]){
                    component.clear();
                    parent[i.first] = -1;
                    init_DFS(i.first, parent, visited, adjList, component);
                    DFS_res.push_back(component);
                }
            }

            return DFS_res;
        }

        stack<int> topological_order(){
            return topo;    
        }

        void reval_dist(int node, unordered_map<int,list<pair<int,int>>> adjList, vector<int> &dist){
            for(auto neighbour : adjList[node]){
                if(dist[node] + neighbour.second < dist[neighbour.first])
                    dist[neighbour.first] = dist[node] + neighbour.second;
            }
        }

        vector<int> shortest_path(int source) {
            vector<int> dist (n, INT_MAX);
            dist[source] = 0;
            
            while(!topo.empty()) {
                int top = topo.top();
                topo.pop();
                
                //skip unreachable unreachable nodes if src node is not SOURCE_SCC
                //i.e., dist remains INF
                if(dist[top] != INT_MAX)
                    reval_dist(top, adjList, dist);
            }

            return dist;
        }
};

int main()
{
    Graph g;
    // bool direction;
    cout<<"\nEnter no. of vertices and edges : ";   //  5 5     or    6 9
    cin>>n>>e;
    // cout<<"\nIs Graph directed? 1 yes 0 no : "<<endl;
    // cin>>direction;
    for(int i = 0; i<e; i++){
        int u,v,wt;
        cout<<"\nEdge "<<i+1<<" is between nodes with wt : ";
        // 1 3 2 1 5 4 3 7 1 5 6 9 7 6 7
        // 0 1 5 0 2 3 1 2 2 1 3 6 2 3 7 2 4 4 2 5 2 3 4 -1 4 5 -2 
        cin>>u>>v>>wt;
        g.addEdge(u,v,wt,1);
    }

    g.printAdjList();

    int src, ctr = 1;
    cout<<"\nEnter source vertex : ";
    cin>>src;
    cout<<"\nDFS traversal is as follows : ";
    vector<vector<int>> res = g.DFScall(src);
    for(auto i : res){
        cout<<"\nPass "<<ctr<<" : ";
        for(auto j : i){
            if(j == i.back()){
                cout<<j;
                break;
            }
            cout<<j<<" --> ";
            ctr++;
        }
    }

    stack<int> order = g.topological_order();
    cout<<"\n\nTopological Order is as follows : "<<endl;
    while(!order.empty()) {
        cout<<order.top()<<" ";
        order.pop();
    }

    cout<<"\n\nParent vector is as follows : "<<endl;
    for(auto node : g.parent){
        cout<<node.first<<" : ["<<node.second<<"]"<<endl;
    }

    vector<int> path_len = g.shortest_path(src);
    cout<<"\n\nShortest distance from source vertex to other nodes are as follows : "<<endl;
    for(auto i : path_len) {
        cout<<i<<"\t";
    }

    return 0;
}