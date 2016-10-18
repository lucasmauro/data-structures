#ifndef SUPERMARKET_CPP
#define SUPERMARKET_CPP

#include "supermarket.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

Supermarket::Supermarket() {

 this->timer_ = 0;

 this->simTime_ = 0;

 this->name_ = "";

 this->queue_size_limit_ = 10;

 this->customerArrivalInt_ = 0;

 this->unattendedCustomers_ = 0;

 this->lostRevenue_ = 0;

 this->cashiers = new CircularList<Cashier>();
}

Supermarket::Supermarket(std::string name, int simulation, int arrival) {

 this->timer_ = 0;

 this->simTime_ = simulation;

 this->name_ = name;

 this->queue_size_limit_ = 10;

 this->customerArrivalInt_ = arrival;

 this->unattendedCustomers_ = 0;

 this->lostRevenue_ = 0;

 this->cashiers = new CircularList<Cashier>();

}

 Supermarket::~Supermarket() {
 }

 void Supermarket::run() {
     Cashier thisCashier = cashiers->at(0);
     Customer thisCustomer;

     while (timer_ <= simTime_) {
        thisCustomer = thisCashier.getCustomer();
        if (thisCustomer.getExitTime() == timer_) {
            thisCashier.checkOut();
        }

        if (timer_ % customerArrivalInt_ == 0) {
            Customer arrival = Customer(timer_);
            if(!this->chooseCashier(arrival)) {
                unattendedCustomers_++;
                lostRevenue_ += arrival.getTotalItemsPrice();
            } else {
                int wait = thisCashier.setWaitingTime(arrival);
                thisCustomer.setExitTime(wait+timer_);
                thisCashier.setTotalWaitingTime(wait);
                }
        }

    }
        this->calculateTotals();

        std::cout << "Simulation terminated successfully.";
        std::cout << this->getName();
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "Total Revenue:\n";
        std::cout << this->totalRevenue_;
        std::cout << "Average Revenue:\n";
        std::cout << this->averageRevenue_;
        std::cout << "Average Waiting Time:\n";
        std::cout << this->averageWait_;
        std::cout << "Unattended Customers:\n";
        std::cout << this->unattendedCustomers_;
        std::cout << "Lost Revenue:\n";
        std::cout << this->lostRevenue_;

        std::cout << "Cashiers Revenue:\n";
        this->cashiersRevenue();

}

 int Supermarket::getTimer() {
    return timer_;
    }

 std::string Supermarket::getName() {
    return name_;
    }

 int Supermarket::getCustomerArrival() {
    return customerArrivalInt_;
    }

 int Supermarket::getUnattended() {
    return unattendedCustomers_;
    }

 void Supermarket::addCashier(Cashier add) {
     cashiers->push_back(add);
 }

 int Supermarket::getLostRevenue() {
    return lostRevenue_;
    }

 void Supermarket::callOvertime() {
    std::string name;
    int eff;
    int income;

    std::cout << "Please enter the name of the new Cashier: ";
    std::cin >> name;
    std::cout << "Please enter the efficiency level of the new Cashier: ";
    std::cin >> eff;
    std::cout << "Please enter the income of the new Cashier: ";
    std::cin >> income;
    std::cout << "Thanks";

    Cashier extra = Cashier(name, eff, income);
    cashiers->push_back(extra);
    }

 void Supermarket::setName(std::string newName) {
    this->name_ = newName;
 }

  void Supermarket::setSimTime(int newSimTime) {
    this->simTime_ = newSimTime;
  }

  void Supermarket::setArrival(int newArrivalTime) {
    this->customerArrivalInt_ = newArrivalTime;
    }

  bool Supermarket::chooseCashier(Customer customer) {
    int smallestQueueSize = 0;
    int smallestTotalOfItems = 0;
    Cashier bestCashierForQueueSize = cashiers->at(0);
    Cashier bestCashierForTotalOfItems = cashiers->at(0);

    for (int i = 1; i < cashiers->size(); i++) {
        Cashier choice = cashiers->at(i);

        if (choice.getQueueSize() <= smallestQueueSize) {
            smallestQueueSize = choice.getQueueSize();
            bestCashierForQueueSize = choice;
        }

        if (customer.getItemsSize() <= smallestTotalOfItems) {
            smallestTotalOfItems = customer.getItemsSize();
            bestCashierForTotalOfItems = choice;
        }
    }

    if (smallestQueueSize >= this->queue_size_limit_) {
        return false;
    }

    if (customer.getCashierSearchType() == 0) {
        bestCashierForQueueSize.add(customer);
        return true;
    }

    if (customer.getCashierSearchType() == 1) {
        bestCashierForTotalOfItems.add(customer);
        return true;
    }

    return false;
}

 int Supermarket::maxQueueSize() {
    return queue_size_limit_;
    }
 int Supermarket::calculateTotals() {
     Cashier cash = cashiers->at(0);
     int total = cash.getTotalRevenue();
     int attendedCustomers=0;
     int wait=0;
     for(int i = 1; i<cashiers->size(); i++) {
        cash = cashiers->at(i);
        total += cash.getTotalRevenue();
        attendedCustomers += cash.getCustomersOut();
        wait += cash.getAverageWaitingTime();
     }

     this->totalRevenue_ = total;
     this->averageRevenue_ = total/attendedCustomers;
     this->averageWait_ = wait;

 }

 int Supermarket::getTotalRevenue() {
    return this->totalRevenue_;
    }

 int Supermarket::getAverageRevenue() {
    return this->averageRevenue_;
    }

 int Supermarket::getAverageWait() {
    return this->averageWait_;
    }
void Supermarket::cashiersRevenue() {
    Cashier cashy = cashiers->at(0);
    int profit;
    int average;
    int total;
    std::string name = cashy.getId();
    for(int i = 0; i<cashiers->size(); i++) {
        cashy = cashiers->at(i);
        total = cashy.getTotalRevenue();
        profit = cashy.getTotalRevenue()-cashy.getIncome();
        average = cashy.getAverageRevenue();
        std::cout << "Cashier's name:\n";
        std::cout << name;
        std::cout << "Cashier's total revenue:\n";
        std::cout << total;
        std::cout << "Cashier's average revenue:\n";
        std::cout << average;
        std::cout << "Cashier's profit:\n";
        std::cout << profit;
    }
    }


 #endif // SUPERMARKET_CPP
