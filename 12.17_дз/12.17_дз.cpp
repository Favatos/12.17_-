#include<iostream>
using namespace std;

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
	void getInfo(const User& a){
		cout << "Информация о пользователе: " << endl;
		cout << "Имя: " << a.name << endl;
		cout << "Раса: " << a.rase << endl;
		cout << "Класс: " << a.Class << endl;
		cout << "Номер сервера: " << counter << endl;
		cout << "Дата регистрации: " << a.day << '.' << a.month << '.' << a.year << endl;
	}
};
int GameServer::counter{ 0 };

class User: public Date {
private:
	string name;
	string rase;
	string Class;
	int num_of_server;
	friend GameServer;
public:
	User(string n, string r, string c, int d, int m, int y) : Date{ d,m,y }, name{ n }, rase{ r }, Class{ c } {
		cout << "Пожалуйста выберите сервер: " << endl
			<< "Доступно " << GameServer::counter << "серверов", cin >> num_of_server;
	}
	User() : User("Иван", "Human", "Archer", 1, 1, 2000) {}
	void changeName(string name) { this->name = name; }
	void changeClass(string Class) { this->Class = Class; }
	void changeServer(int num){
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
	Date(int d, int m, int y): day{d}, month{m}, year{y}{ }
	//Date() :Date(1, 1, 2000){}
};

int main() {
	setlocale(LC_ALL, "ru");

	GameServer serv1(200, 400, "europe", 1);
	GameServer serv2;

	User n1("Dionis", "Tifling", "Bard", 23, 12, 23);
	User n2;

	serv1.getInfo(n1);
}