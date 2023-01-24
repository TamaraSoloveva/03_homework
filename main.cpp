#include <iostream>
#include <string.h>

#include "rand_value.h"
using namespace std;


int main() {
    string userName;
    cout << "> guess the number" << endl;
    cout << "Hi! Enter your name, please:" << endl;
    cin >> userName;

    const int maxVal = get_rand_value();
    cout << maxVal << endl;
    int inVal = 0;
    int count = 0;
    while ( inVal != maxVal ) {
        cout << "Enter your guess:" << endl;
        cin >> inVal;
        if (inVal > maxVal)
            cout << "less than " << inVal << endl;
        else if (inVal < maxVal)
            cout << "greater than " << inVal << endl;
        count++;
    }

    cout << "you win! attempts = " << count << endl;

    return 0;
}
