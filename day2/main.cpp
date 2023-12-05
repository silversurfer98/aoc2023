#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<memory>

bool possible_color(const char* color, std::string data, uint16_t max, size_t no_of_games)
{
    size_t found = 0, num = 0;
    // std::cout<<data<<"\n";
    for (uint16_t j = 0; j<no_of_games; j++)
    {
        found = data.find(color, found + j);
        if (found != std::string::npos)
        {
            if(uint16_t(data[found-3])-48 < 0)
                num = uint16_t(data[found-2])-48;
            else
                num = 10*(uint16_t(data[found-3])-48) + uint16_t(data[found-2])-48;

            // std::cout<<num<<"\n";
            if(num > max)
                return false;
        }
    }
    return true;
} 

size_t largest_color(const char* color, std::string data, size_t no_of_games)
{
    size_t found = 0, num = 0, prev = 0;
    // std::cout<<data<<"\n";
    for (uint16_t j = 0; j<no_of_games; j++)
    {
        found = data.find(color, found + j);
        if (found != std::string::npos)
        {
            if(uint16_t(data[found-3])-48 < 0)
                num = uint16_t(data[found-2])-48;
            else
                num = 10*(uint16_t(data[found-3])-48) + uint16_t(data[found-2])-48;

            if(num>=prev)
                prev = num;

        }
    }
    return prev;
} 

void part1(std::unique_ptr<std::vector<std::string>> data)
{
    size_t found, count = 1, sum = 0, no_of_games = 0;

    // std::string set1, set2, set3;
    for(auto &i: *data)
    {
        found = 0;
        no_of_games = 0;
        found = i.find(":");
        if (found != std::string::npos)
            i.erase(0, found+1);

        // find no. of games
        found = 0;
        for (size_t j = 0; j<10; j++)
        {
            found = i.find(";", found + j);
            if (found != std::string::npos)
                no_of_games++;
            else
                break;
        } 

        // std::cout<<count<<" --> "<<no_of_games<<"\n";
        if(possible_color("blue", i, 14, no_of_games+1) && possible_color("green", i, 13, no_of_games+1) && possible_color("red", i, 12, no_of_games+1)){
            sum = sum + count;
            std::cout<<count<<"\n";
        }

        count++;
    }
    std::cout<<"answer = "<<sum<<"\n";
}

void part2(std::unique_ptr<std::vector<std::string>> data)
{
    size_t found, count = 1, sum = 0, no_of_games = 0;

    for(auto &i: *data)
    {
        found = 0;
        no_of_games = 0;
        found = i.find(":");
        if (found != std::string::npos)
            i.erase(0, found+1);

        // find no. of games
        found = 0;
        for (size_t j = 0; j<10; j++)
        {
            found = i.find(";", found + j);
            if (found != std::string::npos)
                no_of_games++;
            else
                break;
        }

        sum = sum + largest_color("blue", i, no_of_games+1) * largest_color("green", i, no_of_games+1) * largest_color("red", i, no_of_games+1);

    }
    std::cout<<"answer = "<<sum<<"\n";
}

int main(int argc, char *argv[])
{
    std::vector<std::string> data;
    std::fstream data_file;
    data_file.open(argv[1], std::ios::in);

    std::string Buf;
    if (data_file.is_open()) 
    {
                while(std::getline(data_file, Buf))
        {
            data.push_back(Buf);
            Buf.erase();
        }
        }
        data_file.close();
    
    std::unique_ptr<std::vector<std::string>> data_ptr;
    data_ptr = std::make_unique<std::vector<std::string>>(data);
    part2(std::move(data_ptr));
    return 0;
}