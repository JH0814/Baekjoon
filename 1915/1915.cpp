#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
int min(int a, int b, int c){
    return a < (b < c ? b : c) ? a : (b < c ? b : c);
}
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (m, 0));
    for(int i = 0; i<n; i++){
        string line;
        cin >> line;
        for(int j = 0; j<line.length(); j++){
            arr[i][j] = line[j] - '0';
        }
    }
    vector<vector<int>> dp(n, vector<int> (m, 0));
    int side = 0;
    for(int i = 0; i<n; i++){
        dp[i][0] = arr[i][0];
        side = max(side, dp[i][0]);
    }
    for(int i = 0; i<m; i++){
        dp[0][i] = arr[0][i];
        side = max(side, dp[0][i]);
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(arr[i][j] == 1){
                dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1;
            }
            else{
                dp[i][j] = 0;
            }
            side = max(side, dp[i][j]);
        }
    }
    cout << side * side << endl;
}