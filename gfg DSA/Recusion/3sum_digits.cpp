//Sum of digits of no.
//T.C. theta(digits)
//S.C. theta(d)

#include<iostream>
using namespace std;

int sum_digits(int n) {
    if(n == 0)
        return 0;
    return (n%10) + sum_digits(n/10);
} 

int main()
{
    int n;
    cout<<"\nEnter a no. : ";
    cin>>n;
    cout<<"\nSum of digits of "<<n<<" is : \t"<<sum_digits(n);
    return 0;
}