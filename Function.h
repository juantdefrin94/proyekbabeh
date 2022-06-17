#include<iostream>
#include<string>
#include<stdbool.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<vector>
#define GOODS 20
#define ESC 27
using namespace std;

struct goods{
	char quantity[30];
	char purchase[30];
	char selling[30];
	char name[30];
};

vector<goods>goods;

struct goodsInBag{
	char quantity[30];
	char purchase[30];
	char selling[30];
	char name[30];
};

vector<goodsInBag>goodsInBag;

struct history{
	char name[30];
	char productName[30];
	char quantity[30];
	char method[5];
	int d, m, y;
};

vector<history>history;

void scanGoods(){
	goods.clear();
	char quantity[30], purchase[30], selling[30], name[30];
	FILE *op = fopen("Goods/MyGoods.txt", "r");
	while(fscanf(op, "%s %s %s %[^\n]\n", quantity, purchase, selling, name) != EOF){
		struct goods goodss;
		strcpy(goodss.quantity, quantity);
		strcpy(goodss.purchase, purchase);
		strcpy(goodss.selling, selling);
		strcpy(goodss.name, name);
		goods.push_back(goodss);		
	}
	fclose(op);
}

void scanGoodsInBag(){
	goodsInBag.clear();
	char quantity[30], purchase[30], selling[30], name[30];
	FILE *op = fopen("StockinBag/StockinBag.txt", "r");
	while(fscanf(op, "%s %s %s %[^\n]\n", quantity, purchase, selling, name) != EOF){
		struct goodsInBag goodsInBags;
		strcpy(goodsInBags.quantity, quantity);
		strcpy(goodsInBags.purchase, purchase);
		strcpy(goodsInBags.selling, selling);
		strcpy(goodsInBags.name, name);
		goodsInBag.push_back(goodsInBags);		
	} 
	fclose(op);
}

int scanHistory(){
	history.clear();
	char name[30], productName[30], quantity[30], method[5], x[30];
	int d, m, y;
	FILE *op = fopen("Data/History.txt", "r");
	fscanf(op, "%s", x); fclose(op);
	if(strcmp(x, "0") == 0) return 0;
	else{
		op = fopen("Data/History.txt", "r");
		while(fscanf(op, "%[^#]#%[^#]#%[^#]#%[^#]#%d#%d#%d\n", name, productName, quantity, method, &d, &m, &y) != EOF){
			struct history historys;
			strcpy(historys.name, name);
			strcpy(historys.productName, productName);
			strcpy(historys.quantity, quantity);
			strcpy(historys.method, method);
			historys.d = d;
			historys.m = m;
			historys.y = y;
			history.push_back(historys);		
		} 
		return 1;
	}
}

string getString(int type){ //1 = Username, 2 = Password
	string text = "";
	char pw = getch();
	while(pw != 13){
		if(pw == 8){
			if(text.size() > 0){
				cout << "\b \b";
				text.erase(text.size() - 1, 1);
			}
		}else{
			if(text.size() < 12){
				text += pw;
				if(type == 1) cout << pw;
				else if(type == 2) cout << "*";
			}else{
				cout << "\b \b";
				text.erase(text.size() - 1, 1);
				text += pw;
				if(type == 1) cout << pw;
				else if(type == 2) cout << "*";
			}
		}
		pw = getch();
	}
	return text;
}

void printCenter(string text, int sizeX){
	int len = text.size();
	sizeX -= len;
	sizeX /= 2;
	cout << string(sizeX, ' '); cout << text;
}

int getNumber(){
	char answer[100];
	int countNumber = 0;

	do {
		char key = getch();

		if (key == 13) {
			break;
		} else if(key == ESC){
			return 9402;
		}else if (key == '-') {
			if (countNumber == 0) {
				answer[countNumber] = '-';
				printf("-");
				countNumber++;
			}
		} else if (key >= '0' && key <= '9') {
			answer[countNumber] = key;
			printf("%c", key);
			countNumber++;
		} else if (key == 8) {
			if (countNumber != 0) {
				answer[countNumber] = '\0';
				printf("\b \b");
				countNumber--;
			}
		}
	} while(true);
	if(countNumber == 0) return 9999999;	
	return atoi(answer);
}

void viewStockPageWindows(){
	system("mode 59, 80");
	SMALL_RECT WinRect = {0, 0, 59, 80};
	SMALL_RECT* WinSize = &WinRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);
}

void setFontSize(int x, int y){
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    fontInfo.dwFontSize.X = x;
    fontInfo.dwFontSize.Y = y;
    fontInfo.FontWeight = 600;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &fontInfo);
}

void changeCursorPosition(short x, short y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(hConsole, pos);
}

void setWindowSize(string x, string y){
	string cmd = "mode ";
	cmd += x;
	cmd += ", ";
	cmd += y;
	const char *cmds = cmd.c_str();
	system(cmds);
	SMALL_RECT WinRect = {0, 0, (short)stoi(x, nullptr, 10), (short)stoi(x, nullptr, 10)};
	SMALL_RECT* WinSize = &WinRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);
}

void setFontSize(int x, int y, int weight){
    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    fontInfo.dwFontSize.X = x;
    fontInfo.dwFontSize.Y = y;
    fontInfo.FontWeight = weight;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &fontInfo);
}

void moveCenter(){
    RECT rectClient, rectWindow;
    HWND hWnd = GetConsoleWindow();
    GetClientRect(hWnd, &rectClient);
    GetWindowRect(hWnd, &rectWindow);
    int posx, posy;
    posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
    posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2,
    
    SetWindowPos(hWnd, 0, posx, -5, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, SWP_NOSIZE | SWP_NOZORDER );
}

void moveExacCenter(){
    RECT rectClient, rectWindow;
    HWND hWnd = GetConsoleWindow();
    GetClientRect(hWnd, &rectClient);
    GetWindowRect(hWnd, &rectWindow);
    int posx, posy;
    posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
    posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2,
    
    SetWindowPos(hWnd, 0, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, SWP_NOSIZE | SWP_NOZORDER );
}

void setcolor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(hCon,color);
}
