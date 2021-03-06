#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct NhanVien;
void hienThiDSNV(struct NhanVien*,int); 
void hienThiTenCot(); 
struct Name {
	char ho[20];
	char dem[21];
	char ten[20]; 
}; 
struct NhanVien {
	struct Name hovaten ;

	char province[40];
	int year; 
	char gioitinh[10]; 
	
}; 
void nhapHoTen(struct Name* ten) {
	printf("Ho : ");
	scanf("%s",ten->ho);
	printf("Dem : ");
	getchar();
	gets(ten->dem) ;
	printf("Ten : ");
	scanf("%s",ten->ten) ;
	}
struct NhanVien nhapNV(){
	struct NhanVien nv;
	nhapHoTen(&nv.hovaten) ;
	printf("Tinh : ");
	scanf("%s",&nv.province);
	printf("Gioi tinh : ");
	scanf("%s",&nv.gioitinh );
	printf("Nam sinh : ");
	scanf("%d",&nv.year ); 


	return nv;	
	}
void hienThiTTNV(struct NhanVien nv){
	printf("%-10s %-10s %-10s %-10s %-10s %-10d \n ",
	nv.hovaten.ho ,  nv.hovaten.dem  , nv.hovaten.ten , nv.province  , nv.gioitinh , nv.year ); 
	                    
}	
void sapXepTheoTen(struct NhanVien* ds, int slnv){
	int i,j ;
	for(i=0;i<slnv-1;i++){
		for(j=slnv-1;j>i; j--){
			if(strcmp(ds[j].hovaten.ten,ds[j-1].hovaten.ten)<0) {
				struct NhanVien nv = ds[j];
				ds[j]=ds[j-1];
				ds[j-1]=nv ;
				}
			}
		} 
}
void timTheoTen(struct NhanVien* ds, int slnv){	
	char ten[40];
	printf("Nhap ten: ");
	scanf("%s",ten);
//	hienThiTenCot(); 
	int i, timNV = 0;
	for(i=0; i<slnv; i++) {
		if(strcmp(ten,ds[i].hovaten.ten )==0){
			hienThiTTNV(ds[i]);
			timNV=1;
			}
			}
	if(timNV==0){
		printf("Khong co nhan vien %s trong danh sach !\n",ten );
		}
	} 
	
void ghiFile(struct NhanVien* ds, int slnv){
	getchar();
	char fName[26];
	printf("Nhap ten file : ");
	gets(fName); 
	FILE* fOut = fopen(fName ,"a");
	int i;
	for(i=0; i<slnv ; i++){
		struct NhanVien nv = ds[i];
		fprintf(fOut,"%-10s %-10s %-10s %-10s %-10s %-10d \n ",
		nv.hovaten.ho ,  nv.hovaten.dem  , nv.hovaten.ten , nv.province  , nv.gioitinh , nv.year ); 
	 }
	fclose(fOut);   
	}   
void docFile(struct NhanVien* ds, int* slnv){
	
	FILE* fOut = fopen("NV.txt" ,"r");
	
	int i=0;
	if(fOut) {
	for(;;){
		struct NhanVien nv = ds[i];
		fscanf(fOut,"%10s %10[^\n] %10s %10s %10s %10d \n ",
		nv.hovaten.ho ,  nv.hovaten.dem  , nv.hovaten.ten , nv.province  , nv.gioitinh , &nv.year ); 
		if(feof(fOut)){
			break;
		}	 
	 	ds[i++] = nv ; 
		}
}
	fclose(fOut);
	*slnv = i ;  
	}   
void hienThiTenCot(){
	printf("------------------------------------"
	"--------------------------------------------\n"); 
	printf(" %-10s %-10s %-10s %-10s %-10s %-10s \n " ,
	"Ho" , "Dem" , "Ten" , "Province " , "Gioi Tinh" , "Year" );
	} 
void hienThiDSNV(struct NhanVien* ds, int slnv) {
	hienThiTenCot();
	int i;
	for(i=0; i<slnv;i++){
		hienThiTTNV(ds[i]); 
		}
	printf("--------------------------------"
	"---------------------------------------\n") ;
	        
	    }
int main(){
	struct NhanVien dsnv[100];
	int slnv = 0;
	int LuaChon; 
	docFile(dsnv, &slnv);
	printf("DANH SACH NHAN VIEN HIEN THOI : \n");
	hienThiDSNV(dsnv,slnv);
	int i; 
	do{ 
		printf("================== MENU ==================");
		printf("\n 1. Them Nhan vien vao danh sach !"); 
		printf("\n 2. Hien thi danh sach nhan vien !"); 
		printf("\n 3. Sap xep theo ten !"); 
		printf("\n 4. Tim Nhan vien theo ten !"); 
		printf("\n 5. Ghi thong tin Nhan vien ra FILE !");
		printf("\n 0. Thoat chuong trinh !");
		printf("\n Ban chon ? ") ;
		
		scanf("%d",&LuaChon) ;
		struct NhanVien nv;
		int i; 
		switch(LuaChon){
			case 0:
				break; 
			case 1:
				//struct NhanVien nv;
				nv = nhapNV();
				dsnv[slnv++] = nv; 
		 		break; 
		 	case 2:
		 		hienThiTenCot(); 
				
				for(i=0 ; i < slnv ; i++){ 
					hienThiTTNV(dsnv[i]); 
					}
				break; 
			case 3:
				sapXepTheoTen(dsnv,slnv); 
				hienThiTenCot();
				for(i=0 ; i < slnv ; i++){ 
					hienThiTTNV(dsnv[i]); 
					}
				break; 
			case 4:
				timTheoTen(dsnv,slnv);
				break;
			case 5:
				ghiFile(dsnv, slnv) ;
				break;
			default:
				printf(" Sai chuc nang , vui long chon lai !\n"); 
				break; 
				}
	}while(LuaChon); 

return;
