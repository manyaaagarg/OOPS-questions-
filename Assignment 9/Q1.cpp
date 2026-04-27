#include <iostream>
#include <fstream>
using namespace std;
int main() {
ofstream fout("NUM.TXT");
for(int i=1; i<=200; i++) {
fout << i << " ";
}
fout.close();
cout << "Numbers written to file successfully.";
return 0;
}