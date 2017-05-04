#include <iostream>
#include <vector>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>

using namespace std ; 

class Subject; 

class Observer 
{ 
public: 
    Observer() {}; 
    ~Observer() {}; 
    virtual void notify(Subject* theChangeSubject) = 0; 
}; 

class Subject 
{ 
public: 
	Subject(){}; 
	virtual ~Subject(); 
	virtual void Attach(Observer*); 
	virtual void Detach(Observer*); 
	virtual void notifyObservers();  
private: 
	vector<Observer*> _observers; 
}; 

Subject::~Subject()
{}

void Subject::Attach (Observer* o) 
{ 
	_observers.push_back(o); 
} 

void Subject::Detach (Observer* o) 
{ 
    bool found = false;
    auto it = _observers.begin();
	while(it != _observers.end()) 
    {
		if(*it == o) 
        {
            found = true;
			break; 
        }
        ++it;
	} 
	if(found) 
		_observers.erase(it); 

} 

void Subject::notifyObservers() 
{ 
	for (auto it = _observers.begin(); it < _observers.end(); ++it) 
		(*it)->notify(this);
}

class ConcreteSubject : public Subject 
{ 
public: 
    ConcreteSubject();
     void trigger(void);
}; 

ConcreteSubject::ConcreteSubject()
{
    cout << "Inside ConcreteSubject() constructor" << endl;
}

void ConcreteSubject::trigger(void)
{
    int i=0;
    while(i != 10)
    {
        notifyObservers();
        i++;
    }
}

class ConcreteObserver1: public Observer 
{ 
public: 
    ConcreteObserver1(ConcreteSubject *);  
    ~ConcreteObserver1();   
    void notify(Subject *);   
    void Draw();     
private: 
    ConcreteSubject *_subject;
    int i;
}; 

ConcreteObserver1::ConcreteObserver1 (ConcreteSubject *s):i(0)
{ 
    cout << "Initial value of i in Observer 1: " << i << endl;
	_subject = s; 
	_subject->Attach(this); 
} 

ConcreteObserver1::~ConcreteObserver1 () 
{ 
	_subject->Detach(this); 
} 

void ConcreteObserver1::notify (Subject *theChangedSubject) 
{ 
//	if(theChangedSubject == _subject) 
  //  {
        cout << "ConcreteObserver1 notified, i ===== " << ++i << endl;
   // }
} 

class ConcreteObserver2: public Observer 
{ 
public: 
    ConcreteObserver2(ConcreteSubject *);  
    ~ConcreteObserver2();    
    void notify(Subject *);  
private: 
    ConcreteSubject *_subject;   
    int i;
}; 

ConcreteObserver2::ConcreteObserver2 (ConcreteSubject *s):i(0) 
{ 
    cout << "Initial value of i in Observer 2: " << i << endl;
	_subject = s; 
	_subject->Attach(this); 
} 

ConcreteObserver2::~ConcreteObserver2 () 
{ 
	_subject->Detach(this); 
} 

void ConcreteObserver2::notify (Subject *theChangedSubject) 
{ 
//	if(theChangedSubject == _subject) 
  //  {
        cout << "ConcreteObserver2 notified, i = " << ++i << endl;
 //   }
} 

int main(void) 
{ 
	ConcreteSubject cs; 
	ConcreteObserver1 obs1(&cs); 
	ConcreteObserver2 obs2(&cs); 
    cs.trigger();

	return 0; 
}
