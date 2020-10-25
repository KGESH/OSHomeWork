#include "nextfit.h"
#include "circulariterator.h"


void NextFitPolicy::InitList(const std::string& file_name){
    int max_count;
    int temp;
    std::fstream input_stream(file_name.c_str(), std::ios::in);     // not C++ 11 compiler :(

    if (!input_stream){
        std::cout << "File Open Failed" << std::endl;
    }

    input_stream >> max_count;
    for (int i = 0; i<max_count; i++){
        input_stream >> temp;
        block_list_.push_back(temp);
    }

    input_stream >> max_count;
    for (int i = 0; i<max_count; i++){
        input_stream >> temp;
        process_list_.push_back(temp);
    }
}


void NextFitPolicy::NextFit(){
    CircularIterator<std::list<Block_t>::iterator> circular_iterator(block_list_.begin(), block_list_.end());
    std::list<Process_t>::iterator process_itor;
    std::list<Block_t>::iterator allocate_ptr = block_list_.begin();            // last allocated pointer
    std::stringstream string_stream;


    for (process_itor = process_list_.begin(); process_itor != process_list_.end(); process_itor++){
        for (circular_iterator.Current() = allocate_ptr;circular_iterator.Next() != allocate_ptr; circular_iterator++, compare_count_++){  // if current over end, then current = begin

            if (*process_itor <= *circular_iterator.Current()){
                allocated_block_list_.push_back(*process_itor);
                string_stream.str("");                                          // clear string stream
                string_stream << circular_iterator.GetCurrentPosition();        // int to string
                block_number_.push_back(string_stream.str());                   // not C++ 11 compiler :(
                *circular_iterator.Current() -= *process_itor;
                allocate_ptr = circular_iterator.Current();
                compare_count_++;                     
                break;
            }
        }

        if (allocated_block_list_.empty() || (*process_itor != allocated_block_list_.back())){
            block_number_.push_back("Not Allocated");
        }
    }
} 


void NextFitPolicy::ShowMemory(){
    int i = 1;
    std::list<Block_t>::iterator itor;
    std::list<std::string>::iterator block_number_itor = block_number_.begin();
    std::list<Process_t>::iterator process_itor = process_list_.begin();

    std::cout << "[ Next fit memory allocated status ]" << std::endl;
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
