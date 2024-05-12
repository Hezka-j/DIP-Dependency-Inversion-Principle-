#include <iostream>
using namespace std;
//1
//Создайте класс для отправки электронной почты.
//Напишите несколько классов, которые могут использовать этот класс, например, класс для отправки уведомлений пользователю и класс для отправки отчетов администратору.
//Используйте принцип Dependency Inversion, чтобы обеспечить возможность замены класса для отправки электронной почты на другой класс без изменения кода этих двух классов.

class SendEmail abstract{
public:
    virtual void Send(string str) = 0;
};

class SendSMSToSomeone : public SendEmail {
public:
    void Send(string str) {
        cout << "SMS is sent (" << str << ")\n";
    }
};

class ReportToAdmin : public SendEmail {
public:
    void Send(string str) {
        cout << "Report is sent (" << str << ")\n";
    }
};

//2
//Создайте интерфейс для работы с базой данных, который объявляет методы для выполнения CRUD - операций.
//Создайте несколько реализаций этого интерфейса, например, реализацию для работы с MySQL и реализацию для работы с MongoDB.
//Создайте класс, который будет использовать этот интерфейс, например, класс для работы со статьями на сайте.
//Используйте принцип Dependency Inversion, чтобы этот класс мог использовать любую из реализаций интерфейса, без изменения его кода.

__interface ICreate{
    void Create();
};
__interface IRead { 
    void Read();
};
__interface IUpdate {
    void Update();
};
__interface IDelete {
    void Delete();
};

class MySQL : public ICreate, public IRead, public IUpdate, public IDelete {
public:
    void Create() {
        cout << "MySQL\n";
    }
    void Read(){
        cout << "MySQL\n";
    }
    void Update(){
        cout << "MySQL\n";
    }
    void Delete(){
        cout << "MySQL\n";
    }
};

class MongoDB : public ICreate, public IRead, public IUpdate, public IDelete {
public:
    void Create() {
        cout << "MongoDB\n";
    }
    void Read() {
        cout << "MongoDB\n";
    }
    void Update() {
        cout << "MongoDB\n";
    }
    void Delete() {
        cout << "MongoDB\n";
    }
};

class Website{
public:
    void Create(ICreate* object) {
        cout << "create website ";
        object->Create();
    }
    void Read(IRead* object) {
        cout << "read website ";
        object->Read();
    }
    void Update(IUpdate* object) {
        cout << "update website ";
        object->Update();
    }
    void Delete(IDelete* object) {
        cout << "delete website ";
        object->Delete();
    }
};
//3
//Для реализации принципа Dependency Inversion Principle мы можем использовать класс Person и класс Food, где класс Person будет зависеть от абстракции класса Food, а не от конкретных реализаций.

class Food abstract{};

class Apple : public Food{};

class Burger : public Food{};

class Person {
public:
    void Eat(Food* food) {
        cout << "eat\n";
    }
};

int main()
{
    /*Person p;
    Apple a;
    p.Eat(&a);*/
    Website w;
    MongoDB m;
    w.Create(&m);

    SendSMSToSomeone s;
    SendEmail* g = &s;
    g->Send("okay google");
}
