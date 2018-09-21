#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>
#include <vector>

void writeRandoms() {
    std::ofstream readings;
    readings.open("Readings.txt");

    srand (time(NULL));
    std::default_random_engine generator(time(0));
    std::uniform_real_distribution<double>distribution(50.000, 90.000);

    int count = (rand()%513)+512;
    double randDouble = 0;

    std::cout<<"Lab2!"<<std::endl;
    std::cout<< count;

    for(int i = 0; i < count; i++) {
        randDouble = distribution(generator);
        readings << i << " " << std::fixed << std::setprecision(3) << randDouble << std::endl;
    }
    readings.close();
}

int main()
{
    //writeRandoms();

    int count = 0;
    double value = 0;

    double avg = 0;
    double highest = 0;
    double lowest = 0;
    double median = 0;

    std::vector <double> doubleVector;

    std::ifstream inFile;
    inFile.open("Readings.txt");

    std::string line;
    std::istringstream iss;
    while(getline(inFile, line))
    {

        iss.clear();
        iss.str(line);
        std::cout << line << std::endl;

        iss >> count;
        //std::cout << count << " ";
        iss >> value;
        //std::cout << value << std::endl;
        doubleVector.push_back(value);

    }

    std::cout << "now outputting doublevector values" << std::endl;

    std::cout << "Done";

    return 0;
}