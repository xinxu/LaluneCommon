#ifndef __COMMON_HEADER_H_
#define __COMMON_HEADER_H_

//�ͻ��˰�ͷ����

#define MSG_LENGTH(d) (*(uint32_t*)(d))
#define MSG_TYPE(d) (*(uint32_t*)((d) + 4))
#define MSG_OPERATION_ID(d) (*(uint32_t*)((d) + 8))
#define MSG_ERROR(d) (*(uint8_t*)((d) + 12)) //��˷����ǰ�˷��񷵻صĴ�������д�����ôĬ�Ϻ����Protobuf��û���ˣ���������Լ��
#define MSG_ENCRYPTION_TYPE(d) (*(uint8_t*)((d) + 13))
#define MSG_RESERVED(d) (*(uint16_t*)((d) + 14))
#define MSG_HEADER_BASE_SIZE (16)
#define MSG_DATA(d) (*(uint16_t*)((d) + MSG_HEADER_BASE_SIZE))

//Լ����ż���Ķ��Ƿ����������İ��������Ķ��Ƿ���������ȥ��

//��Ϣ���ͣ����ط������
#define MSG_TYPE_CONNECT_OTHER (99) //���ؾ��⣺���߿ͻ�������ķ���
#define MSG_TYPE_LOGIN (100) //��½���������������Ҫ����
#define MSG_TYPE_LOGIN_RESULT (101)
#define MSG_TYPE_LOGIN_QUEUE (102)

//��Ϣ���ͣ��汾�������
#define MSG_CHECK_VERSION (10000)
#define MSG_CHECK_VERSION_RESULT (10001)

//��Ϣ���ͣ���½�����û��˺ŷ������
#define MSG_TYPE_REGISTER (20000)
#define MSG_TYPE_REGISTER_RESULT (20001)


//��Ϣ���ͣ����Ʒ�����أ���Щ��ʵֻ�ںͿ��Ʒ���������﷢��
#define MSG_TYPE_CONTROL_SERVER_SAY_HELLO (500000) //Ҳ�����и�HELLO_RESULT����Ҫ��ʱ���ټӺ��ˡ�
#define MSG_TYPE_CONTROL_SERVER_ADDR_INFO_REFRESH (500011) //�����Ⱥ���ˢ�£����������ǵ����
#define MSG_TYPE_CONTROL_SERVER_ADDR_INFO_ADD (500013)
#define MSG_TYPE_CONTROL_SERVER_ADDR_INFO_REMOVE (500015)
#define MSG_TYPE_CONTROL_SERVER_ADDR_INFO_RESTART (500017)
#define MSG_TYPE_CONTROL_SERVER_REPORT_LOAD (500020)
#define MSG_TYPE_CONTROL_SERVER_CMD (500050)
#define MSG_TYPE_CONTROL_SERVER_CMD_RESULT (500051)

//���������ͣ�ÿ������������Ϣ�ķֶξ���[ID * 10000, (ID+1) * 10000)��������Ϣ����תServerType�ͳ���10000
#define SERVER_TYPE_GATEWAY_SERVER (0)
#define SERVER_TYPE_VERSION_SERVER (1)
#define SERVER_TYPE_LOGIN_SERVER (2)
#define SERVER_TYPE_BASIC_INFO_SERVER (3)
#define SERVER_TYPE_LEAGUE_SERVER (4)
#define SERVER_TYPE_NOTICE_SERVER (5)
#define SERVER_TYPE_RANK_SERVER (6)
#define SERVER_TYPE_ASYNC_BATTLE_SERVER (7)
#define SERVER_TYPE_REPLAY_SERVER (8)
#define SERVER_TYPE_STAT_SERVER (9)
#define SERVER_TYPE_AUTO_MATCH_SERVER (10)
#define SERVER_TYPE_SYNC_BATTLE_SERVER (11)

#define SERVER_TYPE_CONTROL_SERVER (50)

#endif