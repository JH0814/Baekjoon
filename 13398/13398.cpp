#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    int ans = arr[0];
    for(int i = 1; i<n; i++){
        dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }
    cout << ans << endl;
}