#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::vector<int> v1;
    for(int i = 0; i< 17; i++){
        v1.push_back(i);
        cout<<"\nVector size : "<<v1.size()<<" \tCapacity : "<<v1.capacity()<<" \tAddr. : "<<v1.data();
    }
    return 0;
}