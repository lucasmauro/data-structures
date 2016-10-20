#include <cstdio>
#include <cstdlib>
#include <string>
#include "supermarket.cpp"

using namespace std;

int main() {

    int option;

    std::cout << "would you like to open a file or type in the data?\n";
    std::cout << "1 - Open file\n";
    std::cout << "2 - Type in data\n";
    std::cin >> option;

    if (option == 1) {

        FILE *file = fopen("Change this to your directory/input.txt", "r+");

        if (!file)
            perror("File opening failed");

        string supermarketName = "";
        string simulationHours = "";
        int simHours;
        string meanCustomerArrivalTime = "";
        int arrivalTime;
        char line[255];

        while (!feof(file)) {
            fgets(line, 255, file);
            bool validLine = line[0] != '#' && line[0] != '\n' && line[0] != ' ';

            if (supermarketName.empty() && validLine) {
                supermarketName = line;

            } else if (simulationHours.empty() && validLine) {
                simulationHours = line;
                simHours = atoi(simulationHours.c_str())*60;

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

                Supermarket supermarket = Supermarket(supermarketName, simHours, arrivalTime);

                Cashier brandNewCashier = Cashier(firstParameter, secondParam, thirdParam);

                supermarket.addCashier(brandNewCashier);

                supermarket.run();
            }

        }

        fclose(file);


    } else if (option == 2) {
        Supermarket supermarket = Supermarket();
        supermarket.run();
    }





	return 0;
}
