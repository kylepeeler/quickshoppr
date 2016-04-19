//
// Created by kpeel on 4/13/2016.
//

#ifndef QUICKSHOPPR_GROCERYSTORE_H
#define QUICKSHOPPR_GROCERYSTORE_H


#include <string>
#include "GroceryAisle.h"

class GroceryStore {
private:
    std::string storeName;
    int numAisles;
    GroceryAisle* aisles;
public:
    //null constructor
    GroceryStore();
    //overloaded constructor with name and number of isles
    GroceryStore(std::string storeName, int numAisles);
    ~GroceryStore();
    //storeName getter/setter
    std::string getStoreName();
    void setStoreName(std::string storeName);
    //numIsles getter/setter
    int getNumAisles();
    void setNumAisles(int numIsles);
    //get aisles array
    GroceryAisle* getAisles();
    //get specific aisle
    GroceryAisle* getAisle(int index);
    int lookupAisleByCategory(std::string category);
    bool assignCategoryToAisle(std::string category, int aisleNum);
    std::string toString();
};


#endif //QUICKSHOPPR_GROCERYSTORE_H
