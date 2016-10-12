/* Copyright Cyan Lebleu 2016
 * supermarket.hpp
 */

#ifndef SUPERMARKET_HPP
#define SUPERMARKET_HPP

#include customer.hpp
#include cashier.hpp
#include circular_list.hpp

namespace supermarket  {

class Supermarket {

 public

 Supermarket();

 ~Supermarket();

 CircularList<Cashier> *supermarket;

 private

 int timer;

 string name;

 int maxQueueSize;

 int customerArrivalInt;

 int getTimer();

 Cashier callOvertime();

 int maxQueueSize();

 readFile();

 // writeFile();

 

};

}  // namespace supermarket

#endif SUPERMARKET_HPP


