//Cycle Detection in Undirected Graph using BFS

//During BFS,
//for any given node :   <while adding to q>
//Neglect its adj. node    {Condition :   already visited + its parent}
//But if encountered 2nd parent having visited[true],

//That indicates CYCLE exists.  


/*
    visited[node] = true && node != parent(of current traversing node) 
*/

//Also, Track Parent(s) of a node.

//T.C. O(V+E)
//S.C. 

#include<bits/stdc++.h>
using namespace std;
int cc = 1;

class Graph {
    public:
        unordered_map<int,vector<int>> adjList;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        bool cycle = false;
        vector< vector<int> > ans; 

        void addEdge(int u, int v) {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        void printAdjList() {
            for(auto i:adjList){
                cout<<i.first<<"\t: ";
                for(auto j:i.second) 
                    cout<<j<<" ";
                cout<<endl;
            }
        }

        void isCyclicBFS(unordered_map<int,vector<int>> &adjList, unordered_map<int,bool> &visited, vector<int> &component, int node){
            parent[node] = -1;
            visited[node] = true;
            
            queue<int> q;
            q.push(node);
            
            while(!q.empty()){
                int frontNode = q.front();
                component.push_back(frontNode);
                q.pop();

                // cout<<"\n\nDebug for "<<frontNode;
                for(auto neighbour:adjList[frontNode]){
                    //chk if the parent of visited neighbour is actually the frontNode or not
                    //If NOT =>     Cycle exists
                    if(visited[neighbour] == true && neighbour != parent[frontNode]) {
                        cycle = true;
                    }
                    else if(!visited[neighbour]){
                        // cout<<"\nAdded to q, coz(adj.) '"<<i<<"' Not visited ";
                        q.push(neighbour);
                        visited[neighbour] = true;
                        parent[neighbour] = frontNode;
                    }
                }

                // cout<<"\nQueue at end of removal of "<<frontNode<<endl;
                // queue<int> temp = q;
                // if(temp.size() == 0)
                //     cout<<"(empty)";
                // else {
                //     while (!temp.empty())
                //     {
                //         cout<<temp.front()<<" ";
                //         temp.pop();
                //     }
                // }
            }
        }

        //To handle disconnected componenets 
        vector< vector<int> > bfs_final(int src) {
            vector<int> component;
            isCyclicBFS(adjList,visited,component,src);
            ans.push_back(component);

            for(auto i:adjList) {
                if(!visited[i.first]) {
                    ++cc;
                    component.clear();
                    isCyclicBFS(adjList,visited,component,i.first);
                    ans.push_back(component);
                }
            }
            return ans;
        }

};

int main()
{
    int n,e;
    cout<<"\nEnter no. of vertices and edges : ";           // 9  9     or  8 6     or  9 8
    cin>>n>>e;
    Graph g;
    for(int i = 0; i<e; i++) {
        int u,v;
        cout<<"\nEdge "<<i+1<<" is btw vertices : ";   
        // 1 2 2 5 2 4 4 9 4 7 9 5 5 11 7 11 6 3
        // 1 2 2 3 2 4 4 7 4 8 6 5
        // 1 2 2 3 4 5 5 6 5 7 6 8 7 8 8 9
        cin>>u>>v;
        g.addEdge(u,v);
    }

    cout<<"\n\nAdjacency List is as follows : "<<endl;
    g.printAdjList();

    int src,ctr = 1;
    cout<<"\nEnter source vertex : ";
    cin>>src;
    vector< vector<int> > ans = g.bfs_final(src);
    
    cout<<"\n\nBFS traversal of the graph is as follows : \n"<<endl;
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