//Writing into a file
//T.C. 
//S.C. 

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    //creating an object of fstream
    fstream myFile;

    //Reading a file in write mode
    //also, if the file doesnt exists, it'll be created
    myFile.open("input.txt", ios::out);    //write

    //Writing to file
    if(myFile.is_open()){
        myFile<<"Adding context to the newly created file (if not already made)";
        myFile<<"\n\nHave a great day!!!";
        
        //close the files, once all opr. are done
        myFile.close();
    }

    
    
    //overwritting data
    // myFile.open("input.txt", ios::out);    //write

    // //Writing to file
    // if(myFile.is_open()){
    //     myFile<<"\nData modified";
    //     myFile.close();
    // }



    //Appending data
    myFile.open("input.txt", ios::app);    //append

    //Writing to file
    if(myFile.is_open()){
        myFile<<"\nHi there!";
        myFile<<"\nData appended sucessfully!!";
        myFile.close();
    }

    return 0;
}