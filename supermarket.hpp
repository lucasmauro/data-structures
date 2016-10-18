/* Copyright Cyan Lebleu 2016
 * supermarket.hpp
 */

#ifndef SUPERMARKET_HPP
#define SUPERMARKET_HPP

#include <string>
#include "cashier.cpp"
#include "circular_list.h"

class Supermarket {

 public:

 CircularList<Cashier> *cashiers;

 inline Supermarket();

 inline Supermarket(std::string name, int simulation, int arrival);

 inline ~Supermarket();

 inline void run();

 inline int getTimer();

 inline std::string getName();

 inline int getCustomerArrival();

 inline int getUnattended();

 inline int getLostRevenue();

 inline void addCashier(Cashier add);

 inline void callOvertime();

 inline void setName(std::string newName);

 inline void setSimTime(int newSimTime);

 inline void setArrival(int newArrivalTime);

 inline int maxQueueSize();

 inline int calculateTotals();

 inline int getTotalRevenue();

 inline int getAverageRevenue();

 inline int getAverageWait();

 inline void cashiersRevenue();

  /*!
    * Based on their criteria, the customer will either pick a cashier that
    * has either a smallest number of people in queue or
    * the least sum of items in queue.
    *
    * @param cashiers A list of cashiers in the market.
    */
 inline bool chooseCashier(Customer customer);

 private:

 int timer_;

 int simTime_;

 std::string name_;

 int queue_size_limit_;

 int customerArrivalInt_;

 int unattendedCustomers_;

 int lostRevenue_;

 int totalRevenue_;

 int averageRevenue_;

 int averageWait_;


};

#endif //SUPERMARKET_HPP
