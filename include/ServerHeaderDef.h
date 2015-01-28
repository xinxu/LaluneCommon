#ifndef __Boids_Server_Header_def_h_
#define __Boids_Server_Header_def_h_

//服务端包头定义

#include <cstdint>

#define SERVER_MSG_LENGTH(d) (*(uint32_t*)(d))
#define SERVER_MSG_TYPE(d) (*(uint32_t*)((d) + 4))
#define SERVER_MSG_AFTER_TYPE_POS (8)
#define SERVER_MSG_ERROR(d) (*(uint8_t*)((d) + SERVER_MSG_AFTER_TYPE_POS)) //后端服务给前端服务返回的错误。如果有错误，那么默认后面的Protobuf就没有了，除非另有约定
#define SERVER_MSG_HEADER_EX_LEN(d) (*(uint8_t*)((d) + SERVER_MSG_AFTER_TYPE_POS + 1))
#define SERVER_MSG_RESERVED(d) (*(uint16_t*)((d) + SERVER_MSG_AFTER_TYPE_POS + 2))
#define SERVER_MSG_HEADER_BASE_SIZE (SERVER_MSG_AFTER_TYPE_POS + 4)
#define SERVER_MSG_AFTER_HEADER_BASE(d) ((d) + SERVER_MSG_HEADER_BASE_SIZE)
#define SERVER_MSG_DATA(d) ((d) + SERVER_MSG_HEADER_BASE_SIZE + SERVER_MSG_HEADER_EX_LEN(d))
#define SERVER_MSG_DATA_LEN(d) (SERVER_MSG_LENGTH(d) - SERVER_MSG_HEADER_BASE_SIZE - SERVER_MSG_HEADER_EX_LEN(d))

#endif