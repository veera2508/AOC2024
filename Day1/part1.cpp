#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  vector<int> list1;
  vector<int> list2;
  int flag = 1;
  ifstream file("input.txt");
  string str;
  while (file >> str) {
    if (flag == 1)
      list1.push_back(stoi(str));
    else
      list2.push_back(stoi(str));
    flag *= -1;
  }
  sort(list1.begin(), list1.end());
  sort(list2.begin(), list2.end());

  int res = 0;
  for (int i = 0; i < list1.size(); i++) {
    res += abs(list1[i] - list2[i]);
  }
  cout << res << endl;
}
