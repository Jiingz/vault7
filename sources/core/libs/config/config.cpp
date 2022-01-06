// ConfigTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "config.h"

/*
*****************************************************
*												 	*
*	Configparser by Saeurenmensch				 	*
*												 	*
*	pls credit me if you're going to use this ;-)	*
*												 	*
*****************************************************
*/


Config::Config()
{
	this->strConfigPath = ""; // Configpath leermachen da nichts �bergeben wurde
}



Config::Config(std::string configpath, confParams configMode)
{
	//modus setzen
	this->e_confparams = configMode;

	this->strConfigPath = configpath; // strConfigPath auf den �bergebenen path setzen

	// filestreams �ffnen

	switch (this->e_confparams) // switch f�r die parameter
	{
	case CONFIG_READ: // nur lesen
		this->OpenInputStream();
		break;
	case CONFIG_WRITE: // nur schrieben
		this->OpenOutputStream();
		break;
	case CONFIG_READWRITE: //lesen und schreiben
		this->OpenInputStream();
		this->OpenOutputStream();
		break;
	default: // default wenn davon nix ist.
		break;
	}




}

Config::~Config() // schliest die streams
{
	//filestreams schlie�en
	this->CloseInputStream();
	this->CloseOutputStream();
}

std::string Config::GetPath() // gibt den path der config zur�ck
{
	return this->strConfigPath; // returnt den strConfigPath
}

void Config::SetParam(confParams Params)
{
	this->e_confparams = Params;
}

void FORCEINLINE Config::CloseOutputStream()
{
	if (this->e_confparams == CONFIG_WRITE || this->e_confparams == CONFIG_READWRITE)
	{
		this->outputFileStream.close();
	}
}


void FORCEINLINE Config::CloseInputStream()
{
	if (this->e_confparams == CONFIG_READ || this->e_confparams == CONFIG_READWRITE)
	{
		this->inputFileStream.close();
	}
}

void FORCEINLINE Config::OpenOutputStream()
{
	if (this->e_confparams == CONFIG_WRITE || this->e_confparams == CONFIG_READWRITE)
	{
		this->outputFileStream = std::ofstream(this->strConfigPath, std::ios::out); // outputstream �ffnen
	}
}

void FORCEINLINE Config::OpenInputStream()
{
	if (this->e_confparams == CONFIG_READ || this->e_confparams == CONFIG_READWRITE)
	{
		this->inputFileStream = std::ifstream(this->strConfigPath, std::ios::in); // inputstream �ffnen
	}
}