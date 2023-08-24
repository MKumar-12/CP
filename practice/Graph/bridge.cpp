//Bridges in a Graph

/*
    It is an edge, 
        which if removed inc. #cc in a graph


    Brute force approach :
        For every edge,
            Try to remove it, n then run DFS to find #cc in G
            if #CC > 1,     --> its a BRIDGE edge

    Optimized way :
        For every node,
            Keep track of 4 things:
            > Discovery time
            > Earliest possible discovery time (low)
            > Parent 
            > Visited   

        for timer = 0,
            Start from src node, and update these set of values for each node we visit 
                {until we get a node in path with VISITED == true}

            obtaining a node with VISITED = true    -->     BACK-EDGE   (***CYCLE***)
                {earliest possible time of curr_node might be get better,
                *******************alternate path exists *******************}
                            
                low[curr_node] = min(low[curr_node], dis[visited_neighbour] + 1)

                also, before chking for other nodes, 
                    make a chk for if(neighbour != parent)
                        then, only perform relaxation.


        FORWARD edges can be seen as CYCLE in undriected G only,
            not in directed G
*/
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;
int n,e;

class Graph {
    public:
        unordered_map<int,list<int>> adjList;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

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
                cout<< i.first<< " -> ";

                for(auto j:i.second)
                    cout<<j<<", ";
                
                cout<<endl;
            }
        }

};

int main()
{
    Graph g;
    bool direction;
    cout<<"\nEnter no. of vertices and edges : ";
    cin>>n>>e;
    cout<<"\nIs Graph directed? 1 yes 0 no : "<<endl;
    cin>>direction;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        cin>>u>>v;
        g.addEdge(u,v,direction);
    }

    g.printAdjList();
    
    return 0;
}