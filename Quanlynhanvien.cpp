void Nhap(NV &a){
	fflush(stdin);
	printf("\n Nhap ten nhan vien : ");
	gets(a.name);
	printf("\n Nhap tinh cua nhan vien : ");
	gets(a.province);
	printf("\n Nhap tuoi cua nhan vien : ");
	scanf("%d",&a.age);
} 
