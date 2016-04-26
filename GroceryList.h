//
// Created by Kyle A Peeler on 4/17/16.
//

#ifndef QUICKSHOPPR_GROCERYLIST_H
#define QUICKSHOPPR_GROCERYLIST_H


#include "GroceryItem.h"
#include "GroceryStore.h"

class GroceryList {
private:
    int numItems;
    GroceryItem* items;
    GroceryStore store;
public:
    GroceryList();
    GroceryList(GroceryStore* store);
    ~GroceryList();
    int getNumItems();
    void setNumItems(int numItems);
    void addItem(GroceryItem item);
    void removeItem(int index);
    GroceryItem* getItem(int index);
    void setStore(GroceryStore* store);
    GroceryStore getGroceryStore();
    std::string toString();
    std::string itostr(int i) const;
};


#endif //QUICKSHOPPR_GROCERYLIST_H