#pragma once

class SharedMemory {
public:
	template <typename T>
	class View {
	public:
		void read(T* out);
		void write(const T* in);

	private:
		View() = default;
		View(T* data, size_t size) : data_(data), size_(size) {}

		LPVOID data_;
		SIZE_T size_;

		friend class SharedMemory;
	};

	SharedMemory(const char* name);
	~SharedMemory();

	// TODO(Nicolas): Move
	SharedMemory(const SharedMemory&)			 = delete;
	SharedMemory(SharedMemory&&)				 = delete;
	SharedMemory& operator=(const SharedMemory&) = delete;
	SharedMemory& operator=(SharedMemory&&)		 = delete;

	size_t getRefCount() const;

	template <typename T>
	View<T> getMemoryView(size_t address, size_t count);

private:
	HANDLE mapFileHandle_ = nullptr;
	LPVOID buffer_		  = nullptr;
};

template <typename T>
inline void SharedMemory::View<T>::read(T* out) {
	CopyMemory(static_cast<PVOID>(out), data_, size_);
}

template <typename T>
inline void SharedMemory::View<T>::write(const T* in) {
	CopyMemory(data_, static_cast<const void*>(in), size_);
}

template <typename T>
inline SharedMemory::View<T> SharedMemory::getMemoryView(const size_t address, const size_t count) {
	return {static_cast<T*>(buffer_) + address, sizeof(T) * count};
}