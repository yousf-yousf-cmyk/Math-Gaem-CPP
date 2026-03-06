#pragma once
#include <iostream>
#include <string>
using namespace std;
void ReadNumberOfinputs(int arrNumbr[100], int& inputs)
{
    cout << "Enter inputs\n";
    cin >> inputs;
    cout << "Enter number elements\n";
    for (int i = 0; i < inputs; i++)
    {
        cout << "Element [" << i + 1 << "]:";
        cin >> arrNumbr[i];

    }
}
void ReadNameOfinputs(string arrName[100], int& inputs)
{
    cout << "Enter inputs\n";
    cin >> inputs;
    cout << "Enter Name\n";
    for (int i = 0; i < inputs; i++)
    {
        cout << "Name [" << i + 1 << "]:";
        cin >> arrName[i];
    }
}
void PrintArraystring(string Array[100], int inputs)
{


    for (int i = 0; i < inputs; i++)
    {
        cout << Array[i] << " ";
    }
    cout << "\n";
}
void PrintArrayint(int Array[100], int inputs)
{


    for (int i = 0; i < inputs; i++)
    {
        cout << Array[i] << " ";
    }
    cout << "\n";
}
int ReadNumber(string Masge)
{
    int Num;
    do
    {
        cout << Masge << endl;

        cin >> Num;

    } while (Num < 0);

    return Num;
}
int RandomNumber(int Foom, int To)
{
    int Rand;
    Rand = rand() % (To - Foom + 1) + Foom;
    return Rand;
}
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };
enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
        {
            return enPrimNotPrime::NotPrime;
        }
    }
    return enPrimNotPrime::Prime;
}
void Shuff(int& A, int& B)
{
    int Tom;
    Tom = A;
    A = B;
    B = Tom;
}
void AddArrayElement(int Number, int arra[100], int& laen)
{
    arra[laen] = Number;
    laen++;
}
void CopyOddNumbers(int arra[100], int arraodd[100], int laenarra, int& laenarraodd)
{
    for (int i = 0; i < laenarra; i++)
    {
        if (arra[i] % 2 != 0)
        {
            AddArrayElement(arra[i], arraodd, laenarraodd);
        }
    }

}
void ReadinputsArray(int ArraN[100], int& laenNumber)
{
    laenNumber = ReadNumber("Enter Inputs");
    for (int i = 0; i < laenNumber; i++)
    {
        ArraN[i] = RandomNumber(1, 100);
    }
}
int oddCount(int arra[100], int laen)
{
    int countr = 0;
    for (int i = 0; i < laen; i++)
    {
        if (arra[i] % 2 != 0)
        {
            countr++;
        }
    }
    return countr;
}
int EvenCount(int arra[100], int laen)
{
    int countr = 0;
    for (int i = 0; i < laen; i++)
    {
        if (arra[i] % 2 == 0)
        {
            countr++;
        }
    }
    return countr;
}
int Positvcountr(int arra[100], int laen)
{
    int countr = 0;
    for (int i = 0; i < laen; i++)
    {
        if (arra[i] >= 0)
        {
            countr++;
        }
    }
    return countr;
}
int Negativecountr(int arra[100], int laen)
{
    int countr = 0;
    for (int i = 0; i < laen; i++)
    {
        if (arra[i] < 0)
        {
            countr++;
        }
    }
    return countr;
}