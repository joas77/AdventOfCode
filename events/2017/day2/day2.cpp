#include "solutions.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int main()
{
    std::ifstream input("input.txt");
    
    int checksum = 0;
    while (input)
    {
        std::string line;
        std::getline(input, line);
        std::istringstream sline(line);
        // Calculate min and max number for each line
        int max = -1;
        int min = INT32_MAX;
        while (sline)
        {
            int cellnumber;
            sline >> cellnumber;
            std::cout << cellnumber << ",";
            max = max < cellnumber ? cellnumber : max;
            min = min > cellnumber ? cellnumber : min;
            
        }
        std::cout << "====> min => " << min << " max => " << max << std::endl;
        auto maxmin_diff = max - min;
        checksum += maxmin_diff;
    }
    input.close();

    std::cout << "Spreadsheet sheetsum ==> " << checksum << std::endl;
    

    return 0;
}