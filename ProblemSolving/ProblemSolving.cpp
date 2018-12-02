// ProblemSolving.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

template<class T> vector<string> split_string(T);

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {


	return 0;
}

int main(int ** argv, int argc)
{
	int n;

	//cin >> n;
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	ifstream mystream;
	mystream.open("test_input.txt");
	string line;
	getline(mystream, line);
	n = stoi(line.c_str());   

	vector<string> grid(n);
	for (int i = 0; i < n; i++) {
		string grid_item;
		getline(mystream, grid_item);
		cout << " grid[" << i << "] is now " << grid_item << endl;
		grid[i] = grid_item;
	}

	string startPosition;
	getline(mystream, startPosition);

	vector<string> startPositions = split_string(startPosition);
	for (auto s : startPositions) {
		cout << s << " ";
	}
	cout << endl;
    std::cout << "Hello World!\n"; 
}

template<class T> vector<string> split_string(T input_string) {
	cout << "input string is " << input_string << endl;
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});
	
	input_string.erase(new_end, input_string.end());
	cout << "input string now " << input_string << endl;
	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';
	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));
		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
