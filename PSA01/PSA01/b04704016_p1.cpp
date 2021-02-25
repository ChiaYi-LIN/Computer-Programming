#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    cout<< "A:"
        << "\"Hey! May I ask some questions about " << "C" << "\\" << "C++" << ".\"" << endl;
    cout<< "B:"
        << "\"Sure. "<< "C" << "\\" << "C++" << " is very interesting to me. "
        << "What's your question?\"" << endl;
    cout<< "A:"
        << "\"The first question is: How to show values using printf ?\""<< endl;
    cout<< "B:"
        << "\"Ok! It's not a difficult question.\"" << endl;
    cout<< "B:"
        << "\"Let me show you.\""<< endl;

    cout << endl;
    int song = 9453;
    printf("song = %d\n", song);
    cout << endl;

    cout<< "A:"
        << "\"It's the song of 911. (^^)\"" << endl;
    cout<< "A:"
        << "\"Then the second question is: How to use sizeof() in " << "C++" << "?\""<< endl;
    cout << endl;
    cout<< "sizeof( double )\t=\t"<< sizeof(1.0)<< "bytes;\n";
    cout<< "sizeof( float  )\t=\t"<< sizeof(1)<< "bytes;\n";
    cout<< "sizeof( long double )\t=\t"<< sizeof(1.01)<< "bytes.\n";

    return 0;
}
