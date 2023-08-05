//accepting input from user, n recoving if user inputs some incorrect type data
#include <iostream>
using namespace std;

int main() {
  int input_var = 0;
  
  do {
    cout << "Enter a number (-1 = quit): ";
    
    // cin returns false if an input operation fails, that is, if
    // something other than an int (the type of input_var) is entered.
    if (!(cin >> input_var)) {
        //cout << "You entered a non-numeric. Exiting..." << endl;
        //break;

        cout << "Pls re-enter NUMBER only" << endl;
        cin.clear();
        //clears the error flag from input stream

        cin.ignore(10000,'\n');
        //moves the input stream to next newline or after 10000 char. just to make sure we dont read incorrect input again from the same non-number line
    }

    if (input_var != -1) {
      cout << "You entered " << input_var << endl;
    }
  } while (input_var != -1);
  
  cout << "All done." << endl;
  return 0;
}