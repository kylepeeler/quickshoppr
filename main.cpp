#include <iostream>
#include <fstream>
#include <sstream>
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

GroceryStore* loadStoreFromFile(string fileName){
    //create the store
    GroceryStore* store = new GroceryStore(getStoreName(fileName), getNumberAisles(fileName));
    //iterate through all of the aisles and add each category
    //create the input file stream
    ifstream inFile;
    //open the specified file
    inFile.open(fileName);
    //check if we successfully opened the file
    if (inFile.is_open()){
        //variable to store the line we are reading
        string line;
        //parse and ignore the first line (store name)
        getline(inFile, line);
        //parse and ignore the second line (column header)
        getline(inFile, line);
        while(!inFile.eof()){
            //parse the line and store it
            getline(inFile, line);
            //process it if the line is not empty
            if (line != ""){
                //convert the line to inputstringstream
                istringstream iss(line);
                //variable to store parsed category
                string category;
                //variable to store parsed aisle number
                string aisleNum;
                //store the category, parse up to first comma
                getline(iss, category, ',');
                //store the aisle number, parse up to newline(default delimiter)
                getline(iss, aisleNum);
                //now lets try to convert the parsed aisle number string to integer
                stringstream converter;
                int parsedAisleNumber;
                converter << aisleNum;
                converter >> parsedAisleNumber;
                if (converter.fail()){
                    //we encountered a non-number aisle
                }else{
                    //cout << "Accessing parsedAisleNumber: " << parsedAisleNumber << endl;
                    store->getAisle(parsedAisleNumber)->addCategory(category);
                }
            }
        }
        inFile.close();
    }else{
        //we did not open the file
        cout << "Could not open file: '" << fileName << "', check the file and try again." << endl;
    }
    return store;
}

int main() {
    cout << "Grocery Store Test" << endl;
    cout << "-------------" << endl;
    GroceryStore* store = loadStoreFromFile("stores/Marsh.qss");
    cout << store->toString() << endl;
    return 0;
}
