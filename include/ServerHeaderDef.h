#ifndef __Boids_Server_Header_def_h_
#define __Boids_Server_Header_def_h_

//����˰�ͷ����

#include <cstdint>

#define SERVER_MSG_LENGTH(d) (*(uint32_t*)(d))
#define SERVER_MSG_TYPE(d) (*(uint32_t*)((d) + 4))
#define SERVER_MSG_AFTER_TYPE_POS (8)
#define SERVER_MSG_ERROR(d) (*(uint8_t*)((d) + SERVER_MSG_AFTER_TYPE_POS)) //��˷����ǰ�˷��񷵻صĴ�������д�����ôĬ�Ϻ����Protobuf��û���ˣ���������Լ��
#define SERVER_MSG_HEADER_EX_LEN(d) (*(uint8_t*)((d) + SERVER_MSG_AFTER_TYPE_POS + 1))
#define SERVER_MSG_RESERVED(d) (*(uint16_t*)((d) + SERVER_MSG_AFTER_TYPE_POS + 2))
#define SERVER_MSG_HEADER_BASE_SIZE (SERVER_MSG_AFTER_TYPE_POS + 4)
#define SERVER_MSG_AFTER_HEADER_BASE(d) ((d) + SERVER_MSG_HEADER_BASE_SIZE)
#define SERVER_MSG_DATA(d) ((d) + SERVER_MSG_HEADER_BASE_SIZE + SERVER_MSG_HEADER_EX_LEN(d))
#define SERVER_MSG_DATA_LEN(d) (SERVER_MSG_LENGTH(d) - SERVER_MSG_HEADER_BASE_SIZE - SERVER_MSG_HEADER_EX_LEN(d))

#endif