#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> BFS(int start, int N, vector<vector<pair<int, int>>>& arr){
    queue<int> q;
    vector<bool> visited(N + 1, false);
    vector<int> dis(N + 1, 0);
    dis[start] = 0;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i<arr[cur].size(); i++){
            int nei = arr[cur][i].first;
            if(!visited[nei]){
                visited[nei] = true;
                dis[nei] = dis[cur] + arr[cur][i].second;
                q.push(nei);
            }
        }
    }
    return dis;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> arr(N + 1);
    for(int i = 0; i<N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    vector<int> dis1 = BFS(1, N, arr);
    int max_val = 0;
    int idx = 1;
    for(int i = 1; i<=N; i++){
        if(max_val < dis1[i]){
            idx = i;
            max_val = dis1[i];
        }
    }
    max_val = 0;
    vector<int> dis2 = BFS(idx, N, arr);
    for(int i = 1; i<=N; i++){
        if(max_val < dis2[i]){
            max_val = dis2[i];
        }
    }
    cout << max_val << endl;
}