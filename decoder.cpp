#include "decoder.h"

int main(){
    Cube cube;

    std::string key = "2:d:u:r:l";
    std::string line = "1234567812345678";

    /* std::cout << "Enter the line:\t" ;
    std::cin >> line;
    std::cout << "Enter the key:\t" ;
    std::cin >> key; */

    std::cout << cube.StartEncoding(line,key) << std::endl << std::endl;

    /* std::cout << cube.get_coded_line() << std::endl;
    std::cout << cube.get_key_for_decryption() << std::endl;
    std::cout << cube.get_how_many_cubes(line) << std::endl; */

}