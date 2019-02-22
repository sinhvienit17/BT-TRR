#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

typedef struct SinhVien
{
	char hoten[20];
	float chieucao;
	float cannang;
}SinhVien;

void Nhap(int n, SinhVien SV[100])
{
	for(int i=0; i<n; i++)
	{
		printf("Nhap ho ten sinh viên thu %d: ",i); fflush(stdin);
		gets(SV[i].hoten);
		printf("Nhap chieu cao cua sinh vien thu %d: ", i); fflush(stdin);
		scanf("%f", &SV[i].chieucao);
		SV[i].cannang = SV[i].chieucao*100-105;
	}
}

void In(int n, SinhVien SV[100])
{
	printf("---Thong tin sinh viên---\n");
	printf("%-30s %-10s %-10s\n", "Ho Ten", "Chieu Cao", "Can nang");
	for(int i=0; i<n; i++)
	{
		printf("%-30s %-10.2f %-10.1f\n", SV[i].hoten, SV[i].chieucao, SV[i].cannang);
	}
}

void chen(int *n, SinhVien svcc, SinhVien SV[100])
{
	for(int i=*n; i>=0 ;i--)
	{
		SV[i] = SV[i-1];
	}
	SV[0] = svcc;
	*n = *n+1;
}

int Tim(int n, SinhVien SV[100], char tct[20])
{
	for(int i=0; i<n; i++)
	{
		if(strcmp(SV[i].hoten ,tct) == 0)
		return i;
		else return -1;
	}
}

void xoa(int *n, SinhVien SV[100], int k)
{
	for(int i=k; i<*n; i++)
	{
		SV[i] = SV[i+1];
	}
	*n = *n-1;
}

int main()
{
	int n;
	SinhVien SV[100] , svcc;
	printf("Nhap so sinh vien: "); fflush(stdin);
	scanf("%d",&n);
	Nhap(n, SV);
	In(n,SV);
	printf("Nhap ho ten sinh viên can chen: "); fflush(stdin);
		gets(svcc.hoten);
		printf("Nhap chieu cao cua sinh vien can chen : "); fflush(stdin);
		scanf("%f", &svcc.chieucao);
		svcc.cannang = svcc.chieucao*100-105;
	chen(&n, svcc, SV);
	In(n,SV);
	char tct[20];
	printf("Nhap ten can tim xoa "); fflush(stdin);
	gets(tct);
	int k = Tim(n, SV, tct);
	if (k<0) printf("khong tim thay");
	else
	{
		xoa(&n, SV, k);
		In(n, SV);
	}
	getch();
	return 0;
}




