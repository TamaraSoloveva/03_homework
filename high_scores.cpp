#include "high_scores.h"
#include <vector>
#include <algorithm>

struct info{
    string userName;
    int best_score;
};

bool my_comparison(const info &a, const info &b)
{
    return a.best_score < b.best_score;
}

void count_user_records( string high_scores_filename ) {
    info s;
    bool needPush = true;
    vector<info> infoVec;
    ifstream in_file(high_scores_filename);
    while (true) {
        in_file >> s.userName;
        in_file >> s.best_score;
        in_file.ignore();
        if (in_file.fail()) {
            break;
        }
        for (unsigned long i=0; i<infoVec.size(); ++i) {
            if (s.userName.compare(infoVec.at(i).userName) == 0) {
                if (s.best_score < infoVec.at(i).best_score) {
                    infoVec.at(i).best_score = s.best_score;
                }
                needPush = false;
                break;
            }
        }
        if (needPush) infoVec.push_back(s);
        needPush = true;
    }

    std::sort(infoVec.begin(), infoVec.end(), my_comparison);



    for (unsigned long i=0; i<infoVec.size(); ++i) {
        cout << infoVec.at(i).userName << '\t' << infoVec.at(i).best_score << endl;
    }

}


int show_table( string high_scores_filename, int mode ) {
    ifstream in_file{high_scores_filename};

    if (!in_file.is_open()) {
        cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
        return -1;
    }
    cout << "High scores table:" << endl;
    if ( mode == 0) {
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
    }
    else if (mode == 3 ) {
        count_user_records( high_scores_filename );



    }
    in_file.close();
    return 0;
}


int write_new_high_scores( string high_scores_filename, string user_name, int attempts_count) {
    ofstream out_file{high_scores_filename, ios_base::app};
    if (!out_file.is_open()) {
        cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
        return -1;
    }

    // Append new results to the table:
    out_file << user_name << ' ';
    out_file << attempts_count;
    out_file << endl;

    return 0;


}
