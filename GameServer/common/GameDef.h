#pragma once


// ���������о�
enum EObjType
{
	E_OBJ_INVALID = 0,
	E_OBJ_PLAYER = 1,  // �������
	E_OBJ_PET = 2,
	E_OBJ_MONSTER = 3,
	E_OBJ_MAX
};

// ����ģ������ö��
enum EModuleType
{
	E_MODULE_VOID = 0,
	E_MODULE_PET = 1,
	E_MODULE_RANK = 2,
	E_MODULE_BUFF = 3,
};