#pragma once
#include "RepoFile.h"

class RepoFileTXT : public RepoFile {
public:
	RepoFileTXT();
	RepoFileTXT(string fileName);
	~RepoFileTXT();
	void loadFromFile() ;
	void saveToFile();
};