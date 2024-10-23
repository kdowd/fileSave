
#include <fstream> 
#include <iostream> 
#include <filesystem>

// for simplicity 
using namespace std;
using namespace std::filesystem;


int main()
{

	//https://www.sandordargo.com/blog/2024/02/28/std-filesystem-part1-paths-and-operations

	filesystem::path directorypath = "mydirectory";

	if (!exists(directorypath)) {
		create_directory(directorypath);
		cout << "Directory created: " << directorypath << endl;
	}

	if (exists(directorypath) && is_directory(directorypath)) {

		for (const auto& entry : directory_iterator(directorypath)) {

			if (entry.is_regular_file()) {
				cout << "File: " << entry.path() << endl;
			}
		}
	}


	cout << filesystem::current_path() << '\n';
	cout << __FILE__ << '\n';
	cout << filesystem::path(__FILE__).remove_filename() << '\n';




}

