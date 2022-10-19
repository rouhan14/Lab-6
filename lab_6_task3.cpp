#include <bits/stdc++.h>
using namespace std;

bool moveMin(vector<int> &in, vector<int> &out)
{
    bool status = true;

    for (int i = 0; i < in.size(); i++)
    {
        out.push_back(in[i]);
    }

    int temp;
    int pos = out.size() - 1;
    for (int i = out.size() - 2; i > -1; i--){
        if (out[pos] < out[ i ]){
            temp = out[i];
            out[i] = out[pos];
            out[pos] = temp;
            pos--;
        }
    }

    for (int i = 0; i < in.size(); i++){
        if (in[i] != out[i])
        {
            status = false;
            break;
        }
    }

    return status;
}

bool testMoveMin(vector<int> &in, vector<int> &out){
    bool status = true;

    for (int i = 0; i < in.size(); i++)
    {
        out.push_back(in[i]);
    }

    sort(out.begin(), out.end());

    for (int i = 0; i < out.size(); i++)
    {
        if (in[i] != out[i])
        {
            status = false;
            break;
        }
    }

    return status;
}

int main()
{
    
    for (int i = 0; i < 7; i++)
    {
        vec1.push_back(rand() % 100);
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (vec1[j] > vec1[i])
            {
                int temp;
                temp = vec1[j];
                vec1[j] = vec1[i];
                vec1[i] = temp;
            }
        }
    }

    vec1.push_back(rand() % 100);

    cout << "Output from my sorting function:\t" << moveMin(vec1, vec2) << endl;

    return 0;
}