#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream intrare("cod.in");
ofstream iesire("cod.out");

void citireVector(unsigned short int numere[1000], unsigned short int numarDeNumere, unsigned long long &nrZerouri)
{
  for (int i = 0; i < numarDeNumere; i++)
  {
    intrare >> numere[i];
    if (numere[i] == 0)
      nrZerouri++;
  }
}

void celMaiMicNumar(unsigned short int numere[1000], unsigned short int numarDeNumere)
{

  for (int i = 0; i < numarDeNumere - 1; i++)
  {
    for (int j = i + 1; j < numarDeNumere; j++)
    {
      if (numere[i] > numere[j])
      {
        swap(numere[i], numere[j]);
      }
    }
  }
}

unsigned long long construireNumarDinVector(unsigned short int numere[1000], unsigned short int numarDeNumere, unsigned long long nrZerouri)
{
  unsigned long long numar = 0;
  unsigned short int aux = numarDeNumere;

  for (int i = 0; i < numarDeNumere; i++)
  {
    if (numere[i] != 0)
    {
      numar += numere[i] * pow(10, aux - 1);
    }
    aux--;
  }

  // Adaugam zerourile la nr filtrat fara zerouri
  unsigned long long impartitor = pow(10, numarDeNumere - nrZerouri - 1);
  unsigned long long auxNumar = numar % impartitor;

  return numar / impartitor * pow(10, numarDeNumere - 1) + auxNumar;
}

int main()
{
  unsigned short int numere[1000];
  unsigned short int numarDeNumere;
  unsigned long long nrZerouri = 0;

  intrare >> numarDeNumere;
  citireVector(numere, numarDeNumere, nrZerouri);
  celMaiMicNumar(numere, numarDeNumere);
  iesire << construireNumarDinVector(numere, numarDeNumere, nrZerouri);
  return 0;
}