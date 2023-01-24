#include "high_scores.h"


int write_new_high_scores( string user_name, int attempts_count) {
    string high_scores_filename = "high_scores.txt";
    ofstream out_file{high_scores_filename, ios_base::app};
    if (!out_file.is_open()) {
        cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
        return -1;
    }

    // Append new results to the table:
    out_file << user_name << ' ';
    out_file << attempts_count;
    out_file << endl;

    ifstream in_file{high_scores_filename};
    if (!in_file.is_open()) {
        cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
        return -1;
    }
    cout << "High scores table:" << endl;
    string username;
    int high_score = 0;
    while (true) {
        // Read the username first
        in_file >> username;
        // Read the high score next
        in_file >> high_score;
        // Ignore the end of line symbol
        in_file.ignore();

        if (in_file.fail()) {
            break;
        }
        // Print the information to the screen
        cout << username << '\t' << high_score << endl;
    }



    return 0;


}
