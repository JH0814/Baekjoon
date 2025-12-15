#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i<N; i++) cin >> A[i];
    int fir = 0;
    int lst = 0;
    int sum = 0;
    int cnt = 0;
    while(true){
        if(sum >= M){
            if(sum == M) cnt++;
            sum -= A[fir++];
        }
        else if(lst == N) break;
        else{
            sum += A[lst++];
        }
    }
    cout << cnt << "\n";
}