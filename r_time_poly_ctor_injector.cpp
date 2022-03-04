#include <stdio.h>
#include <stdlib.h> 

struct AccountDatabase
{
    virtual ~AccountDatabase() = default;
    virtual void setData(const char* ownerSurname, long bankAccountNumber, long amount) = 0;
    virtual void printData() = 0;
};

struct InMemoryAccountDataBase:
    public AccountDatabase
{
    void setData(const char* ownerSurname, long bankAccountNumber, long amount) override
    {
        this->m_owner = ownerSurname;
        this->m_account = bankAccountNumber;
        this->m_amount = amount;
    }

    void printData() override 
    {
        printf("Surname: %s\nAccount number: %ld\nAmount: %Lf\n\n", m_owner, m_account, m_amount);
    }

    private:
    const char* m_owner;
    long m_account;
    long double m_amount;
};

struct Bank
{
    Bank(AccountDatabase& ref)
    : m_ref { ref } {}

    void setDetails(const char* owner, long bankAccountNumber, long amount);
    inline void getDetails() { m_ref.printData(); }

    private:
    AccountDatabase &m_ref;
};

int
main(int argc, char** argv)
{
    // runtime
    char *p;
    long accNmb = strtol(argv[2], &p, 10);
    long amount = strtol(argv[3], &p, 10);
    

    InMemoryAccountDataBase inMemDB;
    Bank* ptrOnBank = new Bank(inMemDB);
    ptrOnBank->setDetails(argv[1], accNmb, amount);
    ptrOnBank->getDetails();

    delete ptrOnBank;

    return 0;
}

void Bank::setDetails(const char* owner, long bankAccountNumber, long amount)
{
    m_ref.setData(owner, bankAccountNumber, amount);
}
