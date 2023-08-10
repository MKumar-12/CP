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
int cc = 1;

class Graph {
    public:
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

        void bfs(unordered_map<int,vector<int>> &adjList, unordered_map<int,bool> &visited, vector<int> &component, int node){
            visited[node] = true;
            
            queue<int> q;
            q.push(node);
            
            while(!q.empty()){
                int frontNode = q.front();
                component.push_back(frontNode);
                q.pop();

                for(auto neighbour:adjList[frontNode]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
        }

        //To handle disconnected componenets 
        vector< vector<int> > bfs_final(int src) {
            vector<int> component;
            bfs(adjList,visited,component,src);
            ans.push_back(component);

            for(auto i:adjList) {
                if(!visited[i.first]) {
                    ++cc;
                    component.clear();
                    bfs(adjList,visited,component,i.first);
                    ans.push_back(component);
                }
            }
            return ans;
        }

        void calc_inDegree(unordered_map<int,vector<int>> &adjList,vector<int> &inDegree) {
            cout<<endl;
            for(auto i:adjList) {
                cout<< i.first<< " -> ";
                for(auto neighbour:i.second) {
                    cout<<neighbour<<", ";
                    inDegree[neighbour]++;
                }
                cout<<endl;
            }

            cout<<"\nIndegrees of vertices are as follows : "<<endl;
            for(auto i:inDegree) {
                cout<<i<<" ";
            }

        }

        vector<int> topoSort() {
            calc_inDegree(adjList,inDegree);

            vector<int> topo_order;
            
            queue<int> q;
            for(auto i:adjList) {
                if(inDegree[i.first] == 0)
                    q.push(i.first);
            }
            
            topo_order.push_back(q.front());
            
            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto neighbour:adjList[node]){
                    inDegree[neighbour]--;
                    if(inDegree[neighbour] == 0){
                        q.push(neighbour);
                        topo_order.push_back(neighbour);
                    }    
                }
            }

            return topo_order;
        }
};

int main()
{
    Graph g;
    int n,e;
    bool direction;
    cout<<"\nEnter no. of vertices and edges : ";   //  6 7     or  9 9     or  6 5
    cin>>n>>e;
    cout<<"\nIs Graph directed? 1 yes 0 no : "<<endl;
    cin>>direction;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        //  1 2 1 3 2 4 3 4 4 6 4 5 5 6
        //  1 2 2 5 2 4 4 9 4 7 9 5 5 11 7 11 6 3
        //  1 2 1 3 2 4 3 4 6 5
        cin>>u>>v;
        g.addEdge(u,v,direction);
    }

    g.printAdjList();

    int src,ctr = 1;
    cout<<"\nEnter source vertex : ";
    cin>>src;
    vector< vector<int> > ans = g.bfs_final(src);
    
    cout<<"\n\nBFS traversal of the graph is as follows :"<<endl;
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