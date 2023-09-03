//BFS for nodes present at depth of multiples of 3.
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;
int n,e;

class Graph {
    public:
        map<int,list<int>> adjList;
        map<int,bool> visited;
        vector<int> indegree;                               //0 indexed

        //adds edge btw vertices u and v
        void addEdge(int u, int v, bool dir) {
            //dir = 1 -> directed graph
            //dir = 0 -> undirected graph
            adjList[u].push_back(v);
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

        //printing Indegree list
        void printInDegree() {
            indegree.resize(n);

            for(int i = 0; i < n; i++)
                indegree[i] = 0;
            
            for(auto i:adjList) {
                for(auto neighbour:i.second)
                    indegree[neighbour]++;
            }

            for(auto i:indegree)
                cout<<i<<" ";

            cout<<endl;
        }

        vector<int> bfs(int source) {
            indegree[source] = 0;
 
            queue<pair<int, int>> mod3_dist;               
            mod3_dist.push({source,0});                  // node, dist
            
            
            map<int,vector<bool>> distance;
            
            //mod 3 counter
            for(int i = 0 ; i <= 2 ; i++){
                distance[i].resize(n);
                for(int j = 0; j < n; j++)
                    distance[i][j] = false;
            }

            distance[0][0] = true;

            int crr_dist = 0;

            while(!mod3_dist.empty()){
                auto p = mod3_dist.front();
                int frontNode = mod3_dist.front().first;
                int frontDist = mod3_dist.front().second;
                mod3_dist.pop();

                cout<<"\nfrontNode & dist : "<<frontNode<<" "<<frontDist<<endl;
                for(auto neighbour : adjList[frontNode]){
                    crr_dist = 0;
                    if(indegree[neighbour] > 0){
                        cout<<"\nneighbour : "<<neighbour; 
                        indegree[neighbour]--;
                        
                        crr_dist = (frontDist + 1) % 3;
                        cout<<"\ndist : "<<crr_dist;
                        distance[crr_dist][neighbour] = true;

                        if(indegree[neighbour] == 0)                // (5,2) indegree(5) != 0
                        mod3_dist.push({neighbour, crr_dist});
                        
                        cout<<"\n\nFollowing is the dist. analysis matrix :"<<endl;
                        for(int i = 0 ; i <= 2 ; i++){
                            cout<<i<<" : ";
                            for(int j = 0; j < n; j++)
                                cout<<distance[i][j]<<" ";
                            cout<<endl<<endl;
                        }
                    }

                }              
            }

            vector<int> ans;
            for(int i = 0; i < distance[0].size(); i++) {
                if(distance[0][i] == true)
                    ans.push_back(i);
            }

            return ans;
        }
};

int main()
{
    Graph g;
    cout<<"\nEnter no. of vertices and edges : ";       //  8 8
    cin>>n>>e;
    for(int i = 0; i<e; i++){
        int u,v;
        cout<<"\nEdge "<<i+1<<" is between nodes : ";
        // 0 1 1 2 1 5 2 4 4 5 5 6 5 7 7 3
        cin>>u>>v;
        
        g.addEdge(u,v,1);
    }

    g.printAdjList();

    cout<<"\n\nAlso, Indegree of nodes is as follows :"<<endl;
    g.printInDegree();

    int src;
    cout<<"\n\nEnter source node : ";
    cin>>src;
    
    vector<int> dist3 = g.bfs(src);
    cout<<"\n\nFollowing are the nodes at the dist. {multiple of 3} from source :"<<endl;
    for(auto i: dist3)
        cout<<i<<" ";
    
    return 0;
}