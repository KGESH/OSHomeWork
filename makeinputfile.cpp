#include "makeinputfile.h"
#include <ctime>

const std::string InputFile::file_name_ = "input.dat";

void InputFile::MakeInputFile(){
    int block_size;
    int process_size;

    std::fstream output_stream(InputFile::file_name_.c_str(), std::ios::out);   // Not C++ 11 compiler :(

    if (!output_stream) {
        std::cout << "File Open Failed" << std::endl;
    }

    output_stream << kBlockCount << " ";
    for (int i=0; i<kBlockCount; i++) {
        block_size = ((rand() % 10) + 1) * 100;       //  100, 200, ... 1000
        output_stream << block_size << " ";
    }

    output_stream << std::endl;

    output_stream << kProcessCount << " ";
    for (int i=0; i<kProcessCount; i++) {
        process_size = rand() % 1000;           //  1 ~ 999
        output_stream << process_size << " ";                
    }

    output_stream.close();
}

