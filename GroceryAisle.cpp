//
// Created by kpeel on 4/13/2016.
//
#include <iostream>
#include "GroceryAisle.h"

using namespace std;

GroceryAisle::GroceryAisle() {
    //we define undefined aisle number as -1
    this->setAisleNum(0);
    //a new grocery aisle has no categories
    this->setNumCategories(0);
    //allocate it?
    categories = new string[0];
    this->isEmpty = true;
}

GroceryAisle::GroceryAisle(int aisleNum) {
    //we define the aisle number with the parameter
    this->setAisleNum(aisleNum);
    //a new grocery asile has no categories
    this->setNumCategories(0);
    //allocate array of category strings
    categories = new string[0];
    this->isEmpty = true;
}

GroceryAisle::GroceryAisle(int aisleNum, int numberOfCategories){
    //we define the aisle number with the parameter
    this->setAisleNum(aisleNum);
    //we define the number of categories with the parameter
    this->setNumCategories(numberOfCategories);
    //allocate the category array
    categories = new string[numberOfCategories];
    this->isEmpty = false;
}

GroceryAisle::GroceryAisle(const GroceryAisle &original){
    //set the aisle number of the copy
    this->setAisleNum(original.getAisleNum());
    //set the number of categories from the original
    this->setNumCategories(original.getNumCategories());
    //allocate the new category array
    this->categories = new string[this->getNumCategories()];
    //copy each category over
    for (int i = 0; i < this->getNumCategories(); i++){
        this->categories[i] = original.categories[i];
    }
    this->isEmpty = original.isEmpty;
}

GroceryAisle::~GroceryAisle() {
    //cout << "Deleting: " << this->toString() << endl;
    delete[] this->categories;
}

void GroceryAisle::setAisleNum(int aisleNum) {
    this->aisleNum = aisleNum;
}
int GroceryAisle::getAisleIndex() const {
    return this->aisleNum;
}
//aisle number is index + 1
int GroceryAisle::getAisleNum() const {
    return this->aisleNum + 1;
}

void GroceryAisle::setNumCategories(int numCategories) {
    this->numCategories = numCategories;
}

int GroceryAisle::getNumCategories() const {
    return this->numCategories;
}

bool GroceryAisle::addCategory(string category) {
    this->isEmpty = false;
    //get the size of the current number of categories
    int currentNumberCategories = numCategories;
    bool alreadyHaveCategory = false;
    //check if we already have the category
    for (int i = 0; i < currentNumberCategories; i++){
        if (this->categories[i].compare(category) == 0){
            alreadyHaveCategory = true;
        }
    }
    if (!alreadyHaveCategory){
        string * tmpCategories = new string[numCategories + 1];
        //copy each category
        for (int i = 0; i < numCategories; i++){
            tmpCategories[i] = this->categories[i];
        }
        //now assign the new category
        tmpCategories[numCategories] = category;
        //delete the old categories pointer
//        for (int i = 0; i < numCategories; i++){
//            cout << "Aisle#" << this->getAisleNum() << " Old Categories[" << i << "]: " << this->categories[i] << endl;
//        }
        delete[] categories;
        this->categories = tmpCategories;
        this->numCategories++;
        return true;
    }else{
        return false;
    }
}//end add category

bool GroceryAisle::removeCategory(string category){
    //get the size of the current number of categories
    int currentNumberCategories = this->getNumCategories();
    //-1 means we have not found the category
    int foundCategoryIndex = -1;
    //if we found the category, recreate the category array without it
    if (hasCategory(category)){
        //allocate a new string array of categories with size-1
        string * tempCategories = new string[currentNumberCategories - 1];
        //now we copy over up to the index of the foundCategory
        //cout << "found category index: " << foundCategoryIndex << endl;
        for (int j = 0; j < foundCategoryIndex; j++){
            tempCategories[j] = this->categories[j];
        }
        //now we copy elements past the index of foundCategory
        for (int k = foundCategoryIndex + 1; k < currentNumberCategories; k++){
            tempCategories[k - 1] = this->categories[k];
        }
        //free the old categories pointer
        delete[] categories;
        this->categories = tempCategories;
        //decrease the number of categories
        this->setNumCategories(currentNumberCategories - 1);
        if (getNumCategories() == 0){
            this->isEmpty = true;
        }
        return true;
    }else{
        return false;
    }
}

bool GroceryAisle::hasCategory(std::string category) {
    //get the size of the current number of categories
    int currentNumberCategories = this->getNumCategories();
    //did we find the category?
    bool foundCategory = false;
    //lets find the category
    for (int i = 0; i < currentNumberCategories; i++){
        if (this->categories[i].compare(category) == 0){
            foundCategory = true;
            return foundCategory;
        }
    }
    return foundCategory;
}

string* GroceryAisle::getCategories(){
    return this->categories;
}

string GroceryAisle::toString() {
    //the string
    string output;
    output = "Aisle[" + to_string(this->getAisleNum()) + "]-> Categories(" + to_string(this->getNumCategories()) + "): ";
    //loop through categories and concatenate it to output
    for (int i = 0; i < this->getNumCategories(); i++){
        //concatenate the category to output string
        if (i != this->numCategories - 1){
            output += this->categories[i] + ", ";
        }else{
            output += this->categories[i];
        }

    }
    return output;

}

bool GroceryAisle::isAisleEmpty() {
    return this->isEmpty;
}



