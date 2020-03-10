#include "pch.h"
#include "CppUnitTest.h"
#include "../work1/intersec.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:

		TEST_METHOD(Test_cross_dot) {
			//���
			Vector p(2, 0);
			Vector q(2, 2);
			Assert::AreEqual(4.0, cross(p, q));
			Assert::AreEqual(-4.0, cross(q, p));
			Assert::AreEqual(4.0, dot(p, q));

			//�غ�
			p.setPoint(2, 2);
			q.setPoint(2, 2);
			Assert::AreEqual(0.0, cross(p, q));
			Assert::AreEqual(-0.0, cross(q, p));
			Assert::AreEqual(8.0, dot(p, q));

			//ֱ��
			p.setPoint(2, 0);
			q.setPoint(0, 2);
			Assert::AreEqual(4.0, cross(p, q));
			Assert::AreEqual(-4.0, cross(q, p));
			Assert::AreEqual(0.0, dot(p, q));

			//�۽�
			p.setPoint(2, 0);
			q.setPoint(-2, 2);
			Assert::AreEqual(4.0, cross(p, q));
			Assert::AreEqual(-4.0, cross(q, p));
			Assert::AreEqual(-4.0, dot(p, q));
		}
		TEST_METHOD(Test_getCross1)
		{
			//l1 �� l2����б��
			Line l1(0, 0, 1, 1);
			Line l2(0, 1, 1, 0);
			Point tmp(0, 0);
			Point res(0.5, 0.5);
			getCross(l1, l2, &tmp);
			Assert::IsTrue(res == tmp);
		}
		TEST_METHOD(Test_getCross2)
		{
			//l1��ֱ��l2����
			Line l1(0, 0, 0, 1);
			Line l2(0, 1, 1, 0);
			Point tmp(0, 0);
			Point res(0, 1);
			getCross(l1, l2, &tmp);
			Assert::IsTrue(res == tmp);
		}

		TEST_METHOD(Test_getCross3)
		{
			//l1ƽ����x�ᣬl2����
			Line l1(0, 0, 1, 0);
			Line l2(0, 1, 1, 0);
			Point tmp(0, 0);
			Point res(1, 0);
			getCross(l1, l2, &tmp);
			Assert::IsTrue(res == tmp);
		}
		TEST_METHOD(Test_getCross4)
		{
			//l1��ֱ��l2ƽ����x��
			Line l1(1, 0, 1, 9);
			Line l2(0, 1, 10, 1);
			Point tmp(0, 0);
			Point res(1, 1);
			getCross(l1, l2, &tmp);
			Assert::IsTrue(res == tmp);
		}
		
		TEST_METHOD(Test_CircleLineCross1) {
			//��Բ��
			Circle c(2, 2, 1);
			Line l(0, 0, 1, 1);
			Assert::AreEqual(true, getCircleLineCross(c, l));
		}

		TEST_METHOD(Test_CircleLineCross2) {
			//��������
			Circle c(2, 2, 2);
			Line l(1, 0, 0, -1);
			Assert::AreEqual(true, getCircleLineCross(c, l));
		}

		TEST_METHOD(Test_CircleLineCross3) {
			//����
			Circle c(5, 0, 3);
			Line l(0, 0, 4, 3);
			Assert::AreEqual(true, getCircleLineCross(c, l));
		}

		TEST_METHOD(Test_CircleLineCross4) {
			//���ཻ
			Circle c(2, 2, 1);
			Line l(5, 0 , 0, -5);
			Assert::AreEqual(false, getCircleLineCross(c, l));
		}

		TEST_METHOD(Test_getCircleCross1) {
			//�ཻ���⽻
			Point c1(1, 0);
			Point c2(3, 0);
			Assert::AreEqual(true, getCircleCross(c1, 1, c2, 2));
		}
		TEST_METHOD(Test_getCircleCross2) {
			//�ཻ���ڽ�
			Point c1(2, 0);
			Point c2(3, 0);
			Assert::AreEqual(true, getCircleCross(c1, 2, c2, 2));
		}
		TEST_METHOD(Test_getCircleCross3) {
			//���У�����
			Point c1(1, 0);
			Point c2(3, 0);
			Assert::AreEqual(true, getCircleCross(c1, 1, c2, 1));
		}
		TEST_METHOD(Test_getCircleCross4) {
			//���У�����
			Point c1(1, 0);
			Point c2(2, 0);
			Assert::AreEqual(true, getCircleCross(c1, 1, c2, 2));
		}
		TEST_METHOD(Test_getCircleCross5) {
			Point c1(1, 0);
			Point c2(8, 0);
			Assert::AreEqual(false, getCircleCross(c1, 1, c2, 2));
		}
		TEST_METHOD(Test_getCircleCross6) {
			Point c1(3, 0);
			Point c2(3, 0);
			Assert::AreEqual(false, getCircleCross(c1, 1, c2, 2));
		}
		TEST_METHOD(Test_getCircleCross7) {
			Point c1(1, 1);
			Point c2(1, 3);
			Assert::AreEqual(true, getCircleCross(c1, 1, c2, 2));
		}
		TEST_METHOD(Test_getCircleCross8) {
			Point c1(1, 1);
			Point c2(2, 2);
			Assert::AreEqual(true, getCircleCross(c1, 2, c2, 2));
		}
	};
}
