#include <iostream>
#include <string>
#include <string.h>
using namespace std;
 
//convert int to char
char int2char(int n){
  if(n>=0&&n<=9)
    return '0'+n;
  else
    return 'A'+n-10;
}

string convertMars(int value){
  string Mars;
  int residue,radix=13;
  //output format control
  if(value<=radix){
    Mars.insert(Mars.begin(),int2char(value));
    Mars.insert(Mars.begin(),'0');
  }
  else{
    while(value>0){
      residue=value%radix;
      Mars.insert(Mars.begin(),int2char(residue));
      value/=radix;
    }
  }
  return Mars;
}
 
int main(){
  //init
  int r,g,b;
  //input
  cin>>r>>g>>b;
  //algorithm & output
  cout<<"#"<<convertMars(r)<<convertMars(g)<<convertMars(b);
  return 0;
}