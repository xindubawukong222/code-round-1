#include <iostream>
#include <vector>

using namespace std;

// gtest
// junit

int Work(const vector<int>& a) {
  int n = a.size();
  vector<int> sum = a;
  for (int i = 1; i < n; i++) {
    sum[i] += sum[i - 1];
  }
  int min_sum = 0, ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    ans = max(ans, sum[i] - min_sum);
    min_sum = min(min_sum, sum[i]);
  }
  return ans;
}

void Test() {
  int ans = Work({5,4,-1,7,8});
  assert(ans == 23);
  ans = Work({-2,1,-3,4,-1,2,1,-5,4});
  assert(ans == 6);
  ans = Work({1});
  assert(ans == 1);
}

int main() {
  Test();
  return 0;
}
