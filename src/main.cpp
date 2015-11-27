#include <iostream>
#include <chrono>
#include <iostream>
#include <algorithm>

char comp(char c)
{
    if(c == 'A')
	return 'T';
    else if(c == 'C')
	return 'G';
    else if(c == 'T')
	return 'A';
    else
	return 'C';
}

char tmp;

std::string reverse_copy(std::string data)
{
    for(long unsigned int begin = 0, end = data.length() - 1; begin <= end; begin++, end--)
    {
	tmp = comp(data[begin]);
	data[begin] = comp(data[end]);
	data[end] = tmp;
    }

    return data;
}

std::string reverse_ref(std::string& data)
{
    for(long unsigned int begin = 0, end = data.length() - 1; begin <= end; begin++, end--)
    {
        tmp = comp(data[begin]);
	data[begin] = comp(data[end]);
	data[end] = tmp;
    }

    return data;
}

int main(int argc, char* argv[])
{
    int repeat = std::stoll(std::string(argv[1]));
    std::string data(argv[2]);

    auto begin = std::chrono::high_resolution_clock::now();
    
    for(auto i = 0; i != repeat; i++)
    {
	reverse_copy(data);
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - begin;

    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<"by copy "<<duration<<std::endl;

    begin = std::chrono::high_resolution_clock::now();
    
    for(auto i = 0; i != repeat; i++)
    {
	reverse_ref(data);
    }

    elapsed = std::chrono::high_resolution_clock::now() - begin;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<"by ref "<<duration<<std::endl;

}

