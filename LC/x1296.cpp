// Path crossing
//T.C. O(n)
//S.C. O(n)

#include<bits/stdc++.h>
using namespace std;

bool isPathCrossing(string path) {
    set<pair<int,int>> s;
    int x = 0, y = 0;
    s.insert({0,0});

    for(int i = 0; i < path.length(); i++) {
        if(path[i] == 'N') 
            y++;
        else if(path[i] == 'E') 
            x++;
        else if(path[i] == 'S') 
            y--;
        else
            x--;

        //chk if coord already exists in set
        if(s.count({x,y}) == 0)
            s.insert({x,y});
        else
            return true;
    }

    return false;
}

int main()
{
    string str;
    cout<<"\nEnter the directions : ";
    cin>>str;

    if(isPathCrossing(str))
        cout<<"\nPath was crossed atleast once while traversing the given path";
    else
        cout<<"\nPath NOT crossed!";
    
    return 0;
}