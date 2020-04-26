#include "pch.h"
#include<cassert>
#include "CppUnitTest.h"
#include"../Task1/Indexer.h"
#include"../Task1/Indexer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NeuralNetworkTest
{
	TEST_CLASS(NeuralNetworkTest)
	{
	private:
		double* arr = new double[4]{ 1, 2, 3, 4 };
	public:
		TEST_METHOD(HaveCorrectLength)
		{
			Indexer indexer = Indexer(arr, 4, 1, 2);
			Assert::AreEqual(2, indexer.get_sub_length());
		}
		TEST_METHOD(GetCorrectly)
		{
			Indexer indexer(arr, 4, 1, 2);
			Assert::AreEqual(2.0, indexer[0]);
			Assert::AreEqual(3.0, indexer[1]);
		}
		TEST_METHOD(SetCorrectly)
		{
			Indexer indexer(arr, 4, 1, 2);
			indexer[0] = 10;
			Assert::AreEqual(10.0, arr[1]);
		}
		TEST_METHOD(IndexerDoesNotCopyArray)
		{
			Indexer indexer1(arr, 4, 1, 2);
			Indexer indexer2(arr, 4, 0, 2);
			indexer1[0] = 100500;
			Assert::AreEqual(100500.0, indexer2[1]);
		}
		TEST_METHOD(FailWithWrongArguments1)
		{
			auto func = []() {
				double* arr = new double[4]{ 1, 2, 3, 4 };
				Indexer tmp(arr, 4, -1, 3);
			};
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongArguments2)
		{
			auto func = []() {
				double* arr = new double[4]{ 1, 2, 3, 4 };
				Indexer tmp(arr, 4, 1, -1);
			};
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongArguments3)
		{
			auto func = []() {
				double* arr = new double[4]{ 1, 2, 3, 4 };
				Indexer tmp(arr, 4, 1, 10);
			};
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(FailWithWrongIndexing1)
		{
			auto func = []() {
				double* arr = new double[4]{ 1, 2, 3, 4 };
				Indexer indexer(arr, 4, 1, 2);
				double tmp = indexer[-1];
			};
			Assert::ExpectException<std::out_of_range>(func);
		}
		TEST_METHOD(FailWithWrongIndexing2)
		{
			auto func = []() {
				double* arr = new double[4]{ 1, 2, 3, 4 };
				Indexer indexer(arr, 4, 1, 2);
				double tmp = indexer[10];
			};
			Assert::ExpectException<std::out_of_range>(func);
		}
	};
}
