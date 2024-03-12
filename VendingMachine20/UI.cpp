//
// Created by tenni on 20/05/2023.
//

#include "UI.h"
#include <cstring>
#include <exception>
#include "Validator.h"

UI::UI(Service &service){
    this->service = &service;
}

void UI::printMenu() {
    cout<<endl;
    cout<<"1.adaugare produs: "<<endl;
    cout<<"2.afisare lista produse: "<<endl;
    cout<<"3.modif produs: "<<endl;
    cout<<"4.stergere produs: "<<endl;
    cout<<"5.sortare dupa pret: "<<endl;
    cout<<"7.adaugare bancnota: "<<endl;
    cout<<"8.afisare bancnote: "<<endl;
    cout<<"10.achizitionare produs: "<<endl;
}

void UI::printProducts() {
    for (const auto p:this->service->getAll())
        cout<<"Cod: "<<p->getCod()<<", Nume: "<<p->getName()<<", Pret: "<<p->getPret()<<endl;
}

void UI::addProduct() {
    try{
        int pret;
        string name_str;
        string raw_cod;
        cout<<"Introduceti codul produsului: ";
        cin>>raw_cod;
        cout<<"Introduceti numele produsului: ";
        cin>>name_str;
        cout<<"Introduceti pretul produsului: ";
        cin>>pret;
        char* name = new char[name_str.length() + 1];
        strcpy(name, name_str.c_str());
        int cod = Validator::isNumber(raw_cod);
        this->service->addProduct(cod, name, pret);
    }

    catch (std::exception &e){
        cout<<e.what()<<endl;
    }
}

void UI::deleteProduct() {
    try{
        string raw_cod;
        cout<<"dati codul produsului: ";
        cin>>raw_cod;
        int cod = Validator::isNumber(raw_cod);
        this->service->deleteProduct(cod);
    }
    catch (std::exception &e){
        cout<<e.what()<<endl;
    }
}

void UI::modifyProduct() {
    try{
        int pret;
        string name_str;
        string raw_cod;
        cout<<"dati codul de modificat: ";
        cin>>raw_cod;
        cout<<"numele nou: ";
        cin>>name_str;
        cout<<"pretul nou: ";
        cin>>pret;
        char* name = new char[name_str.length() + 1];
        strcpy(name, name_str.c_str());
        int cod = Validator::isNumber(raw_cod);
        this->service->modifyProduct(cod, name, pret);
    }

    catch(std::exception &e){
        cout<<e.what()<<endl;
        return;
    }
}

void UI::sortProductsByPrice() {
    vector <Product *> sorted = this->service->sortByPrice();
    for (const auto p: sorted){
        cout<<"Cod: "<<p->getCod()<<", Nume: "<<p->getName()<<", Pret: "<<p->getPret()<<endl;
    }
}


void UI::addBancnota() {
    try{
        string raw_val;
        cout<<"tipul bancnotei: ";
        cin>>raw_val;
        int val = Validator::isNumber(raw_val);
        this->service->addBancnota(val);
    }
    catch (std::exception &e){
        cout<<e.what()<<endl;
    }
}

void UI::printBancnote() {
    vector <int> bancnote = service->getAllBancnote();
    vector <int> valori = {1, 5, 10, 50, 100, 200, 500};
    for (int i = 0; i < 7; ++i) {
        cout << bancnote[i] << " bancnote de " << valori[i] << endl;
    }
}

void UI::deleteBancnota() {
    try{
        int banc;
        cout<<"bancnota de sters: ";
        cin>>banc;
        this->service->deleteBancnota(banc);
    }
    catch(std::exception &e){
        cout<<e.what()<<endl;
    }
}

void UI::bancnote() {
    vector<int> bancnote = {1, 5, 10, 50, 100, 200};
    for (int j = 0; j < 5; j++)
        for (int i = 0; i < 6; i++)
            this->service->addBancnota(bancnote[i]);
}

void UI::buyProduct() {
    this->printProducts();
    //int cod;
    string raw_cod;
    cout<<"produsul de achizitionat: ";
    cin>>raw_cod;
    try{
        int cod = Validator::isNumber(raw_cod);
        int money, price, rest, x;
        price = this->service->getByCode(cod).getPret();
        cout << "de platit " << price << " lei" << endl << endl;
        cout << "introducere bancnota: ";
        cin >> money;
        rest = money - price;  // cati bani ai introdus

        while (rest < 0){
            cout<<"prea putini lmao mai baga "<<endl;
            cout << "introducere bancnota: ";
            cin>>x;
            money += x;
            rest = money - price;
        }

        vector<int> change = this->service->buyProduct(rest);
        cout << "tranzactie efectuata" << endl;
        cout << "restul este :"<<endl;
        vector<int> v = {1, 5, 10, 50, 100, 200, 500};
        bool found = false;
        for (int i = 0; i < 7; ++i) {
            if (change[i] != 0){
                cout << change[i] << " bancnote de " << v[i] << " lei" << endl;
                found = true;
            }
        }
        if (!found)
            cout << "nu e rest :(" << endl;
    }

    catch(std::exception &e){
        cout<<e.what()<<endl;
    }
}


int UI::start() {
    this->bancnote();
    //int opt;
    string raw_opt;
    while (true) {
        this->printMenu();
        cout << "optiunea: ";
        cin >> raw_opt;
        //int opt = Validator::isNumber(raw_opt);

        try {
            int opt = Validator::isNumber(raw_opt);
            switch (opt) {
                case 1:
                    this->addProduct();
                    break;
                case 2:
                    this->printProducts();
                    break;
                case 3:
                    this->modifyProduct();
                    break;
                case 4:
                    this->deleteProduct();
                    break;
                case 5:
                    this->sortProductsByPrice();
                    break;
                case 6:
                    break;
                case 7:
                    this->addBancnota();
                    break;
                case 8:
                    this->printBancnote();
                    break;
                case 9:
                    break;
                case 10:
                    this->buyProduct();
                    break;
                case 0:
                    break;
                default:
                    return 0;
            }
        } catch (std::exception &e) {
            cout << e.what() << endl;
        }
    }

}