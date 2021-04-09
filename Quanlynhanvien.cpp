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
void Nhap(NV &a){
	fflush(stdin);
	printf("\n Nhap ten nhan vien : ");
	gets(a.name);
	printf("\n Nhap tinh cua nhan vien : ");
	gets(a.province);
	printf("\n Nhap tuoi cua nhan vien : ");
	scanf("%d",&a.age);
} 
void NhapN(NV a[] , int n){
	printf("\n___________________________________________________________________\n");
	for(int i = 0 ; i < n ; i++ ){
		printf("\n Thong tin nhan vien thu a[%d] : ",i+1);
	    Nhap(a[i]);
	}
	printf("\n___________________________________________________________________\n");
}
void Xuat(NV a){
	printf("\n Ho va ten nhan vien : %s ", a.name);
	printf("\n Tinh cua nhan vien  : %s ",a.province);
	printf("\n Tuoi cua nhan vien   : %d ",a.age);
}
void XuatN(NV a[], int n ){

    printf("\n___________________________________________________________________\n");
    for(int i = 0 ; i< n ; i++){
    	printf("\n Thong tin nhan vien thu %d : ",i+1);
    	Xuat(a[i]);
	}
	printf("\n___________________________________________________________________\n");	
}
void thoat(){
	char c;
	do {
         c = getch();
    }while(c!=27);
}
void menu(){
	int n ;
	int k;
	bool daNhap = false ;
	do{
		printf("\n Nhap so luong nhan vien : ");
		scanf("%d",&n);
	}while(n<=0);
	NV a[n];
	while(true){
		system("cls");
		printf("\n **************************************************************\n");
		printf("**                CHUONG TRINH QUAN LY NHAN VIEN               **\n");
		printf("**            01:    Nhap du lieu                              **\n");
		printf("**            02:    In danh sach nhan vien                    **\n");
	    printf("**            03:    Sap xep nhan vien theo tinh               **\n");
	    printf("**            04:    Tim kiem nhan vien                        **\n");
	    printf("**            05:    Thoat                                     **\n");
	    printf("*****************************************************************\n");
	    printf("\n                   Nhap lua chon cua ban                      \n ");
	    scanf("%d",&k);
	switch(k){
		case 1:
			printf("\n Ban da chon nhap ten nhan vien !");
			NhapN(a,n);	
			printf("\n Ban da nhap thanh cong !\n");
			daNhap=true;
			printf("\n Vui long nhap phim bat ki de tiep tuc !");
			getch();
			break;
		case 2: 
		     if(daNhap){
                    printf("\nBan da chon xuat DS  nhan vien!");
                    XuatN(a, n);
                }else{
                    printf("\nNhap DS nhan vien truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;	
        case 5: 
		      printf(" Ban da  chon thoat chuong trinh !");
		      
			  getch();
		default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;	         
	   }
  }
	    
}
