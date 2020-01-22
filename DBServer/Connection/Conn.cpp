#include "Conn.h"
#include "mariacpp/exception.hpp"
#include "mariacpp/prepared_stmt.hpp"
#include "mariacpp/time.hpp"
#include "mariacpp/uri.hpp"
#include "JsonConfig.h"
#include "LogUtil.h"

Conn::Conn()
{
}

Conn::~Conn()
{
}

void Conn::Init()
{
	// �������õĲ�ѯsql ����ȫҲ�������
	m_login_check = std::make_shared<MariaCpp::PreparedStatement>();
	m_login_check->prepare("select * from tb_account where loginname=? and loginpwd=?");
}

bool Conn::ConnectToDB()
{
	const char* uri = g_JsonConfig->m_dbConf["uri"].asCString();
	const char* user = g_JsonConfig->m_dbConf["root"].asCString();
	const char* passwd = g_JsonConfig->m_dbConf["passwd"].asCString();
	try
	{
		m_conn.connect(MariaCpp::Uri(uri), user, passwd);
	}
	catch (const std::exception & e)
	{
		CLOG_ERR << "connect mariadb error," << e.what() << CLOG_END;
		return false;
	}
	return true;
}

bool Conn::IsConnOk()
{
	if (m_conn.MyPing() != 0)
	{
		return false;
	}
	return true;
}

void Conn::DisConnect()
{
	m_conn.close();
}

void Conn::Query(const std::string& sql)
{
	m_conn.query(sql);
	m_result = std::make_shared<MariaCpp::ResultSet>(m_conn.store_result());
	// next() is an alias for fetch_row()
	MariaCpp::ResultSet* res_set = m_result.get();
	while (res_set && res_set->next()) {
		std::cout << "id = " << res->getInt(0)
			<< ", label = '" << res->getRaw(1) << "'"
			<< ", date = "
			<< (res->isNull(2) ? "NULL" : res->getString(2).c_str())
			<< std::endl;
	}
	m_result.reset();
}