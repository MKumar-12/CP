//Insertion Sort - NA
//T.C. 
//S.C. 

#include <bits/stdc++.h>
using namespace std;
int swaps[2] = {0,0};
int comp[2] = {0,0};

void isort1(int Arr[], int n) {
    int key,i;
    //1-indexed
    for(int j = 2; j<n; j++){
        key = Arr[j];
        i = j-1;
        while(i > 0 && Arr[i]> key ) {
            comp[0]++;
            Arr[i+1] = Arr[i];
            i--;
        }
        Arr[i+1] = key;
        swaps[0]++;
    }
}

void isort2(int Arr[], int n) {
    int j;
    //0-indexed
    for(int i = 1; i<=n; i++){
        j = i-1;
        while(j > 0 && Arr[j]> Arr[i] ) {
            comp[1]++;
            j--;
        }
        for(int k = j+1; k <= i-1; k++){
            Arr[k] += Arr[i];
            Arr[i] = Arr[k] - Arr[i];
            Arr[k] = Arr[k] - Arr[i];
            swaps[1]++;
        }
    }
}

int main()
{
    int A[100],B[100],n;
    cout<<"\nEnter no. of elements : ";
    cin>>n;                                     // 6
    cout<<"Enter elements : ";                  // 1 9 2 11 7 8
    for(int i=0; i<n; i++) {
        cin>>A[i];
        B[i] = A[i];
    }
    isort1(A,n);
    cout<<"\n\n{1}Sorted arr is :\t";
    for(int i=0; i<n; i++) {
        cout<<A[i]<< " ";
    }
    cout<<"\nSwaps : "<<swaps[0]<<"\tComp: "<<comp[0];
    
    isort2(B,n);
    cout<<"\n\n{2}Sorted arr is :\t";
    for(int i=0; i<n; i++) {
        cout<<B[i]<< " ";
    }
    cout<<"\nSwaps : "<<swaps[1]<<"\tComp: "<<comp[1];
    
    return 0;
}