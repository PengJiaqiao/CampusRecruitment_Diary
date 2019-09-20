#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
/*将4杯子倒水问题改为一个足够大的杯子倒向4个杯子*/
bitset<17043521> Hash; /*（大小为64*64^4+64*64^3+64*64^2+64*64^1+64*64^0）记录每次操作后的ABCD杯子的当前容量是否已经存在过*/
const int MAX_STEP = 100000;
int WQ[MAX_STEP][6]; /*记录每步操作后0和ABCD的当前容量，最后一个记录操作次数*/
int Goal[5];         /*0和ABCD杯子最终状态*/
int Cap[5];          /*0和ABCD杯子的最大容量*/
int goalval;
int head = 0;
int tail = 0;
void movw(int numfrom, int numto, int other1, int other2, int other3) /*numfrom倒入numto*/
{
    int total = WQ[head][numfrom] + WQ[head][numto]; /*numfrom和numto的总量*/
    WQ[tail][other1] = WQ[head][other1];
    WQ[tail][other2] = WQ[head][other2];
    WQ[tail][other3] = WQ[head][other3];
    WQ[tail][5] = WQ[head][5] + 1;

    if (total > Cap[numto]) /*总量和被倒入杯子的容量大小；大于numfrom就有剩余的，否则全部倒入numto*/
    {
        WQ[tail][numfrom] = total - Cap[numto];
        WQ[tail][numto] = Cap[numto];
    }
    else
    {
        WQ[tail][numfrom] = 0;
        WQ[tail][numto] = total;
    }

    int hashval = WQ[tail][1] * 262144 + WQ[tail][2] * 4096 + WQ[tail][3] * 64 + WQ[tail][4]; /*把ABCD杯子需要的状态抽象为一个值*/
    if (hashval == goalval)
        throw WQ[head][5] + 1; /*判断是否为最终状态*/

    if (!Hash[hashval]) /*该次操作之后的状态之前未存在过并记录*/
    {
        Hash[hashval] = true;
        if (++tail == MAX_STEP)
            tail = 0; /*超出最大操作数*/
    }
}
int main()
{
    Hash.reset();
    scanf("%d %d %d %d", &Cap[1], &Cap[2], &Cap[3], &Cap[4]);
    scanf("%d %d %d %d", &Goal[1], &Goal[2], &Goal[3], &Goal[4]);
    head = 0;
    tail = 0;
    goalval = Goal[1] * 262144 + Goal[2] * 4096 + Goal[3] * 64 + Goal[4]; /*把ABCD杯子需要的状态抽象为一个值*/
    /*处理全部杯子中最后容量都为0的情况*/
    if (Goal[1] == 0 && Goal[2] == 0 && Goal[3] == 0 && Goal[4] == 0)
    {
        printf("0");
        return 0;
    }
    Cap[0] = 6400;      /*0杯子为足够大的杯子，0杯子的容量*/
    WQ[tail][0] = 6400; /*0杯子的当前容量*/
    /*初始化ABCD杯子当前值为0*/
    WQ[tail][1] = 0;
    WQ[tail][2] = 0;
    WQ[tail][3] = 0;
    WQ[tail][4] = 0;
    WQ[tail][5] = 0;
    ++tail;
    try
    {
        /*尝试每一种操作*/
        while (head != tail)
        {
            /*A导入B，外层if判断A中当前容量不为零，内层判断B的最大容量不为0*/
            if (WQ[head][0])
            {
                if (Cap[1])
                    movw(0, 1, 2, 3, 4);
                if (Cap[2])
                    movw(0, 2, 1, 3, 4);
                if (Cap[3])
                    movw(0, 3, 1, 2, 4);
                if (Cap[4])
                    movw(0, 4, 1, 2, 3);
            }

            if (WQ[head][1])
            {
                if (Cap[0])
                    movw(1, 0, 2, 3, 4);
                if (Cap[2])
                    movw(1, 2, 0, 3, 4);
                if (Cap[3])
                    movw(1, 3, 0, 2, 4);
                if (Cap[4])
                    movw(1, 4, 0, 2, 3);
            }

            if (WQ[head][2])
            {
                if (Cap[0])
                    movw(2, 0, 1, 3, 4);
                if (Cap[1])
                    movw(2, 1, 0, 3, 4);
                if (Cap[3])
                    movw(2, 3, 0, 1, 4);
                if (Cap[4])
                    movw(2, 4, 0, 1, 3);
            }

            if (WQ[head][3])
            {
                if (Cap[0])
                    movw(3, 0, 1, 2, 4);
                if (Cap[1])
                    movw(3, 1, 0, 2, 4);
                if (Cap[2])
                    movw(3, 2, 0, 1, 4);
                if (Cap[4])
                    movw(3, 4, 0, 1, 2);
            }

            if (WQ[head][4])
            {
                if (Cap[0])
                    movw(4, 0, 1, 2, 3);
                if (Cap[1])
                    movw(4, 1, 0, 2, 3);
                if (Cap[2])
                    movw(4, 2, 0, 1, 3);
                if (Cap[3])
                    movw(4, 3, 0, 1, 2);
            }

            if (++head == MAX_STEP)
            {
                head = 0;
            }
        }
        printf("-1");
    }
    catch (int step)
    {
        printf("%d\n", step);
    }
}