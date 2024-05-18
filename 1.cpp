////////////////////////////////////////////

// �������ƣ��ι��֣�����ͼ�ķ�����

// ���뻷����Visual C++ 6.0 ~ 2019��EasyX_20220116

#include <graphics.h>
#include<ctime>
#include<cstdlib>
#include <iostream>
using namespace std;
const int offsetx = 170;	// �ν�����ƫ�� x ����

const int offsety = 260;	// �ν�����ƫ�� y ����

IMAGE imgContent(300, 100);	// �ο��������

IMAGE imgMask(300, 100);	// �ѹβ��ֵ������

// ���ƹιο�

void DrawCard()

{

    // ��ɫ����

    setbkcolor(0xf0f0f0);

    cleardevice();

    // ���ùιο���䵥Ԫ

    IMAGE unit(32, 32);

    SetWorkingImage(&unit);	// ���û�ͼ�豸Ϊ unit ����

    setbkcolor(0x1a3bf0);	// ���ñ���ɫ

    cleardevice();

    settextstyle(20, 0, _T("Webdings"), 0, 0, 400, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);	// ����ͼ������

    settextcolor(0x152fe5);

    outtextxy(0, 16, 0x59);	// ���������

    outtextxy(16, 0, 0x59);

    settextcolor(0x284ff5);

    outtextxy(0, 0, 0x73);	// ��������ʺ�

    outtextxy(16, 16, 0x73);

    SetWorkingImage();

    // �� IMAGE ��������������

    setfillstyle(BS_DIBPATTERN, NULL, &unit);	// �������ģʽ

    solidrectangle(150, 30, 490, 450);	// ��������

    TCHAR s[] = _T("�ι���");

    settextstyle(80, 0, _T("����"), 0, 0, 400, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

    setbkmode(TRANSPARENT);

    settextcolor(0x034089);

    outtextxy(offsetx + (300 - textwidth(s)) / 2 + 5, 105, s);

    settextcolor(0x10c2fe);

    outtextxy(offsetx + (300 - textwidth(s)) / 2, 100, s);

    // ���ø��ǲ���䵥Ԫ

    IMAGE unit2(80, 50);

    SetWorkingImage(&unit2);	// ���û�ͼ�豸Ϊ unit ����

    setbkcolor(LIGHTGRAY);

    cleardevice();

    settextstyle(20, 0, _T("����"), 150, 150, 400, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

    settextcolor(0x606060);

    outtextxy(10, 20, _T("�ν���"));

    SetWorkingImage();

    // �� IMAGE ��������������

    setfillstyle(BS_DIBPATTERN, NULL, &unit2);	// �������ģʽ

    solidrectangle(offsetx, offsety, offsetx + 300, offsety + 100);	// ��������

}

// ��ʼ���ν�������

void InitContent()

{
    srand(time(0));

    int a = rand() % 4;
    // ���ƹν�������

    SetWorkingImage(&imgContent);

    setbkcolor(0x05d5ff);

    cleardevice();

    settextcolor(0x0024b8);


    
    if (a == 0) {
        TCHAR  s1[] = _T("���Ƚ�");
        TCHAR s2[] = _T("һ��ˮ��");

        settextstyle(40, 0, _T("����"), 0, 0, 900, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

        outtextxy((300 - textwidth(s1)) / 2, 10, s1);

        outtextxy((300 - textwidth(s2)) / 2, 50, s2);
    }
    if (a == 1) {
        TCHAR  s1[] = _T("һ�Ƚ�");
        TCHAR s2[] = _T("�ɻ�Ʊһ��");

        settextstyle(40, 0, _T("����"), 0, 0, 900, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

        outtextxy((300 - textwidth(s1)) / 2, 10, s1);

        outtextxy((300 - textwidth(s2)) / 2, 50, s2);
    }
    if (a == 2) {
        TCHAR  s1[] = _T("���Ƚ�");
        TCHAR s2[] = _T("��Ӱ��һ��");

        settextstyle(40, 0, _T("����"), 0, 0, 900, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

        outtextxy((300 - textwidth(s1)) / 2, 10, s1);

        outtextxy((300 - textwidth(s2)) / 2, 50, s2);
    }
    if (a == 3) {
        TCHAR  s1[] = _T("лл�ݹ�");
        TCHAR s2[] = _T("ÿ�쿪�����");

        settextstyle(40, 0, _T("����"), 0, 0, 900, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);

        outtextxy((300 - textwidth(s1)) / 2, 10, s1);

        outtextxy((300 - textwidth(s2)) / 2, 50, s2);
    }
    // ���ƹο�������ͼ

    SetWorkingImage(&imgMask);

    setbkcolor(BLACK);

    cleardevice();

    setlinestyle(PS_SOLID, 10);	// ���ùο������Ĵ�ϸ

    SetWorkingImage();

}

// ʵ�ֹο�����

void Scrape(int x1, int y1, int x2, int y2)

{

    SetWorkingImage(&imgMask);

    line(x1, y1, x2, y2);

}

// ��ʾ�ο�Ч��

void Show()

{

    IMAGE tmp = imgContent;

    SetWorkingImage(&tmp);

    putimage(0, 0, &imgMask, SRCAND);	// ������ͼ��δ�ο���������Ϊ��ɫ

    SetWorkingImage();

    putimage(offsetx, offsety, &imgMask, 0x00220326);	// �����ǲ����ѹο���������Ϊ��ɫ

    putimage(offsetx, offsety, &tmp, SRCPAINT);	// ������ͼ�ϲ������ǲ���

}



// ������

int main()

{
    int x = 0;
    cout << "�������Ʊ������";
    cin >> x;
    
    for (int i = 1; i <= x; i++) {
        initgraph(640, 480);// ��ʼ��ͼ�δ���

        DrawCard();	// ���ƹι��ֿ�Ƭ

        InitContent();	// ��ʼ���ν�������

        // ��ȡ�����Ϣ��ʵ�ֹο�����

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

            // ��ʾ��ǰ���

            Show();

        }
    }
   
    return 0;

} //���ߣ�C����_��̾��ֲ� https ://www.bilibili.com/read/cv16494297/ ������bilibili