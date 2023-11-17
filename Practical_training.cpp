#include "Practical_training.h"
#include"furniture.h"
#include<commctrl.h>
#include"Aircondition.h"
#include"fileCreater.h"
#include"math.h"
#include"wall.h"
#include<unordered_map>

#define MAX_LOADSTRING 100
#define AIRCONDITION 1
#define AIRFRESH 2
#define HUMIDIFIER 3
#define DEHUMIDIFIER 4
#define FLOORHEAT 5

// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void CALLBACK MyTimerProc(HWND time_hwnd, UINT message, UINT iTimerID, DWORD dwTime);//Timer信息回调函数
void Create_List(HWND, int, LPTSTR, int);//用于创建列表中列的函数
void Create_List2(HWND);//为列表2特供的函数
void Create_List2_info(HWND, Furniture*);//用于向list2插入数据的函数
void Create_List3(HWND);//为列表3特制的函数
void setList3(LPCTSTR map_type, LPCTSTR map_model, double map_temper, int map_humidity, int map_noise, int map_bacteria);//用于把家具数据放到list3上面
void Create_List4(HWND);//为列表4特制的函数
void Create_List5(HWND);//为列表5特制的函数
void Create_Item(HWND, int, int, LPTSTR);//用于创建列表中行的函数；
void Insert_Item(HWND, int, LPTSTR);//用于创建列表中的第一行
void switch_fun(int, int);//用于读取列表5的点击信息

void button3_fun();//按钮3的函数
void button4_fun();//按钮4的函数
void button5_fun();//按钮5的函数
void list1_fun(LPARAM);//列表1收到点击后的处理函数
bool fun_judge();//判断墙是否封闭的函数

void outsideKeep();//控制外界温度是环境温度
void Furniture_timer_fun();//时间回调函数里面的家具运行函数
void WeatherChange();//时间回调函数里面的天气变化的函数
void cycle_fun();//时间回调函数里面的室内温度、湿度循环函数
#define Spring 1000
#define Summer 2000
#define Autumn 3000
#define Winter 4000
double temperature_outdoor = 26;//室外温度
int Sun_x = 30;//太阳的横纵坐标
int Sun_y = 30;
int clock_day = 0;//当前时间，如12表示12点
int Weather = Spring;
bool Sun_if = 0;


//定义全局变量
UINT timer1_ID = 100;//定义定时器1 的ID
UINT timer2_ID = 101;
UINT timer3_ID = 102;
UINT timer4_ID = 103;


TCHAR* button1_push1_name = (LPTSTR)_T("运行系统");//定义按钮1的名字
UINT button1_push1_ID = 10;//按钮1的ID
TCHAR* button2_push2_name = (LPTSTR)_T("暂停系统");//按钮2
UINT button2_push2_ID = 11;
TCHAR* button3_push3_name = (LPTSTR)_T("");//按钮3
UINT button3_push3_ID = 12;
TCHAR* button4_push4_name = (LPTSTR)_T("");//按钮4
UINT button4_push4_ID = 13;
TCHAR* button5_push5_name = (LPTSTR)_T("");//按钮5
UINT button5_push5_ID = 14;
TCHAR* button6_push6_name = (LPTSTR)_T("开始布置");//按钮6
UINT button6_push6_ID = 15;
TCHAR* button7_push7_name = (LPTSTR)_T("停止布置");//按钮7
UINT button7_push7_ID = 16;
TCHAR* button8_push8_name = (LPTSTR)_T("春");//按钮8
UINT button8_push8_ID = 17;
TCHAR* button9_push9_name = (LPTSTR)_T("夏");//按钮9
UINT button9_push9_ID = 18;
TCHAR* button10_push10_name = (LPTSTR)_T("秋");//按钮10
UINT button10_push10_ID = 19;
TCHAR* button11_push11_name = (LPTSTR)_T("冬");//按钮11
UINT button11_push11_ID = 20;
TCHAR* button12_push12_name = (LPTSTR)_T("X");//按钮12
UINT button12_push12_ID = 21;

TCHAR* list1_name = (LPTSTR)_T("");//定义列表1的名字
UINT list1_ID = 31;
TCHAR* list2_name = (LPTSTR)_T("");//列表2
UINT list2_ID = 32;
TCHAR* list3_name = (LPTSTR)_T("");//列表3
UINT list3_ID = 33;
TCHAR* list4_name = (LPTSTR)_T("");//列表4
UINT list4_ID = 34;
TCHAR* list5_name = (LPTSTR)_T("");//列表5
UINT list5_ID = 35;
TCHAR* list6_name = (LPTSTR)_T("");//列表6
UINT list6_ID = 36;

TCHAR* edit1_name = (LPTSTR)_T("");//定义编辑框1的名字
UINT edit1_ID = 41;//编辑框1的ID
TCHAR edit1_word[256] = { 0 };//编辑框1捕获的内容
TCHAR* edit2_name = (LPTSTR)_T("");//定义编辑框2的名字
UINT edit2_ID = 42;//编辑框2的ID
TCHAR edit2_word[256] = { 0 };//编辑框2捕获的内容
TCHAR* edit3_name = (LPTSTR)_T("");//定义编辑框3的名字
UINT edit3_ID = 43;//编辑框3的ID
TCHAR edit3_word[256] = { 0 }; //编辑框3捕获的内容


HWND list1;//定义列表1的句柄
HWND list2;//列表2
HWND list3;//列表3
HWND list4;//列表4
HWND list5;//列表5
HWND list6;//列表6

HWND edit1;//编辑框1的句柄
HWND edit2;
HWND edit3;

////////////////////////////////////
//////////开始创建地图//////////////
////////////////////////////////////
//其中brick是我已经在头文件framwork.h中声明的类。
std::vector<std::vector<brick>> map_info;//创建地图（一个二维数组),已在头文件里定义
int map_l = 25;//设定地图的长(有多少列）
int map_h = 20;//设定地图的宽
brick map_value{ 27,0 ,30,20,60};//设定地图每块的默认值
//然后在主函数里面完成地图的创建

//下面，我又创建了一个数组，这个数组用于的存储地图格子上面的家具
std::vector<std::vector<Furniture*>>arr_furniture;
Furniture f_temp;//地图里每个格子指向的默认值
Furniture* furniture_value = &f_temp;

//然后，我又加了一个家具运行的有缓存作用的哈希表，只用于存储家具的位置，这样可以大大减少数组遍历时间
std::unordered_map<int, int> map_hash;
//我还创建了一个只含有墙信息的数组，为了判断是否封闭
std::vector<std::vector<bool>> brick_map;
//我还创建了一个数组判断室内区域
std::vector<std::vector<bool>> indoor;

//对于指针指向的类对象被释放问题，我专门创建了一些二维数组来规避
std::vector<std::vector<Air_condition>>arr_Airconditon;
Air_condition aircondition_value;
std::vector<std::vector<Air_fresh>>arr_Airfresh;
Air_fresh airfresh_value;
std::vector<std::vector<Dehumidifier>>arr_Dehumidifier;
Dehumidifier dehumidifier_value;
std::vector<std::vector<FloorHeat>>arr_FloorHeat;
FloorHeat floorheat_value;
std::vector<std::vector<Humidifier>>arr_Humidifier;
Humidifier humidifier_value;
std::vector<std::vector<Wall>>arr_Wall;
Wall wall_value;

//创建存储第五列点击信息的全局变量
int click_list5_item = NULL;//点击的行
int click_list5_isubitem = NULL;//点击的列
Furniture* list5_click_temp = NULL;
//创建存储第一列的点击信息的全局变量
int click_list1_item = 0;//第一列点击的行
int click_list1_isubitem = 0;//第一列点击的列
//创建是否进行点击放置的全局变量
bool put_if = 0;
//创建是否进行删除的全局变量
bool delete_if = 0;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
    {
        //创建按钮
        HWND button1_push1 = CreateWindow(WC_BUTTON, button1_push1_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 20, 20, 80, 28, hWnd, (HMENU)button1_push1_ID, NULL, NULL);//按钮 开始运行
        HWND button2_push2 = CreateWindow(WC_BUTTON, button2_push2_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 20, 50, 80, 28, hWnd, (HMENU)button2_push2_ID, NULL, NULL);//按钮 停止运行
        HWND button3_push3 = CreateWindow(WC_BUTTON, button3_push3_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 1120, 355, 20, 20, hWnd, (HMENU)button3_push3_ID, NULL, NULL);//按钮3 对应edit1
        HWND button4_push4 = CreateWindow(WC_BUTTON, button4_push4_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 1120, 380, 20, 20, hWnd, (HMENU)button4_push4_ID, NULL, NULL);//按钮4 对应edit2
        HWND button5_push5 = CreateWindow(WC_BUTTON, button5_push5_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 1120, 405, 20, 20, hWnd, (HMENU)button5_push5_ID, NULL, NULL);//按钮5 对应edit3
        HWND button6_push6 = CreateWindow(WC_BUTTON, button6_push6_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 20, 90, 80, 80, hWnd, (HMENU)button6_push6_ID, NULL, NULL);//按钮 停止布置       
        HWND button7_push7 = CreateWindow(WC_BUTTON, button7_push7_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 20, 175, 80, 80, hWnd, (HMENU)button7_push7_ID, NULL, NULL);//按钮 开始布置      
        HWND button8_push8 = CreateWindow(WC_BUTTON, button8_push8_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 20, 265, 40, 40, hWnd, (HMENU)button8_push8_ID, NULL, NULL);//按钮 春  
        HWND button9_push9 = CreateWindow(WC_BUTTON, button9_push9_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 60, 265, 40, 40, hWnd, (HMENU)button9_push9_ID, NULL, NULL);//按钮 夏    
        HWND button10_push10 = CreateWindow(WC_BUTTON, button10_push10_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 20, 305, 40, 40, hWnd, (HMENU)button10_push10_ID, NULL, NULL);//按钮 秋   
        HWND button11_push11 = CreateWindow(WC_BUTTON, button11_push11_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 60, 305, 40, 40, hWnd, (HMENU)button11_push11_ID, NULL, NULL);//按钮 冬    
        HWND button12_push12 = CreateWindow(WC_BUTTON, button12_push12_name, WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_BORDER, 1260, 262, 30, 30, hWnd, (HMENU)button12_push12_ID, NULL, NULL);//按钮 X    


        //创建列表
        list1 = CreateWindow(WC_LISTVIEW, list1_name, WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_SHOWSELALWAYS, 110, 80, 850, 385, hWnd, (HMENU)list1_ID, NULL, NULL);
        ListView_SetExtendedListViewStyle(list1, LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES | LVS_EX_AUTOCHECKSELECT | LVS_EX_AUTOSIZECOLUMNS);//补充list1的信息
        list2 = CreateWindow(WC_LISTVIEW, list2_name, WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_SHOWSELALWAYS, 110, 32, 850, 42, hWnd, (HMENU)list2_ID, NULL, NULL);
        ListView_SetExtendedListViewStyle(list2, LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES | LVS_EX_AUTOCHECKSELECT | LVS_EX_AUTOSIZECOLUMNS);//补充list2的信息
        list3 = CreateWindow(WC_LISTVIEW, list3_name, WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_SHOWSELALWAYS, 970, 32, 175, 150, hWnd, (HMENU)list3_ID, NULL, NULL);
        ListView_SetExtendedListViewStyle(list3, LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES | LVS_EX_AUTOCHECKSELECT | LVS_EX_AUTOSIZECOLUMNS);//补充list3的信息
        list4 = CreateWindow(WC_LISTVIEW, list4_name, WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_SHOWSELALWAYS, 990, 190, 140, 153, hWnd, (HMENU)list4_ID, NULL, NULL);
        ListView_SetExtendedListViewStyle(list4, LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES | LVS_EX_AUTOCHECKSELECT | LVS_EX_AUTOSIZECOLUMNS);//补充list4的信息
        list5 = CreateWindow(WC_LISTVIEW, list5_name, WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_SHOWSELALWAYS, 1160, 62, 230, 170, hWnd, (HMENU)list5_ID, NULL, NULL);
        ListView_SetExtendedListViewStyle(list5, LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES | LVS_EX_AUTOCHECKSELECT | LVS_EX_AUTOSIZECOLUMNS);//补充list5的信息
        list6 = CreateWindow(WC_LISTVIEW, list6_name, WS_VISIBLE | WS_CHILD | WS_BORDER | LVS_REPORT | LVS_SHOWSELALWAYS, 5, 420, 100, 45, hWnd, (HMENU)list6_ID, NULL, NULL);
        ListView_SetExtendedListViewStyle(list6, LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_GRIDLINES | LVS_EX_AUTOCHECKSELECT | LVS_EX_AUTOSIZECOLUMNS);//补充list6的信息

        //创建编辑框
        edit1 = CreateWindow(WC_EDIT, edit1_name, WS_VISIBLE | WS_CHILD | WS_BORDER, 1035, 355, 80, 20, hWnd, (HMENU)edit1_ID, NULL, NULL);//创建编辑框1
        edit2 = CreateWindow(WC_EDIT, edit2_name, WS_VISIBLE | WS_CHILD | WS_BORDER, 1035, 380, 80, 20, hWnd, (HMENU)edit2_ID, NULL, NULL);//创建编辑框2
        edit3 = CreateWindow(WC_EDIT, edit3_name, WS_VISIBLE | WS_CHILD | WS_BORDER, 1035, 405, 80, 20, hWnd, (HMENU)edit3_ID, NULL, NULL);//创建编辑框3

        //填充各个列表的信息
        for (int i = 0; i < map_l; i++)//对列表1插入列,这个是地图
            Create_List(list1, i, (LPTSTR)_T("1"), 34);
        for (int i = 0; i < map_h; i++)//对列表1插入行
            Insert_Item(list1, i, (LPTSTR)_T(""));


        Create_List2(list2);//对列表2插入列
        Insert_Item(list2, 0, (LPTSTR)_T(""));
        Create_List3(list3);//对列表3插入行和列
        Create_List4(list4);//对列表4插入行和列
        Create_List5(list5);//对列表5插入行和列
        Create_List(list6, 0, (LPTSTR)_T("时间"), 40);
        Create_List(list6, 1, (LPTSTR)_T("室外温度"), 60);
        Insert_Item(list6, 0, (LPTSTR)_T(""));


        break;
    }
    case WM_COMMAND:
    {
        UINT button_code = LOWORD(wParam);
        UINT button_action = HIWORD(wParam);
        if (button_action == BN_CLICKED)//读取点击动作
        {
            if (button_code == button1_push1_ID)//识别按钮1，调用时间回调函数，所有家具开始运行
            {
                if (fun_judge())
                {
                    SetTimer(hWnd, timer1_ID, 500, MyTimerProc);//家具运行
                    SetTimer(hWnd, timer2_ID, 2000, MyTimerProc);//天气变化
                    SetTimer(hWnd, timer3_ID, 2000, MyTimerProc);//室内热传导
                    SetTimer(hWnd, timer4_ID, 500, MyTimerProc);//外界温度统一
                    PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
                }

            }
            else if (button_code == button2_push2_ID)//停止调用时间回调函数
            {
                KillTimer(hWnd, timer1_ID);
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if (button_code == button6_push6_ID)//设置列表1为放置模式
            {
                put_if = 1;
                delete_if = 0;
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if (button_code == button7_push7_ID)//设置列表一为查看模式
            {
                put_if = 0;
                list5_click_temp = NULL;
                delete_if = 0;
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if (button_code == button12_push12_ID)//设置列表1为删除模式
            {
                put_if = 0;
                list5_click_temp = NULL;
                delete_if = 1;
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if (button_code == button3_push3_ID)//识别按钮3，把编辑框1的值设定为被点击家具的目标温度
            {
                button3_fun();
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if (button_code == button4_push4_ID)//识别按钮4，把编辑框2的值设定为被点击家具的目标湿度
            {
                button4_fun();
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if (button_code == button5_push5_ID)//识别按钮5，把编辑框3的值设定为被点击家具的档位
            {
                button5_fun();
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if (button_code == button8_push8_ID)
            {
                Weather = Spring;
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if (button_code == button9_push9_ID)
            {
                Weather = Summer;
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if (button_code == button10_push10_ID)
            {
                Weather = Autumn;
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
            else if (button_code == button11_push11_ID)
            {
                Weather = Winter;
                PlaySound(_T("E:\\click.wav"), NULL, SND_FILENAME | SND_ASYNC);
            }
        }
    }
    break;
    case WM_NOTIFY://识别列表上的点击消息
    {
        NMHDR* click_list_info = (NMHDR*)lParam;
        if (click_list_info->idFrom == list5_ID)//识别列表5的操作
        {
            if (click_list_info->code == NM_CLICK)
            {
                LPNMITEMACTIVATE lpnmitem = (LPNMITEMACTIVATE)lParam;
                click_list5_item = lpnmitem->iItem;
                click_list5_isubitem = lpnmitem->iSubItem;
                switch_fun(click_list5_item, click_list5_isubitem);//进行点击读取，把点击的信息存到缓存变量list5_click_temp中
            }
        }

        if (click_list_info->idFrom == list1_ID)//识别列表1的操作
        {
            if (click_list_info->code == NM_CLICK)//如果是左键点击的话
            {
                list1_fun(lParam);
            }

        }
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        //MoveToEx(hdc, 0, 430,NULL);//画一条线
        //LineTo(hdc, 500, 430);
        LPCTSTR str_temp_1 = _T("设定温度");
        LPCTSTR str_temp_2 = _T("设定湿度");
        LPCTSTR str_temp_3 = _T("设定档位");
        LPCTSTR str_temp_4 = _T("选择要放置的家具");
        LPCTSTR str_temp_5 = _T("删除家具");
        TextOut(hdc, 970, 355, str_temp_1, 4);
        TextOut(hdc, 970, 380, str_temp_2, 4);
        TextOut(hdc, 970, 405, str_temp_3, 4);
        TextOut(hdc, 1210, 35, str_temp_4, 8);
        TextOut(hdc, 1245, 240, str_temp_5, 4);
        TextOut(hdc, 50, 380, _T("↑"), 1);
        TextOut(hdc, 50, 395, _T("↑"), 1);
        TextOut(hdc, 50, 365, _T("↑"), 1);
        TextOut(hdc, 70, 380, _T("N"), 1);

        EndPaint(hWnd, &ps);
    }
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

void CALLBACK MyTimerProc(HWND time_hwnd, UINT message, UINT iTimerID, DWORD dwTime)//按钮1对应的时间函数，一按下按钮1就调用这个函数
{
    if (iTimerID == timer1_ID)//家具运行函数
    {
        Furniture_timer_fun();//具体定义在下面
    }
    if (iTimerID == timer2_ID)
    {
        WeatherChange();
    }
    if (iTimerID == timer3_ID)
    {
        cycle_fun();
    }
    //把外界设为环境温度
    if (iTimerID == timer4_ID)
    {
        outsideKeep();//控制外界温度是环境温度
    }
}

/// <summary>///////
/// 主函数来啦！////
/// </summary>//////


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    srand(static_cast<unsigned int>(time(0)));
    //先把地图创建好
    for (int i = 0; i < map_h; i++)//map_info这个地图
    {     
        std::vector<brick>map_list(map_l, map_value);//设定地图的行（用于插入整个地图）
        map_info.push_back(map_list);
    }
    for (int i = 0; i < map_h; i++)//brick_map这个地图
    {
        std::vector<bool>map_list(map_l, 0);//设定地图的行（用于插入整个地图）
        brick_map.push_back(map_list);
    }
    for (int i = 0; i < map_h; i++)//arr_furniture这个地图
    {
        std::vector<Furniture*>map_list2(map_l, furniture_value);//设定地图的行
        arr_furniture.push_back(map_list2);
    }

    //搞好那几个存储不同类型家具的数组
    for (int i = 0; i < 2*map_h; i++)//以防数组满了，暂时没找到其他解决方法，所以就暴力地把数组的高变成了二倍的地图的高
    {
        std::vector<Air_condition>map_list3(map_l,aircondition_value);//设定地图的行
        arr_Airconditon.push_back(map_list3);
    }
    for (int i = 0; i < 2 * map_h; i++)
    {
        std::vector<Air_fresh>map_list4(map_l, airfresh_value);//设定地图的行
        arr_Airfresh.push_back(map_list4);
    }
    for (int i = 0; i < 2 * map_h; i++)
    {
        std::vector<Dehumidifier>map_list5(map_l, dehumidifier_value);//设定地图的行
        arr_Dehumidifier.push_back(map_list5);
    }
    for (int i = 0; i < 2 * map_h; i++)
    {
        std::vector<FloorHeat>map_list6(map_l, floorheat_value);//设定地图的行
        arr_FloorHeat.push_back(map_list6);
    }
    for (int i = 0; i < 2 * map_h; i++)
    {
        std::vector<Humidifier>map_list7(map_l, humidifier_value);//设定地图的行
        arr_Humidifier.push_back(map_list7);
    }
    for (int i = 0; i < 2 * map_h; i++)
    {
        std::vector<Wall>map_list9(map_l, wall_value);//设定地图的行
        arr_Wall.push_back(map_list9);
    }
    for (int i = 0; i < map_h; i++)
    {
        std::vector<bool>map_list10(map_l, 0);
        indoor.push_back(map_list10);
    }
    //创建文件
    FileCreater filecreater1;
    filecreater1.Create_file();
    //创建结束

    //播放音乐
    mciSendString(_T("play  E:\\music.wav"), NULL, 0, NULL);

    //该段用来创建窗口
    {
        WNDCLASSEX win_reg = { 0 };//注册的窗口名
        static LPCTSTR window_name = _T("Simulated furniture environment");//窗口的标题
        win_reg.lpfnWndProc = WndProc;
        win_reg.cbSize = sizeof(WNDCLASSEX);
        win_reg.lpszClassName = window_name;
        //开始注册
        BOOL register_YesOrNo = RegisterClassEx(&win_reg);
        if (!register_YesOrNo)
            MessageBox(NULL, _T("注册失败"), _T("Tip"), MB_OK);

        //开始创建窗口
        HWND h_Window = CreateWindow(window_name, _T("Indoor environment simulation program"), WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_BORDER, 60, 110, 1430, 580, NULL, NULL, hInstance, NULL);
        if (h_Window == NULL)
            MessageBox(NULL, _T("创建窗口失败"), _T("Tip"), MB_OK);
        //指定窗口显示状态
        if (h_Window != 0)
            ShowWindow(h_Window, nCmdShow);

        //插入背景图片
        HDC hdc1 = GetDC(h_Window);
        HDC mdc1 = CreateCompatibleDC(hdc1);
        HBITMAP hBG = (HBITMAP)LoadImage(NULL, _T("E:\\006.bmp"), IMAGE_BITMAP, 2800, 1576, LR_LOADFROMFILE);
        SelectObject(mdc1, hBG);
        BitBlt(hdc1, 0, 0, 960, 720, mdc1, 0, 0, SRCCOPY);

        //发送消息
        MSG message = { 0 };
        while (GetMessage(&message, NULL, 0, 0))
        {
            TranslateMessage(&message);
            DispatchMessageW(&message);
        }

    }//创建窗口成功

    return 0;
}
















/////////////////
/////////////////下面为我封装的函数
/////////////////

void Create_List(HWND h, int n,LPTSTR str, int size1)
{
    LVCOLUMN list_temp = { 0 };
    list_temp.mask |= LVCF_WIDTH | LVCF_TEXT | LVCF_FMT;
    list_temp.cx = size1;
    list_temp.fmt = LVCFMT_CENTER;
    list_temp.pszText = str;
    
    SendMessage(h, LVM_INSERTCOLUMN, n, (LPARAM)&list_temp);
}

void Create_List2(HWND list2)
{
    Create_List(list2, 0, (LPTSTR)_T("类别"), 60);//对列表2插入列
    Create_List(list2, 1, (LPTSTR)_T("产品型号"), 170);
    Create_List(list2, 2, (LPTSTR)_T("功率"), 40);
    Create_List(list2, 3, (LPTSTR)_T("长"), 35);
    Create_List(list2, 4, (LPTSTR)_T("宽"), 35);
    Create_List(list2, 5, (LPTSTR)_T("高"), 35);
    Create_List(list2, 6, (LPTSTR)_T("材质"), 60);
    Create_List(list2, 7, (LPTSTR)_T("噪音"), 40);
    Create_List(list2, 8, (LPTSTR)_T("特色"), 155);
    Create_List(list2, 9, (LPTSTR)_T("档位"), 40);
    Create_List(list2, 10, (LPTSTR)_T("温度"), 60);
    Create_List(list2, 11, (LPTSTR)_T("增/除湿能力"), 80);
    Create_List(list2, 12, (LPTSTR)_T("风力"), 40);
}

void Create_List2_info(HWND list2,Furniture* qq)
{
    const TCHAR* a = qq->getType();
    const TCHAR* b = qq->getModel();
    P c = qq->getP();
    L d = qq->getLength();
    L e = qq->getWidth();
    L f = qq->getH();
    const TCHAR* g = qq->getMaterial();
    Noise h = qq->getNoise();
    const TCHAR* i = qq->getFeature();
    int j = qq->getGear();
    double k = qq->getTemperature();
    int l = qq->getHumidity_power();
    int m = qq->getWind_power();
    int n = qq->getHumidity_request();
    int o = qq->getWind_power_now();
    P p = qq->getP_now();
    int q = qq->getP_E();
    int r = qq->getBacteria_power_now();

    TCHAR* temp = new TCHAR[100];
    Create_Item(list2, 0, 0, (LPTSTR)a);
    Create_Item(list2, 0, 1, (LPTSTR)b);
    swprintf(temp, sizeof(c.getPower()), _T("%d"), c.getPower());
    Create_Item(list2, 0, 2, (LPTSTR)temp);
    swprintf(temp, sizeof(int), _T("%d"), d.getLength());
    Create_Item(list2, 0, 3, (LPTSTR)temp);
    swprintf(temp, sizeof(int), _T("%d"), e.getLength());
    Create_Item(list2, 0, 4, (LPTSTR)temp);
    swprintf(temp, sizeof(int), _T("%d"), f.getLength());
    Create_Item(list2, 0, 5, (LPTSTR)temp);
    Create_Item(list2, 0, 6, (LPTSTR)g);
    swprintf(temp, sizeof(int), _T("%d"), h.getDb());
    Create_Item(list2, 0, 7, (LPTSTR)temp);
    Create_Item(list2, 0, 8, (LPTSTR)i);
    swprintf(temp, sizeof(int), _T("%d"), j);
    if (j == 10)
    {
        Create_Item(list4, 0, 1, (LPTSTR)_T("自动"));

    }
    else
    Create_Item(list4, 0, 1, (LPTSTR)temp);
    Create_Item(list2, 0, 9, (LPTSTR)temp);
    swprintf(temp, sizeof(double), _T("%.2f\n"), k);
    Create_Item(list4, 1, 1, (LPTSTR)temp);
    Create_Item(list2, 0, 10, (LPTSTR)temp);
    swprintf(temp, sizeof(int), _T("%d"), l);
    Create_Item(list2, 0, 11, (LPTSTR)temp);
    swprintf(temp, sizeof(int), _T("%d"), m);
    Create_Item(list2, 0, 12, (LPTSTR)temp);
    swprintf(temp, sizeof(int), _T("%d"), n);
    Create_Item(list4, 2, 1, (LPTSTR)temp);
    swprintf(temp, sizeof(int), _T("%d"), o);
    Create_Item(list4, 3, 1, (LPTSTR)temp);
    swprintf(temp, sizeof(int), _T("%d"), p.getPower());
    Create_Item(list4, 4, 1, (LPTSTR)temp);
    swprintf(temp, sizeof(int), _T("%d"), q);
    Create_Item(list4, 5, 1, (LPTSTR)temp);
    swprintf(temp, sizeof(int), _T("%d"), r);
    Create_Item(list4, 6, 1, (LPTSTR)temp);

    delete[] temp;

}

void Create_List3(HWND list3)
{
    Create_List(list3, 0, (LPTSTR)_T("室内参数"), 85);//对列表3插入列
    Create_List(list3, 1, (LPTSTR)_T("数值"), 90);
    Insert_Item(list3, 0, (LPTSTR)_T("此处的家具"));//对列表3插入行
    Insert_Item(list3, 1, (LPTSTR)_T("家具型号"));
    Insert_Item(list3, 2, (LPTSTR)_T("板块温度"));
    Insert_Item(list3, 3, (LPTSTR)_T("板块湿度"));
    Insert_Item(list3, 4, (LPTSTR)_T("板块噪音"));
    Insert_Item(list3, 5, (LPTSTR)_T("细菌情况"));
    Insert_Item(list3, 6, (LPTSTR)_T("当前季节"));
}

void Create_List4(HWND list4)
{
    Create_List(list4, 0, (LPTSTR)_T("家具当前情况"), 85);//对列表4插入列
    Create_List(list4, 1, (LPTSTR)_T("数值"), 55);
    Insert_Item(list4, 0, (LPTSTR)_T("档位"));
    Insert_Item(list4, 1, (LPTSTR)_T("目标温度"));
    Insert_Item(list4, 2, (LPTSTR)_T("目标湿度"));
    Insert_Item(list4, 3, (LPTSTR)_T("当前风力"));
    Insert_Item(list4, 4, (LPTSTR)_T("当前功率"));
    Insert_Item(list4, 5, (LPTSTR)_T("日耗电量"));
    Insert_Item(list4, 6, (LPTSTR)_T("除/增菌能力"));
}

void Create_List5(HWND list5)
{
    Create_List(list5, 0, (LPTSTR)_T("家具类型"), 70);//对列表3插入列
    Create_List(list5, 1, (LPTSTR)_T("一"), 40);
    Create_List(list5, 2, (LPTSTR)_T("二"), 40);
    Create_List(list5, 3, (LPTSTR)_T("三"), 40);
    Create_List(list5, 4, (LPTSTR)_T("四"), 40);

    Insert_Item(list5, 0, (LPTSTR)_T("空调"));//对列表3插入行
    Insert_Item(list5, 1, (LPTSTR)_T("新风系统"));
    Insert_Item(list5, 2, (LPTSTR)_T("加湿器"));
    Insert_Item(list5, 3, (LPTSTR)_T("除湿器"));
    Insert_Item(list5, 4, (LPTSTR)_T("地暖"));
    Insert_Item(list5, 5, (LPTSTR)_T("墙壁"));
    Insert_Item(list5, 6, (LPTSTR)_T("窗户"));
    Insert_Item(list5, 7, (LPTSTR)_T("门"));

    Create_Item(list5, 0, 1, (LPTSTR)_T("♫(1)"));
    Create_Item(list5, 0, 2, (LPTSTR)_T("♫(2)"));
    Create_Item(list5, 0, 3, (LPTSTR)_T("♫(3)"));
    Create_Item(list5, 0, 4, (LPTSTR)_T("♫(4)")); 
    Create_Item(list5, 1, 1, (LPTSTR)_T("▼(1)"));
    Create_Item(list5, 1, 2, (LPTSTR)_T("▼(2)"));
    Create_Item(list5, 1, 3, (LPTSTR)_T("▼(3)"));
    Create_Item(list5, 2, 1, (LPTSTR)_T("֎(1)"));
    Create_Item(list5, 2, 2, (LPTSTR)_T("֎(2)"));
    Create_Item(list5, 2, 3, (LPTSTR)_T("֎(3)"));
    Create_Item(list5, 3, 1, (LPTSTR)_T("◙(1)"));
    Create_Item(list5, 3, 2, (LPTSTR)_T("◙(2)"));
    Create_Item(list5, 3, 3, (LPTSTR)_T("◙(3)"));
    Create_Item(list5, 4, 1, (LPTSTR)_T("ⱷ"));
    Create_Item(list5, 5, 1, (LPTSTR)_T("▒"));
    Create_Item(list5, 5, 2, (LPTSTR)_T("▒"));
    Create_Item(list5, 6, 1, (LPTSTR)_T("♥"));
    Create_Item(list5, 7, 1, (LPTSTR)_T("℗"));

}

void Create_Item(HWND h,int x,int y,LPTSTR str)
{
    LV_ITEM item_temp = { 0 };
    item_temp.mask = LVIF_TEXT;
    item_temp.pszText = str;
    item_temp.iItem = x;
    item_temp.iSubItem = y;
    ListView_SetItem(h, &item_temp);

}

void Insert_Item(HWND h, int x, LPTSTR str)
{
    LV_ITEM list_temp = { 0 };
    list_temp.mask = LVIF_TEXT;
    list_temp.pszText = str;
    list_temp.iItem = x;
    list_temp.iSubItem = 0;
    ListView_InsertItem(h, &list_temp);
}


void Furniture_timer_fun()
{
    
    for (auto it = map_hash.begin(); it != map_hash.end(); it++)//所以有家具运行
    {
        arr_furniture[it->second / map_l][it->second % map_l]->F_run();//运行
        arr_furniture[it->second / map_l][it->second % map_l]->Noise_make();//制造噪音
    }
    //接下来进行数据的输出,输出结果在列表3(右上角的列表)
    const TCHAR* map_type = { 0 };//该区域家具的种类
    const TCHAR* map_model = { 0 };//该区域家具的型号
    int map_judge = map_info[click_list1_item][click_list1_isubitem].judge;//判断该地区是否有家具
    if (map_judge == 0)
    {
        map_type = _T("地板");
        map_model = _T("AAA");
    }
    else
    {
        map_type = arr_furniture[click_list1_item][click_list1_isubitem]->getType();
        map_model = arr_furniture[click_list1_item][click_list1_isubitem]->getModel();
    }
    double map_temper = map_info[click_list1_item][click_list1_isubitem].temperature;//当前地区温度
    int map_humidity = map_info[click_list1_item][click_list1_isubitem].humidity;//当前地区潮湿度
    int map_bacteria = map_info[click_list1_item][click_list1_isubitem].bacteria;//当前地区细菌情况
    int map_noise = map_info[click_list1_item][click_list1_isubitem].noise;//当前地区噪音大小
    setList3(map_type, map_model, map_temper, map_humidity, map_noise, map_bacteria);//把这些数据放到list3上面
    for (int i = 0; i < map_h; i++)
    {
        for (int j = 0; j < map_l; j++) 
        {
            map_info[i][j].noise = 20;
        }
    }
}

void WeatherChange()
{
    switch (Weather)
    {
    case Spring:
    {
        if ((clock_day >= 7)&&(clock_day<=18))
        {
            Sun_if = 1;
            Sun_x = 1000 - (clock_day-7) * 180;
            Sun_y = 3 * (Sun_x - map_l) * (Sun_x - map_l) / 2 + map_h - 1400000;
        }
        else
        {
            Sun_if = 0;
        }
        temperature_outdoor = 10 * sin(3.14 * clock_day/12 - 3.14 / 2) + 20;
        int a = 0;
    }
    break;
    case Summer:
    {
        if ((clock_day >= 6) && (clock_day <= 19))
        {
            Sun_if = 1;
            Sun_x = 800 - (clock_day - 6) * 120;
            Sun_y = 900000-3 * (Sun_x - map_l) * (Sun_x - map_l) / 2 + map_h ;
        }
        else
        {
            Sun_if = 0;
        }
        temperature_outdoor = 8 * sin(3.14 * clock_day /12- 3 * 3.14 / 5) + 25;

    }
    break;
    case Autumn:
    {
        if ((clock_day >= 7) && (clock_day <= 18))
        {
            Sun_if = 1;
            Sun_x = 1050 - (clock_day - 7) * 182;
            Sun_y = 3 * (Sun_x - map_l) * (Sun_x - map_l) / 2 + map_h - 1388888;
        }
        else
        {
            Sun_if = 0;
        }
        temperature_outdoor = 5 * sin(3.14 * clock_day/12 + 4 * 3.14 / 5) + 22;
    }
    break;
    case Winter:
    {
        if ((clock_day >= 8) && (clock_day <= 17))
        {
            Sun_if = 1;
            Sun_x = 800 - (clock_day - 8) * 177;
            Sun_y = 3 * (Sun_x - map_l) * (Sun_x - map_l) / 2 + map_h - 970000;
        }
        else
        {
            Sun_if = 0;
        }
        temperature_outdoor = 6 * sin(3.14 * clock_day / 12 + 3 * 3.14 / 4) + 3;
    }
    break;
    default: 
    {
        MessageBox(NULL, _T("现在是啥季节，我竟然不知道(T ^ T) "), _T("Tips:"), MB_OK);
    }
        break;
    }
    clock_day++;
    TCHAR* temp = new TCHAR[sizeof(double)];
    swprintf(temp, sizeof(double), _T("%f"), temperature_outdoor);
    Create_Item(list6, 0,1,temp);
    swprintf(temp, sizeof(int)+1, _T("%d:00"), clock_day);
    Create_Item(list6, 0, 0, temp);
    delete[] temp;
}

void setList3(LPCTSTR map_type,LPCTSTR map_model,double map_temper,int map_humidity,int map_noise,int map_bacteria)
{
    TCHAR* temp = new TCHAR[sizeof(double)];
    Create_Item(list3, 0, 1, (LPTSTR)map_type);
    Create_Item(list3, 1, 1, (LPTSTR)map_model);
    swprintf(temp, sizeof(map_temper), _T("%f"), map_temper);
    Create_Item(list3, 2, 1, temp);
    swprintf(temp, sizeof(map_humidity), _T("%d"), map_humidity);
    Create_Item(list3, 3, 1, temp);
    swprintf(temp, sizeof(map_noise), _T("%d"), map_noise);
    Create_Item(list3, 4, 1, temp);
    swprintf(temp, sizeof(map_bacteria), _T("%d"), map_bacteria);
    Create_Item(list3, 5, 1, temp);
    switch (Weather)
    {
    case Spring:
        Create_Item(list3, 6, 1, (LPTSTR)_T("春天"));
        break;
    case Summer:
        Create_Item(list3,6, 1, (LPTSTR)_T("夏天"));
        break;
    case Autumn:
        Create_Item(list3, 6, 1, (LPTSTR)_T("秋天"));
        break;
    case Winter:
        Create_Item(list3, 6, 1, (LPTSTR)_T("冬天"));
        break;
    }
    delete[] temp;
}

int counter_Wall = 0;//下面用到的各个数组里面的计数器
int counter_FloorHeat = 0;
int counter_DeHumidifier = 0;
int counter_Humidifier = 0;
int counter_Airfresh = 0;
int counter_aircondition = 0;
void switch_fun(int click_list5_item, int click_list5_isubitem)
{
    switch (click_list5_item)
    {
    case 0://判断是不是空调那一行
    {
        if ((click_list5_isubitem < 5) && (click_list5_isubitem > 0))//判断是不是有空调信息的列
        {
            std::fstream file_Aircondition("E:\\Aircondition.dat", std::ios::out | std::ios::in | std::ios::binary);//打开文件，为了从文件中读取空调信息
            int counter_temp = sizeof(Air_condition) * (click_list5_isubitem - 1);
            file_Aircondition.seekp(counter_temp);
            file_Aircondition.read(reinterpret_cast<char*>(&arr_Airconditon[counter_aircondition/map_l][counter_aircondition % map_l]), sizeof(Air_condition));
            list5_click_temp = &arr_Airconditon[counter_aircondition / map_l][counter_aircondition % map_l];
            counter_aircondition++;

            file_Aircondition.close();

        }
    }
    break;
    case 1:
    {
        if ((click_list5_isubitem < 4) && (click_list5_isubitem > 0))
        {
                std::fstream file_Airfresh("E:\\AirFresh.dat", std::ios::out | std::ios::in | std::ios::binary);
                int counter_temp = sizeof(Air_fresh) * (click_list5_isubitem - 1);
                file_Airfresh.seekp(counter_temp);
                file_Airfresh.read(reinterpret_cast<char*>(&arr_Airfresh[counter_Airfresh / map_l][counter_Airfresh % map_l]), sizeof(Air_fresh));
                list5_click_temp = &arr_Airfresh[counter_Airfresh / map_l][counter_Airfresh % map_l];
                counter_Airfresh++;
                file_Airfresh.close();
        }
    }
    break;
    case 2:
    {
        if ((click_list5_isubitem < 4) && (click_list5_isubitem > 0))
        {
            std::fstream file_Humidifier("E:\\Humidifier.dat", std::ios::out | std::ios::in | std::ios::binary);
            int counter_temp = sizeof(Humidifier) * (click_list5_isubitem - 1);
            file_Humidifier.seekp(counter_temp);
            file_Humidifier.read(reinterpret_cast<char*>(&arr_Humidifier[counter_Humidifier / map_l][counter_Humidifier % map_l]), sizeof(Humidifier));
            list5_click_temp = &arr_Humidifier[counter_Humidifier / map_l][counter_Humidifier % map_l];
            counter_Humidifier++;
            file_Humidifier.close();
        }
    }
    break;
    case 3:
    {
        if ((click_list5_isubitem < 4) && (click_list5_isubitem > 0))
        {

            std::fstream file_Dehumidifier("E:\\Dehumidifier.dat", std::ios::out | std::ios::in | std::ios::binary);
            int counter_temp = sizeof(Dehumidifier) * (click_list5_isubitem - 1);
            file_Dehumidifier.seekp(counter_temp);
            file_Dehumidifier.read(reinterpret_cast<char*>(&arr_Dehumidifier[counter_DeHumidifier/map_l][counter_DeHumidifier % map_l]), sizeof(Dehumidifier));
            list5_click_temp = &arr_Dehumidifier[counter_DeHumidifier / map_l][counter_DeHumidifier % map_l];
            counter_DeHumidifier++;
            file_Dehumidifier.close();
        }
    }
    break;
    case 4:
    {
        if ((click_list5_isubitem == 1))
        {
            std::fstream file_FloorHeat("E:\\FloorHeat.dat", std::ios::out | std::ios::in | std::ios::binary);
            int counter_temp = sizeof(FloorHeat) * (click_list5_isubitem - 1);
            file_FloorHeat.seekp(counter_temp);
            file_FloorHeat.read(reinterpret_cast<char*>(&arr_FloorHeat[counter_FloorHeat / map_l][counter_FloorHeat % map_l]), sizeof(FloorHeat));
            list5_click_temp = &arr_FloorHeat[counter_FloorHeat / map_l][counter_FloorHeat % map_l];
            counter_FloorHeat++;
            file_FloorHeat.close();
        }
    }
    break;
    case 5:
    {
        if ((click_list5_isubitem < 3) && (click_list5_isubitem > 0))
        {
            std::fstream file_Wall("E:\\Wall.dat", std::ios::out | std::ios::in | std::ios::binary);
            int counter_temp = sizeof(Wall) * (click_list5_isubitem - 1);
            file_Wall.seekp(counter_temp);
            file_Wall.read(reinterpret_cast<char*>(&arr_Wall[counter_Wall / map_l][counter_Wall % map_l]), sizeof(Wall));
            list5_click_temp = &arr_Wall[counter_Wall / map_l][counter_Wall % map_l];
            counter_Wall++;
            file_Wall.close();
        }
    }
    break;
    case 6:
    {
        if ((click_list5_isubitem == 1))
        {
            std::fstream file_Window("E:\\Wall.dat", std::ios::out | std::ios::in | std::ios::binary);
            int counter_temp = 0;
            file_Window.seekp(counter_temp);
            file_Window.read(reinterpret_cast<char*>(&arr_Wall[counter_Wall / map_l][counter_Wall % map_l]), sizeof(Wall));
            arr_Wall[counter_Wall / map_l][counter_Wall % map_l].setWindow_if(1);
            list5_click_temp = &arr_Wall[counter_Wall / map_l][counter_Wall % map_l];
            counter_Wall++;
            file_Window.close();
        }
    }
    break;
    case 7:
    {
        if ((click_list5_isubitem == 1))
        {
            std::fstream file_Gate("E:\\Wall.dat", std::ios::out | std::ios::in | std::ios::binary);
            int counter_temp = 0;
            file_Gate.seekp(counter_temp);
            file_Gate.read(reinterpret_cast<char*>(&arr_Wall[counter_Wall / map_l][counter_Wall % map_l]), sizeof(Wall));
            arr_Wall[counter_Wall / map_l][counter_Wall % map_l].setGate_if(1);
            list5_click_temp = &arr_Wall[counter_Wall / map_l][counter_Wall % map_l];
            counter_Wall++;
            file_Gate.close();
        }
    }
    break;
    default: 
    {
        MessageBox(NULL, _T("不知道点的是啥哦(*/ω＼*)"), _T("Tip:"), MB_OK);
    }
    break;
    }
}

void button3_fun()//按钮3的函数
{
    if (arr_furniture[click_list1_item][click_list1_isubitem]->getTemperature() > 0)
    {
        GetWindowText(edit1, edit1_word, 4);
        int a = _ttoi(edit1_word);
        if ((a > 15) && (a < 35))
            arr_furniture[click_list1_item][click_list1_isubitem]->setTemperature(a);
        else if (a <= 15)
            MessageBox(NULL, _T("小心身体，温度不要太低啊喂(〃＞＿＜;〃)"), _T("Tip:"), MB_OK);
        else if (a >= 35)
            MessageBox(NULL, _T("好热啊，不要再高啦(〃＞＿＜;〃)"), _T("Tip:"), MB_OK);
    }
}

void button4_fun()//按钮4的函数
{
    if (arr_furniture[click_list1_item][click_list1_isubitem]->getHumidity_power() > 0)
    {
        GetWindowText(edit2, edit2_word, 4);
        int a = _ttoi(edit2_word);
        if ((a > 0) && (a < 100))
            arr_furniture[click_list1_item][click_list1_isubitem]->setHumidity_request(a);
        else if (a >= 100)
            MessageBox(NULL, _T("嘿嘿，这是不可能做到的(￣▽￣)~*"), _T("Tip:"), MB_OK);
    }
}
void button5_fun()//按钮5的函数
{
    if (map_info[click_list1_item][click_list1_isubitem].judge != 0)
    {
        GetWindowText(edit3, edit3_word, 4);
        int a = _ttoi(edit3_word);
        if (((a >= 0) && (a < 4)) || (a == 10))
            arr_furniture[click_list1_item][click_list1_isubitem]->setGear(a);
        else
            MessageBox(NULL, _T("嘿嘿，这是不可能做到的ヽ(￣▽￣)ﾉ"), _T("Tip:"), MB_OK);
    }
}

int i_hash = 1;//哈希表的一个参数
void list1_fun(LPARAM lParam)
{
    LPNMITEMACTIVATE lpnmitem = (LPNMITEMACTIVATE)lParam;
    click_list1_item = lpnmitem->iItem;
    click_list1_isubitem = lpnmitem->iSubItem;

    if ((list5_click_temp != NULL) && put_if && (map_info[click_list1_item][click_list1_isubitem].judge == 0))//如果现在是放置状态，且放置的东西不为空,该处没有家具，则放置
    {
        Create_Item(list1, click_list1_item, click_list1_isubitem, (LPTSTR)(list5_click_temp->getSymbol()));
        arr_furniture[click_list1_item][click_list1_isubitem] = list5_click_temp;
        arr_furniture[click_list1_item][click_list1_isubitem]->setX(click_list1_item);
        arr_furniture[click_list1_item][click_list1_isubitem]->setY(click_list1_isubitem);
        map_info[click_list1_item][click_list1_isubitem].judge = 1;
        map_hash[i_hash] = map_l * click_list1_item + click_list1_isubitem;
        i_hash++;
        if (list5_click_temp->judge_brick())
        {
            brick_map[click_list1_item][click_list1_isubitem] = 1;
        }
        switch_fun(click_list5_item, click_list5_isubitem);
    }
    if ((!put_if) && (!delete_if))//如果不是放置状态且不是删除状态,则是读取信息
    {
        Create_List2_info(list2, arr_furniture[click_list1_item][click_list1_isubitem]);
    }
    if (delete_if)//判断是不是删除状态
    {
        Create_Item(list1, click_list1_item, click_list1_isubitem, NULL);
        map_info[click_list1_item][click_list1_isubitem].judge = 0;//地图的判断部分设置为0，即当地没有家具
        if (arr_furniture[click_list1_item][click_list1_isubitem]->judge_brick())
        {
            brick_map[click_list1_item][click_list1_isubitem] = 0;
        }
        arr_furniture[click_list1_item][click_list1_isubitem] = furniture_value;//把地图当前位置恢复默认值

        auto i = map_hash.begin();
        for (; i != map_hash.end(); i++)
        {
            if (i->second == click_list1_item * map_l + click_list1_isubitem)
            {
                map_hash.erase(i);
                break;
            }
        }

        
    }
}

void cycle_fun()//室内循环函数
{
    /// <summary>
    /// 先进行不同行之间的参数交换
    /// </summary>

        bool pause1 = 1;//判断有没有碰到砖块
        int i_temp=-1;
        for (int i = 1; i < map_h ; i++)
        {
            for (int j = 0; j < map_l; j++)
            {
                if (brick_map[i][j])//如果碰上砖块
                {
                    if (pause1)//如果之前还没有碰到过砖块
                    {
                        pause1 = 0;
                        if (i_temp > 0)//表明如果又碰到砖块，则说明房子中间有墙.
                            i = i_temp;
                    }
                    else//如果之前碰到过砖块，表面这一段是室内
                    {
                        pause1 = 1;//停止交换参数
                        i_temp = i;
                    }
                }
                if (!pause1)//室内循环
                {
                    double cha = (map_info[i][j].temperature - map_info[i - 1][j].temperature) / 4.0;
                    int cha_h = (map_info[i][j].humidity - map_info[ i - 1][j].humidity) / 3;
                    map_info[i][j].temperature -= cha;
                    map_info[i - 1][j].temperature += cha;
                    map_info[i][j].humidity -= cha_h;
                    map_info[i - 1][j].humidity += cha_h;
                }

            }
            pause1 = 1;
            i_temp = -1;
        }
   
    /// <summary>
    /// 接下来进行不同列之间的交换
    /// </summary>
        bool pause2 = 1;//判断有没有碰到砖块
        int j_temp=-1;
        for (int i = 0; i < map_h; i++)
        {
            for (int j = 1; j < map_l; j++)
            {
                if (brick_map[i][j])//如果碰上砖块
                {
                    if (pause2)//如果之前还没有碰到过砖块
                    {
                        pause2 = 0;
                        if (j_temp > 0)
                            j = j_temp;
                    }
                    else//如果之前碰到过砖块，表面这一段是室内
                    {
                        pause2 = 1;
                        j_temp=j;
                    }
                }

                if (!pause2)//室内循环
                {
                    double cha = (map_info[i][j].temperature - map_info[i][j - 1].temperature) / 4.0;
                    int cha_h = (map_info[i][j].humidity - map_info[i][j - 1].humidity) / 3;
                    map_info[i][ j].temperature -= cha;
                    map_info[i][ j - 1].temperature += cha;
                    map_info[i][ j].humidity -= cha_h;
                    map_info[i][j - 1].humidity += cha_h;

                }
            }
            pause2 = 1;
            j_temp = -1;
        }

}


bool fun_judge()
{
    bool y_n = 1;
    for (int i = 0; i < map_h; i++)
    {
        for (int j = 0; j < map_l; j++)
        {
            if (brick_map[i][j])
            {
                int counter = 0;
                for (int a = -1; a < 2; a++)
                {
                    if((i+a>=0)&&(i+a<map_h))
                    for (int b = -1; b < 2; b++)
                    {
                        if (a*b!=1)
                            if ((j + b >= 0) && (j + b < map_l))
                                if (brick_map[i + a][j + b])
                                    counter++;
                    }
                }
                if (counter < 3)
                {
                    y_n = 0;
                    break;
                }
            }

        }
    }
    if (!y_n)
    {
        MessageBox(NULL, _T("墙壁不封闭哦"), _T("Tip:"), MB_OK);
        return 0;
    }
    else 
        return 1;
}







/// <summary>
/// 以下是系统自带的函数
/// </summary>

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PRACTICALTRAINING));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_PRACTICALTRAINING);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 将实例句柄存储在全局变量中

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

void outsideKeep()
{

    bool pause2 = 1;//判断有没有碰到砖块
    int j_temp = -1;
    for (int i = 0; i < map_h; i++)
    {
        for (int j = 1; j < map_l; j++)
        {
            if (brick_map[i][j])//如果碰上砖块
            {
                if (pause2)//如果之前还没有碰到过砖块
                {
                    pause2 = 0;
                    if (j_temp > 0)
                        j = j_temp;
                }
                else//如果之前碰到过砖块，表明这一段是室内
                {
                    pause2 = 1;
                    j_temp = j;
                }
            }
            indoor[i][j] = 0;
            if (!pause2)//室内循环
            {
                indoor[i][j] = 1;
            }
        }
        pause2 = 1;
        j_temp = -1;
    }
    for (int i = 0; i < map_h; i++)
    {
        for (int j = 0; j < map_l; j++)
        {
            if (!indoor[i][j])
            {
                map_info[i][j].temperature = temperature_outdoor;
                map_info[i][j].bacteria = 0;
                map_info[i][j].humidity = 0;
                map_info[i][j].noise = 0;
            }
            
        }
    }

}