#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int ans = arr[0];
    int temp = arr[0];
    for(int i = 1; i<n; i++){
        temp = max(arr[i], temp + arr[i]);
        ans = max(ans, temp);
    }
    cout << ans << endl;
}