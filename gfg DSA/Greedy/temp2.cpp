#include <bits/stdc++.h>
#include <math.h>
#define ll long long
#define div 1000000007
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	// while(t>0) {
	//     ll n;
	//     cin>>n;
	    
	//     ll temp, max_profit = 0; 
	//     vector<ll> prices;
	//     for(ll i = 0; i<n; i++) {
	//         cin>>temp;
	//         prices.push_back(temp);
	//     }
	    
	//     sort(prices.begin(), prices.end());
	    
	//     for(ll i = n-1; i>=0; i--) {
	//         max_profit += prices[i];
	//         prices[i] = 0;
	        
	//         for(ll j = i - 1; j>=0; j--) {
	//             if(prices[j] >= 1)
	//                 prices[j] -= 1; 
	//         }
	//     }
	    
	//     cout<<(max_profit % div)<<endl;
	//     t--;
	// }

	while(t--) {
	    ll n;
	    cin>>n;
	    
	    ll temp, max_profit = 0; 
	    vector<ll> prices;
	    for(ll i = 0; i<n; i++) {
	        cin>>prices[i];
	    }
	    
	    sort(prices.begin(), prices.end(), greater<int>());		//decreasing order sorting
	    
	    for(ll i = 0; i<n; i++) {
	        max_profit += max(static_cast<ll>(0), prices[i] - i);
	    }
	    
	    cout<<(max_profit % div)<<endl;
	}
	return 0;
}
