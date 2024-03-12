//
// Created by tenni on 20/05/2023.
//

#ifndef LAB12_13_POO_20MAI_REPOSITORY_H
#define LAB12_13_POO_20MAI_REPOSITORY_H



#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

class Repository {
private:
    int currentProductSize = 0;

protected:
    vector <Product *> products;

public:
    Repository();
    virtual int getCurrentSize();
    virtual void addProduct(Product &product);
    virtual void deleteProduct(int cod);
    virtual void modifyProduct(Product &newProduct);
    virtual vector<Product *> getAll();
};

#endif //LAB12_13_POO_20MAI_REPOSITORY_H
