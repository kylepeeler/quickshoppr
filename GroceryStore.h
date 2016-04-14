//
// Created by kpeel on 4/13/2016.
//

#ifndef QUICKSHOPPR_GROCERYSTORE_H
#define QUICKSHOPPR_GROCERYSTORE_H


#include <string>

class GroceryStore {
private:
    std::string storeName;
    int numIsles;
    std::string** categories;
public:
    //null constructor
    GroceryStore();
    //overloaded constructor with name and number of isles
    GroceryStore(std::string storeName, int numIsles);


};


#endif //QUICKSHOPPR_GROCERYSTORE_H
