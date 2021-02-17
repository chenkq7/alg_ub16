#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

const int NMAX = 2e4 + 5;
int rBracket[NMAX];
string s;
string solve(int, int);
string process_norm(int, int);

/**
 * @param begin the str begin index, include
 * @param end   the str end index, exclude
 * @return the str after decode
 * */
string process_norm(int begin, int end)
{
    stringstream ss;
    while (begin < end)
    {
        if (s[begin] != '[')
        {
            ss << s[begin];
        }
        else
        {
            ss << solve(begin, rBracket[begin]);
            begin = rBracket[begin];
        }
        begin++;
    }
    return ss.str();
}

/**
 * @param st the index of [
 * @param ed the index of ]
 * @return the str after decode
 * */
string solve(int st, int ed)
{
    int rep = 0;
    st++;
    while (s[st] >= '0' && s[st] <= '9')
    {
        rep = rep * 10 + s[st] - '0';
        st++;
    }
    string ans = process_norm(st, ed);
    stringstream ss;
    while (rep--)
        ss << ans;
    return ss.str();
}

int main(int argc, char const *argv[])
{
    cin >> s;
    stack<int> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[')
            stk.push(i);
        else if (s[i] == ']')
            rBracket[stk.top()] = i, stk.pop();
    }
    cout << process_norm(0, s.size());
    return 0;
}
