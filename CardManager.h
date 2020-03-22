#pragma once

#include <Windows.h>
#include <vector>

using namespace std;

enum GAMESTATE
{
	PLAY_GAME,
	WAIT_GAME,
	CARDSELECT,
};

class Card;
class BitMapManager;
class CardManager
{
private:
	CardManager();
	static CardManager* inst;


	// Game Info
	int					iWaitGameCount;
	int					iGameState;
	HWND				_hWnd;

	// Card Info
	int					iCardId[20];
	Card*				FirstSelectCard;
	Card*				SecondSelectCard;
	vector<Card*>		vecCard;
	BitMapManager*		cBitMapManager;			


public:

	void Init(HDC hdc, HINSTANCE g_hinst);
	void Draw(HDC hdc);
	void Update(void);
	void LButtonDown(int x, int y);
	void Release(void);
	void SuffleCard(void);

	static CardManager* GetInstance()
	{
		if (inst == nullptr)
			inst = new CardManager();

		return inst;
	}


	~CardManager();
};