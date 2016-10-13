#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include "customer.h"

Customer::Customer(){};

Customer::Customer(int arrivalTime) {
    std::srand((int) time(0));
    int itemsSize = (std::rand() % 99) + 2;

    int paymentType = (std::rand() % 5);

    int cashierSearchType = (std::rand() % 2);

    int itemsTotalPrice = 0;
    for (int i = 1; i <= itemsSize; i++) {
        std::srand((int) time(0));
        itemsTotalPrice += (std::rand() % 89) + 1;
    }

    this->arrivalTime_ = arrivalTime;
    this->paymentType_ = paymentType;
    this->itemsSize_ = itemsSize;
    this->itemsTotalPrice_ = itemsTotalPrice;
    this->cashierSearchType_ = cashierSearchType;
    this->exitTime_ = -1;
}

Customer::~Customer(){}

bool Customer::chooseCashier(CircularList<Cashier> cashiers) {
    int smallestQueueSize = 0;
    int smallestTotalOfItems = 0;
    Cashier bestCashierForQueueSize = nullptr;
    Cashier bestCashierForTotalOfItems = nullptr;

    for (int i = 0; i < cashiers.size(); i++) {
        Cashier cashier = cashiers.at(i);

        if (cashier.size() <= smallestQueueSize) {
            smallestQueueSize = cashier.size();
            bestCashierForQueueSize = cashier;
        }

        if (cashier.getTotalOfItems() <= smallestTotalOfItems) {
            smallestTotalOfItems = cashier.getTotalOfItems();
            bestCashierForTotalOfItems = cashier;
        }
    }

    if (smallestQueueSize >= this-> queue_size_limit_) {
        return false;
    }

    if (this->getCashierSearchType() == 0) {
        bestCashierForQueueSize.add(this);
        return true;
    }

    if (this->getCashierSearchType() == 1) {
        bestCashierForTotalOfItems.add(this);
        return true;
    }

    return false;
}

int Customer::getCashierSearchType() {
    return this->cashierSearchType_;
}

int Customer::getPaymentType() {
    return this->paymentType_;
}

int Customer::getItemsSize() {
    return this->itemsSize_;
}

int Customer::getTotalItemsPrice() {
    return this->itemsTotalPrice_;
}

int Customer::getArrivalTime() {
    return this->arrivalTime_;
}

int Customer::getExitTime() {
    return this->exitTime_;
}

void Customer::setExitTime(int exitTime) {
    this->exitTime_ = exitTime;
}

#endif

