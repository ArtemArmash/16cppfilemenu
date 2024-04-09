#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
public:
	void CreateFile(string filename) {
		try {
			ofstream fout(filename);

			if (!fout.is_open())
			{
				throw runtime_error("Cant created file\n");
			}
			cout << "File created!\n";
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << endl;
		}
	}

	void WriteToFile(string filename, string TEXT) {
		try {
			ofstream fout(filename, iostream::app);

			if (!fout.is_open())
			{
				throw runtime_error("Cant opened file for write\n");

			}
			fout << TEXT << endl;
			cout << "Succefiled writed\n";
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << endl;
		}
	}

	void InfoforFile(string filename) {
		try {
			ifstream fin(filename);
			if (!fin.is_open())
			{
				throw runtime_error("Cant opened file for reading\n");
			}
			string tmp_text;
			cout << "Info in file: \n";
			while (getline(fin, tmp_text))
			{
				cout << tmp_text << endl;
			}
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << endl;
		}
	}
};

class Copy {
public:
	void CopyFile(string FileFirst, string FileLast) {
		ifstream fin(FileFirst);
		if (!fin.is_open())
		{
			throw runtime_error("Cant opened first file for reading\n");
		}
		ofstream fout(FileLast);
		if (!fout.is_open())
		{
			throw runtime_error("Cant opened last file for writing\n");
		}
		fout << fin.rdbuf();

		cout << "Copy from: " << FileFirst << " to " << FileLast << "Succefiled\n";
	}

};

int main() {
	int op;
	string text, namefile, firstfile, lastfile;
	FileHandler File;
	Copy copy;
	do
	{
		cout << "Menu: \n";
		cout << "1. Create file\n";
		cout << "2. Write to file\n";
		cout << "3. Print from file\n";
		cout << "4. Copy in file to file\n";
		cout << "5. Exit\n";

		cout << "Enter operation: ";
		cin >> op;
		cout << endl;
		try {
			switch (op)
			{
			case 1:
				cout << "Enter name file: ";
				cin >> namefile;
				File.CreateFile(namefile);
				break;
			case 2:
				cout << "Enter name file: ";
				cin >> namefile;
				cout << "\nEnter text to file: ";
				cin.ignore();
				getline(cin, text);
				File.WriteToFile(namefile, text);
				break;
			case 3:
				cout << "Enter name file: ";
				cin >> namefile;
				File.InfoforFile(namefile);
				break;
			case 4:
				cout << "Enter first file: ";
				cin >> firstfile;
				cout << "Enter last file: ";
				cin >> lastfile;
				copy.CopyFile(firstfile, lastfile);
				break;
			case 5:
				cout << "Exit!\n";
				break;

			}
		}
		catch (exception& e) {
			cerr << "Error: " << e.what() << endl;
		}
	} while (op != 5);
}