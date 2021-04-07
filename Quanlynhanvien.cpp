#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct Employee{
	char name[40];
	char province[40];
	int age;
};
typedef  struct Employee NV;
struct DanhSach
{
	NV a[100];
	int d;
};
void Nhap(NV  &nv);
void NhapN(NV a , int &n);
void Xuat(NV nv);
void XuatN(NV a[] , int n);
void SapXep(NV a[] , int n);
void XuatFile(NV a[], int n , char fileName );
void thoat();
void menu();
int main(){
	menu();
	
}
void Nhap(NV &a){
	fflush(stdin);
	printf("\n Nhap ten nhan vien : ");
	gets(a.name);
	printf("\n Nhap tinh cua nhan vien : ");
	gets(a.province);
	printf("\n Nhap tuoi cua nhan vien : ");
	scanf("%d",&a.age);
} 
