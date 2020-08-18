#include <iostream>
#include <vector>
#include <cassert>

struct Edge {
    int from;
    int to;
    int w;
};

using EdgeList = std::vector<Edge>;

bool FindCycle(EdgeList &edge_list, int N, int M) {
    std::vector<int> d(N, 0);
    for (int iter = 0; iter <= N; ++iter) {
        bool changed = false;
        for(const Edge &e: edge_list) {
            if (d[e.from] + (-1) * e.w < d[e.to]) {
                d[e.to] = d[e.from] + (-1) * e.w;
                changed = true;
            }
        }
        if (iter == N) {
            return changed;
        }
    }
    return false;
}

void Test() {
    {
        int N = 4;
        int M = 4;
        EdgeList edge_list = {
            {1, 2, -1},
            {2, 3, -1},
            {3, 4, -10},
            {4, 1, 100},
        };
        assert(FindCycle(edge_list, N, M));
    }
    {
        int N = 4;
        int M = 4;
        EdgeList edge_list = {
            {1, 2, -1},
            {2, 3, -1},
            {3, 4, -10},
            {4, 1, 10},
        };
        assert(!FindCycle(edge_list, N, M));
    }
    {
        int N = 4;
        int M = 3;
        EdgeList edge_list = {
            {1, 2, -1},
            {2, 3, -1},
            {3, 4, -10},
        };
        assert(!FindCycle(edge_list, N, M));
    }
}

int main() {
    Test();
    int N, M;
    std::cin >> N >> M;
    EdgeList edge_list(M);
    for (int i = 0; i < M; ++i) {
        int t, f, w;
        std::cin >> f >> t >> w;
        edge_list[i] = {f, t, w};
    }
    std::cout << (FindCycle(edge_list, N, M) ? 1 : 0) << std::endl;
}
