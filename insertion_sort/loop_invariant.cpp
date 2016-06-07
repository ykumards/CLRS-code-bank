/*
Code to demonstrate loop invariance in the insertion sort

Loop invariant for this algorithm is:
At the start of each iteration (for element at index j), the elements between 0 to j-1 are all sorted. And their original 
index was between 0 to j-1.

*/ 

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void print_var(vector<int> A, int start, int end) {
  for (int i = start; i < end; i++) {
    cout << A[i] << " ";
  } 
  cout << endl;
}

int main() {
  string inStr;
  vector<int> input;
  cout << "Enter the input array, separated by space: \n";
  getline(cin, inStr);
  stringstream stream(inStr);
  while(1) {
    int n;
    stream >> n;
    if (!stream) {
      break;
    }
    input.push_back(n);
  }
  for (int j = 1; j < input.size(); j++) {
    cout << "For j = " << j << ",\nSorted part is ";
    print_var(input, 0, j);
    cout << "Unsorted part is ";
    print_var(input, j, input.size());
    int key = input[j];
    int i = j-1;
    while (i >= 0 && input[i] > key) {
      input[i+1] = input[i];
      i = i-1;
    }
    input[i+1] = key;
  }
  cout << "Final sorted list is: ";
  print_var(input, 0, input.size());
  
  return 0;
}
