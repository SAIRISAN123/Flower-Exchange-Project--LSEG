#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility> //  pair
#include <algorithm> // For std::remove_if and std::isspace
using namespace std;

//for splitting string to string vector array
std::vector<std::string> splitString(const std::string &input, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        // Remove extra spaces from the beginning and end of the item
        item.erase(item.begin(), std::find_if(item.begin(), item.end(), [](int ch) {
            return !std::isspace(ch);
        }));
        item.erase(std::find_if(item.rbegin(), item.rend(), [](int ch) {
            return !std::isspace(ch);
        }).base(), item.end());

        result.push_back(item);
    }
    return result;
}




vector<vector<string>> processFile(const string& filename, char delimiter) {
    vector<vector<string>> data;
    ifstream file(filename);

    // if (!file.is_open()) {
    //     cerr << "Failed to open the file." << endl;
    //     return;
    // }

    
    

    string line;
    while (getline(file, line)) {
        vector<string> values = splitString(line, delimiter);
        data.push_back(values);
        // for (const auto& value : values) {
        //     cout << value << " ";
        // }
        // cout << endl;

    }
    

    
    file.close();
    return data;
    }



vector<vector<string>> read_file (string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
     }
     
    for (int i = 0; i < 5; i++)
    {
        string line;
        getline(file,line);
        //cout<<line<<endl;
        char delimeter= ',';
        vector<string> values = splitString(line, delimeter);

        
    }
    
   //print string vector 
    
    vector<vector<string>> data; 
    data=processFile(filename, ',');
    
    

    return data;

}


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
    
    vector<vector<string>> data;
    data= read_file("Example 2.csv") ;
    data[0].insert(data[0].begin(), "Ord ID");
    data[0].insert(data[0].begin()+4, "Exec");
    
    
    for (int i = 1; i < data.size(); i++)
    { 

        data[i].insert(data[i].begin(), "Ord"+to_string(i));
        data[i].insert(data[i].begin()+4, "New"); 
        }
    




    for (int i = 2; i < data.size(); i++)
    { 

        for (int j=i-1 ; j>=0;j--) {
         
            if (( data[i][6]==data[j][6] ) && (( data[i][5]==data[j][5])) && (data[i][3] !=data[j][3])){
                
                //data[i].insert(data[i].begin(), "Ord"+to_string(i));
                
                
                data[i].erase(data[i].begin()+4);
                data[i].insert(data[i].begin()+4, "Fill"); 
                data.push_back(data[j]); 
                data[i+1].insert(data[i+1].begin()+4, "Fill");
                break;
                }



            else if (( data[i][6]==data[j][6] ) && (data[i][3] !=data[j][3]) ){
                 
                if (stoi(data[i][5]) > stoi(data[j][5])){
                    
                    int quantity=stoi(data[i][5]) -stoi(data[j][5]);
                    cout<<quantity<<endl;

                    //data[i].insert(data[i].begin(),"Ord"+to_string(i));
                    data[i].erase(data[i].begin()+4);
                    data[i].insert(data[i].begin()+4, "PFill"); 
                    data[i].erase(data[i].begin()+5);
                    data[i].insert(data[i].begin()+5, to_string(quantity)); 
                    data.erase(data.begin()+j);
                    break;

                }

                else if (stoi(data[i][5]) <  stoi(data[j][5])){
                
                
                    int quantity=stoi(data[j][5])- stoi(data[i][5]);
                    
                //data[j].insert(data[j].begin(), "Ord"+to_string(i));

                    data[j].insert(data[j].begin()+4, "PFill"); 
                    data[j].erase(data[j].begin()+5);
                    data[j].insert(data[j].begin()+5, to_string(quantity)); 
                    data.erase(data.begin()+i);
                    break;
                
                
                }  
            }

            
            
            else {  
            
            

            }
            
            
            
            
        }

        
        
    }
        
        
    

    write_csv("execution_rep.csv", data);

    cout << "CSV file written successfully!" << endl;

    return 0;


}