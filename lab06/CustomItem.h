#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include "IceCreamItem.h"
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>

class CustomItem : public IceCreamItem {
public:
    CustomItem(std::string size);
    virtual ~CustomItem() {};
    void addTopping(std::string topping);
    std::string composeItem();
    double getPrice();
private:
    std::map<std::string, int> toppings;
};

#endif