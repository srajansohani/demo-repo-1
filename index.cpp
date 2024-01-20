#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 998244353;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> nums = [1,4,1,2,6];

    for (int i=0 ; i<nums.size(); i++){
      for (int j=i+1 ; j<nums.size(); j++){
        if (nums[i) < nums[j]){
          swap(nums[i], nums[j]);
        }
      }
    }

    for (auto i:nums){
      cout << i << " ";
    }
    cout << "\n";
  
    return 0;
}
