#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<memory>
int main(size_t argc, char *argv[])
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

    std::string no_words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string no_nos[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
for (auto &test: data)
{
    size_t found = 0, counter = 0, ins = 0, jj = 0;
    std::string k, test2;
    if(test.size()<3)
        continue;
    for(size_t j=0;j<=test.size()-3;j++)
    {
        // std::cout<<"for : "<<j<<"\n";
        // k = k + test.substr(j,5);
        k = test.substr(j,3);
        // k = test;
        test2 = test;
        // std::cout<<k<<"\n";
        found = 0; counter = 0;
        for(auto word: no_words)
        {
            found = k.find(word.c_str());
            if (found != std::string::npos)
            {
                std::cout << "\noccurrence of " << word << " at : "<< found;
                // test2.insert(found+j+ins,no_nos[counter]);
                test2.replace(found, word.size(), no_nos[counter]);
                ins++;

                break;
            }
            counter++;
        }

        // te =te + k;
    }

    // std::cout<<k<<"\n";
    // std::cout<<test<<"\n";
    std::cout<<"\n"<<test2<<"\n";

}
    
    return 0;
}