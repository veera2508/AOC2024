#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
  vector<int> list1;
  unordered_map<int, int> map2;
  int flag = 1;
  ifstream file("input.txt");
  string str;
  while (file >> str) {
    if (flag == 1)
      list1.push_back(stoi(str));
    else {
      map2[stoi(str)]++;
    }
    flag *= -1;
  }
  int res = 0;
  for (int i = 0; i < list1.size(); i++) {
    res += list1[i] * map2[list1[i]];
  }
  cout << res << endl;
}
