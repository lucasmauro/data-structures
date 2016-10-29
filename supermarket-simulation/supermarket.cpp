#ifndef SUPERMARKET_CPP
#define SUPERMARKET_CPP

#include "supermarket.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

Supermarket::Supermarket(std::string name, int simulationTime,
		int costumerArrivalInterval) {
	this->simTime_ = simulationTime;
	this->name_ = name;
	this->queue_size_limit_ = 10;
	this->customerArrivalInt_ = costumerArrivalInterval;
	this->unattendedCustomers_ = 0;
	this->lostRevenue_ = 0;
	this->timer_ = 0;
	this->cashiers_ = new CircularList<Cashier>();
}

Supermarket::~Supermarket() {
}

void Supermarket::run() {
	int nextCustomerArrivalTime;

	if (timer_ == 0) {
		Customer firstCustomer = Customer(timer_);
		this->chooseCashier(firstCustomer);
		nextCustomerArrivalTime = customerArrivalInt_ + (std::rand() % 5);
	}

	while (timer_ <= simTime_) {
		for (int i = 0; i < cashiers_->size(); i++) {
			Cashier thisCashier = cashiers_->at(i);
			if (thisCashier.getQueueSize() > 0) {
				Customer thisCustomer = thisCashier.getCustomer();
				if (thisCustomer.getExitTime() == timer_) {
					thisCashier.checkOut();
				}
			}
		}

		if (nextCustomerArrivalTime == timer_) {
			Customer newCustomer = Customer(timer_);
			if (!chooseCashier(newCustomer)) {
				this->unattendedCustomers_++;
				this->lostRevenue_ += (newCustomer.getTotalItemsPrice() * 3);
			}

			nextCustomerArrivalTime += customerArrivalInt_ + (std::rand() % 5);
		}
		timer_++;
	}

	this->calculateTotals();

	std::cout << "Simulation terminated successfully." << std::endl;
	std::cout << std::endl;
	std::cout << this->getName();
	std::cout << std::endl;
	std::cout << "Total Revenue: " << this->totalRevenue_ << std::endl;
	std::cout << "Average Revenue: " << this->averageRevenue_ << std::endl;
	std::cout << "Average Waiting Time: " << this->averageWait_ << std::endl;
	std::cout << "Unattended Customers: " << this->unattendedCustomers_
			<< std::endl;
	std::cout << "Lost Revenue: " << this->lostRevenue_ << std::endl;
	std::cout << std::endl;
	std::cout << "Cashiers Revenue:" << std::endl;
	std::cout << std::endl;
	this->printCashiersRevenue();
}

int Supermarket::getTimer() {
	return timer_;
}

std::string Supermarket::getName() {
	return name_;
}

int Supermarket::getCustomerArrival() {
	return customerArrivalInt_;
}

int Supermarket::getUnattended() {
	return unattendedCustomers_;
}

void Supermarket::addCashier(Cashier add) {
	cashiers_->insert(add, 0);
}

int Supermarket::getLostRevenue() {
	return lostRevenue_;
}

void Supermarket::callOvertime() {
	std::string name;
	int eff;
	int income;

	std::cout << "Please enter the name of the new Cashier:\n";
	std::cin >> name;
	std::cout << "Please enter the efficiency level of the new Cashier:\n";
	std::cin >> eff;
	std::cout << "Please enter the income of the new Cashier:\n";
	std::cin >> income;
	std::cout << "Thanks";

	Cashier extra = Cashier(name, eff, income);
	cashiers_->insert(extra, 0);
}

bool Supermarket::chooseCashier(Customer& customer) {
	Cashier bestCashierForQueueSize;
	int smallestQueueSize = 0;
	Cashier bestCashierForTotalOfItems;
	int smallestTotalOfItems = 0;
	Cashier choice;

	for (int i = 0; i < cashiers_->size(); i++) {
		choice = cashiers_->at(i);

		if (choice.getQueueSize() <= smallestQueueSize) {
			smallestQueueSize = choice.getQueueSize();
			bestCashierForQueueSize = choice;
		}

		if (choice.getTotalOfItems() <= smallestTotalOfItems) {
			smallestTotalOfItems = choice.getTotalOfItems();
			bestCashierForTotalOfItems = choice;
		}
	}

	if (smallestQueueSize >= this->queue_size_limit_) {
		return false;
	}

	if (customer.getCashierSearchType() == 0) {
		bestCashierForQueueSize.add(customer);
		int wait = bestCashierForQueueSize.getCustomerWaitingTime(customer);
		customer.setExitTime(wait + this->timer_);
		bestCashierForQueueSize.addTotalWaitingTime(wait);
		return true;
	} else if (customer.getCashierSearchType() == 1) {
		bestCashierForTotalOfItems.add(customer);
		int wait = bestCashierForTotalOfItems.getCustomerWaitingTime(customer);
		customer.setExitTime(wait + this->timer_);
		bestCashierForTotalOfItems.addTotalWaitingTime(wait);
		return true;
	} else {
		return false;
	}
}

int Supermarket::maxQueueSize() {
	return queue_size_limit_;
}

void Supermarket::calculateTotals() {
	int totalRevenue = 0;
	int attendedCustomers = 0;
	int waitTime = 0;

	for (int i = 0; i < cashiers_->size(); i++) {
		Cashier cashier = cashiers_->at(i);
		totalRevenue += cashier.getTotalRevenue();
		attendedCustomers += cashier.getCustomersOut();
		waitTime += cashier.getAverageWaitingTime();
	}

	this->totalRevenue_ = totalRevenue;
	if (attendedCustomers != 0) {
		this->averageRevenue_ = totalRevenue / attendedCustomers;
	}
	this->averageWait_ = waitTime;
}

void Supermarket::printCashiersRevenue() {
	for (int i = 0; i < cashiers_->size(); i++) {
		Cashier cashier = cashiers_->at(i);
		std::string cashierName = cashier.getName();

		std::cout << "Cashier's name: " << cashier.getName() << std::endl;
		std::cout << cashierName << "'s total revenue: "
				<< cashier.getTotalRevenue() << std::endl;
		std::cout << cashierName << "'s average revenue: "
				<< cashier.getAverageRevenue() << std::endl;
		std::cout << cashierName << "'s profit: "
				<< cashier.getTotalRevenue() - cashier.getIncome() << std::endl;
		std::cout << std::endl;
	}
}

#endif // SUPERMARKET_CPP

