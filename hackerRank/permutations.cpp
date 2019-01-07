#include<iostream>
#include<cstring>
#include<vector>


using namespace std;

string insertat(string word, char c, int i)
{
    string start = word.substr(0,i);
    string end = word.substr(i);
    return start + c + end;
}
vector<string> perm_insert(string str)
{
    vector<string> vperm;
    if(str.length() == 0 )
    {
        vperm.push_back("");
        return vperm;
    }
    char first= str.at(0);
    string remainder = str.substr(1);
    vector<string> list= perm_insert(remainder);
    for(vector<string> ::iterator word= list.begin();word != list.end();word++)
    {
        string w= *word;
        for(int j=0;j<=w.length();j++)
        {
            string s = insertat(w,first,j);
            vperm.push_back(s);
        }
    }
    return vperm;


}
void perm_swap(string str,int index)

{
    int i = 0;
    if( index == strlen(str.c_str()) )
    {
        cout<<str<<endl;;
        return;
    }
    for( i = index; i < strlen(str.c_str()); i++ )
    {
        swap( str[index], str[i] ); 
        perm_swap( str, index + 1 );
        swap( str[index], str[i] );
    }
    


}void getperms(string prefix,string remainder,vector<string>result)
{
       
        if(remainder.length()==0)
        {
            result.push_back(prefix);
        }
        int len = remainder.length();

        for(int i =0;i<len;i++)
        {
            string before = remainder.substr(0,i);
            string after = remainder.substr(i+1,len);
            char c = remainder.at(i);
            getperms(prefix +c,before+after,result);
        }
        for(int i =0;i<result.size();i++)
        {
            cout<<result[i]<<endl;
        }
}
int main()
{

    cout<<"---------------------"<<endl;
    vector<string> result=perm_insert("ABC");
    for(int i = 0;i<result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    cout<<"---------------------"<<endl;
    perm_swap("ABC",0);
    cout<<"---------------------"<<endl;
    vector<string> result2;
    getperms("","ABC",result2);
    cout<<"---------------------"<<endl;


    return 0;
}
