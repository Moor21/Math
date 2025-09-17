#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


class LangrangeInterpolation
{
private:
    vector<double>xVector;
    vector<double>yVector;
    vector<double>langrangePolinom;
    double X;
    int N;
    double polinom;
    int li;
    void CountingLangrange()
    {
        
        for (int li = 0; li < N; li++)
        {
            double m = 1;
            double r = 1;
            for (int i = 0; i < li; i++)
            {
                m = m * (X - xVector[i]);
                r = r * (xVector[li] - xVector[i]);
            }
            for (int i = li+1; i < N; i++)
            {
                m = m * (X - xVector[i]);
                r = r * (xVector[li] - xVector[i]);
            }
            langrangePolinom.push_back(m / r);
        }
    }
    void EnterNumberOfPoints()
    {
        cout << endl << "Enter number of Points: ";
        cin >> N;
    }
    void EnterThePoints()
    {
        cout << endl << "Enter the points: " << endl;
        for (int i = 0; i < N; i++)
        {
            double x = 0.0, y = 0.0;
            cout << "Enter X" << i << ": ";
            cin >> x;
            cout << "Enter Y" << i << ": ";
            cin >> y;
            xVector.push_back(x);
            yVector.push_back(y);
        }
    }
    void EnterTheX()
    {
        X = 0;
        cout << endl << "Enter the new X: ";
        cin >> X;
    }
    void CountingPolinom()
    {
        polinom = 0.0;
        for (int i = 0; i < N; i++)
        {
            polinom += langrangePolinom[i] * yVector[i];
        }
    }
    void printPolinom()
    {
        cout << endl << "New coordinates is: (" << X << "," << polinom << ")" << endl;
    }
public:
    LangrangeInterpolation()
    {
        EnterNumberOfPoints();
        EnterThePoints();
        EnterTheX();
        CountingLangrange();
        CountingPolinom();
        printPolinom();

    }
};


int main()
{
    LangrangeInterpolation* langrange = new LangrangeInterpolation();
    
}

