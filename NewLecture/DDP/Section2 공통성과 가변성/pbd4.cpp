#include <cstdlib>
#include <iostream>
#include <limits>
#include <new>
#include <vector>
 
template<class T>
struct Mallocator
{
    // 관례적 코드
    typedef T value_type;
 
    Mallocator() = default;
 
    template<class U>
    constexpr Mallocator(const Mallocator <U>&) noexcept {}
    // 관례적 코드

    [[nodiscard]] T* allocate(std::size_t n)
    {
        //예외처리
        if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
            throw std::bad_array_new_length();
        //malloc
        if (auto p = static_cast<T*>(std::malloc(n * sizeof(T))))
        {
            report(p, n);
            return p;
        }
 
        throw std::bad_alloc();
    }
 
    void deallocate(T* p, std::size_t n) noexcept
    {
        report(p, n, 0);
        //free
        std::free(p);
    }
private:
    void report(T* p, std::size_t n, bool alloc = true) const
    {
        std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T) * n
                  << " bytes at " << std::hex << std::showbase
                  << reinterpret_cast<void*>(p) << std::dec << '\n';
    }
};
 
template<class T, class U>
bool operator==(const Mallocator <T>&, const Mallocator <U>&) { return true; }
 
template<class T, class U>
bool operator!=(const Mallocator <T>&, const Mallocator <U>&) { return false; }
 

int main(int argc, char** argv)
{
    std::vector<int, Mallocator<int>> v;
    std::cout << " -----------------" << std::endl;
    v.resize(5);
    // Cpp reference -> Named Requirements.
    std::cout << "------------------" << std::endl;
}