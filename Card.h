#pragma once
#include <Windows.h>

#define WIDTH 145
#define HIGH  235

class BitMap;
class Card
{
private:
	
	bool		bOpenCard;
	int			iCardNumber;
	BitMap*		cBitMap;
	BitMap*		cOldBitMap;
	POINT		CardPos;
	POINT		MousePoint;
	RECT		CardRect;

public:

	void Init(int x, int y, int iCardId, BitMap* MyBitMap, BitMap* OldBitMap);
	bool LButtonDown(int x, int y);
	void Draw(HDC hdc);


	inline void OpenCard(void)
	{
		bOpenCard = true;
	}

	inline void CloseCard(void)
	{
		bOpenCard = false;
	}

	inline int ReturnCardId(void)
	{
		return iCardNumber;
	}

	Card();
	~Card();
};

