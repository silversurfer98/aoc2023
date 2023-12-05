#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<memory>
#include<math.h>

// run command
// g++ main.cpp -o main && ./main test.txt
// |/usr/share/apport/apport -p%p -s%s -c%c -d%d -P%P -u%u -g%g -- %E

// all symbols
// std::string special_char = {'*','@','#','-','=','/','+','%','$','&'};
// if(map[i][j+1]>0 || map[i][j-1]>0)
//     std::cout<<"adjacent --> ("<<i<<" ,"<<j<<") --> "<<data->at(i)[j]<<"\n";
// else if(map[i+1][j]>0 || map[i-1][j]>0)
//     std::cout<<"top down --> ("<<i<<" ,"<<j<<") --> "<<data->at(i)[j]<<"\n";
// else if(map[i+1][j-1]>0 || map[i-1][j+1]>0)
//     std::cout<<"right diagonal--> ("<<i<<" ,"<<j<<") --> "<<data->at(i)[j]<<"\n";
// else if(map[i+1][j+1]>0 || map[i-1][j-1]>0)
//     std::cout<<"left diagonal--> ("<<i<<" ,"<<j<<") --> "<<data->at(i)[j]<<"\n";

void part1(std::unique_ptr<std::vector<std::string>> data)
{
    // std::vector<std::vector<uint16_t>> map(data->size() , std::vector<float>(data->at(0).size()));

    // code to map the data to numbers
    std::vector<std::vector<int>> map(data->size());
    for (size_t i=0; i<data->size();i++)
    {
        map[i] = std::vector<int>(data->at(i).size());
        for (size_t j=0; j<data->at(i).size(); j++)
        {
            switch(data->at(i)[j])
            {
                case '*':
                    map[i][j]=-1;
                    break;
                case '@':
                    map[i][j]=-1;
                    break;
                case '#':
                    map[i][j]=-1;
                    break;
                case '-':
                    map[i][j]=-1;
                    break;
                case '=':
                    map[i][j]=-1;
                    break;
                case '/':
                    map[i][j]=-1;
                    break;
                case '+':
                    map[i][j]=-1;
                    break;
                case '%':
                    map[i][j]=-1;
                    break;
                case '$':
                    map[i][j]=-1;
                    break;
                case '&':
                    map[i][j]=-1;
                    break;
                case '.':
                    map[i][j]=0;
                    break;
                default:
                    map[i][j]=int(data->at(i)[j])-48;
                    break;
            }

        }
    }

    //logic to add all numbers
        for(auto i=0;i<map.size();i++)
        {
            for(auto j=0;j<map[i].size();j++)
            {
                size_t counter=0;
                if(map[i][j]>0)
                {
                    for(auto k=1;k<map[i].size()-j;k++)
                    {
                        if(!(map[i][j+k]<=0))
                            counter++;
                        else
                        {
                            break;
                        }
                    }
                    std::cout<<"counter --> "<<counter<<"\n";
                    map[i][j] = map[i][j]*std::pow(10,counter);
                    size_t f = j + counter;
                    while(counter!=0)
                    {
                        counter--;
                        // map[i][f] = map[i][f] + map[i][j+counter];
                        std::cout<<"from while --> "<<map[i][j+counter]<<"\n";
                    }
                    j = j + counter;
                }

            }
                std::cout<<"\n";
        }

    // logic to find coord
    for(auto i=0;i<map.size();i++)
    {
        for(auto j=0;j<map[i].size();j++)
        {
            if(map[i][j]<0)
                if((map[i][j+1]>0 || map[i][j-1]>0) || (map[i+1][j]>0 || map[i-1][j]>0) || (map[i+1][j-1]>0 || map[i-1][j+1]>0) || (map[i+1][j+1]>0 || map[i-1][j-1]>0))
                    std::cout<<"all--> ("<<i<<" ,"<<j<<") --> "<<data->at(i)[j]<<"\n";

        }
    }

    // print the map
    for(auto i=0;i<map.size();i++)
    {
        for(auto j=0;j<map[i].size();j++)
            std::cout<<map[i][j]<<"  ";
        std::cout<<"\n";
    }
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
    part1(std::move(data_ptr));
    return 0;
}
