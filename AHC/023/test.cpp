#include <iostream>
#include<string>
#include<algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

// testの方針：作物１つを植える。ただし、D-Sが最も大きいものを植える

struct Scores{
       int ex_pos; // 作物番号 - 1
       int num; // スコアの最大値
};

// 比較関数を定義
bool operator>(const Scores& a1, const Scores& a2) {
    if (a1.num > a2.num) return true;
    else return false;
}

// 変数定義
int T = 100;
int H = 20;
int W = 20;
int i0 = 10000;
int h[20 - 1][20], v[20][20 - 1];
int K = 40000;
int SD[40000][2];
vector<Scores> maxscore_rows(40000);

void sort_maxscore() {
    // 潜在的なスコアの高い順に作物番号を並び変える
    for (int i = 0; i < K; i++) {
        maxscore_rows[i].ex_pos = i + 1; // 作物番号
        maxscore_rows[i].num = SD[i][1] - SD[i][0] + 1;
        // テストコード
        //cout << maxscore_rows[i].num << endl;
    }
    sort(maxscore_rows.begin(), maxscore_rows.end(), greater<Scores>());
}

int main() {
    cin >> T >> H >> W >> i0;
    /*
    for (int i = 0; i < H-1; i++) {
        for (int j = 0; j < W; j++) {
            cin >> h[i][j];
        }
    } 
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W-1; j++) {
            cin >> v[i][j];
        }
    } */
    for (int i = 0; i < H-1; i++) {
        cin >> h[i][0];
    } 
    for (int i = 0; i < H; i++) {
        cin >> v[i][0];
    } 
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> SD[i][0] >> SD[i][1];
    }
    
    sort_maxscore();

    cout << 1 << endl;
    cout << to_string(maxscore_rows[0].ex_pos) << " " << to_string(i0) << " 0 1" << endl;

    return 0;
}