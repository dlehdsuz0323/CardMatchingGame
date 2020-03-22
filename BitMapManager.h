#pragma once
#include <Windows.h>

enum BITMAPID
{
	CARD_ID_00,
	CARD_ID_01,
	CARD_ID_02,
	CARD_ID_03,
	CARD_ID_04,
	CARD_ID_05,
	CARD_ID_06,
	CARD_ID_07,
	CARD_ID_08,
	CARD_ID_09,
	CARD_BACK,
};

class BitMap;
class BitMapManager
{
private:

	BitMap*		pBitMap[10];

public:

	void Init(HDC hdc, HINSTANCE g_hinst);
	BitMap* GetBitMap(int iCardId);
	void Relase(void);


	BitMapManager();
	~BitMapManager();
};

