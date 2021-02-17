#include <iostream>
#include <algorithm>
using namespace std;
#define DEBUG(x) cout << #x " = " << x << endl
#define TRACE(s) cerr << #s << endl; s
const int NMAX = 5e3 + 5;
struct student
{
    int id;
    int score;
} students[NMAX];

bool le(const student &left, const student &right)
{
    if (left.score != right.score)
        return left.score > right.score;
    return left.id < right.id;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> students[i].id >> students[i].score;
    //
    sort(&students[0], &students[n], le);
    m = m * 1.5;
    while (m < n && students[m - 1].score == students[m].score)
        m++;
    //
    cout << students[m - 1].score << " " << m << endl;
    for (int i = 0; i < m; i++)
        cout << students[i].id << " " << students[i].score << endl;
    return 0;
}
