#include "SFTest.h"
////////////////////////////////////////////////////////////////////////////
//��ȡ��������
template <size_t arg, size_t... rest>
struct IntegerMax;

template <size_t arg>
struct IntegerMax<arg> : std::integral_constant<size_t, arg>
{
};

template <size_t arg1, size_t arg2, size_t... rest>
struct IntegerMax<arg1, arg2, rest...> : std::integral_constant<size_t, arg1 >= arg2 ? IntegerMax<arg1, rest...>::value :
	IntegerMax<arg2, rest...>::value >
{
};
/////////////////////////////////////////////////////////////////////////////

//������������
template<int...>
struct IndexSeq {};

//������������
template<int N, int... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...> {};

template<int... indexes>
struct MakeIndexes<0, indexes...> {
	//typedef IndexSeq<indexes...> type;
	using type = typename IndexSeq<indexes...>;
};

template<typename T>
void print(T t)
{
	cout << t << endl;
}

template<typename T, typename... Args>
void print(T t, Args... args)
{
	print(t);
	print(args...);
}
template<int... Indexes, typename... Args>
void print_helper(IndexSeq<Indexes...>, std::tuple<Args...>&& tup) {
	//�ٽ�tupleת��Ϊ�ɱ�ģ���������������ԭ�������ٵ���print
	print(std::get<Indexes>(tup)...);
}

template<typename... Args>
void printargs(Args... args) {
	//�Ƚ��ɱ�ģ��������浽tuple��
	print_helper(typename MakeIndexes<sizeof... (Args)>::type(), std::make_tuple(args...));
}

//////////////////////////////////////////////////////////////////////////////////
template<int index, typename... Types>
struct At {};

template<int index, typename First, typename... Types>
struct At<index, First, Types...>
{
	using type = typename At<index - 1, Types...>::type;
};

template<typename T, typename... Types>
struct At<0, T, Types...>
{
	using type = T;
};

void SFTest::TestTrait()
{
	cout << IntegerMax<2, 5, 1, 7, 3>::value << endl;
	printargs(1, 2.5, "test");

	using T = At<0, int, double, char>::type;
	cout << typeid(T).name() << endl;
}