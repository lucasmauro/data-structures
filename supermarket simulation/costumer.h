/* Copyright [2016] <Lucas Mauro de Souza>
* costumer.hpp
*/

/*!
* Costumer
*
* Represents a supermarket costumer.
*/
#ifndef COSTUMER_H
#define COSTUMER_H

//#include "cashier.h"
#include <cstdlib>
#include <ctime>

class Costumer {
 public:
    /*!
    * Constructs a costumer.
    *
    * @param arrivalTime Represents the time in which the costumer has arrived at the supermarket.
    * @param paymentType Represents the payment type that the client shall use to pay for the items he buys.
    * @param cashierSearchType Represents which type of cashier the costumer looks for.
    */
    Costumer(int arrivalTime, int paymentType, int cashierSearchType);

    /*!
    * Based on their criteria, the costumer will either pick a cashier that 
    * has either a smallest number of people in queue or
    * the least sum of items in queue.
    *
    * @param cashiers A list of cashiers in the market.
    */
    bool chooseCashier(CircularList<Cashier> cashiers);

    /*!
    * Returns a representation of which type of cashier the costumer looks for.
    * 0 stands for the queue with the least persons.
    * 1 stands for the queue with the least items.
    */
    int getCashierSearchType();

    /*!
    * Returns a representation of the payment type which the costumer shall use.
    * 0 stands for money;
    * 1 stands for check.
    */
    int getPaymentType();

    /*!
    * Returns how many items the costumer is buying.
    */
    int getItemsSize();

    /*!
    * Returns the total price which the costumer shall pay.
    */
    int getTotalItemsPrice();

    /*!
    * Returns when the costumer has arrived at the supermarket.
    */
    int getArrivalTime();

    /*!
    * Returns when the costumer shall leave the supermarket.
    */
    int getExitTime();

 private:
    int cashierSearchType_;  //<! The type of cashier the costumer looks for.
    int paymentType_;  //<! The payment type that the client uses.
    int itemsSize_;  //<! How many items is the costumer buying.
    int itemsTotalPrice_;  //<! The sum of all items' prices.
    int arrivalTime_;  //<! The time in which the costumer arrived at the supermarket.
    int exitTime_;  //<! The time in which the costumer shall leave the supermarket.
    const int queue_size_limit_ = 10;  //<! The maximum size of a queue that a client shall withstand.
};

#include "costumer.ipp"
#endif
