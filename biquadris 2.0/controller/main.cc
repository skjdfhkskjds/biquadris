#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
    for (int i = 0; i < argc; i++) {
        if (argv[i] == "-text") {

        } else if (argv[i] == "-seed") {
            i++;
            string seed = argv[i];
            
        } else if (argv[i] == "-scriptfile") {
            i++;
            ifstream file{argv[i]};
            
        } else if(argv[i] == "-scriptfile2") {
            i++;
            ifstream file{argv[i]};
            
        } else if (argv[i] == "-startlevel") {
            i++;
            int level = stoi(argv[i]);
        } else { //show text and graphics

        }
    }

}
