
#include <cstdio>

#include "soketpp.h"

using namespace Soketpp;

int main(int argc, char *argv[])
{
   try
   {
      Connection_t conn;
      Server_t server(argv[1], "8080");
      
      for(;;)
      {
         char data[128] = {};
         printf("server %s %s %d\n", server.host, server.port, server.id);
         conn = server.Accept();
         printf("connection %s %s %d\n", conn.host, conn.port, conn.id);
         conn.Recv(data, ' ');
         printf("<%s>\n", data);
         conn.Send("Welcome to Soketpp\n");
      }
   }
   catch(Error_t err)
   {
      printf("%s() %ld %s\n", err.function, err.line, err.message);
   }
   return 0;
}
