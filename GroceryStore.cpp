//
// Created by kpeel on 4/13/2016.
//

#include <iostream>
#include "GroceryStore.h"

using namespace std;

GroceryStore::GroceryStore(){
    this->setStoreName("Undefined Store");
    this->setNumAisles(0);
    this->aisles = new GroceryAisle[this->getNumAisles()];
}

GroceryStore::GroceryStore(std::string storeName, int numAisles){
    this->setStoreName(storeName);
    this->setNumAisles(numAisles);
    //allocate the aisles
    aisles = new GroceryAisle[numAisles];
    for (int i = 0; i < numAisles; i++){
        aisles[i].setAisleNum(i);
    }
}

GroceryStore::~GroceryStore() {
    delete[] aisles;
}

string GroceryStore::getStoreName(){
    return this->storeName;
}

void GroceryStore::setStoreName(std::string storeName) {
    this->storeName = storeName;
}

int GroceryStore::getNumAisles(){
    return this->numAisles;
}

void GroceryStore::setNumAisles(int numIsles) {
    this->numAisles = numIsles;
}

GroceryAisle* GroceryStore::getAisles(){
    return this->aisles;
}

GroceryAisle* GroceryStore::getAisle(int index){
    return &this->aisles[index - 1];
}

int GroceryStore::lookupAisleByCategory(string category){
    //if we can't find the aisle number, return -1
    int aisleNumber = -1;
    //iterate through all of the aisle numbers
    //aisle numbers start from 1
    for (int i = 1; i <= this->getNumAisles(); i++){
        GroceryAisle* aisleToSearch = this->getAisle(i);
        //cout << "searching aisle: " << this->getAisle(i)->toString() << endl;
        //get number of categories in aisle to search
        int numOfCategoriesInAisle = aisleToSearch->getNumCategories();
        //get the categories array from the aisle to search
        string* categoriesInAisle = aisleToSearch->getCategories();
        //iterate through the categories and compare to parameter
        for (int j = 0; j < numOfCategoriesInAisle; j++){
            //if we found a match, report back the aisle number
            if (category.compare(categoriesInAisle[j]) == 0){
                aisleNumber = i;
                //return to stop searching
                return aisleNumber;
            }
        }
    }
    return aisleNumber;
}

bool GroceryStore::assignCategoryToAisle(std::string category, int aisleNum){
    return this->getAisle(aisleNum)->addCategory(category);
}

string GroceryStore::toString() {
    string output;
    output = "Store Name: " + this->getStoreName() + "\n";
    output += "Number of Aisles: " + to_string(this->getNumAisles()) + "\n";
    output += "Aisle Data: \n";
    int numberOfCategories = 0;
    //get number of aisles in the store
    int numberOfAisles = this->numAisles;
    //loop through all of the aisles
    for (int i = 0; i < numberOfAisles; i++){
        if (!this->aisles[i].isAisleEmpty()){
            output += this->aisles[i].toString() + "\n";
            numberOfCategories += this->aisles[i].getNumCategories();
        }else{
            output += "Aisle[" + to_string(i+1) + "]: is empty\n";
        }
    }
    //return the whole string
    cout << "Number of Categories: " << numberOfCategories << endl;
    return output;
}

string* GroceryStore::getAllCategories() {
    int numberOfCategories = 0;
    //get number of aisles in the store
    int numberOfAisles = this->numAisles;
    //loop through all of the aisles
    for (int i = 0; i < numberOfAisles; i++){
        if (!this->aisles[i].isAisleEmpty()){
            numberOfCategories += this->aisles[i].getNumCategories();
        }
    }
    //allocate the categories array
    string* allCategories = new string[numberOfCategories];
    int allCategoriesIndex = 0;
    //loop through all of the aisles
    for (int i = 0; i < numberOfAisles; i++){
        if (!this->aisles[i].isAisleEmpty()){
            string * aisleCategories = this->aisles[i].getCategories();
            //store number of categories in the aisle
            int numCategoriesInAisle = this->aisles[i].getNumCategories();
            for (int j = 0; j < numCategoriesInAisle; j++){
                allCategories[allCategoriesIndex] = aisleCategories[j];
                allCategoriesIndex++;
            }
        }
    }
//    //sort the list of all categories in alphabetical order using bubble sort
//    for (int i = 0; i < numberOfCategories; i++){
//        for (int k = 0; k < numberOfCategories; k++){
//            if (strcmp(allCategories[i].c_str(), allCategories[k].c_str()) < 0){
//                string tmp = allCategories[i];
//                allCategories[i] = allCategories[k];
//                allCategories[k] = tmp;
//            }
//        }
//    }
    return allCategories;
}

int GroceryStore::getNumAllCategories() {
    int numberOfCategories = 0;
    //get the number of aisles in the store
    int numberOfAisles = this->numAisles;
    //loop through all of the aisles
    for (int i = 0; i < numberOfAisles; i++){
        //if the category isn't empty, add the count of categories to the total
        if (!this->aisles[i].isAisleEmpty()){
            numberOfCategories += this->aisles[i].getNumCategories();
        }
    }
    return numberOfCategories;
}







