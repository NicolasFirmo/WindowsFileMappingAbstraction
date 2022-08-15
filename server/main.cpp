#include "SharedMemory.hpp"

int main(){
	SharedMemory messageBuffer{"message_buffer"};
	SharedMemory messageBuffer2{"message_buffer"};
	SharedMemory messageBuffer3{"message_buffer2"};

	auto view = messageBuffer.getMemoryView<char>(16, 16);

	char message[16];
	view.write("Dale carai");
	view.read(message);

	std::cout << "message: " << message << '\n';
}