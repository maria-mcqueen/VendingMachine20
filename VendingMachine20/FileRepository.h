//
// Created by tenni on 20/05/2023.
//

#ifndef LAB12_13_POO_20MAI_FILEREPOSITORY_H
#define LAB12_13_POO_20MAI_FILEREPOSITORY_H

#pragma once
#include "Repository.h"
#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;

class FileRepository : public Repository {
private:
    string fileName;

public:
    FileRepository(const string& fileName);
    void loadFromFile();
    void saveToFile();

    void addProduct(Product &product) override;
    void modifyProduct(Product &product) override;
    void deleteProduct(int cod) override;
    vector<Product *> getAll() override;
    int getCurrentSize() override;
};



#endif //LAB12_13_POO_20MAI_FILEREPOSITORY_H
