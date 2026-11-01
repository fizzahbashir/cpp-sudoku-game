//#include <iostream>
//#include <string>
//#include <fstream>
//#include <windows.h>
//#include <cstdlib>
//#include <time.h>
//using namespace std;
//
//// VARIABLE DECLARATIONS //
//bool win = true;
//int aRR[9][9] = { 0 };
//int cell[9][9] = { 0 };
//int hint[9][9] = { 0 };
//int game[9][9] = { 0 };
//int sud[9][9] = { 0 };
//
//void instructions();
//void playnewGame(int newg);
//void solvedBoard();
//void gameHints(int hints);
//void displayBoard();
//void drawGrid(int size);
//void assigningNumbers(int l);
//void saveProgress(int savegame);
//void loadingSaved(int savedgame);
//void inputelements();
//void displaySolution();
//void checkuserstatus();
//void GameMenu();
//bool solve(int x, int y);
//bool canPut(int x, int y, int ans);
//bool next(int i, int j);
//
//// CASE 1 //
//// INSTRUCTION MANUAL//
//void instructions()
//{
//	cout << "Welcome to your sudoku game !" << endl;
//	cout << " How to play sudoku? " << endl;
//	cout << " Rule 1: Only use numbers 1-9. " << endl;
//	cout << " Rule 2: Do not repeat any numbers. " << endl;
//	cout << " Rule 3: Do not guess. " << endl;
//	cout << " Rule 4: Use process of elimination." << endl;
//}
//// CASE 2 //
//// STARTING GAME//
//void playnewGame(int newg)
//{
//	system("cls");
//	solvedBoard();
//	gameHints(newg);
//	displayBoard();
//}
//
//void solvedBoard()
//{
//	int X = 0;
//	int Y = 0;
//	int ans = 0;
//	srand(time(NULL));
//
//	for (int i = 0; i < 5; i++)
//	{
//		X = rand() % 9 + 0;
//		Y = rand() % 9 + 0;
//
//		game[X][Y] = rand() % 9 + 0;
//
//	}
//
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			sud[i][j] = game[i][j];
//		}
//	}
//
//	if (solve(0, 0))
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				aRR[i][j] = sud[i][j];
//			}
//		}
//	}
//
//}
//void gameHints(int hints)
//{
//	int X = 0;
//	int Y = 0;
//	srand(time(NULL));
//	for (int j = 0; j < hints; j++)
//	{
//		X = rand() % 9 + 0;
//		Y = rand() % 9 + 0;
//		hint[X][Y] = aRR[X][Y];
//	}
//	for (int j = 0; j < 9; j++)
//	{
//		for (int k = 0; k < 9; k++)
//		{
//			cell[j][k] = hint[j][k];
//		}
//	}
//}
//void displayBoard()
//{
//
//	cout << " Y/X" << "||" << " 0 " << "  1 " << "  2 " << "|" << " 3 " << "  4 " << "  5 " << "|" << " 6 " << "  7 " << "  8 " << endl;
//	drawGrid(53); cout << endl;
//	cout << "  0" << " || "; assigningNumbers(0); cout << endl;
//	cout << "  1" << " || "; assigningNumbers(1); cout << endl;
//	cout << "  2" << " || "; assigningNumbers(2); cout << endl;
//	drawGrid(53); cout << endl;
//	cout << "  3" << " || "; assigningNumbers(3); cout << endl;
//	cout << "  4" << " || "; assigningNumbers(4); cout << endl;
//	cout << "  5" << " || "; assigningNumbers(5); cout << endl;
//	drawGrid(53); cout << endl;
//	cout << "  6" << " || "; assigningNumbers(6); cout << endl;
//	cout << "  7" << " || "; assigningNumbers(7); cout << endl;
//	cout << "  8" << " || "; assigningNumbers(8); cout << endl;
//	drawGrid(53); cout << endl;
//	drawGrid(53); cout << endl;
//
//	GameMenu();
//}
//void drawGrid(int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << "-";
//	}
//}
//void assigningNumbers(int l)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		cout << cell[i][l] << " " << "| ";
//	}
//	for (int i = 3; i < 6; i++)
//	{
//		cout << cell[i][l] << " " << "| ";
//	}
//	for (int i = 6; i < 9; i++)
//	{
//		cout << cell[i][l] << " " << "| ";
//	}
//}
//
//// CASE 3 //
//// SAVING THREE GAMES IN FILES//
//void saveProgress(int savegame)
//{
//	ifstream fr;
//	ofstream fw;
//
//	cin >> savegame;
//	switch (savegame)
//	{
//	case 1:
//	{
//		fw.open("game#1.txt");
//
//		for (int i = 0; i < 9; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				fw << cell[i][j];
//			}
//
//		}
//		fw.close();
//		break;
//	}
//	case 2:
//	{
//		fw.open("game#2.txt");
//
//		for (int i = 0; i < 9; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				fw << cell[i][j];
//			}
//		}
//		fw.close();
//		break;
//	}
//	case 3:
//	{
//		fw.open("game#3.txt");
//
//		for (int i = 0; i < 9; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				fw << cell[i][j];
//			}
//		}
//		fw.close();
//		break;
//
//
//	}
//	}
//}
//
//
//
//void loadingSaved(int savedgame) {
//	int z = 0;
//	ifstream fr;
//	switch (savedgame)
//	{
//	choosegame:
//		cout << "Choose which game to load:" << endl;
//		cout << "1." << endl;
//		cout << "2." << endl;
//		cout << "3." << endl;
//		cin >> savedgame;
//		if (savedgame > 3 || savedgame < 1)
//		{
//			cout << "invalid input." << endl;
//			cout << "try again." << endl;
//			goto choosegame;
//		}
//
//	case 1:
//	{
//		fr.open("game#1.txt");
//		for (int i = 0; i < 9; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				fr >> z;
//				cell[i][j] = z;
//			}
//		}
//		fr.close();
//		break;
//	}
//	case 2:
//	{
//		fr.open("game#2.txt");
//		for (int i = 0; i < 9; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				fr >> z;
//				cell[i][j] = z;
//			}
//		}
//		fr.close();
//		break;
//	}
//	case 3:
//	{
//		fr.open("game#3.txt");
//		for (int i = 0; i < 9; i++)
//		{
//			for (int j = 0; j < 9; j++)
//			{
//				fr >> z;
//				cell[i][j] = z;
//			}
//		}
//		fr.close();
//		break;
//	}
//	}
//	system("cls");
//	displayBoard();
//}
//
//void inputelements()
//{
//	int x = 0;// x coordinate
//	int y = 0;// y coordinate
//	int value = 0;
//
//Try_Again:
//	cout << " enter x axis position of box:" << endl;
//	cin >> x;
//	cout << " Enter y axis positinon of box:" << endl;
//	cin >> y;
//	cout << "enter desired value:" << endl;
//	cin >> value;
//
//	//input validation//
//	if (x < 0 || x>8 || y < 0 || y>8 || value > 9 || value < 1)
//	{
//		cout << "invalid input." << endl;
//		goto Try_Again;
//	}
//
//	if (hint[x][y] != 0)
//	{
//
//		cout << "hint is already given." << endl;
//
//		goto Try_Again;
//	}
//
//	cell[x][y] = value;
//	system("cls");
//}
//// DISPLAYING SOLUTION//
//void displaySolution()
//{
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j << 9; j++)
//		{
//			cell[i][j] = aRR[i][j];
//		}
//	}
//}
//void checkuserstatus()
//{
//	if (win == true)
//	{
//		system("cls");
//		cout << "YOU HAVE SOLVED THE PUZZLE!" << endl;
//	}
//	else
//	{
//		system("cls");
//		cout << "BETTER LUCK NEXT TIME" << endl;
//	}
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			if (cell[i][j] != aRR[i][j])
//			{
//				win = false;
//			}
//		}
//	}
//	int choice = 0;
//	cin >> choice;
//	cout << "press 0 to exit game" << endl;
//	if (choice == 0)
//	{
//		system("cls");
//
//		exit(0);
//	}
//}
//void GameMenu()
//{
//	int input = 0;
//gamemenu:
//	cout << " - Game Menu - " << endl;
//	cout << "================" << endl;
//	cout << "1. enter answer" << endl;
//	cout << "2. check your status" << endl;
//	cout << "3. view solution" << endl;
//	cout << "4. exit game" << endl;
//	cout << "5. save your progress" << endl;
//	cin >> input;
//	if (input > 5 || input < 1)
//	{
//		cout << "invalid option" << endl;
//		goto gamemenu;
//	}
//	switch (input)
//	{
//	case 1:
//	{
//		inputelements();
//		displayBoard();
//		break;
//	}
//	case 2:
//	{
//		checkuserstatus();
//		break;
//	}
//	case 3:
//	{
//		displaySolution();
//		system("cls");
//		displayBoard();
//		break;
//	}
//	case 4:
//	{
//		exit(0);
//	}
//	case 5:
//	{
//		int save;
//		cin >> save;
//		saveProgress(save);
//		Sleep(1500);
//		system("cls");
//		displayBoard();
//
//		break;
//	}
//	}
//}
//bool solve(int x, int y)
//{
//	if (game[x][y] == 0) {
//		for (int i = 1; i <= 9; i++) {
//			if (canPut(x, y, i)) {
//				sud[x][y] = i;
//				if (next(x, y)) return true;
//			}
//		} sud[x][y] = 0; return false;
//	} return next(x, y);
//}
//bool canPut(int x, int y, int ans) {
//	for (int i = 0; i < 9; i++) {
//		if (ans == sud[x][i] || ans == sud[i][y] ||
//			ans == sud[x / 3 * 3 + i % 3][y / 3 * 3 + i / 3]) return false;
//
//	} return true;
//}
//bool next(int i, int j)
//{
//	if (i == 8 && j == 8) return true;
//	else if (i == 8) return solve(0, j + 1);
//	else return solve(i + 1, j);
//}
//// MAIN FUNCTION //
//int main()
//{
//
//	system("cls");
//	int options;
//	int savedgame;
//	cout << "What would you like to do?" << endl;
//	cout << "Options Menu:" << endl;
//
//
//OptionsMenu:
//	cout << "(1) to view instructions. " << endl;
//	cout << "(2) to start new game. " << endl;
//	cout << "(3) to load another game." << endl;
//	cout << "(4) to exit game." << endl;
//	int back;
//	cin >> options;
//	if (options > 4 || options < 1)
//	{
//		cout << "try again." << endl;
//		goto OptionsMenu;
//	}
//	switch (options)
//	{
//	case 1://to see instructions
//	{	system("cls");
//		instructions();
//		cout << endl << "Press 1 to go back to options menu" << endl;
//		cin >> back;
//		if (back == 1)
//			goto OptionsMenu;
//		break;
//
//	}
//
//	case 2://to play the game
//		system("cls");
//		playnewGame(60);
//		break;
//
//
//	case 3://to load another game
//		loadingSaved(savedgame = 0);
//		break;
//
//	case 4: //to exit
//		exit(0);
//
//	}
//}
//
