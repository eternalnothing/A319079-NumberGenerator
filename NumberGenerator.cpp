#include <iostream>
#include "LargeInt.h"

using namespace std;

void NumberGenerator();

int main()
{
    NumberGenerator();
    return 0;
}

void NumberGenerator()
{
    //Test all the y up to given number
    int Test_y_Upto=100;

    //Test all the x up to given number. The higher number means the result for the y will be more reliable.
    int Test_x_Upto=1000000000;

    //There are loops that does not reach 1 for some y s. This is used to cut those cycles.
    int LimitLoop=5000000;
    //This counts the total steps for. When it reaches LimitLoop the loop is terminated.
    int counter=0;

    //Each y up to Test_y_Upto is tested. This is incremented each time a y is tested.
    int Currently_Tested_y;
    //Each x up to Test_x_Upto is tested. Currently_Tested_x is incremented each time an x is tested.
    LargeInt Currently_Tested_x; LargeInt Temporary_x;


    //x es smaller than this were successful. If a tested x was successful we don't need to test it again.
    int Are_Successful;

    //y=1 is obviously not gonna work. y=2 is already conjectured to always reach 1. Search 3x+1 problem.
    for(Currently_Tested_y=7; Currently_Tested_y<Test_y_Upto; Currently_Tested_y++)
    {
        /////////////      Initializing for the Current y.     /////////////////////
        counter=0;
        //All the x smaller than y will always reach 1. So, no need to test them.
        Are_Successful=Currently_Tested_y+1;
        Currently_Tested_x.ResetL();
        Currently_Tested_x.ShiftL(Currently_Tested_x.IntSize(Are_Successful));
        Currently_Tested_x.InsertDigits(Are_Successful);
        /////////////      Initializing for the Current y.     /////////////////////

        while(Currently_Tested_x.CompareInt(Test_x_Upto)==SMALLER)
        {
            Temporary_x.ChangeL(Currently_Tested_x);
            while((counter<LimitLoop) && (Temporary_x.CompareInt(1)==GREATER))
            {
                //x es smaller than Are_Successful are successful. So, no need to test further.
                if((Temporary_x.CompareInt(Are_Successful)==SMALLER))
                {
                    Temporary_x.ResetL();
                    Temporary_x.ShiftL(Temporary_x.IntSize(1));
                    Temporary_x.InsertDigits(1);
                    break;
                }
                else
                {
                    //If x mod y is not 0...
                    if(Temporary_x.ModulusInt(Currently_Tested_y))
                    {
                        //...we multiply x by y+1...
                        Temporary_x.MultiplyInt(Currently_Tested_y+1);
                        //...then add y to it and then subtract x mod y...
                        Temporary_x.AdditionInt(Currently_Tested_y - Temporary_x.ModulusInt(Currently_Tested_y));
                        //...finally we divide it by y.
                        Temporary_x.DivideInt(Currently_Tested_y);
                        counter++;
                    }
                    else
                    {
                        //If x mod y is 0 then we divide x by y.
                        Temporary_x.DivideInt(Currently_Tested_y);
                        counter++;
                    }
                }
            }
            //If Temporary_x did not reach 1 after the loop, we don't need to test any other x for the Currently_Tested_y as it has just failed.
            if((Temporary_x.CompareInt(1)!=EQUAL))
                break;
            else
                Are_Successful++;

            counter=0;
            Currently_Tested_x.Increment();
        }
        if(Are_Successful==Test_x_Upto)
            cout<<Currently_Tested_y<<"\n";
    }
}
