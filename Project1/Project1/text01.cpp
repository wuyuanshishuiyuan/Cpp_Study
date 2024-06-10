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
    int n;                        //�ŵ��ĸ���
    int s;                        //���ܺ�
    cout << "�����뵱ǰ�ŵ��ĸ�����" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "����ŵ���Ϊ��";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cout << a[i] << " ";
    }
    cout << endl;
    while (1)
    {
        cout << endl;
        cout << "              ��������������������������������������������������" << endl;
        cout << "              �������� ��  �����̵����㷨�����б���      �� ��" << endl;
        cout << "              �ĩ�����������������������������������������������" << endl;
        cout << "              ��     1�������ȷ����㷨��FCFS��                ��" << endl;
        cout << "              �ĩ�����������������������������������������������" << endl;
        cout << "              ��     2�����Ѱ��ʱ���㷨��SSTF��              ��" << endl;
        cout << "              �ĩ�����������������������������������������������" << endl;
        cout << "              ��     3��ɨ���㷨��SCAN��                      ��" << endl;
        cout << "              �ĩ�����������������������������������������������" << endl;
        cout << "              ��     4��ѭ��ɨ���㷨��CSCAN��                 ��" << endl;
        cout << "              �ĩ�����������������������������������������������" << endl;
        cout << "              ��     0���˳�                                  ��" << endl;
        cout << "              ��������������������������������������������������" << endl;
        cout << endl;
        cout << "��ѡ�����蹦�ܵ�ǰ�ñ��:";
        cin >> s;
        if (s > 4)
        {
            cout << "���������������������룺" << endl;
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
//�����ȷ�������㷨��FCFS��
void FCFS(int a[], int n)
{
    int j, i, first = 0, now;
    float sum = 0, m;
    cout << "�����뵱ǰ�ŵ��ţ�";
    cin >> now;//ȷ����ǰ��ͷ����λ��
    cout << "���̵���˳��Ϊ��" << endl;
    for (i = 0; i < n; i++)//������˳������ŵ���
    {
        cout << a[i] << " ";
    }
    //����sum
    for (i = 0, j = 1; j < n; i++, j++)
    {
        first += abs(a[j] - a[i]);//��Χ�ŵ���������ŵ��ľ���
    }
    sum += first + abs(now - a[0]);
    cout << endl;
    cout << "�ƶ����ܴŵ���Ϊ�� " << sum << endl;
    m = sum / n;
    cout << "ƽ��Ѱ������Ϊ�� " << m << endl;
}
//���Ѱ��ʱ���㷨��SSTF��
void SSTF(int a[], int n)
{
    int temp;
    int k = 1;
    int now, l, r;
    int i, j;
    float m, sum = 0;
    //���ŵ��Ű���������
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
    cout << "������˳���źõĴŵ���ʾΪ��" << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";//����źõĴŵ�˳��
    }
    cout << endl;
    cout << "�����뵱ǰ�Ĵŵ��ţ�";
    cin >> now;//ȷ����ǰ��ͷ����λ��
    cout << "���̵���˳��Ϊ��" << endl;
    if (a[n - 1] <= now)//��ǰ��ͷλ�ô�������Χ�����ʴŵ�
    {
        for (i = n - 1; i >= 0; i--)
            cout << a[i] << " ";
        sum = now - a[0];
    }
    else
        if (a[0] >= now)//��ǰ��ͷλ��С�����������ʴŵ�
        {
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            sum = a[n - 1] - now;
        }
        else
        {
            while (a[k] < now)//ȷ����ǰ�ŵ������ŵ������е�λ��
            {
                k++;
            }
            l = k - 1;//�ڴ�ͷλ�õ�ǰһ�������ʴŵ�
            r = k;//��ͷ�����ʴŵ�

            while ((l >= 0) && (r < n))
            {
                if ((now - a[l]) <= (a[r] - now))//ѡ�����ͷ���Ĵŵ�
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
            if (l = -1)//��ͷλ�����Ĵŵ��ѷ�����
            {
                for (j = r; j < n; j++)//���ʴ�ͷλ�����Ĵŵ�
                {
                    cout << a[j] << " ";
                }
                sum += a[n - 1] - a[0];
            }
            if (r == n)//��ͷλ�����Ĵŵ��ѷ�����
            {
                for (j = k - 1; j > -1; j--) //���ʴ�ͷλ�����Ĵŵ�
                {
                    cout << a[j] << " ";
                }
                sum += a[n - 1] - a[0];
            }
        }
    cout << endl;
    cout << "�ƶ����ܵ���Ϊ:" << sum << endl;
    m = sum / n;
    cout << "ƽ��Ѱ������Ϊ�� " << m << endl;
}
//ɨ���㷨��SCAN��
void SCAN(int a[], int n)
{
    int temp;
    int k = 1;
    int now, l, r;
    int i, j;
    float m, sum = 0;
    for (i = 0; i < n; i++)//�Է��ʴŵ�����С����˳���������
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    cout << "������˳���źõĴŵ�Ϊ��" << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "�����뵱ǰ�Ĵŵ��ţ�";
    cin >> now;
    //�����㷨ȷ���ŵ�����˳��
    if (a[n - 1] <= now) //��ͷλ�ô�������Χ�����ʴŵ�
    {
        for (i = n - 1; i >= 0; i--)
            cout << a[i] << " ";
        sum = now - a[0];
    }
    else
        if (a[0] >= now) //��ͷλ��С�����������ʴŵ�
        {
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            sum = a[n - 1] - now;
        }
        else                   //��ͷλ���������ŵ��������ŵ�֮��
        {
            int d;
            while (a[k] < now)
            {             //ȷ����ǰ�ŵ������ŵ������е�λ��
                k++;
            }
            l = k - 1;//�ڴ�ͷλ�õ�ǰһ�������ʴŵ�
            r = k;   //��ͷ�����ʴŵ�
            cout << "�����뵱ǰ��ͷ�ƶ��ķ��� (0 ��ʾ���� ��1��ʾ����) : ";
            cin >> d;    //ȷ����ͷ���ʵķ���
            cout << "���̵���˳��Ϊ��";
            if (d == 0 || d == 1)
            {
                if (d == 0)    //��ͷ����
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
                if (d == 1)               //��ͷ����
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
                cout << "������0��1��" << endl;
        }
    cout << endl;
    cout << "�ƶ����ܵ���Ϊ�� " << sum << endl;
    m = sum / n;
    cout << "ƽ��Ѱ������Ϊ�� " << m << endl;
}
//ѭ��ɨ���㷨��CSCAN��
void CSCAN(int a[], int n)
{
    int temp;
    int now, l, r;
    int i, j;
    float m, sum = 0;
    int k = 1;
    for (i = 0; i < n; i++)//�Է��ʴŵ�����С����˳���������
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    cout << "������˳���źõĴŵ�Ϊ��" << endl;
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "�����뵱ǰ�Ĵŵ��ţ�";
    cin >> now;//ȷ����ǰ�ŵ���
    if (a[n - 1] <= now)//��ͷλ�ô�������Χ�����ʴŵ�
    {
        for (i = 0; i < n; i++)
            cout << a[i] << " ";
        sum = now - 2 * a[0] + a[n - 1];
    }
    else
        if (a[0] >= now)//��ͷλ��С�����������ʴŵ�
        {
            for (i = 0; i < n; i++)
                cout << a[i] << " ";
            sum = a[n - 1] - now;
        }
        else //��ͷλ���������ŵ��������ŵ�֮��
        {
            int d;
            while (a[k] < now)
            {
                k++;
            }
            l = k - 1;//�ڴ�ͷλ�õ�ǰһ�������ʴŵ�
            r = k;   //��ͷ�����ʴŵ�
            cout << "�����뵱ǰ��ͷ�ƶ��ķ��� (0 ��ʾ���� ��1��ʾ����) : ";
            cin >> d;    //ȷ����ͷ���ʵķ���
            cout << "���̵���˳��Ϊ��";
            if (d == 0 || d == 1)
            {
                if (d == 1)    //��ͷ��������
                {
                    for (j = r; j < n; j++)//�ȷ������ŵ���ת�����������ʴŵ�
                    {
                        cout << a[j] << " ";
                    }
                    for (j = 0; j < r; j++)
                    {
                        cout << a[j] << " ";
                    }
                    sum = 2 * a[n - 1] - now - 2 * a[0] + a[l];
                }
                if (d == 0)                //��ͷ���ڲ����
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
                cout << "������0��1!";
        }
    cout << endl;
    cout << "�ƶ����ܵ���Ϊ�� " << sum << endl;
    m = sum / n;
    cout << "ƽ��Ѱ������Ϊ�� " << m << endl;
}
