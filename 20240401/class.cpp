#include<iostream>
#include<set>
#include<sstream>           //必須有該標頭檔案
#include<cstring>
using namespace std;
int main()
{
    string input = "5b1g0001,吳翎瑋,95,8,及格";
    istringstream stream(input);
    string s;
    while(stream>>s)           // 抽取stream中的值到s
    {
        cout<<s<<endl;      //依次輸出s
    }
    return 0;
}
