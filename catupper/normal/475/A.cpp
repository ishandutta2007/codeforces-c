#include<iostream>
#include<algorithm>

using namespace std;
char a[1080];
int main(){
	int n;
	cin >> n;
	fill(a, a + 1080, '#');
	for(int i =1;i <= n;i++)a[i] = 'O';
	cout << "+------------------------+" << endl;
	cout << "|" << a[1] << "." << a[5] << "." << a[8] << "." << a[11] << "." << a[14] << "." << a[17] << "." << a[20] << "." << a[23] << "." << a[26] << "." << a[29] << "." << a[32] << ".|D|)" <<endl;
	cout << "|" << a[2] << "." << a[6] << "." << a[9] << "." << a[12] << "." << a[15] << "." << a[18] << "." << a[21] << "." << a[24] << "." << a[27] << "." << a[30] << "." << a[33] << ".|.|" <<endl;
	cout << "|" << a[3] << ".......................|" << endl;
	cout << "|" << a[4] << "." << a[7] << "." << a[10] << "." << a[13] << "." << a[16] << "." << a[19] << "." << a[22] << "." << a[25] << "." << a[28] << "." << a[31] << "." << a[34] << ".|.|)" <<endl;
	cout << "+------------------------+" << endl;
	return 0;
}