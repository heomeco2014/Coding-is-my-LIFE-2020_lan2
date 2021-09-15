#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;
const long long M = pow(10.0, 9) + 9;


struct Company {
	string name;
	string profit_tax;
	string address;
};

vector <Company> ReadComapanyList(string file_name) {
	vector<Company> list;
	ifstream fi(file_name, ios::in);
	if (fi.fail()) return list;
	while (!fi.eof()) {
		string info;
		getline(fi, info);
		stringstream ss(info);
		Company x;
		getline(ss, x.name, '|');
		getline(ss, x.profit_tax, '|');
		getline(ss, x.address, '|');
		list.push_back(x);
	}
	fi.close();
	return list;
}

long long abc(int x) {
	long long rs = 1;
	for (int i = 1; i < x; i++) {
		rs = ((rs % M) * 31) % M;
	}
	return rs;
}

long long HashFormula(char x, int i) {
	long long res = 0;
	long long p = abc(i);
	res = (x * p % M) % M;
	return res;
}

long long HashString(string company_name) {
	string s = company_name.substr(company_name.length() - 20, 20);
	long long hashkey = 0;
	for (int i = 0; i < 20; i++) {
		hashkey += HashFormula(s[i], i);
	}
	return hashkey;
}

Company* CreateHashTable(string file_name) {
	vector <Company> ComapyList = ReadComapanyList(file_name);
	Company* list = new Company[2000];
	for (int i = 0; i < 2000; i++) {
		list[i].name = "";
	}
	for (int i = 1; i < ComapyList.size(); i++) {
		long long key = HashString(ComapyList[i].name) % 2000;
		while (list[key].name != "") {
			key = (key + 1) % 2000;
		}
		list[key] = ComapyList[i];
	}
	return list;
}

void Insert(Company* hash_table, Company company) {
	// Linear
	long long  key = HashString(company.name) % 2000;
	while (hash_table[key].name != "") {
		key = (key + 1) % 2000;
	}
	hash_table[key] = company;
}

Company* Search(Company* hash_table, string company_name) {
	if (hash_table == NULL) return NULL;
	long long key = HashString(company_name) % 2000;

	Company* res = new Company;
	while (hash_table[key].name != company_name && hash_table[key].name != "") {
		key = (key + 1) % 2000;
	}

	if (hash_table[key].name == company_name) {
		res->name = hash_table[key].name;
		res->address = hash_table[key].address;
		res->profit_tax = hash_table[key].profit_tax;
		return res;
	}
	else return NULL;
}

void printCompanyList(Company* hashtable) {
	for (int i = 0; i < 2000; i++) {
		if (hashtable[i].name != "") {
			cout << hashtable[i].name << "  " << i << endl;
		}
	}
}



int main() {
	cout << "2";
	Company* hashTable = CreateHashTable("input.txt");
	printCompanyList(hashTable);
	
	return 0;
}