//
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int INF = 1e9+10;

//defining weighted Graph
vector<pair<int, int>> g[N];        //stored as <node, wt>


void djkstra(int source) {
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);
    
    set<pair<int,int>> st;      //stores relaxed <wt, to_node> pair obtained

    st.insert({0,source});
    dist[source] = 0;

    while (st.size() > 0)
    {
        auto node = *st.begin();        //takes out min. wt/dist from queue
        int v = node.second;
        int v_dist = node.first;

        st.erase(st.begin());
        if(vis[v])  continue;   
        vis[v] = 1;
        for(auto child : g[v]) {
            int child_v = child.first;
            int wt = child.second;

            if(dist[v] + wt < dist[child_v]){
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            } 
        }
    }
}

int main()
{
    int n,m;        //n vertices, m edges
    cout<<"\nEnter no. of Vertices and Edges : ";               // 7 8 or   9 9
    cin>>n>>m;
    cout<<"\nEnter the edges btw vertices u,v with wt. w :"<<endl;
    for(int i=0; i<m; i++) {
        int x,y,wt;
        cin>> x >> y >> wt;
        g[x].push_back({y,wt});
        //node x is connected to y with wieght wt. [Directed G]
    }

    return 0;
}