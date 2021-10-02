#include <bits/stdc++.h>
using namespace std;
int board[100][100];
int n; 
bool is_attacked(int a, int b, int m) {
	for(int i = 1; i <= m; i++) {
		if(board[i][b] == 1)
			return true;
		if(board[a][i] == 1)
			return true;
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) {
			if(i+j == a+b) {
				if(board[i][j] == 1)
					return false;
			}
			if(i-j == a-b) {
				if(board[i][j] == 1)
					return false;
			}
		}
	}
	return true;
}

bool NQueens(int m) {
	if(m == 0) {
		return true;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) {
			if(is_attacked(i, j, m) == false)
				board[i][j] = 1;
			if(NQueens(m-1))
				return true;
			board[i][j] = 0;
		}
	}
	return false;	
}

int main() {
	cin >> n;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			board[i][j] = 0;
		}
	}
	bool ok = NQueens(n);
	if(!ok) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cout << board[i][j] << " ";
			}
			cout << '\n';
		}
	}
}