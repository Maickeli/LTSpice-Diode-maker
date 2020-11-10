#include "EditTextFile.h"

using namespace std;

string editFile(string inputStr, string path)
{
	ifstream ReadFile(path);
	if (ReadFile.fail())
	{
		return "File not found.";
	}
	string fullText;
	string testText;
	while (getline(ReadFile, testText))
	{
		if (testText.empty())
		{
			fullText.append("\n\n");
		}
		else
		{
			fullText.append(testText + '\n');
		}
	}
	ReadFile.close();

	size_t index = fullText.find_last_of('*');
	fullText.insert(index + 1, "\n" + inputStr);

	ofstream myfile;
	myfile.open(path); //C:/Users/Omistaja/Documents/testi.txt

	myfile << fullText;
	myfile.close();
	return "Component Added Successfully.";
}