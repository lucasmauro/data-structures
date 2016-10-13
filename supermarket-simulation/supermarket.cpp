#ifndef SUPERMARKET_CPP
#define SUPERMARKET_CPP

#include "supermarket.hpp"

using namespace supermarket;

Supermarket::Supermarket() {

 this->timer = 0;

 this->simTime = 3600;

 this->name "SuperPobre";

 this->maxQueueSize = 10;

 this->customerArrivalInt = 5;

 this->unattendedCustomers = 0;

 this->lostRevenue = 0;

}

 Supermarket::~Supermarket() {
    delete supermarket;
 }

 void Supermarket::run() {
     Cashier cashier;
     arrival = getCustomerArrival();
    while(timer<=simTime)
    {
        if(timer%arrival == 0)
            {
                Customer newCustomer = new Customer(timer);
                if (!newCustomer.chooseCashier(supermarket)) {
                    this->unattendedCustomers++;
                    this->lostRevenue += newCustomer->getTotalItemsPrice();
                    this->callOvertime();
                }
            }
        for(int i = 0; i< supermarket->size(); i++)
        {
            cashier = supermarket.at(i);
            if(cashier.nextCheckout == getTimer()) {
                cashier.handleCustomer;
            }
        }
    }
    }

 int Supermarket::getTimer() {
    return timer;
    }

 string Supermarket::getName() {
    return name;
    }

 int Supermarket::getCustomerArrival() {
    return customerArrivalInt;
    }

 int Supermarket::getUnatended() {
    return unattendedCustomers;
    }

 int Supermarket::getLostRevenue() {
    return lostRevenue;
    }

 void Supermarket::callOvertime() {
    string name = ;
    int eff;
    int income;

    cout << "Please enter the name of the new Cashier: ";
    cin >> name;
    cout << "Please enter the efficiency level of the new Cashier: ";
    cin >> eff;
    cout << "Please enter the income of the new Cashier: ";
    cin >> income;
    cout << "Thanks";

    Cashier cashier = new Cashier(name, eff, income);
    supermarket.push(cashier);
    }

 int Supermarket::maxQueueSize() {
    return maxQueueSize;
    }

 void Supermarket::readFile(){}
