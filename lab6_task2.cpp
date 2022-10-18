#include <bits/stdc++.h>
using namespace std;

bool moveMin(vector<int> &in, vector<int> &out){
    bool status = true;
    for (int i = 0; i < in.size(); i++){
        out.push_back(in[i]);
    }
    for (int i = 0; i < out.size(); i++){
        for (int j = 0; j < out.size() - 1; j++){
            if (out[j] > out[i]){
                int temp;
                temp = out[j];
                out[j] = out[i];
                out[i] = temp;
            }
        }
    }

    for (int i = 0; i < in.size(); i++){
        if ( in[i] != out[i]){
            status = false;
        }
    }

    return status;
}

bool testMoveMin(vector<int> &in, vector<int> &out){
    bool status;
    

    return status;
}

int main(){
    srand(time(0));
    vector<int> vec1;
    vector<int> vec2;
    for (int i = 0; i < 7; i++){
        vec1.push_back(rand() % 100);
    }
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 6; j++){
            if(vec1[j] > vec1[i]){
                int temp;
                temp = vec1[j];
                vec1[j] = vec1[i];
                vec1[i] = temp;
            }
        }
    }
    vec1.push_back(rand() % 70);

    cout << moveMin(vec1, vec2) << endl;

    return 0;
}