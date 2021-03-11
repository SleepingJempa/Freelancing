#include <iostream>

using namespace std;


int voting_fun() {
    const int N = 100, M = 5;
    int votes[M] = {0}; // 5 candidates

    // get vote info from input 100 times
    for(int i = 0; i < N; i++) {
        printf("Person number %d, please vote to one of the candidates\n", i+1);
        printf("1.John Smith\n");
        printf("2.John Smith\n");
        printf("3.John Smith\n");
        printf("4.John Smith\n");
        printf("5.John Smith\n");
        
        int v;
        cin >> v;

        // get input from the i-th voter
        if (v >= 1 && v <= 5) {
            votes[v-1]++;
        } else {
            printf("Invalid number\n");
            i--;
        }
    }

    // finding the best candidates
    int bestCandidate = 0, bestIndex = 0;
    for(int i = 0; i < M; i++) {
        if (votes[i] > bestCandidate) {
            bestCandidate = votes[i];
            bestIndex = i;
        }
    }

    return bestIndex + 1;
}

int main() {
    cout << voting_fun() << endl;
}