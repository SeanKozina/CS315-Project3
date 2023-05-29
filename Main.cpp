/* ********************************************
 *
 * Main function and test code for CS 315 P3
 *
 * Sean Kozina
 */
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include "project3.hpp"  
using namespace std;
/* Function prototypes */
bool read_inputs(vector<int>& numbers, string filename);
void run_tests(string filename);


int main() {
    run_tests("Text.txt");

    return 0;
}
/*
 * read_inputs(vector<int>&, char*)
 *
 * Pass it the filename as a C-string and a vector to populate with
 * the numbers in that file (which should be separated by whitespace)
 *
 * This vector should be empty prior to calling this function
 *
 * Returns true if it was able to read at least one number into the
 * vector, else false
 */
bool read_inputs(vector<int>& numbers, string filename) {
    assert(numbers.empty()); // vector should be empty before call
    ifstream inFile(filename);
    int currentNumber;
    inFile >> currentNumber;
    while (inFile.good() && !(inFile.eof())) {
        numbers.push_back(currentNumber);
        inFile >> currentNumber;
    }
    // Return true if at least 1 number was read from input file,
    // else false
    return (numbers.size() > 0);
}
/*
 * Run_tests
 * Given a filename, call your functions and run unit tests
 *
 * You'll probably want to change this function to pass it
 * the desired outputs for each input file
 */
void run_tests(string inputfile) {
    vector<int> inputs, result, resultComparison;
    bool failureFlag = false;
    if (!read_inputs(inputs, inputfile)) {
        cerr << "I couldn't read from " << inputfile << endl;
        return;
    }
    cout << "Testing your functions on " << inputfile << endl;
    // Call your test functions here
    if (count_inversions_iterative(inputs) != count_inversions_recursive(inputs)) {
        failureFlag = true;
    }
    largest_left_iterative(inputs, result);
    largest_left_recursive(inputs, resultComparison);
    if (result != resultComparison) {
        failureFlag = true;
    }
    result.clear();
    resultComparison.clear();
    largest_left_right_iterative(inputs, result);
    largest_left_right_recursive(inputs, resultComparison);

    if (result != resultComparison) {
        failureFlag = true;
    }

    inputs.clear();
    result.clear();
    resultComparison.clear();

    string problem4InputFile = "Problem4.txt";
    if (!read_inputs(inputs, problem4InputFile)) {
        cerr << "I couldn't read from " << problem4InputFile << endl;
        return;
    }
    cout << "Testing your functions on " << problem4InputFile << endl;
    if (increasing_sequences_recursive(inputs) != increasing_sequences_iterative(inputs)) {
        failureFlag = true;
    }
    if (count_inversions_iterative(inputs) != count_inversions_recursive(inputs)) {
        failureFlag = true;
    }
 
    largest_left_right_iterative(inputs, result);
    largest_left_right_recursive(inputs, resultComparison);

    if (result != resultComparison) {
        failureFlag = true;
    }
    if (!failureFlag) {
        cout << "All tests passed\n";
    }
    else {
        cout << "You done fucked up\n";
    }
}
