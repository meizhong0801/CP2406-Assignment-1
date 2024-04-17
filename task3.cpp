#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "Database.h"

using namespace std;
using namespace Records;

vector<string> readData(string filename);

int main() {
    Database employeeDB;
    // read data from txt file into vectors
    vector<string> firstNames = readData("./names/firstnames.txt");
    vector<string> middleNames = readData("./names/middlenames.txt");
    vector<string> lastNames = readData("./names/lastnames.txt");
    vector<string> numbers = readData("./names/numbers.txt");
    vector<string> streetNames = readData("./names/streetnames.txt");
    vector<string> cities = readData("./names/cities.txt");

    // generate 8000 unique names and address
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            for (int k = 0; k < 20; k++) {
                string address = numbers[k] + " " + streetNames[j] + " " + cities[i];
                employeeDB.addEmployee(firstNames[i], lastNames[k], middleNames[j], address);
            }
        }
    }

    employeeDB.displayAll();
    
    return 0;
}
// read data from txt file and return vector
vector<string> readData(string filename) {
    vector<string> names;
    ifstream nameFile(filename);
    if (!nameFile.is_open()) {
        throw runtime_error {"Error while opening file."};
    }
    string line;
    while ( getline (nameFile, line) ) {
        names.push_back(line);
    }

    return names;
}