
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
			printf("socket descriptor %d\n", server.id);
			conn = server.Accept();
			printf("connection descriptor %d\n", conn.id);
			conn.Recv((Byte *)data, ' ');
			printf("<%s>\n", data);
		}
	}
	catch(Error_t err)
	{
		printf("%s() %u %s\n", err.function, err.line, err.message);
	}
	return 0;
}
