#include <iostream>
#include <map>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    map<int, int> arr;
    int n, x = 0, y = 0;
    cin >> n;
    
    for (int j = 1; j <= n; j++) {
        int temp;
        cin >> temp;

        if (temp >= 100) {  
            arr[temp] = j;
            continue;
        } else {
            int target = 100 - temp;
        
            auto cari = arr.find(target);
            if (cari != arr.end()) {
                x = cari->second;
                y = j;
                break;
            }
            
            arr[temp] = j;
        }
        
    }
    
    cout << x << "\n" << y;
    
    return 0;
}