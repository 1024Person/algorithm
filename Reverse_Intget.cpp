//#include<iostream>
//using namespace std;
//
//class Solution
//{
//public:
//    //将x逆序
//	int reverse(int x)
//	{
//        long n = 0;
//        while (x != 0) {
//            n = n * 10 + x % 10;//n就等于n*10，将之前的n进行×10，这一步妙啊，在x不等于0的前提下就会一直将n*10
//            x = x / 10;
//        }
//        //这一步判断也是牛逼的一批，，将long型的数据进行强转之后如果还是原来的值，那么，就说明没有溢出，如果不再是原来的n了
//        return (int)n == n ? (int)n : 0;
//     
//	}
//};