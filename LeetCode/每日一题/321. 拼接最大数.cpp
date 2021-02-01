/*

题目分析
①．该题的本质即为从两个数组中挑选 k 个元素，并且使拼接后的结果的字典序最大。
②．要使数组的字典序最大，则需要保证从左到右的每一个位置的值尽可能的大，即单调递减。
③．枚举所有 k 的组合情况，分别从两个数组中取 i、j 个元素构成的最大数组，然后再进行合并，最终保留最大值。
④．在挑选指定个数的元素的过程中，若当前供挑选的元素数量大于需要的个数，则进行取舍操作，以使每一个位置的值尽可能的大。
⑤．合并过程中，分别从头到尾遍历两个数组并比较当前元素优先取较大值作为合并结果；若当前位置值相等，则需要进行进行下一位的比较，以确保下一位可选的元素值最大。

字典序比较算法
①．序列的字典序比较：从第一位开始分别比较对应的元素值，若分出大小则返回结果，否则继续进行下一位的大小。
②．vector 的默认比较操作即为字典序比较。
③．STL 中的 lexicographical_compare() 算法可以按字典序比较由开始和结束迭代器定义的两个序列。

单调栈
①．单调栈：就是栈内元素单调按照递增(递减)顺序排列的栈。
②．单调栈的实现：可以使用 vector 来实现栈操作，vector 可以在末尾快速的添加和删除元素，并且方便栈内元素的读取。

*/

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        int len1 = nums1.size();
        int len2 = nums2.size();
        for (int i = 0; i <= len1; i++) {  // i++, j--
            int j = k - i;
            if (j > k || j > len2) continue;
            if (i > k) break;

            vector<int> vec1 = getMax(nums1, i);
            vector<int> vec2 = getMax(nums2, j);
            ret = max(ret, merge2vec(vec1, vec2));
        }
        return ret;
    }

    // 从数组中取 k 位数字，并保持相对顺序，使其构成的数字最大
    vector<int> getMax(vector<int>& nums, int k) {
        vector<int> res;
        int size = nums.size();
        int remain = size - k;  // 允许舍弃的元素个数
        for (auto &num : nums) {
            // 如果当前元素值比末尾位置的值大，则舍弃末尾元素
            while (res.size() > 0 && remain > 0 && num > res.back()) {
                res.pop_back();
                remain--;
            }
            if (res.size() < k) {
                res.push_back(num);
            }
            else {  // 已经取够了k个，直接丢弃
                remain--;
            }
        }
        return res;
    }

    // 合并两个递减数组，使结果保持递减，并且构成的序列字典序最大
    vector<int> merge2vec(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if( !lexicographical_compare(nums1.begin()+i ,nums1.end(), nums2.begin()+j, nums2.end()) ) {
                res.push_back(nums1[i]);
                i++;
            }
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        //拷贝剩余元素到结果数组
        copy(nums1.begin()+i, nums1.end(), back_inserter(res));
        copy(nums2.begin()+j, nums2.end(), back_inserter(res));
        return res;
    }
};