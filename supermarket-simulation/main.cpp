#include <cstdio>
#include <cstdlib>
#include <string>
#include "Cashier.hpp"
#include "circular_list.h"
#include "supermarket.cpp"

using namespace std;

int main() {

	string supermarketName = "";
	string simulationHours = "";
	int simHours = 0;
	string meanCustomerArrivalTime = "";
	int arrivalTime = 0;
	char line[255];

	CircularList<Cashier> cashiers { };

	FILE *file =
			fopen(
					"/home/lucas/workspace/linked_list/src/input.txt",
					"r+");

	if (!file) {
		perror("File opening failed");
	}

	while (!feof(file)) {
		fgets(line, 255, file);
		bool validLine = line[0] != '#' && line[0] != '\n' && line[0] != ' ';

		if (supermarketName.empty() && validLine) {
			supermarketName = line;

		} else if (simulationHours.empty() && validLine) {
			simulationHours = line;
			simHours = atoi(simulationHours.c_str()) * 3600;

		} else if (meanCustomerArrivalTime.empty() && validLine) {
			meanCustomerArrivalTime = line;
			arrivalTime = atoi(meanCustomerArrivalTime.c_str());

		} else if (!supermarketName.empty() && !simulationHours.empty()
				&& !meanCustomerArrivalTime.empty() && validLine) {

			string cashierLine = line;
			int pos = cashierLine.find(" ");

			string firstParameter = cashierLine.substr(0, pos);

			string secondChunk = cashierLine.substr(pos + 1,
					cashierLine.find(" "));

			pos = secondChunk.find(" ");

			string secondParameter = secondChunk.substr(0, pos);
			string thirdParameter = secondChunk.substr(pos + 1,
					secondChunk.size());

			int secondParam = atoi(secondParameter.c_str());
			int thirdParam = atoi(thirdParameter.c_str());

			Cashier brandNewCashier = Cashier(firstParameter, secondParam,
					thirdParam);

			cashiers.insert(brandNewCashier, 0);
		}

	}

	fclose(file);

	Supermarket supermarket = Supermarket(supermarketName, simHours,
			arrivalTime);

	for (auto i = 0; i < cashiers.size(); i++) {
		supermarket.addCashier(cashiers.at(i));
	}
	supermarket.run();

	return 0;
}
