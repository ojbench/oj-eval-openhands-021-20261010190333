#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin >> n)) return 0;
    vector<pair<long long,long long>> pts(n);
    for(int i=0;i<n;++i){
        long long x,y;cin>>x>>y;pts[i]={x,y};
    }
    sort(pts.begin(), pts.end(), [](auto &a, auto &b){return a.first<b.first;});
    set<long long> seenY;
    long long ans=0;
    for(auto &p: pts){
        long long y=p.second;
        auto it=seenY.lower_bound(y);
        if(it!=seenY.begin()) ans++;
        seenY.insert(y);
    }
    cout<<ans<<"\n";
    return 0;
}
