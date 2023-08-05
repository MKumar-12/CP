//'hello world' with right aligned output in grid

#include <iostream>
#include<iomanip>
using namespace std;

int main() {

    cout << std::setiosflags(ios::left);
    //sets cout to left align, at os output

    string str = "Hello World!";
    
    for(int i = 0 ; i<6; i++)
    {
        for(int j = 0; j<4; j++)
            cout<<setw(15)<<str;
            //if setw(width_val) < actual display pixels val, then by default it'll be set to min. pixels reqd for displaying the value
        cout<<endl;
    }
    return 0;
}


