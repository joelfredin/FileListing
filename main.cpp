#include<iostream>
#include"boost/filesystem.hpp"
#include<ctime>
#include<vector>

using namespace boost::filesystem;

int main(int argc, char* argv[])
{
    path p (argv[1]);
    directory_iterator it{p};

    typedef std::vector<path> vec;
    vec v;

    copy(it, directory_iterator(),back_inserter(v));

    sort(v.begin(), v.end());

    for(vec::const_iterator i (v.begin()); i != v.end(); ++i)
    {
        if(!is_directory((*i)))
        {
            std::cout << "Filename: " << (*i).filename() << '\n';
            std::cout << "Size:     " << (*i).size() << '\n';
            std::cout << "Time:     " << last_write_time(*i) << '\n';
            std::cout << "Type:     " << (*i).extension() << '\n' << '\n' << '\n';
        }
    }

    return 0;
}
