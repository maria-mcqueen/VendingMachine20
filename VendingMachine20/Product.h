//
// Created by tenni on 20/05/2023.
//

#ifndef LAB12_13_POO_20MAI_PRODUCT_H
#define LAB12_13_POO_20MAI_PRODUCT_H

class Product {
private:
    int cod;
    char* name;
    int pret;
public:
    Product();
    Product(int cod, char* name, int pret);
    Product(Product &otherProduct);


    int getCod();
    char* getName();
    int getPret();

    void setPret(int newPret);
    void setName(char* newName);

    bool operator == (Product other);
};



#endif //LAB12_13_POO_20MAI_PRODUCT_H
