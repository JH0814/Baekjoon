#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Meet{
    int s;
    int e;
    int p;
};

bool cmp(const Meet& a, const Meet& b){
    if(a.e == b.e){
        return a.s < b.s;
    }
    return a.e < b.e;
}
int search_job(const vector<Meet>& arr, int idx, int start_val){
    int left = 0;
    int right = idx - 1;
    int ans = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid].e <= start_val){
            ans = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    vector<Meet> arr(N);
    for(int i = 0; i<N; i++) cin >> arr[i].s >> arr[i].e >> arr[i].p;
    vector<long long> dp(N + 1, 0);
    sort(arr.begin(), arr.end(), cmp);
    vector<int> end_time(N);
    for(int i = 0; i<N; i++){
        end_time[i] = arr[i].e;
    }
    dp[0] = arr[0].p;
    for(int i = 1; i<N; i++){
        long long cur = arr[i].p;
        int idx = search_job(arr, i, arr[i].s);
        if(idx != -1){
            cur += dp[idx];
        }
        dp[i] = max(dp[i - 1], cur);
    }
    cout << dp[N - 1] << "\n";
}