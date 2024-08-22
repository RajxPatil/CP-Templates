#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
    }

    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
        size[v] = 1;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];  
            if (rank[a] == rank[b])
                ++rank[a];
        }
    }

    int component_size(int v) {
        return size[find_set(v)];
    }
};

signed main(){
    int n = 5;  
    DSU dsu(n);

    dsu.union_sets(0, 1);
    dsu.union_sets(3, 4);
    dsu.union_sets(1, 3);

    if (dsu.find_set(0) == dsu.find_set(4)) {
        std::cout << "0 and 4 are in the same set" << std::endl;
    } else {
        std::cout << "0 and 4 are in different sets" << std::endl;
    }

}

