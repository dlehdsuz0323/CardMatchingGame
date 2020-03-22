#pragma once

#include <Windows.h>

class BitMap
{
private:
	HDC			MemDC;
	SIZE		BitMapSize;
	HBITMAP		MyBitMap;
	HBITMAP		OldBitMap;
public:

	void Init(HDC hdc, HINSTANCE g_hinst, int iCardId);
	void draw(HDC hdc, int x, int y);
	void Release(void);
	BitMap();
	~BitMap();
};

