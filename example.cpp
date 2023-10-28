//
//  main.cpp
//  MLArray
//
//  Created by Matthew liew on 28.10.23.
//

#include <iostream>
#include "MLArrays.hpp"
#include <random>
using namespace std;

//random int generator
int rand_gen(int& start, int& end) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(start,end);
    return dist(gen);
}

// random array filler
MLArray random_fill_array(MLArray& array, int start, int end) {
    unsigned long int size = array.size();
    for (int i = 0; i < size; i++) {
        array[i] = rand_gen(start,end);
    }
    return array;
}

// print array
void print_array(MLArray& array) {
    unsigned long int size = array.size();
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


int main () {
    // initialize two MLArrays
    MLArray array1(5);
    MLArray array2(3);
    
    // fill array1
    int start = 1;
    int end = 50;
    random_fill_array(array1, start, end);
    random_fill_array(array2, 20, 30);
    
    //print array
    cout << "array1: ";
    print_array(array1);
    
    cout << "array2: ";
    print_array(array2);
    
    //max elem
    cout << "max of array1: ";
    cout << array1.max() << endl;
    
    // elem add two arrays
    array1 += array2;
    cout << "array1 + array2: ";
    print_array(array1);
    
    //apply square function on array2
    auto square = [](double x) { return x*x; };
    MLArray squared_array2 = array2.apply(square);
    cout << "array2 squared: ";
    print_array(squared_array2);
    
    return 0;
}

