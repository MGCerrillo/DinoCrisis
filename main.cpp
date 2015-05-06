#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


using namespace std;


vector<GLfloat> coorTriangle;
GLfloat valuesX[20000], valuesY[20000], valuesZ[20000]; 
string tipo;                                              //Lo que estamos leyendo en la linea
string v;
int n=0;                                            //Numero de vertices y numero total de elementos respectivamente
int x=0;     

void leerFicheroObj()
{
    string line, s;

    ifstream myfile ("STEGOSRS1.txt");

    while(!myfile.eof())
    {
        getline (myfile,line);

        if (line[0] == 'v' && line[1] == ' ')                                                             //Leemos v's
        {
            std::istringstream iss(line);
            iss >> v >> valuesX[n]>> valuesY[n]>> valuesZ[n];
            cout << valuesX[n] << "\t" << valuesY[n] << "\t" << valuesZ[n] << endl;
            n++;                                                                        //Aumentamos el numero total de elementos
        }
                                                                                        //Leemos f's
        if (line[0] == 'f')
        {
            cout << "Hay barras\n" << endl;

            fscanf(myfile,"%d %d",);



            // std::istringstream iss(line);
            // iss >> v >> valuesX[n] >> s >> valuesY[n] >> s >> valuesZ[n];
            // cout << "Valores" << valuesX[n] << "\t" << valuesY[n] << "\t" << valuesZ[n] << endl;
            // cout << "lines3: " << line[3] << "lines5: " << line[5] << "lines6: " << line[6] << endl;
            // n++;
        }

        // if ((line[0] == 'f') && (line[3]!='/') && (line[4]!='/') && (line[5]!='/') && (line[6]!='/') && (line[7]!='/') && (line[8]!='/'))        //Si no hay barras
        // {
        //     std::istringstream iss(line);
        //     iss >> v >> valuesX[n] >> valuesY[n] >> valuesZ[n];
        //     cout << "A meter" << line[2] << "\t" << line[8] << "\t" << line[14] << endl;
        //     cout << "Valores" << valuesX[n] << "\t" << valuesY[n] << "\t" << valuesZ[n] << endl;
        //     //cin >> s;
        //     cout << "lines: " << line[3] << line [5] << endl;
        //     n++;                                                                        //Aumentamos el numero total de elementos
        // }
    }
}

int main(int argc, char * argv[] )
{
	glutInit(&argc, argv);
	glutCreateWindow("STEGOSRS");

    leerFicheroObj();


    cout << valuesX[0] << "\t" << valuesY[0] << "\t" << valuesZ[0] << endl;

 //    glutReshapeFunc(EscalaVentana);
	// glutDisplayFunc(DibujarEscena);

	glutMainLoop();
}