
#include <cstdio>

#include "soketpp.h"

using namespace Soketpp;

int main(int argc, char *argv[])
{
   try
   {
      for(int I = 0; I < 10; I++)
      {
         char data[128] = {};
         Connection_t conn(argv[1], "8080");
         printf("Connection %s %s %d\n", conn.host, conn.port, conn.id);
         conn.Send("Hello world! ");
         conn.Recv(data, '\n');
         printf("%s", data);
      }
   }
   catch(Error_t err)
   {
      printf("%s() %ld %s\n", err.function, err.line, err.message);
   }
   return 0;
}
