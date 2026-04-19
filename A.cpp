#include <iostream>
#include <map>

using namespace std;

int main(){

    map<int, int>arr;
    int n, x, y, flag=0;

    cin >> n;
    for (int i = 1; i <= n; i++){
        int temp;
        cin >> temp;
        arr.insert({temp, i});
        int a = 100-temp;
        if((flag < 1) && a<100){
            auto cari = arr.find(a);
            auto now = arr.find(temp);
            if((cari != arr.end()) && (cari->second != now->second)){
                x = now->second;
                y = cari->second;
                flag++;
        }
        }
    }
    
    cout << x <<"\n"<< y;

return 0;
}