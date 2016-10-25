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

 this->simTime_ = (simTime*60);

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

 this->simTime_ = simulation;

 this->name_ = name;

 this->queue_size_limit_ = 10;

 this->customerArrivalInt_ = arrival;

 this->cashiers = new CircularList<Cashier>();

}

 Supermarket::~Supermarket() {
 }


 void Supermarket::run() {
  // cria o primeiro cliente. sua chegada dispara o programa
    Customer firstCustomer = Customer(timer_);
  //  escolhe um caixa para o primeiro cliente
    this->chooseCashier(firstCustomer);
  // gera a hora de chegada do próximo cliente
    int nextCustomer = (customerArrivalInt_ + (std::rand() % 5));

  //  cria um laço para, enquanto o relógio não chegar ao fim da simulação...
    while (timer_ <= simTime_) {
     //  ...percorrer a lista circular, caixa por caisa
            for( int i = 0; i < cashiers->size(); i++) {
                Cashier thisCashier = cashiers->at(i);
             //  se a fia do caixa não for vazia...
                if (thisCashier.getQueueSize() >  0) 
                 //  ...verifica se está na hora de o primeiro cliente ser atendido
                    Customer thisCustomer = thisCashier.getCustomer();
                    if (thisCustomer.getExitTime() == timer_) {
                        thisCashier.checkOut();
                    }
                }
            }
  //  aqui, verificamos se está na hora do próximo cliente chegar

            if (nextCustomer == timer_) {
                Customer arrival = Customer(timer_);
             //  se estiver, escolhemos um caixa pra ele, se houver
                if (chooseCashier(arrival)) {
                    nextCustomer += (customerArrivalInt_ + (std::rand() % 5));
                } else {  //  se não houver, ele abandona o carrinho. o valor de suas compras é multiplicdo por três.
                    this->unattendedCustomers_++;
                    this->lostRevenue_ += (arrival.getTotalItemsPrice() * 3);
                }
            }
            timer_++;
        }

//  ao final da simulação, calcula-se os totais que o sistema deve informar ao usuário
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
/*!
    bool Supermarket::chooseCashier(Customer& customer) {
        int searchType = customer.getCashierSearchType();
        Cashier& choice = cashiers->at(0);

        if (searchType == 0) {
            for (int i = 1; i<cashiers->size(); i++) {
                Cashier& assert = cashiers->at(1);
                if (choice.getQueueSize() > assert.getQueueSize()) {
                    choice = assert;
                }
            }
            choice.add(customer);
            int wait = choice.setWaitingTime(customer);
            customer.setExitTime(wait+this->timer_);
            choice.setTotalWaitingTime(wait);
            return true;
        } else if (searchType == 1) {
            for (int i = 1; i<cashiers->size(); i++) {
                Cashier& assert = cashiers->at(1);
                if (choice.getTotalOfItems() > assert.getTotalOfItems()) {
                    choice = assert;
                }
            }
            choice.add(customer);
            int wait = choice.setWaitingTime(customer);
            customer.setExitTime(wait+this->timer_);
            choice.setTotalWaitingTime(wait);
            return true;
        } else {
            return false;
        }
    } */

 bool Supermarket::chooseCashier(Customer& customer) {
    Cashier &bestCashierForQueueSize = cashiers->at(1);
    int smallestQueueSize = bestCashierForQueueSize.getQueueSize();
    Cashier &bestCashierForTotalOfItems = cashiers->at(0);
    int smallestTotalOfItems = bestCashierForTotalOfItems.getQueueSize();
    Cashier choice;

    for (int i = 0; i < cashiers->size(); i++) {
        choice = cashiers->at(i);

        if (choice.getQueueSize() <= smallestQueueSize) {
            smallestQueueSize = choice.getQueueSize();
            bestCashierForQueueSize = choice;
        }

        if (choice.getItemsSize() <= smallestTotalOfItems) {
            smallestTotalOfItems = choice.getItemsSize();
            bestCashierForTotalOfItems = choice;
        }
    }

    if (smallestQueueSize >= this->queue_size_limit_ -1) {
        return false;
    }

    if (customer.getCashierSearchType() == 0) {
        bestCashierForQueueSize.add(customer);
        int wait = bestCashierForQueueSize.setWaitingTime(customer);
        customer.setExitTime(wait+this->timer_);
        bestCashierForQueueSize.setTotalWaitingTime(wait);
        return true;
    }

    if (customer.getCashierSearchType() == 1) {
        bestCashierForTotalOfItems.add(customer);
        int wait = bestCashierForTotalOfItems.setWaitingTime(customer);
        customer.setExitTime(wait+this->timer_);
        bestCashierForTotalOfItems.setTotalWaitingTime(wait);
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
        std::cout << "\nCashier's name: " << name << std::endl;
        std::cout << "\nCashier's total revenue: " << total << std::endl;
        std::cout << "\nCashier's average revenue: " << average << std::endl;
        std::cout << "\nCashier's profit: " << profit << std::endl;
    }
    }


 #endif // SUPERMARKET_CPP
