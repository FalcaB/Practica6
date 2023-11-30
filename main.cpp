#include <iostream>
#include "cuerpo.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    vector<cuerpo*> cuerpos;

    string line;
    ofstream fout;
    fout.open("calculos.txt");
    ifstream arch;
    arch.open("cuerpos.txt");
    if(arch.is_open()){
        while(getline(arch, line)){
            double x, y, m, r, vx, vy;

            istringstream ss(line);
            string token;
            int index = 0;
            while(getline(ss, token, ','))
            {
                if(index == 0)
                {
                    x = stod(token); // Convierte la cadena a double
                }
                else if(index == 1)
                {
                    y = stod(token);
                }
                else if(index == 2)
                {
                    m = stod(token);
                }
                else if(index == 3)
                {
                    r = stod(token);
                }
                else if(index == 4)
                {
                    vx = stod(token);
                }
                else if(index == 5)
                {
                    vy = stod(token);
                }
                index++;
            }
            cuerpos.push_back(new cuerpo(x, y, m, r, vx, vy));
            fout<<x<<"\t"<<y<<"\t";
        }
        fout<<endl;
    }



    for(int i=0; i<10000; i++)
    {
        for(const auto& itP : cuerpos)
        {
            double AFx = 0, AFy = 0;
            for(const auto& itO : cuerpos)
            {
                if(itP != itO)
                {
                    itP->A(itO->getPX(), itO->getPY());
                    itP->CalA(itO->getM(), itO->getPX(), itO->getPY());
                    AFx += itP->getAX();
                    AFy += itP->getAY();
                }
            }
            itP->setAX(AFx);
            itP->setAY(AFy);
            itP->CalVel();
            itP->CalP();
            fout<<itP->getPX()<<"\t"<<itP->getPY()<<"\t";
        }
        fout<<endl;
    }

    fout.close();
    cout<<"FIN"<<endl;

    return 0;
}
