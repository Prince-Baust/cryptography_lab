#include <cmath>
#include<iostream>

using namespace std;

class BBS
{
private:
    long p, q, n, x0, decryptionExp;

public:
    BBS();

    BBS(long p, long q, long seed);
    int getRandBit();
    long getRandNum();
    void setParams(long p, long q, long seed);
};

void BBS::setParams(long p, long q, long seed)
{
    //choose p and q such that gcd(p, q) = 1
    this->p = p;
    this->q = q;
    //random seed should be netween 1 & n-1
    this->x0 = seed;
    //blum integer
    this->n = p * q;
}

BBS::BBS(long p, long q, long seed)
{
    this->setParams(p, q, seed);
}

long BBS::getRandNum()
{
    long nextRandNum = (this->x0 * this->x0) % this->n;
    this->x0 = nextRandNum;
    return nextRandNum;
}

int BBS::getRandBit()
{
    return this->getRandNum() % 2;
}

int main()
{
    const int P = 7;
    const int Q = 19;
    const int seed = 6;

    BBS numberGen(P, Q, seed);

    //generate 6 random numbers
    for (int i = 0; i < 6; i++)
    {
        cout << numberGen.getRandNum() << " ";
    }

    cout << endl;

    //generate 6 random bits
    for (int i = 0; i < 6; i++)
    {
        cout << numberGen.getRandBit() << " ";
    }

    return 0;
}
