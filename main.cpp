#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>

void writeRandoms() {
    std::ofstream readings;
    readings.open("Readings.txt");

    srand (time(NULL));
    //std::default_random_engine generator(time(0));
    std::uniform_real_distribution<double>distribution(50.000, 90.000);
    std::random_device rd;
    std::default_random_engine generator(rd());

    int count = (rand()%513)+512;
    double randDouble = 0;

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

//finds the median by sorting with the  <bits/stdc++.h> sort command
double findMedian(std::vector<double> dVect){


    std::sort(dVect.begin(), dVect.end());


    for(double value: dVect)
    {

        //std::cout << value << std::endl;
    }

    return dVect.at(dVect.size()/2);
}

int main()
{
    //writeRandoms();

    std::vector <double> dVect = makeDoubleVector();




    std::cout << "now outputting doublevector valudasdasdases" << std::endl;


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
        //std::cout << value << std::endl;
    }
    double avg = sum/count;
    median = findMedian(dVect);

    std::cout << "There are " << count << "readings in the file."<< std::endl;
    std::cout << "The average reading is " << std::fixed << std::setprecision(3) << avg << std::endl;
    std::cout << "The highest reading is " << std::fixed << std::setprecision(3) << highest << std::endl;
    std::cout << "The lowest reading is " << std::fixed << std::setprecision(3) << lowest << std::endl;
    std::cout << "The median reading is " << std::fixed << std::setprecision(3) << median << std::endl;

    std::cout << "Done";

    return 0;
}