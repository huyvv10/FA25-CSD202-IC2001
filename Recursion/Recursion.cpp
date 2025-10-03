#include <iostream>
using namespace std;

int factorial(int n){
	if (n==0)
		return 1;
	else
		return n*factorial(n-1);	
}

int fibonacii(int n){
	if (n<2)
		return n;
	else
		return fibonacii(n-1)+fibonacii(n-2);	
}

void HanoiTower(int n, char s, char d, char m){
	if (n==1)
		cout<<"Move disk "<<n<<" from "<<s<<" to "<<d<<endl;
	else{
		HanoiTower(n-1, s, m, d);
		cout<<"Move disk "<<n<<" from "<<s<<" to "<<d<<endl;
		HanoiTower(n-1, m, d, s);
	}	 
}

int main(){
	int i, n;
	cout<<"Input n = "; cin>>n;	
	cout<<n<<"! = "<<factorial(n)<<endl;
	
	for (i=0; i<n; i++)
		cout<<fibonacii(i)<<" ";
	cout<<endl;	
	HanoiTower(n, 'A', 'C', 'B');	
	return 0;
}
