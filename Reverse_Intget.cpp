//#include<iostream>
//using namespace std;
//
//class Solution
//{
//public:
//    //��x����
//	int reverse(int x)
//	{
//        long n = 0;
//        while (x != 0) {
//            n = n * 10 + x % 10;//n�͵���n*10����֮ǰ��n���С�10����һ�������x������0��ǰ���¾ͻ�һֱ��n*10
//            x = x / 10;
//        }
//        //��һ���ж�Ҳ��ţ�Ƶ�һ��������long�͵����ݽ���ǿת֮���������ԭ����ֵ����ô����˵��û����������������ԭ����n��
//        return (int)n == n ? (int)n : 0;
//     
//	}
//};