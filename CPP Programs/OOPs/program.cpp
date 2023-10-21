#include <iostream>
using namespace std;

class Cars
{
private:
    int price;

public:
    int modelNumbers;
    string features;

    Cars()
    {
        cout << "Default constructor called" << endl;
    }

    Cars(int m, string f, int p)
    {
        modelNumbers = m;
        features = f;
        price = p;
    }

    void setPrice(int p)
    {
        if (p > 0)
            price = p;
        else
            price = 0;
    }

    void getPrice()
    {
        cout << "Price : " << price << endl;
    }

    float getDiscounttedPrice(float x)
    {
        return (1.0 - x) * price;
    }

    void applyDiscount(float x)
    {
        price = price * (1.0 - x);
    }

    ~Cars()
    {
        cout << "Destructor called for model number " << modelNumbers << endl;
    }
};

int main()
{
    Cars bmw = Cars();
    bmw.modelNumbers = 123;
    bmw.features = "Automatic";
    bmw.setPrice(100);

    cout << "Model Number: " << bmw.modelNumbers << endl;
    cout << "Features : " << bmw.features << endl;
    bmw.getPrice();
    cout << "Discounted Price : " << bmw.getDiscounttedPrice(0.5) << endl;
    bmw.applyDiscount(0.5);
    bmw.getPrice();

    // Cars audi(456, "Automatic", 100);
    // cout << audi.modelNumbers << endl;
    // cout << audi.features << endl;
    // audi.getPrice();
    // cout << audi.getDiscounttedPrice(0.9) << endl;

    return 0;
}