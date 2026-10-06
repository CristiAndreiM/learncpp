#include <iostream>
#include <cstdint>
#include <string>
#include <algorithm>

static int count_no_call_sum = 0;

std::uint8_t sum(const std::uint8_t* array, std::size_t n) {
    std::uint8_t sum = 0;
    for (std::size_t i = 0; i < n; ++i) {
        sum += array[i]; 
    }
    count_no_call_sum++;
    return sum;
}

constexpr std::uint8_t doubleNumber(std::size_t number) {
    return static_cast<std::uint8_t>(number * 2);
}

int main(int argc, char* argv[]) {
    std::uint8_t sum_value{};
   
    std::cout << "No of arguments is: " << argc << "\n";

    std::size_t available_args = (argc > 1) ? static_cast<std::size_t>(argc - 1) : 0;
    std::size_t size = std::min(static_cast<std::size_t>(5), available_args);

    std::uint8_t v[5] = {0};

    for (std::size_t i = 0; i < size; ++i) {
        v[i] = static_cast<std::uint8_t>(std::stoi(argv[i + 1]));
    }
    
    sum_value = sum(v, size);
    
    const std::uint8_t double_sum_value{doubleNumber(sum_value)};

    // Cast uint8_t to int for numerical printing
    std::cout << "The sum of array is: " << static_cast<int>(sum_value) 
              << "\nNo of Sum calls: " << count_no_call_sum
              << "\nDouble of sum is: " << static_cast<int>(double_sum_value) << "\n";

    return 0;
}