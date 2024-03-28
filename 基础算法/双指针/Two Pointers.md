# Two Pointers

Two Pointers算法是一种常见的解决问题的技巧，它通常用于在数组或链表中查找满足某种条件的一对元素或一段连续的元素。这种算法的核心思想是使用两个指针，在数据结构上进行迭代或移动，以在O(n)时间复杂度内解决问题，而不是传统的暴力搜索方法，其时间复杂度通常为O(n^2)。

## 常见算法

Two Pointers算法的常见应用包括：

1. **求解两数之和**：在给定的整数数组中找到两个数，使它们的和等于一个给定的目标值。
2. **求解三数之和**：在给定的整数数组中找到三个数，使它们的和等于零。
3. **求解最接近的三数之和**：在给定的整数数组中找到三个数，使它们的和尽可能接近给定的目标值。
4. **反转数组或字符串**：使用两个指针，一个从头开始，另一个从尾部开始，交换它们指向的元素，直到它们相遇。
5. **合并两个有序数组**：使用两个指针分别指向两个数组的末尾，从后往前合并两个数组的元素。

## 代码示例

### 两数之和

下面是一个示例问题：给定一个有序数组，找到两个数，使它们的和等于给定的目标值。如果存在这样的两个数，返回它们的索引，否则返回一个空数组。

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            result.push_back(left);
            result.push_back(right);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    if (result.size() == 2) {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No such indices found." << endl;
    }

    return 0;
}
```

在上面的代码中，`twoSum`函数接受一个有序数组和一个目标值作为参数，并使用两个指针`left`和`right`分别指向数组的开头和结尾。然后，它在`while`循环中逐步向数组的中间部分逼近，直到找到满足条件的两个数或指针相遇为止。

### 合并序列

以下是一个使用Two Pointers算法来合并两个有序数组的示例代码：

```cpp
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;

    while (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }

    // If there are remaining elements in nums2
    while (p2 >= 0) {
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

在这个例子中，`merge`函数接受两个有序数组`nums1`和`nums2`，以及它们各自的有效长度`m`和`n`。它使用两个指针`p1`和`p2`分别指向`nums1`和`nums2`的末尾，并使用指针`p`指向合并后数组的末尾。然后，它从后往前遍历`nums1`和`nums2`，比较当前元素的大小，并将较大的元素放入合并后数组的末尾，直到其中一个数组遍历完毕。最后，如果`nums2`中仍有剩余元素，将它们拷贝到合并后数组的前面。