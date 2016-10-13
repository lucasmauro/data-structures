/* Copyright [2016] <Lucas Mauro de Souza>
* customer.hpp
*/

/*!
* Customer
*
* Represents a supermarket customer.
*/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <cstdlib>
#include <ctime>
#include "circular_list.h"
#include "cashier.hpp"

class Customer {
 public:
    /*!
    * Constructs a customer.
    *
    * @param cashierSearchType Represents which type of cashier the customer looks for.
    */

    Customer();

    Customer(int arrivalTime);
    /*!
    * Destroys a customer.
    */
    ~Customer();

    /*!
    * Based on their criteria, the customer will either pick a cashier that
    * has either a smallest number of people in queue or
    * the least sum of items in queue.
    *
    * @param cashiers A list of cashiers in the market.
    */
    bool chooseCashier(CircularList<Cashier> cashiers);

    /*!
    * Returns a representation of which type of cashier the customer looks for.
    * 0 stands for the queue with the least persons.
    * 1 stands for the queue with the least items.
    */
    int getCashierSearchType();

    /*!
    * Returns a representation of the payment type which the customer shall use.
    * 0 stands for money;
    * 1 stands for check.
    */
    int getPaymentType();

    /*!
    * Returns how many items the customer is buying.
    */
    int getItemsSize();

    /*!
    * Returns the total price which the customer shall pay.
    */
    int getTotalItemsPrice();

    /*!
    * Returns when the customer has arrived at the supermarket.
    */
    int getArrivalTime();

    /*!
    * Returns when the customer shall leave the supermarket.
    */
    int getExitTime();

   /*!
    * Tells when the customer shall leave the supermarket based on Cashier's
    */
    void setExitTime(int exitTime);

 private:
    int cashierSearchType_;  //<! The type of cashier the customer looks for.
    int paymentType_;  //<! The payment type that the client uses.
    int itemsSize_;  //<! How many items is the customer buying.
    int itemsTotalPrice_;  //<! The sum of all items' prices.
    int arrivalTime_;  //<! The time in which the customer arrived at the supermarket.
    int exitTime_;  //<! The time in which the customer shall leave the supermarket.
    const static int queue_size_limit_ = 10;  //<! The maximum size of a queue that a client shall withstand.
};

#include "customer.cpp"
#endif
