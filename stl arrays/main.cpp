#include <iostream>
#include <vector>
using namespace std;

int SumOfDigits(const vector<int>& arr) 
{
    int sum = 0;
    for (int num : arr) 
    {
        while (num) 
        {
            sum += num % 10;
            num /= 10;
        }
    }
    return sum;
}

double AverageOfPositives(const vector<int>& arr) 
{
    double sum = 0, count = 0;
    for (int num : arr) 
    {
        if (num > 0) 
        {
            sum += num;
            count++;
        }
    }
    if (count) return sum / count;
    else
        return 0;
}

void MaxNegative(const vector<int>& arr) 
{
    int max_neg = INT_MIN;
    int index = -1;
    for (size_t i = 0; i < arr.size(); i++) 
    {
        if (arr[i] < 0 && arr[i] > max_neg) 
        {
            max_neg = arr[i];
            index = i;
        }
    }
    if (index != -1) cout << "Max negative: " << max_neg << " at position " << index << endl;
    else
        cout << "No negative elements" << endl;
}

int MostOftenFound(const vector<int>& arr) 
{
    int maxCount = 0;   
    int most_often = arr[0]; 

    for (size_t i = 0; i < arr.size(); i++) 
    {
        int count = 0;
        
        for (size_t j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j]) 
            {
                count++;
            }
        }
        
        if (count > maxCount) 
        {
            maxCount = count;
            most_often = arr[i];
        }
    }
    return most_often;
}

int MaxOddIndexNumberDivisibleByThree(const vector<int>& arr) 
{
    int max = INT_MIN;
    for (size_t i = 1; i < arr.size(); i += 2) 
    {
        if (arr[i] % 3 == 0 && arr[i] > max)  max = arr[i];
    }
    if (max != INT_MIN) return max;
    else {  return 0; }
}

void SwapMaxEvenMinOdd(vector<int>& arr) 
{
    int max_even = INT_MIN, min_odd = INT_MAX;
    int max_even_index = -1, min_odd_index = -1;

    for (size_t i = 0; i < arr.size(); i++) 
    {
        if (arr[i] % 2 == 0 && arr[i] > max_even) 
        {
            max_even = arr[i];
            max_even_index = i;
        }
        if (arr[i] % 2 != 0 && arr[i] < min_odd) 
        {
            min_odd = arr[i];
            min_odd_index = i;
        }
    }

    if (max_even_index != -1 && min_odd_index != -1)  swap(arr[max_even_index], arr[min_odd_index]);
    else
    {
        fill(arr.begin(), arr.end(), 0);
    }
}

void ThirdArray(const vector<int>& arr1, const vector<int>& arr2) 
{
    vector<int> common, unique;

    for (int num1 : arr1) 
    {
        bool isCommon = false;
        for (int num2 : arr2) 
        {
            if (num1 == num2) 
            {
                isCommon = true;
                break;
            }
        }
        if (isCommon) 
        {
            bool alreadyAdded = false;
            for (int c : common) 
            {
                if (c == num1) 
                {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded) 
            {
                common.push_back(num1);
            }
        }
        else 
        {
            bool alreadyAdded = false;
            for (int u : unique) 
            {
                if (u == num1) 
                {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded) 
            {
                unique.push_back(num1);
            }
        }
    }


    for (int num2 : arr2) 
    {
        bool isUnique = true;
        for (int num1 : arr1) 
        {
            if (num2 == num1) 
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique) 
        {
            bool alreadyAdded = false;
            for (int u : unique) 
            {
                if (u == num2) 
                {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded) 
            {
                unique.push_back(num2);
            }
        }
    }

    cout << "Common elements: ";
    for (int num : common) 
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Unique elements: ";
    for (int num : unique) 
    {
        cout << num << " ";
    }
    cout << endl;
}



int main() 
{
    vector<int> arr = { 12, 104, 81 };
    cout << "Sum of digits: " << SumOfDigits(arr) << endl;

    vector<int> arr2 = { 11, -7, 7, -1, 9, 0, 11, 9, 3 };
    cout << "Average of positives: " << AverageOfPositives(arr2) << endl;
    MaxNegative(arr2);
    cout << "Number occurs most often: " << MostOftenFound(arr2) << endl;
    cout << "Max element on odd indices divisible by 3: " << MaxOddIndexNumberDivisibleByThree(arr2) << endl;

    SwapMaxEvenMinOdd(arr);
    for (int num : arr) cout << num << " ";
    cout << endl;

    vector<int> arr3 = { 81, 12, 5 };
    ThirdArray(arr, arr3);
    return 0;
}