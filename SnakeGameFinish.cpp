#include <stdio.h>
#include <conio.h>
#include "PhamVanHau.h"
#include "windows.h"
#define MAX 100
#include <time.h>
int soLuong = 3;
void veTuongTren(){
	int x, y;
	x = 10;
	y = 1;
	while(x <= 100){
		gotoXY(x, y);
		printf("+");
		x++;
	}
}
void veTuongDuoi(){
	int x, y;
	x = 10;
	y = 26;
	while(x <= 100){
		gotoXY(x, y);
		printf("+");
		x++;
	}
}
void veTuongPhai(){
	int x, y;
	x = 100;
	y = 1;
	while(y <= 26){
		gotoXY(x, y);
		printf("+");
		y++;
	}
}
void veTuongTrai(){
	int x, y;
	x = 10;
	y = 1;
	while(y <= 26){
		gotoXY(x, y);
		printf("+");
		y++;
	}
}
void khoiTaoRan(int toaDoX[], int toaDoY[]){
	int x = 50, y = 13;
	for(int i = 0; i < soLuong; i++){
		toaDoX[i] = x;
		toaDoY[i] = y;
		x--;
	}
}
void veTuong(){
	veTuongTren();
	veTuongDuoi();
	veTuongPhai();
	veTuongTrai();
}
void veRan(int toaDoX[], int toaDoY[]){
	for(int i = 0; i < soLuong; i++){
		gotoXY(toaDoX[i], toaDoY[i]);
		if(i == 0){
			printf("0");
		}
		else{
			printf("o");
		}
	}
}
// them vao dau vao xoa o dau
void them(int a[], int vtThem){
	for(int i = soLuong; i > 0; i--){
		a[i] = a[i - 1];
	}
	a[0] = vtThem;
	soLuong++;
	
}
void xoa(int a[], int vtXoa){
	for(int i = vtXoa; i < soLuong; i++){
		a[i] = a[i + 1];
	}
	soLuong--;
}
void xoaDLC(int toaDoX[], int toaDoY[]){
	for(int i = 0; i < soLuong; i++){
		gotoXY(toaDoX[i], toaDoY[i]);
		printf(" ");
	}
}
bool ranDeQua(int toaDoX[], int toaDoY[], int x, int y){
	for(int i = 0; i < soLuong; i++){
		if(toaDoX[i] == x && toaDoY[i] == y){
			return true; // ran de len qua
		}
	}
	return false;
}
void taoQua(int toaDoX[], int toaDoY[], int &x, int &y){
	// rand() % (b - a + 1) + a thuoc [a,b]
	
	do{
		x = rand() % (99 - 11 + 1) + 11;
		y = rand() % (25 - 2 + 1) + 2;
	}while(ranDeQua(toaDoX, toaDoY, x, y));
	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	gotoXY(x, y);
	printf("o");
}
bool ranAnQua(int x0, int y0, int xQua, int yQua){
	if(x0 == xQua && y0 == yQua){
		return true;
	}
	return false;
}
void xuLyRan(int toaDoX[], int toaDoY[], int x, int y, int &xQua, int &yQua){
	// b1 them vao dau
	them(toaDoX, x);
	them(toaDoY, y);
	// b2 xoa phan tu cuoi
	if(!ranAnQua(toaDoX[0], toaDoY[0], xQua, yQua)){
		xoa(toaDoX, soLuong -1);
		xoa(toaDoY, soLuong -1);
	}
	
	// b3
	else{
		taoQua(toaDoX, toaDoY, xQua, yQua);
	}
	veRan(toaDoX, toaDoY);
}
bool ranChamTuong(int x0, int y0){
	if(y0 == 1 && x0 >= 10 && x0 <= 100){
		return true;
	}
	else if(y0 == 26 && (x0 >= 10 && x0 <= 100)){
		return true;
	}
	else if(x0 == 100 && (y0 >= 1 && y0 <= 26)){
		return true;
	}
	else if(x0 == 10 && (y0 >= 1 && y0 <= 26)){
		return true;
	}
	return false;
}
bool ranChamDuoi(int toaDoX[], int toaDoY[]){
	for(int i = 1; i < soLuong; i++){
		if((toaDoX[0] == toaDoX[i])&& (toaDoY[0] == toaDoY[i])){
			return true;
		}
	}
	return false;
}
bool kiemTraGameover(int toaDoX[], int toaDoY[]){
	bool phamVanHau1 = ranChamDuoi(toaDoX, toaDoY);
	bool phamVanHau2 = ranChamTuong(toaDoX[0], toaDoY[0]);
	if(phamVanHau1 == true || phamVanHau2 == true){
		return true;
	}
	return false;
}
int main(){
	int toaDoX[MAX], toaDoY[MAX];
	// ------------ tao ran roi moi tao qua de kiem tra xem co trung khong
	bool gameover = false;
	veTuong();
	khoiTaoRan(toaDoX, toaDoY);
	veRan(toaDoX, toaDoY);
	srand(time(0));
	int xQua, yQua;
	taoQua(toaDoX, toaDoY, xQua, yQua);
	int check;
	check = 2;
	int x = 50, y = 13;
	while(gameover == false){
		xoaDLC(toaDoX, toaDoY);
		if(kbhit()){
		char kyTu = getch();
			if(kyTu == -32){
			kyTu = getch();
				if(kyTu == 72 && check != 0){
					check = 1;
				}
				else if(kyTu == 80 && check != 1){
					check = 0;
				}
				else if(kyTu == 77 && check != 3){
					check = 2;
				}
				else if(kyTu == 75 && check != 2){
					check = 3;
				}
			}
		}
		if(check == 0){
			y++;
		}
		else if(check == 1){
			y--;
		}
		else if(check == 2){
			x++;
		}
		else if(check == 3){
			x--;
		}
		xuLyRan(toaDoX, toaDoY, x, y, xQua, yQua);
		gameover = kiemTraGameover(toaDoX, toaDoY);
		Sleep(200);
	}
	getch();
	return 0;
}
