#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N;
    cin >> K;
    long long fir = 1;
    long long lst = K;
    long long ans = 0;
    while(fir <= lst){
        long long mid = (fir + lst) / 2;
        long long count = 0;
        for(int i = 1; i<=N; i++){
            count += min((long long)N, mid/i);
        }
        if(count >= K){
            ans = mid;
            lst = mid - 1;
        }
        else{
            fir = mid + 1;
        }
    }   
    cout << ans << endl;
}