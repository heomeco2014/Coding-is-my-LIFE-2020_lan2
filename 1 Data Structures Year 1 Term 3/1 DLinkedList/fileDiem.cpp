#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct Examinee
{
    string id,name;
    float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science, 
        social_science, foreign_language;
};

Examinee readExaminee(string line_info){
    Examinee a;
    stringstream ss(line_info);
    string temp;
    getline(ss, a.id, ',');
	getline(ss, a.name, ',');
	getline(ss, temp, ',');	if (temp == "") a.math = 0; else a.math = stof(temp);
	getline(ss, temp, ',');	if (temp == "") a.literature = 0; else a.literature = stof(temp);
	getline(ss, temp, ',');	if (temp == "") a.physic = 0; else a.physic = stof(temp);
	getline(ss, temp, ',');	if (temp == "") a.chemistry = 0; else a.chemistry = stof(temp);
	getline(ss, temp, ',');	if (temp == "") a.biology = 0; else a.biology = stof(temp);
	getline(ss, temp, ',');	if (temp == "") a.history = 0; else a.history = stof(temp);
	getline(ss, temp, ',');	if (temp == "") a.geography = 0; else a.geography = stof(temp);
	getline(ss, temp, ',');	if (temp == "") a.civic_education = 0; else a.civic_education = stof(temp);
	getline(ss, temp, ','); if (temp == "") a.natural_science = a.physic + a.chemistry + a.biology;
	getline(ss, temp, ','); if (temp == "") a.social_science = a.history + a.geography + a.civic_education;
	getline(ss, temp, ','); if (temp == "") a.foreign_language = 0; else a.foreign_language = stof(temp);
    return a;
}

vector<Examinee> readExamineeList(string file_name)
{
    vector<Examinee> result;
    ifstream f(file_name);
    string line;
    while(!f.eof()){
        getline(f,line);
        Examinee tmp = readExaminee(line);
        result.push_back(tmp);
    }
    f.close();
    return result;
}

void writeTotal(vector<Examinee> examinee_list, string out_file_name){
    ofstream f(out_file_name);
    if(f.is_open()){
        for (size_t i = 0; i < examinee_list.size(); i++)
        {
            double sum = examinee_list[i].math + examinee_list[i].literature + examinee_list[i].foreign_language + examinee_list[i].natural_science + examinee_list[i].social_science;
            f << examinee_list[i].id << " " << sum << endl;
        }
        f.close();
    }
    else cout << "Cant Open FILE" << out_file_name << endl;

}

int main()
{
    vector<Examinee> examList;
	writeTotal(readExamineeList("input.txt"), "output.txt");
    return 0;
}