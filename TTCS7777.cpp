#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include <stdlib.h>
#include <iomanip>
using namespace std;


typedef struct Ngay{
int ngay, thang , nam;
}ngay;

struct NhanVien{
string ten,chucvu;
float hesoluong;
ngay a;
};
typedef struct NhanVien nhanvien;

 struct Node{

nhanvien NV;
Node*next; 
};
typedef struct Node node;

typedef struct DSNV{
	node*Dau;
	node*Cuoi;
}DSNV;

void KhoiTao(DSNV &ds){
	ds.Dau=ds.Cuoi=NULL; 
}

Node *tao(Node *P, NhanVien nv)   // tao thong tin cho node
{
	P=new Node;
	if(P==NULL) exit(1);
	P->next=NULL;	
	P->NV.ten=nv.ten;
	P->NV.chucvu=nv.chucvu;
	P->NV.a.ngay=nv.a.ngay;
	P->NV.a.thang=nv.a.thang;
	P->NV.a.nam=nv.a.nam;
	P->NV.hesoluong=nv.hesoluong;
	return P;
}


void nhapnhanvien(node &x){
   	
	int day,month,year;
	float hesoluong;
	cin.ignore(1);
	
	
	cout<<"Nhap Ho Ten Nhan Vien: ";
	getline(cin,x.NV.ten);
	cout<<"Chuc Vu Nhan Vien: ";
	getline(cin,x.NV.chucvu);
	cout<<"nhap vao ngay :\n";
	cin>>day;
	x.NV.a.ngay=day;
	cout<<"nhap vao thang :\n";
	cin>>month;
	x.NV.a.thang=month;
	cout<<"nhap vao nam sinh\n";
	cin>>year;
	x.NV.a.nam=year;	

	do{
		cout<<"He So Luong: "; 
		cin>>hesoluong;
	   if(hesoluong<0){
	   	cout<<"Nhap sai.Nhap lai\n";
	   }
	}while(hesoluong < 0);	
		x.NV.hesoluong=hesoluong;
	
	x.next=NULL;
}
//chen danh sach 

//void ChenDau(DSNV &ds, Node* x){
//
//	if(ds.Dau==NULL)
//	{
//		ds.Dau=ds.Cuoi=x;
//	}
//	else
//	{	
//		x->next=ds.Dau;
//		ds.Dau=x;
//	}
//}
void ChenCuoi(DSNV &ds, Node* x){
	if(ds.Dau==NULL){
		ds.Dau=ds.Cuoi=x;
		
	}
	else{
		ds.Cuoi->next=x;
		ds.Cuoi=x;
	}
}


float  NhapNV(DSNV &ds){
	Node *x=new Node();
 
	nhapnhanvien(*x);
	ChenCuoi(ds,x);
	return 0;
}


void nhapsoluongnhanvien(DSNV &ds)
{
	
	int n ,i;
	cout << "Nhap so luong Nhan vien: ";
	cin >> n;
	cout << endl;
	for (i = 1; i <= n; i++)
	{
		cout << "Nhap thong tin cho nhan vien thu " << i << ": " << endl;
			NhapNV(ds);
	}
}



void swap(int &x,int &y)   
{
     float t=x; 
     x=y; 
     y=t; 
}
void swap1(float &x,float &y){
     float t=x; 
     x=y; 
     y=t; 
}
void swap2(string &a,string &b) 
{
     string t=a; 
     a=b; 
     b=t; 
}

//----------------Sap xep theo ten----------------------
void SapXepTen(DSNV &ds){
	node*data=ds.Dau;
	if(data==NULL){
		cout<<"\nDanh sach rong!";
	}else{
		
	for(node* s=ds.Dau;s!=ds.Cuoi;s=s->next)
		for(node*x=s->next;x!=NULL;x=x->next){
			if(s->NV.ten>x->NV.ten){
			swap2(s->NV.ten,x->NV.ten);
			swap2(s->NV.chucvu,x->NV.chucvu);
			swap(s->NV.a.ngay,x->NV.a.ngay);
			swap(s->NV.a.thang,x->NV.a.thang);
			swap(s->NV.a.nam,x->NV.a.nam);
			swap1(s->NV.hesoluong,x->NV.hesoluong);
			}
		}
	}
}	

//----------------Sap xep theo he so luong -----------------
void SapXepHSL(DSNV &ds){
	if(ds.Dau==NULL){
		cout<<"\nDanh Nhan Vien sach rong!";
	}else{
		Node *s,*x;
		for(s=ds.Dau;s!=ds.Cuoi;s=s->next){
		
			for(x=s;x!=NULL;x=x->next){
			if(s->NV.hesoluong>x->NV.hesoluong){
			swap2(s->NV.ten,x->NV.ten);
			swap2(s->NV.chucvu,x->NV.chucvu);
			swap(s->NV.a.ngay,x->NV.a.ngay);
			swap(s->NV.a.thang,x->NV.a.thang);
			swap(s->NV.a.nam,x->NV.a.nam);
			swap1(s->NV.hesoluong,x->NV.hesoluong);
					
				}
			}
	}
	}
}		


int SapXepChucVu(DSNV &ds){
	if(ds.Dau==NULL){
		cout<<"Danh sach nhan vien rong!";
	}else{
		Node *s,*x;
		for(s=ds.Dau;s!=ds.Cuoi;s=s->next)
			for(x=s;x!=NULL;x=x->next){
			if(s->NV.chucvu>x->NV.chucvu){
			swap2(s->NV.ten,x->NV.ten);
			swap2(s->NV.chucvu,x->NV.chucvu);
			swap(s->NV.a.ngay,x->NV.a.ngay);
			swap(s->NV.a.thang,x->NV.a.thang);
			swap(s->NV.a.nam,x->NV.a.nam);
			swap1(s->NV.hesoluong,x->NV.hesoluong);
					
				}
		}
		}
}		
//----------------Sap xep ngay thang nam sinh -----------------
void SapXepDate(DSNV &ds){
	if(ds.Dau==NULL){
		cout<<"\nDanh sach nhan vien rong!";
	}else{
		Node *s,*x;
		for(s=ds.Dau;s!=ds.Cuoi;s=s->next)
			for(x=s->next;x!=NULL;x=x->next){
				if(s->NV.a.nam>x->NV.a.nam){
				swap2(s->NV.ten,x->NV.ten);
				swap2(s->NV.chucvu,x->NV.chucvu);
				swap(s->NV.a.ngay,x->NV.a.ngay);
				swap(s->NV.a.thang,x->NV.a.thang);
				swap(s->NV.a.nam,x->NV.a.nam);
				swap(s->NV.hesoluong,x->NV.hesoluong);	
				}else 	if(s->NV.a.nam==x->NV.a.nam)
				{
				if(s->NV.a.thang>x->NV.a.thang){
					swap2(s->NV.ten,x->NV.ten);
					swap2(s->NV.chucvu,x->NV.chucvu);
					swap(s->NV.a.ngay,x->NV.a.ngay);
					swap(s->NV.a.thang,x->NV.a.thang);
					swap(s->NV.a.nam,x->NV.a.nam);
					swap1(s->NV.hesoluong,x->NV.hesoluong);
						}
				}else  if(s->NV.a.thang==x->NV.a.thang)
				{	
			if(s->NV.a.ngay>x->NV.a.ngay){
					swap2(s->NV.ten,x->NV.ten);
					swap2(s->NV.chucvu,x->NV.chucvu);
					swap(s->NV.a.ngay,x->NV.a.ngay);
					swap(s->NV.a.thang,x->NV.a.thang);
					swap(s->NV.a.nam,x->NV.a.nam);
					swap1(s->NV.hesoluong,x->NV.hesoluong);
					}
				}
			}
	}
}	


int Xoa(DSNV &ds,Node *y){
	Node* data=ds.Dau;
	
	
	if(ds.Dau==y)
	{
		ds.Dau=y->next;
		delete y;
		return 1;
	
	}
	while((data!=NULL)&&(data->next!=y))
	{
	data=data->next;
	}
	if(data==NULL) return 0;
	else
	{
		data->next=y->next;
		delete (y);
		return 1;
	}
	
}

//-------------------Xoa ten--------------------------
void XoaTen(DSNV &ds,string ten){
	int dem=0;
	Node *data=ds.Dau;
	if(ds.Dau==NULL)
		cout<<"\nDanh Sach Nhan vien Rong!\t";
	else {
	
		while(data!=NULL)
		{
			
			if(data->NV.ten.find(ten)!=-1)
			{	
				Xoa(ds,data);
				dem++;
			}
			data=data->next;
		}
		if(dem>0){
		cout<<"\nXoa Thanh Cong: "<<dem<<" Nhan Vien Co Ten: "<<ten<<endl;
			}
		else
			cout<<"\nNV Ten: "<<ten<< " khong ton tai trong danh sach! ";
	}
}


//-------------------Xoa chuc vu----------------------
void XoaChucVu(DSNV &ds,string n){
	int d=0;
	Node *data=ds.Dau;
	if(data==NULL)
	cout<<"\nDanh Sach Nhan vien Rong!";
	else {
		while(data!=NULL)
		{
			if(data->NV.chucvu==n)
			{
				Xoa(ds,data);
				d++;
			}
			data=data->next;
		}

		if(d>0){
			cout<<"\nHe Thong Da Xoa Thanh Cong: "<<d<<" Nhan Vien Co Chuc Vu la:"<<n<<endl;
		}
		else
			cout<<"\n==  Chuc Vu "<<n<<" Khong Ton Tai Trong Danh Sach  =="<<endl;
	}
}

void XoaNgayThangNam(DSNV &ds,Ngay d){
	int dem=0;
	Node *data=ds.Dau;
	if(ds.Dau==NULL)
	cout<<"\nDanh Sach Dang Rong.";

	while(data!=NULL)
	{
	
		if((data->NV.a.ngay==d.ngay)&&(data->NV.a.thang==d.thang)&&(data->NV.a.nam==d.nam))
		{
			Xoa(ds,data);
			dem++;
		}
		data=data->next;
	}
	if(dem>0){
	cout<<"\nHe Thong Da Xoa Thanh Cong: "<<dem<<" Nhan Vien Co Ngay-Thang-Nam/Sinh la:"<<d.ngay<<"-"<<d.thang<<"-"<<d.nam<<endl;
		}
	else
	cout<<"\nNgay-Thang-Nam/Sinh: "<<d.ngay<<"-"<<d.thang<<"-"<<d.nam<<endl;
}

//---------- Xoa theo ngay hoac thang hoac nam rieng biet----------
void XoaDay(DSNV &ds,Ngay d){
	int dem=0;
	Node *data=ds.Dau;
	if(ds.Dau==NULL)
	cout<<"\nDanh Sach Dang Rong!!!.";
	int kq;
	while(data!=NULL)
	{
	
		if(data->NV.a.ngay==d.ngay || data->NV.a.thang==d.thang || data->NV.a.nam==d.nam)
		{
			Xoa(ds,data);
			dem++;
		}
		data=data->next;
	}
	if(dem>0){
	cout<<"\nHe Thong Da Xoa Thanh Cong: "<<dem<<" Nhan Vien"<<endl;
		}
	else
	cout<<"\nNhan Vien khong ton tai trong danh sach";
}

//--------------------Xoa theo he so luong ------------------------------------------
float Xoahesoluong(DSNV &ds,float n){
	int dem=0;
	Node *data=ds.Dau;
	if(ds.Dau==NULL)
	cout<<"\nKhong tim thay nhan vien de xoa.\t";
	int kq;
	while(data!=NULL){
		if(data->NV.hesoluong==n)
		{
			Xoa(ds,data);
			dem++;
		}
		data=data->next;
	}
	if(dem>0){
	cout<<"\nHe Thong Da Xoa Thanh Cong: "<<dem<<" Nhan Vien Co He So Luong: "<<n<<endl;
		}
	else
	cout<<"\nHe So Luong: "<<n<<" Khong Ton Tai Trong Danh Sach";
}


//---------------------------VOID TIM()-------------------------------------------------------------------------------------------------------
void TimTen(DSNV ds, string id){
	int d=0;
	Node *data = ds.Dau;
	
	if (data==NULL) {cout<<"Khong co trong danh sach!!!"; return;}
	cout<<"\nHoTen\t\t\tChucVu\t\tNgay-Thang-Nam/Sinh\tHe So Luong\n";	

	while(data!=NULL){
		if(data->NV.ten.find(id)!=-1){
		cout<< data->NV.ten <<"\t\t"<<data->NV.chucvu<<"\t"<<data->NV.a.ngay<<"-"<<data->NV.a.thang<<"-"<<data->NV.a.nam<<"\t\t\t"<<data->NV.hesoluong<<endl;
		d++;
		}
		data=data->next;
	}
	if(d>0){
	cout<<"\nHe Thong Tim Kiem Thanh Cong: "<<d<<" Nhan Vien Co Ten "<<id<<"Trong Danh Sach"<<endl;
		}
	else
	cout<<"\n===Khong Tim Thay Nhan Vien Co Ten "<<id<<" Trong Danh Sach\n";
}
//-----------------------------------------------------------------------------------------------------------------
void TimChucVu(DSNV ds, string id){
	int d=0;
	Node *data= ds.Dau;
	if (data==NULL)
	 {cout<<"Khong co trong danh sach!!!";return ; }

	while(data!=NULL){
		if(data->NV.chucvu.find(id)!=-1){
		cout<<"\nHoTen\t\t\tChucVu\t\tNgay-Thang-Nam/Sinh\tHe So Luong\n";	
		cout<< data->NV.ten <<"\t\t"<<data->NV.chucvu<<"\t"<<data->NV.a.ngay<<"-"<<data->NV.a.thang<<"-"<<data->NV.a.nam<<"\t\t\t"<<data->NV.hesoluong<<endl;
		d++;
		}
		data=data->next;
	}
	if(d>0){
	cout<<"He Thong Tim Kiem Thanh Cong: "<<d<<" Nhan Vien Co Chuc vu "<<id<<"Trong Danh Sach"<<endl;
		}
	else
	cout<<"Khong Tim Thay Nhan Vien Co Chuc Vu "<<id<<" Trong Danh Sach\n";
}
//---------------------------------------------------------------------------------

void TimTheoNam(DSNV ds,Ngay id){
	int d=0;
	Node *data= ds.Dau;
	if (data==NULL) {cout<<"Khong Tim Thay Nam:\t"<<id.nam<<" \tTrong Danh Sach Can Tim\n";; return;}
	cout<<"\nHoTen\t\t\tChucVu\t\tNgay-Thang-Nam/Sinh\tHe So Luong\n";		
	while(data!=NULL){
		if(data->NV.a.nam==id.nam){
			cout<< data->NV.ten <<"\t\t"<<data->NV.chucvu<<"\t"<<data->NV.a.ngay<<"-"<<data->NV.a.thang<<"-"<<data->NV.a.nam<<"\t\t\t"<<data->NV.hesoluong<<endl;
				d++;
		}
		
			data=data->next;
	}	
	if(d>0){
	cout<<"\nHe Thong Tim Kiem Thanh Cong: "<<d<<" Nhan Vien Co Nam Sinh "<<id.nam<<" Trong Danh Sach\n";
		}
	else
	cout<<"\n===   Khong Tim Thay Nhan Vien Co Nam Sinh "<<id.nam<<" Trong Danh Sach   ===\n";
	
}

//------------------------------------------------------------------------------------------------
void TimTheoNgay(DSNV ds,Ngay id){
	int d=0;
	Node *data= ds.Dau;
if (data==NULL)
 {cout<<"Khong Tim Thay Ngay:\t"<<id.ngay<<" \tTrong Danh Sach Can Tim\n";return;}
	
	while(data!=NULL){
		cout<<"\nHoTen\t\t\tChucVu\t\tNgay-Thang-Nam/Sinh\tHe So Luong\n";		
		if(data->NV.a.ngay==id.ngay){
		cout<< data->NV.ten <<"\t\t"<<data->NV.chucvu<<"\t"<<data->NV.a.ngay<<"-"<<data->NV.a.thang<<"-"<<data->NV.a.nam<<"\t\t\t"<<data->NV.hesoluong<<endl;
		d++;
		}
		
			data=data->next;
	}	
	if(d>0){
	cout<<"He Thong Tim Kiem Thanh Cong: \n"<<d<<" Nhan Vien Co Nam Sinh "<<id.ngay<<" Trong Danh Sach\n";
		}
	else
	cout<<"Khong Tim Thay Nhan Vien Co Ngay\n "<<id.ngay<<" \nTrong Danh Sach   ===\n";
	
}
void TimTheothang(DSNV ds,Ngay id){
	int d=0;
	Node *data= ds.Dau;
	if (data==NULL)
	 {cout<<"Khong Tim Thay Thang:\t"<<id.thang<<" \tTrong Danh Sach Can Tim\n"; return;}
	cout<<"\nHoTen\t\t\tChucVu\t\tNgay-Thang-Nam/Sinh\tHe So Luong\n";		
	while(data!=NULL){
		if(data->NV.a.thang==id.thang){
			cout<< data->NV.ten <<"\t\t"<<data->NV.chucvu<<"\t"<<data->NV.a.ngay<<"-"<<data->NV.a.thang<<"-"<<data->NV.a.nam<<"\t\t\t"<<data->NV.hesoluong<<endl;
				d++;
		}
		
			data=data->next;
	}	
	
	
}

//-----------------------------------------------------------------------------------------------------------
void TimTheongaythangnam(DSNV  ds,Ngay id){

	Node *data= ds.Dau;
	
if (data==NULL) 
{cout<<"Khong Tim Thay Ngay-Thang-Nam:\t"<<id.ngay<<"-"<<id.thang<<"-"<<id.nam<<" \t\nTrong Danh Sach Can Tim\n";return;}
	cout<<"\nHoTen\t\t\tChucVu\t\tNgay-Thang-Nam/Sinh\tHe So Luong\n";		
	while(data!=NULL){
		if(data->NV.a.thang==id.thang&&data->NV.a.ngay==id.ngay && data->NV.a.nam==id.nam){
			cout<< data->NV.ten <<"\t\t"<<data->NV.chucvu<<"\t"<<data->NV.a.ngay<<"-"<<data->NV.a.thang<<"-"<<data->NV.a.nam<<"\t\t\t"<<data->NV.hesoluong<<endl;
			
		}
		
			data=data->next;
	}	

	
}

//-------------------------------------------------------------------------------------------------------------------
void TimHeSoLuong(DSNV x, float id){
	Node *data= x.Dau;
	
	if (data==NULL) {cout<<"Khong Tim Thay He So Luong:\t"<<id<<" \tTrong Danh Sach Can Tim\n"; return;}
	cout<<"\nHoTen\t\t\tChucVu\t\tNgay-Thang-Nam/Sinh\tHe So Luong\n";	

	while(data!=NULL){
		if(data->NV.hesoluong==id){
		cout<< data->NV.ten <<"\t\t"<<data->NV.chucvu<<"\t"<<data->NV.a.ngay<<"-"<<data->NV.a.thang<<"-"<<data->NV.a.nam<<"\t\t\t"<<data->NV.hesoluong<<endl;
		
		}
		data=data->next;
	}

	

}
  


void  GhiFile(DSNV &ds, fstream &f)
{	
	teo:
	Node *data = ds.Dau;
	
	if(data==NULL){
	cout<<"file khong co du lieu ! rong!  \n";
	}
		
			f << "\tHo va Ten\t|\tChu Vu\t|Ngay-Thang-Nam SInh|\tHeSoLuong\t" ;
			f<<"\n";
	while (data != NULL) {
		
		f <<"\t"<< data->NV.ten << "|" <<data->NV.chucvu << "|\t\t" << data->NV.a.ngay << "/" << data->NV.a.thang << "/" << data->NV.a.nam << "\t|" << data->NV.hesoluong ; 
	
		data = data->next;
		f << endl;
	}



}
void DocFile(DSNV &ds, fstream &f)
{   
   

	string line="";
	 while(!f.eof()){
	 NhanVien x;
	 Node *data=new Node();
	 
	 	getline(f,line,'|'); 
		 data->NV.ten=line;
	 	 getline(f,line,'|'); 
		  data->NV.chucvu=line;
		  getline(f,line,'|'); 
		 
	 	 getline(f,line); 
		  data->NV.hesoluong=atof(line.c_str());
	 	
		 ChenCuoi(ds,data);
	}
	cout << "Doc Du Lieu Thanh Cong!" << "\n";

}
void XuatDSNV(DSNV x){
	Node *data=x.Dau; //khoi tao ban dau
	if (data==NULL) 
		cout<<"Danh Sach Nhan Vien Rong!!!!\n";
	else{
	cout<<"\n---------    Danh Sach Nhan Vien:   -------\n";
	cout<< "\nHoTen\t\t\t ChucVu\t\t Ngay-thang-NamSinh\t\tHe So Luong\n";
	
	for(data=x.Dau ; data!=NULL; data=data->next){
		cout<<left<<setw(22)<<data->NV.ten<<setw(8)<<data->NV.chucvu<<"\t\t"<<data->NV.a.ngay<<"-"<<data->NV.a.thang<<"-"<<data->NV.a.nam<<"\t\t\t"<<data->NV.hesoluong<<endl;
		
		cout<<endl;
		}
	}
}
void XuatNhanVien(DSNV ds)
{
	Node *data;
	data=ds.Dau;
	cout<<"----------Danh Sach Nhan Vien Trong Cong Ty----------\n";
	cout<< "HoTen\t ChucVu\t\t Ngay-Thang-NamSinh\t\tHe So Luong\n";
	
	while(data!=NULL){
		cout<<left<<setw(20)<<data->NV.ten<<"\t\t"<<data->NV.chucvu<<"\t"<<data->NV.a.ngay<<"-"<<data->NV.a.thang<<"-"<<data->NV.a.nam<<"\t\t\t"<<data->NV.hesoluong<<endl;
		data=data->next;
		cout<<endl;
	}
}



void xoaHSL(DSNV &ds,float id ){
	
		node *data=ds.Dau;
		int dem =0;
		if(data==NULL ){
			cout<<"danh sach nhan vien rong\n";
			
		}
		while(data!=NULL){
			cout<<"danh sach nhan vien\n";
			cout<<"ten\t chucvu\t\ngaythangnamsinh\t\thesoluong\n";
			if(data->NV.hesoluong==id){
				Xoa(ds,data);
				cout<<data->NV.ten<<"\t"<<data->NV.chucvu<<"\t"<<data->NV.a.ngay<<"-"<<data->NV.a.thang<<"-"<<data->NV.a.nam<<"\t\t"<<data->NV.hesoluong<<endl;
				cout<<"\n";
				dem++;
			}
			data=data->next;
		}
		
}

int  main()
{
	Ngay time;
	DSNV x;
	KhoiTao(x);
	int sl;
	string chuoi;
	fstream f1, f2;
	string file;
	float S;

	ChucNang:
		cout<<"------------------------------------------------------------\n";
		cout<<"  |             Chon Chuc Nang Cua Phan Mem!!!             |  \n";
		cout<<"  | +++++++++++++++++++++++++++++++++++++++++++++++++++++++| \n";
		cout<<"  |  Chon 0: De Thoat Chuong Trinh.                        |  \n";
		cout<<"  |  Chon 1: Nhap So Luong Nhan Vien.                      |  \n";
		cout<<"  |  Chon 2: De Sap Xep Nhan Vien.                         |  \n";
		cout<<"  |  Chon 3: De Them Nhan Vien Theo Cac Tieu CHi Tren.     |  \n";
		cout<<"  |  Chon 4: De Xoa Nhan Vien .                            |  \n";
		cout<<"  |  Chon 5: De Tim Kiem Nhan Vien                         |  \n";
		cout<<"  |  Chon 6: De Xuat  Danh Sach Nhan Vien Ra File Text.    |  \n";
		cout<<"  |  Chon 7: Doc Danh Sach Nhan Vien Tu  File Text!!.      |  \n";
		cout<<"  |  Chon 8: Hien Thi Danh Sach Nhan Vien.                 |  \n";
		cout<<"  ---------------------------------------------------------\n";	
		cout<<"Moi Nhap So:\t";
	 	cin>>sl;
	 		
switch(sl)
{
	case 0 :return 0;
	case 1 : {
		nhapsoluongnhanvien(x);
		XuatDSNV(x);
							
	 }goto ChucNang;
	case 2: {
	XuatDSNV(x);
		int chon;
		lap2:
		cout<<"\n+++++++    Lua Chon Tieu Chi Sap Xep Nhan Vien!!!     +++++++++\n";
		cout<<"\n====     Chon 0: De Quay Lai Menu Ban Dau               ====";
		cout<<"\n====     Chon 1: De Sap Xep Theo Ten.                   ====";
		cout<<"\n====     Chon 2: De Sap Xep Theo Chuc Vu .              ====";
		cout<<"\n====     Chon 3: De Sap Xep Theo Ngay-Thang-Nam Sinh    ====";
		cout<<"\n====     Chon 4: De Sap Xep Theo He So Luong .          ====\n";
		cout<<"Moi Nhap Lua Chon\t";
		cin>>chon;
		switch(chon){
		case 0:goto ChucNang;
		case 1:{
		cout<<"==> Danh sach nhan vien sap xep theo ten la ====";
		SapXepTen(x);
		XuatNhanVien(x);
		break;
		}
		case 2:{
		cout<<"==> Danh sach nhan vien sap xep theo chuc vu la ====";
		SapXepChucVu(x);
		XuatNhanVien(x);
		break;
		}
		case 3:{
		cout<<"==>Danh sach nhan vien sap xep theo ngay thang nam sinh la ====";
		SapXepDate(x);
		XuatNhanVien(x);
		break;
		}
		case 4:{
		cout<<"==> Danh sach nhan vien sap xep theo he so luong la ====";
		SapXepHSL(x);
		XuatNhanVien(x);
		break;
		}									
		}goto lap2;
		}
		case 3: {
		int chon;
		lap3:
		cout<<"\n== Lua Chon Tieu Chi Them Nhan Vien ===\n";	
		cout<<"-  Chon 0: De Quay Lai .                   \n";
		cout<<"-  Chon 1:Them Nhan Vien Tieu Chi Ten.      \n";
		cout<<"-  Chon 2:Them Nhan Vien Tieu Chi Chuc Vu    \n";
		cout<<"-  Chon 3: De Them Nhan Vien Tieu Chi Ngay Sinh \n";
		cout<<"-  Chon 4: De Them Nhan Vien Tieu Chi He So Luong \n";
		cout <<"Moi Nhap Lua Chon \t";
			cin>>chon;
			switch(chon){
			case 0:goto ChucNang;
			case 1:{
				cout<<"Them Nhan Vien Voi Tieu Chi Ten:\n";
				NhapNV(x);
				
				cout<<"\nDanh Sach Sau Khi Them La Tieu Chi Ten ======\n";
				SapXepTen(x);
				XuatNhanVien(x);
				break;
				}
			case 2:{
				cout<<"Nhap Them Nhan Vien Voi tieu Chi Chuc Vu:\n";
				NhapNV(x);
				cout<<"\n===>> Danh Sach Sau Khi Them VOi tieu chi Chuc Vu:  ====\n";
				SapXepChucVu(x);
				XuatNhanVien(x);
				break;
				}
			case 3:{
			cout<<"Nhap Them Nhan Vien Voi tieu Chi Date:\n";
			NhapNV(x);
			cout<<"\n===>> Danh Sach  Them VOi tieu chi chuc vu: =========\n";
			SapXepDate(x);
			XuatNhanVien(x);
			break;
				}
			case 4:{
			cout<<"Nhap Them Nhan Vien Voi tieu Chi He So Luong:\n";
			NhapNV(x);
			cout<<"\n===>> Danh Sach Sau Khi Them VOi tieu chi He So Luong ====";
			SapXepHSL(x);
			XuatNhanVien(x);
			break;
				}
			}goto lap3;	
			}goto ChucNang;
			
				case 4:{
							XuatDSNV(x);
							int chon4;
							lap4:
									cout<<"\n========             Lua Chon Tieu Chi Can Xoa!!!           =========";
									cout<<"\n---------------------------------------------------------------------";
									cout<<"\n====    Chon 0: Quay Lai Menu Ban Dau.                            ===";
									cout<<"\n====    Chon 1: De Xoa Nhan Vien Theo Ten.       	               ===";
									cout<<"\n====    Chon 2: De Xoa Nhan Vien Theo Chuc Vu.   	               ===";
									cout<<"\n====    Chon 3: De Xoa Nhan Vien Theo Ngay Sinh.                  ====";
									cout<<"\n====    Chon 4: De Xoa Nhan Vien Theo Thang Sinh.                 ====";
									cout<<"\n====    Chon 5: De Xoa Nhan Vien Theo Nam Sinh.                   ====";
									cout<<"\n====    Chon 6: De Xoa Nhan Vien Theo Ngay-Thang-Nam Sinh.        ===\n";
									cout<<"\n====    Chon 7: De Xoa Nhan Vien Theo He So Luong.                ===\n";			
								cout<<"\nMoi Nhap So:\t";
								cin.ignore();
								cin>>chon4;
								switch(chon4){
								case 0:goto ChucNang;
								case 1:{
											cout<<"Nhap vao Ten Nhan Vien can xoa: ";
											cin.ignore(1);
											getline(cin,chuoi);
											XoaTen(x,chuoi);
											XuatNhanVien(x);
											break;
										}
								case 2:{
											cout<<"Nhap vao chuc vu nhan vien can xoa: ";
												cin.ignore(1);
											getline(cin,chuoi);
											XoaChucVu(x,chuoi);
									
												XuatNhanVien(x);
											break;
										}goto lap4;
								case 3:{
											cout<<"\n Nhap de xoa theo tieu chi chuc vu\t: "; 
											cin>>time.ngay;
											XoaDay(x,time);
												XuatNhanVien(x);
											break;
										}goto lap4;	
								case 4:{
											 cout<<" Nhap de xoa theo tieu chi thang: "; 
											 cin>>time.thang;
											 XoaDay(x,time);
											 	XuatNhanVien(x);
											break;
										}goto lap4;	
								case 5:{
											 cout<<"\n Nhap vao nam : ";
											  cin>>time.nam;
											 XoaDay(x,time);
												XuatNhanVien(x);
												
											
											break;
										}goto lap4;
								case 6:{
											cout<<"\n Nhap vao ngay can xoa: ";cin>>time.ngay;
											cout<<"\n Nhap vao thang can xoa: ";cin>>time.thang;
											cout<<"\n Nhap vao nam can xoa: ";cin>>time.nam;
											XoaNgayThangNam(x,time);
												XuatNhanVien(x);
											break;
											}goto lap4;
								case 7:{
								cout<<"\n Nhap vao he so luong can xoa: "; cin>>S;
								Xoahesoluong(x,S);
								XuatDSNV(x);
								break;
								
								}goto lap4;
								
//							
								
						
							}goto lap4;
						
						}goto ChucNang;
							
			
			case 5:{
			int chon5;
			lap5:
			cout<<"\n=========      Lua Chon Tieu Chi Tim Kiem Nhan Vien!!!       ========\n";	
			cout<<"\n====    Chon 0: De Quay Lai Menu Dau.                            ====";
			cout<<"\n====    Chon 1: De Tim Kiem Nhan Vien Theo Ten.                  ====";
			cout<<"\n====    Chon 2: De Tim Kiem Nhan Vien Theo Chuc Vu               ====";
			cout<<"\n====    Chon 3: De Tim Kiem Nhan Vien Theo He So Luong           ====";
			cout<<"\n====    Chon 4: De Tim Kiem Nhan Vien Theo Ngay-Thang-Nam Sinh.  ====";
			cout<<"\nXin Moi Nhap\t";
			
			cin>>chon5;
			switch(chon5){
				case 0:goto ChucNang;
				case 1:{
					cout<<"Nhap vao ten can tim kiem: ";
					cin.ignore(1);
					getline(cin,chuoi);
					TimTen(x,chuoi);
					
				}goto lap5;
				case 2:{
					cout<<"Nhap vao chuc vu can tim kiem: ";
					cin.ignore(1);
					getline(cin,chuoi);
					TimChucVu(x,chuoi);
					
				}goto lap5;
				case 3:{
					cout<<"nhap vao he so luong ban can tim:";
					cin>>S;
					TimHeSoLuong(x,S);
					
				}goto lap5;
				
				case 4:{
					int thang;					 
					 date:
					 	cout<<"\n== Moi Ban Lua Chon Cac Tieu Chi Tim NV Theo Ngay-Thang-Nam   ====\n";
					 	cout<<"-Chon 0: De Quay lai:                                 ----\n";
						cout<<"-Chon 1: De Tim Kiem Nhan Vien Theo Ngay:             ----\n";
					 	cout<<"-Chon 2 :De Tim Kiem Nhan Vien Theo Thang:            ----\n";
					 	cout<<"-Chon 3 :De Tim Kiem Nhan Vien Theo Nam:              ----\n";
					 	cout<<"-Chon 4 :De Tim Kiem Nhan Vien Theo Ngay-Thang-Nam:   ----\n";
						cout<<"Moi Ban Chon\t";
						cin>>thang;
						switch(thang){
							case 0:goto lap5;
							case 1:{
								cout<<" Moi Ban Nhap Vao Ngay Can Tim:\n";
								cin >> time.ngay;
								TimTheoNgay(x,time);
							
							}goto date;
							case 2 :{
								cout<<" Moi Ban Nhap Vao Thang Can Tim:\n";
								cin >> time.thang;
								TimTheothang(x,time);
							
							}goto date;
							case 3 :{
								cout<<" Moi Ban Nhap Vao Nam Can Tim:\n";
								cin>>time.nam ;
								TimTheoNam(x,time);
							
							}goto date;
							case 4 :{
								cout<<" Moi Ban Nhap Vao Ngay-Thang-Nam:";
								cout<<"\n Nhap vao ngay : ";
								cin>>time.ngay;
								cout<<"\n Nhap vao thang : ";
								cin>>time.thang;
								cout<<"\n Nhap vao nam : ";
								cin>>time.nam;
								TimTheongaythangnam(x,time);
															
							}goto date;
						}
				
				}goto lap5;
		}
	}
	
				case 6: 
					{	
						cout<<"Moi ban nhap file text muon luu .txt:";
						cin>>file;
				   	    f2.open(file.c_str(), ios::out);
					
						GhiFile(x,f2);
						cout << "Ban Da Ghi File Text la:"<<file<<"\nThanh Cong~~!\n";
						f2.close();
					}goto ChucNang;		
		
			       
			case 7: {
				{

				
					cout<<"Moi ban nhap file text:";
						cin>>file;
					f1.open(file.c_str(), ios::in);
					 	if(!f1){
					cout<<"khong co file \n";
					break;
				}
					 DocFile(x, f1);
					
					 
						XuatNhanVien(x);
					

					}
									
				}goto ChucNang;
				case 8: {
				
						XuatDSNV(x);
		
					}goto ChucNang;			
				
			
}goto ChucNang;
}
			
			
			
	
	

	


		
		
	
	
		
		


