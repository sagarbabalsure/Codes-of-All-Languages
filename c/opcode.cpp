#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    string mnemonic[15]={"STOP","ADD","SUB","MULT","MOVER","MOVEM","COMP","BC","DIV","READ","PRINT"};
    string opco[15]={"00","01","02","03","04","05","06","07","08","09","10"};
    ofstream of;
    of.open("opcode.txt");
    for (int i = 0; i <= 15; ++i)
    {
        of<<mnemonic[i];
        // st<<" ";
        of<<opco[i]<<endl;
    }
    of.close();
    ifstream my_if;
    string s1,s2;
    cin>>s1;
   if (my_if.is_open())
      {
        while (getline(my_if,s1) )
        {
          // getline (my_if,s1);
          my_if>>s2;
          cout << s1 << endl;
          cout << s2 << endl;

        }
        my_if.close();
      }

    return 0;
}