#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include "customer.h"

inline Customer::Customer(){}

inline Customer::Customer(int arrivalTime) {
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
}

Customer::~Customer(){}

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

#endif //CUSTOMER_CPP
