#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int main() {

	FILE *file = fopen("/CHANGE/THIS/TO/YOUR/DIRECTORY/input.txt", "r+");

	if (!file)
		perror("File opening failed");

	string supermarketName = "";
	string simulationHours = "";
	string meanCustomerArrivalTime = "";

	char line[255];

	while (!feof(file)) {
		fgets(line, 255, file);
		bool validLine = line[0] != '#' && line[0] != '\n' && line[0] != ' ';

		if (supermarketName.empty() && validLine) {
			supermarketName = line;
			// TODO pass this onto the Supermarket object
		} else if (simulationHours.empty() && validLine) {
			simulationHours = line;
			// TODO pass this onto the Supermarket object
		} else if (meanCustomerArrivalTime.empty() && validLine) {
			meanCustomerArrivalTime = line;
			// TODO pass this onto the Supermarket object
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

			// TODO create Cashier and store it in a circular list
			// then pass the list onto the supermarket object
		}

	}

	fclose(file);

	return 0;
}
