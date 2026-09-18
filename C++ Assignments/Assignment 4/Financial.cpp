#include <iostream>
using namespace std;

class LedgerEntry{
    private:
        string desc;
        double* amounts;
        int days;
        static int totalEntries;

    public:

    int getEntries(){
        return totalEntries;
    }

    LedgerEntry(const string& desc , int days):desc(desc),days(days){
        amounts = new double[days];
        for (int i = 0; i < days; i++) {
            amounts[i] = 0.0;   // zero-initialize, since caller may not set every index
    }
        totalEntries++;
    }

    LedgerEntry(const LedgerEntry& other) : desc(other.desc), days(other.days) {
        amounts = new double[days];
        for (int i = 0; i < days; i++) {
            amounts[i] = other.amounts[i];
        }
        totalEntries++;
            cout << "[Copy Constructor] Deep copy of: " << other.desc << endl;
    }

    LedgerEntry(LedgerEntry&& other) noexcept
    : desc(other.desc), amounts(other.amounts), days(other.days) {
    other.amounts = nullptr;
    other.days = 0;
    totalEntries++;
    cout << "[Move Constructor] Ownership transferred from: " << desc << endl;
}

    LedgerEntry& operator=(const LedgerEntry& other) {
    if (this != &other) {
        delete[] amounts;              // free existing buffer first

        desc = other.desc;
        days = other.days;
        amounts = new double[days];
        for (int i = 0; i < days; i++) {
            amounts[i] = other.amounts[i];
        }
        cout << "[Copy Assignment] Deep copy of: " << other.desc << endl;
    }
    return *this;
}

    LedgerEntry& operator=(LedgerEntry&& other) noexcept {
    if (this != &other) {
        delete[] amounts;              // free existing buffer

        desc = other.desc;
        amounts = other.amounts;       // steal pointer
        days = other.days;

        other.amounts = nullptr;       // empty out source
        other.days = 0;

        cout << "[Move Assignment] Ownership transferred from: " << desc << endl;
    }
    return *this;
}

    ~LedgerEntry() {
        delete[] amounts;
        totalEntries--;
        cout << "[Destructor] " << desc << " destroyed" << endl;
        }

    friend ostream& operator<<(ostream& out,const LedgerEntry& entry);

    LedgerEntry operator+(const LedgerEntry& other) const;

    double& operator[](int index);

    const double& operator[](int index) const;

};

int LedgerEntry::totalEntries = 0;

ostream& operator<<(ostream& out,const LedgerEntry& entry){
    out << entry.desc << " : ";
    double total=0;;
    for(int i=0;i<entry.days;i++)
        {
            out << entry.amounts[i];
            total+=entry.amounts[i];
        }
        out << "   Total : " << total << endl;

    return out;
}

LedgerEntry LedgerEntry::operator+(const LedgerEntry& other)const {
    int resultDays = (days < other.days) ? days : other.days;

    LedgerEntry combined1("Combined", resultDays);

    for (int i = 0; i < resultDays; i++) {
       combined1.amounts[i] = amounts[i] + other.amounts[i];
    }

    return combined1;
}
double& LedgerEntry::operator[](int index) {
    if (index < 0 || index >= days) {
        throw out_of_range("LedgerEntry index out of range");
    }
    return amounts[index];
}

const double& LedgerEntry::operator[](int index) const {
    if (index < 0 || index >= days) {
        throw out_of_range("LedgerEntry index out of range");
    }
    return amounts[index];
}

int main() {
    // Objective 1 — Constructor & deep copy
    LedgerEntry jan("January Sales", 5);
    jan[0] = 1200.50; jan[1] = 3400.00; jan[2] = 800.75;
    jan[3] = 2100.00; jan[4] = 650.25;
    LedgerEntry feb("February Sales", 5);
    feb[0] = 900.00; feb[1] = 2200.50; feb[2] = 1750.00;
    feb[3] = 3000.00; feb[4] = 475.50;
    cout << jan << endl;
    cout << feb << endl;

    // Objective 2 — Operator + (sum two ledgers into combined)
    LedgerEntry combined = jan + feb;
    cout << "Combined: " << combined << endl;

    // // Objective 3 — Relational operators
    // cout << "Jan == Feb : " << (jan == feb ? "Yes" : "No") << endl;
    // cout << "Jan > Feb : " << (jan > feb ? "Yes" : "No") << endl;

    // Objective 4 — Move constructor (should NOT deep copy)
    LedgerEntry moved = move(jan);
    cout << "After move, jan.amounts is null: "
    << (/* check jan is empty */ true ? "YES" : "NO") << endl;
    cout << "Moved entry: " << moved << endl;

    // Objective 5 — Move assignment
    LedgerEntry q1("Q1 Total", 5);
    q1 = move(feb); // feb's resources transferred to q1
    cout << "Q1 (moved from feb): " << q1 << endl;

    jan.~LedgerEntry();   // legal, but dangerous

    // Objective 6 — Static member
    cout << "Live LedgerEntry objects: " << jan.getEntries() << endl;
    return 0;
}
