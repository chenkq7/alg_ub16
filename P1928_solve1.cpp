#include <iostream>
#include <string>
using namespace std;

string read()
{
    string ss = "";
    char c;
    while (cin >> c)
    {
        if (c == '[')
        {
            int n;
            cin >> n;
            string s1 = read();
            ss.reserve(n * ss.size());
            while (n--)
                ss += s1;
        }
        else if (c == ']')
            break;
        else
            ss += c;
    }
    return ss;
}
int main()
{
    cout << read();
    return 0;
}