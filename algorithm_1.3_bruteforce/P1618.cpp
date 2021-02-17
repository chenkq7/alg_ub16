#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  bool flag = false;
  vector<int> myints = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  do
  {
    int nums[3];
    for (int i = 0; i < 3; i++)
      nums[i] = myints[3 * i] * 100 + myints[3 * i + 1] * 10 + myints[3 * i + 2];
    if (nums[0] < nums[1] && nums[1] < nums[2])
      if (a * nums[1] == b * nums[0] && a * nums[2] == c * nums[0])
      {
        flag = true;
        for (auto item : nums)
          cout << item << " ";
        cout << endl;
      }
  } while (next_permutation(myints.begin(), myints.end()));
  if (!flag)
  {
    cout << "No!!!";
  }
  return 0;
}