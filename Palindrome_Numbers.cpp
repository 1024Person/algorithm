//#include<iostream>
//using namespace std;
////题目要求：
////
//
//
////回文数的两种思路：1、这个整数逆序之后还是不是原来的数（较好，思路简洁）这里的方法一还需要判断是否有溢出的情况
////                  2、将整个整数的一般逆序看看丢了一般的x个逆序之后的数字是否相等（好，弥补了方法一的缺陷，不需要判断反转后的数字是否溢出）
////                  3、将这个整数拆分开来，判断从后向前是不是每一个对应的数字都相等
//
////方法一
//class Solution1
//{
//public:
//    bool isPalindrome(int x)
//    {
//        if (x < 0)
//            return false;
//        else if (x != 0 && 0 == x % 10)
//            return false;
//        int t = x;
//        int reverse = 0;
//        while (x != 0)
//        {
//            reverse = reverse * 10 + x % 10;
//            x /= 10;
//        }
//        return reverse == t;       
//    }
//};
//
////方法二
//class Solution2
//{
//public:
//    bool isPalindrome(int x)
//    {
//        if (x < 0)
//            return false;
//        else if (x > 0 && 0 == x % 10)
//            return false;
//        int reveredNumber = 0;
//        while (x > reveredNumber)
//        {
//            reveredNumber = reveredNumber * 10 + x % 10;
//            x /= 10;
//        }
//        return reveredNumber == x || reveredNumber / 10 == x;
//    }
//};
//
//
////方法3
//class Solution3 {
//public:
//    bool isPalindrome(int x) {
//        if (x < 0||x%10==0)
//            return false;
//        if (x / 10 == 0)return true;
//        int y = x;
//        int t = 0;
//        while (y != 0)
//        {
//            y /= 10;
//            t++;
//        }
//        int* z = (int*)malloc(sizeof(int) * t);
//        int i = 0;
//        while (x != 0)
//        {
//            z[i] = x % 10;
//            x /= 10;
//            i++;
//        }
//        int l = 0;
//        t = t - 1;
//        while (l < t)
//        {
//            if (z[l] != z[t])
//                return false;
//            l++;
//            t--;
//        }
//
//        return true;
//    }
//};
//int main()
//{
//    Solution2 c;
//    cout << c.isPalindrome(10) << endl;
//    system("pause");
//    return 0;
//}