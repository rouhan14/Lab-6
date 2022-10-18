// C++ program to generate random numbers
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    // This program will create different sequence of
    // random numbers on every program run

    // Use current time as seed for random generator
    srand(time(0));
    int size;
    cout << "Enter the number of times the die should be thrown: ";
    cin >> size;
    int die_num;
    for (int i = 0; i < size; i++){
        die_num =  rand() % 7;
        if (die_num == 0){
            while (die_num == 0){
                die_num = rand() % 7;
            }
        }
        cout << die_num << " ";
    }
    return 0;
}
