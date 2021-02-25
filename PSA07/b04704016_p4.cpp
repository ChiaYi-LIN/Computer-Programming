#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

int out_put(int fisrt_index, int last_index, double *sorted_seq, double target);

int main()
{

    int seq_size = 0, i =0, answer = 0;
    double *sorted_seq, target = 0;

    cin >> seq_size ;

    sorted_seq = new double [seq_size];

    for (i; i<seq_size; i++)
    {
        cin >> sorted_seq[i];
    }

    cin >> target;

    answer = out_put(0,seq_size-1,sorted_seq,target);
    cout << answer << endl;

    delete [] sorted_seq;
    return 0;

}

int out_put(int first_index, int last_index,double *sorted_seq, double target)
{

if (sorted_seq[(first_index+last_index)/2]==target)
{
    return (first_index+last_index)/2;
}
else if (first_index==last_index-1)
{
    return last_index;
}
else if (sorted_seq[(first_index+last_index)/2]>target)
{
    return out_put(first_index, (first_index+last_index)/2, sorted_seq, target);
}
else if (sorted_seq[(first_index+last_index)/2]<target)
{
    return out_put((first_index+last_index)/2, last_index, sorted_seq, target);
}

}

