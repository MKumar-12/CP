//Checking validity of 3 sides of a triangle

//For every, Sum of 2 sides should be greater than the 3rd side.

#include <bits/stdc++.h>
using namespace std;
  
// function to check if three sider form a triangle or not
bool checkValidity(int a, int b, int c)
{
    // check condition
    if (a + b <= c || a + c <= b || b + c <= a)
        return false;
    else
        return true;
}
  
// Driver function
int main()
{
    int a = 17, b = 2, c = 3;
    if (checkValidity(a, b, c))
        cout << "Valid";
    else
        cout << "Invalid";
}