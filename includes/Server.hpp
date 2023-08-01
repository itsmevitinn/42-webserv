#pragma once

#include <string>
#include <netinet/in.h>
#include <exception>

/*
 * 'Server' class is responsable for
 * connections with clients (including
 * I/O operations) and redirections
 **/

class Server
{
private:
	int					_serverSocket;
	struct sockaddr_in	_address;
	socklen_t			_addrlen;

	/* config */

	int					_port;

public:
	Server( void );
	~Server();

	void init( std::string const & configFile );
	void start( void );

	class SocketFailed : public std::exception {
	public:
		char const * what() const throw();
	};
	class BindFailed : public std::exception {
	public:
		char const * what() const throw();
	};
	class ListenFailed : public std::exception {
	public:
		char const * what() const throw();
	};
	class AcceptFailed : public std::exception {
	public:
		char const * what() const throw();
	};
	class ReadFailed : public std::exception {
	public:
		char const * what() const throw();
	};
	class WriteFailed : public std::exception {
	public:
		char const * what() const throw();
	};
};
