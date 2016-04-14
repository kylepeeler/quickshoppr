//
// Created by kpeel on 4/13/2016.
//

#ifndef QUICKSHOPPR_GROCERYAISLE_H
#define QUICKSHOPPR_GROCERYAISLE_H


#include <string>

class GroceryAisle {
private:
    int aisleNum;
    std::string categories[];
public:
    //constructor
    GroceryAisle();
    //constructor with aisle number
    GroceryAisle(int aisleNum);
    //copy constructor
    GroceryAisle(const GroceryAisle &orig);
    //destructor
    ~GroceryAisle();
    //aisleNum setters/getters
    void setAisleNum(int aisleNum);
    int getAisleNum();
    //category getter/"setter"
    bool addCategory(std::string category);//returns false if the category already exists, true if successful
    bool removeCategory(std::string category);//returns false if category is not found, true if the category was removed successfully
    std::string* getCategories();
    int getNumItems();
};


#endif //QUICKSHOPPR_GROCERYAISLE_H
