//Draven McConathy
//Tic Tac Toe
// 01-27-2024

#include <iostream>
#include <random>

using namespace std;

//Global constants
const int ROWS = 3;
const int COLS = 3;
const int MAXGAMESPERSESSION = 10;
const int PLAYER = 0;
const int COMPUTER = 1;
const int CAT = 2;
const int WINNERS = 0;
const int TURNS = 1;
const int COL1 = 0;
const int COL2 = 1;
const int COL3 = 2;
const int ROW1 = 0;
const int ROW2 = 1;
const int ROW3 = 2;

//Function prototypes
void initialize(char [][COLS], const int, int&);
void drawBoard(char [][COLS], const int);
void playerTurn(char [][COLS], const int);
void computerTurn(char [][COLS], const int);
bool validateTurn(char [][COLS], int, int);
bool checkWinner(char[][COLS], int [][2], const int, int, int);
void menu(bool&, bool&, int&, int[][2], int);
void findWinner(int[][2], int);

int main() {
	//Variable definitions
	char board[ROWS][COLS];
	int score[MAXGAMESPERSESSION][2] = { 0 };
	bool stillPlaying = true;
	bool gameWon = false;
	int numberOfGamesPlayed = 0;
	int turnCount = 0;
	gameWon = false;

	//Game Start
	while (stillPlaying) {
		
		initialize(board, ROWS, turnCount);
		menu(gameWon, stillPlaying, numberOfGamesPlayed, score, numberOfGamesPlayed);

		//Loops until someone wins the game
		while (gameWon == false) {
			drawBoard(board, ROWS);
			playerTurn(board, ROWS);
			turnCount++;
			gameWon = checkWinner(board, score, ROWS, numberOfGamesPlayed, turnCount);
			if (gameWon == true) {
				break;
			}
			computerTurn(board, ROWS);
			gameWon = checkWinner(board, score, ROWS, numberOfGamesPlayed, turnCount);
		}
		numberOfGamesPlayed++;

		//if the maximum number of games has been played end the session and show the end game statistics
		if (numberOfGamesPlayed == MAXGAMESPERSESSION) {
			findWinner(score, numberOfGamesPlayed);
			exit(1);
		}
	}
}

//Resets the game board so that each square is a blank space before each round and resets the turn counter
//Declares each row in board array as an empty character
void initialize(char board[][COLS], const int ROWS, int& turnCount) {
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			board[row][col] = ' ';
		}
	}
	turnCount = 0;
}

//Clears screen and draws the game board with the current moves stored in the board array
void drawBoard(char board[][COLS], const int ROWS) {
	system("cls"); 

	//loops for each row on the board
	for (int n = 0; n < 3; n++) {
		cout << "|----|----|----|" << endl;
		cout << "|  " << board[n][0] << " |  " << board[n][1] << " |  " << board[n][2] << " |" << endl;
	}
	cout << "|----|----|----|" << endl;
}

//Gets player input until a valid input is recieved and stores it into the board array
void playerTurn(char board[][COLS], const int) {
	int row, col;
	bool validTurn = false;

	//loops until a valid turn is entered
	while (validTurn == false) {
		cout << endl << "Enter your move's cell row and column : ";
		cin >> row >> col; 

		//Clears input stream buffer to prevent an infinite validation loop
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		validTurn = validateTurn(board, row, col);

	}
	board[row][col] = 'X'; 
}

//Randomly generates two integers for the computers move for the row and and column
//until a valid move is received and is stored into the board array
void computerTurn(char board[][COLS], const int ROWS) {
	int row, col;
	bool validTurn = false;

	srand(time(0)); //Random number seed

	//loops until a valid turn is generated 
	while (validTurn == false) {
		//Randomly generates a row and column
		row = rand() % 3; 
		col = rand() % 3; 
		validTurn = validateTurn(board, row, col);
	}
	//Stores move onto the board
	board[row][col] = 'O'; 
}

//Checks to see if the computer or player input is a valid move by seeing if the square
//on the board is open (an empty character). Also prevents inputs that would throw an exception.
bool validateTurn(char board[][COLS], int row, int col) {
	if (row < 0 || row > 2) {
		return false;
	}

	if (col < 0 || col > 2) {
		return false;
	}

	if (board[row][col] == ' ') {
		return true;
	}

	else {
		cout << "\nThat space is full please try again\n";
		return false;
	}
}

//Checks to see if their are 3 X's or O's in a row accross the board and if there is, assigns the winner
//for that round as well as how many turns it took them to win in the score array
bool checkWinner(char board[][COLS], int score[][2], const int ROWS, int gamesPlayed, int turnCount) {
	//Checks each row for 3 X's or O's in a row
	for (int row = ROW1; row < ROWS; row++) {
		if (board[row][COL1] == 'X' && board[row][COL2] == 'X' && board[row][COL3] == 'X') {
			score[gamesPlayed][WINNERS] = PLAYER;
			score[gamesPlayed][TURNS] = turnCount;
			cout << "\nYou won in " << turnCount << " turns.";
			return true;
		}
		else if (board[row][COL1] == 'O' && board[row][COL2] == 'O' && board[row][COL3] == 'O') {
			score[gamesPlayed][WINNERS] = COMPUTER;
			score[gamesPlayed][TURNS] = turnCount;
			cout << "\nYou have been defeated by a computer in " << turnCount << " turns.";
			return true;
		}
	}

	//Checks each column for 3 X's or O's in a row
	for (int col = 0; col < COLS; col++) {
		if (board[ROW1][col] == 'X' && board[ROW2][col] == 'X' && board[ROW3][col] == 'X') {
			score[gamesPlayed][WINNERS] = PLAYER;
			score[gamesPlayed][TURNS] = turnCount;
			drawBoard(board, ROWS);
			cout << "\nYou won in " << turnCount << " turns.";
			return true;
		}
		else if (board[ROW1][col] == 'O' && board[ROW2][col] == 'O' && board[ROW3][col] == 'O') {
			score[gamesPlayed][WINNERS] = COMPUTER;
			score[gamesPlayed][TURNS] = turnCount;
			drawBoard(board, ROWS);
			cout << "\nYou have been defeated by a computer in " << turnCount << " turns.";
			return true;
		}
	}

	//Checks if there are 3 X's or O's in a row in diagonal 1
	if (board[ROW1][COL1] == 'X' && board[ROW2][COL2] == 'X' && board[ROW3][COL3] == 'X') { 
		score[gamesPlayed][WINNERS] = PLAYER;
		score[gamesPlayed][TURNS] = turnCount;
		drawBoard(board, ROWS);
		cout << "\nYou won in " << turnCount << " turns.";
		return true;
	}
	else if (board[ROW1][COL1] == 'O' && board[ROW2][COL2] == 'O' && board[ROW3][COL3] == 'O') {
		score[gamesPlayed][WINNERS] = COMPUTER;
		score[gamesPlayed][TURNS] = turnCount;
		drawBoard(board, ROWS);
		cout << "\nYou have been defeated by a computer in " << turnCount << " turns.";
		return true;
	}
	//Checks if there are 3 X's or O's in a row in diagonal 2
	else if (board[ROW3][COL1] == 'X' && board[ROW2][COL2] == 'X' && board[ROW1][COL3] == 'X') {
		score[gamesPlayed][WINNERS] = PLAYER;
		score[gamesPlayed][TURNS] = turnCount;
		drawBoard(board, ROWS);
		cout << "\nYou won in " << turnCount << " turns.";
		return true;
	}
	else if (board[ROW3][COL1] == 'O' && board[ROW2][COL2] == 'O' && board[ROW1][COL3] == 'O') {
		score[gamesPlayed][WINNERS] = COMPUTER;
		score[gamesPlayed][TURNS] = turnCount;
		drawBoard(board, ROWS);
		cout << "\nYou have been defeated by a computer in " << turnCount << " turns.";
		return true;
	}
	//Checks if the Cat won due to no valid moves (open squares) remaining
	else {
		for (int row = 0; row < ROWS; row++) {
			for (int col = 0; col < COLS; col++) {
				if (board[row][col] == ' ') {
					return false;
				}
			}
		}
		score[gamesPlayed][WINNERS] = CAT;
		score[gamesPlayed][TURNS] = turnCount;
		drawBoard(board, ROWS);
		cout << "The cat defeated both of you!";
		return true;
	}
}
 
//A small menu that asks the user if they would like to play/keep playing the game
//If yes the game continues, if no the game either exits or shows the endgame stats
void menu(bool& gameWon, bool& stillPlaying, int& numberOfGamesPlayed, int score[][2], int gamesPlayed) {
	char input;
	bool validInput = false;

	//If the user has not played a game ask if they would like to play
	if (numberOfGamesPlayed == 0) { 
		cout << "Would you like to play Tic Tac Toe? (Y/N): ";
		while (validInput == false) {
			cin >> input; 
			if (input == 'Y' || input == 'y') {
				cout << "Have Fun!" << endl;
				validInput = true; 
				gameWon = false;
			}
			else if (input == 'N' || input == 'n') {
				cout << "Okay, Bye!";
				exit(1); 
			}
			else {
				cout << "Please enter 'Y' or 'N'." << endl;
			}
		}
	}
	else { //If the user has played at least one game since program start ask if they would like to play again
		cout << "\nwould you like to play again? (Y/N): ";
		while (validInput == false) {

			cin >> input; 

			if (input == 'Y' || input == 'y') { 
				cout << "Have Fun!" << endl;
				validInput = true;
				gameWon = false;
			}
			else if (input == 'N' || input == 'n') { 
				findWinner(score, gamesPlayed);
				cout << "\nGood Bye!";
				exit(1); 
			}
			else {
				cout << "Please enter 'Y' or 'N'." << endl;
			}
		}
	}
}

//Loops through the score array to find who won in the fewest turns and who won the most games
//then prints this information
void findWinner (int score[][2], int gamesPlayed) {
	int row = 0;
	int winner = score[row][0];
	int winningTurns = score[row][1];
	int playerWins = 0;
	int computerWins = 0;
	int catWins = 0;

	cout << "\nHere's The end game break down: \n";

	// Finds the win achieved in the fewest turns and saves the amount of turns and whether it was the computer or player
	while (row < gamesPlayed) { 
		if (score[row + 1][0] == COMPUTER) {
			if (score[row + 1][1] <= score[row][1]) {
				winner = score[row][0];
				winningTurns = score[row][1];
				row++;
			}
		}
		else {
			if (score[row + 1][1] < score[row][1]) {
				winner = score[row][0];
				winningTurns = score[row][1];
				row++;
			}
		}
		row++;
	}

	//Finds out the total wins for the player, computer and cat
	row = 0;
	while (row < gamesPlayed) { 
		if (score[row][0] == PLAYER) {
			playerWins++;
			row++;
		}
		else if (score[row][0] == COMPUTER) {
			computerWins++;
			row++;
		}
		else {
			catWins++;
			row++;
		}
	}

	//Prints out end game statistics
	if (winner == PLAYER) { 
		cout << "\nYou won overall by winning a " << winningTurns << " turn game.\n";
	}
	else {
		cout << "\nThe computer won overall by winning a " << winningTurns << " turn game.\n";
	}
	cout << "You won " << playerWins << " times.\n";
	cout << "The computer won " << computerWins << " times.\n";
	cout << "The cat won " << catWins << " times.\n";
}

