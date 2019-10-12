#include <iostream>
#include <map>
using namespace std;

map<int, long> answers;

void calculateAnswers() {
    for (unsigned int k = 0; k < 14; ++k) {
        long m = k + 1;
        bool correctAnswer = false;
        while (!correctAnswer) {
            long killPosition = 0;
            bool goodGuysSaved = true, goodGuyKilled = false;
            for (unsigned int i = 0; i < k and !goodGuyKilled; ++i) {
                killPosition = (killPosition + m - 1) % (2 * k - i);
                if (killPosition < k) {
                    goodGuysSaved = false;
                    goodGuyKilled = true;
                }
            }
            if (goodGuysSaved) {
                answers[k] = m;
                correctAnswer = true;
            }
            ++m;
        }
    }
}

void consultFromAnswers(int k) {
    cout << answers[k] << "\n";
}

int main() {
    int k;
    calculateAnswers();
    while (cin >> k and k != 0) consultFromAnswers(k);
    return EXIT_SUCCESS;
}
