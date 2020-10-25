#include "bestfit.h"


void BestFitPolicy::InitList(const std::string& file_name){
    int max_count;
    int temp;
    std::fstream input_stream(file_name.c_str(), std::ios::in);     // not C++ 11 compiler :(

    if (!input_stream){
        std::cout << "File Open Failed" << std::endl;
    }

    input_stream >> max_count;
    for (int i=0; i<max_count; i++){
        input_stream >> temp;
        block_list_.push_back(temp);
    }

    input_stream >> max_count;
    for (int i=0; i<max_count; i++){
        input_stream >> temp;
        process_list_.push_back(temp);
    }
}


void BestFitPolicy::BestFit(){
    const int kNotAllocated = -1;
    int i;
    int min_available_size = 9999;
    int min_available_block_position;
    std::list<Block_t>::iterator block_itor;
    std::list<Process_t>::iterator process_itor;
    std::stringstream string_stream;

    for (process_itor = process_list_.begin(); process_itor != process_list_.end(); process_itor++, min_available_block_position = kNotAllocated, min_available_size = 9999){    // max block size : 1000
        for (block_itor = block_list_.begin(), i=0; block_itor != block_list_.end(); block_itor++, compare_count_++, i++){

            if (*block_itor - *process_itor > 0 && *process_itor <= *block_itor){
                compare_count_++;   // compare count to best fit

                if (*block_itor - *process_itor < min_available_size){
                    min_available_size = *block_itor - *process_itor;   //  block size - process size
                    min_available_block_position = i;
                }
            }
        }

        for (i=0, block_itor = block_list_.begin(); i<min_available_block_position; i++){   // if not allocated then not work
            block_itor++;
        }

        if (min_available_block_position != kNotAllocated && *block_itor - *process_itor > 0){  // if find allocate block and block size - process size > 0
            allocated_block_list_.push_back(*process_itor);
            string_stream.str("");                          // clear string stream
            string_stream << min_available_block_position;  // int to string
            block_number_.push_back(string_stream.str());   // not C++ 11 compiler :(    std::to_stirng()
            *block_itor -= *process_itor;

        } else {
            block_number_.push_back("Not Allocated");
        }
    }
}

void BestFitPolicy::ShowMemory(){
    int i = 1;
    std::list<Block_t>::iterator itor;
    std::list<std::string>::iterator block_number_itor = block_number_.begin();
    std::list<Process_t>::iterator process_itor = process_list_.begin();

    std::cout << "[ Best fit memory allocated status ]" << std::endl;
    std::cout << "Process No." << "\t" << "Process Size" << "\t" << "Block no." << std::endl;
    for(itor = process_list_.begin(); itor != process_list_.end(); itor++, i++, process_itor++, block_number_itor++){
        std::cout << i << "\t\t" << *process_itor << "\t\t" << *block_number_itor << std::endl;
    }
    std::cout << std::endl;

    std::cout << "[ Allocated Block List ]" << std::endl;
    for (itor = allocated_block_list_.begin(); itor != allocated_block_list_.end(); itor++){
        std::cout << *itor << " ";
    }
    std::cout << std::endl;

    std::cout << "[ Available Block List ]" << std::endl;
    for (itor = block_list_.begin(); itor != block_list_.end(); itor++){
        std::cout << *itor << " ";
    }
    std::cout << std::endl;

    std::cout << "compare count = " << compare_count_ << std::endl;
    std::cout << "average comapre count = " << compare_count_ / process_list_.size() << std::endl << std::endl;
}
