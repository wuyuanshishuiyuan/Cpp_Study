#include<iostream>
#include<ctime>
#include<stdlib.h>

using namespace std;
void FCFS(int a[], int n);
void SSTF(int a[], int n);
void SCAN(int a[], int n);
void CSCAN(int a[], int n);
int main()
{
    int n;                        //磁道的个数
    int s;                        //功能号
    cout << "请输入当前磁道的个数：" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "输入磁道号为：";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cout << a[i] << " ";
    }
    cout << endl;
    while (1)
    {
        cout << endl;
        cout << "              ┏━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "              ┃　　　 　  　磁盘调度算法功能列表　　      　 ┃" << endl;
        cout << "              ┠───────────────────────┨" << endl;
        cout << "              ┃     1、先来先服务算法（FCFS）                ┃" << endl;
        cout << "              ┠───────────────────────┨" << endl;
        cout << "              ┃     2、最短寻道时间算法（SSTF）              ┃" << endl;
        cout << "              ┠───────────────────────┨" << endl;
        cout << "              ┃     3、扫描算法（SCAN）                      ┃" << endl;
        cout << "              ┠───────────────────────┨" << endl;
        cout << "              ┃     4、循环扫描算法（CSCAN）                 ┃" << endl;
        cout << "              ┠───────────────────────┨" << endl;
        cout << "              ┃     0、退出                                  ┃" << endl;
        cout << "              ┗━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        cout << endl;
        cout << "请选择所需功能的前置编号:";
        cin >> s;
        if (s > 4)
        {
            cout << "数据输入有误！请重新输入：" << endl;
        }
        else
        {
            switch (s)
            {
            case 0: exit(0); break;
            case 1:FCFS(a, n); break;
            case 2:SSTF(a, n); break;
            case 3:SCAN(a, n); break;
            case 4:CSCAN(a, n); break;
            }
        }
    }
    return 0;
}
//先来先服务调度算法（FCFS）
void FCFS(int a[], int n)
{
    int j, i, first = 0, now;
    float sum = 0, m;
    cout << "请输入当前磁道号：";
    cin >> now;//确定当前磁头所在位置
    cout << "磁盘调度顺序为：" << endl;
    for (i = 0; i < n; i++)//按访问顺序输出磁道号
    {
        cout << a[i] << " ";
    }
    //计算sum
    for (i = 0, j = 1; j < n; i++, j++)
    {
        first += abs(a[j] - a[i]);//外围磁道与最里面磁道的距离
    }
    sum += first + abs(now - a[0]);
    cout << endl;
    cout << "移动的总磁道数为： " << sum << endl;
    m = sum / n;
    cout << "平均寻道长度为： " << m << endl;
}
//最短寻道时间算法（SSTF）
void SSTF(int a[], int n)
{
    int temp;
    int k = 1;
    int now, l, r;
    int i, j;
    float m, sum = 0;
    //将磁道号按递增排序
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    cout << "按递增顺序排好的磁道显示为：" << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";//输出排好的磁道顺序
    }
    cout << endl;
    cout << "请输入当前的磁道号：";
    cin >> now;//确定当前磁头所在位置
    cout << "磁盘调度顺序为：" << endl;
    if (a[n - 1] <= now)//当前磁头位置大于最外围欲访问磁道
    {
        for (i = n - 1; i >= 0; i--)
            cout << a[i] << " ";
        sum = now - a[0];
    }
    else
        if (a[0] >= now)//当前磁头位置小于最里欲访问磁道
        {
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            sum = a[n - 1] - now;
        }
        else
        {
            while (a[k] < now)//确定当前磁道在已排的序列中的位置
            {
                k++;
            }
            l = k - 1;//在磁头位置的前一个欲访问磁道
            r = k;//磁头欲访问磁道

            while ((l >= 0) && (r < n))
            {
                if ((now - a[l]) <= (a[r] - now))//选择离磁头近的磁道
                {
                    cout << a[l] << " ";
                    sum += now - a[l];
                    now = a[l];
                    l = l - 1;
                }
                else
                {
                    cout << a[r] << " ";
                    sum += a[r] - now;
                    now = a[r];
                    r = r + 1;
                }
            }
            if (l = -1)//磁头位置里侧的磁道已访问完
            {
                for (j = r; j < n; j++)//访问磁头位置外侧的磁道
                {
                    cout << a[j] << " ";
                }
                sum += a[n - 1] - a[0];
            }
            if (r == n)//磁头位置外侧的磁道已访问完
            {
                for (j = k - 1; j > -1; j--) //访问磁头位置里侧的磁道
                {
                    cout << a[j] << " ";
                }
                sum += a[n - 1] - a[0];
            }
        }
    cout << endl;
    cout << "移动的总道数为:" << sum << endl;
    m = sum / n;
    cout << "平均寻道长度为： " << m << endl;
}
//扫描算法（SCAN）
void SCAN(int a[], int n)
{
    int temp;
    int k = 1;
    int now, l, r;
    int i, j;
    float m, sum = 0;
    for (i = 0; i < n; i++)//对访问磁道按由小到大顺序排列输出
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    cout << "按递增顺序排好的磁道为：" << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "请输入当前的磁道号：";
    cin >> now;
    //以下算法确定磁道访问顺序
    if (a[n - 1] <= now) //磁头位置大于最外围欲访问磁道
    {
        for (i = n - 1; i >= 0; i--)
            cout << a[i] << " ";
        sum = now - a[0];
    }
    else
        if (a[0] >= now) //磁头位置小于最里欲访问磁道
        {
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            sum = a[n - 1] - now;
        }
        else                   //磁头位置在最里侧磁道与最外侧磁道之间
        {
            int d;
            while (a[k] < now)
            {             //确定当前磁道在已排的序列中的位置
                k++;
            }
            l = k - 1;//在磁头位置的前一个欲访问磁道
            r = k;   //磁头欲访问磁道
            cout << "请输入当前磁头移动的方向 (0 表示向内 ，1表示向外) : ";
            cin >> d;    //确定磁头访问的方向
            cout << "磁盘调度顺序为：";
            if (d == 0 || d == 1)
            {
                if (d == 0)    //磁头向内
                {
                    for (j = l; j >= 0; j--)
                    {
                        cout << a[j] << " ";
                    }
                    for (j = r; j < n; j++)
                    {
                        cout << a[j] << " ";
                    }
                    sum = now - 2 * a[0] + a[n - 1];
                }
                if (d == 1)               //磁头向外
                {
                    for (j = r; j < n; j++)
                    {
                        cout << a[j] << " ";
                    }
                    for (j = l; j >= 0; j--)
                    {
                        cout << a[j] << " ";
                    }
                    sum = 2 * a[n - 1] - now - a[0];
                }
            }
            else
                cout << "请输入0或1！" << endl;
        }
    cout << endl;
    cout << "移动的总道数为： " << sum << endl;
    m = sum / n;
    cout << "平均寻道长度为： " << m << endl;
}
//循环扫描算法（CSCAN）
void CSCAN(int a[], int n)
{
    int temp;
    int now, l, r;
    int i, j;
    float m, sum = 0;
    int k = 1;
    for (i = 0; i < n; i++)//对访问磁道按由小到大顺序排列输出
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    cout << "按递增顺序排好的磁道为：" << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "请输入当前的磁道号：";
    cin >> now;//确定当前磁道号
    if (a[n - 1] <= now)//磁头位置大于最外围欲访问磁道
    {
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
        sum = now - 2 * a[0] + a[n - 1];
    }
    else
        if (a[0] >= now)//磁头位置小于最里欲访问磁道
        {
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            sum = a[n - 1] - now;
        }
        else //磁头位置在最里侧磁道与最外侧磁道之间
        {
            int d;
            while (a[k] < now)
            {
                k++;
            }
            l = k - 1;//在磁头位置的前一个欲访问磁道
            r = k;   //磁头欲访问磁道
            cout << "请输入当前磁头移动的方向 (0 表示向内 ，1表示向外) : ";
            cin >> d;    //确定磁头访问的方向
            cout << "磁盘调度顺序为：";
            if (d == 0 || d == 1)
            {
                if (d == 1)    //磁头向外侧访问
                {
                    for (j = r; j < n; j++)//先访问外侧磁道再转向最里欲访问磁道
                    {
                        cout << a[j] << " ";
                    }
                    for (j = 0; j < r; j++)
                    {
                        cout << a[j] << " ";
                    }
                    sum = 2 * a[n - 1] - now - 2 * a[0] + a[l];
                }
                if (d == 0)                //磁头向内侧访问
                {
                    for (j = r - 1; j >= 0; j--)
                    {
                        cout << a[j] << " ";
                    }
                    for (j = n - 1; j >= r; j--)
                    {
                        cout << a[j] << " ";
                    }
                    sum = 2 * a[n - 1] - 2 * a[0] + now - a[r];
                }
            }
            else
                cout << "请输入0或1!";
        }
    cout << endl;
    cout << "移动的总道数为： " << sum << endl;
    m = sum / n;
    cout << "平均寻道长度为： " << m << endl;
}
