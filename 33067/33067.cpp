#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long memo[17][1 << 16];

long long solve(int idx, int mask, int N, vector<int>& a, vector<int>& b){
    if(idx == N){
        return 1;
    }
    if(memo[idx][mask] != -1){
        return memo[idx][mask];
    }
    long long res = 0;
    for(int num = 1; num <= N; num++){
        if(!(mask & (1 << (num - 1)))){
            if(num != a[idx] && num != b[idx]){
                res += solve(idx + 1, mask | (1 << (num - 1)), N, a, b);
            }
        }
    }
    return memo[idx][mask] = res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> a(N);
        vector<int> b(N);
        for(int i = 0; i<N; i++) cin >> a[i];
        for(int i = 0; i<N; i++) cin >> b[i];
        for(int i = 0; i<=N; i++){
            for(int j = 0; j<(1<<N); j++){
                memo[i][j] = -1;
            }
        }
        cout << solve(0, 0, N, a, b) << "\n";
    }
}