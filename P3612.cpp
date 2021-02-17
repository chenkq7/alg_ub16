#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long ll;

#define DEBUG(x) cout << #x << " = " << x << endl

int main(int argc, char const *argv[])
{
    string s;
    ll ind, anchor;
    cin >> s >> ind;
    anchor = s.size();
    while (anchor < ind) anchor <<= 1;
    // Invariant: anchor >= ind
    while (anchor > s.size())
    {
        anchor >>= 1;
        if (anchor < ind)
        {
            ind = ind - anchor - 1;
            if (ind == 0)
                ind = anchor;
        }
    }
    cout << s[ind - 1];
    return 0;
}

/**
 * 1 2 3   4 5 6    7 8 9    10 11 12
 * C O W   W C O    O C O    W  W  C
 * */