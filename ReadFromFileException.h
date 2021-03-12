#pragma once
#include <exception>
#include <string.h>

using namespace std;

class ReadFromFileException : public exception {
private:
	char* message;
public:
	ReadFromFileException(const char* message)
	{
		this->message = new char[strlen(message) + 1];
		strcpy_s(this->message, strlen(message) + 1, message);
	}

	~ReadFromFileException()
	{
		if (this->message != NULL)
		{
			delete[] this->message;
		}
	}

	virtual const char* what()
	{
		return message;
	}
};