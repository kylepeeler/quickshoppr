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

public:
    //null constructor
    GroceryItem();
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
    //completion status getters/setters
    bool isCompleted() const;
    void setCompletionStatus(bool completionStatus);
    void completeItem();

};


#endif //QUICKSHOPPR_GROCERYITEM_H
