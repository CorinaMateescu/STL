#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    ifstream inFile("input3.txt");

    int no_problems, no_doctors;
    string name, speciality;

    inFile >> no_problems;
    vector<string>necessary;//vector pt specializarile de care avem nevoie
    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        necessary.emplace_back(speciality);
        //cout << name << ' ' << speciality << '\n';
    }

    inFile >> no_doctors;
    unordered_set<string>doctors;// set in care salvam specializarile doctorilor
    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        doctors.insert(speciality);
        // cout << name << ' ' << speciality << '\n';
    }
    inFile.close();
    for (const string& speciality : necessary)//specializarile din vectorul necessary
    {
        if (doctors.find(speciality) != doctors.end())// daca gasim specializarea pana la finalul set-ului scriem admis
        {
            cout << speciality << " Acceptat"<<endl;
        }
        else
        {
            cout << speciality << " Respins"<<endl;//altfel respins
        }
    }
    return 0;
}

/*int main()
{
    ifstream inFile("input.txt");

    int no_problems, no_doctors;
    string name, speciality;
    
    inFile >> no_problems;
    vector<string>necessary;
    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        necessary.emplace_back(speciality);
        //cout << name << ' ' << speciality << '\n';
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        for (int i = 0; i < no_doctors; i++)
        {
            if (necessary[i] == speciality)
                cout << speciality<<" " << "Accepted"<<endl;
            else
                cout << speciality << " " << "Rejected" << endl;
        }
       // cout << name << ' ' << speciality << '\n';
    }
   
    return 0;
}*/