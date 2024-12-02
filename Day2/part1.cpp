#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ifstream inFile("input.txt");
  string line;
  int res = 0;

  while (getline(inFile, line)) {

    stringstream ls(line);
    string word;
    ls >> word;
    int slope = -1;
    int prev = stoi(word);
    ls >> word;
    int val = stoi(word);
    int diff = prev - val;
    if (diff > 0)
      slope = 1;
    else
      slope = -1;
    if (abs(diff) < 1 || abs(diff) > 3) {
      continue;
    }
    int safe = 1;
    prev = val;
    while (ls >> word) {
      val = stoi(word);
      diff = prev - val;
      if ((diff < 0) != (slope < 0)) {
        safe = 0;
        break;
      }
      if (abs(diff) < 1 || abs(diff) > 3) {
        safe = 0;
        break;
      }
      prev = val;
    }
    if (safe == 1)
      res++;
  }
  cout << res << endl;
}
