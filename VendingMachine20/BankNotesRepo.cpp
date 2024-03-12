//
// Created by tenni on 20/05/2023.
//

#include "BanknotesRepo.h"

BanknotesRepo::BanknotesRepo() {
    this->occurrences = {0, 0, 0, 0, 0, 0, 0};
}

void BanknotesRepo::addBancnota(int value) {
    this->occurrences[value]++;
}

vector<int> BanknotesRepo::getAll() {
    return this->occurrences;
}

void BanknotesRepo::deleteBancnota(int value) {
    if (this->occurrences[value] > 0)
        this->occurrences[value]--;
    else
        throw invalid_argument("Bancnota nu a putut fi stearsa");
}

