#ifndef SUPERMARKET_CPP
#define SUPERMARKET_CPP

#include "supermarket.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

Supermarket::Supermarket(std::string name, int simulationTime,
		int costumerArrivalInterval) {
	this->simTime_ = simulationTime * 3600;
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
	// cria o primeiro cliente. sua chegada dispara o programa
	Customer firstCustomer = Customer(timer_);
	//  escolhe um caixa para o primeiro cliente
	this->chooseCashier(firstCustomer);
	// gera a hora de chegada do próximo cliente
	int nextCustomerArrivalTime = (customerArrivalInt_ + (std::rand() % 5));

	//  cria um laço para, enquanto o relógio não chegar ao fim da simulação...
	while (timer_ <= simTime_) {
		//  ...percorrer a lista circular, caixa por caixa
		for (int i = 0; i < cashiers_->size(); i++) {
			Cashier thisCashier = cashiers_->at(i);
			//  se a fia do caixa não for vazia...
			if (thisCashier.getQueueSize() > 0) {
				//  ...verifica se está na hora de o primeiro cliente ser atendido
				Customer thisCustomer = thisCashier.getCustomer();
				if (thisCustomer.getExitTime() == timer_) {
					thisCashier.checkOut();
				}
			}
		}
		//  aqui, verificamos se está na hora do próximo cliente chegar

		if (nextCustomerArrivalTime == timer_) {
			Customer arrival = Customer(timer_);
			//  se estiver, escolhemos um caixa pra ele, se houver
			if (chooseCashier(arrival)) {
				nextCustomerArrivalTime += (customerArrivalInt_
						+ (std::rand() % 5));
			} else { //  se não houver, ele abandona o carrinho. o valor de suas compras é multiplicdo por três.
				this->unattendedCustomers_++;
				this->lostRevenue_ += (arrival.getTotalItemsPrice() * 3);
			}
		}
		timer_++;
	}

//  ao final da simulação, calcula-se os totais que o sistema deve informar ao usuário
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
	cashiers_->push_back(add);
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
	cashiers_->push_back(extra);
}

bool Supermarket::chooseCashier(Customer& customer) {
	Cashier &bestCashierForQueueSize = cashiers_->at(1);
	int smallestQueueSize = bestCashierForQueueSize.getQueueSize();
	Cashier &bestCashierForTotalOfItems = cashiers_->at(0);
	int smallestTotalOfItems = bestCashierForTotalOfItems.getQueueSize();
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

	if (smallestQueueSize >= this->queue_size_limit_ - 1) {
		return false;
	}

	if (customer.getCashierSearchType() == 0) {
		bestCashierForQueueSize.add(customer);
		int wait = bestCashierForQueueSize.setWaitingTime(customer);
		customer.setExitTime(wait + this->timer_);
		bestCashierForQueueSize.setTotalWaitingTime(wait);
		return true;
	}

	if (customer.getCashierSearchType() == 1) {
		bestCashierForTotalOfItems.add(customer);
		int wait = bestCashierForTotalOfItems.setWaitingTime(customer);
		customer.setExitTime(wait + this->timer_);
		bestCashierForTotalOfItems.setTotalWaitingTime(wait);
		return true;
	}

	return false;
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
		std::cout << "Cashier's name: " << cashier.getName() << std::endl;
		std::cout << "Cashier's total revenue: " << cashier.getTotalRevenue()
				<< std::endl;
		std::cout << "Cashier's average revenue: "
				<< cashier.getAverageRevenue() << std::endl;
		std::cout << "Cashier's profit: "
				<< cashier.getTotalRevenue() - cashier.getIncome() << std::endl;
		std::cout << std::endl;
	}
}

#endif // SUPERMARKET_CPP

