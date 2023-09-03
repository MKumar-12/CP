#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t>0) {
	    int n,k,l;
	    cin>>n>>k>>l;              // #customers = k (including us), 
	                               // we're L'th person in queue 
	    
	    int a[n];
	    for(int i = 1; i<=n; i++)
	        cin>>a[i];              // tastiness of a[i]
	    

	    //sort(a, a+n+1, greater<int>());


        // int max,swap;
        // for(int  i = 1; i<=n; i++){         // O(n^2)
        //     max = a[i]; 
        //     for(int j = i+1; j<=n; j++){
        //         if(max < a[j]){
        //             swap = max;
        //             max = a[j];
        //             a[j] = swap;
        //         }
        //     }
        //     a[i] = max;
        // }


        int key,i;
        //1-indexed
        for(int j = 2; j<=n; j++){          //Insertion Sort - O(n^2) WC
            key = a[j];
            i = j-1;
            while(i > 0 && a[i]< key ) {
                a[i+1] = a[i];
                i--;
            }
            a[i+1] = key;
        }


        cout<<"\n\nSorted arr is as follows : "<<endl;
        for(int i = 1; i<=n; i++)
	        cout<<a[i]<<" "; 
	    
        cout<<endl;

	    int init = l, sum = 0;
	    while(init <= n){
	        sum += a[init];
	        init += k;
	    }

	    cout<<sum<<endl;
	    t--;
	}
	return 0;
}

/*

1
5 3 3
8 5 9 11 49

*/