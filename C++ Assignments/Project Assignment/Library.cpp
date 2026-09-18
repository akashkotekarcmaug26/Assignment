#include <iostream>
#include <string>
using namespace std;


class Person{
    private:
        int id;
        string name;
        long phone;
    public:

        Person():id(0),name(""),phone(0){}
        Person(int id, string name, long phone):id(id),name(name),phone(phone){}
        virtual void displayInfo()=0;
        virtual ~Person(){
    }

    string getname() const{
        return name;
    }

};

class Member: public Person{
    private:
        int num_issuedBooks;
        string* bookIds;
        static const int maxBooks=4;
    
    public:
    //Default constructor  
    Member():num_issuedBooks(0), bookIds(new string[maxBooks]){
    }

    //Parameterized Construtor
    Member(int id, string name, long phone, int num_issuedBooks,string* bookIds):Person(id, name, phone),num_issuedBooks(num_issuedBooks){
        this->bookIds = new string[maxBooks];
        for (int i = 0; i < num_issuedBooks; i++)
        this->bookIds[i] = bookIds[i];
    }
    
    //Display func override
    void displayInfo() override{
        cout << "==========Member Information===============" << endl;
        cout << "Number of Books Issued : " << num_issuedBooks << endl;
        cout << "Book Ids";
        for(int i =0;i<num_issuedBooks;i++)
            cout << " " << bookIds[i];
        cout << endl;
    }

    //Deep Copy Constructor
    Member(const Member& m):num_issuedBooks(m.num_issuedBooks){
        cout << "Deep Copy Constructor"<< endl;
        bookIds = new string[maxBooks];
        for(int i=0;i<maxBooks;i++)
            bookIds[i]=m.bookIds[i];
    }

    //Destructor
    ~Member(){
        delete[] bookIds;
        bookIds =nullptr;
    }

};

class Librarian : public Person{
    private:
        int empoloyeeId;
        int salary;

    void displayInfo() override{

    }

};

class Book{
    private:
    int bookId;
    string title;
    string author; 
    int isbn;
    string status;
    int quantity; 
    int available_copies;
};


class Transaction{
    private:
        static int transactionId;
        int memberId; 
        int bookId; 
        string issueDate; 
        string dueDate; 
        string returnDate; 
        int fineAmount;

};

class Library{

};
int main(){
    // Dummy book IDs — a plain array, on the stack
    string myBooks[] = {"B101", "B102"};

    // Person* pointer holding a Member object -- tests polymorphism
    Person* p = new Member(1, "Alice", 9876543210, 2, myBooks);
    //                     ^id ^name  ^phone      ^count ^array

    Member m = Member(2, "Akash", 9876543210, 2, myBooks);
    Member m1=m;
    m.displayInfo();
    //p->displayInfo();   // should print Alice's member info with 2 book IDs
    cout << p->getname();
    delete p;            // virtual destructor runs ~Member() then ~Person()

    cout << 
    return 0;
}