#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long A, B, C;
    cin >> A >> B >> C;
    long long ans = 1;
    long long base = A % C;
    while(B > 0){
        if(B % 2 == 1){
            ans = (ans * base) % C;
        }
        base = (base * base) % C;
        B /= 2;
    }
    cout << ans << endl;
    return 0;
}