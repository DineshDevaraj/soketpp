
#include <cstdio>

#include "soketpp.h"

using namespace Soketpp;

int main(int argc, char *argv[])
{
   try
   {
      for(int I = 0; I < 10; I++)
      {
         Connection_t conn(argv[1], "8080");
         printf("Connection id : %d\n", conn.id);
         conn.Send("Hello world! ");
         conn.Close();
      }
   }
   catch(Error_t err)
   {
      printf("%s() %u %s\n", err.function, err.line, err.message);
   }
   return 0;
}
