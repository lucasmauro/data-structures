/*

 Copyright Cyan Lebleu 2016
 cashier.hpp
*/
#ifndef STRUCTURES_CASHIER_H
#define STRUCTURES_CASHIER_H
#include <string>
#include "customer.cpp"
#include "array_queue.h"

class Cashier {
    /*!
     *
     * Class Cashier
     *
     * Represents a supermarket cashier, which handles a list of Customers
     * and stores data related to the processing of said list.
     *
     */

 public:

 inline Cashier(std::string &id, int eff, int income);
 /*
  * Constructs a Cashier with the given data
  */

  inline Cashier();
 /*
  * Constructs a Cashier
  */

 inline ~Cashier();
 /*
  * Deletes the Cashier
  */
 inline Customer getCustomer();
  /*
  * returns the customer at the front of the queue;
  */
 inline void checkOut();
 /*
  * checks the Customer out
  */
 inline std::size_t getQueueSize();
 /*
  * Returns the size of the Customer Queue
  */
 inline int getCustomersOut();
 /*
  * Returns the amount of customers checked out
  */
 inline int getWaitingTime();
  /*
  * Returns the waiting time for a customer
  */
 inline int getAverageWaitingTime();
 /*
  * Returns the average waiting time for a customer
  */
 inline int getTotalWaitingTime();
 /*
  * Returns the total waiting time for a customer
  */
 inline int getTotalRevenue();
 /*
  * Returns the total of cash stored by the cashier
  */
 inline int getAverageRevenue();
 /*
  * Returns the average revenue of the cashier
  */
 inline int getIncome();
 /*
  * Returns the average revenue of the cashier
  */
 inline std::string getName();
 /*
  * Returns the cashier's ID
  */
 inline int getEff();
 /*
  * Returns the cashier's efficiency
  */

 inline int getTotalOfItems();
  /*
  * Returns the number of items in the cashier's queue
  */
 inline void addTotalRevenue(int amount);
 /*
  * Changes the value of the total revenue
  */
  inline int getCustomerWaitingTime(Customer myCustomer);
 /*
  * Changes the value of the Waiting Time
  */
  inline void addTotalWaitingTime(int wTime);
 /*
  * Changes the value of the total Waiting Time
  */
 inline bool emptyQueue();
 /*
  * Checks if the queue of Customers is empty
  */
 inline void add(Customer newCustomer);
 /*
  * Adds a customer to the queue;
  */


 protected:
 ArrayQueue<Customer>* queue_;
 /*
  * A pointer for a Customer's queue
  */
 std::string id_;
 /*
  * The Id of the Cahsier
  */
 int eff_;
 /*
  *  The efficiency coefficient of the Cashier
  */
 int income_;
 /*
  * The income of the cashier
  */
 int customersOut{0};
 /*
  * The number of customer checked out by the cashier
  */
 int totalItems_{0};
  /*
  * The number items in the cashier's queue
  */
 int averageWaitingTime{0};
 /*
  * The average time in seconds that a Customer stands waiting
  */
  int waitingTime{0};
  /*
  * The waiting time of the next customer
  */
  int totalWaitingTime{0};
  /*
  * The total amount of time accumulated by all clients
  */
 int totalRevenue{0};
 /*
  * The total amount of cash accumulated by the cashier
  */
 int averageRevenue{0};
 /*
  * The Average amount of cash accumulated by the Cashier
  */


};


#endif // STRUCTURES_CASHIER_H
