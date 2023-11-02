// Homework20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>

class Printable
{
public:
    virtual ~Printable() = default;
    virtual std::string print() const = 0;
   /* virtual std::string printAsHTML() const = 0;
    virtual std::string printAsText() const = 0;
    virtual std::string printAsJSON() const = 0;*/
};

//Теперь класс Printable может наследоваться и другими классами с другими типами данных и работа класса saveClass не будет зависить то того какой тип данных используется в классе-наследнике Printable'a
//А так же не потребуется менять что либо при добавлении

class DataString {
public:
    DataString(std::string data):data_(data){}
 
protected:
    std::string data_;
};

//Возможно добавление различных форматов для печати строки без изменения уже работающего кода

class DataStringAsHTML : public DataString, public Printable{
    DataStringAsHTML(std::string data) :DataString(data) {};

    std::string print() const override{
        return "<html>" + data_ + "<html/>";
    }
};

class DataStringAsText : public DataString, public Printable {
    DataStringAsText(std::string data) :DataString(data) {};

    std::string print() const override {
        return data_;
    }
};

class DataStringAsJSON : public DataString, public Printable {
    DataStringAsJSON(std::string data) :DataString(data) {};

    std::string print() const override {
        return "{ \"data\": \"" + data_ + "\"}";
    }
};

//Так же был разделен интерфей для того чтобы упростить функцию saveTo

void saveTo(std::ofstream& file, const Printable& printable){
    file << printable.print();
}


/*
Тут было нарушение принципа открытости/закрытости
а так же принцип подстановки Лисков

void saveTo(std::ofstream& file, const Printable& printable, Data::Format format)
{
    switch (format)
    {
    case Data::Format::kText:
        file << printable.printAsText();
        break;
    case Data::Format::kJSON:
        file << printable.printAsJSON();
        break;
    case Data::Format::kHTML:
        file << printable.printAsHTML();
        break;
    }
}

void saveToAsHTML(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kHTML);
}

void saveToAsJSON(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kJSON);
}

void saveToAsText(std::ofstream& file, const Printable& printable) {
    saveTo(file, printable, Data::Format::kText);
}*/

int main() {

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"