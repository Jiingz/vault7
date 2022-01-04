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


cConfig::cConfig()
{
	this->strConfigPath = ""; // Configpath leermachen da nichts �bergeben wurde
}



cConfig::cConfig(std::string configpath, confParams configMode)
{
	//modus setzen
	this->e_confparams = configMode;

	this->strConfigPath = configpath; // strConfigPath auf den �bergebenen path setzen

	// filestreams �ffnen

	switch (this->e_confparams) // switch f�r die parameter
	{
	case CONFIG_READ: // nur lesen
		this->openInputStream();
		break;
	case CONFIG_WRITE: // nur schrieben
		this->openOutputStream();
		break;
	case CONFIG_READWRITE: //lesen und schreiben
		this->openInputStream();
		this->openOutputStream();
		break;
	default: // default wenn davon nix ist.
		break;
	}




}

cConfig::~cConfig() // schliest die streams
{
	//filestreams schlie�en
	this->closeInputStream();
	this->closeOutputStream();
}

std::string cConfig::getPath() // gibt den path der config zur�ck
{
	return this->strConfigPath; // returnt den strConfigPath
}

void cConfig::setParam(confParams Params)
{
	this->e_confparams = Params;
}

void FORCEINLINE cConfig::closeOutputStream()
{
	if (this->e_confparams == CONFIG_WRITE || this->e_confparams == CONFIG_READWRITE)
	{
		this->outputFileStream.close();
	}
}


void FORCEINLINE cConfig::closeInputStream()
{
	if (this->e_confparams == CONFIG_READ || this->e_confparams == CONFIG_READWRITE)
	{
		this->inputFileStream.close();
	}
}

void FORCEINLINE cConfig::openOutputStream()
{
	if (this->e_confparams == CONFIG_WRITE || this->e_confparams == CONFIG_READWRITE)
	{
		this->outputFileStream = std::ofstream(this->strConfigPath, std::ios::out); // outputstream �ffnen
	}
}

void FORCEINLINE cConfig::openInputStream()
{
	if (this->e_confparams == CONFIG_READ || this->e_confparams == CONFIG_READWRITE)
	{
		this->inputFileStream = std::ifstream(this->strConfigPath, std::ios::in); // inputstream �ffnen
	}
}