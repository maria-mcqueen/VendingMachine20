//
// Created by tenni on 20/05/2023.
//

#ifndef LAB12_13_POO_20MAI_EXCEPTIEFILE_H
#define LAB12_13_POO_20MAI_EXCEPTIEFILE_H

#include <iostream>

class ExceptieFile: public std::exception {

public:
    const char * what() const noexcept override {
        return "Could not open file!";
    }
};



#endif //LAB12_13_POO_20MAI_EXCEPTIEFILE_H
