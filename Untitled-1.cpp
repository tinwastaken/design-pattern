#include <iostream>
using namespace std;

class Discount {
public:
    virtual float apply(float amount) = 0;
    virtual ~Discount() {}
};

class NoDiscount : public Discount {
public:
    float apply(float amount) override {
        return amount;
    }
};

class TenPercentDiscount : public Discount {
public:
    float apply(float amount) override {
        return amount * 0.9f;
    }
};

class TwentyPercentDiscount : public Discount {
public:
    float apply(float amount) override {
        return amount * 0.8f;
    }
};

class DiscountCalculator {
private:
    Discount* discount;
public:
    DiscountCalculator() : discount(nullptr) {}
    
    ~DiscountCalculator() {
        delete discount;
    }

    void setDiscount(Discount* disc) {
        delete discount;
        discount = disc;
    }

    float calculate(float amount) {
        if (discount) {
            return discount->apply(amount);
        } else {
            cout << "Discount not set!" << endl;
            return amount;
        }
    }
};

int main() {
    float amount;
    int choice;

    cout << "Enter amount: ";
    cin >> amount;

    cout << "Enter discount (No discount, 10%, 20%): ";
    cin >> choice;

    DiscountCalculator calc;

    switch (choice) {
        case 0: calc.setDiscount(new NoDiscount()); break;
        case 1: calc.setDiscount(new TenPercentDiscount()); break;
        case 2: calc.setDiscount(new TwentyPercentDiscount()); break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    float total = calc.calculate(amount);
    cout << "Total after discount: " << total << " pesos" << endl;

    return 0;
}
