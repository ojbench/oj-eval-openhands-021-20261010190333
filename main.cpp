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
    // sort by x-coordinate (all x are distinct)
    sort(pts.begin(), pts.end(), [](const auto &a, const auto &b){return a.first < b.first;});
    vector<long long> y(n);
    for(int i=0;i<n;++i) y[i]=pts[i].second;
    // coordinate compression for BIT
    vector<long long> comp=y;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    int m=comp.size();
    vector<int> bit(m+2,0);
    auto add=[&](int idx){
        for(; idx<=m; idx+=idx&-idx) bit[idx]++;
    };
    auto sum=[&](int idx){
        int s=0; for(; idx>0; idx-=idx&-idx) s+=bit[idx]; return s;
    };
    long long ans=0;
    long long cur_min = LLONG_MAX;
    int total=0; // number of minima stored in BIT
    for(int i=n-1;i>=0;--i){
        long long yi=y[i];
        int pos = lower_bound(comp.begin(), comp.end(), yi) - comp.begin() + 1; // 1-indexed
        // count minima to the right with value > yi
        int cnt = total - sum(pos);
        ans += cnt;
        if(yi < cur_min){
            cur_min = yi;
            add(pos);
            total++;
        }
    }
    cout << ans << "\n";
    return 0;
}
