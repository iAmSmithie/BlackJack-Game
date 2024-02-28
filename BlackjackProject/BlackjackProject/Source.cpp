#include <iostream>
#include <string.h>
#include <string>

int GameStart();
int Instructions();
int Quit();
int Win();
int Lose();
int Draw();
int BothBust();
int DealerBust();
int PlayerBank = 10;
int BetAmount = 0;


int main() 
{
	int MenuRun = 1;
	int NumberChosen = 0;

	std::cout << "BlackJack!" << std::endl;
	std::cout << "Menu: " << std::endl;
	MenuRun = 1;

	if (MenuRun == 1)
	{
		std::cout << "Press 1 to start the game" << std::endl;
		std::cout << "Press 2 for the instructions" << std::endl;
		std::cout << "Press 3 to quit" << std::endl;

		std::cin >> NumberChosen;

		switch (NumberChosen) 
		{
		case 1:
			std::cout << "Game Start" << std::endl;
			MenuRun = 0; //terminates the switch statement
			GameStart();
			break;

		case 2:
			std::cout << "Instructions" << std::endl;
			MenuRun = 0; //terminates the switch statement
			Instructions();
			break;

		case 3:
			std::cout << "Quit" << std::endl;
			MenuRun = 0; //terminates the switch statement
			Quit();
			break;

		default: // if anything else is pressed
			std::cout << "Error! Wrong Number Entered" << std::endl;
			MenuRun = 0; //terminates the switch statement
			break;

		}
	}
	
	return 0;


}
int GameStart()
{
	int seed = 0;

	struct Card //initialise struct for the deck
	{
		char m_cardNum[6];
		char m_cardSuit[9];
		int m_cardValue1;
		int m_cardValue2;

	};

	//initialise array Deck
	Card Deck[52] = { 0 };
	for (int Suit = 0;Suit < 52;Suit += 13)
	{
		for (int Card = 0;Card < 13;Card++)
		{
			if (Card > 9) 
			{ 
				Deck[Suit + Card].m_cardValue1 = 10;	
				Deck[Suit + Card].m_cardValue2 = 10;
			}
			else 
			{ 
				Deck[Suit + Card].m_cardValue1 = Card + 1; 
				Deck[Suit + Card].m_cardValue2 = Card + 1;
			}
			if (Suit == 0) 
			{ 
				strcpy_s(Deck[Suit + Card].m_cardSuit, "Hearts");
			}
			if (Suit == 13) 
			{
				strcpy_s(Deck[Suit + Card].m_cardSuit, "Diamonds");
			}
			if (Suit == 26) 
			{ 
				strcpy_s(Deck[Suit + Card].m_cardSuit, "Clubs");
			}
			if (Suit == 39) 
			{
				strcpy_s(Deck[Suit + Card].m_cardSuit, "Spades");
			}
			switch (Card)
			{
			case 0: {strcpy_s(Deck[Suit + Card].m_cardNum,"Ace"); 
			break;}
			case 1: {strcpy_s(Deck[Suit + Card].m_cardNum,"Two");
			break;}
			case 2: {strcpy_s(Deck[Suit + Card].m_cardNum,"Three"); 
			break;}
			case 3: {strcpy_s(Deck[Suit + Card].m_cardNum,"Four"); 
			break;}
			case 4: {strcpy_s(Deck[Suit + Card].m_cardNum,"Five");
			break;}
			case 5: {strcpy_s(Deck[Suit + Card].m_cardNum,"Six");
			break;}
			case 6: {strcpy_s(Deck[Suit + Card].m_cardNum,"Seven");
			break;}
			case 7: {strcpy_s(Deck[Suit + Card].m_cardNum,"Eight");
			break;}
			case 8: {strcpy_s(Deck[Suit + Card].m_cardNum,"Nine"); 
			break;}
			case 9: {strcpy_s(Deck[Suit + Card].m_cardNum,"Ten"); 
			break;}
			case 10: {strcpy_s(Deck[Suit + Card].m_cardNum,"Jack");
			break;
			case 11: {strcpy_s(Deck[Suit + Card].m_cardNum,"Queen");
			break;}
			case 12: {strcpy_s(Deck[Suit + Card].m_cardNum,"King");
			break;}
			default: break;
			}

			}
			
		}
	}
	// randomises the seed used for the deck.
	srand(time(0));

	int CardPulls = 1;
	int Handtotal = 0;
	int DHandtotal = 0;
	int Card1 = 0;
	char* Card1Num = nullptr;
	char* Card1Suit = nullptr;
	int Card2 = 0;
	char* Card2Num = nullptr;
	char* Card2Suit = nullptr;
	int Card3 = 0;
	char* Card3Num = nullptr;
	char* Card3Suit = nullptr;
	int DCard = 0;
	int DCard2 = 0;
	int DCard3 = 0;
	int Q = 0;
	int i = 0;
	int P = 0;
	char* DCardSuit2 = nullptr;
	char* DCardNum2 = nullptr;
	char* DCardSuit = nullptr;
	char* DCardNum = nullptr;
	int DCardsPulled = 0;
    char choice;
	char Choice2;
	int AnotherCard = 1;

    char DebugMode = 0;

	//PLAYERSCARDS
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		std::cout << "Would you like enable debug mode?(Y/N)" << std::endl;
		std::cin >> DebugMode;

		if (DebugMode == 'Y' || DebugMode == 'y')
		{
			DebugMode = 1;
		}
		if (DebugMode == 'N' || DebugMode == 'n')
		{
			DebugMode = 0;
		}
		
	std::cout << "Current bank balance : " << PlayerBank << std::endl;
	std::cout << "Please enter bet amount" << std::endl;
	std::cin >> BetAmount;

	if (PlayerBank <= 0 || BetAmount < 0 || BetAmount > PlayerBank)
	{
		std::cout << "You dont have enough money" << std::endl;
		main();
	}

		for (std::size_t i = 0; i < std::size(Deck) - 1; ++i) //array indexing
		{
			std::size_t j = i + rand() % (std::size(Deck) - i);
			std::swap(Deck[i], Deck[j]); //swaps the two variables to randomise what card will come out
		}
		for (int i = 0; i < 2; i++)
		{
			//grab cardNum and cardSuit from the Array called Deck

			Card1Num = Deck[i].m_cardNum;
			Card1Suit = Deck[i].m_cardSuit;
			Card1 = Deck[i].m_cardValue1;
		}
		for (int i = 0; i < 1; i++)
		{
			//grab cardNum and cardSuit from the Array called Deck

			Card2Num = Deck[i].m_cardNum;
			Card2Suit = Deck[i].m_cardSuit;
			Card2 = Deck[i].m_cardValue1;
		}

		Handtotal = Card1 + Card2;
		std::cout << Card1Num << " of " << Card1Suit << " (" << Card1 << ")" << std::endl;
		std::cout << Card2Num << " of " << Card2Suit << " (" << Card2 << ")" << std::endl;
		std::cout << "Your total is " << Handtotal << std::endl;
	
	//DEALERS CARDS
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (DHandtotal < 17) 
	{
		for (std::size_t i = 0; i < std::size(Deck) - 1; ++i) //array indexing
		{
			std::size_t j = i + rand() % (std::size(Deck) - i);

			std::swap(Deck[i], Deck[j]); //swaps the two variables to randomise what card will come out

			for (int i = 0; i < 2; i++)
			{
				DCard = Deck[i].m_cardValue1;
				DCardNum = Deck[i].m_cardNum;
				DCardSuit = Deck[i].m_cardSuit;
			}
			for (int i = 0; i < 1; i++)
			{
				DCard2 = Deck[i].m_cardValue1;
				DCardNum2 = Deck[i].m_cardNum;
				DCardSuit2 = Deck[i].m_cardSuit;
			}
		}
		DHandtotal = DCard + DCard2;
	}

	std::cout << "Dealers first card" << std::endl;
	std::cout << DCardNum << " of " << DCardSuit << " (" << DCard << ")" << std::endl;

	if (DebugMode == 1)
	{
		std::cout << DCardNum2 << " of " << DCardSuit2 << " (" << DCard2 << ")" << std::endl;
	}
	if (DebugMode == 0)
	{
		std::cout << "HIDDEN CARD" << std::endl;
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	AnotherCard = 1;

	while (Handtotal <= 21 && AnotherCard == 1)
	{
		std::cout << "Would you like to draw another card?(Y/N)" << std::endl;
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			for (std::size_t i = 0; i < std::size(Deck) - 1; ++i) //array indexing
			{

				std::size_t j = i + rand() % (std::size(Deck) - i);


				std::swap(Deck[i], Deck[j]); //swaps the two variables to randomise what card will come out

			}
			for (int Q = 0; Q < 1; Q++)
			{
				Card3 = Deck[Q].m_cardValue1;
				Card3Num = Deck[Q].m_cardNum;
				Card3Suit = Deck[Q].m_cardSuit;
			}
			Handtotal = Handtotal + Card3;

			std::cout << Card3Num << " of " << Card3Suit << " (" << Card3 << ")" << std::endl;
			std::cout << "Your total is " << Handtotal << std::endl;

			if (Handtotal > 21)
			{
				std::cout << "Bust!" << std::endl;


				std::cout << "Would you like to play again?(Y/N)" << std::endl;
				std::cin >> Choice2;
				if (Choice2 == 'Y' || Choice2 == 'y')
				{
					AnotherCard = 0;
					PlayerBank = PlayerBank - BetAmount;
					Lose();
				}
				if (Choice2 == 'N' || Choice2 == 'n')
				{
					AnotherCard = 0;
					PlayerBank = PlayerBank - BetAmount;
					int MenuRun = 1;
					main();
				}
			}

		}
		else if (choice == 'N' || choice == 'n')
		{
			std::cout << "Your total is " << Handtotal << std::endl;

			std::cout << "dealers total is " << DHandtotal << std::endl;


			if (DHandtotal > 21 && Handtotal > 21)
			{
				AnotherCard = 0;
				std::cout << "You've both gone bust bet returned" << std::endl;
				std::cout << "Your bank balance is now " << PlayerBank << std::endl;
				BothBust();
			}
			if (DHandtotal > Handtotal)
			{
				AnotherCard = 0;
				std::cout << "You Lose" << std::endl;
				PlayerBank = PlayerBank - BetAmount;
				std::cout << "Your bank balance is now " << PlayerBank << std::endl;
				Lose();
			}
			if (Handtotal > DHandtotal)
			{
				AnotherCard = 0;
				std::cout << "You win" << std::endl;
				PlayerBank = PlayerBank + BetAmount;
				std::cout << "Your bank balance is now " << PlayerBank << std::endl;
				Win();
			}
			if (Handtotal == DHandtotal)
			{
				AnotherCard = 0;
				std::cout << "Draw Bet Returned" << std::endl;
				std::cout << "Your bank balance is now " << PlayerBank << std::endl;
				Draw();
			}
			if (DHandtotal > 21)
			{
				AnotherCard = 0;
				std::cout << "Dealer Bust bet won" << std::endl;
				PlayerBank = PlayerBank + BetAmount;
				std::cout << "Your bank balance is now " << PlayerBank << std::endl;
				DealerBust();
			}
		}
	}

	return 0;
}

int Win()
{
	main();
	return 0;
}
int Lose()
{
	main();
	return 0;
}
int Draw()
{
	main();
	return 0;
}
int BothBust()
{
	main();
	return 0;
}
int DealerBust()
{
	main();
	return 0;
}



int Instructions()
{
	char MenuReturn = 0;
	int Rtrn = 0;

	std::cout << "Blackjack is a simple card game where the player will draw two cards and the dealer draws two cards however the player can only see the dealers first card." << std::endl;
	std::cout << "the goal of the game is for the player to get their cards to total to 21, have higher number cards than the dealer at the end or for the dealer to go bust." << std::endl;
	std::cout << "If the dealer has higher cards than you or you go bust the dealer wins and you lose." << std::endl;
	std::cout << "If both players go bust or have equal cards its a draw and the bet is returned to the player." << std::endl;
	std::cout << "" << std::endl;


	while (Rtrn == 0)
	{
		std::cout << "Press R to return" << std::endl;
		std::cin >> MenuReturn;

		if (MenuReturn == 'R' || MenuReturn == 'r')
		{
			Rtrn = 1;
			main();
		}
	}
	return 0;
}

int Quit()
{

	return 0;
}