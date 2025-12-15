#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    int ans = 2000000001;
    int fir = 0;
    int lst = 0;
    while(fir < N && lst < N){
        int d = A[lst] - A[fir];
        if(d < M){
            lst++;
        }
        else{
            ans = min(ans, d);
            fir++;
        }
    }
    cout << ans << "\n";
}