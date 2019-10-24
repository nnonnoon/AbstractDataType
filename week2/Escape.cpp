#include <iostream>
using namespace std;

char* write_chars(char* dest, const char* st)
{
  
int i = 0 ;
while(st[i] != '\0'){
   *dest=st[i];
   dest++;
   i++;
}

  return dest;
}

void escape(char* src, char *dest)
{
  
int i = 0 ;
while(src[i] != '\0'){
  if (src[i] == '<'){
     dest = write_chars(dest , "&lt;");
  }
  else if (src[i] == '>'){
     dest = write_chars(dest , "&gt;");
  }
  else if (src[i] == '"'){
     dest = write_chars(dest ,"&quot;");
  }
  else {
    *dest = src[i];
    dest++;
  }
  i++;
}
*dest='\0';
}

int main()
{
  char st[1000];
  char out[1000];
  int l;

  cin.getline(st,1000);
  escape(st,out);

  cout << out << endl;
}