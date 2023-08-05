#include<iostream>
#include<vector>
using namespace std;
int flag = 0;

void chk(int x, int y)
{
    if (x == 0 && y == 0)
        flag = 1;
    else if (x == 1 && y == 2)
        flag = 1;
    else if(x == 2 && y == 1)
        flag = 1;    
    else if(x >= y && x>=0 && y>=0)
        chk(x-2,y-1);
    else if(x < y && x>=0 && y>=0)
        chk(x-1,y-2);    
}

int main()
{
    int a,b,t;
    std::vector<string> final;
    string res;
    //cout<<"Enter no. of test-cases : ";
    cin>>t;
    for(int i = 0; i<t; i++)
    {
        //cout<<"\nEnter values a,b : \t";
        cin>> a >> b;
        flag = 0;
        chk(a,b);
        if(flag == 0)
            res = "NO";
        else
            res = "YES";

        final.push_back(res);
    }

    for(int i = 0; i < final.size(); i++) {
        cout << final[i] << "\n";
    }
    
    return 0;
}