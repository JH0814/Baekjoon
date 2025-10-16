#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int** arr = new int*[N];
    for(int i = 0; i<N; i++){
        arr[i] = new int[M];
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    long long ans = 0;
    for(int r1 = 0; r1 < N; r1++){
        std::vector<int> temp_arr(M, 0);
        for(int r2 = r1; r2 < N; r2++){
            for(int c = 0; c < M; c++){
                temp_arr[c] += arr[r2][c];
            }
            long long current_max = 0;
            long long max_for_this_band = 0;
            for(int val : temp_arr){
                current_max += val;
                if(current_max < 0){
                    current_max = 0;
                }
                max_for_this_band = std::max(max_for_this_band, current_max);
            }
            ans = std::max(ans, max_for_this_band);
        }
    }

    std::cout << ans << endl;
    
    for(int i = 0; i<N; i++){
        delete[] arr[i];
    }
    delete[] arr;
}