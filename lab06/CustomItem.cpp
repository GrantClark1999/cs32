#include "CustomItem.h"

using namespace std;

CustomItem::CustomItem(string size) : IceCreamItem(size) {}

void CustomItem::addTopping(string topping) {
    toppings[topping]++;
    price += 0.40;
}

string CustomItem::composeItem() {
    stringstream ss;
    stringstream priceStream;
    ss << "Custom Size: " << size << endl;
    ss << "Toppings:" << endl;
    for(map<string, int>::iterator it = toppings.begin(); it != toppings.end(); ++it) {
        ss << it->first << ": " << it->second << " oz" << endl;
    }
    priceStream << fixed << setprecision(2) << price;
    ss << "Price: $" << priceStream.str() << endl;
    return ss.str();
}

double CustomItem::getPrice() {
    return price;
}