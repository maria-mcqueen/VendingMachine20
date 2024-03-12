//
// Created by tenni on 20/05/2023.
//

#include "FileRepository.h"

#include <fstream>

FileRepository::FileRepository(const string& fileName) : fileName(fileName) {
    this->fileName = fileName;
    loadFromFile();
}

void FileRepository::loadFromFile() {
    ifstream f(this->fileName);

    if (!f.is_open()){
        cout<<"Fisierul nu a putut fi deschis!";
        return;
    }

    products.clear();

    while (!f.eof()){
        int cod, pret;
        string name_str;

        while( f >> cod >> name_str >> pret){
            char* name = new char[name_str.length() + 1];
            strcpy(name, name_str.c_str());
            Product product = Product(cod, name, pret);
            Product *p = new Product(product);
            this->products.push_back(p);
        }
    }
    f.close();
}

void FileRepository::saveToFile() {

    ofstream file(fileName);

    if (!file.is_open()){
        cout<<"Fisierul nu a putut fi deschis!";
        return;
    }

    for (const auto &p: Repository :: getAll()){
        file<<p->getCod()<<" "<<p->getName()<<" "<<p->getPret()<<endl;
    }
    file.close();
}

void FileRepository::addProduct(Product &product) {
    Repository::addProduct(product);
    saveToFile();
}

void FileRepository::modifyProduct(Product &product) {
    Repository::modifyProduct(product);
    saveToFile();
}

void FileRepository::deleteProduct(int cod) {
    Repository::deleteProduct(cod);
    saveToFile();
}

vector<Product *> FileRepository::getAll() {
    loadFromFile();
    return products;
}

int FileRepository::getCurrentSize() {
    loadFromFile();
    return Repository::getCurrentSize();
}
