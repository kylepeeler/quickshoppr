//
// Created by kpeel on 4/13/2016.
//

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
    return &this->aisles[index];
}

int GroceryStore::lookupAisleByCategory(string category){
    //if we can't find the aisle number, return -1
    int aisleNumber = -1;
    //iterate through all of the aisle numbers
    for (int i = 0; i < this->getNumAisles(); i++){
        GroceryAisle* aisleToSearch = this->getAisle(i);
        //get number of categories in aisle to search
        int numOfCategoriesInAisle = aisleToSearch->getNumCategories();
        //get the categories array from the aisle to search
        string* categoriesInAisle = aisleToSearch->getCategories();
        //iterate through the categories and compare to parameter
        for (int j = 0; j < numOfCategoriesInAisle; j++){
            //if we found a match, report back the aisle number
            if (category.compare(categoriesInAisle[j])){
                aisleNumber = i;
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
    //get number of aisles in the store
    int numberOfAisles = this->numAisles;
    //loop through all of the aisles
    for (int i = 0; i < numberOfAisles; i++){
        output += this->aisles[i].toString() + "\n";
    }
    //return the whole string
    return output;
}

