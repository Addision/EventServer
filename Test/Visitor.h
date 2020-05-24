#pragma once

template<typename... Types>
class Visitor;

template<typename T, typename... Types>
class Visitor<T, Types...> : Visitor<Types...>
{
public:
	using Visitor<Types...>::Visit; // �������ػ����ͬ������
	virtual void Visit(const T&) = 0;
};

template<typename T>
class Visitor<T>
{
public:
	virtual void Visit(const T&) = 0;
};