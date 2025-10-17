#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<long long > arr(N + 1, 0);
    for(int i = 1; i<=N; i++){
        int num;
        cin >> num;
        arr[i] = num + arr[i - 1];
    }
    int I, J;
    for(int i = 0; i<M; i++){
        cin >> I >> J;
        cout << arr[J] - arr[I - 1] << '\n';
    }
}