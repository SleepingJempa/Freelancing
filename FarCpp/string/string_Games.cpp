/*
Chon drive C permission mikhast ba drive d kar mikonam 
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <random>
#include <string>
#include <set>

using namespace std;

// Constants
const int GamesCount = 3;
const string SECRET_WORD_FILE = "D:\\SecretWord.txt";
const string LONGEST_WORD_FILE = "D:\\Subsequence.txt";

// Games Enum
enum GAME {
    GUESSWORDGAME = 0,
    WORDSCRAMBLE  = 1,
    LONGESTINCREASINGSUBSEQUENCE = 2,
};

string getGameName(GAME type) {
    switch (type)
    {
    case GUESSWORDGAME:
        return "Guess Word";
    case WORDSCRAMBLE:
        return "Word Scramble";
    case LONGESTINCREASINGSUBSEQUENCE:
        return "Longest Increasing Subsequence";
    default:
        return "WrongUsage!!";
        break;
    }
}

enum SCRAMBLE {
    WORD = 0,
    HELP = 1
};

// Typedef
typedef struct Player Player;
typedef struct GameResult GameResult;
typedef struct StringGameManager StringGameManager;
typedef struct GuessWordGame GuessWordGame;
typedef struct WordScramble WordScramble;
typedef struct LongestIncreasingSubsequence LongestIncreasingSubsequence;


// Structs
struct GameResult {
    GAME type;
    int points;

    GameResult(GAME type, int points) : type(type), points(points) {}
};

// Structs
struct Player {
    string name;
    vector<struct GameResult> games;
    int score[GamesCount];

    void addResult(GAME type, int points);
};

struct GuessWordGame {
    int turn;
    bool running;
    bool win;
    int max_wrong;
    int found_chars;
    string word;
    string guess;
    string path;
    ifstream fin;

    GuessWordGame(string path) : turn(1), win(false), found_chars(0), path(path) {}

    void Start(Player& player);
    void Init();
    void Run();
};

struct WordScramble {
    bool running;
    int score;
    int index;
    string help;
    bool win;
    string word;
    string jumble;
    string path;
    vector<vector<string>> available_words;
    ifstream fin;

    WordScramble(string path) : score(0), running(false), win(false), path(path) {}

    void randomShuffle();

    void Start(Player& player);
    void Init();
    void Run();

    void Hint();
};

struct LongestIncreasingSubsequence {
    string word;
    string current_word;
    string path;
    int lisLength;
    ifstream fin;
    int score;
    bool running;
    set<string> all;

    LongestIncreasingSubsequence(string path) : path(path), score(0), running(false) {}

    // Prototype
    void Start(Player &player);
    void Init();
    void Run();

    void FindTheLIS();
    bool isLIS();
};

struct StringGameManager {
    bool running;
    Player player;

    StringGameManager(string name) {
        player.name = name;
        fill(player.score, player.score+3, 0);
        running = true;
    }
    
    void Start();
    void StartGuessWordGame();
    void StartWordScramble();
    void StartLongestIncreasingSubsequence();
    void ShowStats();
    void Close();
};

int main () {
    srand(time(NULL));

    cout << "Enter your name to enter the game.\n";
    string name;
    cin >> name;
    StringGameManager manager(name);
    while(manager.running) manager.Start();
}

void StringGameManager::Start() {
    printf(":: %s \n", player.name.c_str());
    printf("Game Menu\n");
    printf("1. Guess Word\n");
    printf("2. Word Scramble\n");
    printf("3. Longest Increasing Subsequence\n");
    printf("4. Show Stats\n");
    printf("5. Exit\n");

    
    int cmd;
    cin >> cmd;

    switch (cmd) {
        case 1:
            StartGuessWordGame();
            break;
        case 2:
            StartWordScramble();
            break;
        case 3:
            StartLongestIncreasingSubsequence();
            break;
        case 4:
            ShowStats();
            break;
        case 5:
            Close();
            return;
        default:
            break;
    }
}

void StringGameManager::StartGuessWordGame() {
    GuessWordGame game("SecretWord.txt");
    game.Start(player);
}

void StringGameManager::StartWordScramble() {
    WordScramble game("HintWords.txt");
    game.Start(player);
}

void StringGameManager::StartLongestIncreasingSubsequence() {
    LongestIncreasingSubsequence game("Subsequence.txt");
    game.Start(player);
}

void StringGameManager::ShowStats() {
    cout << "=-=-=-=-=-=-=" << endl;
    cout << "=-= Stats =-=" << endl;
    cout << "Player " << player.name << endl;
    
    for(int game = 0; game < GamesCount; game++) {
        cout << getGameName((GAME)game) << " = " << player.score[game] << endl;
    }

    cout << "=-=-=-=-=-=-=" << endl;
}

void LongestIncreasingSubsequence::Start(Player &player) {
    Init();

    cout << "Welcome to Longest Increasing Subsequence game!\n\n";
    cout << "Find the Longest Increasing Subsequences in this word: " << word << "\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The String is: " << word;

    while(running) {
        Run();
    }

    cout << "Game finished!\n\n";
    cout << "Your score: " << score << endl;

    player.addResult(LONGESTINCREASINGSUBSEQUENCE, score);
}

void LongestIncreasingSubsequence::Run() {
    cout << "\n\nYour answer: ";
    cin >> current_word;

    if (current_word == "quit") {
        running = false;
        return;
    }

    if (isLIS()) {
        if (all.find(current_word) == all.end()) {
            cout << "Yay! Your answer is correct. +10 Points\n";
            score += 10;
            all.insert(current_word);
        } else {
            cout << "Dude! You entered this answer before. Try a new one\n";
        }
    } else {
        cout << "Oups, Wrong. -1 Point\n";
        score--;
    }
}

bool LongestIncreasingSubsequence::isLIS() {
    for(int i = 1; i < current_word.size(); i++) {
        if (current_word[i] <= current_word[i-1]) return false;
    }
    return current_word.size() == lisLength;
}

void LongestIncreasingSubsequence::FindTheLIS() {
    int n = word.size();
    vector<int> dp(26);
    lisLength = INT_MIN;
    for (int i = 0; i < n; i++) {
        int val = word[i] - 'a';
        int cur = 0;
        for (int j = 0; j < val; j++) {
            cur = max(cur, dp[j]);
        }
        cur++;
        lisLength = max(lisLength, cur);
        dp[val] = max(dp[val], cur);
    }
}

void LongestIncreasingSubsequence::Init() {
    fin.open(path);

    fin >> word;
    FindTheLIS();

    fin.close();

    running = true;
}

void WordScramble::randomShuffle() {
    jumble = word;
    shuffle(jumble.begin(), jumble.end(), default_random_engine(rand() % jumble.size()));
}

void StringGameManager::Close() {
    running = false;
}

void WordScramble::Start(Player& player) {
    Init();
    
    cout << "\t\t\tWelcome to Word Scramble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter 'hint' to get help. (3 Points)\n";
    cout << "Enter 'quit' to exit.\n";
    cout << "Your scramble word is: " << jumble;
    cout << "\n\nYour guress: ";

    while(running) {
        Run();
    }

    if (win) {
        score += 20;
        printf("You won! +%d Score\n", score);
    } else {
        printf("You Lose! No Points Gained.\n");
    }

    printf("Your score: %d\n", score);

    player.addResult(WORDSCRAMBLE, score);
}

void WordScramble::Init() {
    fin.open(path);

    int n;
    fin >> n;

    available_words.resize(n, vector<string>(2));

    string current;
    getline(fin, current);

    for(int i = 0; i < n; i++) {
        getline(fin, current);

        int comma = current.find(",");
        available_words[i][WORD] = current.substr(0, comma);
        available_words[i][HELP] = current.substr(comma + 1);
    }

    index = rand() % n;
    word = available_words[index][WORD];
    help = available_words[index][HELP];

    randomShuffle();

    running = true;
}

void WordScramble::Run() {
    cout << "Enter your guess:" << endl;

    string input;
    cin >> input;

    if (input == word) {
        win = true;
        running = false;
    } else if (input == "hint") {
        cout << "You're getting a hint. -3 Pts" << endl;
        Hint();
        printf("Your score to now: %d\n", score);
    } else if (input == "quit") {
        running = false;
    } else {
        cout << "No no! -1" << endl;
        score--;
        printf("Your score to now: %d\n", score);
    }
}

void WordScramble::Hint() {
    cout << "Hint: " << available_words[index][HELP] << endl;
    score -= 3;
}

void GuessWordGame::Start(Player& player) {
    fin.open(path);

    Init();

    while(running) {
        Run();
    }

    fin.close();

    if (win) {
        printf("You won! +1 Point\n");
    } else {
        printf("You Lose! No Points Gained.\n");
    }

    printf("The answer was %s\n", word.c_str());

    player.addResult(GUESSWORDGAME, win);
}

void GuessWordGame::Init() {
    int n;
    fin >> n;

    vector<string> words(n);

    for(int i = 0; i < n; i++) {
        fin >> words[i];
    }

    fin >> max_wrong;

    word = words[rand() % n];
    guess = string(word.length(), '-');

    running = true;
}

void GuessWordGame::Run() {
    printf("Turn : %d / %d\n", turn, max_wrong);

    if (turn == max_wrong) {
        printf("Last turn\n");
        running = false;
    }

    printf("-=-=-=-=-=-=-=-\n");
    if (turn == 1) {
        printf("You're about to start the game.\n");
    } else {
        printf("Your guessed word until now\n");
        for(char c : guess) {
            printf("%c ", c);
        }
        printf("\n");
    }
    printf("-=-=-=-=-=-=-=-\n");

    printf("Enter your guess: ");
    string current_guess;
    cin >> current_guess;

    found_chars = 0;

    int n = word.length();
    int m = current_guess.length();

    for(int i = 0; i < min(n, m); i++) {
        if (word[i] == current_guess[i]) {
            guess[i] = word[i];
            found_chars++;
        }
    }

    if (found_chars > 0) {
        printf("Good, you had guessed %d characters correct.\n", found_chars);
    } else {
        printf("Sorry! Your guess is not similar to the secret word.\n");
    }

    if (found_chars == n) {
        printf("You guessed correct!\n");
        win = true;
        running = false;
        return;
    }

    turn++;
}

void Player::addResult(GAME type, int points) {
    score[type] += points;
    games.push_back(GameResult(type, points));
}