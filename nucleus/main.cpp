#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "boost/crc.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::srand(time(0));
    boost::crc_optimal<8, 0x5Bu << 1u, 0xFF, 0, false, false> my_checksum_solver;
    uint8_t example_data[32] = {0};
    for (auto i = 0; i < sizeof(example_data) / sizeof(uint8_t); ++i)
    {
        example_data[i] = static_cast<uint8_t>(std::rand());
    }

    my_checksum_solver.process_bytes(example_data, sizeof(example_data)/sizeof(uint8_t));
    std::cout << (int)my_checksum_solver.checksum();
    return 0;
}