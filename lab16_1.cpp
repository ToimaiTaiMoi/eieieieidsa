#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
//เติมส่วนที่หายไปใน Function showData() โดยห้ามแก้ไขโครงสร้าง

void showData(double* x,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << x[i];
        if((i+1) % M == 0) cout << endl;
        else cout << " ";
    }
}
//เติมส่วนที่หายไปใน Function randData() โดยห้ามแก้ไขโครงสร้าง

void randData(double *x,int N,int M){
    for(int i = 0; i < N*M; i++){
        x[i] = (rand() %  101) * 0.01;
    }
}
//เติมเฉพาะ Function findRowSum() เท่านั้น
void findRowSum(const double *x, double *y, int N, int M) {
    for (int i = 0; i < N; i++) {
        y[i] = 0; 
    }
        for (int i = 0; i < N * M; i++) {
        if ((i + 1) % M == 0) {
            y[i / M] += x[i];
        } else {
            y[i / M] += x[i];
        }
    }
}
//เติมเฉพาะ Function findColSum() เท่านั้
void findColSum(const double *x , double *y , int N , int M){
    int j = 0 ;
    for (int k = 0 ; k < M ; k++){
        y[k] = 0 ;
    }
    
    for (int i = 0 ; i < N*M ; i++){
        y[j] += x[i] ;
        j = j + 1 ;
        if ((i+1) %M == 0){
            j = 0 ;
        }
    }
}