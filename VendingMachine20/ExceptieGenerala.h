//
// Created by tenni on 20/05/2023.
//

#ifndef LAB12_13_POO_20MAI_EXCEPTIEGENERALA_H
#define LAB12_13_POO_20MAI_EXCEPTIEGENERALA_H

#include <iostream>


class ExceptieGenerala: public std::exception {
private:
    std::string message;
public:
    ExceptieGenerala(std::string message): message(message){}

    const char *what() const noexcept override {
        return message.c_str();
    }
};


#endif //LAB12_13_POO_20MAI_EXCEPTIEGENERALA_H
