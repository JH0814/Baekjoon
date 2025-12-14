#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W; cin >> H >> W;
    vector<int> arr(W);
    for(int i = 0; i<W; i++) cin >> arr[i];
    int fir = 0;
    int lst = W - 1;
    int left_max = arr[fir];
    int right_max = arr[lst];
    int tot = 0;
    while(fir < lst){
        if(left_max <= right_max){
            fir++;
            if(arr[fir] > left_max){
                left_max = arr[fir];
            }
            else{
                tot += (left_max - arr[fir]);
            }
        }
        else{
            lst--;
            if(arr[lst] > right_max){
                right_max = arr[lst];
            }
            else{
                tot += (right_max - arr[lst]);
            }
        }
    }
    cout << tot << "\n";
}