#include <iostream>
#include<string>
#include<algorithm>
#include <vector>
#include <stdio.h>
#include <tuple>

using namespace std;

// testの方針：t_iを順番にすべてつなげる

int N = 15;
int M = 200;
int x = 0;
int y = 0;
string A_str;
string t_str;
char A_char[15 * 15];
//char A[15][15];
//vector<vector<char>> A(15, vector<char>(15));
string t[200];

// t_iをすべて結合したString t_allを作成する。
string concat_t() {
    string t_all;
    for (int i = 0; i < M; i++) {
        t_all += t[i];
    }
    return t_all;
}

// 任意のcharに対して、Aの中から位置i,jを検索する
tuple<int, int> find_A(char next_char) {
    // 愚直に前から順番に検索（計算量O(1000*N*N)）
    int char_x, char_y;
    for (int i = 0; i < N * N; i++) { 
        if (next_char == A_char[i]) {
            char_x = i / N;
            char_y = i % N;
            break;
        }
    }
    return make_tuple(char_x, char_y);
}

// t_allの先頭からcharを確認して、移動位置i,jを取得する
void get_ans(string t_all) {
    char next_char;
    for (int i = 0; i < t_all.length(); i++) {
        next_char = t_all[i];
        tie(x, y) = find_A(next_char);
        cout << x << ' ' << y << endl;
    }
}

int main() {
    cin >> N >> M;
    cin >> x >> y;
    for (int i = 0; i < N; i++) {
        cin >> A_str;

        for (int j = 0; j < N; j++) {
            A_char[15 * i + j] = A_str[j];
            //A[i][j] = A_str[j];
        }  
    }
    for (int i = 0; i < M; i++) {
        cin >> t_str;
        t[i] = t_str;
    }

    //cout << A_char[15];
    //cout << concat_t()[0];
    get_ans(concat_t());
 
    return 0;
}