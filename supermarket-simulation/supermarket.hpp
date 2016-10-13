/* Copyright Cyan Lebleu 2016
 * supermarket.hpp
 */

#ifndef SUPERMARKET_HPP
#define SUPERMARKET_HPP

#include customer.hpp
#include cashier.hpp
#include circular_list.hpp

class Supermarket {

 public:

 Supermarket();

 ~Supermarket();

 CircularList<Cashier> *supermarket;

 void run();

 int getTimer();

 string getName();

 int getCustomerArrival();

 int getUnnnatended();

 int getLostRevenue();

 void callOvertime();

 int maxQueueSize();

 void readFile();

 private:

 int timer_;

 int simTime_;

 string name_;

 int maxQueueSize_;

 int customerArrivalInt_;

 int unattendedCustomers_;

 int lostRevenue_;

 // writeFile();

};

#endif SUPERMARKET_HPP
