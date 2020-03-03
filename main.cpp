#include <iostream>
#include <fstream>

/**
 * Aric Shi
 * February 18, 2020
 * Caesar 3: (rP + s) % 26
 */

using namespace std;

bool gcf(int firstNumber, int secondNumber)
{
    int gcf = 0;
    for (int index = 1; index <= firstNumber && index <= secondNumber; index++)
    {
        if ((firstNumber % index == 0) && (secondNumber % index == 0)) gcf = index;
    }
    if (gcf == 1)
    {
        return true;
    } else return false;
}

bool isLetter(char s)
{
    if ((s >= 65 && s <= 90) || (s >= 97 && s <= 122))
    {
        return true;
    } else return false;
}

int main()
{
    ofstream outfile("Caesar3.out");
    ifstream infile("Caesar3.in");
    int r, s;
    bool stopCheckr = false, stopChecks = false;
    char plain, cypher;

    //if (infile.fail)
    //{
    //    cout << "Sorry. Could not open file" << endl;
    //}

    cout << "Enter the multiplier" << endl;
    cin >> r;

    do
    {
        if (!gcf(r, 26))
        {
            cout << "The greatest common factor of the multiplier and 26 must be 1" << endl;
            cin >> r;
        } else if (r > 25)
        {
            cout << "The multiplier must be smaller than 26" << endl;
            cin >> r;
        } else if (gcf(r, 26) && r < 26) stopCheckr = true;
    } while (!stopCheckr);
    cout << "Enter the scramble value" << endl;
    cin >> s;
    do
    {
        if (s > 25 || s < 1)
        {
            cout << "The scramble value must be between 1 and 26" << endl;
        } else stopChecks = true;
    } while (!stopChecks);

    while (infile.get(plain))
    {
        if (isLetter(plain))
        {
            plain = plain - 65;
            cypher = r * plain + s;
            cypher = cypher % 26;
            cypher = cypher + 65;
            outfile << cypher;
        } else outfile << plain;
    }
    return 0;
}
