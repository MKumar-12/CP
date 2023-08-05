//Listing Primes <= n
//T.C. O(n loglog n)
//S.C. O(n)

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool isPrime(int x) {                           //T.C. x3 times faster O( sqrt(n) )
    if(x== 2 || x == 3)
        return true;
    if(x%2 == 0 || x%3 == 0)
        return false;
    for(int i = 5; i<=sqrt(x);i+=6)
    {
        if(x%i == 0 || x%(i+2) == 0)
            return false;
    }  
    return true;  
}

void displayPrimes(int n) {                       //Naive soln. T.C. O(n/2 * sqrt(n)) ~ O(n * sqrt(n))
    if(2<= n)
        cout<<"2 ";
    for(int i = 3; i<=n; i+=2){
        if(isPrime(i))
            cout<<i<<" ";
    }
}

void sieve_algo(int n) {
    vector<bool> prime_status(n+1,true);
    for(int i = 2; i<=sqrt(n); i++)
    {
        if(prime_status[i]){
            for(int j = 2*i; j<=n; j+=i)
                prime_status[j] = false;
        }
    }

    for(int i = 2; i<=n; i++)
    {
        if(prime_status[i])
            cout<<i<<" ";
    }
}

void sieve_algo_optimized(int n) {                      //T.C. O(n loglogn)
    vector<bool> prime_status(n+1,true);
    for(int i = 2; i<=n; i++)
    {
        if(prime_status[i]){ 
            cout<<i<<" ";                   
            for(int j = i*i; j<=n; j+=i)            
            //starts loops from i^2 than 2i as other no. have been included earlier hand 
                prime_status[j] = false;
        }
    }
}

int main()
{
    int n;
    bool res;
    cout<<"Enter a no. : ";
    cin>>n;
    cout<<"Following are the primes <= "<<n<<" : \t";
    if(n <= 1)
        cout<<"None Exists";
    else
        // displayPrimes(n);
        // sieve_algo(n);
        sieve_algo_optimized(n);
    return 0;
}