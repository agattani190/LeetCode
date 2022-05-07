#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
vector<int> buildArray(vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    nums[i] += (n * (nums[nums[i]] % n));
  }
  for (int i = 0; i < n; i++) {
    nums[i] /= n;
  }
  return nums;
}