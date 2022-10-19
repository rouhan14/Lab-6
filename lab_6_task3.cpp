#include <bits/stdc++.h>
using namespace std;

bool moveMin(vector<int> &in, vector<int> &out)
{
    bool status = true;

    // Pushing the first vector elements into the second vector.
    for (int i = 0; i < in.size(); i++)
    {
        out.push_back(in[i]);
    }


    // Sorting the vector as stated in the lab task.
    int temp;
    int pos = out.size() - 1;
    for (int i = out.size() - 2; i > -1; i--)
    {
        if (out[pos] < out[i])
        {
            temp = out[i];
            out[i] = out[pos];
            out[pos] = temp;
            pos--;
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

bool testMoveMin()
{
    bool status = true;

    /* Creating three vector:
        vec1 -> all elements are sorted except the last element.
        vec2 -> all elements are sorted using bubble sort. (Done in the moneMin function).
        vec3 -> all elements are sorted using stl::sort() function.
    */

    srand(time(0)); // to randomize the value everytime we take it.
    vector<int> vec1;
    vector<int> vec2;
    vector<int> vec3;

    // Pushing random elements in the first vector.
    for (int i = 0; i < 7; i++)
    {
        vec1.push_back(rand() % 100);
    }

    // Sorting the first vector.
    sort(vec1.begin(), vec1.end());

    // Pushing a random element in the vectoor as mentioned in the lab.
    vec1.push_back(rand() % 101);

    // Sorting using sort function created from bubble sort.
    bool bubble = moveMin(vec1, vec2);

    // Sorting using sort function.
    for (int i = 0; i < vec1.size(); i++)
    {
        vec3.push_back(vec1[i]);
    }
    sort(vec3.begin(), vec3.end());

    // Comparing vectors that was sorted by sort function and the vector itself.
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] != vec3[i])
        {
            status = false;
            break;
        }
    }

    // Comparing if the bubble sort and the sort function gave the same ans.
    if (bubble == status)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}


// Generating different test cases.
bool testMoveMin_with_variable_size(int vector_size)
{
    bool status = true;

    /* Creating three vector:
        vec1 -> all elements are sorted except the last element.
        vec2 -> all elements are sorted using bubble sort. (Done in the moneMin function).
        vec3 -> all elements are sorted using stl::sort() function.
    */

    srand(time(0)); // to randomize the value everytime we take it.
    vector<int> vec1;
    vector<int> vec2;
    vector<int> vec3;

    // Pushing random elements in the first vector.
    for (int i = 0; i < vector_size - 1; i++)
    {
        vec1.push_back(rand() % 100);
    }

    // Sorting the first vector.
    sort(vec1.begin(), vec1.end());

    // Pushing a random element in the vectoor as mentioned in the lab.
    vec1.push_back(rand() % 101);

    // Sorting using sort function created from bubble sort.
    bool bubble = moveMin(vec1, vec2);

    // Sorting using sort function.
    for (int i = 0; i < vec1.size(); i++)
    {
        vec3.push_back(vec1[i]);
    }
    sort(vec3.begin(), vec3.end());

    // Comparing vectors that was sorted by sort function and the vector itself.
    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] != vec3[i])
        {
            status = false;
            break;
        }
    }

    // Comparing if the bubble sort and the sort function gave the same ans.
    if (bubble == status)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

int main()
{
    clock_t start, end;

    start = clock();
    cout << "Test case answer: " << testMoveMin() << endl;
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl
        << endl;

    start = clock();
    cout << "Test case answer with 1000 inputs: " << testMoveMin_with_variable_size(1000) << endl
        << endl;
    end = clock();

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl
        << endl;

    start = clock();
    cout << "Test case answer with 10000 inputs: " << testMoveMin_with_variable_size(10000) << endl
        << endl;
    end = clock();

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl
        << endl;

    start = clock();
    cout << "Test case answer with 100000 inputs: " << testMoveMin_with_variable_size(100000) << endl;
    end = clock();

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl
        << endl;

    start = clock();
    cout << "Test case answer with 1000000 inputs: " << testMoveMin_with_variable_size(1000000) << endl;
    end = clock();

    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl
        << endl;

    

    return 0;
}
