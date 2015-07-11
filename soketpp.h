
#pragma once

namespace Soketpp
{
	typedef unsigned char Byte;

	struct Error_t
	{
		size_t		line;
		const char *file;
		const char *function;
		const char *message;
		const char *fqname;		/* fully qualified function name */
	};

	struct Sokinfo_t
	{	
		int id;

		char host[8];
		char port[46];

		Error_t error;
	};

	struct Connection_t : Sokinfo_t
	{
		Connection_t();

		Connection_t(int id); 

		Connection_t(const char *host, const char *port);

		void Close();

		void Shutdown();
		
		void operator = (int id);
		
		void Setup(const char *host, const char *port);

		/* NULL terminated string */
		size_t Send(const char *str);

		/* block untill len byte is send */
		size_t Send(const Byte *hay, size_t len);

		size_t Send(const char *str, const char chdlm);

		/* send untill strdlm reached */
		size_t Send(const char *str, const char *strdlm);

		/* send byte <= len before timeout and return */
		size_t Send(const Byte *hay, size_t len, int timeout);

		size_t Send(const char *str, const char chdlm, int timeout);

		/* send untill strdlm reached with timeout */
		size_t Send(const char *str, const char *strdlm, int timeout);

		/* recv till connection close */
		size_t Recv(Byte *hay);

		/* block untill len byte recived */
		size_t Recv(Byte *hay, size_t len);

		size_t Recv(char *str, const char chdlm);

		size_t Recv(char *str, const char *strdlm);

		size_t Recv(Byte *hay, size_t len, int timeout);

		size_t Recv(char *str, const char chdlm, int timeout);

		size_t Recv(char *str, const char *strdlm, int timeout);

		~Connection_t();
	};

	struct Server_t : Sokinfo_t
	{
		Server_t();

		int Accept();

		Server_t(const char *host, const char *port);

		void Setup(const char *host, const char *port);
	};
}
