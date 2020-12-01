#include <iostream>
using namespace std;
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <time.h>
#include <conio.h>

///Global Variables
char backupAlpbhabets[] = { 'A', 'B', 'C',
					'D', 'E', 'F',
					'G', 'H', 'I',
					'J', 'K', 'L',
					'M', 'N', 'O',
					'P', 'Q', 'R',
					'S', 'T', 'U',
					'V', 'W', 'X',
					'Y', 'Z','\0'};

vector<string> listOfWords= { 
"abruptly",
"absurd",
"abyss",
"affix",
"askew",
"avenue",
"awkward",
"axiom",
"azure",
"bagpipes",
"bandwagon",
"banjo",
"bayou",
"beekeeper",
"bikini",
"blitz",
"blizzard",
"boggle",
"bookworm",
"boxcar",
"boxful",
"buckaroo",
"buffalo",
"buffoon",
"buxom",
"buzzard",
"buzzing",
"buzzwords",
"caliph",
"cobweb",
"cockiness",
"croquet",
"crypt",
"curacao",
"cycle",
"daiquiri",
"dirndl",
"disavow",
"dizzying",
"duplex",
"dwarves",
"embezzle",
"equip",
"espionage",
"euouae",
"exodus",
"faking",
"fishhook",
"fixable",
"fjord",
"flapjack",
"flopping",
"fluffiness",
"flyby",
"foxglove",
"frazzled",
"frizzled",
"fuchsia",
"funny",
"gabby",
"galaxy",
"galvanize",
"gazebo",
"giaour",
"gizmo",
"glowworm",
"glyph",
"gnarly",
"gnostic",
"gossip",
"grogginess",
"haiku",
"haphazard",
"hyphen",
"iatrogenic",
"icebox",
"injury",
"ivory",
"ivy",
"jackpot",
"jaundice",
"jawbreaker",
"jaywalk",
"jazziest",
"jazzy",
"jelly",
"jigsaw",
"jinx",
"jiujitsu",
"jockey",
"jogging",
"joking",
"jovial",
"joyful",
"juicy",
"jukebox",
"jumbo",
"kayak",
"kazoo",
"keyhole",
"khaki",
"kilobyte",
"kiosk",
"kitsch",
"kiwifruit",
"klutz",
"knapsack",
"larynx",
"lengths",
"lucky",
"luxury",
"lymph",
"marquis",
"matrix",
"megahertz",
"microwave",
"mnemonic",
"mystify",
"naphtha",
"nightclub",
"nowadays",
"numbskull",
"nymph",
"onyx",
"ovary",
"oxidize",
"oxygen",
"pajama",
"peekaboo",
"phlegm",
"pixel",
"pizazz",
"pneumonia",
"polka",
"pshaw",
"psyche",
"puppy",
"puzzling",
"quartz",
"queue",
"quips",
"quixotic",
"quiz",
"quizzes",
"quorum",
"razzmatazz",
"rhubarb",
"rhythm",
"rickshaw",
"schnapps",
"scratch",
"shiv",
"snazzy",
"sphinx",
"spritz",
"squawk",
"staff",
"strength",
"strengths",
"stretch",
"stronghold",
"stymied",
"subway",
"swivel",
"syndrome",
"thriftless",
"thumbscrew",
"topaz",
"transcript",
"transgress",
"transplant",
"triphthong",
"twelfth",
"twelfths",
"unknown",
"unworthy",
"unzip",
"uptown",
"vaporize",
"vixen",
"vodka",
"voodoo",
"vortex",
"voyeurism",
"walkway",
"waltz",
"wave",
"wavy",
"waxy",
"wellspring",
"wheezy",
"whiskey",
"whizzing",
"whomever",
"wimpy",
"witchcraft",
"wizard",
"woozy",
"wristwatch",
"wyvern",
"xylophone",
"yachtsman",
"yippee",
"yoked",
"youthful",
"yummy",
"zephyr",
"zigzag",
"zigzagging",
"zilch",
"zipper",
"zodiac",
"zombie" };
int triesAllowed = 10;
bool cheatMode = false;
//end of global variables

void printHangman(int const count);
void introScreen();

int main()
{
	introScreen();
	
	srand((time_t)time(NULL));

	int score = 0;
	int noOfFailures = 0;
	char ch;
	
	char alphabets[27];
	
	while (noOfFailures < triesAllowed && listOfWords.size()>0)
	{
		int randomNo = rand() % listOfWords.size();
		string word = listOfWords[randomNo];

		string charactersCorrectlyGuessed = "";
		string charactersIncorrectlyGuessed = "";
		listOfWords.erase(listOfWords.begin()+randomNo);
		
		unsigned short correctlyGuessedCharacterCount = 0;
		
		if (cheatMode == true)
		{
			system("cls");
			cout << word;
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
		
		bool printAgain = true;
		strcpy_s(alphabets, backupAlpbhabets);
		while (correctlyGuessedCharacterCount<word.length() && noOfFailures< triesAllowed)
		{
			if (printAgain)
			{
				system("cls");
				cout << "Score: " << score << endl << endl;
				printHangman(noOfFailures);

				for (unsigned short i = 0; i < word.length(); i++)
				{
					if (charactersCorrectlyGuessed.find(word[i]) != string::npos)
					{
						cout << word[i];
					}
					else
						cout << "_";

					cout << " ";
				} //end of for loop

				cout << endl << endl;
				cout << "Remaining Letters: ";
				for (short i = 0; i < 26; i++)
					cout << alphabets[i] << " ";

				cout << endl;
				cout << "Guess a character: ";
			}
			
			ch=_getch();
			
			ch = tolower(ch);
			if (isalpha(ch) == false)
			{
				printAgain = false;
				continue;
			}

			//if the character is already used up.
			if ( charactersCorrectlyGuessed.find(ch) != string::npos || charactersIncorrectlyGuessed.find(ch) != string::npos)
			{
				printAgain = false;
				continue;
			}

			//if the character is a new character and exists in the word.
			else if (word.find(ch) != string::npos)
			{
				charactersCorrectlyGuessed += ch;
				correctlyGuessedCharacterCount+=  std::count(word.begin(), word.end(), ch);
				
				if (correctlyGuessedCharacterCount == word.length())
					score++;

				alphabets[toupper(ch) - 'A'] = '*';
				printAgain = true;
			}

			//the character is a new character, but it does not exist in the word.
			else
			{
				charactersIncorrectlyGuessed += ch;
				noOfFailures++;
				alphabets[toupper(ch) - 'A'] = '*';
				printAgain = true;
			}

			
		} //end of inner while loop
		
		//user has lost the game
		if (noOfFailures == triesAllowed)
		{
			system("cls");
			cout << "Score: " << score << endl << endl;
			printHangman(noOfFailures);
			cout << "The correct word was: " << word << endl;
		}
	        //user has correctly identified the current word.
		else if (correctlyGuessedCharacterCount == word.length())
		{
			system("cls");
			cout << "Score: " << score << endl << endl;
			printHangman(noOfFailures);
			for (unsigned short i = 0; i < word.length(); i++)
			{
					cout << word[i]<<" ";
			}
			this_thread::sleep_for(chrono::milliseconds(1000));
		}

		//user has won the game
		if (listOfWords.size() == 0)
		{
			system("cls");
			cout << "Score: " << score << endl;
			cout << "You have correctly identified all words!" << endl;
			
		}

	} //end of outer while loop

	system("pause");
}

void printHangman(int const count)
{
	switch (count)
	{

	case 0:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;

	case 1:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|      (         " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;

	case 2:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|      (   )     " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;

	case 3:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|      (- -)     " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;

	case 4:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|      (-_-)     " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;

	case 5:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|      (-_-)     " << endl;
		cout << "|        |       " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;

	case 6:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|      (-_-)     " << endl;
		cout << "|        |       " << endl;
		cout << "|      /|||\\    " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;

	case 7:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|      (-_-)     " << endl;
		cout << "|        |       " << endl;
		cout << "|      /|||\\    " << endl;
		cout << "|    _/ ||| \\_  " << endl;
		cout << "|		  " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;
	
	case 8:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|      (-_-)     " << endl;
		cout << "|        |       " << endl;
		cout << "|      /|||\\    " << endl;
		cout << "|    _/ ||| \\_  " << endl;
		cout << "|       |||      " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;

	case 9:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|      (-_-)     " << endl;
		cout << "|        |       " << endl;
		cout << "|      /|||\\    " << endl;
		cout << "|    _/ ||| \\_  " << endl;
		cout << "|       |||      " << endl;
		cout << "|       / \\     " << endl;
		cout << "|                " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;

	case 10:
		cout << "_________________" << endl;
		cout << "|        |       " << endl;
		cout << "|      (-_-)     " << endl;
		cout << "|        |       " << endl;
		cout << "|      /|||\\    " << endl;
		cout << "|    _/ ||| \\_  " << endl;
		cout << "|       |||      " << endl;
		cout << "|       / \\     " << endl;
		cout << "|     _/   \\_   " << endl;
		cout << "|                " << endl;
		cout << "|________________" << endl<<endl;
		break;
	}

}

void introScreen()
{
	cout << "Welcome to Hangman Game ver 1.00." << endl;
	cout << "Made by Saad Farooq" << endl;
	printHangman(triesAllowed);
	cout << "Press any Key to start the game";
	char key=_getch();
	if (key == '&')
	{
		cheatMode = true;
	}
}
