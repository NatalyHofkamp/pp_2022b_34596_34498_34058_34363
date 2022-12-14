#include "../include/Parser.h"
#include <cstring>
#include <iostream>
#include <string>
#include <vector>


bool Parser(int argc, char *argv[], std::string &file, double &umbral, size_t &gen, std::string &out, bool &best)
{
    int counterArgs = 0;
    char *pend = nullptr;

    for (size_t i = 1; i<argc; i++){
        if( (strcmp(argv[i], "-h")==0)|| (strcmp(argv[i], "--help")==0)){
                std::cout<< std::endl << " --------------  HELP  ---------------"<<std::endl;
                std::cout<<"|DESCRIPTION.                         |"<<std::endl;
                std::cout<<"|                                     |"<<std::endl;
                std::cout<<"|This program implements a genetic    |"<<std::endl;
                std::cout<<"|algorithm to solve the traveling     |"<<std::endl;
                std::cout<<"|salesman's problem.                  |"<<std::endl;
                std::cout<<"|                                     |"<<std::endl;   
                std::cout<<"|OPTIONS.                             |"<<std::endl;
                std::cout<<"|                                     |"<<std::endl;
                std::cout<<"|-f or --file --> cities file name    |"<<std::endl;
                std::cout<<"|-u or --umbral --> when the variation|"<<std::endl;
                std::cout<<"|of the last ten populations is below |"<<std::endl;
                std::cout<<"|this value the program finishes      |"<<std::endl;
                std::cout<<"|-g or --gen --> when the amount of   |"<<std::endl;
                std::cout<<"|generations reaches this value then  |"<<std::endl;
                std::cout<<"|the program finishes                 |"<<std::endl;
                std::cout<<"|-o or --out --> indicate data        |"<<std::endl;
                std::cout<<"|collected wanted, 1->for amount of   |"<<std::endl;
                std::cout<<"|iterations and shortest distance,    |"<<std::endl;
                std::cout<<"|2->for amount of iterations and      |"<<std::endl;
                std::cout<<"|average distance, 3->for amount of   |"<<std::endl;
                std::cout<<"|iterations and largest distance,     |"<<std::endl;
                std::cout<<"|4->coordinates of cities in best     |"<<std::endl;
                std::cout<<"|route found (more than one option    |"<<std::endl;
                std::cout<<"|can be chosen, by inserting the      |"<<std::endl;
                std::cout<<"|of each wanted, example 1234 would   |"<<std::endl;
                std::cout<<"|indicate all were requested)         |"<<std::endl;
                std::cout<<"|-b or --best --> if included, the    |"<<std::endl;
                std::cout<<"|best route found will be shown       |"<<std::endl;
                std::cout<<"|through the terminal                 |"<<std::endl;
                std::cout<<"|                                     |"<<std::endl;
                std::cout<<"|In case of not including or giving   |"<<std::endl;
                std::cout<<"|the wrong type of the first three    |"<<std::endl;
                std::cout<<"|argument, the program won't start.   |"<<std::endl;
                std::cout<<"---------------------------------------"<<std::endl << std::endl;

            return false;       
        }
        if((strcmp(argv[i], "-f") == 0) || (strcmp(argv[i], "--file") == 0)){
            file = argv[i+1];
            counterArgs++;
        }
        else if((strcmp(argv[i], "-g") == 0) || (strcmp(argv[i], "--gen") == 0)){
            int g = std::strtol(argv[i+1], &pend, 10);
            if (*pend == '\0') {
                gen = g;
                counterArgs++;
            }
        }
        else if((strcmp(argv[i], "-u") == 0) || (strcmp(argv[i], "--umbral") == 0)){
            double u = std::strtod(argv[i+1], &pend);
            if (*pend == '\0') {
                umbral = u;
                counterArgs++;
            }
        }
        else if((strcmp(argv[i], "-o") == 0) || (strcmp(argv[i], "--out") == 0)){
            out = argv[i+1]; 
        }
        else if((strcmp(argv[i], "-b") == 0) || (strcmp(argv[i], "--best") == 0)){
            best = true;
        }
    }
    if (counterArgs != 3) {
        return false;
    }
    return true;
}
