#include "De20_DSLK.h"
NodeCTHD* createNodeCTHD(CTHoaDon x)
{
	NodeCTHD *p = new NodeCTHD;
	if (p == NULL)
	{
		printf("overload");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
//============================================================
int isEmptyCTHD(SListCTHD lcthd)
{
	if (lcthd.head == NULL)
		return 1;
	else
		return 0;
}
//=============================================================
int insertHeadCTHD(SListCTHD &lcthd, NodeCTHD *p)
{
	if (p == NULL)
		return 0;
	if (isEmptyCTHD(lcthd) == 1)
	{
		lcthd.head = p;
		lcthd.tail = p;
	}
	else
	{
		p->next = lcthd.head;
		lcthd.head = p;
	}
	return 1;
}
//============================================================
int InsertTailCTHD(SListCTHD &lcthd, NodeCTHD* p)
{
	if (p == NULL)
		return 0;
	if (isEmptyCTHD(lcthd) == 1)
	{
		lcthd.head = p;
		lcthd.tail = p;
	}
	else
	{
		lcthd.tail->next = p;
		lcthd.tail = p;
	}
	return 1;
}
//============================================================
void InsertAfterCTHD(SListCTHD &lcthd, NodeCTHD* q, NodeCTHD* p)
{
	if (p == NULL || q == NULL)
		return;
	p->next = q->next;
	q->next = p;
	if (q == lcthd.tail)
		lcthd.tail == p;

}
//============================================================
void initSListCTHD(SListCTHD &lcthd)
{
	lcthd.head = NULL;
	lcthd.tail = NULL;
}

//============================================================
NodeHH* createNode(HangHoa x)
{
	NodeHH *p = new NodeHH;
	if (p == NULL)
	{
		printf("overload");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
//============================================================
int isEmpty(SListHH l)
{
	if (l.head == NULL)
		return 1;
	else
		return 0;
}
//=============================================================
int insertHead(SListHH &l, NodeHH *p)
{
	if (p == NULL)
		return 0;
	if (isEmpty(l) == 1)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
	return 1;
}
//============================================================
int InsertTail(SListHH &l, NodeHH* p)
{
	if (p == NULL)
		return 0;
	if (isEmpty(l) == 1)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
	return 1;
}
//============================================================
void InsertAfter(SListHH &l, NodeHH* q, NodeHH* p)
{
	if (p == NULL || q == NULL)
		return;
	p->next = q->next;
	q->next = p;
	if (q == l.tail)
		l.tail == p;

}
//============================================================
NodeHH *TimHangHoa(SListHH l, char MaHH[])
{
	for (NodeHH *i = l.head; i != NULL; i = i->next)
		if (strcmp(MaHH, i->info.MaHangHoa) == 0)
			return i;
	return NULL;
}
//============================================================
void initSListHH(SListHH &l)
{
	l.head = NULL;
	l.tail = NULL;
}

void nhapFileHeadHH(SListHH &l)
{
	initSListHH(l);
	fstream f("hanghoa.txt");
	if (!f.is_open())
		return;
	int i = 0;
	while (!f.eof())
	{
		if (i >= 100)
		{
			cout << "\nToi da 100 hang hoa hang";
			return;
		}
		HangHoa fa;
		f >> fa.MaHangHoa;
		f >> fa.TenSP;
		f >> fa.DonViTinh;
		f >> fa.GiaNhap;
		f >> fa.GiaBan;
		NodeHH *t = createNode(fa);
		insertHead(l, t);
		i++;
	}
	f.close();
}
void Xuat1HangHoa(NodeHH* k)
{
	cout << "\n" << setw(15) << left << k->info.MaHangHoa << setw(30) << left << k->info.TenSP
		<< setw(20) << left << k->info.DonViTinh << setw(20) << left << k->info.GiaNhap
		<< setw(10) << left << k->info.GiaBan;
}
void XuatHangHoa(SListHH &l)
{
	cout << setw(15) << left << "MaHangHoa :" << setw(30) << left << "TenSP :"
		<< setw(20) << left << "DonViTinh :" << setw(20) << left << "GiaNhap :"
		<< setw(10) << left << "GiaBan :" << "\n";
	for (NodeHH* i = l.head; i != NULL; i = i->next)
		Xuat1HangHoa(i);
}
//==================================================================================================================
//============================================================
NodeKH* createNodeKH(KhachHang x)
{
	NodeKH *p = new NodeKH;
	if (p == NULL)
	{
		printf("overload");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
//============================================================
int isEmpty(SListKH l)
{
	if (l.head == NULL)
		return 1;
	else
		return 0;
}
//=============================================================
int insertHeadKH(SListKH &l, NodeKH *p)
{
	if (p == NULL)
		return 0;
	if (isEmpty(l) == 1)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
	return 1;
}
//============================================================
int InsertTailKH(SListKH &l, NodeKH* p)
{
	if (p == NULL)
		return 0;
	if (isEmpty(l) == 1)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
	return 1;
}
//============================================================
void InsertAfterKH(SListKH &l, NodeKH* q, NodeKH* p)
{
	if (p == NULL || q == NULL)
		return;
	p->next = q->next;
	q->next = p;
	if (q == l.tail)
		l.tail == p;

}

//============================================================
void initSListKH(SListKH &l)
{
	l.head = NULL;
	l.tail = NULL;
}
void docKH(SListKH &l)
{
	initSListKH(l);
	fstream f("khachhang.txt");
	if (!f.is_open())
		return;
	int i = 0;
	while (!f.eof())
	{
		if (i >= 50)
		{
			cout << "\nToi da 50 khach hang";
			return;
		}
		KhachHang y;
		f >> y.MaKhachHang;
		f >> y.FullName;
		f >> y.NumberPhone;
		NodeKH* p = createNodeKH(y);
		insertHeadKH(l, p);
		i++;
	}
	f.close();
}
//========================================================================
void Xuat1KhachHang(NodeKH* h)
{
	cout << "\n" << setw(20) << left << h->info.MaKhachHang << setw(20) << left << h->info.FullName <<
		setw(30) << left << h->info.NumberPhone;
}
//========================================================================
void XuatKhachHang(SListKH l)
{
	cout << setw(20) << left << "MaKhachHang :" << setw(15) << left << "FullName :" <<
		setw(30) << left << "NumberPhone :" << "\n";
	for (NodeKH* i = l.head; i != NULL; i = i->next)
		Xuat1KhachHang(i);
}
//=========================================================================================================
//============================================================
NodeHD* createNodeHD(HoaDon x)
{
	NodeHD *p = new NodeHD;
	if (p == NULL)
	{
		printf("overload");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
//============================================================
int isEmptyHD(SListHD l)
{
	if (l.head == NULL)
		return 1;
	else
		return 0;
}
//=============================================================
int insertHeadHD(SListHD &l, NodeHD *p)
{
	if (p == NULL)
		return 0;
	if (isEmptyHD(l) == 1)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		p->next = l.head;
		l.head = p;
	}
	return 1;
}
//============================================================
int InsertTailHD(SListHD &l, NodeHD* p)
{
	if (p == NULL)
		return 0;
	if (isEmptyHD(l) == 1)
	{
		l.head = p;
		l.tail = p;
	}
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
	return 1;
}
//============================================================
void InsertAfterHD(SListHD &l, NodeHD* q, NodeHD* p)
{
	if (p == NULL || q == NULL)
		return;
	p->next = q->next;
	q->next = p;
	if (q == l.tail)
		l.tail == p;

}

//============================================================
void initSListHD(SListHD &l)
{
	l.head = NULL;
	l.tail = NULL;
}

//========================================================================
void DocFILECTHoaDon(string CTHD, SListHH l, SListCTHD &lcthd)
{
	initSListCTHD(lcthd);
	fstream f(CTHD + ".txt");
	if (!f.is_open())
		return;
	int j = 0;
	while (!f.eof())
	{
		CTHoaDon t;
		f >> t.MaHangHoa;
		f >> t.SoLuongBan;
		NodeCTHD* p = createNodeCTHD(t);
		insertHeadCTHD(lcthd, p);
	}
	NodeCTHD *p = lcthd.head;
	while (p != NULL)
	{
		NodeHH *h = TimHangHoa(l, p->info.MaHangHoa);
		if (h != NULL)
		{
			p->info.ThanhTien = p->info.SoLuongBan * h->info.GiaBan;
			j++;
		}
		p = p->next;
	}
}

//===================================================================
double TongTien(SListCTHD lcthd)
{
	double Tien = 0.0;
	for (NodeCTHD* i = lcthd.head; i != NULL; i = i->next)
		Tien += i->info.ThanhTien;
	if (Tien >= 200000)
		return Tien / 100 * 95;
	return Tien;
}
void Xuat1CTHD(SListCTHD l)
{
	for (NodeCTHD *i = l.head; i != NULL; i = i->next)
	{
		cout << "\n" << i->info.MaHangHoa << "\t" << i->info.SoLuongBan;
	}
}
//========================================================================
NodeKH *TimKhachHang(SListKH l, char MaKH[])
{
	for (NodeKH* i = l.head; i != NULL; i = i->next)
		if (MaKH == i->info.MaKhachHang)
			return i;
	return NULL;
}
//Hàm hóa ðõn
void DocFILEHoaDon(SListHD &lhd, SListKH lkh, SListHH lhh, SListCTHD &lcthd)
{
	NodeCTHD *p = lcthd.head;
	initSListHD(lhd);
	fstream f("hoadon.txt");
	if (!f.is_open())
		cout << "\nLoi mo file";
	else
	{
		int i = 0;
		while (!f.eof() && p != NULL)
		{
			HoaDon k;
			f >> k.MaHoaDon;
			f >> k.MaKhachHang;
			f >> k.NgayBan;
			DocFILECTHoaDon(k.MaHoaDon, lhh, lcthd);
			k.TongTien = TongTien(lcthd);
			k.cthd = lcthd;
			//DocFILECTHoaDon(k.cthd, k.MaHoaDon, lhh);
			//NodeHH *h = TimHangHoa(l, t.MaHangHoa);
			NodeHD *p = createNodeHD(k);
			insertHeadHD(lhd, p);
			if (TimKhachHang(lkh, k.MaKhachHang) != NULL)
				i++;
			p = p->next;
		}
	}
}
//========================================================================
void Xuat1HoaDon(NodeHD* d)
{
	cout << "\n" << d->info.MaHoaDon << "\t" << d->info.MaKhachHang << "\t" << d->info.NgayBan << "\t" << (size_t)d->info.TongTien;
}
void XuatHoaDon(SListHD lhd)
{
	for (NodeHD* i = lhd.head; i != NULL; i = i->next)
		Xuat1HoaDon(i);
}

int tim_XuatHDVaCTHD_duaVaoSoHD(SListHD HD, char soHD[7])
{

	//-----------------------------------------------

	if (isEmptyHD(HD) == 1)
	{
		printf("\n DS hoa don rong: ");
		return 0;
	}
	for (NodeHD *p = HD.head; p != NULL; p = p->next)
	{
		char so[7];
		//int n = strlen(p->info.MaHoaDon);
		//strncpy(so,p->info.MaHoaDon+3 , n-2);
		if (strcmp(soHD, p->info.MaHoaDon) == 0)
		{
			printf("\n - thong tin HD: ");
			Xuat1HoaDon(p);
			printf("\n - HD CHI TIET: ");
			Xuat1CTHD(p->info.cthd);
			return 1;
		}
	}

	printf("\n so don %s khong ton tai", soHD);
	return 0;

}
//câu 7
//=====================================
void xuatAllHD_tongTienMax(SListHD HD)
{
	if (isEmptyHD(HD) == 1)
	{
		cout << "\n" << " DS hoa don rong";
		return;
	}

	double tongTienMax = HD.head->info.TongTien;
	for (NodeHD *p = HD.head->next; p != NULL; p = p->next)
	{
		if (tongTienMax < p->info.TongTien)
			tongTienMax = p->info.TongTien;
	}
	cout << "\n" << (tongTienMax);

	for (NodeHD *p = HD.head; p != NULL; p = p->next)
	{

		if (tongTienMax == p->info.TongTien)
			Xuat1HoaDon(p);
	}
}

//câu 9
//=====================================================
int lietKeHD_duaVaoMaKH(SListHD HD, char maKH[50])
{
	if (isEmptyHD(HD) == 1)
	{
		printf("\n DS hoa don rong: ");
		return 0;

	}
	int dem = 0;
	for (NodeHD *p = HD.head; p != NULL; p = p->next)
	{
		if (strcmp(p->info.MaKhachHang, maKH) == 0)
		{
			dem++;
			Xuat1HoaDon(p);
		}
	}
	if (dem == 0)
	{
		printf("\n Khong ton tai hoa don cua khach hang %s khong ton tai", maKH);
		return 0;
	}
	else
	{
		printf("\n khach hang %s co %d hoa don", maKH, dem);
		return 1;
	}
}
void XuatHDTongTienGiamDan(SListHD lhd)
{
	for (NodeHD* p = lhd.head; p != lhd.tail; p = p->next)
	{
		for (NodeHD* q = p->next; q != NULL; q = q->next)
		{
			if (p->info.TongTien < q->info.TongTien)
				std: swap(p->info.TongTien, q->info.TongTien);
		}
	}
}

void XuatHDMaKHTangDan(SListHD lhd)
{
	for (NodeHD* p = lhd.head; p != lhd.tail; p = p->next)
	{
		for (NodeHD* q = p->next; q != NULL; q = q->next)
		{
			if (strcmp(p->info.MaKhachHang, q->info.MaKhachHang) > 0)
				std: swap(q->info, p->info);
		}
	}
}

//Gi?i thích do ngay/tháng/nãm có t?t c? 10 k? t? và khi m?n tách t?ng thành ph?n ra ta dung ham strncpy(bi?n gi? giá
//tr?,str+v? trí c?t,s? k? t? mu?n c?t);
//hàm atoi chuy?n chu?i sang s? nguyên
int Ngay(char h[])
{
	char ngay[3];
	strncpy(ngay, h + 0, 2);
	ngay[2] = '\0';
	return atoi(ngay);
}
int Thang(char h[])
{
	char thang[3];
	strncpy(thang, h + 3, 2);
	thang[2] = '\0';
	return atoi(thang);
}
int Nam(char h[])
{
	char nam[5];
	strncpy(nam, h + 6, 4);
	nam[4] = '\0';
	return atoi(nam);
}
void doanhThuTheoNgay(SListHD lhd)
{
	char day[11];
	double Tong = 0;
	printf("\nNhap ngay thang nam muon tinh : ");
	scanf("%s", &day);
	for (NodeHD *p = lhd.head; p != NULL; p = p->next)
	{
		if (strcmp(day, p->info.NgayBan) == 0)
			Tong += p->info.TongTien;
	}
	if (Tong == 0)
		printf("\nNgay %d khong co doanh thu", day);
	else
		printf("\nTong tien ngay %s : %.0f", day, Tong);
}
int kiemTraNam(SListHD lhd, int Year)
{
	for (NodeHD *p = lhd.head; p != NULL; p = p->next)
	{
		if (Year == Nam(p->info.NgayBan))
			return 1;
	}
	return 0;
}
void doanhThuTheoThang(SListHD lhd)
{
	int Year;
	do
	{
		cout << "\nNhap nam muon tinh theo thang : ";
		cin >> Year;
	} while (Year < 1 || Year > 2021 || kiemTraNam(lhd, Year) == 0);
	int Month;
	double Tong = 0;
	do
	{
		cout << "\nNhap thang muon tinh : ";
		cin >> Month;
	} while (Month < 1 || Month > 12);
	for (NodeHD *p = lhd.head; p != NULL; p = p->next)
	{
		if (Month == Thang(p->info.NgayBan) && Year == Nam(p->info.NgayBan))
			Tong += p->info.TongTien;
	}
	if (Tong == 0)
		cout << "\nThang " << Month << " khong co doanh thu ";
	else
		cout << "\nTong tien thang " << Month << " : " << Tong;
}
void doanhThuTheoNam(SListHD lhd)
{
	int Year;
	double Tong = 0;
	do
	{
		cout << "\nNhap nam muon tinh : ";
		cin >> Year;
	} while (Year < 1 || Year > 2022);
	for (NodeHD *p = lhd.head; p != NULL; p = p->next)
	{
		if (Year == Nam(p->info.NgayBan))
			Tong += p->info.TongTien;
	}
	if (Tong == 0)
		cout << "\nNam " << Year << " khong co doanh thu ";
	else
		cout << "\nTong tien nam " << Year << " : " << Tong;
}
void doanhThuTheoQuy(SListHD lhd)
{
	int Chon = 1;
	int Year;
	do
	{
		cout << "\nNhap nam muon tinh theo Quy : ";
		cin >> Year;
	} while (Year < 1 || Year > 2021 || kiemTraNam(lhd, Year) == 0);
	while (Chon != 0)
	{
		cout << "\n====================================================";
		cout << "\n1. Xuat doanh thu quy 1";
		cout << "\n2. Xuat doanh thu quy 2";
		cout << "\n3. Xuat doanh thu quy 3";
		cout << "\n4. Xuat doanh thu quy 4";
		cout << "\n0. Thoat";
		cout << "\n====================================================";
		cout << "\nChon Quy muon xuat doanh thu : ";
		cin >> Chon;
		//system("cls");
		switch (Chon)
		{
		case 1:
		{
			double Tong = 0;
			for (NodeHD *p = lhd.head; p != NULL; p = p->next)
			{
				if (Thang(p->info.NgayBan) >= 1 && Thang(p->info.NgayBan) <= 3 && Year == Nam(p->info.NgayBan))
					Tong += p->info.TongTien;
			}
			if (Tong == 0)
				cout << "\nQuy " << Chon << " Nam " << Year << "khong co doanh thu " << endl;
			else
				cout << "\nTong tien Quy " << Chon << "Nam" << Year << " : " << Tong << endl;
			break;
		}
		case 2:
		{
			double Tong = 0;
			for (NodeHD *p = lhd.head; p != NULL; p = p->next)
			{
				if (Thang(p->info.NgayBan) >= 4 && Thang(p->info.NgayBan) <= 6 && Year == Nam(p->info.NgayBan))
					Tong += p->info.TongTien;
			}
			if (Tong == 0)
				cout << "\nQuy " << Chon << " khong co doanh thu " << endl;
			else
				cout << "\nTong tien Quy " << Chon << " : " << Tong << endl;
			break;
		}
		case 3:
		{
			double Tong = 0;
			for (NodeHD *p = lhd.head; p != NULL; p = p->next)
			{
				if (Thang(p->info.NgayBan) >= 7 && Thang(p->info.NgayBan) <= 9 && Year == Nam(p->info.NgayBan))
					Tong += p->info.TongTien;
			}
			if (Tong == 0)
				cout << "\nQuy " << Chon << " khong co doanh thu " << endl;
			else
				cout << "\nTong tien Quy " << Chon << " : " << Tong << endl;
			break;
		}
		case 4:
		{
			double Tong = 0;
			for (NodeHD *p = lhd.head; p != NULL; p = p->next)
			{
				if (Thang(p->info.NgayBan) >= 10 && Thang(p->info.NgayBan) <= 12 && Year == Nam(p->info.NgayBan))
					Tong += p->info.TongTien;
			}
			if (Tong == 0)
				cout << "\nQuy " << Chon << " khong co doanh thu " << endl;
			else
				cout << "\nTong tien Quy " << Chon << " : " << Tong << endl;
			break;
		}
		}
	}
}

void themKiTu0ODau(char s[], int doDai_chuoi)
{
	int n = strlen(s);
	if (n < doDai_chuoi)
	{
		for (int i = doDai_chuoi, j = n; i >= doDai_chuoi - n; i--, j--)
			s[i] = s[j];
		for (int i = 0; i < doDai_chuoi - n; i++)
			s[i] = '0';
	}
}
void taoMaMoi(int dem, char ma[5])
{
	char s[5];
	itoa(dem, s, 10);
	themKiTu0ODau(s, 3);
	/*int n = strlen(s);
	for (int i = 3, j = strlen(s); i >= 3 - (4 - n); i--, j--)
	s[i] = s[j];
	for (int i = 0; i < 3 - n; i++)
	s[i] = '0';*/
	int i = 0;
	while (i <= 3)
	{
		ma[2 + i] = s[i];
		i++;
	}
}
void taoMaHangHoaMoi(SListHH l, char ma[])
{
	int dem = 0;
	for (NodeHH*p = l.head; p != NULL; p = p->next)
		dem++;
	ma[0] = 'H';
	ma[1] = 'H';
	taoMaMoi(dem, ma);
}
void them1HangHoa(SListHH &l)
{
	HangHoa moi;
	taoMaHangHoaMoi(l, moi.MaHangHoa);
	printf("Nhap ten san pham: ");
	scanf("%s", &moi.TenSP);
	printf("Nhap don vi tinh: ");
	scanf("%s", &moi.DonViTinh);
	printf("Nhap gia nhap: ");
	scanf("%f", &moi.GiaNhap);
	printf("Nhap gia ban: ");
	scanf("%f", &moi.GiaBan);
	insertHead(l, createNode(moi));
	/*insertHead(l, createNode(moi));
	FILE* f = fopen("hanghoa.txt", "r+");
	fseek(f, 0, SEEK_END);
	fprintf(f, "\n%s %s %s %.1f %.1f", moi.MaHangHoa, moi.TenSP, moi.DonViTinh, moi.GiaNhap, moi.GiaBan);
	fclose(f);*/
}
void taoMaHoaDonMoi(SListHD l, char ma[])
{
	int dem = 1;
	for (NodeHD*p = l.head; p != NULL; p = p->next)
		dem++;
	ma[0] = 'H';
	ma[1] = 'D';
	taoMaMoi(dem, ma);
}
void taoMaKhachHangMoi(SListKH KH, char ma[5])
{
	int dem = 1;
	for (NodeKH*p = KH.head; p != NULL; p = p->next)
		dem++;
	ma[0] = 'K';
	ma[1] = 'H';
	taoMaMoi(dem, ma);
}
void copyChar(char a[], char cp[])
{
	for (int i = 0; i <= strlen(a); i++)
		cp[i] = a[i];
}
NodeHH* timHangHoa(SListHH HH, char ma[])
{
	for (NodeHH*p = HH.head; p != NULL; p = p->next)
		if (strcmpi(p->info.MaHangHoa, ma) == 0)
			return p;
	return NULL;
}
NodeCTHD* kTMuaHangHoaDaTungMua(SListCTHD cthd, char ma[])
{
	for (NodeCTHD*p = cthd.head; p != NULL; p = p->next)
		if (strcmp(p->info.MaHangHoa, ma) == 0)
			return p;
	return NULL;
}
float tinhTien1MonHang(CTHoaDon ct, SListHH HH)
{
	float tong = 1.0*ct.SoLuongBan*timHangHoa(HH, ct.MaHangHoa)->info.GiaBan;
	if (tong >= 200000)
		return tong/100 * 95;
	return tong;
}
void xuatCTHD(SListCTHD cthd, SListHH HH)
{
	for (NodeCTHD*p = cthd.head; p != NULL; p = p->next)
	{
		printf("\nMa hang hoa: %s", p->info.MaHangHoa);
		printf("\nSo luong ban: %d", p->info.SoLuongBan);
		printf("\nThanh tien: %.2f", tinhTien1MonHang(p->info, HH));

	}
}
NodeKH* kiemTraKhachHangDaTonTai(SListKH KH, char sdt[])
{
	for (NodeKH*p = KH.head; p != NULL; p = p->next)
		if (strcmp(sdt, p->info.NumberPhone) == 0)
			return p;
	return NULL;
}
void layNgayThangNamCuaHeThong_Char(char tg[])
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	ltm->tm_year += 1900;
	ltm->tm_mon += 1;
	char ngay[3], thang[3], nam[5];
	itoa(ltm->tm_mday, ngay, 10);
	itoa(ltm->tm_mon, thang, 10);
	itoa(ltm->tm_year, nam, 10);
	themKiTu0ODau(ngay, 2);
	themKiTu0ODau(thang, 2);
	themKiTu0ODau(nam, 4);
	for (int i = 0; i < 2; i++)
	{
		tg[i] = ngay[i];
		tg[i + 3] = thang[i];
		tg[i + 6] = nam[i];
		tg[i + 8] = nam[i + 2];
		tg[(i + 1) * 2 + i] = '/';
	}
	tg[10] = '\0';
}
void ghiCTHDMoiVaoFile(char tenfile[], SListCTHD Moi)
{
	char txt[] = ".txt";
	char namef[10];
	int n = strlen(tenfile);
	for (int i = 0; i < n; i++)
		namef[i] = tenfile[i];
	for (int i = 0; i <= strlen(txt); i++)
		namef[n + i] = txt[i];
	FILE*f = fopen(namef, "a+");
	for (NodeCTHD*p = Moi.head; p != NULL; p = p->next)
		fprintf(f, "\n%s %d", p->info.MaHangHoa, p->info.SoLuongBan);
	fclose(f);
}
void ghiHoaDonMoiVaoFile(HoaDon moi)
{
	FILE*f = fopen("hoadon.txt", "r+");
	fseek(f, 0, SEEK_END);
	fprintf(f, "\n%s %s %s", moi.MaHoaDon, moi.MaKhachHang, moi.NgayBan);
}
SListCTHD taoChiTietHoaDon(SListHH HH, double& tong_tien)
{
	SListCTHD moi;
	initSListCTHD(moi);
	tong_tien = 0;
	do
	{
		CTHoaDon mHH;
		NodeHH* k;
		do
		{
			printf("\nNhap ma hang hoa: ");
			scanf("%s", &mHH.MaHangHoa);
			k = timHangHoa(HH, mHH.MaHangHoa);
			if (!k)
				printf("Ma hang hoa khong ton tai! Hay nhap lai:\n");
		} while (!k);
		printf("Nhap so luong ban muon mua: ");
		scanf("%d", &mHH.SoLuongBan);
		NodeCTHD*p = kTMuaHangHoaDaTungMua(moi, mHH.MaHangHoa);
		if (p != NULL)
			p->info.SoLuongBan += mHH.SoLuongBan;
		else
			insertHeadCTHD(moi, createNodeCTHD(mHH));
		tong_tien += mHH.SoLuongBan*k->info.GiaBan;
		printf("Ban co muon mua them sam pham nao khach khong?\n");
		printf("Bam cac phim sau:\nPhim bat ki.Co\n0.Khong");
		while (true)
			if (_kbhit())
				if (getch() == '0')
					return moi;
				else
					break;
	} while (true);
}
void banHang(SListHD &HD, SListKH &KH, SListHH HH)
{
	HoaDon moi;
	taoMaHoaDonMoi(HD, moi.MaHoaDon);
	KhachHang mKH;
	printf("Nhap so dien thoai de tim kiem khach hang: ");
	scanf("%s", &mKH.NumberPhone);
	NodeKH *k = kiemTraKhachHangDaTonTai(KH, mKH.NumberPhone);
	if (k == NULL)
	{
		printf("Day la khach hang moi! Tao thong tin khach hang moi: ");
		printf("\nNhap ho va ten khach hang moi:");
		scanf("%s", &mKH.FullName);
		taoMaKhachHangMoi(KH, mKH.MaKhachHang);
		copyChar(mKH.MaKhachHang, moi.MaKhachHang);
		insertHeadKH(KH, createNodeKH(mKH));
		/*FILE* f = fopen("khachhang.txt", "r+");
		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s %s %s", mKH.MaKhachHang, mKH.FullName, mKH.NumberPhone);
		fclose(f);*/
	}
	else
		copyChar(k->info.MaKhachHang, moi.MaKhachHang);
	printf("Chon san pham de mua:\n");
	layNgayThangNamCuaHeThong_Char(moi.NgayBan);
	moi.cthd = taoChiTietHoaDon(HH,moi.TongTien);
	ghiCTHDMoiVaoFile(moi.MaHoaDon, moi.cthd);
	/*ghiHoaDonMoiVaoFile(moi);*/
	NodeHD*p = createNodeHD(moi);
	insertHeadHD(HD, p);
	printf("Chi tiet hoa don:\n");
	xuatCTHD(moi.cthd, HH);
	printf("\nThong tin hoa don:\n");
	Xuat1HoaDon(p);
}
void capNhatDuLieuVaoFile(SListHD HD, NodeHD *hd,SListKH KH,NodeKH*kh,SListHH HH,NodeHH*hh)
{
	if (HD.head != hd)
	{
		FILE*f = fopen("hoadon.txt", "r+");
		fseek(f, 0, SEEK_END);
		for (NodeHD*p = HD.head; p != hd;p=p->next)
			fprintf(f, "\n%s %s %s", p->info.MaHoaDon, p->info.MaKhachHang, p->info.NgayBan);
		fclose(f);
	}
	if (KH.head != kh)
	{
		FILE* f = fopen("khachhang.txt", "r+");
		fseek(f, 0, SEEK_END);
		for (NodeKH*p = KH.head; p != kh; p = p->next)
		fprintf(f, "\n%s %s %s", p->info.MaKhachHang, p->info.FullName, p->info.NumberPhone);
		fclose(f);
	}
	if (HH.head != hh)
	{
		FILE* f = fopen("hanghoa.txt", "r+");
		fseek(f, 0, SEEK_END);
		for (NodeHH*p = HH.head; p != hh; p = p->next)
		fprintf(f, "\n%s %s %s %.1f %.1f", p->info.MaHangHoa, p->info.TenSP, p->info.DonViTinh, p->info.GiaNhap, p->info.GiaBan);
		fclose(f);
	}
}