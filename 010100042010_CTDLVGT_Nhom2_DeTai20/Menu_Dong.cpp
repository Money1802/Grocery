#include "De20_DSLK.h"
#include "DoHoa.h"
#include<string>
#define TREN 'w'
#define DUOI 's'
#define TRAI 'a'
#define PHAI 'd'
#define ENTER 13
#define ESC 27
char batSkBanPhim()
{
	char c = getch();
	if (c == -32)
	{
		c = getch();
		if (c == 72 || c == 'w' || c == 'W')
			return TREN;
		else if (c == 80 || c == 's' || c == 'S')
			return DUOI;
		else if (c == 75 || c == 'a' || c == 'A')
			return TRAI;
		else if (c == 77 || c == 'd' || c == 'D')
			return PHAI;
	}
	else if (c == 13)
		return ENTER;
	else if (c == 27)
		return ESC;
}
void chaoMung()
{
	FILE*f = fopen("Hello.txt", "rt");
	while (!feof(f))
	{
		char s[1000];
		fgets(s, 1000, f);
		printf("%s", s);
	}
	getch();
}
int MENU(int x,int y, int w, int h, string menu[], int n, int mau_vien,int mau_chu)
{

	hop(x, y, w, h, "", mau_vien);
	for (int dem = 0, i = y+2; dem < n; dem++, i = i + 2)
	{
		hop(x+2, i, w-4, 1, menu[dem], mau_vien);
		if (dem > 0 && dem < n)
			fixGiuaTren(x + 2, i, w - 4, 1, mau_vien);
	}
	doiMauChu(x+2, y+2, w-4, 1, menu[0], mau_chu);
	int i = y+2, dem = 0;
	while (true)
	{
		ShowCur(0);
		int c;
		if (_kbhit())
		{
			char c = batSkBanPhim();
			if (c == 's'&&dem < n-1)
			{
				doiMauChu(x+2, i, w - 4, 1, menu[dem], mau_vien);
				i += 2;
				dem++;
				doiMauChu(x+2, i, w - 4, 1, menu[dem], mau_chu);
			}
			else if (c == 'w'&&dem > 0)
			{
				doiMauChu(x+2, i, w - 4, 1, menu[dem], mau_vien);
				i -= 2;
				dem--;
				doiMauChu(x+2, i, w - 4, 1, menu[dem], mau_chu);
			}
			else if (c == 13)
				return dem;
		}
	}
}
int hopLuuHanhDong(string s, string cauhoi)
{
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	int n = (80 - s.length()) / 2;
	gotoXY(20+n+1, 8);
	cout << s;
	hop(30, 11, 60, 10, "", 10);
	n = (60 - cauhoi.length())/2;
	gotoXY(30 + n+1, 13);
	cout << cauhoi;
	gotoXY(49, 14);
	cout << "Nhan enter de lua chon";
	hop(34, 17, 12, 1, "Luu", 11);
	hop(54, 17, 12, 1, "Khong luu", 11);
	hop(74, 17, 12, 1, "Tiep tuc", 11);
	hopKhongChu(34, 17, 12, 1, 14);
	int ix = 34, dem = 0;
	do
	{
		ShowCur(0);
		if (_kbhit())
		{
			char c = batSkBanPhim();
			if (c == 'd'&&dem < 2)
			{
				hopKhongChu(ix, 17, 12,1,11);
				ix += 20;
				dem++;
				hopKhongChu(ix, 17, 12, 1, 14);
			}
			else if (c == 'a'&&dem > 0)
			{
				hopKhongChu(ix, 17, 12, 1, 11);
				ix -= 20;
				dem--;
				hopKhongChu(ix, 17, 12, 1, 14);
			}
			else if (c == 13)
				return dem;
		}
	} while (true);
}
void them1HangHoa_dong(SListHH &l)
{
	int k;
	do
	{
		ShowCur(1);
		system("cls");
		hop(20, 5, 80, 23, "", 11);
		gotoXY(54, 8);
		printf("THEM HANG HOA MOI");
		HangHoa moi;
		taoMaHangHoaMoi(l, moi.MaHangHoa);
		hop(37, 10, 46, 1, "", 14);
		gotoXY(39, 11);
		printf("Nhap ten san pham: ");
		hop(37, 14, 46, 1, "", 14);
		gotoXY(39, 15);
		printf("Nhap don vi tinh: ");
		hop(37, 18, 46, 1, "", 14);
		gotoXY(39, 19);
		printf("Nhap gia nhap: ");
		hop(37, 22, 46, 1, "", 14);
		gotoXY(39, 23);
		printf("Nhap gia ban: ");
		textcolor(240);
		gotoXY(58, 11);
		scanf("%s", &moi.TenSP);
		gotoXY(58, 15);
		scanf("%s", &moi.DonViTinh);
		gotoXY(58, 19);
		scanf("%f", &moi.GiaNhap);
		gotoXY(58, 23);
		scanf("%f", &moi.GiaBan);
		insertHead(l, createNode(moi));
		textcolor(7);
		k = hopLuuHanhDong("THEM HANG HOA MOI", "Ban co muon luu lan thay doi nay khong?");
		if (k == 2||k==0)
			insertHead(l, createNode(moi));
	} while (k==2);
	system("cls");
}
void banHang_Dong(SListHD &HD, SListKH &KH, SListHH HH);
void taoMaHoaDonMoi(SListHD l, char ma[]);
void taoMaKhachHangMoi(SListKH KH, char ma[5]);
NodeHH* timHangHoa(SListHH HH, char ma[]);
NodeCTHD* kTMuaHangHoaDaTungMua(SListCTHD cthd, char ma[]);
NodeKH* kiemTraKhachHangDaTonTai(SListKH KH, char sdt[]);
void layNgayThangNamCuaHeThong_Char(char tg[]);
void ghiCTHDMoiVaoFile(char tenfile[], SListCTHD Moi);
SListCTHD taoChiTietHoaDon(SListHH HH, double& tong_tien);
void xuatCTHD(SListCTHD cthd, SListHH HH);
void copyChar(char a[], char cp[]);
float tinhTien1MonHang(CTHoaDon ct, SListHH HH);
double taoChiTietHoaDon_Dong(SListHH HH, SListCTHD &moi, char ma[])
{
	initSListCTHD(moi);
	double tong_tien = 0;
	do
	{
		CTHoaDon mHH;
		NodeHH* k;
		do
		{
			system("cls");
			gotoXY(51, 14);
			printf("Chon san pham de mua:");
			hop(20, 5, 80, 23, "", 11);
			gotoXY(58, 7);
			printf("BAN HANG");
			hopKhongChu(30, 8, 60, 17, 11);
			hop(37, 10, 46, 1, "", 14);
			gotoXY(39, 11);
			printf("Khach hang: ");
			textcolor(240);
			gotoXY(59, 11);
			printf("%s", ma);
			textcolor(7);
			gotoXY(42, 23);
			printf("Nhan enter de ket thuc 1 dong nhap lieu!");
			hopKhongChu(37, 20, 46, 1, 14);
			gotoXY(39, 21);
			printf("Nhap so luong: ");
			hopKhongChu(37, 16, 46, 1, 14);
			gotoXY(39, 17);
			printf("Nhap ma hang hoa: ");
			scanf("%s", &mHH.MaHangHoa);
			k = timHangHoa(HH, mHH.MaHangHoa);
			if (!k)
			{
				system("cls");
				hop(20, 5, 80, 23, "", 11);
				gotoXY(58, 7);
				printf("BAN HANG");
				hopKhongChu(30, 8, 60, 17, 11);
				hop(37, 10, 46, 1, "", 14);
				gotoXY(39, 11);
				printf("Khach hang: ");
				textcolor(240);
				gotoXY(59, 11);
				printf("%s", ma);
				textcolor(7);
				hopKhongChu(33, 13, 54, 6, 12);
				gotoXY(48, 15);
				textcolor(252);
				printf("MA HANG HOA KHONG TON TAI!");
				textcolor(7);
				gotoXY(47, 17);
				printf("Nhan phim 'ENTER' de nhap lai");
				gotoXY(46, 18);
				printf("hoac nhan'ESC' de huy don hang!");
				do
				{
					if (_kbhit())
					{
						char c = getch();
						if (c == 13)
						{
							k = 0;
							break;
						}
						else if (c == 27)
							return 0;
					}
				} while (true);
			}
		} while (!k);
		hopKhongChu(37, 20, 46, 1, 14);
		gotoXY(39, 21);
		printf("Nhap so luong: ");
		scanf("%d", &mHH.SoLuongBan);
		NodeCTHD*p = kTMuaHangHoaDaTungMua(moi, mHH.MaHangHoa);
		if (p != NULL)
			p->info.SoLuongBan += mHH.SoLuongBan;
		else
			insertHeadCTHD(moi, createNodeCTHD(mHH));
		tong_tien += mHH.SoLuongBan*k->info.GiaBan;
		system("cls");
		hop(20, 5, 80, 23, "", 11);
		gotoXY(58, 7);
		printf("BAN HANG");
		hopKhongChu(30, 8, 60, 17, 11);
		hop(37, 10, 46, 1, "", 14);
		gotoXY(39, 11);
		printf("Khach hang: ");
		textcolor(240);
		gotoXY(59, 11);
		printf("%s", ma);
		textcolor(7);
		hopKhongChu(33, 13, 54, 7, 13);
		gotoXY(43, 15);
		textcolor(11);
		printf("BAN CO MUON MUA THEM CAC SAN PHAM KHAC?");
		gotoXY(48, 17);
		printf("Tong tien hien tai: %.2f", tong_tien);
		textcolor(7);
		gotoXY(39, 18);
		printf("Nhan phim bat ki de tiep tuc mua them san pham!");
		gotoXY(44, 19);
		printf("Nhan phim 'ENTER' de ket thuc mua hang");
		while (true)
			if (_kbhit())
				if (getch() == 13)
					return tong_tien;
				else
					break;
	} while (true);
}
void Xuat1HoaDon_Dong(NodeHD* d, int x, int y)
{
	gotoXY(x, y++);
	printf("--------------------------------------------------------------");
	gotoXY(x, y++);
	printf("| Ma hoa don | Ma khach hang |   Ngay ban   |    Tong tien   |");
	gotoXY(x, y++);
	printf("|   %6s   |    %7s    |  %10s  | %12.2f   |",d->info.MaHoaDon,d->info.MaKhachHang,d->info.NgayBan,d->info.TongTien);
	gotoXY(x, y++);
	printf("--------------------------------------------------------------");
}
void cuonCTHD(CTHoaDon a[],int vt)
{
	textcolor(7);
	int j = 17;
	for (int i = vt; i < vt + 10; i++)
	{
		gotoXY(43, j++);
		printf("   %7s   | %6d   |   %7.2f", a[i].MaHangHoa, a[i].SoLuongBan, a[i].ThanhTien);
	}
}
void diChuyenCTHD(SListCTHD cthd, SListHH HH)
{
	int i = 17, sl = 0;
	CTHoaDon a[100];
	for (NodeCTHD*p = cthd.head; p != NULL; p = p->next)
	{
		if (i - 17 < 11)
		{
			gotoXY(43, i++);
			printf("   %7s   | %6d   |   %7.2f", p->info.MaHangHoa, p->info.SoLuongBan, tinhTien1MonHang(p->info, HH));
		}
		a[sl] = p->info;
		a[sl].ThanhTien = tinhTien1MonHang(a[sl], HH);
		sl++;
	}
	gotoXY(43, 17);
	textcolor(47);
	printf("   %7s   | %6d   |   %7.2f  ", a[0].MaHangHoa, a[0].SoLuongBan, a[0].ThanhTien);
	i = 17;
	int vt = 0, cuon = 0,k = 0;
	while (true)
	{
		ShowCur(0);
		int c;
		if (_kbhit())
		{
			char c = batSkBanPhim();
			if (c == 's'&&vt < sl-1&&k==0)
			{
				gotoXY(43, i++);
				textcolor(7);
				printf("   %7s   | %6d   |   %7.2f  ", a[vt].MaHangHoa, a[vt].SoLuongBan, a[vt].ThanhTien);
				gotoXY(43, i);
				vt++;
				textcolor(47);
				printf("   %7s   | %6d   |   %7.2f  ", a[vt].MaHangHoa, a[vt].SoLuongBan, a[vt].ThanhTien);
				if (i == 27)
					k = 1;
			}
			else if (c == 'w'&& vt >0&&i>17)
			{
				gotoXY(43, i--);
				textcolor(7);
				printf("   %7s   | %6d   |   %7.2f  ", a[vt].MaHangHoa, a[vt].SoLuongBan, a[vt].ThanhTien);
				gotoXY(43, i);
				vt--;
				textcolor(47);
				printf("   %7s   | %6d   |   %7.2f  ", a[vt].MaHangHoa, a[vt].SoLuongBan, a[vt].ThanhTien);
				k = 0;
			}
			else if(sl>10&& vt >= 10 && c=='s'&&vt<sl-1&&i==27)
			{
				cuonCTHD(a, ++cuon);
				vt++;
				gotoXY(43, i);
				textcolor(47);
				printf("   %7s   | %6d   |   %7.2f  ", a[vt].MaHangHoa, a[vt].SoLuongBan, a[vt].ThanhTien);
				if (vt == sl - 1)
					k = 0;
			}
			else if (c == 'w'&&vt > 0 && i == 17)
			{
				cuonCTHD(a, --cuon);
				vt--;
				gotoXY(43, i);
				textcolor(47);
				printf("   %7s   | %6d   |   %7.2f  ", a[vt].MaHangHoa, a[vt].SoLuongBan, a[vt].ThanhTien);
			}
			else if (c == 13)
				return;
		}
	}
}
void xuatCTHD_Dong(SListCTHD cthd, SListHH HH)
{
	gotoXY(54, 15);
	printf("Chi tiet hoa don");
	gotoXY(43, 16);
	printf(" Ma hang hoa | So luong | Thanh tien ");
	diChuyenCTHD(cthd, HH);
}
void banHang_Dong(SListHD &HD, SListKH &KH, SListHH HH)
{
	ShowCur(1);
	HoaDon moi;
	KhachHang mKH;
	taoMaHoaDonMoi(HD, moi.MaHoaDon);
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(30, 8, 60, 17, 11);
	gotoXY(58, 7);
	printf("BAN HANG");
	gotoXY(42, 23);
	printf("Nhan enter de ket thuc 1 dong nhap lieu!");
	gotoXY(51, 14);
	printf("Chon san pham de mua:");
	hop(37, 10, 46, 1, "", 14);
	gotoXY(39, 11);
	printf("Nhap so dien thoai: ");
	hopKhongChu(37, 16, 46, 1, 14);
	gotoXY(39, 17);
	printf("Nhap ma hang hoa: ");
	hopKhongChu(37, 20, 46, 1, 14);
	gotoXY(39, 21);
	printf("Nhap so luong: ");
	do
	{
		gotoXY(59, 11);
		printf("                         ");
		gotoXY(59, 11);
		textcolor(240);
		gotoXY(59, 11);
		scanf("%s", &mKH.NumberPhone);
		if (strlen(mKH.NumberPhone) < 10 || strlen(mKH.NumberPhone) > 10)
		{
			gotoXY(37, 13);
			textcolor(12);
			printf("*Dinh dang so dien thoai chua chinh xac! (10 chu so)");
			textcolor(7);
		}
		else
			break;
	} while (true);
	textcolor(7);
	NodeKH *k = kiemTraKhachHangDaTonTai(KH, mKH.NumberPhone);
	if (k == NULL)
	{
		system("cls");
		hop(20, 5, 80, 23, "", 11);
		gotoXY(58, 7);
		printf("BAN HANG");
		hopKhongChu(30, 10, 60, 12, 14);
		gotoXY(51, 12);
		printf("Day la khach hang moi!");
		gotoXY(48, 13);
		printf("Tao thong tin khach hang moi");
		gotoXY(43, 20);
		printf("Nhan phim 'ENTER' de luu khach hang moi!");
		hopKhongChu(35, 16, 50, 1, 11);
		gotoXY(37, 17);
		printf("Ho va ten: ");
		textcolor(240);
		scanf("%s", &mKH.FullName);
		textcolor(7);
		taoMaKhachHangMoi(KH, mKH.MaKhachHang);
		copyChar(mKH.MaKhachHang, moi.MaKhachHang);
		insertHeadKH(KH, createNodeKH(mKH));
	}
	else
	{
		copyChar(k->info.MaKhachHang, moi.MaKhachHang);
		copyChar(k->info.FullName, mKH.FullName);
	}
	textcolor(7);
	gotoXY(51, 14);
	printf("Chon san pham de mua:");
	layNgayThangNamCuaHeThong_Char(moi.NgayBan);
	int discount;
	moi.TongTien = taoChiTietHoaDon_Dong(HH, moi.cthd, mKH.FullName);
	if (moi.TongTien == 0)
	{
		textcolor(7);
		return;
	}
	if (moi.TongTien >= 200000)
	{
		moi.TongTien = moi.TongTien / 100 * 95;
		discount = 5;
	}
	else
		discount = 0;
	ghiCTHDMoiVaoFile(moi.MaHoaDon, moi.cthd);
	NodeHD*p = createNodeHD(moi);
	insertHeadHD(HD, p);
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(29, 8, 62, 19, 11);
	gotoXY(58, 7);
	printf("BAN HANG");
	gotoXY(47, 9);
	printf("HOA DON DA DUOC TAO THANH CONG!");
	/*gotoXY(54, 10);
	printf("Thong tin hoa don");*/
	gotoXY(38, 10);
	printf("Thong tin hoa don:                 Discount: %2d",discount);
	Xuat1HoaDon_Dong(p, 31, 11);
	xuatCTHD_Dong(moi.cthd, HH);
	textcolor(7);
}
void xuatAllHD_tongTienMax_Dong(SListHD HD)
{
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	if (isEmptyHD(HD))
	{
		hopKhongChu(33, 13, 54, 6, 12);
		gotoXY(49, 15);
		textcolor(252);
		cout << "DANH SACH HOA DON RONG!";
		textcolor(7);
		gotoXY(42, 17);
		printf("Nhan phim bat ki de quay ve MENU chinh");
		getch();
		return;
	}
	double tongTienMax = HD.head->info.TongTien;
	for (NodeHD *p = HD.head->next; p != NULL; p = p->next)
	{
		if (tongTienMax < p->info.TongTien)
			tongTienMax = p->info.TongTien;
	}
	gotoXY(40, 7);
	textcolor(27);
	printf("Hoa don co tong tien cao nhat: %7.2f", tongTienMax);
	textcolor(7);
	gotoXY(54, 10);
	printf("Thong tin hoa don");
	int y = 11;
	for (NodeHD *p = HD.head; p != NULL; p = p->next)
	{

		if (tongTienMax == p->info.TongTien)
		{
			Xuat1HoaDon_Dong(p, 31, y);
			y += 3;
		}
	}
	getch();
}
int tim_XuatHDVaCTHD_duaVaoSoHD_Dong(SListHD HD,SListHH HH, char soHD[7])
{

	//-----------------------------------------------

	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(29, 8, 62, 19, 11);
	if (isEmptyHD(HD))
	{
		hopKhongChu(33, 13, 54, 6, 12);
		gotoXY(49, 15);
		textcolor(252);
		cout << "DANH SACH HOA DON RONG!";
		textcolor(7);
		gotoXY(42, 17);
		printf("Nhan phim bat ki de quay ve MENU chinh");
		getch();
		return 0;
	}
	for (NodeHD *p = HD.head; p != NULL; p = p->next)
	{
		char so[7];
		if (strcmpi(soHD, p->info.MaHoaDon) == 0)
		{
			gotoXY(54, 10);
			printf("Thong tin hoa don");
			Xuat1HoaDon_Dong(p, 31, 11);
			xuatCTHD_Dong(p->info.cthd,HH);
			return 1;
		}
	}

	hopKhongChu(33, 13, 54, 6, 12);
	gotoXY(46, 15);
	textcolor(180);
	printf("KHONG TON TAI HOA DON %s",soHD);
	textcolor(7);
	gotoXY(42, 17);
	printf("Nhan phim bat ki de quay ve MENU chinh");
	getch();
	return 0;

}
void MenuMuc6(SListHD HD,SListHH HH)
{
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(30, 8, 60, 17, 11);
	gotoXY(54, 7);
	printf("TIM KIEM HOA DON");
	hop(37, 10, 46, 1, "", 14);
	gotoXY(39, 11);
	char soHD[7];
	printf("Nhap so hoa don: ");
	scanf("%s", &soHD);
	tim_XuatHDVaCTHD_duaVaoSoHD_Dong(HD,HH, soHD);
}
void cuonHD(HoaDon a[], int vt)
{
	textcolor(7);
	int j = 13;
	for (int i = vt; i < vt + 15; i++)
	{
		gotoXY(31, j++);
		printf("|   %6s   |    %7s    |  %10s  |  %11.2f   |", a[i].MaHoaDon, a[i].MaKhachHang, a[i].NgayBan, a[i].TongTien);
	}
}
void xuatTapHopHoaDon_Dong(HoaDon a[], int dem)
{
	int i = 13;
	for (int ii = 0; ii < dem; ii++)
	{
		if (ii > 14)
			break;
		gotoXY(31, i++);
		printf("|   %6s   |    %7s    |  %10s  |  %11.2f   |", a[ii].MaHoaDon, a[ii].MaKhachHang, a[ii].NgayBan, a[ii].TongTien);
	}
	int sl = dem;
	gotoXY(31, 13);
	textcolor(47);
	printf("|   %6s   |    %7s    |  %10s  |  %11.2f   |", a[0].MaHoaDon, a[0].MaKhachHang, a[0].NgayBan, a[0].TongTien);
	i = 13;
	int vt = 0, cuon = 0, k = 0;
	while (true)
	{
		ShowCur(0);
		if (_kbhit())
		{
			char c = batSkBanPhim();
			if (c == 's'&&vt < sl - 1 && k == 0)
			{
				gotoXY(31, i++);
				textcolor(7);
				printf("|   %6s   |    %7s    |  %10s  |  %11.2f   |", a[vt].MaHoaDon, a[vt].MaKhachHang, a[vt].NgayBan, a[vt].TongTien);
				gotoXY(31, i);
				vt++;
				textcolor(47);
				printf("|   %6s   |    %7s    |  %10s  |  %11.2f   |", a[vt].MaHoaDon, a[vt].MaKhachHang, a[vt].NgayBan, a[vt].TongTien);
				if (i == 27)
					k = 1;
			}
			else if (c == 'w'&& vt >0 && i>13)
			{
				gotoXY(31, i--);
				textcolor(7);
				printf("|   %6s   |    %7s    |  %10s  |  %11.2f   |", a[vt].MaHoaDon, a[vt].MaKhachHang, a[vt].NgayBan, a[vt].TongTien);
				gotoXY(31, i);
				vt--;
				textcolor(47);
				printf("|   %6s   |    %7s    |  %10s  |  %11.2f   |", a[vt].MaHoaDon, a[vt].MaKhachHang, a[vt].NgayBan, a[vt].TongTien);
				k = 0;
			}
			else if (sl>10 && vt >= 10 && c == 's'&&vt<sl - 1 && i == 27)
			{
				cuonHD(a, ++cuon);
				vt++;
				gotoXY(31, i);
				textcolor(47);
				printf("|   %6s   |    %7s    |  %10s  |  %11.2f   |", a[vt].MaHoaDon, a[vt].MaKhachHang, a[vt].NgayBan, a[vt].TongTien);
				if (vt == sl - 1)
					k = 0;
			}
			else if (c == 'w'&&vt > 0 && i == 13)
			{
				cuonHD(a, --cuon);
				vt--;
				gotoXY(31, i);
				textcolor(47);
				printf("|   %6s   |    %7s    |  %10s  |  %11.2f   |", a[vt].MaHoaDon, a[vt].MaKhachHang, a[vt].NgayBan, a[vt].TongTien);
			}
			else if (c == 13)
				return;
		}
	}
}
int lietKeHD_duaVaoMaKH_Dong(SListHD HD, char maKH[50])
{
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(29, 8, 62, 19, 11);
	gotoXY(47, 7);
	printf("TIM KIEM CAC HOA DON CUA KHACH");
	if (isEmptyHD(HD))
	{
		hopKhongChu(33, 13, 54, 6, 12);
		gotoXY(49, 15);
		textcolor(252);
		cout << "DANH SACH HOA DON RONG!";
		textcolor(7);
		gotoXY(42, 17);
		printf("Nhan phim bat ki de quay ve MENU chinh");
		getch();
		return 0;
	}
	int dem = 0;
	HoaDon a[100];
	for (NodeHD *p = HD.head; p != NULL; p = p->next)
	{
		if (strcmpi(p->info.MaKhachHang, maKH) == 0)
			a[dem++] = p->info;
	}
	if (dem == 0)
	{
		gotoXY(54, 10);
		printf("Thong tin hoa don");
		hopKhongChu(33, 13, 54, 6, 12);
		gotoXY(44, 15);
		textcolor(252);
		printf("MA KHACH HANG %s KHONG TON TAI!", maKH);
		textcolor(7);
		gotoXY(42, 17);
		printf("Nhan phim bat ki de quay ve MENU chinh");
		getch();
		return 0;
	}
	else
	{
		gotoXY(37, 10);
		printf("Thong tin hoa don");
		gotoXY(73, 10);
		printf("So luong: %d", dem);
		gotoXY(31, 12);
		printf("| Ma hoa don | Ma khach hang |   Ngay ban   |    Tong tien   |");
		xuatTapHopHoaDon_Dong(a, dem);
		return 1;
	}
}
void MenuMuc7(SListHD HD)
{
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(30, 8, 60, 17, 11);
	gotoXY(47, 7);
	printf("TIM KIEM CAC HOA DON CUA KHACH");
	hop(37, 10, 46, 1, "", 14);
	gotoXY(39, 11);
	char maKH[50];
	printf("Nhap ma khach hang: ");
	scanf("%s", &maKH);
	lietKeHD_duaVaoMaKH_Dong(HD, maKH);
	getch();
}
void xuatHoaDon_Dong(SListHD HD)
{
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(30, 8, 60, 19, 11);
	HoaDon a[1000];
	int n = 0;
	for (NodeHD *p = HD.head; p != NULL; p = p->next)
		a[n++] = p->info;
	gotoXY(54, 10);
	printf("DANH SACH HOA DON");
	gotoXY(31, 12);
	printf("| Ma hoa don | Ma khach hang |   Ngay ban   |    Tong tien   |");
	int y = 13;
	xuatTapHopHoaDon_Dong(a,n);
}
void cuonKH(KhachHang a[], int vt, int k)
{
	textcolor(7);
	int j = 10;
	for (int i = vt; i < vt + 18; i++)
	{
		gotoXY(22, j++);
		printf("|    %6s     |  %30s              |   %10s  |", a[i].MaKhachHang, a[i].FullName, a[i].NumberPhone);
		/*printf("|    %6s     |", a[i].MaKhachHang);
		if (k == 0)
			doiMauChu(38, j+1, 44, 1, a[i].FullName, 7);
		else
			doiMauChu(38, j-1, 44, 1, a[i].FullName, 7);
		printf("|  %11s  |", a[i].NumberPhone);*/
	}
}
void xuatKhachHang_Dong(SListKH KH)
{
	int n = 0;
	KhachHang a[1000];
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(21, 8, 78, 19, 11);
	gotoXY(50, 7);
	printf("DANH SACH KHACH HANG");
	int i = 10;
	for (NodeKH *p = KH.head; p != NULL; p = p->next)
	{
		if (n < 18)
		{
			gotoXY(22, i++);
			printf("|    %6s     |  %30s              |   %10s  |", p->info.MaKhachHang, p->info.FullName, p->info.NumberPhone);
			/*printf("|    %6s     |", p->info.MaKhachHang);
			doiMauChu(38, i-2, 44, 1, p->info.FullName, 7);
			printf("|  %11s  |", p->info.NumberPhone);*/
		}
		a[n++] = p->info;
	}
	gotoXY(22, 9);
	printf("| Ma khach hang |                  Ho va Ten                   | So dien thoai |");
	gotoXY(22,10);
	textcolor(47);
	printf("|    %6s     |  %30s              |   %10s  |", a[0].MaKhachHang, a[0].FullName, a[0].NumberPhone);
	/*printf("|    %6s     |",a[0].MaKhachHang);
	doiMauChu(38, 9, 44, 1, a[0].FullName, 47);
	printf("|  %11s  |",a[0].NumberPhone);*/
	
	int vt = 0, cuon = 0, k = 0, sl = n;
	i = 10;
	while (true)
	{
		ShowCur(0);
		int c;
		if (_kbhit())
		{
			gotoXY(0,12 );
			char c = batSkBanPhim();
			if (c == 's'&&vt < sl - 1 && k == 0)
			{
				gotoXY(22, i++);
				textcolor(7);
				/*printf("|    %6s     |", a[vt].MaKhachHang);
				doiMauChu(38, i-2, 44, 1, a[vt].FullName, 7);
				printf("|  %11s  |", a[vt].NumberPhone);*/
				printf("|    %6s     |  %30s              |   %10s  |", a[vt].MaKhachHang, a[vt].FullName, a[vt].NumberPhone);
				gotoXY(22, i);
				vt++;
				textcolor(47);
				/*printf("|    %6s     |", a[vt].MaKhachHang);
				doiMauChu(38, i - 1, 44, 1, a[vt].FullName, 47);
				textcolor(47);
				printf("|  %11s  |", a[vt].NumberPhone);*/
				printf("|    %6s     |  %30s              |   %10s  |", a[vt].MaKhachHang, a[vt].FullName, a[vt].NumberPhone);
				if (i == 27)
					k = 1;
			}
			else if (c == 'w'&& vt >0 && i>10)
			{
				gotoXY(22, i--);
				textcolor(7);
				/*printf("|    %6s     |", a[vt].MaKhachHang);
				doiMauChu(38, i, 44, 1, a[vt].FullName, 7);
				printf("|  %11s  |", a[vt].NumberPhone);*/
				printf("|    %6s     |  %30s              |   %10s  |", a[vt].MaKhachHang, a[vt].FullName, a[vt].NumberPhone);
				gotoXY(22, i);
				vt--;
				textcolor(47);
				/*printf("|    %6s     |", a[vt].MaKhachHang);
				doiMauChu(38, i - 1, 44, 1, a[vt].FullName, 47);
				textcolor(47);
				printf("|  %11s  |", a[vt].NumberPhone);*/
				printf("|    %6s     |  %30s              |   %10s  |", a[vt].MaKhachHang, a[vt].FullName, a[vt].NumberPhone);
				k = 0;
			}
			else if (sl>17 && vt >= 17 && c == 's'&&vt<sl - 1 && i == 27)
			{
				cuonKH(a, ++cuon,1);
				vt++;
				gotoXY(22, i);
				textcolor(47);
				/*printf("|    %6s     |", a[vt].MaKhachHang);
				doiMauChu(38, i-1, 44, 1, a[vt].FullName, 47);
				textcolor(47);
				printf("|  %11s  |", a[vt].NumberPhone);*/
				printf("|    %6s     |  %30s              |   %10s  |", a[vt].MaKhachHang, a[vt].FullName, a[vt].NumberPhone);
				if (vt == sl - 1)
					k = 0;
			}
			else if (c == 'w'&&vt > 0 && i == 10)
			{
				cuonKH(a, --cuon,0);
				vt--;
				gotoXY(22, i);
				textcolor(47);
				/*printf("|    %6s     |", a[vt].MaKhachHang);
				doiMauChu(38, i-1, 44, 1, a[vt].FullName, 47);
				textcolor(47);
				printf("|  %11s  |", a[vt].NumberPhone);*/
				printf("|    %6s     |  %30s              |   %10s  |", a[vt].MaKhachHang, a[vt].FullName, a[vt].NumberPhone);
			}
			else if (c == 13)
				return;
		}
	}
}
void cuonHH(HangHoa a[], int vt)
{
	textcolor(7);
	int j = 10;
	for (int i = vt; i < vt + 18; i++)
	{
		gotoXY(22, j++);
		printf("|   %6s    |%25s    | %6s |%10.2f  | %9.2f  |", a[i].MaHangHoa, a[i].TenSP, a[i].DonViTinh, a[i].GiaNhap, a[i].GiaBan);
	}
}
void xuatHangHoa_Dong(SListHH HH)
{
	int n = 0;
	HangHoa a[1000];
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(21, 8, 78, 19, 11);
	gotoXY(52, 7);
	printf("DANH SACH HANG HOA");
	int i = 10;
	for (NodeHH *p = HH.head; p != NULL; p = p->next)
	{
		if (n < 18)
		{
			gotoXY(22, i++);
			printf("|   %6s    |%25s    | %6s |%10.2f  | %9.2f  |", p->info.MaHangHoa, p->info.TenSP, p->info.DonViTinh, p->info.GiaNhap, p->info.GiaBan);
		}
		a[n++] = p->info;
	}
	gotoXY(22, 9);
	printf("| Ma hang hoa |         Ten san pham        | Don vi |  Gia nhap  |  Gia ban   |");
	gotoXY(22, 10);
	textcolor(47);
	printf("|   %6s    |%25s    | %6s |%10.2f  | %9.2f  |", a[0].MaHangHoa, a[0].TenSP, a[0].DonViTinh,a[0].GiaNhap,a[0].GiaBan);
	int vt = 0, cuon = 0, k = 0, sl = n;
	i = 10;
	while (true)
	{
		ShowCur(0);
		int c;
		if (_kbhit())
		{
			gotoXY(0, 12);
			char c = batSkBanPhim();
			if (c == 's'&&vt < sl - 1 && k == 0)
			{
				gotoXY(22, i++);
				textcolor(7);
				printf("|   %6s    |%25s    | %6s |%10.2f  | %9.2f  |", a[vt].MaHangHoa, a[vt].TenSP, a[vt].DonViTinh, a[vt].GiaNhap, a[vt].GiaBan);
				gotoXY(22, i);
				vt++;
				textcolor(47);
				printf("|   %6s    |%25s    | %6s |%10.2f  | %9.2f  |", a[vt].MaHangHoa, a[vt].TenSP, a[vt].DonViTinh, a[vt].GiaNhap, a[vt].GiaBan);
				if (i == 27)
					k = 1;
			}
			else if (c == 'w'&& vt >0 && i>10)
			{
				gotoXY(22, i--);
				textcolor(7);
				printf("|   %6s    |%25s    | %6s |%10.2f  | %9.2f  |", a[vt].MaHangHoa, a[vt].TenSP, a[vt].DonViTinh, a[vt].GiaNhap, a[vt].GiaBan);
				gotoXY(22, i);
				vt--;
				textcolor(47);
				printf("|   %6s    |%25s    | %6s |%10.2f  | %9.2f  |", a[vt].MaHangHoa, a[vt].TenSP, a[vt].DonViTinh, a[vt].GiaNhap, a[vt].GiaBan);
				k = 0;
			}
			else if (sl>17 && vt >= 17 && c == 's'&&vt<sl - 1 && i == 27)
			{
				cuonHH(a, ++cuon);
				vt++;
				gotoXY(22, i);
				textcolor(47);
				printf("|   %6s    |%25s    | %6s |%10.2f  | %9.2f  |", a[vt].MaHangHoa, a[vt].TenSP, a[vt].DonViTinh, a[vt].GiaNhap, a[vt].GiaBan);
				if (vt == sl - 1)
					k = 0;
			}
			else if (c == 'w'&&vt > 0 && i == 10)
			{
				cuonHH(a, --cuon);
				vt--;
				gotoXY(22, i);
				textcolor(47);
				printf("|   %6s    |%25s    | %6s |%10.2f  | %9.2f  |", a[vt].MaHangHoa, a[vt].TenSP, a[vt].DonViTinh, a[vt].GiaNhap, a[vt].GiaBan);
			}
			else if (c == 13)
				return;
		}
	}
}
void doanhThuNgay_Dong(char day[11],SListHD lhd)
{
	double Tong = 0;
	HoaDon a[100];
	int n = 0;
	for (NodeHD *p = lhd.head; p != NULL; p = p->next)
	{
		if (strcmp(day, p->info.NgayBan) == 0)
		{
			a[n++] = p->info;
			Tong += p->info.TongTien;
		}
	}
	if (Tong == 0)
	{
		hopKhongChu(33, 13, 54, 6, 12);
		gotoXY(48, 15);
		gotoXY(45, 15);
		textcolor(252);
		printf("NGAY %s KHONG CO DOANH THU", day);
		gotoXY(49, 16);
		printf("HOAC NGAY NAY KHONG TON TAI");
		textcolor(7);
		gotoXY(47, 18);
		printf("Nhan phim bat ki de thoat!");
		getch();
	}
	else
	{
		hop(37, 10, 46, 1, "", 0);
		gotoXY(38, 11);
		printf("                                    ");
		gotoXY(27, 10);
		printf("Thong tin hoa don");
		gotoXY(55, 10);
		textcolor(27);
		printf("Tong doanh thu ngay %s: %.0f", day, Tong);
		textcolor(7);
		gotoXY(31, 12);
		printf("| Ma hoa don | Ma khach hang |   Ngay ban   |    Tong tien   |");
		gotoXY(44, 13);
		xuatTapHopHoaDon_Dong(a, n);
	}
}
void doanhThuTheoNgay_Dong(SListHD HD)
{
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(21, 8, 78, 19, 11);
	gotoXY(47, 7);
	printf("THONG KE DOANH THU THEO NGAY");
	char day[11];
	double Tong = 0;
	hop(37, 10, 46, 1, "", 14);
	gotoXY(39, 11);
	printf("Nhap ngay/thang/nam: ");
	scanf("%s", &day);
	doanhThuNgay_Dong(day, HD);
}
int kiemTraNam(SListHD lhd, int Year);
struct datta
{
	int ngay, thang, nam;
};
datta layNgayThangNamHeThong()
{ 
	datta a;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	ltm->tm_year += 1900;
	ltm->tm_mon += 1;
	a.nam = ltm->tm_year;
	a.thang = ltm->tm_mon;
	a.ngay = ltm->tm_mday;
	return a;
}
void doanhThuTheoThang_Dong(SListHD lhd)
{
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(21, 8, 78, 19, 11);
	gotoXY(47, 7);
	datta a = layNgayThangNamHeThong();
	printf("THONG KE DOANH THU THEO THANG");
	int Month;
	hop(37, 10, 46, 1, "", 14);
	hop(37, 15, 46, 1, "", 14);
	gotoXY(39, 16);
	printf("Nhap nam: ");
	double Tong = 0;
	do
	{
		gotoXY(39, 11);
		printf("                       ");
		gotoXY(39, 11);
		printf("Nhap thang: ");
		cin >> Month;
		if (Month < 1 || Month > 12)
		{
			gotoXY(39, 13);
			textcolor(12);
			printf("*Thang khong ton tai, hay nhap lai!");
			textcolor(7);
		}
	} while (Month < 1 || Month > 12);
	gotoXY(39, 13);
	printf("                                           ");
	int Year;
	do
	{
		gotoXY(49, 16);
		printf("               ");
		gotoXY(49, 16);
		cin >> Year;
		if (Year < 1 || Year > a.nam)
		{
			gotoXY(39, 18);
			textcolor(12);
			printf("*Nam khong ton tai, hay nhap lai!");
			textcolor(7);
		}
	} while (Year < 1 || Year > a.nam);
	gotoXY(39, 18);
	printf("                                           ");
	HoaDon h[100];
	int n = 0;
	for (NodeHD *p = lhd.head; p != NULL; p = p->next)
	{
		if (Month == Thang(p->info.NgayBan) && Year == Nam(p->info.NgayBan))
		{
			h[n++] = p->info;
			Tong += p->info.TongTien;
		}
	}
	hop(37, 15, 46, 1, "", 0);
	gotoXY(38, 16);
	printf("                          ");
	hop(37, 10, 46, 1, "", 0);
	gotoXY(38, 11);
	printf("                                    ");
	if (Tong == 0)
	{
		hopKhongChu(33, 13, 54, 6, 12);
		gotoXY(48, 15);
		gotoXY(45, 15);
		textcolor(252);
		printf("THANG %d NAM %d KHONG CO DOANH THU",Month, Year);
		gotoXY(49, 16);
		printf("HOAC THOI GIAN KHONG TON TAI");
		textcolor(7);
		gotoXY(49, 18);
		printf("Nhan phim bat ki de thoat!");
		getch();
	}
	else
	{
		hop(37, 10, 46, 1, "", 0);
		gotoXY(38, 11);
		printf("                                    ");
		gotoXY(25, 10);
		printf("Thong tin hoa don");
		gotoXY(60, 10);
		textcolor(27);
		printf("Tong doanh thu thang %d nam %d: %.0f", Month, Year, Tong);
		textcolor(7);
		gotoXY(31, 12);
		printf("| Ma hoa don | Ma khach hang |   Ngay ban   |    Tong tien   |");
		gotoXY(44, 13);
		xuatTapHopHoaDon_Dong(h, n);
	}
}
void doanhThuTheoNam_Dong(SListHD lhd)
{
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(21, 8, 78, 19, 11);
	gotoXY(47, 7);
	datta a = layNgayThangNamHeThong();
	printf("THONG KE DOANH THU THEO NAM");
	hop(37, 10, 46, 1, "", 14);
	gotoXY(39, 11);
	printf("Nhap nam: ");
	int Year;
	double Tong = 0;
	do
	{
		gotoXY(49, 11);
		printf("               ");
		gotoXY(49, 11);
		cin >> Year;
		if (Year < 1 || Year > a.nam)
		{
			gotoXY(39, 13);
			textcolor(12);
			printf("*Nam khong ton tai, hay nhap lai!");
			textcolor(7);
		}
	} while (Year < 1 || Year > a.nam);
	gotoXY(39, 13);
	printf("                                        ");
	HoaDon h[100];
	int n = 0;
	for (NodeHD *p = lhd.head; p != NULL; p = p->next)
	{
		if (Year == Nam(p->info.NgayBan))
		{
			Tong += p->info.TongTien;
			h[n++] = p->info;
		}
	}
	hop(37, 15, 46, 1, "", 0);
	gotoXY(38, 16);
	printf("                          ");
	hop(37, 10, 46, 1, "", 0);
	gotoXY(38, 11);
	printf("                                    ");
	if (Tong == 0)
	{
		hopKhongChu(33, 13, 54, 6, 12);
		gotoXY(48, 15);
		gotoXY(51, 15);
		textcolor(252);
		printf("NAM %d KHONG CO DOANH THU", Year);
		gotoXY(49, 16);
		printf("HOAC THOI GIAN KHONG TON TAI");
		textcolor(7);
		gotoXY(49, 18);
		printf("Nhan phim bat ki de thoat!");
		getch();
	}
	else
	{
		hop(37, 10, 46, 1, "", 0);
		gotoXY(38, 11);
		printf("                                    ");
		gotoXY(31, 10);
		printf("Thong tin hoa don");
		gotoXY(60, 10);
		textcolor(27);
		printf("Tong doanh thu nam %d: %.0f", Year, Tong);
		textcolor(7);
		gotoXY(31, 12);
		printf("| Ma hoa don | Ma khach hang |   Ngay ban   |    Tong tien   |");
		gotoXY(44, 13);
		xuatTapHopHoaDon_Dong(h, n);
	}
}
void doanhThuTheoQuy_Dong(SListHD lhd)
{
	system("cls");
	hop(20, 5, 80, 23, "", 11);
	hopKhongChu(21, 8, 78, 19, 11);
	gotoXY(47, 7);
	datta a = layNgayThangNamHeThong();
	printf("THONG KE DOANH THU THEO THANG");
	int quy;
	hop(37, 10, 46, 1, "", 14);
	hop(37, 15, 46, 1, "", 14);
	gotoXY(39, 16);
	printf("Nhap nam: ");
	double Tong = 0;
	do
	{
		gotoXY(39, 11);
		printf("                       ");
		gotoXY(39, 11);
		printf("Nhap quy: ");
		cin >> quy;
		if (quy < 1 || quy > 4)
		{
			gotoXY(39, 13);
			textcolor(12);
			printf("*Khong ton tai quy %d, hay nhap lai!",quy);
			textcolor(7);
		}
	} while (quy < 1 || quy > 4);
	gotoXY(39, 13);
	printf("                                                        ");
	int Year;
	do
	{
		gotoXY(49, 16);
		printf("               ");
		gotoXY(49, 16);
		cin >> Year;
		if (Year < 1 || Year > a.nam)
		{
			gotoXY(39, 18);
			textcolor(12);
			printf("*Nam khong ton tai, hay nhap lai!");
			textcolor(7);
		}
	} while (Year < 1 || Year > a.nam);
	gotoXY(39, 18);
	printf("                                       ");
	HoaDon h[100];
	int n = 0;
	for (NodeHD *p = lhd.head; p != NULL; p = p->next)
	{
		if (quy * 3 >= Thang(p->info.NgayBan) &&quy * 3 - 2 <= Thang(p->info.NgayBan)&&Year == Nam(p->info.NgayBan))
		{
			h[n++] = p->info;
			Tong += p->info.TongTien;
		}
	}
	hop(37, 15, 46, 1, "", 0);
	gotoXY(38, 16);
	printf("                          ");
	hop(37, 10, 46, 1, "", 0);
	gotoXY(38, 11);
	printf("                                    ");
	if (Tong == 0)
	{
		hopKhongChu(33, 13, 54, 6, 12);
		gotoXY(48, 15);
		gotoXY(45, 15);
		textcolor(252);
		printf(" QUY %d NAM %d KHONG CO DOANH THU", quy, Year);
		gotoXY(49, 16);
		printf("HOAC THOI GIAN KHONG TON TAI");
		textcolor(7);
		gotoXY(49, 18);
		printf("Nhan phim bat ki de thoat!");
		getch();
	}
	else
	{
		hop(37, 10, 46, 1, "", 0);
		gotoXY(38, 11);
		printf("                                    ");
		gotoXY(25, 10);
		printf("Thong tin hoa don");
		gotoXY(60, 10);
		textcolor(27);
		printf("Tong doanh thu quy %d nam %d: %.0f", quy, Year, Tong);
		textcolor(7);
		gotoXY(31, 12);
		printf("| Ma hoa don | Ma khach hang |   Ngay ban   |    Tong tien   |");
		gotoXY(44, 13);
		xuatTapHopHoaDon_Dong(h, n);
	}
}
void tenTiem(int mau)
{
	doiMauChu(53,3, 14, 1, "TAP HOA CHI CA", mau);
}
void main()
{
	string menu[10];
		menu[0] = "Xuat Du Lieu";
		menu[1] = "Them 1 hang hoa moi";
		menu[2] = "Ban hang";
		menu[3] = "Sap xep hoa don giam dan theo tong tien";
		menu[4] = "Sap xep hoa don theo Ma khach hang tang dan";
		menu[5] = "Thong tin hoa don co gia cao nhat";
		menu[6] = "Tim kiem hoa don cung cac chi tiet hoa don tuong ung";
		menu[7] = "Liet ke thong tin hoa don tu ma khach hang";
		menu[8] = "Thong ke doanh thu";
		menu[9] = "Thoat";
	int chon;
	SListHH HH; SListKH KH; SListHD HD; SListCTHD CTHD;
	nhapFileHeadHH(HH);
	docKH(KH);
	DocFILEHoaDon(HD, KH, HH, CTHD);
	NodeHD*hd = HD.head;
	NodeKH*kh = KH.head;
	NodeHH*hh = HH.head;
	do
	{
		system("cls");
		tenTiem(11);
		chon = MENU(20,5,80,23,menu,10,14,47);
		system("cls");
		switch (chon)
		{
		case 0:
		{
			string menuDl[4];
			menuDl[0] = "Xuat Du Lieu Khach Hang";
			menuDl[1] = "Xuat Du Lieu Hang Hoa";
			menuDl[2] = "Xuat Du Lieu Hoa Don";
			menuDl[3] = "Quay lai";
			int a;
			do
			{
				system("cls");
				tenTiem(14);
				hop(20, 5, 80, 23, "", 11);
				gotoXY(54, 7);
				printf("THONG KE DU LIEU");
				a = MENU(24, 9, 72, 11, menuDl, 4, 14, 47);
				system("cls");
				switch (a)
				{
				case 0:
					xuatKhachHang_Dong(KH);
					break;
				case 1:
					xuatHangHoa_Dong(HH);
					break;
				case 2:
					xuatHoaDon_Dong(HD);
					break;
				case 3:
					break;
				}
				textcolor(7);
			} while (a != 3);
		}
		break;
		case 1:
			them1HangHoa_dong(HH);
		break;
		case 2:
			banHang_Dong(HD, KH, HH);
			break;
		case 3:
		{
			XuatHDTongTienGiamDan(HD);
			xuatHoaDon_Dong(HD);
		}
		break;
		case 4:
		{
			XuatHDMaKHTangDan(HD);
			xuatHoaDon_Dong(HD);
		}
		break;
		case 5:
			xuatAllHD_tongTienMax_Dong(HD);
			break;
		case 6:
			MenuMuc6(HD, HH);
			break;
		case 7:
			MenuMuc7(HD);
			break;
		case 8:
		{
			string menuDT[6];
			menuDT[0] = "HOM NAY";
			menuDT[1] = "NGAY";
			menuDT[2] = "THANG";
			menuDT[3] = "NAM";
			menuDT[4] = "QUY";
			menuDT[5] = "QUAY LAI";
			int a;
			do
			{
				system("cls");
				tenTiem(14);
				hop(20, 5, 80, 23, "", 11);
				gotoXY(50, 7);
				printf("THONG KE DOANH THU THEO");
				a = MENU(24, 9, 72, 15, menuDT, 6, 14, 47);
				system("cls");
				ShowCur(1);
				switch (a)
				{
				case 0:
				{
					hop(20, 5, 80, 23, "", 11);
					hopKhongChu(21, 8, 78, 19, 11);
					gotoXY(47, 7);
					printf("THONG KE DOANH THU HOM NAY");
					char day[11];
					layNgayThangNamCuaHeThong_Char(day);
					doanhThuNgay_Dong(day, HD);
				}
				break;
				case 1:
					doanhThuTheoNgay_Dong(HD);
				break;
				case 2:
					doanhThuTheoThang_Dong(HD);
				break;
				case 3:
					doanhThuTheoNam_Dong(HD);
				break;
				case 4:
					doanhThuTheoQuy_Dong(HD);
				break;
				case 5:
					break;
				}
				textcolor(7);
			} while (a != 5);
		}
			break;
		default:
			break;
		}
		textcolor(7);
	} while (chon != 9);
	capNhatDuLieuVaoFile(HD, hd, KH, kh, HH, hh);
}