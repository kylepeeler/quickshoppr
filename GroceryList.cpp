//
// Created by Kyle A Peeler on 4/17/16.
//

#include "GroceryList.h"

using namespace std;

GroceryList::GroceryList() {
    //create an empty grocery list
    this->setNumItems(0);
    //allocate items array
    items = new GroceryItem[this->getNumItems()];
    //store is unassigned, keep null
}

GroceryList::GroceryList(GroceryStore store) {
    this->setNumItems(0);
    //allocate items array
    items = new GroceryItem[this->getNumItems()];
    //assign the grocery store
    this->setStore(store);
}

GroceryList::~GroceryList() {
    delete[] items;
}

int GroceryList::getNumItems() {
    return this->numItems;
}

void GroceryList::setNumItems(int numItems) {
    this->numItems = numItems;
}

void GroceryList::addItem(GroceryItem item) {
    //allocate a new temp array of items with size + 1
    GroceryItem* tempItems = new GroceryItem[this->getNumItems() + 1];
    //copy all of the items over from the old array
    for (int i = 0; i < this->numItems; i++){
        //deep copy grocery items
        tempItems[i].setName(items[i].getName());
        tempItems[i].setCategory(items[i].getCategory());
        tempItems[i].setCompletionStatus(items[i].isCompleted());
        tempItems[i].setAisleNumber(items[i].getAisleNumber());
    }
    //set the properties of the new grocery item
    int newItemIndex = this->numItems;
    tempItems[newItemIndex].setName(item.getName());
    tempItems[newItemIndex].setCategory(item.getCategory());
    tempItems[newItemIndex].setCompletionStatus(item.isCompleted());
    tempItems[newItemIndex].setAisleNumber(item.getAisleNumber());
    //delete the old items pointer
    delete[] items;
    this->items = tempItems;
    //increase the number of items
    this->setNumItems(this->getNumItems() + 1);
}

void GroceryList::removeItem(int index) {
    //allocate a new temp array of items with size - 1
    GroceryItem* tempItems = new GroceryItem[this->getNumItems() - 1];
    //now we copy up to the index of the found category
    for (int i = 0; i < index; i++){
        tempItems[i].setName(this->getItem(i).getName());
        tempItems[i].setCategory(this->getItem(i).getCategory());
        tempItems[i].setAisleNumber(this->getItem(i).getAisleNumber());
        tempItems[i].setCompletionStatus(this->getItem(i).isCompleted());
    }
    //now we copy past the index of the found item
    for (int k = index + 1; k < this->getNumItems(); k++){
        tempItems[k - 1].setName(this->getItem(k).getName());
        tempItems[k - 1].setAisleNumber(this->getItem(k).getAisleNumber());
        tempItems[k - 1].setCategory(this->getItem(k).getCategory());
        tempItems[k - 1].setCompletionStatus(this->getItem(k).isCompleted());
    }
    //delete the old items pointer
    delete[] items;
    //set the new items pointer
    this->items = tempItems;
    //decrease the number of items
    this->setNumItems(this->getNumItems() - 1);
}

GroceryItem GroceryList::getItem(int index) {
    return this->items[index];
}

void GroceryList::setStore(GroceryStore store) {
    this->setStore(store);
}

GroceryStore GroceryList::getGroceryStore() {
    return this->store;
}

string GroceryList::toString() {
    //get the number of items in the list
    int numItems = this->getNumItems();
    //loop through the items and concatinate the item with a newline
    string output;
    output = "Number of Items: " + to_string(numItems) + "\n";
    output += "Store: " + this->getGroceryStore().toString() + "\n";
    for (int i = 0; i < numItems; i++){
        output += "ListItem[" + std::to_string(i) + "]:" + this->getItem(i).toString() + "\n";
    }
    return output;
}