#include "Card.h"
#include "resource.h"
#include "BitMap.h"


Card::Card()
{
	bOpenCard = false;
}


Card::~Card()
{
}

void Card::Init(int x, int y, int iCardId, BitMap* MyBitMap, BitMap* OldBitMap)
{
	CardPos.x = x;
	CardPos.y = y;

	iCardNumber = iCardId;

	cBitMap = MyBitMap;
	cOldBitMap = OldBitMap;
}

bool Card::LButtonDown(int x, int y)
{
	MousePoint.x = x;
	MousePoint.y = y;

	CardRect = { CardPos.x, CardPos.y, CardPos.x + WIDTH, CardPos.y + HIGH };

	if (PtInRect(&CardRect, MousePoint) == true)
	{
		return true;
	}

	return false;
}

void Card::Draw(HDC hdc)
{
	if (bOpenCard == true)
	{
		cBitMap->draw(hdc, CardPos.x, CardPos.y);
	}
	else if (bOpenCard == false)
	{
		cOldBitMap->draw(hdc, CardPos.x, CardPos.y);
	}
}
