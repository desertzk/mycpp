#include <stdio.h>

int main()
{
    /* �ֲ��������� */
    int a = 10;

    /* do ѭ��ִ�� */
LOOP:
    do
    {
        if (a == 15)
        {
            /* �������� */
            a = a + 1;
            goto LOOP;
        }
        if (a == 12)
        {
            /* �������� */
            a = a + 1;
            goto restart_timer;
        }

        printf("a ��ֵ�� %d\n", a);
        a++;

    } while (a < 20);



restart_timer:
    printf("restart_timer");

out:
    return 0;
}