������Ŀ��Ҫ�Ľű����ߵ�
�ϴ���װ ����
yum -y install lrzsz
����Ŀ��centos8 ����
��ѹ lz4 �ļ�
yum install -y lz4 lz4-devel

coredump Ĭ���ļ�·��
/var/lib/systemd/coredump  


���� �ļ�����������
vim /etc/security/limits.conf
��������
* soft nofile 8192
* hard nofile 8192
ulimit -a �鿴��Ϣ

TODO log ��־�ļ���̫����
TODO �޸�dump·����binĿ¼��








