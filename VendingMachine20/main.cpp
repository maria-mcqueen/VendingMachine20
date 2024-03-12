#include <iostream>
#include "UI.h"
#include "FileRepository.h"
#include "Teste.h"

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    //test_all();


    FileRepository repo = FileRepository("C:\\Users\\tenni\\CLionProjects\\lab12_13_poo_20MAI\\products.txt");
    BanknotesRepo banknotesRepo = BanknotesRepo();

    Service service = Service(repo, banknotesRepo);
    UI ui = UI(service);

    ui.start();

    return 0;
}
