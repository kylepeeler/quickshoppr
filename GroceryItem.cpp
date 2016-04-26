// GroceryItem.cpp
// Created by kpeel on 4/13/2016.
//

#include <sstream>
#include "GroceryItem.h"

using namespace std;

GroceryItem::GroceryItem() {
    this->setName("New Item");
    this->setCategory("Undefined");
    this->setCompletionStatus(false);
    this->setAisleNumber(-1);
}

GroceryItem::GroceryItem(std::string name, std::string category, bool completionStatus) {
    this->setName(name);
    this->setCategory(category);
    this->setCompletionStatus(completionStatus);
    this->setAisleNumber(-1);
}

GroceryItem::GroceryItem(std::string name, std::string category, int aisleNum) {
    this->setName(name);
    this->setCategory(category);
    this->setCompletionStatus(false);
    this->setAisleNumber(aisleNum);
}

GroceryItem::GroceryItem(std::string name, std::string category) {
    this->setName(name);
    this->setCategory(category);
    this->setCompletionStatus(false);
    this->setAisleNumber(-1);
}


GroceryItem::GroceryItem(const GroceryItem &original) {
    this->setName(original.getName());
    this->setCategory(original.getCategory());
    this->setCompletionStatus(original.isCompleted());
    this->setAisleNumber(original.getAisleNumber());
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
    if (!this->completed){
        this->completed = true;
    }
}

void GroceryItem::setCompletionStatus(bool completionStatus){
    this->completed = completionStatus;
}

bool GroceryItem::isCompleted() const{
    return this->completed;
}

std::string GroceryItem::getCompletionStatusStr() const{
    if (this->isCompleted()){
        return "true";
    }else{
        return "false";
    }
}

int GroceryItem::getAisleNumber()const {
    return this->aisleNum;
}

string GroceryItem::itostr(int i) const{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

std::string GroceryItem::getAisleNumberStr() const{
    int aisleNumber = this->getAisleNumber();
    std::string aisleNumberString = itostr(aisleNumber);
    return aisleNumberString;
}

void GroceryItem::setAisleNumber(int aisle) {
    this->aisleNum = aisle;
}

std::string GroceryItem::toString() {
    if (this->isCompleted()){
        return "Item: " + this->getName() + " (" + this->getCategory() + "): completed? \u2714";
    }else{
        return "Item: " + this->getName() + " (" + this->getCategory() + "): completed? \u2718";
    }
}



























