//Max no. of carpets that can be placed 
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t>0) {
	    ll l,b;
	    cin>>l>>b;
	    
	    ll n;
	    cin>>n;
	    
	    ll x,y;
	    vector<pair<int,int>> dim;
	    for(ll i = 0; i<n; i++){
	        cin>>x>>y;
	        dim.push_back(make_pair(x,y));
	    }
	    
	    ll sum = 0;
	    for(ll i = 0; i<n; i++){
	        sum += (dim[i].first/l) * (dim[i].second/b);
	    }
	    
	    cout<<sum<<endl;
	    t--;
	}
	return 0;
}

// 1 4 4 1 4 12

// O/P: 3