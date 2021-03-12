#pragma once
#include <exception>
#include <string.h>

using namespace std;

class ValidationException : public exception {
private:
	char* message;
public:
	ValidationException(const char* message)
	{
		this->message = new char[strlen(message) + 1];
		strcpy_s(this->message, strlen(message) + 1, message);
	}

	~ValidationException()
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