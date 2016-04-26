//
// Created by kpeel on 4/13/2016.
//

#ifndef QUICKSHOPPR_GROCERYAISLE_H
#define QUICKSHOPPR_GROCERYAISLE_H


#include <string>

class GroceryAisle {
private:
    int aisleNum;
    int numCategories;
    std::string* categories;
    bool isEmpty;
public:
    //constructor
    GroceryAisle();
    //constructor with aisle number
    GroceryAisle(int aisleNum);
    //overloaded constructor for 'special' aisles ie front, dairy, pharmacy
    GroceryAisle(bool isSpecial);
    //constructor with aisle number and number of categories
    GroceryAisle(int aisleNum, int numberOfCategories);
    //copy constructor
    GroceryAisle(const GroceryAisle &orig);
    //destructor
    ~GroceryAisle();
    //is empty getter
    bool isAisleEmpty();
    //aisleNum setters/getters
    void setAisleNum(int aisleNum);
    //get aisle index
    int getAisleIndex() const;
    int getAisleNum() const;
    //number of categories getter/setter
    void setNumCategories(int numCategories);
    int getNumCategories() const;
    //category getter/"setter"
    bool addCategory(std::string category);//returns false if the category already exists, true if successful
    bool removeCategory(std::string category);//returns false if category is not found, true if the category was removed successfully
    std::string* getCategories();
    bool hasCategory(std::string category);//returns true if contains category, if it doesn't returns false
    std::string itostr(int i);
    std::string toString();
};


#endif //QUICKSHOPPR_GROCERYAISLE_H
