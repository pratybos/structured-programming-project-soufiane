#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Player {
    vector<int> scores;
    int totalScore = 0;
    double averageScore = 0.0;
};

void calculateScores(vector<Player>& players, int rounds) {
    for (Player& player : players) {
        player.totalScore = 0;
        for (int score : player.scores) {
            player.totalScore += score;
        }
        player.averageScore = static_cast<double>(player.totalScore) / rounds;
    }
}

void displayScoreboard(const vector<Player>& players, int rounds) {
    cout << "Player |";
    for (int i = 1; i <= rounds; i++) {
        cout << " Round " << i << " |";
    }
    cout << " Total Score | Average Score" << endl;
    cout << string(12 + rounds * 10, '-') << endl;

    for (int i = 0; i < players.size(); i++) {
        cout << setw(6) << i + 1 << " |";
        for (int score : players[i].scores) {
            cout << setw(9) << score << " |";
        }
        cout << setw(12) << players[i].totalScore << " |" << setw(13) << fixed << setprecision(2) << players[i].averageScore << endl;
    }
}

void findHighestAndLowestScores(const vector<Player>& players, int rounds) {
    for (int i = 0; i < rounds; i++) {
        int highest = players[0].scores[i];
        int lowest = players[0].scores[i];

        for (const Player& player : players) {
            if (player.scores[i] > highest) highest = player.scores[i];
            if (player.scores[i] < lowest) lowest = player.scores[i];
        }

        cout << "Highest Score in Round " << i + 1 << ": " << highest << endl;
        cout << "Lowest Score in Round " << i + 1 << ": " << lowest << endl;
    }
}

int main() {
    const int playersCount = 5;
    const int roundsCount = 4;
    vector<Player> players(playersCount, Player{vector<int>(roundsCount)});

    // Input scores for each player and each round
    for (int i = 0; i < playersCount; i++) {
        cout << "Enter scores for Player " << i + 1 << " in " << roundsCount << " rounds:" << endl;
        for (int j = 0; j < roundsCount; j++) {
            cout << "Round " << j + 1 << ": ";
            cin >> players[i].scores[j];
        }
    }

    calculateScores(players, roundsCount);
    cout << endl;
    displayScoreboard(players, roundsCount);
    cout << endl;
    findHighestAndLowestScores(players, roundsCount);

    return 0;
}
