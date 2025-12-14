#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    vector<vector<int>> arr(N + 1);
    vector<int> indegree(N + 1, 0);
    int A, B;
    for(int i = 0; i<M; i++){
        cin >> A >> B;
        arr[A].push_back(B);
        indegree[B]++;
    }
    queue<int> q;
    for(int i = 1; i<=N; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    } 
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int next : arr[cur]){
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    cout << "\n";
}