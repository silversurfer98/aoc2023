#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<memory>
// ownerproof-3609745-1701630677-cd2d93cb84a6
void part1(std::unique_ptr<std::vector<std::string>> data)
{
    std::vector<int> numbers;
    uint64_t sum = 0;
    for(auto i: *data)
    {
        // std::cout<<i<<std::endl;
        int no1=0;
        int no2=0;
        uint16_t count=0; 
        for(auto j: i)
        {
            int t = int(j)-48;
            if(t<=9)
            {
                if(count==0)
                    no1 = t;
                no2=t;
                count++;
            }
        }
        if(count==1)
            no2=no1;
        numbers.push_back((no1*10)+no2);
    }

    for(auto i: numbers){
        sum=sum+i;
        // std::cout<<i<<"\n";
    }
    std::cout<<"Answer: "<<sum<<"\n";
}

void part2(std::unique_ptr<std::vector<std::string>> data)
{
    std::string no_words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string no_nos[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    // std::string no_nos[] = {"1ne", "tw2", "3hree", "4our", "5ive", "6ix", "7even", "8ight", "9ine"};

    std::vector<std::string> data_r;

    size_t found = 0, counter = 0, ins = 0, f = 0, s = 0;
    std::string k, fin;
    for(auto &i: *data)
    {
        f = 0;
        s = i.size();
        if(s>3 && s<5)
            f = 3;
        else if(s>=5)
            f = 5;
        else
            continue;
        fin = i;
        ins = 0;
//-----------------------------
        for(size_t j=0;j<=s-f;j++)
        {
            k = i.substr(j,f);
            found = 0; counter = 0;
            for(auto word: no_words)
            {
                found = k.find(word.c_str());
                if (found != std::string::npos)
                {
                    // std::cout << "occurrence of " << word << " at : "<< found << std::endl;
                    fin.insert(found+j+ins,no_nos[counter]);
                    ins++;
                    break;
                }
                counter++;
            }
        }

        i = fin;
        k.erase();
        fin.erase();
//------------------------------
    }
    part1(std::move(data));
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
    data_ptr=std::make_unique<std::vector<std::string>>(data);

    part2(std::move(data_ptr));

    return 0;
}