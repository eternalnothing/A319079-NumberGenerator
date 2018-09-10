#include <iostream>
#include <math.h>
#include "LargeInt.h"

using namespace std;

int LargeInt::IntSizeL()
{
    return NumberofDigits;
}

int LargeInt::GetDigitL(int NthDigit)
{
    return Digits[NthDigit];
}

void LargeInt::ResetL()
{
    int i;
    for(i=0; i<DIGITLIMIT; i++)
    {
        Digits[i]=0;
    }
    NumberofDigits=0;
}

void LargeInt::ChangeL(LargeInt ChangeTo)
{
    int i;
    for(i=0; i<ChangeTo.IntSizeL(); i++)
        Digits[i]=ChangeTo.GetDigitL(i);
    while(i<NumberofDigits)
    {
        Digits[i]=0;
        i++;
    }
    NumberofDigits=ChangeTo.IntSizeL();
}

void LargeInt::Increment()
{
    int i=0; int temporary;
    do
    {
        Digits[i]++;
        temporary=Digits[i];
        Digits[i]=Digits[i]%BASE;
        i++;
    }
    while(temporary/BASE);
    if(i>NumberofDigits)
        NumberofDigits=i;
}

int LargeInt::IntSize(int MeasuredInt)
{
    int thesize=0;
    while(MeasuredInt)
    {
        MeasuredInt=MeasuredInt/10;
        thesize++;
    }
    return thesize;
}

int LargeInt::GetDigitInt(int Number, int NthDigit)
{
    int i=1;
    if(NthDigit<=IntSize(Number))
    {
        while(i<NthDigit)
        {
            Number=Number/10;
            i++;
        }
    return Number%10;
    }
    else
        return 0;
}

int LargeInt::CompareInt(int ComparedNumber)
{
    int i;
    if(IntSize(ComparedNumber)<NumberofDigits)
        return GREATER;
    else if(IntSize(ComparedNumber)>NumberofDigits)
        return SMALLER;
    else
    {
        for(i=NumberofDigits-1; i>=0; i--)
        {
            if(Digits[i]<GetDigitInt(ComparedNumber, i+1))
            {
                return SMALLER;
                break;
            }
            else if(Digits[i]>GetDigitInt(ComparedNumber, i+1))
            {
                return GREATER;
                break;
            }
        }
    }
    return EQUAL;
}

void LargeInt::ShiftL(int ShiftBy)
{
        int i;
    for(i=NumberofDigits+ShiftBy-1; i>=ShiftBy; i--)
        Digits[i]=Digits[i-ShiftBy];
    for(i=0; i<ShiftBy; i++)
        Digits[i]=0;
    NumberofDigits=NumberofDigits+ShiftBy;
}

void LargeInt::InsertDigits(int InsertedNumber)
{
    int i=0;
    do
    {
        Digits[i]=InsertedNumber%BASE;
        InsertedNumber=InsertedNumber/BASE;
        i++;
    }
    while(InsertedNumber);
}

int LargeInt::AdditionL(LargeInt AddedNumber)
{
    int i; int takeover=0; int tempTakeover=0;
    int addingdigits;;
    if(NumberofDigits>AddedNumber.IntSizeL())
        addingdigits=NumberofDigits;
    else
        addingdigits=AddedNumber.IntSizeL();
    if(addingdigits>DIGITLIMIT)
        return 0;
    else
    {
        for(i=0; i<addingdigits; i++)
        {
            tempTakeover=(Digits[i]+AddedNumber.Digits[i]+takeover)/BASE;
            Digits[i]=(Digits[i]+AddedNumber.Digits[i]+takeover)%BASE;
            takeover=tempTakeover;
        }
        Digits[i]=takeover;
        if((i>=NumberofDigits) && (Digits[i]>0))
            NumberofDigits=addingdigits+1;
        else
            NumberofDigits=addingdigits;
        return 1;
    }
}

void LargeInt::AdditionInt(int AddedNumber)
{
    int i; int takeover=0; int tempTakeover=0;
    int addingdigit;
    if(NumberofDigits>IntSize(AddedNumber))
        addingdigit=NumberofDigits;
    else
        addingdigit=IntSize(AddedNumber);
    for(i=0; i<addingdigit; i++)
    {
        tempTakeover=(Digits[i]+GetDigitInt(AddedNumber, i+1)+takeover)/BASE;
        Digits[i]=(Digits[i]+GetDigitInt(AddedNumber, i+1)+takeover)%BASE;
        takeover=tempTakeover;
    }
    Digits[i]=takeover;
    if(Digits[i]>0)
        NumberofDigits=addingdigit+1;
    else
        NumberofDigits=addingdigit;
}

void LargeInt::MultiplyInt(int MultipliedNumber)
{
    LargeInt Result;
    LargeInt tempResult;
    int i;
    for(i=0; i<NumberofDigits; i++)
    {
        tempResult.ShiftL(IntSize(Digits[i]*MultipliedNumber));
        tempResult.InsertDigits(Digits[i]*MultipliedNumber);
        tempResult.ShiftL(i);
        Result.AdditionL(tempResult);
        tempResult.ResetL();
    }
    ChangeL(Result);
}

void LargeInt::DivideInt(int DivideBy)
{
    LargeInt Result;
    int i=NumberofDigits-1;
    int temporary=0;
    int divided=0;
    while(i+1)
    {
        temporary=temporary+Digits[i];
        if(temporary/DivideBy)
        {
            Result.ShiftL(1);
            Result.InsertDigits(temporary/DivideBy);
            temporary=(temporary%DivideBy)*BASE;
            divided=1;
            i--;
        }
        else if((divided==1) && !(temporary/DivideBy))
        {
            Result.ShiftL(1);
            Result.InsertDigits(0);
            temporary=(temporary%DivideBy)*BASE;
            i--;
        }
        else
        {
            temporary=(temporary%DivideBy)*BASE;
            i--;
        }
    }
    ChangeL(Result);
}

int LargeInt::ModulusInt(int ModulusBase)
{
    LargeInt Result;
    int i=NumberofDigits-1;
    int temporary=0;
    int divided=0;
    int lastoperation=0;
    while(i+1)
    {
        temporary=temporary+Digits[i];
        if(temporary/ModulusBase)
        {
            Result.ShiftL(1);
            Result.InsertDigits(temporary/ModulusBase);
            temporary=(temporary%ModulusBase)*BASE;
            divided=1;
            lastoperation=1;
            i--;
        }
        else if((divided==1) && !(temporary/ModulusBase))
        {
            Result.ShiftL(1);
            Result.InsertDigits(0);
            temporary=(temporary%ModulusBase)*BASE;
            i--;
            lastoperation=1;
        }
        else
        {
            temporary=(temporary%ModulusBase)*BASE;
            lastoperation=0;
            i--;
        }
    }
    if(lastoperation)
        return temporary/10;
    else
        return temporary;
}

int LargeInt::ConvertToInt()
{
    int i; int converted=0;
    for(i=0; i<NumberofDigits; i++)
    {
        converted=converted+(Digits[i]*pow(10,i));
    }
    return converted;
}

void LargeInt::PrintL()
{
    int i;
    for(i=NumberofDigits-1; i>=0; i--)
        cout<<Digits[i];
    cout<<"\n";
}

LargeInt::LargeInt()
{
    ResetL();
}
