#ifndef project3_hpp
#define project3_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
int count_inversions_iterative(const std::vector<int>& numbers);
int count_inversions_recursive(const std::vector<int>& numbers);

void largest_left_iterative(const std::vector<int>& numbers, std::vector<int>& result);
void largest_left_recursive(const std::vector<int>& numbers, std::vector<int>& result);

void largest_left_right_iterative(const std::vector<int>& numbers, std::vector<int>& result);
void largest_left_right_recursive(const std::vector<int>& numbers, std::vector<int>& result);

int increasing_sequences_iterative(std::vector<int>& numbers);
int increasing_sequences_recursive(std::vector<int>& numbers);

#endif // !
