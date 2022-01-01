#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double mat[][N]){
	for(int i = 0 ; i < N; i++){
		cout << "Row " << i+1 << ": ";
		for(int j = 0; j < N; j++) 
			cin >> mat[i][j];
	}
}

void findLocalMax(const double mat[][N], bool result[][N]){
	for(int i = 0; i < N; i++) result[0][i] = 0;
	for(int i = 0; i < N; i++) result[N-1][i] = 0;
	for(int j = 1; j < N-1; j++) result[j][0] = 0;
	for(int j = 1; j < N-1; j++) result[j][N-1] = 0;
	
	bool isLocalMax;
	for(int i = 1; i < N-1; i++){
		for(int j = 1; j < N-1; j++){
			isLocalMax = 1;
			isLocalMax &= (mat[i][j] >= mat[i-1][j]);
			isLocalMax &= (mat[i][j] >= mat[i+1][j]);
			isLocalMax &= (mat[i][j] >= mat[i][j-1]);
			isLocalMax &= (mat[i][j] >= mat[i][j+1]);
			if(isLocalMax){
				result[i][j] = 1;	
			}else{
				result[i][j] = 0;
			}
		}
	}
}

void showMatrix(const bool mat[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
}