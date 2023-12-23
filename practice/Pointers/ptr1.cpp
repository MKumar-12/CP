//Intro to Pointers
//T.C. 
//S.C. 

#include<iostream>
using namespace std;

int main()
{
    int num = 4;

    cout<< "\nValue at num : " << num;
    cout<< "\nAddr. of num : " << &num;

    int* p = &num;

    //Arithmetic 
    cout<< "\n\nIncrement by 1 in 2 ways: " << endl;
    cout<< ++num << endl;
    cout<< ++(*p);

    cout<<"\nCurrent value: "<< num << endl;

    //Sizeof ptr. vs storage classes in mem.
    cout<<"\n"<<sizeof(int)<<"\t"<<sizeof(int*)<<endl;
    cout<<sizeof(char)<<"\t"<<sizeof(char*)<<endl;
    cout<<sizeof(long long int)<<"\t"<<sizeof(long long int*)<<endl;
    cout<<sizeof(float)<<"\t"<<sizeof(float*)<<endl;
    cout<<sizeof(double)<<"\t"<<sizeof(double*)<<endl;

    return 0;
}