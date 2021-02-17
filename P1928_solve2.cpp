#include <cstdio>
#define M 10000

char *print(char *begin, int times);
char zip[M];

int main()
{
    gets(zip);
    print(zip, 1);
    return 0;
}

/*打印函数：
输入起始坐标
*/

char *print(char *begin, int times) //这里输入的是的下一个的坐标，不是左括号也不是数字的
{
    int i;
    int j;
    int end;

    for (i = 1; i <= times; i++)
    {
        for (j = 0; begin[j] != ']' && begin[j] != '\0'; j++)
        {
            if (begin[j] != '[')
                printf("%c", begin[j]);
            if (begin[j] == '[')
            {
                if (begin[j + 2] < '0' || begin[j + 2] > '9')
                    j = print(begin + j + 2, begin[j + 1] - '0') - begin;
                else
                    j = print(begin + j + 3, ((begin[j + 1] - '0') * 10 + begin[j + 2] - '0')) - begin;
            }
        }
    }

    if (begin[j] == ']' || begin[j] == '\0')
        return begin + j;
}