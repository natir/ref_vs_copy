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

std::string reverse_copy_glob(std::string data)
{

    for(long unsigned int begin = 0, end = data.length() - 1; begin <= end; begin++, end--)
    {
        ::tmp = comp(data[begin]);
	data[begin] = comp(data[end]);
	data[end] = ::tmp;
    }

    return data;
}

std::string reverse_ref_glob(std::string& data)
{
    for(long unsigned int begin = 0, end = data.length() - 1; begin <= end; begin++, end--)
    {
	::tmp = comp(data[begin]);
	data[begin] = comp(data[end]);
	data[end] = ::tmp;
    }

    return data;
}

std::string reverse_copy_loc(std::string data)
{
    char tmp;
    
    for(long unsigned int begin = 0, end = data.length() - 1; begin <= end; begin++, end--)
    {
        tmp = comp(data[begin]);
	data[begin] = comp(data[end]);
	data[end] = tmp;
    }

    return data;
}

std::string reverse_ref_loc(std::string& data)
{
    char tmp;
    
    for(long unsigned int begin = 0, end = data.length() - 1; begin <= end; begin++, end--)
    {
	tmp = comp(data[begin]);
	data[begin] = comp(data[end]);
	data[end] = tmp;
    }

    return data;
}

class notused
{

public:
    char tmp;
    
public:
    notused()
	{
	    // do_nothing
	}

    std::string reverse_copy(std::string data)
	{

	    for(long unsigned int begin = 0, end = data.length() - 1; begin <= end; begin++, end--)
	    {
		this->tmp = comp(data[begin]);
		data[begin] = comp(data[end]);
		data[end] = this->tmp;
	    }

	    return data;
	}

    std::string reverse_ref(std::string& data)
	{
	    for(long unsigned int begin = 0, end = data.length() - 1; begin <= end; begin++, end--)
	    {
		this->tmp = comp(data[begin]);
		data[begin] = comp(data[end]);
		data[end] = this->tmp;
	    }

	    return data;
	}
};

class notused_static
{

public:
    static char tmp;
    
public:
    notused_static()
	{
	    // do_nothing
	}

    std::string reverse_copy(std::string data)
	{

	    for(long unsigned int begin = 0, end = data.length() - 1; begin <= end; begin++, end--)
	    {
		notused_static::tmp = comp(data[begin]);
		data[begin] = comp(data[end]);
		data[end] = notused_static::tmp;
	    }

	    return data;
	}

    std::string reverse_ref(std::string& data)
	{
	    for(long unsigned int begin = 0, end = data.length() - 1; begin <= end; begin++, end--)
	    {
		notused_static::tmp = comp(data[begin]);
		data[begin] = comp(data[end]);
		data[end] = notused_static::tmp;
	    }

	    return data;
	}
};

char notused_static::tmp = 'A';

int main(int argc, char* argv[])
{
    int repeat = std::stoll(std::string(argv[1]));
    std::string data(argv[2]);

    /* GLOBAL */
    /* Copy */
    auto begin = std::chrono::high_resolution_clock::now();
    
    for(auto i = 0; i != repeat; i++)
    {
	reverse_copy_glob(data);
    }

    auto elapsed = std::chrono::high_resolution_clock::now() - begin;

    long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<"by copy glob "<<duration<<std::endl;

    /* Ref */
    begin = std::chrono::high_resolution_clock::now();
    
    for(auto i = 0; i != repeat; i++)
    {
	reverse_ref_glob(data);
    }

    elapsed = std::chrono::high_resolution_clock::now() - begin;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<"by ref glob "<<duration<<std::endl;

    /* LOCAL */
    /* Copy */
    begin = std::chrono::high_resolution_clock::now();
    
    for(auto i = 0; i != repeat; i++)
    {
	reverse_copy_loc(data);
    }

    elapsed = std::chrono::high_resolution_clock::now() - begin;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<"by copy local "<<duration<<std::endl;

    /* Ref */
    begin = std::chrono::high_resolution_clock::now();
    
    for(auto i = 0; i != repeat; i++)
    {
	reverse_ref_loc(data);
    }

    elapsed = std::chrono::high_resolution_clock::now() - begin;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<"by ref local "<<duration<<std::endl;

    /* CLASS */
    /* Copy */
    notused instance;
    begin = std::chrono::high_resolution_clock::now();
    
    for(auto i = 0; i != repeat; i++)
    {
	instance.reverse_copy(data);
    }
    
    elapsed = std::chrono::high_resolution_clock::now() - begin;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<"by copy class "<<duration<<std::endl;

    /* Ref */
    begin = std::chrono::high_resolution_clock::now();
    
    for(auto i = 0; i != repeat; i++)
    {
	instance.reverse_ref(data);
    }

    elapsed = std::chrono::high_resolution_clock::now() - begin;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<"by ref class "<<duration<<std::endl;

    /* CLASS STATIC */
    /* Copy */
    notused_static instance_stat;
    begin = std::chrono::high_resolution_clock::now();
    
    for(auto i = 0; i != repeat; i++)
    {
	instance_stat.reverse_copy(data);
    }

    elapsed = std::chrono::high_resolution_clock::now() - begin;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<"by copy class static "<<duration<<std::endl;

    /* Ref */
    begin = std::chrono::high_resolution_clock::now();
    
    for(auto i = 0; i != repeat; i++)
    {
	instance_stat.reverse_ref(data);
    }

    elapsed = std::chrono::high_resolution_clock::now() - begin;

    duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

    std::cout<<"by ref class static "<<duration<<std::endl;
}

