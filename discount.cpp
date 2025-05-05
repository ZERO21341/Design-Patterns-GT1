#include <iostream>
using namespace std;


class DiscountStrategy {
public:
    virtual double applyDiscount(double price) = 0;
    virtual ~DiscountStrategy() {}
};


class NoDiscount : public DiscountStrategy {
public:
    double applyDiscount(double price) override {
        return price;
    }
};

class TenPercentDiscount : public DiscountStrategy {
public:
    double applyDiscount(double price) override {
        return price * 0.90;
    }
};

class TwentyPercentDiscount : public DiscountStrategy {
public:
    double applyDiscount(double price) override {
        return price * 0.80;
    }
};

int main() {
    double price;
    int choice;

   
    NoDiscount noDisc;
    TenPercentDiscount tenDisc;
    TwentyPercentDiscount twentyDisc;

    DiscountStrategy* strategies[] = { &noDisc, &tenDisc, &twentyDisc };

    cout << "Enter the original price: ";
    cin >> price;

    cout << "Choose a discount strategy:\n"
         << "1. No Discount\n"
         << "2. 10% Discount\n"
         << "3. 20% Discount\n"
         << "Enter choice: ";
    cin >> choice;
       
        if (choice >= 1 && choice <= 3) {
            double discounted = strategies[choice - 1]->applyDiscount(price);
            cout << "Discounted Price: " << discounted << endl;
        } else {
            cout << "Invalid choice." << endl;
        }

    return 0;
}
