#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Disabling synchronization and untying streams can help improve performance in scenarios 
    //  where efficiency is critical.
    
    // C++ streams will not be synchronized with C standard I/O, 
    //  which can lead to potentially faster I/O operations.
    ios_base::sync_with_stdio(false);
    
    // Setting cin.tie(0) unties cin from any stream, 
    //  which can improve the efficiency of input operations by preventing 
    //  unnecessary flushing of the output buffer before input.
    cin.tie(0);
    
    // set the precision (number of decimal places) for floating-point numbers 
    //  that will be displayed using the cout stream.
    cout.precision(2);

    int a;
    float b;
    cin >> a >> b;
    
    if ((a%5==0) && (b-a-0.5>=0))
    {
        cout << fixed << b-a-0.5 << endl;
    }
    else
    {
        cout << fixed << b << endl;
    }
    
    /*
        With fixed: When you use std::cout << fixed, 
        it tells the stream to display floating-point numbers in the "fixed-point notation",
        where the numbers are displayed in a fixed number of decimal places, 
        rather than using scientific notation. 
        i.e.,

                >>
                    double number = 1234567.8901;
                    cout<< number <<endl;               // Output: 1.23457e+06
                    cout<< fixed << number <<endl;      // Output: 1234567.890100

    */
    
    return 0;
}
