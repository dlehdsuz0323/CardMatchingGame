#include "BitMapManager.h"
#include "BitMap.h"
#include "resource.h"



BitMapManager::BitMapManager()
{
}


BitMapManager::~BitMapManager()
{
}



void BitMapManager::Init(HDC hdc, HINSTANCE g_hinst)
{
	for (int i = 0; i <= 10; i++)
	{
		BitMap* pNew = new BitMap();
		pNew->Init(hdc, g_hinst, IDB_BITMAP1 + i);
		pBitMap[i] = pNew;
	}
}

BitMap* BitMapManager::GetBitMap(int iCardId)
{
	return pBitMap[iCardId];
}

void BitMapManager::Relase(void)
{
	for (int i = 0; i < 11; i++)
	{
		delete pBitMap[i];
	}
}