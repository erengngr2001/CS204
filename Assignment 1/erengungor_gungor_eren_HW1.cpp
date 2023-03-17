//Eren Güngör
//29465
//Lab Section C2
//Homework1 with VS2012

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct cell
	{
		char letter; // letter inside the cell
		char color; // color of the cell
	}; 

void InputCheck(int &attempts, string &input, string &wordToGuess, vector<string> inputVec, vector<vector<cell>> &matrix);
void CheckWordLength(string &input, string &wordToGuess, vector<string> &inputVec, int &attempts, vector<vector<cell>> &matrix);
void AskInput(string &input, vector<string> &inputVec, int &attempts, string &wordToGuess, vector<vector<cell>> &matrix);
bool isAlpha(string &input, vector<string> &inputVec, int &attempts, string &wordToGuess, vector<vector<cell>> &matrix);
void PrintMatrix(vector<vector<cell>> &matrix);
bool isInWord(const string &input, const string &wordToGuess, const int &i);
void GuessAnalysis(const string &input, vector<vector<cell>> &matrix, const string &wordToGuess, int &attempts);
void RepeatedLetter(string &input, vector<string> &inputVec, int &attempts, string &wordToGuess, vector<vector<cell>> &matrix);
void RepeatedGuess(vector<string> &inputVec, string &input, int &attempts, string &wordToGuess, vector<vector<cell>> &matrix);
void isGreenLetterUsed(vector<vector<cell>> &matrix, int &attempts, vector<string> &inputVec, string &input, string &wordToGuess);
void CheckWin(int &attempts, string &input, const string &wordToGuess, vector<vector<cell>> &matrix);

int main() 
{ 
	ifstream inFile;
	string filename, wordToGuess, line, input;
	int attempts, columns;
	vector<string> inputVec;

	//Open the file succesfully
	cout << "Welcome to SWordle!" << endl;
	cout << "Please enter the file name: ";
	cin >> filename;
	inFile.open( filename.c_str() );
	while ( inFile.fail() )
	{
		cout << "Couldn't find the file!" << endl;
		cout << "Please enter the file name: ";
		cin >> filename;
		inFile.open( filename.c_str() );
	}

	//Read the file and get given word and attempts.
	inFile >> attempts;
	inFile >> wordToGuess;
	
	//Create matrix with given column(length of wordToGuess) and row(attempts) numbers, and include cell objects.
	columns = wordToGuess.length();
	vector<vector<cell>> matrix(attempts);
	for (unsigned int i=0; i < matrix.size(); i++) 
	{
		for (int k=0; k < columns; k++) 
		{
				cell a;
				a.letter = '-';
				a.color = '-';
				matrix[i].push_back(a);
		}
	}

	//Initialize the game and ask for input.
	cout << "The word that you will guess has " << wordToGuess.length() << " letters and you have " << attempts << " attempts." << endl;
	AskInput(input, inputVec, attempts, wordToGuess, matrix);

	//Now the input check begins.
	InputCheck(attempts, input, wordToGuess, inputVec, matrix);

	//After exiting the while loop, check last guess was true or false (win/lose) by looking at attempts.
	if (0 == attempts && input == wordToGuess)
	{
		GuessAnalysis(input, matrix, wordToGuess, attempts);
		cout << "You win!" << endl;
	}
	else if (0 == attempts && input != wordToGuess)
	{
		cout << "You lose!" << endl;
	}

	inFile.close();
	return 0;
}

//Initialize input check.
void InputCheck(int &attempts, string &input, string &wordToGuess, vector<string> inputVec, vector<vector<cell>> &matrix)
{
	while ( attempts > 0 )
	{
		CheckWordLength(input, wordToGuess, inputVec, attempts, matrix);
		if ( !isAlpha(input, inputVec, attempts, wordToGuess, matrix) ) 
		{
			cout << "Your input has illegal letters!" << endl;
			AskInput(input, inputVec, attempts, wordToGuess, matrix);
		}
		else
		{
			RepeatedLetter(input, inputVec, attempts, wordToGuess, matrix);
			RepeatedGuess(inputVec, input, attempts, wordToGuess, matrix);
			isGreenLetterUsed(matrix, attempts, inputVec, input, wordToGuess); 
			CheckWin(attempts, input, wordToGuess, matrix);
		}
		if (attempts > 0 && input != wordToGuess)
		{
			inputVec.push_back(input);
			AskInput(input, inputVec, attempts, wordToGuess, matrix);
		}
	}
}

//Print matrix in a specific format.
void PrintMatrix(vector<vector<cell>> &matrix)
{
	for ( unsigned int i=0; i < matrix.size(); i++ ) 
	{
		for ( unsigned int k=0; k < matrix[i].size(); k++ )
		{
			cout << "|| " << matrix[i][k].letter  << " , " << matrix[i][k].color << " ";
		}
		cout << "||" << endl;
	}
}

//Asks user to guess the word by giving an input to the console.
void AskInput(string &input, vector<string> &inputVec, int &attempts, string &wordToGuess, vector<vector<cell>> &matrix)
{
	cout << "What's your guess? ";
	cin >> input;
	InputCheck(attempts, input, wordToGuess, inputVec, matrix);
	inputVec.push_back(input);
}

//Check if the user input length matches with the word.
void CheckWordLength(string &input, string &wordToGuess, vector<string> &inputVec, int &attempts, vector<vector<cell>> &matrix) 
{
	if (attempts > 0)
	{
		if ( input.length() > wordToGuess.length() ) 
		{
			cout << "The word is too long!" << endl;
			AskInput(input, inputVec, attempts, wordToGuess, matrix);
		}
		else if ( input.length() < wordToGuess.length() ) 
		{
			cout << "The word is too short!" << endl;
			AskInput(input, inputVec, attempts, wordToGuess, matrix);
		}
	}
}

//Check if the user input only consists of alphabetical letters.
bool isAlpha(string &input, vector<string> &inputVec, int &attempts, string &wordToGuess, vector<vector<cell>> &matrix) 
{
	char ch;
	bool check = true;
	if (attempts > 0)
	{
		for (unsigned int i=0; i < input.length(); i++) 
		{
			ch = input[i];
			if ( !(ch <= 'z' && ch >= 'a') )
			{
				check = false;
				cout << "Your input has illegal letters!" << endl;
				AskInput(input, inputVec, attempts, wordToGuess, matrix);
			}
		}
	}
	return check;
}

//Checks the guess of the user which is in correct format, analyzes letter by letter, and shows in the matrix.
void GuessAnalysis(const string &input, vector<vector<cell>> &matrix, const string &wordToGuess, int &attempts)
{
	int ct; //needed in order not to display the correct word always at the end of matrix since attempts becomes zero after finding the correct word

	if (0 == attempts)
	{
		ct = 0;
		for (int k=0; k < matrix.size(); k++)
		{
			if (matrix[k][0].letter == '-')
			{
				ct++;
			}
		}
	}
	else
	{
		ct = attempts;
	}

	for (unsigned int i=0; i < input.length(); i++)
	{
		if (input[i] == wordToGuess[i])
		{
			matrix[5-ct][i].color = 'G';
			matrix[5-ct][i].letter = input[i];
		}
		else if ( input[i] != wordToGuess[i] && isInWord(input, wordToGuess, i) )
		{
			matrix[5-ct][i].color = 'Y';
			matrix[5-ct][i].letter = input[i];
		}
		else 
		{
			matrix[5-ct][i].color = 'B';
			matrix[5-ct][i].letter = input[i];
		}
	}
	PrintMatrix(matrix);
}

//Checks whether a letter exists in a word or not.
bool isInWord(const string &input, const string &wordToGuess, const int &i)
{
	char tempLetter = input[i];
	for (unsigned int k=0; k < wordToGuess.length(); k++)
	{
		if (wordToGuess[k] == tempLetter && i != k)
		{
			return true;
		}
	}
	return false;
}

//Checks whether a letter occurs in a word more than once.
void RepeatedLetter(string &input, vector<string> &inputVec, int &attempts, string &wordToGuess, vector<vector<cell>> &matrix)
{
	bool checkDouble = true;
	if (attempts > 0)
	{
		for (unsigned int i=0; i < input.length()-1; i++)
		{
			for (unsigned int k=i+1; k < input.length(); k++)
			{
				if (input[i] == input[k])
				{
					checkDouble = false;
				}
			}
		}
		if (false == checkDouble)
		{
			cout << "Your input has a duplicate letter!" << endl;
			AskInput(input, inputVec, attempts, wordToGuess, matrix);
		}
	}
}

//Checks whether a word was entered before or not.
void RepeatedGuess(vector<string> &inputVec, string &input, int &attempts, string &wordToGuess, vector<vector<cell>> &matrix)
{
	bool checkRepeat = true;
	if (attempts > 0)
	{
		for (unsigned int i=0; i < inputVec.size(); i++)
		{
			if (input == inputVec[i])
			{
				checkRepeat = false;
			}
		}
		if (false == checkRepeat)
		{
			cout << "You've already tried this word!" << endl;
			AskInput(input, inputVec, attempts, wordToGuess, matrix);
		}
		checkRepeat = true;
	}
}

//Checks whether the green letters are used or not.
void isGreenLetterUsed(vector<vector<cell>> &matrix, int &attempts, vector<string> &inputVec, string &input, string &wordToGuess)
{
	bool checkGreen = true;
	if (attempts > 0 && attempts <= 4)
	{
		for (unsigned int i=0; i < matrix[5-attempts].size(); i++)
		{
			if (matrix[5-attempts-1][i].color == 'G' && wordToGuess[i] != input[i])
			{
				checkGreen = false;
			}
		}
	
		if (false == checkGreen) 
		{
			cout << "You did not use the green letter in your word!" << endl;
			AskInput(input, inputVec, attempts, wordToGuess, matrix);
		}
	}
}

//Check whether the guess is correct. If so, jump to the end of the program.
void CheckWin(int &attempts, string &input, const string &wordToGuess, vector<vector<cell>> &matrix)
{
	if (input == wordToGuess)
	{
		attempts = 0; //Exit the while loop in the InputCheck() function.
	}
	else
	{
		GuessAnalysis(input, matrix, wordToGuess, attempts);
		attempts -= 1;
	}
}