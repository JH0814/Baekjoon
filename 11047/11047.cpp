#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i<N; i++) cin >> A[i];
    int cnt = 0;
    int ptr = N - 1;
    while(K > 0){
        if(A[ptr] > K){
            ptr--;
        }
        else{
            K -= A[ptr];
            cnt++;
        }
    }
    cout << cnt << "\n";
}