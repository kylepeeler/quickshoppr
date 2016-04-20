#include <iostream>
#include <fstream>
#include <sstream>
#include "GroceryStore.h"

using namespace std;

int parseNumAisles(string fileName){
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

string parseStoreName(string fileName){
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
    GroceryStore* store = new GroceryStore(parseStoreName(fileName), parseNumAisles(fileName));
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
                    cout << "We found non-numbered aisle: " << aisleNum << endl;
                }else{
                    //cout << "Accessing parsedAisleNumber: " << parsedAisleNumber << endl;
                    store->assignCategoryToAisle(category, parsedAisleNumber);
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

void swapStr(string* val1, string* val2){
    string temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

int partition(string* array, int startIndex, int endIndex) {
    string pivot = array[endIndex];
    int pIndex = startIndex;
    for (int i = startIndex; i < endIndex; i++){
        if (array[i] <= pivot){
            swapStr(&array[i], &array[pIndex]);
            pIndex += 1;
        }
    }
    swapStr(&array[pIndex], &array[endIndex]);
    return pIndex;
}

void quickSort(string* array, int startIndex, int endIndex){
    if (startIndex < endIndex){
        int pivot = partition(array, startIndex, endIndex);
        quickSort(array, startIndex, pivot - 1);
        quickSort(array, pivot + 1, endIndex);
    }
}


int main() {
    cout << "Grocery Store Test" << endl;
    cout << "-------------" << endl;
    GroceryStore* store = loadStoreFromFile("stores/Marsh.qss");
//    cout << store->toString() << endl;
//    cout << "Aisle containing 'Tea': " << store->lookupAisleByCategory("Tea") << endl;
//    int aisleNumWithTea = store->lookupAisleByCategory("Tea");
//    cout << "Removing 'Tea' in aisle: " << aisleNumWithTea << "......";
//    cout << store->getAisle(aisleNumWithTea)->removeCategory("Tea") << endl;
//    cout << "Aisle containing 'Tea': " << store->lookupAisleByCategory("Tea") << endl;
    cout << "Aisle 1 empty? " << store->getAisle(1)->isAisleEmpty() << endl;
    cout << "Aisle 1 number:" << store->getAisle(1)->getAisleNum() << endl;
    string * allCategories = store->getAllCategories();
    cout << " Pre-sorted Listing Categories: " << endl;
    cout << "Number of All Categories: " << store->getNumAllCategories() << endl;
    for (int i = 0; i < store->getNumAllCategories(); i++){
        cout << "Category[" << i << "]: " << allCategories[i] << endl;
    }
    quickSort(allCategories, 0, (store->getNumAllCategories() - 1));
    cout << " Post-sorted Listing Categories: " << endl;
    cout << "Number of All Categories: " << store->getNumAllCategories() << endl;
    for (int i = 0; i < store->getNumAllCategories(); i++){
        cout << "Category[" << i << "]: " << allCategories[i] << endl;
    }
    cout << store->toString() << endl;
    return 0;
}