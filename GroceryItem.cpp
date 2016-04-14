// GroceryItem.cpp
// Created by kpeel on 4/13/2016.
//

#include "GroceryItem.h"

using namespace std;

GroceryItem::GroceryItem() {
    this->setName("New Item");
    this->setCategory("Undefined");
    this->setCompletionStatus(false);
}

GroceryItem::GroceryItem(std::string name, std::string category, bool completionStatus) {
    this->setName(name);
    this->setCategory(category);
    this->setCompletionStatus(completionStatus);
}

GroceryItem::GroceryItem(std::string name, std::string category) {
    this->setName(name);
    this->setCategory(category);
    this->setCompletionStatus(false);
}


GroceryItem::GroceryItem(const GroceryItem &original) {
    this->setName(original.getName());
    this->setCategory(original.getCategory());
    this->setCompletionStatus(original.isCompleted());
}

GroceryItem::~GroceryItem() {
    //empty, nothing declared on heap
}

std::string GroceryItem::getName() const{
    return this->name;
}

void GroceryItem::setName(std::string name) {
    this->name = name;
}

std::string GroceryItem::getCategory() const{
    return this->category;
}


void GroceryItem::setCategory(std::string category) {
    this->category = category;
}


void GroceryItem::completeItem() {
    if (this->completed == false){
        this->completed = true;
    }
}

void GroceryItem::setCompletionStatus(bool completionStatus){
    this->completed = completionStatus;
}

bool GroceryItem::isCompleted() const{
    return this->completed;
}






















