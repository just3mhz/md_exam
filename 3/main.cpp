#include <iostream>
#include <vector>
#include <cassert>

using VectorInt = std::vector<int>;
using DState = std::vector<VectorInt>;

int min3(int x, int y, int z) {
    return std::min(x, std::min(y, z));
}

int LDist(const std::string &s, const std::string &t) {
    DState d(s.size() + 1, VectorInt (t.size() + 1));
    for (int i = 0; i <= s.size(); ++i) {
        d[i][0] = i;
    }
    for (int j = 0; j <= t.size(); ++j) {
        d[0][j] = j;
    }
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j <= t.size(); ++j) {
            if ( s[i - 1] == t[j - 1] ) {
                d[i][j] = d[i - 1][j - 1];
            }
            else {
                d[i][j] = min3(
                            d[i - 1][j - 1],
                            d[i - 1][j],
                            d[i][j - 1]
                        ) + 1;
            }
        }
    }
    return d[s.size()][t.size()];
}

void Test() {
    {
        assert(LDist("banana", "ananas") == 2);
        assert(LDist("ananas", "banana") == 2);
    }
    {
        assert(LDist("from", "for") == 2);
        assert(LDist("for", "from") == 2);
    }
    {
        assert(LDist("abcd", "abcd") == 0);
    }
}

int main() {
    Test();
    std::string s, t; 
    std::cin >> s >> t;
    std::cout << LDist(s, t);
}
