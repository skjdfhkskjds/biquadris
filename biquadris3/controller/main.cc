#include <iostream>
#include <vector>
#include <string>
// #include "game.h"
#include "../common/coordinates.h"

using namespace std;

void print(vector<Coordinates> coords)
{
    for (auto &c : coords)
    {
        c.print();
    }
}

vector<Coordinates> foo(vector<Coordinates> coords)
{
    for (auto &c : coords)
    {
        c.update(c.getX() + 1, c.getY() + 1);
    }
    return coords;
}

int main(int argc, char ** argv)
{
    vector<Coordinates> coords;
    Coordinates a{0, 0};
    Coordinates b{1, 0};
    Coordinates c{1, 1};
    Coordinates d{2, 1};
    
    coords.emplace_back(a);
    coords.emplace_back(b);
    coords.emplace_back(c);
    coords.emplace_back(d);

    print(coords);
    coords = foo(coords);
    print(coords);

    // for (int i = 1; i < argc; i++)
    // {

    // }
    // Game g{};
    // int winner = g.run();
}

/*

int main(int argc, char **argv)
{
    vector<string> seq;
    string file1 = "sequence1.txt";
    string file2 = "sequence2.txt";
    int seed = 0;
    int startLvl = 0;
    bool graphics = true;
    for (int i = 0; i < argc; i++)
    {
        if (argv[i] == "-text")
        {
            bool graphics = false;
        }
        else if (argv[i] == "-seed")
        {
            i++;
            seed = stoi(argv[i]);
        }
        else if (argv[i] == "-scriptfile")
        {
            i++;
            file1 = argv[i];
        }
        else if (argv[i] == "-scriptfile2")
        {
            i++;
            file2 = argv[i];
        }
        else if (argv[i] == "-startlevel")
        {
            i++;
            startLvl = stoi(argv[i]);
        }
        else
        {
            string command = argv[i];
            throw command_not_found(command);
        }
    }
    seq.emplace_back(file1);
    seq.emplace_back(file2);
    Game bisexual(seq, seed, startLvl);
    string s;
    Commands commander;
    if (graphics) {
        unique_ptr<AbstractBoard> abstractBoard1;
        unique_ptr<AbstractBoard> abstractBoard2;
        


    }
    while (cin >> s)
    {
        istringstream iss{s};
        commander.interpret(s);
    }

}

*/
