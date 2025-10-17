#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void BFS(int N, int K){
    queue<pair<int, int>> q;
    vector<bool> visited(100000 + 1, false);
    q.push({N, 0});
    visited[N] = true;
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == K){
            cout << cnt << endl;
            break;
        }
        vector<int> next;
        next.push_back(cur - 1);
        next.push_back(cur + 1);
        next.push_back(2 * cur);
        for(int i = 0; i<3; i++){
            if(next[i] > 100000 || next[i] < 0 || visited[next[i]]){
                continue;
            }
            visited[next[i]] = true;
            q.push({next[i], cnt + 1});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    BFS(N, K);

}