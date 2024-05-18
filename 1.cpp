////////////////////////////////////////////

// 程序名称：刮刮乐（掩码图的范例）

// 编译环境：Visual C++ 6.0 ~ 2019，EasyX_20220116

#include <graphics.h>
#include<ctime>
#include<cstdlib>
#include <iostream>
using namespace std;
const int offsetx = 170;	// 刮奖区的偏移 x 坐标

const int offsety = 260;	// 刮奖区的偏移 y 坐标

IMAGE imgContent(300, 100);	// 刮开后的内容

IMAGE imgMask(300, 100);	// 已刮部分的掩码层

// 绘制刮刮卡

void DrawCard()

{

    // 白色背景

    setbkcolor(0xf0f0f0);

    cleardevice();

    // 设置刮刮卡填充单元

    IMAGE unit(32, 32);

    SetWorkingImage(&unit);	// 设置绘图设备为 unit 对象

    setbkcolor(0x1a3bf0);	// 设置背景色

    cleardevice();

    settextstyle(20, 0, _T("Webdings"), 0, 0, 400, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);	// 设置图标字体

    settextcolor(0x152fe5);

    outtextxy(0, 16, 0x59);	// 输出两个心

    outtextxy(16, 0, 0x59);

    settextcolor(0x284ff5);

    outtextxy(0, 0, 0x73);	// 输出两个问号

    outtextxy(16, 16, 0x73);

    SetWorkingImage();

    // 用 IMAGE 对象填充矩形区域

    setfillstyle(BS_DIBPATTERN, NULL, &unit);	// 设置填充模式

    solidrectangle(150, 30, 490, 450);	// 画填充矩形

    TCHAR s[] = _T("刮刮乐");

    settextstyle(80, 0, _T("黑体"), 0, 0, 400, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

    setbkmode(TRANSPARENT);

    settextcolor(0x034089);

    outtextxy(offsetx + (300 - textwidth(s)) / 2 + 5, 105, s);

    settextcolor(0x10c2fe);

    outtextxy(offsetx + (300 - textwidth(s)) / 2, 100, s);

    // 设置覆盖层填充单元

    IMAGE unit2(80, 50);

    SetWorkingImage(&unit2);	// 设置绘图设备为 unit 对象

    setbkcolor(LIGHTGRAY);

    cleardevice();

    settextstyle(20, 0, _T("黑体"), 150, 150, 400, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

    settextcolor(0x606060);

    outtextxy(10, 20, _T("刮奖区"));

    SetWorkingImage();

    // 用 IMAGE 对象填充矩形区域

    setfillstyle(BS_DIBPATTERN, NULL, &unit2);	// 设置填充模式

    solidrectangle(offsetx, offsety, offsetx + 300, offsety + 100);	// 画填充矩形

}

// 初始化刮奖区内容

void InitContent()

{
    srand(time(0));

    int a = rand() % 4;
    // 绘制刮奖区内容

    SetWorkingImage(&imgContent);

    setbkcolor(0x05d5ff);

    cleardevice();

    settextcolor(0x0024b8);


    
    if (a == 0) {
        TCHAR  s1[] = _T("二等奖");
        TCHAR s2[] = _T("一篮水果");

        settextstyle(40, 0, _T("黑体"), 0, 0, 900, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

        outtextxy((300 - textwidth(s1)) / 2, 10, s1);

        outtextxy((300 - textwidth(s2)) / 2, 50, s2);
    }
    if (a == 1) {
        TCHAR  s1[] = _T("一等奖");
        TCHAR s2[] = _T("飞机票一张");

        settextstyle(40, 0, _T("黑体"), 0, 0, 900, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

        outtextxy((300 - textwidth(s1)) / 2, 10, s1);

        outtextxy((300 - textwidth(s2)) / 2, 50, s2);
    }
    if (a == 2) {
        TCHAR  s1[] = _T("三等奖");
        TCHAR s2[] = _T("观影卷一张");

        settextstyle(40, 0, _T("黑体"), 0, 0, 900, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

        outtextxy((300 - textwidth(s1)) / 2, 10, s1);

        outtextxy((300 - textwidth(s2)) / 2, 50, s2);
    }
    if (a == 3) {
        TCHAR  s1[] = _T("谢谢惠顾");
        TCHAR s2[] = _T("每天开心愉快");

        settextstyle(40, 0, _T("黑体"), 0, 0, 900, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

        outtextxy((300 - textwidth(s1)) / 2, 10, s1);

        outtextxy((300 - textwidth(s2)) / 2, 50, s2);
    }
    // 绘制刮卡的掩码图

    SetWorkingImage(&imgMask);

    setbkcolor(BLACK);

    cleardevice();

    setlinestyle(PS_SOLID, 10);	// 设置刮卡操作的粗细

    SetWorkingImage();

}

// 实现刮卡操作

void Scrape(int x1, int y1, int x2, int y2)

{

    SetWorkingImage(&imgMask);

    line(x1, y1, x2, y2);

}

// 显示刮卡效果

void Show()

{

    IMAGE tmp = imgContent;

    SetWorkingImage(&tmp);

    putimage(0, 0, &imgMask, SRCAND);	// 将背景图中未刮开的区域置为黑色

    SetWorkingImage();

    putimage(offsetx, offsety, &imgMask, 0x00220326);	// 将覆盖层中已刮开的区域置为黑色

    putimage(offsetx, offsety, &tmp, SRCPAINT);	// 将背景图合并到覆盖层中

}



// 主函数

int main()

{
    int x = 0;
    cout << "请输入彩票个数：";
    cin >> x;
    
    for (int i = 1; i <= x; i++) {
        initgraph(640, 480);// 初始化图形窗口

        DrawCard();	// 绘制刮刮乐卡片

        InitContent();	// 初始化刮奖区内容

        // 获取鼠标消息，实现刮卡操作

        ExMessage msg;

        int x, y, oldx, oldy;

        bool scrape = false;

        while (true)

        {

            msg = getmessage(EM_MOUSE);

            switch (msg.message)

            {

            case WM_LBUTTONDOWN:

                scrape = true;

                x = oldx = msg.x - offsetx;

                y = oldy = msg.y - offsety;

                Scrape(oldx, oldy, x, y);

                break;

            case WM_LBUTTONUP:

                scrape = false;

                break;

            case WM_MOUSEMOVE:

                if (scrape)

                {

                    oldx = x;

                    oldy = y;

                    x = msg.x - offsetx;

                    y = msg.y - offsety;

                    Scrape(oldx, oldy, x, y);

                }

                break;

            }

            // 显示当前结果

            Show();

        }
    }
   
    return 0;

} //作者：C语言_编程俱乐部 https ://www.bilibili.com/read/cv16494297/ 出处：bilibili