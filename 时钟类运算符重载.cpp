#include <iostream>
using namespace std;
class Clock    //时钟类声明
{
public:    //外部接口
    Clock(int NewH = 0, int NewM = 0, int NewS = 0);
    void ShowTime();
    Clock operator ++();        //前置单目运算符重载
    //后置单目运算符重载
    Clock operator ++(int);

    //+运算符重载
    Clock operator +(const Clock& t);

private:    //私有数据成员
    int Hour, Minute, Second;
};

Clock::Clock(int NewH, int NewM, int NewS) {
    Hour = NewH;
    Minute = NewM;
    Second = NewS;
    //进位操作
    if (Second >= 60) {
        Second = Second - 60;
        Minute++;
    }
    if (Minute >= 60) {
        Minute = Minute - 60;
        Hour++;
    }
    if (Hour >= 24) {
        Hour = Hour - 24;
    }
}
Clock Clock::operator +(const Clock& t) {
    int h = Hour + t.Hour;
    int m = Minute + t.Minute;
    int s = Second + t.Second;
    return Clock(h,m,s);
}
Clock Clock::operator ++() {
//调用构造函数，实现进位
    *this = Clock(Hour, Minute, Second + 1);  
    return *this;
}

Clock Clock::operator ++(int) {
    Clock temp = *this;
    *this=Clock(Hour, Minute, Second + 1);
    return temp;
}



void Clock::ShowTime()
{
    cout << Hour << ":" << Minute << ":" << Second << endl;
}

int main()
{
    Clock c1(23, 59, 59), c2(5, 12, 10), c3;
    c1.ShowTime();
    c1++;
    c1.ShowTime();
    c3 = ++c2;
    c3.ShowTime();
    c3 = c2 + c1;
    c3.ShowTime();
    return 0;
}