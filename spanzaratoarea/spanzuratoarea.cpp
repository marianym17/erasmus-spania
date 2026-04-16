#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void drawHangman(int wrongGuesses) {
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    if (wrongGuesses >= 1) cout << "  O   |" << endl; else cout << "      |" << endl;
    if (wrongGuesses >= 3) cout << " /|\\  |" << endl;
    else if (wrongGuesses >= 2) cout << "  |   |" << endl;
    else cout << "      |" << endl;
    if (wrongGuesses >= 5) cout << " / \\  |" << endl;
    else if (wrongGuesses >= 4) cout << " /    |" << endl;
    else cout << "      |" << endl;
    cout << "      |" << endl;
    cout << "=========" << endl;
}

int main() {
    srand(time(0));

    vector<string> words = {"apple", "banana", "computer", "programming", "algorithm", "structure", "function"};
    string secretWord = words[rand() % words.size()];
    string guessedWord(secretWord.length(), '_');
    int wrongGuesses = 0;
    const int maxWrong = 6;
    vector<char> guessedLetters;

    cout << "Welcome to Hangman!" << endl;
    cout << "Guess the word: " << guessedWord << endl;

    while (wrongGuesses < maxWrong && guessedWord != secretWord) {
        drawHangman(wrongGuesses);
        cout << "Guessed word: " << guessedWord << endl;
        cout << "Wrong guesses: " << wrongGuesses << "/" << maxWrong << endl;
        cout << "Enter a letter: ";
        char guess;
        cin >> guess;

        bool alreadyGuessed = false;
        for (char c : guessedLetters) {
            if (c == guess) {
                alreadyGuessed = true;
                cout << "You already guessed that letter!" << endl;
                break;
            }
        }
        if (alreadyGuessed) continue;

        guessedLetters.push_back(guess);

        bool found = false;
        for (size_t i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                found = true;
            }
        }

        if (!found) {
            wrongGuesses++;
            cout << "Wrong letter!" << endl;
        }
    }

    drawHangman(wrongGuesses);
    if (guessedWord == secretWord) {
        cout << "Congratulations! You won!" << endl;
    } else {
        cout << "You lost! The word was: " << secretWord << endl;
    }

    return 0;
}