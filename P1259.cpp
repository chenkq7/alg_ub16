/*
ooooxxxx--
ooo--xxxox
oooxoxx--x
o--xoxxoox
oxoxox--ox
--oxoxoxox 
*/
/*
ooooo*****--
oooo--****o*
oooo****--o*
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int NMAX = 200 + 5;
char chess[NMAX];
int n;

void solve_4()
{
    swap(chess[3], chess[8]), swap(chess[4], chess[9]), puts(chess);
    swap(chess[3], chess[7]), swap(chess[4], chess[8]), puts(chess);
    swap(chess[1], chess[7]), swap(chess[2], chess[8]), puts(chess);
    swap(chess[1], chess[6]), swap(chess[2], chess[7]), puts(chess);
    swap(chess[0], chess[6]), swap(chess[1], chess[7]), puts(chess);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        chess[i] = 'o', chess[n + i] = '*';
    chess[2 * n] = chess[2 * n + 1] = '-';
    puts(chess);
    int len = n;
    while (len > 4)
    {
        swap(chess[len - 1], chess[2 * len]), swap(chess[len], chess[2 * len + 1]), puts(chess);
        swap(chess[len - 1], chess[2 * len - 2]), swap(chess[len], chess[2 * len - 1]), puts(chess);
        len--;
    }
    solve_4();
    return 0;
}
