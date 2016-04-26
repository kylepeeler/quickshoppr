//
// Created by kpeel on 4/13/2016.
//

#ifndef QUICKSHOPPR_GROCERYITEM_H
#define QUICKSHOPPR_GROCERYITEM_H


#include <string>

class GroceryItem {
private:
    std::string name;
    std::string category;
    bool completed;
    int aisleNum;

public:
    //null constructor
    GroceryItem();
    //overloaded constructor w/ aisle number
    GroceryItem(std::string name, std::string category, int aisleNum);
    //overloaded constructor w/ parameters
    GroceryItem(std::string name, std::string category, bool completionStatus);
    //overloaded constructor w/out completion status - assumes false
    GroceryItem(std::string name, std::string category);
    //copy constructor
    GroceryItem(const GroceryItem &orig);
    //destructor
    ~GroceryItem();
    //name getters/setters
    std::string getName() const;
    void setName(std::string name);
    //category getters/setters
    std::string getCategory() const;
    void setCategory(std::string category);
    //aisle number setters/getters
    int getAisleNumber()const;
    void setAisleNumber(int aisle);
    std::string getAisleNumberStr() const;
    //completion status getters/setters
    bool isCompleted() const;
    void setCompletionStatus(bool completionStatus);
    std::string getCompletionStatusStr() const;
    void completeItem();
    std::string toString();
    std::string itostr(int i) const;

};


#endif //QUICKSHOPPR_GROCERYITEM_H
