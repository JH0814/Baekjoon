#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N, -1);
    vector<int> inp;
    stack<int> st;
    for(int i = 0; i<N; i++){
        int num;
        cin >> num;
        inp.push_back(num);
    }
    for(int i = 0; i<N; i++){
        while(!st.empty() && inp[st.top()] < inp[i]){
            arr[st.top()] = inp[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0; i<N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}