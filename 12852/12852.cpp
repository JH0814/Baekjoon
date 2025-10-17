#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> dp(N + 1, 0);
    vector<int> parent(N + 1, 0);
    for(int i = 2; i<=N; i++){
        dp[i] = dp[i - 1] + 1;
        parent[i] = i - 1;
        if(i % 2 == 0 && dp[i] > dp[i/2] + 1){
            dp[i] = dp[i/2] + 1;
            parent[i] = i/2;
        }
        if(i % 3 == 0 && dp[i] > dp[i/3] + 1){
            dp[i] = dp[i/3] + 1;
            parent[i] = i/3;
        }
    }
    cout << dp[N] << endl;
    vector<int> path;
    int cur = N;
    while(cur != 0){
        path.push_back(cur);
        cur = parent[cur];
    }
    for(int i = 0; i<path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
}