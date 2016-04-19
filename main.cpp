#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "GroceryStore.h"

using namespace std;

int getNumberAisles(string fileName){
    int maxAisleNumber = -1;
    //create the input file stream
    ifstream inFile;
    //open the specified file
    inFile.open(fileName);
    //check if we successfully opened the file
    if(inFile.is_open()){
        //variable to store the line we are reading
        string line;
        //parse & ignore the first line (store name)
        getline(inFile, line);
        //parse & ignore the second line (header line)
        getline(inFile, line);
        while(!inFile.eof()){
            getline(inFile, line);
            //process the line if it is not empty
            if (line != ""){
                //cout << "Line Parsed: " << line << endl;
                //convert the line to an input stream so we can parse it individually
                istringstream iss(line);
                //variable to store parsed category
                string category;
                //variable to store parsed aisle number
                string aisleNum;
                //store the category, parse up to first comma
                getline(iss, category, ',');
                //store the aisle number, parse up to newline
                getline(iss, aisleNum);
                //cout << "category: " << category << " | aisleNum: " << aisleNum << endl;
                //now lets try to convert the parsed aisle number string to an integer
                stringstream converter;
                int parsedAisleNumber;
                converter << aisleNum;
                converter >> parsedAisleNumber;
                if (converter.fail()){
                    //we encountered a non-number aisle!
                }else{
                    //if the parsed aisle number is bigger than the max, store it
                    if (parsedAisleNumber > maxAisleNumber){
                        maxAisleNumber = parsedAisleNumber;
                    }
                }
            }//end if
        }//end while
        //close the file stream
        inFile.close();
    }else{
        cout << "Could not open file: '" << fileName << "', check the file and try again." << endl;
        return -1;
    }
    return maxAisleNumber;
}

string getStoreName(string fileName){
    string storeName = "Unknown";
    //create the input file stream
    ifstream inFile;
    //open the specified file
    inFile.open(fileName);
    //check if we have successfully opened the file
    if(inFile.is_open()){
        //we did open the file successfully
        //parse only the first line up to the new line
        string firstLine;
        //parse up to colon, don't do anything with it
        getline(inFile, firstLine, ':');
        //parse again up to the new line
        //declare the storeName variable
        getline(inFile, storeName);
        //output our store name
        //cout << "storeName->" << storeName << endl;
        inFile.close();
    }else{
        //we did not open the file successfully
    }
    return storeName;
}

int main() {
    cout << "Grocery Store Test" << endl;
    cout << "-------------" << endl;
    cout << "Parsing Kroger.qss...: " << endl;
    cout << "Number of Aisles (Kroger):" << getNumberAisles("stores/Kroger.qss") << endl;
    cout << "Store Name:" << getStoreName("stores/Kroger.qss") << endl;

    cout << "Parsing Kroger.qss...: " << endl;
    cout << "Number of Aisles (Kroger):" << getNumberAisles("stores/Marsh.qss") << endl;
    cout << "Store Name:" << getStoreName("stores/Marsh.qss") << endl;
    //cout << "Parsing Marsh.csv...: " << endl;
    //cout << "Number of Aisles (Marsh): " << getNumberAisles("stores/Marsh.csv") << endl;


//    GroceryStore* store = new GroceryStore("Kroger", 3);
//    cout << "Added? " << store->getAisle(0)->addCategory("Hello") << endl;
//    cout << "Added? " << store->getAisle(0)->addCategory("Hello") << endl;
//    cout << "Added? " << store->getAisle(1)->addCategory("World") << endl;
//    store->getAisle(2)->addCategory("Lol");
//    store->getAisle(2)->addCategory("Test");

    //aisles[0].addCategory("Test");
    //cout << store->toString() << endl;
    return 0;
}
