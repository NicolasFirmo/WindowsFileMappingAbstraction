#include "SharedMemory.hpp"

SharedMemory::SharedMemory(const char* name) {
	SYSTEM_INFO systemInfo;
	GetSystemInfo(&systemInfo);

	mapFileHandle_ = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0,
									   systemInfo.dwAllocationGranularity, TEXT(name));

	assert(mapFileHandle_ != NULL, "Could not create file mapping object.\n");

	buffer_ = MapViewOfFile(mapFileHandle_, FILE_MAP_ALL_ACCESS, 0, 0,
							systemInfo.dwAllocationGranularity);

	assert(buffer_ != NULL, "Could not map view of file.\n");
}

SharedMemory::~SharedMemory() {
	UnmapViewOfFile(buffer_);
	CloseHandle(mapFileHandle_);
}

// TODO(Nicolas)
size_t SharedMemory::getRefCount() const {
	return size_t();
}
