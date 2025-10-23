#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr;
    for(int i = 0; i<N; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int ans = 0;
    stack<int> st;
    for(int i = 0; i<=N; i++){
        int cur = (i == N) ? 0 : arr[i];
        while(!st.empty() && cur < arr[st.top()]){
            int h = arr[st.top()];
            st.pop();
            int w = (st.empty()) ? i : i - st.top() - 1;
            ans = max(ans, w * h);
        }
        st.push(i);
    }
    cout << ans << endl;
}