#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "GroceryStore.h"

using namespace std;

void getNumberAisles(string fileName){
    //TODO: Figure out how to count number of aisles
    //create the input file stream
    ifstream inFile;
    //open the specified file
    inFile.open(fileName);
    //variable to store the line we are reading
    string line;
    while(!inFile.eof()){
        getline(inFile, line);
        //process the line if it is not empty
        if (line != ""){
            cout << "Line Parsed: " << line << endl;
        }//end if
    }//end while
    //close the file stream
    inFile.close();
}

int main() {
    cout << "Grocery Store Test" << endl;
    cout << "-------------" << endl;
    cout << "Parsing Kroger.csv...: " << endl;
    getNumberAisles("stores/Kroger.csv");
    //cout << "Parsing Marsh.csv...: " << endl;
    //getNumberAisles("Marsh.csv");
    //cout << "Number of Aisles (Marsh): " << countAisles("Marsh.csv") << endl;

    GroceryStore* store = new GroceryStore("Kroger", 3);
    cout << "Added? " << store->getAisle(0)->addCategory("Hello") << endl;
    cout << "Added? " << store->getAisle(0)->addCategory("Hello") << endl;
    cout << "Added? " << store->getAisle(1)->addCategory("World") << endl;
    store->getAisle(2)->addCategory("Lol");
    store->getAisle(2)->addCategory("Test");

    //aisles[0].addCategory("Test");
    cout << store->toString() << endl;
    return 0;
}
