#include <iostream>
using namespace std;

int main(void)
{
    //init
    int sum=0,cur=0,next,num;
    //input & algorithm
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>next;
        if(next>cur)
          sum+=(next-cur)*6;
        else
          sum+=(cur-next)*4;
        cur=next;
    }
    //output
    cout<<sum+5*num<<endl;
    return 0;
}