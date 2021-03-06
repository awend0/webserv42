#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

#include "../Includes/webserv.hpp"


struct Location {

	std::string						path;
	std::string						root;
	std::vector< std::string >		index;
	std::string						cgi_path;
	std::string						cgi_ext;
	std::string						alias;
	std::vector< std::string >		methods;
	std::map< int, std::string >	error_pages;
	std::vector< Location >			locations;
	int								authorization;
	int								autoindex;
	int								max_body_size;


	// MARK: - Static Struct Methods

	static Location	getTestConfig( void );

	friend std::ostream	&operator << ( std::ostream &out, const Location &loc );

};


struct ServerConfig {
	
	std::string						host;
	std::string						name;
	std::string						port;
	std::string						root;
	std::vector< std::string >		index;
	std::map< int, std::string >	error_pages;
	std::vector< Location >			locations;
	std::vector<std::string>		locationdirs;
	int								autoindex;
	int								max_body_size;


	// MARK: - struct methods

	Location	getLocation( const std::string &path ) const;


	// MARK: - static struct methods

	static ServerConfig	getTestConfig( std::string port );

	friend std::ostream	&operator << ( std::ostream &out, const ServerConfig &conf );

};


struct Config {

	std::vector< ServerConfig >		servers;
	std::map< int, std::string >	error_pages;
	std::string						root;
	std::vector< std::string >		index;
	int								autoindex;
	int								max_body_size;

	// MARK: - Static Struct Methods

	static Config	getTestConfig( void );

	ServerConfig getServerConf(std::string &host, std::string &port)
	{
		for (size_t i = 0; i < servers.size(); i++)
			if (host == this->servers[i].host && port == this->servers[i].port)
				return (this->servers[i]);
		return (this->servers[0]);
	}

	friend std::ostream	&operator << ( std::ostream &out, const Config &conf );

};
