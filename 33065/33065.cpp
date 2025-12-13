#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef struct rgb{
    int r;
    int g;
    int b;
}RGB;
vector<vector<RGB>> arr;
vector<vector<bool>> visited;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool check_rgb(const RGB& a, const RGB& b) {
    return (a.r == b.r && a.g == b.g && a.b == b.b);
}
void bfs(int x, int y, int N, int M){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i = 0; i<8; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                if(!visited[nx][ny]){
                    if(check_rgb(arr[cx][cy], arr[nx][ny])){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}
int main(){   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    arr.resize(N, vector<RGB>(M));
    visited.resize(N, vector<bool>(M, false));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> arr[i][j].r >> arr[i][j].g >> arr[i][j].b;
        }
    }
    int cnt = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(!visited[i][j]){
                bfs(i, j, N, M);
                cnt++;
            }
        }
    }
    cout << cnt << endl;;
}