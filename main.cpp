#include <iostream>
#include <string.h>

#include "rand_value.h"
#include "high_scores.h"
using namespace std;


int main(int argc, char *argv[]) {
    string high_scores_filename = "high_scores.txt";
    int maxNum=100;
    int level = 0;
    if (argc > 1) {
        if ( ( strcmp(argv[1], "-max") == 0) && (argc == 3)) {
            maxNum = atoi(argv[2]);
        }
        else if (strcmp(argv[1], "-table") == 0) {
            show_table(high_scores_filename, 3);
            return 0;
        }
        else if ((strcmp(argv[1], "-level") == 0) && (argc == 3)) {
            level = atoi(argv[2]);
            if ((level <= 0 ) || (level > 3)) {
                cout << "Error -- no such level";
            return -1;
            }
            switch(level) {
            case 1:
                maxNum = 10;
                break;

            case 2:
                maxNum = 50;
                break;

            case 3:
                maxNum = 100;
                break;
            }
        }
    }

    string userName;
    cout << "> guess the number " << endl;
    cout << "Hi! Enter your name, please:" << endl;
    cin >> userName;

    const int maxVal = get_rand_value(maxNum);
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
    write_new_high_scores(high_scores_filename, userName, count);

    int mode=3;
    //mode=0 - обычный вывод
    //mode=3 - доп. задание три

    show_table(high_scores_filename, mode);


    return 0;
}
