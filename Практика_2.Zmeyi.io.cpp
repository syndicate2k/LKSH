#include <iostream>
#include <vector>

using namespace std;

int used[1000][1000];
char zmeyka[1000][1000];

int otr = 0;
int kol = 0;

void dfs(int i,int j, int n, int m, char symb){
	used[i][j] = 1;
	
	if (zmeyka[i][j+1]== symb && used[i][j+1] == false && j + 1 < m){
		kol++;
		dfs(i, j + 1, n, m, symb);
	}
	if (zmeyka[i][j-1] == symb && used[i][j-1]  == false && j - 1 >= 0){
		kol++;
		dfs(i, j - 1, n, m, symb);
	}
	
	if (zmeyka[i+1][j] == symb && used[i+1][j] == false && i + 1 < n){
		kol++;
		dfs(i + 1, j, n, m, symb);
	}
	if (zmeyka[i-1][j] == symb && used[i - 1][j] == false && i - 1 >= 0){
		kol++;
		dfs(i - 1, j, n, m, symb);
	}
	
	if ((j - 1 >= 0 && used[i][j - 1]) + (j + 1 < m && used[i][j + 1]) +
	     (i + 1 < n && used[i + 1][j]) + (i - 1 >= 0 && used[i - 1][j]) > 1) otr++;
}

int main(){
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> zmeyka[i][j];
		}
	}
	
	int max_dl = -1;
	int symb;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			otr = 0;
			kol = 0;
			
			if (zmeyka[i][j] != '.' && used[i][j] == false){
				dfs(i, j, n, m, zmeyka[i][j]);
				
				if(otr != 0 && (otr == kol + 1 || otr == kol)){
					kol = kol - 10000;
				}
			
				if(kol > max_dl){
					symb = zmeyka[i][j];
					max_dl = kol;
				}
			}
		}
	}
	
	if(max_dl == -1){
		cout << "NO" << endl;
	}else{
		max_dl += 1;
		cout << "YES" << endl;
		cout << (char)symb << " " << max_dl << endl;
	}
}
