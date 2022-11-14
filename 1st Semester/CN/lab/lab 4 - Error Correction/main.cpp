#include <iostream>
#include <math.h>

using namespace std;

class SignalEncode
{
    int data[10];
    int data_bits;
    int encoded[10];
    int parity[10];
    bool even_encoding;

public:
    SignalEncode(int *data, int len, bool even_encoding)
    {
        copy(data, data + len, begin(this->data));
        this->even_encoding = even_encoding;
        data_bits = len;
    }

    void hamming_encode();
};

int main()
{
    int data[] = {0, 1, 0, 0};

    SignalEncode obj = SignalEncode(data, 4, true);

    obj.hamming_encode();

    return 0;
}

void SignalEncode::hamming_encode()
{
    int i = 0;
    while(pow(2, i) < data_bits+1) {
        ++i;
    }
    cout << i;
}