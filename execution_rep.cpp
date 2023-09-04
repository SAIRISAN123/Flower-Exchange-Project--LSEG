#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility> //  pair

using namespace std;

void write_csv(const string &filename, vector<vector<string>> &data) {

    ofstream file(filename);

    for (auto &row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i != row.size() - 1) {
                file << ",";  // Add a comma to separate values
            }
        }
        file << "\n";  // Move to the next line for the next row
    }

    file.close();
}





int main() {
    // Make three vectors, each of length 100 filled with 1s, 2s, and 3s
    
     vector<vector<string>> data = {
        {"Name", "Age", "City"},
        {"John Doe", "30", "New York"},
        {"Jane Smith", "25", "Los Angeles"},
        {"Bob Johnson", "35", "Chicago"}
    };

    write_csv("execution_rep.csv", data);

    cout << "CSV file written successfully!" << endl;

    return 0;
    
  
}
