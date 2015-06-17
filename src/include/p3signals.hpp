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

#ifndef P3WE_GUARD_P3SIGNALS_HPP
#define P3WE_GUARD_P3SIGNALS_HPP

#include <functional>
#include <tuple>
#include <vector>

namespace p3
{
	/* forward declarations */
	template<typename ...Args> class Slot;
	template<typename ...Args> class Signal;

	template<typename ...Args>
	class Slot
	{
	public:
		friend class Signal<Args...>;

	public:
		typedef std::function<void(Args...)> SlotFunc;

	public:
		Slot(const SlotFunc& func)
		: m_func(func)
		{
			// pass
		}

		Slot(Slot&&) = default;

		Slot(const Slot&) = delete;

		Slot& operator=(const Slot&) = delete;

		~Slot() = default;

	private:
		SlotFunc m_func;
	};

	template<typename ...Args>
	class Signal
	{
	public:
		Signal() = default;

		Signal(Signal&&) = default;

		Signal(const Signal&) = delete;

		Signal& operator= (const Signal&) = delete;

		~Signal() = default;

	public:
		void fire(Args ...args)
		{
			for (auto itr = m_slots.begin(); itr != m_slots.end(); ++itr)
			{
				std::get<1>(*itr)->m_func(args...);
			}
		}

		Signal& connect(Slot<Args...> &slot)
		{
			m_slots.push_back(std::make_tuple(0, &slot));

			return *this;
		}

		Signal& disconnect(Slot<Args...> &slot)
		{
			return *this;
		}

	private:
		std::vector<std::tuple<size_t,Slot<Args...>*>> m_slots;
	};

}

#endif /* P3WE_GUARD_P3SIGNALS_HPP */
