#ifndef CASHIER_CPP
#define CASHIER_CPP

#include <cstdint>
#include "Cashier.hpp"

Cashier::Cashier(std::string &id, int eff, int income) {
	this->id_ = id;
	this->eff_ = eff;
	this->income_ = income;
	this->queue_ = new ArrayQueue<Customer>(11);
}

Cashier::Cashier() {
	this->id_ = "";
	this->eff_ = 0;
	this->income_ = 0;
	this->queue_ = new ArrayQueue<Customer>(11);
}

Cashier::~Cashier() {
}
Customer Cashier::getCustomer() {
	return queue_->front();
}
void Cashier::checkOut() {
	Customer out = queue_->dequeue();
	addTotalRevenue(out.getTotalItemsPrice());
	customersOut++;
}
std::size_t Cashier::getQueueSize() {
	return this->queue_->size();
}
int Cashier::getCustomersOut() {
	return customersOut;
}
int Cashier::getAverageWaitingTime() {
	if (customersOut > 0) {
		return (totalWaitingTime / customersOut);
	}
	return 0;
}

int Cashier::getWaitingTime() {
	return waitingTime;
}
int Cashier::getTotalRevenue() {
	return totalRevenue;
}
int Cashier::getAverageRevenue() {
	return averageRevenue;
}
int Cashier::getIncome() {
	return this->income_;
}
std::string Cashier::getName() {
	return id_;
}
int Cashier::getEff() {
	return eff_;
}
int Cashier::getTotalOfItems() {
	return totalItems_;
}
void Cashier::addTotalRevenue(int amount) {
	totalRevenue += amount;
}
void Cashier::setAverageRevenue() {
	averageRevenue = (totalRevenue / customersOut);
}
int Cashier::setWaitingTime(Customer myCustomer) {
	int checkDelay = 0;
	if (myCustomer.getPaymentType() == 0) {
		if (this->eff_ == 1) {
			checkDelay = 10;
		} else if (this->eff_ == 2) {
			checkDelay = 25;
		} else if (this->eff_ == 3) {
			checkDelay = 60;
		}
	}

	if (this->eff_ == 1) {
		waitingTime = myCustomer.getItemsSize() + checkDelay;
	} else if (this->eff_ == 2) {
		waitingTime = (myCustomer.getItemsSize() * 2) + checkDelay;
	} else if (this->eff_ == 3) {
		waitingTime = (myCustomer.getItemsSize() * 4) + checkDelay;
	}
	return waitingTime;
}

void Cashier::setTotalWaitingTime(int wTime) {
	this->totalWaitingTime += wTime;
}

bool Cashier::emptyQueue() {
	return this->queue_->empty();
}

void Cashier::add(Customer newCustomer) {
	this->queue_->enqueue(newCustomer);
	this->totalItems_ += newCustomer.getItemsSize();
}

#endif // CASHIER_H
