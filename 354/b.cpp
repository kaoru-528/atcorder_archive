#include <bits/stdc++.h>

using namespace std;

struct Card {
    long long A, C, index;
};

bool compare(const Card &a, const Card &b) {
    if (a.A == b.A) {
        return a.C < b.C; 
    }
    return a.A < b.A; 
}

vector<Card> filterCards(vector<Card> &cards) {
    sort(cards.begin(), cards.end(), compare);

    vector<Card> filteredCards;
    for (const auto &card : cards) {
        while (!filteredCards.empty() && filteredCards.back().C > card.C) {
            filteredCards.pop_back();
        }
        filteredCards.push_back(card);
    }
    return filteredCards;
}

int main() {
    long long N;
    cin >> N;
    vector<Card> cards(N);

    for (int i = 0; i < N; ++i) {
        cin >> cards[i].A >> cards[i].C;
        cards[i].index = i + 1;
    }

    vector<Card> result = filterCards(cards);

    set <long long> s;
    cout << result.size() << endl;
    for (const auto &card : result) {
       s.insert(card.index);
    }
    for(auto x : s) {
         cout << x << " ";
    }
    cout << endl;

    return 0;
}
