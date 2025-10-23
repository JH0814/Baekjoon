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
                visited[nei] = true;
                dis[nei] = dis[cur] + 1;
                q.push(nei);
            }
        }
    }
    int max_val = 0;
    for(int i = 1; i<=N; i++){
        max_val = max(max_val, dis[i]);
    }
    return max_val;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> arr(N + 1);
    while(true){
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    vector<int> dis(N + 1);
    int x = N + 1;
    for(int i = 1; i<=N; i++){
        int val = BFS(i, N, arr);
        dis[i] = val;
        x = min(x, val);
    }
    vector<int> ans;
    for(int i = 1; i<=N; i++){
        if(dis[i] == x){
            ans.push_back(i);
        }
    }
    cout << x << " " << ans.size() << endl;
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}