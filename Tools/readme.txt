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

TODO �޸�dump·����binĿ¼��
TODO ���mysql ������ ��sql �����protobuff ��ת
TODO protobuff �༭�ͻ��˳���
TODO ģ����ҵ�¼��Ϸ
TODO �߻���ֵ��ʽת�����ߣ����ʽ��ʽ��
TODO AI 
TODO ��ͼ���� recast navgition


linux������coredump�ļ��Ŀ��غ�·��
ulimit -c unlimited ����������core�ļ���С
ulimit -c 0 �ر�core�ļ����ɿ���
ulimit -c 1024 �޶�����core�ļ��Ĵ�СΪ1024

2.core�ļ�����������
/proc/sys/kernel/core_uses_pid 1 ��ʾʹ��procid������0��ʾ��ʹ��
/proc/sys/kernel/core_pattern �������ø�ʽ���� core �ļ�����λ�û��ļ���
echo ��/opt/corefile/core-%e-%p-%t�� > /proc/sys/kernel/core_pattern
��������������� core �ļ����ŵ� /corefile Ŀ¼�£��������ļ���Ϊ core- ������ -pid- ʱ���
�����ǲ����б� :
%p - insert pid into filename ��� pid
%u - insert current uid into filename ��ӵ�ǰ uid
%g - insert current gid into filename ��ӵ�ǰ gid
%s - insert signal that caused the coredump into the filename ��ӵ��²��� core ���ź�
%t - insert UNIX time that the coredump occurred into filename ��� core �ļ�����ʱ�� unix ʱ��
%h - insert hostname where the coredump happened into filename ���������
%e - insert coredumping executable name into filename ���������









