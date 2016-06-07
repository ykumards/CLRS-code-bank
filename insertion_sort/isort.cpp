/*
Direct adapation of CLRS's Insertion Sort algorithm in C++
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
  string inArr;
  vector<int> input;
  // Storing the input array in vector 'input'
  cout << "Enter the input array with space separated elements: \n";
  getline (cin, inArr);
  stringstream stream(inArr);
  while(1) {
    int n;
    stream >> n;
    if (!stream) {
      break;
    }
    input.push_back(n);
  }
  // Algorithm body
  for (int j = 1; j < input.size(); j++) {
    int key = input[j];
    int i = j-1;
    while (i >= 0 && input[i] > key){
      // for each j, compare the element with all previous elements
      // obtain the appropriate position for key and insert
      // this will involve shifting all the larger elements to the right
      input[i+1] = input[i];
      i = i-1;
    } 
    input[i+1] = key;
  }
  // The vector was sorted inline, so print the output
  cout << "Sorted list is: \n";
  for (auto iter = input.begin(), end = input.end(); iter != end; ++iter) {
    if (iter != input.begin()) cout << ", ";
    cout << *iter;
  } 
  cout << endl;
  return 0;
}
