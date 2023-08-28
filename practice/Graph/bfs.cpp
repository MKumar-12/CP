//BFS traversal - any order

//insert src node into queue
//remove it from queue 
//mark it VISITED
//print the node onto screen.
//push its neighbors onto stack using adj. list [if NOT visited already]
//  repeat until !queue.empty()


//repeat same if any node remains UNVISITED from visited queue. {in case of forest}

/*
    Might cause more no. of BFS calls than actual no. of cc exists
        >> because we're using unordered map, 
            also
                we must apply BFS in topological order.
*/

//T.C. O(V+2E) or       O(V+E)
//S.C. 

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;
int n,e;

class Graph {
    public:
        unordered_map<int,list<int>> adjlist;         //saves the edge connections of a vertex.
        vector<int> component;
        vector<vector<int>> ans;                    //returns BFS traversal
        unordered_map<int,bool> visited;    //maintains status of nodes being traversed or not
        //initially all values set as FALSE

        //adds edge btw vertices u and v
        void addEdge(int u, int v, bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            adjlist[u].push_back(v);

            if(dir == 0)
                adjlist[v].push_back(u);
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
        void traverse(unordered_map<int,list<int>> &adjlist,unordered_map<int,bool> &visited,vector<int> &component, int node) {
            queue<int> q;
            q.push(node);
            visited[node] = true;

            while(!q.empty()){
                int FirstNode = q.front();
                component.push_back(FirstNode);
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


        //running BFS traversal for nodes in the connected component {for undirected G mostly}
        // isolated node gets skipped
        // {to avoid this, count for }

        /*
            in case of directed graph,
                if we dont provide the src as SOURCE SCC, 
                    then only nodes reachable from src actually represents the BFS of that node;
        */
        vector<vector<int>> bfs(int source) {
            traverse(adjlist,visited,component,source);
            ans.push_back(component);

            //to chk if any other component exists, n to run bfs on it.
            for(auto i: adjlist) {
                if(!visited[i.first]) {
                    component.clear();
                    traverse(adjlist,visited,component,i.first);
                    ans.push_back(component);
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
        //    0 1 1 2 2 3 3 5 2 4 4 6 5 6
        //    1 2 2 5 2 4 4 9 4 7 9 5 5 11 7 11
        cin>>u>>v;
        g.addEdge(u,v,direction);
    }

    g.printAdjList();

    int src;
    //Traversing vertices for BFS for diff. components (if applicable)
    cout<<"\nEnter source node : ";
    cin>>src;
    cout<<"\nBFS traversal is as follows : \n";
    vector<vector<int>> res = g.bfs(src);
    int pass = 1;
    for(auto i:res) {
        cout<<"Pass "<<pass++<<" : ";
        for(auto j:i){
            if(j == i.back()){
                cout<<j;
                break;
            }
            cout<<j<<" --> ";
        }
        cout<<endl;
    }
    
    return 0;
}