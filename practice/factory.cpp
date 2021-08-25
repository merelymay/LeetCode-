#include "pub_head.h"
using namespace std;

class Product {
public:
    virtual void show() {

    }
};

class ProductA : public Product {
public:
    void show() {
        cout << "Product A" << endl;
    }
};

class ProductB : public Product {
public:
    void show() {
        cout<< "Product B" << endl;
    }
};

enum PRODUCT_TYPE {
    A,
    B
};

class SimpleFactory {
public:
    Product *CreateProduct(PRODUCT_TYPE type) {
        switch (type)
        {
        case A:
            return new ProductA();
            break;
        case B:
            return new ProductB();
            break;
        default:
            break;
        }
    }
};

int main() {
    SimpleFactory factory;

    Product *productA = factory.CreateProduct(A);
    if (productA != nullptr) {
        productA->show();
    }

}