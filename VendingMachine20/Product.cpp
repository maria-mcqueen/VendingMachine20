//
// Created by tenni on 20/05/2023.
//

#include "Product.h"
#include <string.h>

Product::Product() {
    this->cod = 0;
    this->pret = 0;
    this->name = NULL;
}

Product::Product(int cod, char *name, int pret) {
    this->cod = cod;
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
    this->pret = pret;
}

int Product::getCod() {
    return this->cod;
}

char *Product::getName() {
    return this->name;
}

int Product::getPret() {
    return this->pret;
}

Product::Product(Product &otherProduct) {
    this->cod = otherProduct.getCod();
    this->pret = otherProduct.getPret();

    this->name = new char[strlen(otherProduct.getName()) + 1];
    strcpy_s(this->name, strlen(otherProduct.getName()) + 1, otherProduct.getName());
}

bool Product::operator==(Product other) {
    if (this->cod != other.getCod())
        return false;
    if (strcmp (this->name, other.getName()) != 0)
        return false;
    if (this->pret != other.getPret())
        return false;
    return true;
}

void Product::setPret(int newPret) {
    this->pret = newPret;
}

void Product::setName(char *newName) {
    this->name = new char[strlen(newName) + 1];
    strcpy_s(this->name, strlen(newName) + 1, newName);
}
