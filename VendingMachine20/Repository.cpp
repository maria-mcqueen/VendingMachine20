//
// Created by tenni on 20/05/2023.
//

#include "Repository.h"


#include "string.h"


Repository::Repository() {

}

int Repository::getCurrentSize() {
    return this->currentProductSize;
}

void Repository::addProduct(Product &product) {
    Product *p = new Product(product);
    this->products.push_back(p);
    this->currentProductSize++;
}

vector<Product *> Repository::getAll() {
    return this->products;
}

void Repository::deleteProduct(int cod) {
    int position = 0; // poz elem de sters

    for (const auto p: this->getAll()){
        if (p->getCod() == cod){
            this->currentProductSize--;

            for (int j = position; j < this->getCurrentSize(); j++)
                this->products.at(j) = this->products.at(j+1);

            this->products.pop_back();
            break;
        }
        position++;
    }
}

void Repository::modifyProduct(Product &newProduct) {
    int cod = newProduct.getCod();
    int i = 0;
    for (const auto p:this->getAll()){
        if (p->getCod() == cod){
            this->products[i]->setPret(newProduct.getPret());
            char* newName = new char[strlen(newProduct.getName()) + 1];
            strcpy_s(newName, strlen(newProduct.getName()) + 1, newProduct.getName());
            this->products[i]->setName(newName);
            break;
        }
        i++;
    }
}