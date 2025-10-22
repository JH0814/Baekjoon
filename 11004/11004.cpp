#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    priority_queue<int> q;
    for(int i = 0; i<N; i++){
        int num;
        cin >> num;
        if(q.size() < K){
            q.push(num);
        }
        else{
            if(num < q.top()){
                q.pop();
                q.push(num);
            }
        }
    }
    cout << q.top() << endl;
}