#include "CardManager.h"
#include "BitMapManager.h"
#include "Card.h"

CardManager* CardManager::inst = NULL;

CardManager::CardManager()
{
	iGameState = PLAY_GAME;
	iWaitGameCount = 0;
}


CardManager::~CardManager()
{
}

void CardManager::Init(HDC hdc, HINSTANCE g_hinst)
{
	srand(GetTickCount());
	BitMapManager* cBitMapManager = new BitMapManager();
	cBitMapManager->Init(hdc, g_hinst);

	for (int i = 0; i < 20; i++)
	{
		iCardId[i] = i % 10;
	}

	for (int i = 0; i < 100; i++)
	{
		for (int i = 0; i < 100; i++)
		{
			int randA = rand() % 20;
			int randB = rand() % 20;
			int temp;
	
			temp = iCardId[randA];
			iCardId[randA] = iCardId[randB];
			iCardId[randB] = temp;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Card* pNew = new Card();
		if(i < 10)
		{
			pNew->Init(WIDTH* i,
					   0,
				iCardId[i],
				cBitMapManager->GetBitMap(iCardId[i]),
				cBitMapManager->GetBitMap(CARD_BACK));
			vecCard.push_back(pNew);
		}

		else if (i < 20)
		{
			pNew->Init(WIDTH * (i % 10),
					   HIGH,
				iCardId[i],
				cBitMapManager->GetBitMap(iCardId[i]),
				cBitMapManager->GetBitMap(CARD_BACK));
			vecCard.push_back(pNew);
		}
	}
}

void CardManager::Draw(HDC hdc)
{
	for (auto iter = vecCard.begin(); iter != vecCard.end(); iter++)
	{
		(*iter)->Draw(hdc);
	}
}

void CardManager::LButtonDown(int x, int y)
{
	for (auto iter = vecCard.begin(); iter != vecCard.end(); iter++)
	{
		if ((*iter)->LButtonDown(x, y))
		{
			if (iGameState == PLAY_GAME)
			{
				FirstSelectCard = (*iter);
				FirstSelectCard->OpenCard();
				iGameState = CARDSELECT;
			//	MessageBox(_hWnd, "같은 카드", "MessageBoxBox", MB_OK);
			}

			else if (iGameState == CARDSELECT)
			{
				SecondSelectCard = (*iter);
				SecondSelectCard->OpenCard();
				if (FirstSelectCard->ReturnCardId() == SecondSelectCard->ReturnCardId())
				{
					FirstSelectCard  = NULL;
					SecondSelectCard = NULL;
					iGameState = PLAY_GAME;
					//MessageBox(_hWnd, "같은 카드", "MessageBoxBox", MB_OK);
				}
				else if (FirstSelectCard->ReturnCardId() != SecondSelectCard->ReturnCardId())
				{
					iGameState = WAIT_GAME;
					//MessageBox(_hWnd, "다른 카드", "MessageBoxBox", MB_OK);
				}
			}
		}
	}
	InvalidateRect(_hWnd, NULL, TRUE);
}

void CardManager::Update(void)
{
	if (iGameState == WAIT_GAME)
	{
		iWaitGameCount++;
		if (iWaitGameCount > 2)
		{
			iWaitGameCount = 0;
			iGameState = PLAY_GAME;
			FirstSelectCard->CloseCard();
			SecondSelectCard->CloseCard();
		}
	}
	//InvalidateRect(_hWnd, NULL, TRUE);
}

void CardManager::Release(void)
{
	for (auto iter = vecCard.begin(); iter != vecCard.end(); iter++)
	{
		delete (*iter);
	}
	cBitMapManager->Relase();
	delete inst;
}
