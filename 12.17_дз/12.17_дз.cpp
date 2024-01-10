#include<iostream> 
using namespace std;
class Date;
class User;
class GameServer {
private:
    int amount_off;
    int amount_on;
    string region;
    bool state;
public:
    static int counter;

    GameServer(int off, int on, string r, bool s) : amount_off{ off }, amount_on{ on }, region{ r }, state{ s } { counter++; }
    GameServer() : GameServer(0, 0, "america", 1) {}
    void changeRegion(string newRegion) { region = newRegion; }
    void changeState(bool state) { this->state = state; }
    void getInfo(const User& acc);
    friend User;
};
int GameServer::counter{ 0 };

class User {
private:
    string name;
    string rase;
    string Class;
    int num_of_server;
    friend GameServer;
public:
    User(string n, string r, string c, int d, int m, int y) :name{ n }, rase{ r }, Class{ c } {
        cout << "Пожалуйста выберите сервер: " << endl
            << "Доступно " << GameServer::counter << " серверов: ", cin >> num_of_server;
    }
    User() : User("Иван", "Human", "Archer", 1, 1, 2000) {}
    void changeName(string name) { this->name = name; }
    void changeClass(string Class) { this->Class = Class; }
    void changeServer(int num) {
        if (num <= GameServer::counter) {
            num_of_server = num;
            cout << "Операция прошла успешно" << endl;
        }
        else
            cout << "Ошибка ";
    }
};

class Date {
    friend GameServer;
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) : day{ d }, month{ m }, year{ y } { }
};
void GameServer::getInfo(const User& acc)
{
    cout << "Информация о пользователе: " << endl;
    cout << "Имя: " << acc.name << endl;
    cout << "Раса: " << acc.rase << endl;
    cout << "Класс: " << acc.Class << endl;
    cout << "Номер сервера: " << acc.num_of_server << endl;
}
int main() {
    setlocale(LC_ALL, "ru");

    GameServer serv1(200, 400, "europe", 1);
    GameServer serv2;

    User n1("Dionis", "Tifling", "Bard", 23, 12, 23);
    User n2;

    serv1.getInfo(n2);
}