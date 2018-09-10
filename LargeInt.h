#ifndef LARGEINT_H
#define LARGEINT_H

//This shows how many digits the Large Int has. You can change this if you need more digits. Functions are compatible.
#define DIGITLIMIT 100
//This shows the base in which the Large Int is stored. Currently  some functions are not compatible for the change in this value.
#define BASE 10

//These are the constants used for function CompareInt.
enum{EQUAL, GREATER, SMALLER};

class LargeInt
{
    public:
        //Returns how many digits the Large Int has.
        int IntSizeL();

        //Returns the nth digit of the Large Int.
        int GetDigitL(int NthDigit);

        //Resets the Large Int to 0.
        void ResetL();

        //Changes Large Int to the given number.
        void ChangeL(LargeInt ChangeTo);

        //Adds 1 to the Large Int.
        void Increment();

        //Returns how many digits the given number has.
        int IntSize(int MeasuredInt);

        //Returns the nth digit of the given number.
        int GetDigitInt(int Number, int NthDigit);

        //Compares the Large Int to given number. Returns 0 if they are equal, 1 if the Large Int is greater, 2 if the Large Int is smaller.
        int CompareInt(int ComparedNumber);

        //Shift the digits of the Large Int to the left by given number. Adds 0s to the emptied digits. This makes the number bigger.
        void ShiftL(int ShiftBy);

        /*Inserts the digits of the given number to the Large Int.
        At the end of this process the Large Int will be equal to the given number if the Large Int was 0 at the beginning.*/
        void InsertDigits(int InsertedNumber);

        //Adds the given number to Large Int.
        int AdditionL(LargeInt AddedNumber);
        void AdditionInt(int AddedNumber);

        //Multiplies the Large Int by the given number.
        void MultiplyInt(int MultipliedNumber);

        //Divides the Large Int by the given number.
        void DivideInt(int DivideBy);

        //Gives the modulus of the Large Int for the given number.
        int ModulusInt(int ModulusBase);

        //Returns the value of the Large Int. This should not be used if the Large Int is too big.
        int ConvertToInt();

        //Prints the Large Int.
        void PrintL();

        //Initial value of a Large Int is 0.
        LargeInt();
    private:
        //Digits of the number in decimal. Smallest value digit is stored in first index.
        int Digits[DIGITLIMIT];
        //This is how many digits the Large Int has.
        int NumberofDigits;
};

#endif // LARGEINT_H
