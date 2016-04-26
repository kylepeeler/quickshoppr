#include <iostream>
#include <fstream>
#include <sstream>
#include "GroceryStore.h"
#include "GroceryList.h"

using namespace std;

void printAsciiHeader(){
    string header =
            "\nOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOOoOoOoOoOoOoOoOo\n"
            "8                                                                                                                8\n"
            "8      /$$$$$$            /$$           /$$        /$$$$$$  /$$                                                  8\n"
            "0     /$$__  $$          |__/          | $$       /$$__  $$| $$                                                  0\n"
            "8    | $$  \\ $$ /$$   /$$ /$$  /$$$$$$$| $$   /$$| $$  \\__/| $$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$     8\n"
            "0    | $$  | $$| $$  | $$| $$ /$$_____/| $$  /$$/|  $$$$$$ | $$__  $$ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$    0\n"
            "8    | $$  | $$| $$  | $$| $$| $$      | $$$$$$/  \\____  $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\__/    8\n"
            "0    | $$/$$ $$| $$  | $$| $$| $$      | $$_  $$  /$$  \\ $$| $$  | $$| $$  | $$| $$  | $$| $$  | $$| $$          0\n"
            "8    |  $$$$$$/|  $$$$$$/| $$|  $$$$$$$| $$ \\  $$|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$/| $$$$$$$/| $$          8\n"
            "0     \\____ $$$ \\______/ |__/ \\_______/|__/  \\__/ \\______/ |__/  |__/ \\______/ | $$____/ | $$____/ |__/          0\n"
            "8          \\__/                                                                | $$      | $$                    8\n"
            "0                     v0.1  by Kyle Peeler                                     | $$      | $$                    0\n"
            "8                                                                              |__/      |__/                    8\n"
            "0                                                                                                                0\n"
            "OoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOoOo0OoOoOoOo\n";
    cout << header << endl;
}

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
    cout << "Loading " << fileName << "..." << endl;
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
                    //cout << "We found non-numbered aisle: " << aisleNum << endl;
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

int partitionStr(string *array, int startIndex, int endIndex) {
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

void quickSortStr(string *array, int startIndex, int endIndex){
    if (startIndex < endIndex){
        int pivot = partitionStr(array, startIndex, endIndex);
        quickSortStr(array, startIndex, pivot - 1);
        quickSortStr(array, pivot + 1, endIndex);
    }
}

void assignAisles(GroceryList* list, GroceryStore* store){
    int numberOfItems = list->getNumItems();
    //iterate through all of the items
    for (int i = 0; i < numberOfItems; i++){
        string category = list->getItem(i)->getCategory();
        list->getItem(i)->setAisleNumber(store->lookupAisleByCategory(category));
    }
}

void printListAscendingAisles(GroceryList* list, GroceryStore* store){
    int numStoreAisles = store->getNumAisles();
    int numListItems = list->getNumItems();
    //iterate through the store aisle to be printed
    for (int i = 1; i <= numStoreAisles; i++){
        //iterate through the list items
        //check if the item at index j is equal to aisle i
        if (!store->getAisle(i)->isAisleEmpty()){
            for (int j = 0; j < numListItems; j++){
                if (list->getItem(j)->getAisleNumber() == i) {
                    cout << "Aisle [" << i << "]->" << list->getItem(j)->toString() << endl;
                }
            }
        }
    }
    //now print the unknown location items
    for (int j = 0; j < numListItems; j++){
        if (list->getItem(j)->getAisleNumber() == -1){
            cout << "Aisle [?]->" << list->getItem(j)->toString() << endl;
        }
    }
    //iterate through all of the aisles in the store
}

int selectCategory(string* categories, int numberOfCategories){
    int selectedIndex = -1;
    while (selectedIndex == -1){
        for (int i = 0; i < numberOfCategories; i++){
            cout << "(" << i+1 << ")" << " " << categories[i] << endl;
        }
        cout << "Select a category for the item : ";
        cin >> selectedIndex;
        //decrement as we are showing index + 1
        selectedIndex--;
        if (!(selectedIndex >= 0 && selectedIndex < numberOfCategories)){
            selectedIndex = -1;
        }
    }
	return selectedIndex;
}


void addItemToList(GroceryList* list, GroceryStore* store, string* categories){
    GroceryItem itemToAdd;
    string itemName;
    cout << "\nWhat is the name of the item? : ";
    std::getline(cin, itemName);
    std::getline(cin, itemName);

    int catIndex = selectCategory(categories, store->getNumAllCategories());
    itemToAdd.setName(itemName);
    itemToAdd.setCategory(categories[catIndex]);
    list->addItem(itemToAdd);
}


int main() {
    GroceryStore* store = loadStoreFromFile("stores/Marsh.qss");
    GroceryList* list = new GroceryList(store);
//    cout << store->toString() << endl;
//    cout << "Aisle containing 'Tea': " << store->lookupAisleByCategory("Tea") << endl;
//    int aisleNumWithTea = store->lookupAisleByCategory("Tea");
//    cout << "Removing 'Tea' in aisle: " << aisleNumWithTea << "......";
//    cout << store->getAisle(aisleNumWithTea)->removeCategory("Tea") << endl;
//    cout << "Aisle containing 'Tea': " << store->lookupAisleByCategory("Tea") << endl;
//    cout << "Aisle 1 empty? " << store->getAisle(1)->isAisleEmpty() << endl;
//    cout << "Aisle 1 number:" << store->getAisle(1)->getAisleNum() << endl;
    //allocate the categories array on heap, make sure to free!!!
    string * allCategories = store->getAllCategories();
    //cout << " Unsorted Listing Categories: " << endl;
    quickSortStr(allCategories, 0, (store->getNumAllCategories() - 1));

    //save the user's entered menu option
    string userMenuOption;
    do {
        printAsciiHeader();
        cout << "Loaded Store Name: " << store->getStoreName() << endl;
        cout << "Number of Loaded Categories: " << store->getNumAllCategories() << endl;
        cout << "Number of Loaded Aisles: " << store->getNumAisles() << endl;
        if (list->getNumItems() != 0){
            cout << "\nGROCERY LIST BY AISLE" << endl;
            cout << "------------------------" << endl;
            printListAscendingAisles(list, store);
            cout << "------------------------\n" << endl;
        }else{
            cout << "\n[Grocery List is Empty!]" << endl;
        }
        //do-while loop, display the menu atleast once
        cout << "\nWhat would you like to do?" << endl;
        cout << "1) Add Grocery Item to list" << endl;
        cout << "2) Remove Grocery Item from list" << endl;
        cout << "3) Change stores" << endl;
        cout << "4) Shopping mode" << endl;
        cout << "5) Exit\n" << endl;
        //prompt user to enter an option according to menu
        cout << "Please select an option : ";
        //clean out cin to remove previous values
        cin.clear();
        cin >> userMenuOption; //take option value as input and save it
        if (cin.good()){
            if (userMenuOption == "1"){
                //add grocery item to list
                addItemToList(list, store, allCategories);
                assignAisles(list, store);
            }else if(userMenuOption == "2"){
                //remove grocery item from list
            }else if(userMenuOption == "3"){
                delete store;
                cout << "Enter store filename to load: ";
                string inputFileName;
                cin >> inputFileName;
                store = loadStoreFromFile("stores/" + inputFileName + ".qss");
                allCategories = store->getAllCategories();
                assignAisles(list, store);
                //change stores
            }else if(userMenuOption == "4"){
                //shopping mode
            }else if(userMenuOption == "5"){
                cout << "Quitting...Good Bye" << endl;
            }else{
                cout << "Invalid Option Entered, Try Again!" << endl;
            }
        }else{
            cout << "Invalid Option Entered, Try Again!" << endl;
        }
    }while (userMenuOption != "5");




//    cout << " QUICKSORTED Listing Categories: " << endl;
//    for (int i = 0; i < store->getNumAllCategories(); i++){
//        cout << "Category[" << i << "]: " << allCategories[i] << endl;
//    }
//    cout << store->toString() << endl;
//    list->addItem(GroceryItem("Tomato Soup", "Soups"));
//    list->addItem(GroceryItem("Sour Patch Kids", "Candy"));
//    list->addItem(GroceryItem("AA Batteries", "Batteries"));
//    list->addItem(GroceryItem("Pears", "Canned Fruits"));
//    list->getItem(0)->completeItem();
   // assignAisles(list, store);
    //cout << "Returned category number: " << selectCategory(allCategories, store->getNumAllCategories()) << endl;
    delete[] allCategories;
    return 0;
}
