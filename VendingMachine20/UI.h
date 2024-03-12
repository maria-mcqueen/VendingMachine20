//
// Created by tenni on 20/05/2023.
//

#ifndef LAB12_13_POO_20MAI_UI_H
#define LAB12_13_POO_20MAI_UI_H

#include "Service.h"

class UI {
private:
    Service *service;
    static void printMenu();
    void printProducts();
    void addProduct();
    void deleteProduct();
    void modifyProduct();
    void sortProductsByPrice();
    void filterProductsHigherThan();

    void addBancnota();
    void printBancnote();
    void deleteBancnota();

    void buyProduct();

public:
    UI() = default;
    UI(Service &service);
    int start();

    void bancnote();
};



#endif //LAB12_13_POO_20MAI_UI_H
