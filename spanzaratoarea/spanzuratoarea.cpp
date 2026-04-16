#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// Display game instructions
void displayInstructions() {
    cout << "\n╔════════════════════════════════════════════════════╗\n";
    cout << "  ║        🎮 HANGMAN GAME - HOW TO PLAY 🎮           ║\n";
    cout << "  ╚════════════════════════════════════════════════════╝\n\n";
    
    cout << "📌 OBJECTIVE:\n";
    cout << "   Guess the secret word letter by letter!\n\n";
    
    cout << "⚙️ HOW TO PLAY:\n";
    cout << "   1. The computer picks a random word\n";
    cout << "   2. Enter ONE LETTER per turn\n";
    cout << "   3. Correct letter → its position is revealed\n";
    cout << "   4. Wrong letter → the hangman gets closer!\n";
    cout << "   5. You have maximum 6 MISTAKES before losing\n\n";
    
    cout << "🎯 WINNING & LOSING:\n";
    cout << "   ✅ WIN: Guess the word before 6 wrong guesses\n";
    cout << "   ❌ LOSE: Make 6 wrong guesses\n\n";
    
    cout << "📝 IMPORTANT RULES:\n";
    cout << "   • Enter ONLY ONE LETTER per turn\n";
    cout << "   • You cannot repeat a letter you already guessed\n";
    cout << "   • Uppercase and lowercase are the same\n";
    cout << "   • Only letters (a-z) are accepted\n\n";
    
    cout << "📊 WHAT YOU'LL SEE ON SCREEN:\n";
    cout << "   - The hangman drawing (grows with each mistake)\n";
    cout << "   - The word with revealed letters: progra_ing\n";
    cout << "   - Remaining mistakes: 3 out of 6\n";
    cout << "   - Wrong letters: x, z, q\n\n";
    
    cout << "💡 TIPS & STRATEGY:\n";
    cout << "   ★ Start with vowels: A, E, I, O, U\n";
    cout << "   ★ Then try common letters: N, R, T, S, L\n";
    cout << "   ★ Think of common words from computing\n";
    cout << "   ★ Calculate risk - be careful with few attempts left!\n\n";
    
    cout << "═══════════════════════════════════════════════════════\n\n";
}

// Display the hangman drawing
void displayHangman(int mistakes) {
    cout << "\n";
    cout << "   ┌─────────┐\n";
    cout << "   │         │\n";
    
    if (mistakes >= 1) cout << "   │         O\n";
    else cout << "   │         \n";
    
    if (mistakes >= 3) cout << "   │        /";
    else cout << "   │         ";
    
    if (mistakes >= 2) cout << "|";
    else cout << " ";
    
    if (mistakes >= 4) cout << "\\\n";
    else cout << "\n";
    
    if (mistakes >= 5) cout << "   │        /";
    else cout << "   │         ";
    
    if (mistakes >= 6) cout << " \\\n";
    else cout << "\n";
    
    cout << "   │\n";
    cout << "   └─────────┘\n";
    cout << "   \n";
}

int main() {
    // Initialization
    srand(time(0));
    
    vector<string> words = {
        "programming",
        "computer",
        "informatics",
        "algorithm",
        "variable",
        "function",
        "structure",
        "terminal",
        "database",
        "internet",
        "python",
        "debug",
        "compiler",
        "runtime",
        "software",
        "hardware",
        "memory",
        "processor",
        "keyboard",
        "display"
    };
    
    // Pick a random word
    string secretWord = words[rand() % words.size()];
    int length = secretWord.length();
    
    // Game initialization
    string displayedWord(length, '_');
    vector<char> guessedLetters;
    vector<char> wrongLetters;
    int mistakes = 0;
    int maxMistakes = 6;
    bool won = false;
    
    cout << "\n╔════════════════════════════════════╗\n";
    cout << "║    🎮 WELCOME TO HANGMAN 🎮       ║\n";
    cout << "║  Guess the word before you lose!   ║\n";
    cout << "╚════════════════════════════════════╝\n";
    
    // Display instructions
    displayInstructions();
    
    // Game loop
    while (mistakes < maxMistakes && !won) {
        // Display
        displayHangman(mistakes);
        
        cout << "\nWord: " << displayedWord << "\n";
        cout << "Mistakes allowed: " << (maxMistakes - mistakes) << " / " << maxMistakes << "\n";
        
        if (!wrongLetters.empty()) {
            cout << "Wrong letters: ";
            for (char c : wrongLetters) {
                cout << c << " ";
            }
            cout << "\n";
        }
        
        // Read input
        cout << "\nEnter a letter: ";
        char letter;
        cin >> letter;
        
        // Convert to lowercase
        letter = tolower(letter);
        
        // Check if letter was already guessed
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
            cout << "You already guessed that letter!\n";
            continue;
        }
        
        guessedLetters.push_back(letter);
        
        // Check if letter is in word
        bool found = false;
        for (int i = 0; i < length; i++) {
            if (secretWord[i] == letter) {
                displayedWord[i] = letter;
                found = true;
            }
        }
        
        if (!found) {
            wrongLetters.push_back(letter);
            mistakes++;
            cout << "Wrong! The letter is not in the word.\n";
        } else {
            cout << "Correct! The letter is in the word.\n";
        }
        
        // Check if won
        if (displayedWord == secretWord) {
            won = true;
        }
    }
    
    // Game end
    displayHangman(mistakes);
    cout << "\n═════════════════════════════════════\n";
    
    if (won) {
        cout << "🎉 CONGRATULATIONS! YOU WON! 🎉\n";
        cout << "The word was: " << secretWord << "\n";
    } else {
        cout << "💀 GAME OVER! YOU LOST! 💀\n";
        cout << "The word was: " << secretWord << "\n";
    }
    
    cout << "═════════════════════════════════════\n";
    
    return 0;
}
