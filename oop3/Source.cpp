#include<iostream>
#include<cassert>

class String {
private:
    char* str_; // Указатель на C-строку
    size_t size_; // Размер строки (без учета завершающего нулевого символа)
public:
    // Конструктор, который принимает C-style строку
    String(const char* c_str)
    {
        size_ = strlen(c_str);
        str_ = new char[size_ + 1];
        strcpy(str_, c_str);
    }

    String(size_t count, char ch)
    {
        size_ = count;
        str_ = new char[size_ + 1];
        for (size_t i = 0; i < size_; i++)
            str_[i] = ch;
        str_[size_] = '\0';
    }
 
    void append(const char* other_str) {
        size_t other_size = strlen(other_str);
        char* res = new char[size_ + other_size + 1];
        strcpy(res, str_);
        strcpy(res + size_, other_str);

        delete[] str_;
        str_ = res;
        size_ += other_size;
    }

    String concat(const String& otherString) {
        char* res = new char[size_ + otherString.size_ + 1];
        strcpy(res,  str_);
        strcpy(res + size_, otherString.str_);
        String result(res);
        return result;
    }

    int compare(const String& otherString) {
        int i = 0;
        if (str_ == otherString.str_) return 0;
        else
            while (str_[i] != NULL || otherString.str_[i] != NULL)
            {
                if (str_[i] < otherString.str_[i]) return -1;
                if (str_[i] > otherString.str_[i]) return 1;
                i++;
            }
    }

    void toUpper() {
        for (int i = 0; i < size_; i++)
        {
            for (int j = 0;j < (int)'z' - (int)'a' + 1;j++)
                if(str_[i] == 'a'+j)
                    str_[i] = str_[i] - 32;
        }
    }

    void toLower() {
        for (int i = 0; i < size_; i++)
        {
            for (int j = 0; j < (int)'Z' - (int)'A' + 1; j++)
                if (str_[i] == 'A' + j)
                    str_[i] = str_[i] + 32;
        }
    }

    ~String()
    {
        size_ = 0;
        delete[] str_;
    }

    size_t getSize() {
        return size_;
    }
    const char* getCString() {
        return str_;
    }

};

void test()
{
    const char* c_str = "Hello, World!";
    String ss(c_str);
    assert(ss.getSize() == 13);
    //assert(ss.getCString() == "Hello, World!");
}

int main()
{
    test();
    const char* c_str = "Hello, World!";
    String myString(c_str);

    String myString2(5, 'c');

    const char* initial_str = "Hello ";
    const char* append_str = "World!";

    String myString3(initial_str);
    myString3.append(append_str);

    const char* hello = "Hello ";
    const char* world = "World";

    String helloStr(hello);
    String worldStr(world);
    String combined = helloStr.concat(worldStr);
    std::cout << "String content: " << combined.getCString() << std::endl;
    combined.toLower();
    std::cout << "Uppercase String: " << combined.getCString() << std::endl;
    //std::cout << "String size: " << myString.getSize() << std::endl;
    //std::cout << "String content: " << myString.getCString() << std::endl;
    //std::cout << "String size: " << myString2.getSize() << std::endl;
    //std::cout << "String content: " << myString2.getCString() << std::endl;
    //std::cout << "String content: " << myString3.getCString() << std::endl;
    //std::cout << "String content: " << combined.getCString() << std::endl;
    //std::cout << "String content: " << helloStr.compare(worldStr) << std::endl;

}