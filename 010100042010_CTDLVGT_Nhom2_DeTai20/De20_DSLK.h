
#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <ctime>
using namespace std;
struct HangHoa
{
	char MaHangHoa[10];
	char TenSP[30];
	char DonViTinh[10];
	float GiaNhap;
	float GiaBan;
};
struct KhachHang
{
	char MaKhachHang[7];
	char FullName[50];
	char NumberPhone[11];
};
struct CTHoaDon
{
	char MaHangHoa[10];
	int SoLuongBan;
	double ThanhTien;
};
//==========================================================================
//List CTHD
struct NodeCTHD
{
	CTHoaDon info;
	NodeCTHD* next;
};
struct SListCTHD
{
	NodeCTHD* head;
	NodeCTHD* tail;
};
//============================================================
struct HoaDon
{
	char MaHoaDon[10];
	char NgayBan[15];
	char MaKhachHang[7];
	SListCTHD cthd;
	double TongTien;
};
//===============================================================================
//Hàng Hóa
struct NodeHH
{
	HangHoa info;
	NodeHH* next;
};
struct SListHH
{
	NodeHH* head;
	NodeHH* tail;
};
//Khách Hàng
struct NodeKH
{
	KhachHang info;
	NodeKH* next;
};
struct SListKH
{
	NodeKH* head;
	NodeKH* tail;
};
//Hóa Ðơn
struct NodeHD
{
	HoaDon info;
	NodeHD* next;
};
struct SListHD
{
	NodeHD* head;
	NodeHD* tail;
};
//============================================================
NodeCTHD* createNodeCTHD(CTHoaDon x);
//============================================================
int isEmptyCTHD(SListCTHD lcthd);
//=============================================================
int insertHeadCTHD(SListCTHD &lcthd, NodeCTHD *p);
//============================================================
int InsertTailCTHD(SListCTHD &lcthd, NodeCTHD* p);
//============================================================
void InsertAfterCTHD(SListCTHD &lcthd, NodeCTHD* q, NodeCTHD* p);
//============================================================
void initSListCTHD(SListCTHD &lcthd);
//============================================================
NodeHH* createNode(HangHoa x);
//============================================================
int isEmpty(SListHH l);
//=============================================================
int insertHead(SListHH &l, NodeHH *p);
//============================================================
int InsertTail(SListHH &l, NodeHH* p);
//============================================================
void InsertAfter(SListHH &l, NodeHH* q, NodeHH* p);
//============================================================
NodeHH *TimHangHoa(SListHH l, char MaHH[]);
//============================================================
void initSListHH(SListHH &l);
void nhapFileHeadHH(SListHH &l);
void Xuat1HangHoa(NodeHH* k);
void XuatHangHoa(SListHH &l);
//==================================================================================================================
NodeKH* createNodeKH(KhachHang x);
//============================================================
int isEmpty(SListKH l);
//=============================================================
int insertHeadKH(SListKH &l, NodeKH *p);
//============================================================
int InsertTailKH(SListKH &l, NodeKH* p);
//============================================================
void InsertAfterKH(SListKH &l, NodeKH* q, NodeKH* p);
//============================================================
void initSListKH(SListKH &l);
void docKH(SListKH &l);
//========================================================================
void Xuat1KhachHang(NodeKH* h);
//========================================================================
void XuatKhachHang(SListKH l);
//=========================================================================================================
NodeHD* createNodeHD(HoaDon x);
//============================================================
int isEmptyHD(SListHD l);
//=============================================================
int insertHeadHD(SListHD &l, NodeHD *p);
//============================================================
int InsertTailHD(SListHD &l, NodeHD* p);
//============================================================
void InsertAfterHD(SListHD &l, NodeHD* q, NodeHD* p);
//============================================================
void initSListHD(SListHD &l);
//========================================================================
void DocFILECTHoaDon(string CTHD, SListHH l, SListCTHD &lcthd);
//===================================================================
double TongTien(SListCTHD lcthd);
void Xuat1CTHD(SListCTHD l);
//========================================================================
NodeKH *TimKhachHang(SListKH l, char MaKH[]);
//Hàm hóa ðõn
void DocFILEHoaDon(SListHD &lhd, SListKH lkh, SListHH lhh, SListCTHD &lcthd);
//========================================================================
void Xuat1HoaDon(NodeHD* d);
void XuatHoaDon(SListHD lhd);
int tim_XuatHDVaCTHD_duaVaoSoHD(SListHD HD, char soHD[7]);
//câu 7
//=====================================
void xuatAllHD_tongTienMax(SListHD HD);
//câu 9
//=====================================================
int lietKeHD_duaVaoMaKH(SListHD HD, char maKH[50]);
//=======================================================
void XuatHDTongTienGiamDan(SListHD lhd);
void XuatHDMaKHTangDan(SListHD lhd);
int Ngay(char h[]);
int Thang(char h[]);
int Nam(char h[]);
void doanhThuTheoNgay(SListHD lhd);
void doanhThuTheoThang(SListHD lhd);
void doanhThuTheoNam(SListHD lhd);
void doanhThuTheoQuy(SListHD lhd);
void banHang(SListHD &HD, SListKH &KH, SListHH HH);
void taoMaHangHoaMoi(SListHH l, char ma[]);
void them1HangHoa(SListHH &l);
void capNhatDuLieuVaoFile(SListHD HD, NodeHD *hd, SListKH KH, NodeKH*kh, SListHH HH, NodeHH*hh);
void banHang_Dong(SListHD &HD, SListKH &KH, SListHH HH);