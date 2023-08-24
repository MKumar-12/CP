//Reading from a file
//T.C. 
//S.C. 

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    //creating fstream object
    fstream myFile;

    //Reading from a file
    myFile.open("input.txt", ios::in);      //read
    if(myFile.is_open()){
        string line;

        //obtains line 1 by 1 until we reach EOF
        while (getline(myFile, line)) {
            cout<<line<<endl;
        }
        myFile.close();
    }

    else
        cout<<"\nFailed to open the file!!"<<endl;

    return 0;
}