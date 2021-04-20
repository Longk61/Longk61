#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
struct Employee{
	char name[40];
	char province[40];
	int age;
	int mssv;
};
typedef Employee NV;
void Nhap(NV  &x);
void NhapN(NV a[], int &n);
void Xuat(NV x);
void XuatN(NV a[], int n);
void XuatFile(NV a[], int n, char fileName );
void ThemNV(NV a[], int n , int b);
void TimNvTheotinh(NV a[], int n , char c[] );
void Sapxep(NV a[], int n );
void ThongKe(NV a[], int n );
void xuatFile(NV a[], int n,char fileName[] );
void menu();

int main(){
	menu();
	getch();
	
}
void Nhap(NV &x){
	fflush(stdin);
	printf("\n Nhap ten nhan vien : ");
	gets(x.name);
	printf("\n Nhap tinh cua nhan vien : ");
	gets(x.province);
	printf("\n Nhap tuoi cua nhan vien : ");
	scanf("%d",&x.age);
	printf("\n Nhap ma so sinh vien : ");
	scanf("%d",&x.mssv);
} 
void NhapN(NV a[], int &n){
	printf("\n___________________________________________________________________\n");
	for(int i = 0 ; i < n ; i++ ){
		printf("\n Thong tin nhan vien thu %d : ",i+1);
	    Nhap(a[i]);
	}
	printf("\n___________________________________________________________________\n");
}
void Xuat(NV x){
     printf("\n %-20s %-20s %-15d %-15d\n",x.name,x.province,x.age,x.mssv);
}
void XuatN(NV a[], int n){
	printf("\n                  Xuat danh sach nhan vien                          \n");
    printf("\n____________________________________________________________________\n");
    printf("%-20s %-20s %-15s %-15s \n", "Ho Ten "," Tinh"," Tuoi","Ma so Sinh vien");
    for(int i = 0 ; i< n ; i++){
    	Xuat(a[i]);
	}
	printf("\n___________________________________________________________________\n");	
}
void ThemNV(NV a[] ,int &n , NV &x, int b){
	for(int i = n ; i>b ;i--){
		a[i]=a[i-1];
	}
	a[b]= x;
	n++;
}
void TimNvTheoTinh(NV a[], int n , char c[] ){
	int dem;
	printf("%-20s %-20s %-20s \n","Ho Ten ","Tinh","Tuoi");
	for( int i = 0 ; i < n ; i++){
		if(strcmp(a[i].province,c)==0){
			Xuat(a[i]);
			dem++;
		}
	}
	if(dem ==0 ){
		printf(" Khong co chuc nang nay!!!!!!!!!");
	}
}
void Sapxep(NV a[], int n ){
	Employee t;
	for(int i = 0; i <n ; i++){
		for(int j=i+1; j<=n; j++){
			if(strcmp(a[i].province, a[j].province)<0){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	XuatN(a,n);
}
void ThongKe(NV a[], int n ){
	int dem = 0 ;
	for( int i = 0 ; i < n ; i++){
		dem++;
		if(strcmp(a[i].province,a[i+1].province)!=0){
			printf("\n\t %s co %d nhan vien .",a[i].province,dem);
			dem=0;
       	}
	}
}
void xuatFile(NV a[], int n,char fileName[] ){
	FILE * fp;
    fp = fopen (fileName,"w");
    fprintf(fp, "%-20s %-20s %-20s %-20s \n", "Ho Ten","Tinh", "Tuoi","Ma So Sinh Vien");
    for(int i = 0;i < n;i++){
      fprintf(fp, "%-20s %-20s %-20s %-20s \n",a[i].name,a[i].province,a[i].age,a[i].mssv);
    }
    fclose (fp);
}

void menu(){
	NV x;
	char fileName[] = "employee.dat";
	int k,b,n;
	char c[20];
	bool daNhap = false ;
	do{
		printf("\n Nhap so luong nhan vien : ");
		scanf("%d",&n);
	}while(n<=0);
	NV a[max];
	while(true){
		system("cls");
		printf("\n **************************************************************\n");
		printf("**                CHUONG TRINH QUAN LY NHAN VIEN               **\n");
		printf("**            01:    Nhap du lieu                              **\n");
		printf("**            02:    In danh sach nhan vien                    **\n");
	    printf("**            03:    Them Nhan vien                            **\n");
	    printf("**            04:    Tim kiem nhan vien theo tinh              **\n");
	    printf("**            05:    Sap xep nhan vien theo ten (Z->A)         **\n");
	    printf("**            06:    Thong ke nhan vien theo tinh              **\n");
	    printf("**            07:    Ghi thong tin qua file                    **\n");
	    printf("**            08:    Thoat                                     **\n");
	    printf("*****************************************************************\n");
	    printf("\n                   Nhap lua chon cua ban :                      ");
	    scanf("%d",&k);
	switch(k){
		case 1:{
			printf("\n Ban da chon nhap ten nhan vien !");
			NhapN(a,n);	
			printf("\n Ban da nhap thanh cong !\n");
			daNhap=true;
			printf("\n Vui long nhap phim bat ki de tiep tuc !");
			getch();
			break;
		}
		case 2: {
		     if(daNhap){
                    printf("\nBan da chon xuat DS  nhan vien!");
                    XuatN(a,n);
                }else{
                    printf("\nNhap DS nhan vien truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            }
		case 3:{
			    do{
			    printf("\n Them nhan vien\n ");
				printf(" Nhap so vi tri can chen :");
				scanf("%d",&b);
				if(b>n){
					printf(" VUI LONG NHAP LAI !!!!");
				}
			}while(b>n);
	
			    Nhap(x);
				ThemNV(a,n,x,b);
				printf("\n thong tin sinh vien da them vao :\n");
				XuatN(a,n);
				getch();
				break;
				}
		case 4:
			{
				fflush(stdin);
				printf("\n Nhap ten tinh can tim :");
				gets(c);
				printf("\n Du lieu nhan vien can tim la \n\n");
				printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
			    TimNvTheoTinh(a,n,c);
			    getch();
	 			break;	
	     	}
	    case 5: {
	    	printf(" Thong tin nhan vien sau khi sap xep la: \n");
	       	Sapxep(a,n);
		    fflush(stdin);
		    getch();
			break;
		}
		case 6:{
			fflush(stdin);
			printf("\n Thong ke nhan vien theo tinh \n");
			ThongKe(a,n);
			getch();
			break;
		}
		case 7:{
			if(daNhap){
                    printf("\nBan da chon xuat DS SV!");
                    xuatFile(a,n,fileName);
                }
			else{
                   printf("\nNhap DS SV truoc!!!!");
           }
            printf("\nXuat DSSV thanh cong vao file %s!", fileName);
            printf("\nBam phim bat ky de tiep tuc!");
            getch();
		  	break;
		}
		 case 8:{
		    printf(" Ban da  chon thoat chuong trinh !");
		    getch();
		}
		default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;	         
	   }
  }	    
}
