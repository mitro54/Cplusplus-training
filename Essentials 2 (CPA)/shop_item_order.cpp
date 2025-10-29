#include <iostream>
#include <string>
#include <cmath>

class ShopItemOrder {
    public:
        ShopItemOrder(std::string name, double price, int quantity = 1):
        name(name), unit_price(price), quantity(quantity) {
            unit_price = (price > 0) ? price : fabs(price);
            this->quantity = (quantity > 0) ? quantity : abs(quantity);
        }
        // getters
        std::string get_name() { return name; }
        int get_quantity() { return quantity; }
        double get_price() { return unit_price; }
        double get_order_total() { return quantity * unit_price; }
        // setters
        void set_name(std::string name);
        void set_price(double price);
        void set_quantity(int count);
        // print
        void print();

    private:
        std::string name;
        double unit_price;
        int quantity;
};

void ShopItemOrder::set_name(std::string name) {
    this->name = name;
}

void ShopItemOrder::set_price(double price) {
    if (price > 0) unit_price = price;
}

void ShopItemOrder::set_quantity(int count) {
    if (count > 0) quantity = count;
}

void ShopItemOrder::print() {
    std::cout
    << "Item name: "
    << name
    << "\nUnit price: "
    << unit_price
    << "\nOrder amount: "
    << quantity
    << "\nOrder total: "
    << get_order_total();
}

int main(void) {
    ShopItemOrder pizza("Pizza", 13.37, 4);
    pizza.print();
    return 0;
}