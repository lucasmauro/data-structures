#ifndef CASHIER_H
#define CASHIER_H

#include "Cashier.hpp"

 using namespace cashier;

 Cashier(string id, int eff, int income) {
    Id_{id};
    eff_{eff};
    income_{income};
    queue_ = new LinkedQueue<Customer>;
    queueSize_{0};
    }
 Cashier();

 ~Cashier() {
    delete queue_;
    delete Cashier;
 }

 handleCustomer(Customer customer) {
    setTotalRevenue(customer.total);
    customersOut++;
    queue_.dequeue();
    setAverageRevenue();
 }
 int getQueueSize() {
    return queueSize;
    }
 int getCustomersOut() {
    return customersOut;
    }
 int getAverageWaitingTime() {
    return AverageWaitingTime;
    }
 double getTotalRevenue() {
    return totalRevenue;
 }
 double getAverageRevenue() {
    return averageRevenue;
    }
 String getId() {
    return id;
    }
 int getEff() {
 return eff_;
 }
 setTotalRevenue(double amount) {
     totalRevenue += amount;
    }
 setAverageRevenue() {
        averageRevenue = (totalRevenue/customersOut);
    }
 setWaitingTime(int waitingTime) {
     averageWaitingTime += waitingTime;
     return averageWaitingTime/getQueueSize();
    }

bool emptyQueue {
    return queueSize_ == 0;
    }


#endif // CASHIER_H
