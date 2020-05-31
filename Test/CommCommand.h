#pragma once

#include <functional>
#include <type_traits>

// ʵ��һ��ͨ�ú�����װ��
template <typename R = void>
class FuncWraper
{
public:
	// ���պ�������İ�װ��
	template<class F, class... Args, class = typename std::enable_if<!std::is_member_function_pointer<F>::value>::type>
	void Wrap(F&& f, Args&&...args)
	{
		m_f = [&] { return f(args...); };
	}
	// ���ܳ�����Ա������װ��
	template<class R, class C, class...DArgs, class P, class...Args>
	void Wrap(R(C::*f)(DArgs...) const, P&& p, Args&&... args)
	{
		m_f = [&, f] { return (*p.*f)(args...); };
	}
	// ���ܷǳ�����Ա������װ��
	template<class R, class C, class...DArgs, class P, class...Args>
	void Wrap(R(C::*f)(DArgs...), P&& p, Args&&... args)
	{
		m_f = [&, f] { return (*p.*f)(args...); };
	}

	R Excute()
	{
		return m_f();
	}
private:
	std::function<R()> m_f;
};

