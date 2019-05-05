#include<iostream>
using namespace std;
int findway(int xs, int ys, int xd, int yd);
int map[100][100]={0};
int n;
int main(){
	int xs,ys,xw,yw,xd,yd;
	char c;
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> c;
			if (c == 'K'){
				xs = i;
				ys = j;
			}
			if (c == 'W'){
				xw = i;
				yw = j;
			}
			if (c == '.' && (i == 0||j == 0||i == n-1||j == n-1)){
				xd = i;
				yd = j;
			}
			if (c == '#'){
				map[i][j] = -1;
			}
		}
	}
	cout << findway(xs,ys,xw,yw) + findway(xw,yw,xd,yd) << endl;
	return 0;
}
int findway(int xs, int ys, int xd, int yd){
	bool check[100][100] = {false};
	check[xs][ys] = true;
	int queuex[10000] = {0};
	int queuey[10000] = {0};
	int head = 0;
	int tail = 1;
	int count = 0;
	int deptail = 1;
	queuex[head] = xs;
	queuey[head] = ys;
	check[xs][ys] = true;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (map[i][j] < 0){
				check[i][j] = true;
			}
		}
	}
	while (true){
		for (int i=head; i<deptail; i++){
			if (queuex[i] == xd && queuey[i] == yd){
				return count;
			}
			if (not check[queuex[i]+1][queuey[i]]){
				queuex[tail] = queuex[i] + 1;
				queuey[tail] = queuey[i];
				check[queuex[i]+1][queuey[i]] = true;
				tail++;
			}
			if (not check[queuex[i]][queuey[i]+1]){
				queuex[tail] = queuex[i];
				queuey[tail] = queuey[i] + 1;
				check[queuex[i]][queuey[i]+1] = true;
				tail++;
			}
			if (not check[queuex[i]-1][queuey[i]]){
				queuex[tail] = queuex[i] - 1;
				queuey[tail] = queuey[i];
				check[queuex[i]-1][queuey[i]] = true;
				tail++;
			}
			if (not check[queuex[i]][queuey[i]-1]){
				queuex[tail] = queuex[i];
				queuey[tail] = queuey[i] - 1;
				check[queuex[i]][queuey[i]-1] = true;
				tail++;
			}
		}
		head = deptail;
		deptail = tail;
		count++;
	}
}