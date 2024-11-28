#include <iostream>
#include <vector>

// 提前声明
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void print_vec(vector<int> &a)
{
    for (auto val : a)
    {
        cout << val << " ";
    }
    cout << endl;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> nums3 = nums1;
    nums1.resize(m + n);
    // print_vec(nums1);
    // print_vec(nums2);
    // print_vec(nums3);

    int i{}, j{};
    while (i < m && j < n)
    {
        if (nums3[i] < nums2[j])
        {
            nums1[i + j] = nums3[i];
            i++;
        }
        else
        {
            nums1[i + j] = nums2[j];
            j++;
        }
    }
    while (i < m)
    {
        nums1[i + j] = nums3[i];
        i++;
    }
    while (j < n)
    {
        nums1[i + j] = nums2[j];
        j++;
    }
}

int main()
{
    vector<int> a = {1, 1, 2, 3, 4, 4, 5};
    vector<int> b = {2, 2, 2, 2};
    int m = a.size();
    int n = b.size();
    merge(a, m, b, n);
    print_vec(a);
}
// 