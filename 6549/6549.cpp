#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        int n;
        cin >> n;
        if(n == 0) return 0;
        vector<int> arr;
        for(int i = 0; i<n; i++){
            int num;
            cin >> num;
            arr.push_back(num);
        }
        long long   ans = 0;
        stack<int> st;
        for(int i = 0; i<=n; i++){
            int cur = (i == n) ? 0 : arr[i];
            while(!st.empty() && cur < arr[st.top()]){
                long long  h = arr[st.top()];
                st.pop();
                long long  w = (st.empty()) ? i : i - st.top() - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }
        cout << ans << endl;
    }
}