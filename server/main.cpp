#include "SharedMemory.hpp"

int main() {
	SharedMemory messageBuffer{"message_buffer"};

	const auto address = std::random_device{}() % 4096;
	auto addressView   = messageBuffer.getMemoryView<std::random_device::result_type>(0, 1);
	addressView.write(&address);

	const auto value = std::random_device{}();
	auto valueView	 = messageBuffer.getMemoryView<std::random_device::result_type>(address, 1);
	valueView.write(&value);

	std::cout << "Server wrote the value " << value << " on address " << address << '\n';

	std::cin.ignore();

	std::cout << "Server closed!\n";
}