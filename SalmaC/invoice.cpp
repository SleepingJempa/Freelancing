#include <iostream>

using namespace std;

class Invoice
{
private:
    string segment_id;
    string description;
    int soldNumber;
    int price;
public:
    Invoice(string segment_id, string description, int sold, int price);
    string getID() { return segment_id; }
    void setID(string id) { segment_id = id; }
    string getDescription() { return description; }
    void setInfo(string info) { description = info; }
    int getSoldNumber() { return soldNumber; }
    void setSoldNumber(int soldNumber) { this->soldNumber = soldNumber; }
    int getPrice() { return price; }
    void setPrice(int price) { this->price = price; }
    int getInvoiceAmount() { return soldNumber * price; } 
    void showInfo();
};

Invoice::Invoice(string segment_id, string description, int sold, int price)
{
    this->segment_id = segment_id;
    this->description = description;

    if (soldNumber < 0) soldNumber = 0;
    this->soldNumber = sold;
    
    if (price < 0) price = 0;
    this->price = price;
}

void Invoice::showInfo() {
    cout << "Segment ID: " << segment_id << endl;
    cout << "Description: " << description << endl;
    cout << "Sold NUmber: " << soldNumber << endl;
    cout << "Price: " << price << endl; 
}

int main() {
    Invoice inv("001", "Zahra miz kharid", 2, 120);
    inv.showInfo();
    inv.setID("002");
    inv.showInfo();
    inv.setInfo("Zahra miz ra kharid");
    inv.showInfo();
    inv.setSoldNumber(1);
    inv.showInfo();
    inv.setPrice(200);
    inv.showInfo();
}