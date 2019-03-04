#include "IceCreamItem.h"

using namespace std;

IceCreamItem::IceCreamItem(string size) {
    if (size == "small") {
        price = 3.00;
    }
    else if (size == "medium") {
        price = 5.00;
    }
    else if (size == "large") {
        price = 6.50;
    }
    else {
        // TODO: Error case?
    }

    this->size = size;
}