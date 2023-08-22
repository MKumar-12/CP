//Calculation of shortest path from source node to a vertex in DIRECTED graph   {using BFS}
//T.C. O(V+E)
//S.C. O(V+E)

#include <bits/stdc++.h>
using namespace std;
int cc;

class Graph {
    public:
        unordered_map<int,list<int>> adjList;
        unordered_map<int,bool> visited;
        
        unordered_map<int,int> parent;
        vector<int> component;

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

        void traverse(unordered_map<int,list<int>> adjList,unordered_map<int,bool> &visited,unordered_map<int,int> &parent,vector<int> &component,int node){
            parent[node] = -1;
            visited[node] = true;
            cc++;
            
            queue<int> q;
            q.push(node);

            while(!q.empty()) {
                int frontNode = q.front();
                component.push_back(frontNode);
                q.pop();

                for(auto neighbour:adjList[frontNode]){
                    if(!visited[neighbour]){
                        parent[neighbour] = frontNode;
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }

        //running BFS traversal for all components of a graph
        vector<vector<int>> bfs(int source) {
            vector<vector<int>> res;
            traverse(adjList,visited,parent,component,source);
            res.push_back(component);

            //to chk if any other component exists, n to run bfs on it.
            for(auto i: adjList) {
                if(!visited[i.first]) {
                    component.clear();
                    traverse(adjList,visited,parent,component,i.first);
                    res.push_back(component);
                }
            }
            return res;
        }

        vector<int> calc_shortest_path(int src,int target) {
            vector<int> path;
            path.push_back(target);
            while(target != src) {
                target = parent[target]; 
                path.push_back(target);
            }

            //reverse the order of nodes sent to path vector
            reverse(path.begin(),path.end());

            return path;
        }
};

int main()
{
    Graph g;
    int n,e;
    // bool direction;
    cout<<"\nEnter no. of vertices and edges : ";   //  6 7
    cin>>n>>e;
    // cout<<"\nIs Graph directed? 1 yes 0 no : "<<endl;
    // cin>>direction;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        // 1 2 1 3 2 4 3 4 4 5 4 6 5 6
        cin>>u>>v;
        g.addEdge(u,v,1);
    }

    g.printAdjList();

    int src;
    int ctr = 1;
    //Traversing vertices for BFS for diff. components (if applicable)
    cout<<"\nEnter source node : ";
    cin>>src;
    cout<<"\nBFS traversal is as follows : \n";
    vector<vector<int>> res = g.bfs(src);
    for(auto i:res) {
        cout<<"Pass "<<ctr++<<" : ";
        for(auto j:i){
            if(j == i.back()){
                cout<<j;
                break;
            }
            cout<<j<<" --> ";
        }
        cout<<endl;
    }

    cout<<"\n\n#Connected Components : "<<cc;

    int target,dist;
    cout<<"\n\nEnter the target node : ";
    cin>>target;
    vector<int> path = g.calc_shortest_path(src,target);
    cout<<"\n\nMin. distance to target node = "<<path.size() - 1;

    cout<<"\n\nShortest Path to the target node is as follows : "<<endl;
    for(auto i : path) {
        if(i == path.back()) {
            cout<<i;
            break;
        }
        cout<<i<<" --> ";
    }
    return 0;
}