#include<iostream>
#include<set>
#include<sstream>           //�������Ӽ��Y�ɮ�
#include<cstring>
using namespace std;
int main()
{
    string input = "5b1g0001,�d��޳,95,8,�ή�";
    istringstream stream(input);
    string s;
    while(stream>>s)           // ���stream�����Ȩ�s
    {
        cout<<s<<endl;      //�̦���Xs
    }
    return 0;
}
