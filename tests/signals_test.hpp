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

#include <p3signals.hpp>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class SignalsTest : public CppUnit::TestFixture
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

	void testSimple()
	{
		class TestType
		{
		public:
			TestType() : counter(0) {}

		public:
			void testMethod(bool value)
			{
				CPPUNIT_ASSERT(value);
				counter++;
			}

		public:
			int counter;
		};

		TestType obj;
		p3::Signal<bool> signal;
		p3::Slot<bool> slot = p3::make_slot(&TestType::testMethod, &obj);

		signal.connect(slot);
		signal.fire(true);

		CPPUNIT_ASSERT_EQUAL(true, slot.isConnected());
		CPPUNIT_ASSERT_EQUAL(1, obj.counter);

		signal.fire(true);

		CPPUNIT_ASSERT_EQUAL(true, slot.isConnected());
		CPPUNIT_ASSERT_EQUAL(2, obj.counter);

		signal.disconnect(slot);
		signal.fire(true);

		CPPUNIT_ASSERT_EQUAL(false, slot.isConnected());
		CPPUNIT_ASSERT_EQUAL(2, obj.counter);
	}

	void testLifetime1()
	{
		class TestType
		{
		public:
			TestType() : counter(0) {}

		public:
			void testMethod(bool value)
			{
				CPPUNIT_ASSERT(value);
				counter++;
			}

		public:
			int counter;
		};

		TestType obj;

		p3::Signal<bool> signal;

		{
			p3::Slot<bool> slot = p3::make_slot(&TestType::testMethod, &obj);

			signal.connect(slot);
			signal.fire(true);

			CPPUNIT_ASSERT_EQUAL(size_t(1), signal.quantity());
			CPPUNIT_ASSERT_EQUAL(true, slot.isConnected());
			CPPUNIT_ASSERT_EQUAL(1, obj.counter);
		}

		CPPUNIT_ASSERT_EQUAL(size_t(0), signal.quantity());
	}

	void testLifetime2()
	{
		class TestType
		{
		public:
			TestType() : counter(0) {}

		public:
			void testMethod(bool value)
			{
				CPPUNIT_ASSERT(value);
				counter++;
			}

		public:
			int counter;
		};

		TestType obj;

		p3::Slot<bool> slot = p3::make_slot(&TestType::testMethod, &obj);

		CPPUNIT_ASSERT_EQUAL(false, slot.isConnected());

		{
			p3::Signal<bool> signal;

			signal.connect(slot);
			signal.fire(true);

			CPPUNIT_ASSERT_EQUAL(true, slot.isConnected());
			CPPUNIT_ASSERT_EQUAL(1, obj.counter);
		}

		CPPUNIT_ASSERT_EQUAL(false, slot.isConnected());
		CPPUNIT_ASSERT_EQUAL(1, obj.counter);
	}


public:
	CPPUNIT_TEST_SUITE(SignalsTest);
	CPPUNIT_TEST(testSimple);
	CPPUNIT_TEST(testLifetime1);
	CPPUNIT_TEST(testLifetime2);
	CPPUNIT_TEST_SUITE_END();
};
