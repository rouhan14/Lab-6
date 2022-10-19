#include <bits/stdc++.h>
using namespace std;

bool moveMin(vector<int> &in, vector<int> &out)
{
    bool status = true;

    for (int i = 0; i < in.size(); i++)
    {
        out.push_back(in[i]);
    }

    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out.size() - 1; j++)
        {
            if (out[j] > out[i])
            {
                int temp;
                temp = out[j];
                out[j] = out[i];
                out[i] = temp;
            }
        }
    }

    // Comparing vectors that was sorted by bubble sort and the vector itself.
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] != out[i])
        {
            status = false;
            break;
        }
    }

    return status;
}

bool testMoveMin(){
    bool status = true;

    srand(time(0));
    vector<int> vec1;
    vector<int> vec2;
    vector<int> vec3;

    for (int i = 0; i < 7; i++){
        vec1.push_back(rand() % 100);
    }

    sort(vec1.begin(), vec1.end());

    vec1.push_back(rand() % 101);

    // Sorting using sort function created from bubble sort.
    bool bubble = moveMin(vec1, vec2);



    // Sorting using sort function.
    for (int i = 0; i < vec1.size(); i++){
        vec3.push_back(vec1[i]);
    }
    sort(vec3.begin(), vec3.end());


    // Comparing vectors that was sorted by sort function and the vector itself.
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] != vec3[i]){
            status = false;
            break;
        }
    }


    // Comparing if the bubble sort and the sort function gave the same ans.
    if (bubble == status){
        status = true;
    }
    else{
        status = false;
    }

    return status;
}

int main(){

    cout << "Test case answer: " << testMoveMin() << endl;

    return 0;
}