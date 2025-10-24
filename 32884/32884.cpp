    #include<iostream>
    #include<algorithm>
    #include<vector>
    using namespace std;
    int main(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int N, M;
        cin >> N >> M;
        vector<vector<int>> arr(N, vector<int>(M));
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cin >> arr[i][j];
            }
        }
        long long ans = 0;
        for(int i = 0; i<N; i++){
            vector<long long> temp_arr(M, 0);
            for(int p = i; p<N; p++){
                for(int q = 0; q<M; q++){
                    temp_arr[q] += arr[p][q];
                }
                long long temp_max = 0;
                long long cur = 0;
                for(int q = 0; q<M; q++){
                    cur = max(0LL, cur + temp_arr[q]);
                    temp_max = max(temp_max, cur);
                }
                ans = max(ans, temp_max);
            }
        }
        cout << ans << endl;
    }