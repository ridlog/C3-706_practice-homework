#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    ifstream in("in.txt");
    in>>n>>m;
    int q = n+m;
    int num;
    set<int>arr;
    for(int i = 0;i<q;i++){
        in>>num;
        arr.insert(num);
    }
    auto ii = arr.begin();
    while(1){
        cout<<*ii<<' ';
        ii++;
        if(ii==arr.end()){
            break;
        }
    }
}
