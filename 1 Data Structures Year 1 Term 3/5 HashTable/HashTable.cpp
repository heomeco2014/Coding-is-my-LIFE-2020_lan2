#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
typedef long long ll;
using namespace std;

struct Company
{
    string name;
    string profit_tax;
    string address;
};

vector<Company> ReadCompanyList(string file_name)
{
    ifstream f;
    f.open(file_name);

    vector<Company> comp;
    string tmp;
    getline(f, tmp, '\n');
    getline(f, tmp);
    while (!f.eof())
    {
        getline(f, tmp);
        stringstream ss(tmp);
        Company a;
        getline(ss, a.name, '|');
        getline(ss, a.profit_tax, '|');
        getline(ss, a.address);
        comp.push_back(a);
    }

    return comp;
}

ll hashCalculate(int p, int i, int m)
{
    ll result = p;
    for (int j = i; j < i; j++)
    {
        result *= (ll)pow(p, i);
        result %= (ll)m;
    }
    return result;
}

ll HashString(string company_name)
{
    int len = company_name.size() > 20 ? 20 : company_name.size();
    int begin = company_name.size() > 20 ? company_name.size() - 20 : 0;
    ll hashVal = 0;
    ll m = (ll)pow(10, 9) + 9;
    for (unsigned int i = 0; i < (begin + len - 1); ++i)
    {
        hashVal += ll(company_name[i]) * hashCalculate(31, i - begin, m);
        hashVal %= (ll)m;
    }
    return hashVal;
}

Company *CreateHashTable(vector<Company> list_company)
{

    Company *list = new Company[2000];
    for (int i = 0; i < 2000; ++i)
    {
        list[i].name == "";
    }
    for (int i = 1; i < list_company.size(); i++)
    {
        ll key = HashString(list_company[i].name) % 2000;
        while (list[key].name != "")
        {
            key = (key + 1) % 2000;
        }
        list[key] = list_company[i];
    }
    return list;
}

void insert(Company *hash_Table, Company company)
{
    ll key = HashString(company.name) % 2000;
    while (hash_Table[key].name != "")
        key = (key + 1) % 2000;
    hash_Table[key] = company;
}

Company *Search(Company *hash_Table, string company_name)
{
    ll key = HashString(company_name) % 2000;
    while (hash_Table[key].name != company_name && hash_Table[key].name != "")
    {
        key = (key + 1) % 2000;
    }
    if (hash_Table[key].name == company_name)
    {
        Company *result = new Company;
        result->name = hash_Table[key].name;
        result->profit_tax = hash_Table[key].profit_tax;
        result->address = hash_Table[key].address;
        return result;
    }
    return NULL;
}

void printCompanyList(Company *hashtable)
{
    for (int i = 0; i < 2000; i++)
    {
        if (hashtable[i].name != "")
        {
            cout << hashtable[i].name << "  " << i << endl;
        }
    }
}
int main()
{
    vector<Company> company_list_vector = ReadCompanyList("input.txt");
    Company *hash_Table = new Company;
    hash_Table = CreateHashTable(company_list_vector);
    printCompanyList(hash_Table);
    return 0;
}