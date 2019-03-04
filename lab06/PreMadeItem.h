#include "IceCreamItem.h"
#include <sstream>
#include <iomanip>

class PreMadeItem : public IceCreamItem {
public:
    PreMadeItem(std::string name, std::string size);
    virtual ~PreMadeItem() {};
    std::string composeItem();
    double getPrice();
private:
    std::string name;
};