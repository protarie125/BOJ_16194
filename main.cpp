#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

constexpr auto kMaxVal = numeric_limits<ll>::max() / 2 - 1;

ll n;
vl P;
vl dp;

ll solve(ll x) {
  if (dp[x] == kMaxVal) {
    dp[x] = P[x];
    for (auto i = 1; i < x; ++i) {
      dp[x] = min(dp[x], solve(x - i) + P[i]);
    }
  }

  return dp[x];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  P = vl(n + 1, 0);
  for (auto i = 1; i <= n; ++i) {
    cin >> P[i];
  }

  dp = vl(n + 1, kMaxVal);
  dp[1] = P[1];
  const auto& ans = solve(n);
  cout << ans;

  return 0;
}