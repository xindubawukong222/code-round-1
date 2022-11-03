#include <iostream>
#include <stack>

using namespace std;

bool Work(const string& s) {
  stack<char> sta;
  for (char ch : s) {
    if (ch == '(' || ch == '[' || ch == '{') {
      sta.push(ch);
    } else {
      if (sta.empty()) return false;
      if ((ch == ')' && sta.top() == '(') || (ch == ']' && sta.top() == '[') ||
          (ch == '}' && sta.top() == '{')) {
        sta.pop();
      } else {
        return false;
      }
    }
  }
  return sta.empty();
}

void Test() {
  assert(Work("()"));
  assert(Work("()[]{}"));
  assert(!Work("(]"));
  // assert(!Work("([]"));
  cout << "Test passed.\n";
}

int main() {
  Test();
  return 0;
}
