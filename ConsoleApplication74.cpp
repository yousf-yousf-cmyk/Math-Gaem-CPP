#include <iostream>
#include "My.h"
using namespace std;

enum enLevel{Easy = 1, Medium = 2,Hard = 3, MixLevel = 4};
enum enOperatinoType{Add=1,Sub=2,Mul=3,Div=4,MixOp=5};
//
struct StQuizz
{
    enLevel QuestionsLevel;
    int NumberOfQuestions = 0;
    enOperatinoType OpType;
    int CorrectAnswers = 0;
    int WrongAnswers = 0;
};
//لادخال مستوا صعوبة
enLevel ReadLevel()
{
    int Number = ReadNumber("\nEasy:[1], Medium:[2],Hard:[3], MixLevel:[4]\n");
    return (enLevel)Number;
}
//لادخال نوع العملية الحسابية
enOperatinoType ReadType()
{
    int Number = ReadNumber("\n+[1],-[2],*[3],/[4],MixOp[5]\n");
    return (enOperatinoType)Number;
}
//
void PlayGame(StQuizz &Quizz)
{
    Quizz.NumberOfQuestions=ReadNumber("\nHow Many questions?\n");
    Quizz.QuestionsLevel = ReadLevel();
    Quizz.OpType = ReadType();
    
       
    
}
//لتشيك متسوا الصعوبة
void CheckLevel(StQuizz &Quizz, int &Number1,int &Number2)
{
    
    switch (Quizz.QuestionsLevel)
    {
    case enLevel::Easy:
        Number1 = RandomNumber(1, 10);
        Number2 = RandomNumber(1, 10);
        break;
    case enLevel::Hard:
        Number1 = RandomNumber(50, 100);
        Number2 = RandomNumber(50, 100);
        break;
    case enLevel::Medium:
        Number1 = RandomNumber(20, 50);
        Number2 = RandomNumber(20, 50);
        break;
    case enLevel::MixLevel:
        Number1 = RandomNumber(1, 100);
        Number2 = RandomNumber(1, 100);
        break;
    }
}
//لتشيك نوع العملية الحسابية
void CheckType(StQuizz& Quizz,int &Number1,int &Number2)
{
    int Number,Sum=0,Type;
    if (Quizz.OpType == 5)
    {
        Type = RandomNumber(1, 4);
    }
    else
    {
        Type = Quizz.OpType;
    }

    switch (Type)
    {
    case enOperatinoType::Add:
        cout << Number1 << "+" << Number2 << endl;
        Sum = Number1 + Number2;
        cin >> Number;
        break;
    case enOperatinoType::Sub:

        cout << Number1 << "-" << Number2 << endl;

        Sum = Number1 - Number2;
        cin >> Number;
        break;
    case enOperatinoType::Mul:
        cout << Number1 << "*" << Number2 << endl;
        Sum = Number1 * Number2;
        cin >> Number;
        break;
    case enOperatinoType::Div:
        cout << Number1 << "/" << Number2 << endl;
        Sum = Number1 / Number2;
        cin >> Number;
        break;
    }
    if (Number == Sum)
    {
        system("color 2F");
        cout << "\nCorect\n\n";
        Quizz.CorrectAnswers++;
    }
    else
    {
        system("color 4F");
        cout << "\a\nWrong\n\n";
        Quizz.WrongAnswers++;
    }
    
}
//طباعة نتائج
void PrintFinal()
{
    cout << "\n\t------------------------\n";
    cout << "\t    Final results";
    cout << "\n\t------------------------\n";
}
void PrintOutput(StQuizz Quizz)
{
    if (Quizz.CorrectAnswers > Quizz.WrongAnswers)
    {
        system("color 2F");
        cout << "\n\tQuestions:" << Quizz.NumberOfQuestions
           
            << "\n\tCorect:" << Quizz.CorrectAnswers
            << "\n\tWrong:" << Quizz.WrongAnswers << endl;
    }
    else if(Quizz.WrongAnswers>Quizz.CorrectAnswers)
    {
        system("color 4F");
        cout << "\n\tQuestions:" << Quizz.NumberOfQuestions
           
            << "\n\tCorect:" << Quizz.CorrectAnswers
            << "\n\tWrong:" << Quizz.WrongAnswers << endl;
    }
    else
    {
        system("color 3F");
        cout << "\n\tQuestions :" << Quizz.NumberOfQuestions
           
            << "\n\tCorect:" << Quizz.CorrectAnswers
            << "\n\tWrong:" << Quizz.WrongAnswers << endl;
    }
}
// لتجميع فانكشن
void StartGame()
{
    string playAgain = "Y";
    do
    {
        system("color 0F");
        StQuizz Quizz;
       PlayGame( Quizz);
      int Number1, Number2;
        for (int i = 1; i <= Quizz.NumberOfQuestions; i++)
        {
             
            CheckLevel(Quizz,Number1, Number2);

            CheckType(Quizz, Number1, Number2);

        }
        PrintFinal();
        PrintOutput(Quizz);
        cout << "\nDo you want to continue? [Y]yas [N]No:";
        cin >> playAgain;
    } while (playAgain == "Y" || playAgain == "y");
}
int main()
{
    srand(time(0));
    StartGame();
}

