#ifndef SUPERMARKET_CPP
#define SUPERMARKET_CPP

#include "supermarket.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

Supermarket::Supermarket() {

 int simTime;
 int queueLimit;
 int customerArrival;
 int numberOfCashiers;
 std::string name;


 this->timer_ = 0;

 std::cout << "Please, set the simulation time in hours:\n";
 std::cin >> simTime;

 this->simTime_ = simTime*60;

 std::cout << "Please, type the name of the supermarket:\n";
 std::cin >> name;
 this->name_ = name;

 std::cout << "Please, type the maximum size of the queue:\n";
 std::cin >> queueLimit;
 this->queue_size_limit_ = queueLimit;

 std::cout << "Please, type the customer arriving interval:\n";
 std::cin >> customerArrival;
 this->customerArrivalInt_ = customerArrival;

 this->unattendedCustomers_ = 0;

 this->lostRevenue_ = 0;

 this->cashiers = new CircularList<Cashier>();

 std::cout << "How many cashiers would you like to add?\n";
 std::cin >> numberOfCashiers;

 for (int i = 0; i < numberOfCashiers; i++) {
     std::string cashierName;
     int cashierEff;
     int cashierIncome;

     std::cout << "Please type in the cashier's name\n";
     std::cin >> cashierName;

     std::cout << "Cashier Efficiency?\n1 - good\n2 - average\n3 - bad\n";
     std::cin >> cashierEff;

     std::cout << "What is the cashier's income??\n";
     std::cin >> cashierIncome;

     Cashier newCashier = Cashier(cashierName, cashierEff, cashierIncome);
     cashiers->push_back(newCashier);
 }
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

     Customer firstCustomer = Customer(timer_);
     this->chooseCashier(firstCustomer);
     Cashier thisCashier;
     Customer thisCustomer;

    while (this->timer_ <= simTime_) {
     for (int i = 0; i < cashiers->size(); i++) {
         thisCashier = cashiers->at(i);
        if (thisCashier.getQueueSize() > 0) {
            thisCustomer = thisCashier.getCustomer();
            if (thisCustomer.getExitTime() == this->timer_) {
                thisCashier.checkOut();
            }

            if (this->timer_ % customerArrivalInt_ == 0) {
                Customer arrival = Customer(this->timer_);
                if(!this->chooseCashier(arrival)) {
                    unattendedCustomers_++;
                    lostRevenue_ += arrival.getTotalItemsPrice();
                } else {
                    int wait = thisCashier.setWaitingTime(arrival);
                    thisCustomer.setExitTime(wait+this->timer_);
                    thisCashier.setTotalWaitingTime(wait);
                    }
            }
        }
        this->timer_++;
     }

    }
        this->calculateTotals();

        std::cout << "Simulation terminated successfully.\n";
        std::cout << "\n";
        std::cout << this->getName();
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "Total Revenue: " << this->totalRevenue_ << std::endl;
        std::cout << "Average Revenue: " << this->averageRevenue_ << std::endl;
        std::cout << "Average Waiting Time: " << this->averageWait_ << std::endl;
        std::cout << "Unattended Customers: " << this->unattendedCustomers_ << std::endl;
        std::cout << "Lost Revenue: " << this->lostRevenue_ << std::endl;
        std::cout << "Cashiers Revenue:\n" << std::endl;
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

    std::cout << "Please enter the name of the new Cashier:\n";
    std::cin >> name;
    std::cout << "Please enter the efficiency level of the new Cashier:\n";
    std::cin >> eff;
    std::cout << "Please enter the income of the new Cashier:\n";
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

    for (int i = 0; i < cashiers->size(); i++) {
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
 void Supermarket::calculateTotals() {
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
     if (attendedCustomers != 0) {
     this->averageRevenue_ = total/attendedCustomers;
     }
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
        std::cout << "Cashier's name:\n" << name;
        std::cout << "Cashier's total revenue:\n" << total;
        std::cout << "Cashier's average revenue:\n" << average;
        std::cout << "Cashier's profit:\n" << profit;
    }
    }


 #endif // SUPERMARKET_CPP
