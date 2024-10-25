struct Bit { 
    int n;
    vector<ll> bit;
    Bit(int _n = 0) : n(_n), bit(n + 1) {}

    void update(int i, ll x) {
        for(i++; i <= n; i += i & -i) bit[i] += x;
    } 

    ll pref(int i) {
        ll ret = 0;
        for(i++; i; i-= i & -i) ret += bit[i];
        return ret;
    }
};