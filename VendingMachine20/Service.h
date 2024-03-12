//
// Created by tenni on 20/05/2023.
//

#ifndef LAB12_13_POO_20MAI_SERVICE_H
#define LAB12_13_POO_20MAI_SERVICE_H


#include "Repository.h"
#include "BanknotesRepo.h"

class Service {
private:
    Repository *repo;
    BanknotesRepo *banknotesRepo;
public:
    Service() = default;
    Service(Repository &repo, BanknotesRepo &banknotesRepo);
    int getCurrentSize();
    vector <Product *> getAll();
    Product getByCode(int cod);
    void addProduct(int cod, char* name, int pret);
    void deleteProduct(int cod);
    void modifyProduct(int cod, char* newName, int newPret);
    vector<Product *> sortByPrice();
    vector<Product *> filterPriceHigherThan(int limit);

    void addBancnota(int valoare);
    vector<int> getAllBancnote();
    void deleteBancnota(int valoare);

    static int changeOccurrenceToBanknote(int i);
    vector<int> buyProduct(int rest);
};



#endif //LAB12_13_POO_20MAI_SERVICE_H
