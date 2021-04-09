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
void ChenNV(danhsach &ds , NV x, int b){

	fflush(stdin);
	for(int i = ds.n ; i > b ; i-- ){
		ds.a[i]=ds.a[i-1];
	}
	ds.a[b] = x;
	ds.n++;
}
