#include "SpaceSaving.h"
#include <ctime>
#include <fstream>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        cerr << "Error: Expected 3 Arguments" << endl;
        exit(1);
    }

    vector<string> input;

    ifstream ifs;
    ifs.open(argv[1]);
    if (!ifs)
    {
        cerr << "Open Failed" << endl;
        exit(1);
    }

    string line;
    while (true)
    {
        getline(ifs, line);
        if (!ifs)
        {
            break;
        }
        input.push_back(line);
    }

    int capacity = stoi(argv[2]);
    SpaceSaving obj(capacity);

    clock_t t;
    t = clock();
    for (auto &&id : input)
    {
        obj.spaceSaving(id);
    }
    t = clock() - t;

    double time = ((double)t) / CLOCKS_PER_SEC;

    cout << "Running time: " << 1e9 * time/input.size() << " nanoseconds." << "\n";
    cout << "\n";

    obj.print();

    return 0;
}
