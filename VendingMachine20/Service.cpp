//
// Created by tenni on 20/05/2023.
//

#include <algorithm>
#include "Service.h"

Service::Service(Repository &repo, BanknotesRepo &banknotesRepo) {
    this->repo = &repo;
    this->banknotesRepo = &banknotesRepo;
}

int Service::getCurrentSize() {
    return this->repo->getCurrentSize();
}

vector <Product *> Service::getAll(){
    return this->repo->getAll();
}

void Service::addProduct(int cod, char *name, int pret) {
    int exists = 0;
    for (const auto produs:this->getAll()){
        if (produs->getCod() == cod)
            exists = 1;
    }
    if (exists)
        throw invalid_argument("Exista un alt produs in tonomat cu acest cod");
    if (pret < 0 || pret > 1000)
        throw invalid_argument("Pretul introdus nu este valid!");
    if (cod < 0 || cod > 1000)
        throw invalid_argument("Codul introdus nu este valid!");

    Product newProduct = Product(cod, name, pret);
    this->repo->addProduct(newProduct);
}

void Service::deleteProduct(int cod) {
    int exists = 0;
    for (const auto produs:this->getAll()){
        if (produs->getCod() == cod)
            exists = 1;
    }
    if (exists == 0)
        throw invalid_argument("Produsul nu exista");
    else
        this->repo->deleteProduct(cod);
}

void Service::addBancnota(int valoare) {
    vector <int> bancnote = {1, 5, 10, 50, 100, 200, 500};
    bool found = false;
    for (int i = 0; i < 7; ++i) {
        if (valoare == bancnote[i]){
            found = true;
            this->banknotesRepo->addBancnota(i);
            break;
        }
    }
    if (!found)
        throw invalid_argument("Bancnota invalida");
}

vector<int> Service::getAllBancnote() {
    return this->banknotesRepo->getAll();
}

void Service::deleteBancnota(int valoare) {
    // sa nu se stearga decat daca exista cel putin o bancnota de valoare respectiva in tonomat
    vector <int> bancnote = {1, 5, 10, 50, 100, 200, 500};
    bool found = false;
    for (int i = 0; i < 7; ++i) {
        if (valoare == bancnote[i]){
            found = true;
            this->banknotesRepo->deleteBancnota(i);
            break;
        }
    }
    if (!found)
        throw invalid_argument("Bancnota invalida");
}

void Service::modifyProduct(int cod, char *newName, int newPret) {
    int exists = 0;
    for (const auto produs:this->getAll()){
        if (produs->getCod() == cod)
            exists = 1;
    }
    if (!exists)
        throw invalid_argument("Nu exista niciun produs cu acest cod");
    if (newPret < 0 || newPret > 1000)
        throw invalid_argument("Pretul introdus nu este valid!");
    if (cod < 0 || cod > 1000)
        throw invalid_argument("Codul introdus nu este valid!");

    Product newProduct = Product(cod, newName, newPret);
    this->repo->modifyProduct(newProduct);
}

vector<Product *> Service::sortByPrice() {
    vector <Product *> products = this->getAll();
    sort(products.begin(), products.end(), [](Product *a, Product *b){ return (a->getPret() < b->getPret());});
    return products;
}

//vector<Product *> Service::filterPriceHigherThan(int limit) {
//    vector <Product *> products = this->getAll();
//    vector <Product *> filtered;
//
//    if (limit < 0 || limit > 1000)
//        throw invalid_argument("Nu e bine");
//
//    for (const auto p: products){
//        if (p->getPret() > limit)
//            filtered.push_back(p);
//    }
//
//    return filtered;
//}

Product Service::getByCode(int cod) {
    for (const auto p:this->getAll()){
        if (p->getCod() == cod){
            return *p;
        }
    }
    throw invalid_argument("Codul nu este valid uwu"); // daca nu am returnat nimic
}

int Service::changeOccurrenceToBanknote(int i) {
    int v[7] = {1, 5, 10, 50, 100, 200, 500};
    for (int j = 0; j < 7; ++j) {
        if (j == i)
            return v[j];
    }
    throw invalid_argument("lmao");
}

vector<int> Service::buyProduct(int rest) {

    vector <int> available = this->getAllBancnote();
    vector <int> change = {0, 0, 0, 0, 0, 0, 0};

    int i = 6, value;

    while (rest != 0 && i >= 0){
        value = changeOccurrenceToBanknote(i);

        while (available[i] != 0 && value <= rest){
            // cat timp am cel putin o bancnota de felul ala si bancnota aia e necesara pt a plati restul
            // o sterg din available si din repo
            // si o adaug in ce returnez
            change[i] += 1;
            this->banknotesRepo->deleteBancnota(i);
            available = this->getAllBancnote();
            rest -= value;
        }
        i--;
    }
    return change;
}

