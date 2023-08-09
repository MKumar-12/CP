//BFS traversal - sorted ASSCENDING order [uses SET for adj. list]

//insert src node into queue
//remove it from queue 
//mark it VISITED
//print the node onto screen.
//push its neighbors onto stack using adj. list [if NOT visited already]
//repeat same if any node remains UNVISITED from visited queue.

//T.C. O(V+2E) or       O(V+E)
//S.C. 

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
int n,e;

class Graph {
    public:
        unordered_map<int,set<int>> adjlist;        //saves the edge connections of a vertex.
        vector<int> ans;                            //returns BFS traversal
        unordered_map<int,bool> visited;            //maintains status of nodes being traversed or not
        //initially all values set as FALSE

        //adds edge btw vertices u and v
        void addEdge(int u, int v, bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            adjlist[u].insert(v);

            if(dir == 0)
                adjlist[v].insert(u);
        }

        //printing adj. list
        void printAdjList() {
            cout<<"\n\nAdj. list are as follows : \n";
            for(auto i:adjlist) {
                cout<< i.first<< "-> ";
                for(auto j:i.second)
                    cout<<j<<", ";
                
                cout<<endl;
            }
        }

        //Traversal phase
        void traverse(unordered_map<int,set<int>> &adjlist,unordered_map<int,bool> &visited,vector<int> &ans, int node) {
            queue<int> q;
            q.push(node);
            visited[node] = true;

            while(!q.empty()){
                int FirstNode = q.front();
                ans.push_back(FirstNode);
                q.pop();

                //storing elements connected to HEAD into queue, if NOT visited already.
                for(auto i:adjlist[FirstNode]) {
                    if(!visited[i]) {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }


        //running BFS traversal for all components of a graph
        vector<int> bfs(int source) {
            traverse(adjlist,visited,ans,source);

            //to chk if any other component exists, n to run bfs on it.
            for(auto i: adjlist) {
                if(!visited[i.first]) {
                    traverse(adjlist,visited,ans,i.first);
                }
            }
            return ans;
        }
};

int main()
{
    bool direction;
    cout<<"\nEnter no. of vertices : ";         //7
    cin>>n;
    cout<<"\nEnter no. of edges : ";            //7         8
    cin>>e;
    cout<<"\nGraph directed? 1: yes 0:no \n";   //0
    cin>>direction;

    Graph g;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        /*
            0 1 1 2 2 3 3 5 2 4 4 6 5 6
        
            1 2 2 5 2 4 4 9 4 7 9 5 5 11 7 11
        */
        cin>>u>>v;
        g.addEdge(u,v,direction);
    }

    g.printAdjList();


    int src;
    //Traversing vertices for BFS for diff. components (if applicable)
    cout<<"\nEnter source node : ";
    cin>>src;
    cout<<"\nBFS traversal is as follows : \n";
    vector<int> res = g.bfs(src);
    for(auto i:res) {
        if(i == res.back()){
            cout<<i;
            break;
        }
        cout<<i<<" --> ";
    }
    
    return 0;
}