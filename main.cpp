#include "makeinputfile.h"
#include "firstfit.h"
#include "bestfit.h"
#include "nextfit.h"

int main(){
    srand(time(NULL));
    InputFile::MakeInputFile();  //  make input.dat
    FirstFitPolicy first_fit_manager;
    BestFitPolicy best_fit_manager;
    NextFitPolicy next_fit_manager;

    first_fit_manager.InitList(InputFile::file_name_);
    first_fit_manager.FirstFit();
    first_fit_manager.ShowMemory();

    best_fit_manager.InitList(InputFile::file_name_);
    best_fit_manager.BestFit();
    best_fit_manager.ShowMemory();

    next_fit_manager.InitList(InputFile::file_name_);
    next_fit_manager.NextFit();
    next_fit_manager.ShowMemory();

    return 0;
}

