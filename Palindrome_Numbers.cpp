//#include<iostream>
//using namespace std;
////��ĿҪ��
////
//
//
////������������˼·��1�������������֮���ǲ���ԭ���������Ϻã�˼·��ࣩ����ķ���һ����Ҫ�ж��Ƿ�����������
////                  2��������������һ�����򿴿�����һ���x������֮��������Ƿ���ȣ��ã��ֲ��˷���һ��ȱ�ݣ�����Ҫ�жϷ�ת��������Ƿ������
////                  3�������������ֿ������жϴӺ���ǰ�ǲ���ÿһ����Ӧ�����ֶ����
//
////����һ
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
////������
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
////����3
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