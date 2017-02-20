#include <iostream>
#include <string>
using namespace std;

int main(){
  long long a,b;
  cin>>a>>b;
  long long sum=a+b;
  if(sum==0){
    cout<<0<<endl;
    return 0;
  }
  if(sum<0) cout<<'-';
  string ans="";
  int cnt=0;
  while(sum!=0){
    ans+='0'+abs(sum%10);
    sum/=10;
    cnt++;
    if(cnt==3 && sum!=0){
      ans+=',';
      cnt=0;
    }
  }
  int len=ans.length();
  for(int i=len-1;i>=0;i--){
    cout<<ans[i];
  }
  cout<<endl;
  system("pause");
  return 0;
}