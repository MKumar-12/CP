//Djkstra's Algo.   {UNDIRECTED + WEIGHTED G}
// {for shortest path calculation}
// gives the output as shortest dist of all nodes from the source node {based on any path chosen}

//-----------------------------------SINGLE SOURCE SHORTEST PATH---------------------------------          

//T.C.  O( E logV )
//S.C.  O( V+E )

#include <bits/stdc++.h>
using namespace std;
int n,e;

class Graph {
    public:
        unordered_map<int, list<pair<int, int>>> adjList;

        //adds edge btw vertices u and v
        void addEdge(int u, int v, int wt, bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            pair<int,int> p = make_pair(v,wt);
            adjList[u].push_back(p);

            if(dir == 0){
                pair<int,int> p_rev = make_pair(u,wt);
                adjList[v].push_back(p_rev);
            }
        }


        //printing adj. list
        void printAdjList() {
            cout<<"\n\nAdj. list are as follows : \n";
            for(auto i:adjList) {
                cout<< i.first<< "-> ";

                for(auto j:i.second)
                    cout<<"("<<j.first<<", "<<j.second<<"), ";
                
                cout<<endl;
            }
        }


        vector<int> calc_shortest_dist(int source){
            vector<int> distance(n,INT_MAX);
            
            /*  dist to other nodes can be saved as SET / Priority QUEUE : <pair<int,int>>
                    where,  pair.first represetns the distance_from_src and
                            pair.second represents the curr_node
            */

            //SET to store (nodes_dist, node) from src  
            set<pair<int,int>> st;
            
            distance[source] = 0;
            st.insert(make_pair(0, source));

            while(!st.empty()) {
                //fetch top record - <distance_from_src, node>
                //min. value node is always present at begg. of SET
                auto lowest_dist_node = *(st.begin());

                int nodeDistance = lowest_dist_node.first;
                int topNode = lowest_dist_node.second;

                //remove top record
                st.erase(st.begin());

                //traverse on its neighbour
                // to reval their dist. (if reqd.), assuming topNode as src     [RELAXATION]
                for(auto neighbour: adjList[topNode]){
                    if(nodeDistance + neighbour.second < distance[neighbour.first]) {
                        //lesser dist. path available

                        auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));
                        
                        // removing any prev existing record
                        if(record != st.end())    
                            st.erase(record); 
                        
                        //updating distance, n pushing it into SET
                        distance[neighbour.first] = nodeDistance + neighbour.second;
                        st.insert(make_pair(distance[neighbour.first], neighbour.first));
                    }
                }
            }

            return distance;
        }
};

int main()
{
    Graph g;
    cout<<"\nEnter no. of vertices and edges : ";   //  4 5     or      5 7
    cin>>n>>e;
    for(int i = 0; i<e; i++){
        int u,v,wt;
        cout<<"\nEdge "<<i+1<<" is between nodes with wt : ";
        // 0 1 5 0 2 8 1 2 9 1 3 2 2 3 6
        // 0 2 1 0 1 7 0 3 2 2 1 3 1 4 1 1 3 5 4 3 7
        cin>>u>>v>>wt;
        g.addEdge(u,v,wt,0);
    }

    g.printAdjList();

    int src;
    cout<<"\nEnter source node : ";
    cin>>src;
    
    vector<int> dist = g.calc_shortest_dist(src);
    cout<<"\n\nNodes dist. to src is as follows : "<<endl;
    for(auto i: dist) {
        cout<<i<<" ";
    }
    
    return 0;
}