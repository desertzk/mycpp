#include <stdio.h>

int main()
{
    /* 局部变量定义 */
    int a = 10;

    /* do 循环执行 */
LOOP:
    do
    {
        if (a == 15)
        {
            /* 跳过迭代 */
            a = a + 1;
            goto LOOP;
        }
        if (a == 12)
        {
            /* 跳过迭代 */
            a = a + 1;
            goto restart_timer;
        }

        printf("a 的值： %d\n", a);
        a++;

    } while (a < 20);



restart_timer:
    printf("restart_timer");

out:
    return 0;
}