#include <iostream>
#include "list"
#include "string"
using namespace std;

class IObserver
{
public:
    virtual void update(std::string)=0;
    virtual ~IObserver(){};
};

class PostGAI: public IObserver
{
private:
    string postTitle;
    list<string> *orders;
public:
    PostGAI(string postTitle) {
        this->postTitle = postTitle;
        this->orders = new list<string>();
    }
    void update(string message) {
        cout << this->postTitle << " : " << "Есть " << message << "!" << endl;
        this->orders->push_back(message);
    }
    ~PostGAI() {
        delete this->orders;
    };
};

class ISubject
{
public:
    virtual void attach(IObserver *observer)=0;
    virtual void deattach(IObserver *observer)=0;
    virtual void notify(std::string message)=0;
    virtual ~ISubject(){};
};

class ShtabGAI: public ISubject
{
private:
    list<IObserver *> *myList;
public:
    ShtabGAI() {
        this->myList = new list<IObserver *>();
    }
    
    void attach(IObserver *observer) {
        this->myList->push_back(observer);
    }
    void deattach(IObserver *observer) {
        this->myList->remove(observer);
    }

    void catchCriminals() {
        list<string> criminals({"Вася", "Сережа"});
        list<string>::iterator iterator = criminals.begin();
        while(iterator != criminals.end()) {
            this->notify("поймать " + (*iterator));
            ++iterator;
        }
    }
    void notify(std::string message) {
        cout << "Всем-всем, " << message << "!" << endl;
        list<IObserver *>::iterator iterator = this->myList->begin();
        while(iterator != this->myList->end()) {
            (*iterator)->update(message);
            ++iterator;
        }
    }
    ~ShtabGAI() {
        list<IObserver *>::iterator iterator = this->myList->begin();
        while(iterator != this->myList->end()) {
            delete (*iterator);
            ++iterator;
        }
        delete this->myList;
    }
};


int main() {
    ShtabGAI *shtab = new ShtabGAI();
    PostGAI *post1 = new PostGAI("post1");
    PostGAI *post2 = new PostGAI("post2");
    PostGAI *post3 = new PostGAI("post3");
    shtab->attach(post1);
    shtab->attach(post2);
    shtab->attach(post3);

    shtab->catchCriminals();

    delete shtab;
} 