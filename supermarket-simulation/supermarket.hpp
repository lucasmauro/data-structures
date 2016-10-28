/* Copyright Cyan Lebleu 2016
 * supermarket.hpp
 */

#ifndef SUPERMARKET_HPP
#define SUPERMARKET_HPP

#include <string>
#include "cashier.cpp"
#include "circular_list.h"


/*!
* Supermarket
*
* Represents a supermarket.
*/
class Supermarket {

 public:

/*!
  * The row of cashiers of the Supermarket.
 */
 CircularList<Cashier> *cashiers_;
 /*!
  * Constructor
  * Constructs a supermarket
  */
 inline Supermarket();

 /*!
  * Constructor
  * Constructs a supermarket with the given parameters
  */
 inline Supermarket(std::string name, int simulation, int arrival);

 /*!
  * Destructor
  * Destructs a supermarket
  */
 inline ~Supermarket();  //ignorar

 inline void run();

 inline int getTimer();  //ignorar

 inline std::string getName();  //ignorar

 inline int getCustomerArrival();  //ignorar

 inline int getUnattended();  //ignorar

 inline int getLostRevenue();  //ignorar

 inline void addCashier(Cashier add);  //ignorar

 inline void addCashier();  //ignorar

 inline void callOvertime();  //ignorar

 inline void setArrival(int newArrivalTime);  //ignorar

 inline int maxQueueSize();  //ignorar

 inline void calculateTotals();  //ignorar

 inline void printCashiersRevenue(); //ignorar

  /*!
    * Based on their criteria, the customer will either pick a cashier that
    * has either a smallest number of people in queue or
    * the least sum of items in queue.
    *
    * @param cashiers A list of cashiers in the market.
    */
 inline bool chooseCashier(Customer& customer);

 private:

 int timer_{0};

 int simTime_;  //ignorar

 std::string name_;

 int queue_size_limit_; //ignorar

 int customerArrivalInt_; //ignorar

 int unattendedCustomers_{0};

 int lostRevenue_{0};

 int totalRevenue_{0}; //ignorar

 int averageRevenue_{0}; //ignorar

 int averageWait_{0};  //ignorar


};

#endif //SUPERMARKET_HPP
