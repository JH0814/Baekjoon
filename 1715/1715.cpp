#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int, vector<int>, greater<int>> pq;
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        int num;
        cin >> num;
        pq.push(num);
    }
    int ans = 0;
    while(pq.size() > 1){
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        ans += num1 + num2;
        pq.push(num1 + num2);
    }
    cout << ans<< endl;
}