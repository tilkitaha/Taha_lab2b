#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Item {
public:
    Item(std::string n, float unp, char type, int amount);
    void setName(std::string n);
    std::string get_name() const;
    void setUnit(float unp);
    float get_unit() const;
    void setVattype(char type);
    char get_vattype() const;
    void setAmount(int amount);
    int get_amount() const;
    float net_price();
    float total_price();
private:
    std::string name;
    double unit_per_price;
    char VAT_tax_type;
    int amount_sold;
};
class Invoice {
public:
    Invoice(double s,double b, std::vector<Item> it={});
    long long int getSeller();
    long long int getBuyer();
    std::vector<Item> getItems();
    void add_item(Item item);
    void print();
private:
    long long int seller;
    long long int buyer;
    std::vector<Item> items;
    friend std::ostream &operator<<(std::ostream &out, Invoice &inv);

};
