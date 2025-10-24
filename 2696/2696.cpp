#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int t = 0; t<T; t++){
        int N;
        cin >> N;
        priority_queue<int> fir;
        priority_queue<int, vector<int>, greater<int>> lst;
        vector<int> med;
        for(int i = 1; i<=N; i++){
            int num;
            cin >> num;
            fir.push(num);
            lst.push(fir.top());
            fir.pop();
            if(fir.size() < lst.size()){
                fir.push(lst.top());
                lst.pop();
            }
            if(i % 2 == 1){
                med.push_back(fir.top());
            }
        }
        cout << med.size() << endl;
        for(int i = 0; i<med.size(); i++){
            cout << med[i] << " ";
            if((i + 1) % 10 == 0){
                cout << endl;
            }
        }
        if(med.size() % 10 != 0){
            cout << endl;
        }
    }
}