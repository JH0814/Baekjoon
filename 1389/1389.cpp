#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int BFS(int start, int N, vector<vector<int>>& arr){
    vector<int> dis(N + 1, 0);
    queue<int> q;
    vector<bool> visited(N + 1, false);
    dis[start] = 0;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i<arr[cur].size(); i++){
            int nei = arr[cur][i];
            if(!visited[nei]){
                q.push(nei);
                visited[nei] = true;
                dis[nei] = dis[cur] + 1;
            }
        }
    }
    int res = 0;
    for(int i = 1; i<=N; i++){
        res += dis[i];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N + 1);
    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int ans = 0;
    int ans_val = 999999999;
    for(int i = 1; i<=N; i++){
        int val = BFS(i, N, arr);
        if(val < ans_val){
            ans = i;
            ans_val = val;
        }
    }
    cout << ans << endl;
}