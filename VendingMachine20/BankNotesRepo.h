//
// Created by tenni on 20/05/2023.
//

#ifndef LAB12_13_POO_20MAI_BANKNOTESREPO_H
#define LAB12_13_POO_20MAI_BANKNOTESREPO_H


#include <iostream>
#include <vector>
using namespace std;

class BanknotesRepo {
private:
    vector<int> occurrences;
public:
    BanknotesRepo();
    void addBancnota(int value);
    vector<int> getAll();
    void deleteBancnota(int value);

};

#endif //LAB12_13_POO_20MAI_BANKNOTESREPO_H
