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

std::vector <double> makeDoubleVector() {
    int count = 0;
    double value = 0;

    std::vector <double> doubleVector;

    std::ifstream inFile;
    inFile.open("Readings.txt");

    std::string line;
    std::istringstream iss;
    while(getline(inFile, line))
    {
        iss.clear();
        iss.str(line);
        iss >> count >> value;
        //std::cout << value << std::endl;
        doubleVector.push_back(value);
    }
    return doubleVector;
}

int main()
{
    //writeRandoms();

    std::vector <double> dVect = makeDoubleVector();




    std::cout << "now outputting doublevector values" << std::endl;


    int count = 0;
    double sum = 0;
    double highest = dVect.at(0);
    double lowest = dVect.at(0);
    double median = 0;
    for(double value: dVect)
    {
        count++;
        sum += value;
        if(value > highest)
        {
            highest = value;
        }
        else if(value < lowest) {
            lowest = value;
        }
        std::cout << value << std::endl;
    }
    double avg = sum/count;

    std::cout << "There are " << count << "readings in the file."<< std::endl;
    std::cout << "The average reading is " << avg << std::endl;
    std::cout << "The highest reading is " << highest << std::endl;
    std::cout << "The lowest reading is " << lowest << std::endl;
    std::cout << "The median reading is " << median << std::endl;

    std::cout << "Done";

    return 0;
}