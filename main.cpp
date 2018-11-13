#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
    long int level, column, mlevel;
    cout << "Podaj poziom: ";
    cin >> level;
    level = level - 1;
    column = level;
    mlevel = level;
    long int tab[ level + 1 ][ column + 1 ]; //making tab
    for( level = 0; level <= mlevel; level++ )
    {
        for( column = 0; column <= mlevel; column++ )
        {
            tab[ level ][ column ] = 0;
        }// cleaning tab
    }
    tab[ 0 ][ 0 ] = 1;
    tab[ 1 ][ 0 ] = 1;
    tab[ 1 ][ 1 ] = 1;

    for( long int level = 2; level <= mlevel; level++ )
    {
        for( long int column = 0; column <= level; column++ )
        {
            if( level == column ) tab[ column ][ level ] = 1;
            
            if( column == 0 ) tab[ column ][ level ] = 1;

            tab[ level ][ column ] = tab[ level - 1 ][ column - 1 ] + tab[ level - 1 ][ column ];
        }
    } //calculation of cell values
    for( level = 0; level <= mlevel; level++ )
    {
        for( column = 0; column <= level; column++ )
        {
            cout << tab[ level ][ column ] << " ";
        }
        cout << endl;
    }
    getch();
    return 0;
}

