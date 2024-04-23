#include<iostream>
#include<cassert>
#include<string.h>
#include <sstream>
#include<cmath>

class String {
private:
    char* str_;
    size_t size_;
public:
    String(const char* c_str) {
        size_ = strlen(c_str);
        str_ = new char[size_ + 1];
        strcpy(str_, c_str);
    }

    String(size_t count, char ch) {
        size_ = count;
        str_ = new char[size_ + 1];
        for (size_t i = 0; i < size_; i++)
            str_[i] = ch;
        str_[size_] = '\0';
    }
 
    String(const String& other) {
        size_ = other.size_;
        str_ = new char[size_ + 1];
        strncpy(str_, other.str_, size_);
        str_[size_] = '\0';
    }

    void swap(String& a) {
        std::swap(size_, a.size_);
        std::swap(str_, a.str_);
    }

    String & operator=(const String& a) {
        if (this != &a)
            String(a).swap(*this);
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

    ~String() {
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

////////////////////////////////////

double print_data(double a) {
    return a;
}
int print_data(int a) {
    return a;
}
std::string print_data(std::string a) {
    return a;
}

////////////////////////////////////

class Person {
private:
    char* lname_;
    char* fname_;
    size_t age_;
public:

    Person(const char* c_str, const char* cc_str, size_t c_age) {
        age_ = c_age;
        size_t c = strlen(c_str);
        size_t cc = strlen(cc_str);
        fname_ = new char[c + 1];
        lname_ = new char[cc + 1];
        strcpy(fname_, c_str);
        strcpy(lname_, cc_str);
    }

    Person(const char* c_str) {
        size_t c = strlen(c_str);
        fname_ = new char[c+1];
        lname_ = NULL;
        strcpy(fname_, c_str);
        age_ = NULL;
    }

    Person(const char* c_str, const char* cc_str) {
        size_t c = strlen(c_str);
        size_t cc = strlen(cc_str);
        fname_ = new char[c + 1];
        lname_ = new char[cc + 1];
        strcpy(fname_, c_str);
        strcpy(lname_, cc_str);
        age_ = NULL;
    }

    Person(const char* c_str, size_t c_age) {
        age_ = c_age;
        size_t c = strlen(c_str);
        fname_ = new char[c + 1];
        lname_ = NULL;
        strcpy(fname_, c_str);
    }

    std::string display_info(size_t f) {
        std::ostringstream os;
        setlocale(LC_ALL, "ru");
        os << "Имя: " << fname_ << std::endl;
        return os.str();
    }
    std::string display_info(size_t f, char n) {
        std::ostringstream os;
        setlocale(LC_ALL, "ru");
        os << "Имя: " << fname_ << std::endl << "Возраст: " << age_ << std::endl;
        return os.str();
    }
    std::string display_info(size_t f, char n, size_t ff) {
        std::ostringstream os;
        setlocale(LC_ALL, "ru");
        os << "Имя: " << fname_ << std::endl << "Фамилия: " << lname_ << std::endl << "Возраст: " << age_ << std::endl;
        return os.str();
    }

    ~Person() {
        age_ = 0;
        delete[] fname_;
        delete[] lname_;
    }

};

////////////////////////////////////

class Shape {
public:
    virtual double calculate_area() = 0;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculate_area() {
        return width * height;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculate_area() {
        return 3.14159 * radius * radius;
    }
};

class Triangle : public Shape {
private:
    double width;
    double height;
    double ug;
public:
    Triangle(double w, double h, double u): width(w), height(h), ug(u) {}

    double calculate_area() {
        return (width * height * sin(ug))/2;
    }
};

void test() {
    const char* c_str = "Hello, World!";
    String ss(c_str);
    std::string s1 = "Hello, World!";
    int s2 = 322;
    double s3 = 322.2;
    assert(ss.getSize() == 13);
    assert(print_data(s1) == "Hello, World!");
    assert(print_data(s2) == 322);
    assert(print_data(s3) == 322.2);
    //assert(ss.getCString() == "Hello, World!");
}

int main() {
    test();
    Triangle d(2, 1, 3.14 / 2);
    std::cout<<d.calculate_area();
    return 0;
}