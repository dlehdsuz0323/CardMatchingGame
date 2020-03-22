#include "BitMap.h"
#include "resource.h"



BitMap::BitMap()
{
}


BitMap::~BitMap()
{
}

void BitMap::Init(HDC hdc, HINSTANCE g_hinst, int iCardId)
{
	MemDC = CreateCompatibleDC(hdc);
	MyBitMap = LoadBitmap(g_hinst, MAKEINTRESOURCE(iCardId));
	OldBitMap = (HBITMAP)SelectObject(MemDC, MyBitMap);

	BITMAP BitMapInfo;
	GetObject(MyBitMap, sizeof(BitMapInfo), &BitMapInfo);
	BitMapSize.cx = BitMapInfo.bmWidth;
	BitMapSize.cy = BitMapInfo.bmHeight;
}

void BitMap::draw(HDC hdc, int x, int y)
{
	BitBlt(hdc, x, y, BitMapSize.cx, BitMapSize.cy, MemDC, 0, 0, SRCCOPY);
}

void BitMap::Release()
{
	DeleteObject(MemDC);
	DeleteObject(MyBitMap);
	DeleteObject(OldBitMap);
}