//
// Created by tenni on 20/05/2023.
//

#include "Teste.h"

#include "Product.h"
#include "Repository.h"
#include "Service.h"
#include "FileRepository.h"
#include <string.h>
#include <cassert>

void testProduct(){
    /// test constructor implicit
    Product p;
    assert (p.getName() == NULL);
    assert (p.getCod() == 0);
    assert (p.getPret() == 0);

    /// test constructor cu parametri
    Product pr(1, "croisant", 5);
    assert (strcmp(pr.getName(), "croisant") == 0);
    assert (pr.getCod() == 1);
    assert (pr.getPret() == 5);

    /// test copy constructor
    Product pr1 = Product(pr);
    assert (pr1.getCod() == 1);
    assert (pr1.getPret() == 5);
    assert (strcmp(pr1.getName(), "croisant") == 0);
}

void testRepo(){
    /// test constructor
    Repository repo;
    assert (repo.getCurrentSize() == 0);

    /// test adaugare
    Product pr1(1, "croisant", 5);
    Product pr2(2, "suc", 4);
    repo.addProduct(pr1);
    repo.addProduct(pr2);
    assert (repo.getCurrentSize() == 2);

    /// test getAll
    vector <Product *> products = repo.getAll();
    assert (pr1 == Product(*products[0]));
    assert (pr2 == Product(*products[1]));
}

void test_delete_repo(){
    Repository repo;
    Product product1 = Product(1, "carne", 5);
    Product product2 = Product(2, "cascaval", 4);
    Product product3 = Product(3, "sunca", 12);
    repo.addProduct(product1), repo.addProduct(product2), repo.addProduct(product3);

    repo.deleteProduct(2);
    assert (repo.getCurrentSize() == 2);
    vector <Product *> products = repo.getAll();
    assert (Product(*products[0]) == product1);
    assert (Product(*products[1]) == product3);
}

void testService(){
    Repository repo;
    BanknotesRepo br;
    Product product(1, "croisant", 5);
    repo.addProduct(product);

    /// test constructor
    Service service = Service(repo, br);
    assert (service.getCurrentSize() == 1);

    /// test add
    service.addProduct(2, "suc", 4);
    assert (service.getCurrentSize() == 2);

    /// test getAll
    vector <Product *> products = service.getAll();
    assert (product == Product(*products[0]));
    assert (products[1]->getCod() == 2);
    assert (products[1]->getPret() == 4);
    assert (strcmp(products[1]->getName(), "suc") == 0);
}


void test_sort_by_price(){
    Repository repo;
    BanknotesRepo br;
    Product product1 = Product(1, "carne", 5);
    Product product2 = Product(2, "cascaval", 4);
    Product product3 = Product(3, "sunca", 12);
    repo.addProduct(product1), repo.addProduct(product2), repo.addProduct(product3);
    Service service = Service(repo, br);

    vector <Product *> sorted = service.sortByPrice();
    assert (product2 == Product(*sorted[0]));
    assert (product1 == Product(*sorted[1]));
    assert (product3 == Product(*sorted[2]));

}



void test_file_repo(){
    FileRepository repo = FileRepository("C:\\Users\\tenni\\CLionProjects\\lab12_13_poo_20MAI\\products.txt");

    /// test citire din fisier
    vector <Product *> products = repo.getAll();
    assert (products.size() == 8);

    /// test adaugare in fisier
    Product product1 = Product(9, "carne", 11);
    repo.addProduct(product1);
    products = repo.getAll();
    assert (products.size() == 9);
    //assert (product1 == Product(*products[7]));

    /// test modificare in fisier
    Product product2 = Product(9, "carne", 10);
    repo.modifyProduct(product2);
    products = repo.getAll();
    //assert (product2 == Product(*products[7]));

    /// test stergere in fisier
    repo.deleteProduct(8);
    products = repo.getAll();
    assert (products.size() == 8);
}

void test_all(){
    testProduct();
    testRepo();
    testService();
    test_delete_repo();
    test_sort_by_price();
    test_file_repo();

}