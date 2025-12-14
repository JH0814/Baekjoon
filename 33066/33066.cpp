#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, K, S; cin >> N >> M >> K >> S;
    vector<vector<int>> arr(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> row_sum(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> col_sum(N + 1, vector<int>(M + 1, 0));
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cin >> arr[i][j];
            row_sum[i][j] = row_sum[i][j - 1] + arr[i][j];
            col_sum[i][j] = col_sum[i - 1][j] + arr[i][j];
        }
    }
    int half_k = K / 2;
    for(int i = 1; i<=N - K+1; i+=S){
        for(int j = 1; j<= M - K + 1; j+=S){
            int c_r = i + half_k;
            int c_c = j + half_k;
            int hori_sum = row_sum[c_r][j + K - 1] - row_sum[c_r][j - 1];
            int vert_sum = col_sum[i + K - 1][c_c] - col_sum[i - 1][c_c];
            int res = hori_sum + vert_sum - arr[c_r][c_c];
            cout << res << " ";
        }
        cout << "\n";
    }
}