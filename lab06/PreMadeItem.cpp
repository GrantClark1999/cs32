#include "PreMadeItem.h"

using namespace std;

PreMadeItem::PreMadeItem(string name, string size) :
    IceCreamItem(size) {
    this->name = name;
    price += 1.00;
}

string PreMadeItem::composeItem() {
    stringstream ss;
    stringstream priceStream;
    ss << "Pre-made Size: " << size << endl;
    ss << "Pre-made Item: " << name << endl;
    priceStream << fixed << setprecision(2) << price;
    ss << "Price: $" << priceStream.str() << endl;
    return ss.str();
}

double PreMadeItem::getPrice() {
    return price;
}