/*
 * (C) Copyright 2015 Artur Sobierak <asobierak@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <p3delegate.hpp>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class MakeDelegateTest : public CppUnit::TestFixture
{
public:
	void setUp()
	{
		// pass
	}

	void tearDown()
	{
		// pass
	}

	void test0()
	{
		class TestType
		{
		public:
			TestType() : executed(false) {}

		public:
			void testMethod()
			{
				executed = true;
			}

		public:
			bool executed;
		};

		TestType obj;
		auto delegate = p3::make_delegate(&TestType::testMethod, &obj);
		if (delegate)
		{
			delegate();
		}

		CPPUNIT_ASSERT_EQUAL(true, obj.executed);
	}

	void test1()
	{
		class TestType
		{
		public:
			TestType() : executed(false) {}

		public:
			void testMethod(bool arg1)
			{
				CPPUNIT_ASSERT(arg1);
				executed = true;
			}

		public:
			bool executed;
		};

		TestType obj;
		auto delegate = p3::make_delegate(&TestType::testMethod, &obj);
		if (delegate)
		{
			delegate(true);
		}

		CPPUNIT_ASSERT_EQUAL(true, obj.executed);
	}

	void test2()
	{
		class TestType
		{
		public:
			TestType() : executed(false) {}

		public:
			void testMethod(bool arg1, bool arg2)
			{
				CPPUNIT_ASSERT(arg1 && arg2);
				executed = true;
			}

		public:
			bool executed;
		};

		TestType obj;
		auto delegate = p3::make_delegate(&TestType::testMethod, &obj);
		if (delegate)
		{
			delegate(true, true);
		}

		CPPUNIT_ASSERT_EQUAL(true, obj.executed);
	}

	void test3()
	{
		class TestType
		{
		public:
			TestType() : executed(false) {}

		public:
			void testMethod(bool arg1, bool arg2, bool arg3)
			{
				CPPUNIT_ASSERT(arg1 && arg2 && arg3);
				executed = true;
			}

		public:
			bool executed;
		};

		TestType obj;
		auto delegate = p3::make_delegate(&TestType::testMethod, &obj);
		if (delegate)
		{
			delegate(true, true, true);
		}

		CPPUNIT_ASSERT_EQUAL(true, obj.executed);
	}

	void test4()
	{
		class TestType
		{
		public:
			TestType() : executed(false) {}

		public:
			void testMethod(bool arg1, bool arg2, bool arg3, bool arg4)
			{
				CPPUNIT_ASSERT(arg1 && arg2 && arg3 && arg4);
				executed = true;
			}

		public:
			bool executed;
		};

		TestType obj;
		auto delegate = p3::make_delegate(&TestType::testMethod, &obj);
		if (delegate)
		{
			delegate(true, true, true, true);
		}

		CPPUNIT_ASSERT_EQUAL(true, obj.executed);
	}

	void test5()
	{
		class TestType
		{
		public:
			TestType() : executed(false) {}

		public:
			void testMethod(bool arg1, bool arg2, bool arg3, bool arg4, bool arg5)
			{
				CPPUNIT_ASSERT(arg1 && arg2 && arg3 && arg4 && arg5);
				executed = true;
			}

		public:
			bool executed;
		};

		TestType obj;
		auto delegate = p3::make_delegate(&TestType::testMethod, &obj);
		if (delegate)
		{
			delegate(true, true, true, true, true);
		}

		CPPUNIT_ASSERT_EQUAL(true, obj.executed);
	}

public:
	CPPUNIT_TEST_SUITE(MakeDelegateTest);
	CPPUNIT_TEST(test0);
	CPPUNIT_TEST(test1);
	CPPUNIT_TEST(test2);
	CPPUNIT_TEST(test3);
	CPPUNIT_TEST(test4);
	CPPUNIT_TEST(test5);
	CPPUNIT_TEST_SUITE_END();
};
