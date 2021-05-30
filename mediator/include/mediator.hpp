#pragma once
#include<iostream>
#include<string>
using namespace std;
class Colleague;
class ConcreteColleague1;
class ConcreteColleague2;

// 調停者
// Colleagueと通信を行って、調整を行うためのインターフェースを提供する
class Mediator
{
public:
	virtual void Send(string message, Colleague * colleague) = 0;
};
// Mediatorクラスと通信を行うインターフェースを紐づける
class Colleague
{
protected:
	Mediator * mediator;
public:
	Colleague(Mediator * mediator)
	{
		this->mediator = mediator;
	}
};

// Colleague1, 2（実装）
class ConcreteColleague1 : public Colleague
{
public:
	ConcreteColleague1(Mediator * mediator) : Colleague(mediator)
	{}
	void Send(string message)
	{
		mediator->Send(message, this);
	}
	void Notify(string message)
	{
		cout << "Colleague1がメッセージを受け取る: " << message << endl;
	}
};
class ConcreteColleague2 : public Colleague
{
public:
	ConcreteColleague2(Mediator * mediator) : Colleague(mediator)
	{}
	void Send(string message)
	{
		mediator->Send(message, this);
	}
	void Notify(string message)
	{
		cout << "Colleague2がメッセージを受け取る: " << message << endl;
	}
};
// Mediatorクラスのインターフェースを実装し、実際の調停を行う
class ConcreteMediator : public Mediator
{
private:
	ConcreteColleague1 * colleague1;
	ConcreteColleague2 * colleague2;
public:
	void Colleague1(ConcreteColleague1 * colleague1)
	{
		this->colleague1 = colleague1;
	}
	void Colleague2(ConcreteColleague2 * colleague2)
	{
		this->colleague2 = colleague2;
	}
	void Send(string message, Colleague * colleague)
	{
		if (colleague == colleague1)
		{
			colleague2->Notify(message);
		}
		else
		{
			colleague1->Notify(message);
		}
	}
};