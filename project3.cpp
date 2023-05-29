#include "project3.hpp"

int count_inversions_recursive_helper(const std::vector<int>& numbers, int n);

int largest_left_iterative_helper(const std::vector<int>& numbers, std::vector<int>& result, const int& i);
int largest_right_iterative_helper(const std::vector<int>& numbers, std::vector<int>& result, const int& i);

void largest_left_recursive_helper(const std::vector<int>& numbers, std::vector<int>& result, int n);
int largest_left_recursive_value_helper(const std::vector<int>& numbers, std::vector<int>& result, int n, int s);

void largest_right_recursive(const std::vector<int>& numbers, std::vector<int>& result);

void largest_right_recursive_helper(const std::vector<int>& numbers, std::vector<int>& result, int n);
int largest_right_recursive_value_helper(const std::vector<int>& numbers, std::vector<int>& result, int n, int s);

void largest_left_right_recursive_helper(const std::vector<int>& numbers, std::vector<int>& result, int n);

int increasing_sequences_iterative_helper(std::vector<int>& numbers, int startIdx);

int increasing_sequences_recursive_value_helper(std::vector<int>& numbers, int startIdx);
int increasing_sequences_recursive_helper(std::vector<int>& numbers, int startIdx);



void readInFile(std::vector<int>& numbers, std::ifstream inputFile) {
	std::string myline;
	if (inputFile.is_open()) {
		while (inputFile) {
			std::getline(inputFile, myline);
		}
	}
	else {
		std::cout << "couldn't open file";
	}
}



int count_inversions_iterative(const std::vector<int>& numbers) {
	int numberOfInversions = 0;
	for (int i = 0; i < size(numbers) - 1; i++) {
		if (numbers.at(i) > numbers.at(i + 1)) {
			numberOfInversions++;
		}
	}
	return numberOfInversions;
}



int count_inversions_recursive(const std::vector<int>& numbers) {
	return count_inversions_recursive_helper(numbers, size(numbers) - 1);
}



int count_inversions_recursive_helper(const std::vector<int>& numbers, int n) { //size of vector
	if (n == 0) {
		return 0;
	}

	int recursiveCount = count_inversions_recursive_helper(numbers, n - 1);

	if (numbers[n] < numbers[n - 1]) {
		recursiveCount++;
	}

	return recursiveCount;
}



void largest_left_iterative(const std::vector<int>& numbers, std::vector<int>& result) {
	for (int i = 0; i < numbers.size(); i++) {
		result.push_back(largest_left_iterative_helper(numbers, result, i));
	}
}



int largest_left_iterative_helper(const std::vector<int>& numbers, std::vector<int>& result, const int& i) {
	for (int j = i; j >= 0; j--) {
		if (numbers.at(i) < numbers.at(j)) {
			return numbers.at(j);
		}
	}
	return 0;

}



int largest_right_iterative_helper(const std::vector<int>& numbers, std::vector<int>& result, const int& i) {
	for (int j = i; j < numbers.size(); j++) {
		if (numbers.at(i) < numbers.at(j)) {
			return numbers.at(j);
		}
	}
	return 0;
}



void largest_left_recursive(const std::vector<int>& numbers, std::vector<int>& result) {
	largest_left_recursive_helper(numbers, result, numbers.size() - 1);
}



void largest_left_recursive_helper(const std::vector<int>& numbers, std::vector<int>& result, int n) {
	if (n == -1) {
		return;
	}
	largest_left_recursive_helper(numbers, result, n - 1);;
	result.push_back(largest_left_recursive_value_helper(numbers, result, n, n));
}


int largest_left_recursive_value_helper(const std::vector<int>& numbers, std::vector<int>& result, int startingPos, int currPos) {
	if (currPos == -1) {
		return 0;
	}
	if (numbers.at(startingPos) < numbers.at(currPos)) {
		return numbers.at(currPos);
	}
	else {
		return largest_left_recursive_value_helper(numbers, result, startingPos, currPos - 1);
	}
}


void largest_left_right_iterative(const std::vector<int>& numbers, std::vector<int>& result) {
	for (int i = 0; i < numbers.size(); i++) {
		int leftElement = largest_left_iterative_helper(numbers, result, i);
		int rightElement = largest_right_iterative_helper(numbers, result, i);
		if (leftElement > rightElement) {
			result.push_back(leftElement);
		}
		else {
			result.push_back(rightElement);
		}
	}
}



void largest_left_right_recursive(const std::vector<int>& numbers, std::vector<int>& result) {
	largest_left_right_recursive_helper(numbers, result, numbers.size() - 1);
}



void largest_left_right_recursive_helper(const std::vector<int>& numbers, std::vector<int>& result, int n) {
	if (n == -1) {
		return;
	}
	largest_left_right_recursive_helper(numbers, result, n - 1);
	int leftElement = largest_left_recursive_value_helper(numbers, result, n, n);
	int rightElement = largest_right_recursive_value_helper(numbers, result, n, n);
	if (leftElement > rightElement) {
		result.push_back(leftElement);
	}
	else {
		result.push_back(rightElement);
	}
}




void largest_right_recursive(const std::vector<int>& numbers, std::vector<int>& result) {
	largest_right_recursive_helper(numbers, result, numbers.size() - 1);
}



void largest_right_recursive_helper(const std::vector<int>& numbers, std::vector<int>& result, int n) {
	if (n == -1) {
		return;
	}
	largest_right_recursive_helper(numbers, result, n - 1);
	result.push_back(largest_right_recursive_value_helper(numbers, result, n, n));

}



int largest_right_recursive_value_helper(const std::vector<int>& numbers, std::vector<int>& result, int startingPos, int currPos) {
	if (currPos == numbers.size()) {
		return 0;
	}
	if (numbers.at(startingPos) < numbers.at(currPos)) {
		return numbers.at(currPos);
	}
	else {
		return largest_right_recursive_value_helper(numbers, result, startingPos, currPos + 1);
	}
}



int increasing_sequences_iterative(std::vector<int>& numbers) {
	int highestSequence = 1;
	for (int i = 0; i < numbers.size(); i++) {
		int highestCurrSequence = increasing_sequences_iterative_helper(numbers, i);
		if (highestSequence < highestCurrSequence) {
			highestSequence = highestCurrSequence;
		}
	}
	return highestSequence;
}



int increasing_sequences_iterative_helper(std::vector<int>& numbers, int startIdx) {
	int highestSequenceCounter = 1;
	for (int j = startIdx; j < numbers.size() - 1; j++) {
		if (numbers.at(j) <= numbers.at(j + 1)) {
			highestSequenceCounter++;
		}
		else {
			return highestSequenceCounter;
		}
	}
}



int increasing_sequences_recursive(std::vector<int>& numbers) {
	return increasing_sequences_recursive_helper(numbers, 0);
}



int increasing_sequences_recursive_helper(std::vector<int>& numbers, int startIdx) {
	if (startIdx == numbers.size()) {
		return 1;
	}
	int currSequence = increasing_sequences_recursive_value_helper(numbers, startIdx);
	int longestSequence = increasing_sequences_recursive_helper(numbers, startIdx + 1);

	if (currSequence > longestSequence) {
		return currSequence;
	}
	else {
		return longestSequence;
	}
}



int increasing_sequences_recursive_value_helper(std::vector<int>& numbers, int startIdx) {
	if (startIdx == numbers.size() - 1 || numbers.at(startIdx) > numbers.at(startIdx + 1)) {
		return 1;
	}
	//recursive step
	int highestSequence = increasing_sequences_recursive_value_helper(numbers, startIdx + 1);
	highestSequence++;
	return highestSequence;
}
