#include <stdlib.h>
#include <string>

int main(){
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 5; i++){
            std::string cmd = "./a.out 125000 " + std::to_string(j) + " >> " + std::to_string(j) + ".txt";
            system(cmd.c_str());
        }
    }
}