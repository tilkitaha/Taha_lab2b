#include <iostream>
#include <Invoice.h>

Item::Item(std::string n, float unp, char type, int amount) {
    name = n;
    unit_per_price = unp;
    VAT_tax_type = type;
    amount_sold = amount;
}

void Item::setName(std::string n) {
    name=n;
}

std::string Item::get_name() const {
    return name;
}

void Item::setUnit(float unp) {
    unit_per_price = unp;
}

float Item::get_unit() const {
    return unit_per_price;
}

void Item::setVattype(char type) {
    VAT_tax_type = type;
}

char Item::get_vattype() const {
    return VAT_tax_type;
}

void Item::setAmount(int amount) {
    amount_sold = amount;
}

int Item::get_amount() const {
    return amount_sold;
}

float Item::net_price() {
    return unit_per_price*amount_sold;
}

float Item::total_price() {
    float vat = 1.0;
    if(VAT_tax_type == 'A')
    {
        vat = 1.23;
    }
    else if(VAT_tax_type == 'B')
    {
        vat = 1.08;
    }
    return net_price()*vat;
}

void Invoice::add_item(Item item) {
    items.emplace_back(item);
}
Invoice::Invoice(double s, double b, std::vector<Item> it){
    seller = s;
    buyer = b;
    std::vector<Item> items = it;
}
long long int Invoice::getSeller() {
    return seller;
}

long long int Invoice::getBuyer() {
    return buyer;
}

std::vector<Item> Invoice::getItems() {
    return items;
}

std::ostream &operator<<(std::ostream &out, Invoice &inv) {
    out << "------------------VAT invoice------------------\n";
    out << "Seller: " << inv.getSeller() << "      Buyer: " << inv.getBuyer() << "\n\n";
    out << "                  c.j. VAT   il.    net   total\n";
    float net = 0;
    float total = 0;
    for(int i = 0;i<(int)inv.getItems().size();i++)
    {
        out << i+1 << ". " << inv.items[i].get_name() << "\t| " << inv.items[i].get_unit() << " " << inv.items[i].get_vattype() << " | ";
        out << inv.items[i].get_amount() << " | " << inv.items[i].net_price() << " | " << inv.items[i].total_price();
        out << std::fixed << std::setprecision(2) << "\n";
        net += inv.items[i].net_price();
        total += inv.items[i].total_price();
        }
    out << "------------------------------------ TOTAL ----" << std::endl;
    out << "                                  " << net << " | " << total << std::endl;
    return out;
}
