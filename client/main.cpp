#include "SharedMemory.hpp"

int main() {
	SharedMemory messageBuffer{"message_buffer"};

	auto addressView = messageBuffer.getMemoryView<std::random_device::result_type>(0, 1);
	std::random_device::result_type address{};
	addressView.read(&address);

	auto valueView = messageBuffer.getMemoryView<std::random_device::result_type>(address, 1);
	std::random_device::result_type value{};
	valueView.read(&value);

	std::cout << "Client read the value " << value << " on address " << address << '\n';

	std::cin.ignore();

	std::cout << "Client closed!\n";
}