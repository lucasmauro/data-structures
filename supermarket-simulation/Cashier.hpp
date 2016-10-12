/*

 Copyright Cyan Lebleu 2016
 cashier.hpp
*/
#ifndef STRUCTURES_CASHIER_H
#define STRUCTURES_CASHIER_H

#include <cstdint>  //!< included csdtint
#include <stdexcept>  //!< included stdexcept
#include "customer.hpp"  //!< using Customer to get it's data

namespace cashier {

class Cashier {
    /*!
     *
     * Class Cashier
     *
     * Represents a supermarket cashier, which handles a list of Customers
     * and stores data related to the processing of said list.
     *
     */

 public
 Cashier();
 /*
  * Constructs a Cashier
  */
 ~Cashier();
 /*
  * Deletes the Cashier
  */
 handleCustomer();
 /*
  * checks the Customer out
  */
 int getQueueSize();
 /*
  * Returns the size of the Customer Queue
  */
 int getCustomersOut();
 /*
  * Returns the amount of customers checked out
  */
 int getAverageWaitingTime();
 /*
  * Returns the average waiting time for a customer
  */
 double getTotalRevenue();
 /*
  * Returns the total of cash stored by the cashier
  */
 double getAverageRevenue();
 /*
  * Returns the average revenue of the cashier
  */
 string getId();
 /*
  * Returns the cashier's ID
  */
 int getEff();
 /*
  * Returns the cashier's efficiency
  */
 setTotalRevenue();
 /*
  * Changes the value of the total revenue
  */
 setAverageRevenue();
 /*
  * Changes the value of the Average Revenue
  */
 setWaitingTime();
 /*
  * Changes the value of the Average Waiting time
  */


 protected
 Customer *queue_;
 /*
  * A pointer for a Customer's queue
  */
 std::size_t queueSize_;
 /*
  * The size of the queue
  */
 string Id_;
 /*
  * The Id of the Cahsier
  */
 const int eff_;
 /*
  *  The efficiency coefficient of the Cashier
  */
 const int income_;
 /*
  * The income of the cashier
  */
 int customersOut;
 /*
  * The number of customer checked out by the cashier
  */
 int averageWaitingTime;
 /*
  * The average time in seconds that a Customer stands waiting
  */
 double totalRevenue;
 /*
  * The total amount of cash accumulated by the cashier
  */
 double averageRevenue;
 /*
  * The Average amount of cash accumulated by the Cashier
  */
 bool emptyQueue();
 /*
  * Checks if the queue of Customers is empty
  */



};
}





#endif // STRUCTURES_CASHIER_H
