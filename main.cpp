#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>

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
}

int main()
{
    writeRandoms();




    return 0;
}