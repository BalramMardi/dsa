#include <iostream>
#include <vector>

using namespace std;

void unboundedKnapsack(int n, vector<int> val, vector<int> weight, int cap) {


  vector<int> dp(cap + 1);
  dp[0] = 0;

  for (int c = 1; c <= cap; c++) {
    int mx = 0;
    for (int i = 0; i < n; i++) {
      if (weight[i] <= c) {
        int rembagc = c - weight[i];
        int rembagv = dp[rembagc];
        int tbagv = rembagv + val[i];

        if (tbagv > mx) {
          mx = tbagv;
        }

      }
    }
    dp[c] = mx;

  }
  cout << dp[cap];

}


int main() {

  int n;
  cin >> n;
  vector<int> val(n);
  for (int i = 0; i < n; i++) {

    cin >> val[i];
  }
  vector<int> weight(n);
  for (int i = 0; i < n; i++) {
    cin >> weight[i];
  }
  int cap;
  cin >> cap;

  unboundedKnapsack(n, val, weight, cap);


}