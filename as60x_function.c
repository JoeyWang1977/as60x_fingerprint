
#include "stdtypes.h"
#include "as60x.h"
#include "transport.h"

/// 1) PS_GetImage
#define PS_GetImage (0x01)
/// ? ָ����룺01H
/// ? ���ܣ���֤�û�ȡͼ��
/// 2) PS_GetEnrollImage
#define PS_GetEnrollImage (0x29)
/// ? ָ����룺29H
/// ? ���ܣ�ע���û�ȡͼ��
/// 3) PS_GenChar
#define PS_GenChar (0x02)
/// ? ָ����룺02H
/// ? ���ܣ�����ԭʼͼ������ָ���������������ļ�������
/// 4) PS_Match
#define PS_Match (0x03)
/// ? ָ����룺03H
/// ? ���ܣ���ȷ�ȶ������ļ��������е������ļ�
/// 5) PS_Search
#define PS_Search (0x04)
/// ? ָ����룺04H
/// ? ���ܣ��������ļ��������е������ļ����������򲿷�ָ�ƿ�
/// 6) PS_RegModel
#define PS_RegModel (0x05)
/// ? ָ����룺05H
/// ? ���ܣ��������ļ��ϲ�����ģ����������ļ�������
/// 7) PS_StoreChar
#define PS_StoreChar (0x06)
/// ? ָ����룺06H
/// ? ���ܣ��������������е��ļ����浽 flash ָ�ƿ���
/// 8) PS_LoadChar
#define PS_LoadChar (0x07)
/// ? ָ����룺07H
/// ? ���ܣ��� flash ָ�ƿ��ж�ȡһ��ģ�嵽����������
/// 9) PS_UpChar
#define PS_UpChar (0x08)
/// ? ָ����룺08H
/// ? ���ܣ��������������е��ļ��ϴ�����λ��
/// 10) PS_DownChar
#define PS_DownChar (0x09)
/// ? ָ����룺09H
/// ? ���ܣ�����λ������һ�������ļ�������������
/// 11) PS_UpImage
#define PS_UpImage (0x0a)
/// ? ָ����룺0aH
/// ? ���ܣ��ϴ�ԭʼͼ��
/// 12) PS_DownImage
#define PS_DownImage (0x0b)
/// ? ָ����룺0bH
/// ? ���ܣ�����ԭʼͼ��
/// 13) PS_DeletChar
#define PS_DeletChar (0x0c)
/// ? ָ����룺0cH
/// ? ���ܣ�ɾ�� flash ָ�ƿ��е�һ�������ļ�
/// 14) PS_Empty
#define PS_Empty (0x0d)
/// ? ָ����룺0dH
/// ? ���ܣ���� flash ָ�ƿ�
/// 15) PS_WriteReg
#define PS_WriteReg (0x0e)
/// ? ָ����룺0eH
/// ? ���ܣ�д SOC ϵͳ�Ĵ���
/// 16) PS_ReadSysPara
#define PS_ReadSysPara (0x0F)
/// ? ָ����룺0FH
/// ? ���ܣ���ϵͳ��������
/// 17) PS_AutoEnroll
#define PS_AutoEnroll (0x31)
/// ? ָ����룺31H
/// ? ���ܣ��Զ�ע��ģ��
/// 18) PS_AutoIdentify
#define PS_AutoIdentify (0x32)
/// ? ָ����룺32H
/// ? ���ܣ��Զ���ָ֤��
/// 19) PS_SetPwd
#define PS_SetPwd (0x12)
/// ? ָ����룺12H
/// ? ���ܣ������豸���ֿ���
/// 20) PS_VfyPwd
#define PS_VfyPwd (0x13)
/// ? ָ����룺13H
/// ? ���ܣ���֤�豸���ֿ���
/// 21) PS_GetRandomCode
#define PS_GetRandomCode (0x14)
/// ? ָ����룺14H
/// ? ���ܣ����������
/// 22) PS_SetChipAddr
#define PS_SetChipAddr (0x15)
/// ? ָ����룺15H
/// ? ���ܣ�����оƬ��ַ
/// 23) PS_ReadINFpage
#define PS_ReadINFpage (0x16)
/// ? ָ����룺16H
/// ? ���ܣ���ȡ FLASH Information Page ����
/// 24) PS_Port_Control
#define PS_Port_Control (0x17)
/// ? ָ����룺17H
/// ? ���ܣ�ͨѶ�˿ڣ�UART/USB�����ؿ���
/// 25) PS_WriteNotepad
#define PS_WriteNotepad (0x18)
/// ? ָ����룺18H
/// ? ���ܣ�д���±�
/// 26) PS_ReadNotepad
#define PS_ReadNotepad (0x19)
/// ? ָ����룺19H
/// ? ���ܣ������±�
/// 27) PS_BurnCode ��AS60x SOC ��ָ��Ϊ��дƬ�� FLASH ���룩
#define PS_BurnCode (0x1a)
/// ? ָ����룺1aH
/// ? ���ܣ���дƬ�� FLASH
/// 28) PS_HighSpeedSearch
#define PS_HighSpeedSearch (0x1b)
/// ? ָ����룺1bH
/// ? ���ܣ��������� FLASH
/// 29) PS_GenBinImage
#define PS_GenBinImage (0x1c)
/// ? ָ����룺1cH
/// ? ���ܣ����ɶ�ֵ��ָ��ͼ��
/// 30) PS_ValidTempleteNum
#define PS_ValidTempleteNum (0x1d)
/// ? ָ����룺1dH
/// ? ���ܣ�����Чģ�����
/// 31) PS_UserGPIOCommand
#define PS_UserGPIOCommand (0x1e)
/// ? ָ����룺1eH
/// ? ���ܣ��û� GPIO ��������
/// 32) PS_ReadIndexTable
#define PS_ReadIndexTable (0x1f)
/// ? ָ����룺1fH
/// ? ���ܣ���������
/// 33) PS_Cancle
#define PS_Cancle (0x30)
/// ? ָ����룺30H
/// ? ���ܣ�ȡ��ָ��
/// 34) PS_AutoEnroll
#define PS_AutoEnroll (0x31)
/// ? ָ����룺31H
/// ? ���ܣ��Զ�ע��ģ��ָ��
/// 35) PS_AutoIdentify
#define PS_AutoIdentify (0x32)
/// ? ָ����룺32H
/// ? ���ܣ��Զ���ָ֤��ָ��
/// 36) PS_Sleep
#define PS_Sleep (0x33)
/// ? ָ����룺33H
/// ? ���ܣ�����ָ��
/// 37) PS_GetChipSN
#define PS_GetChipSN (0x34)
/// ? ָ����룺34H
/// ? ���ܣ���ȡоƬΨһ���к�
/// 38) PS_HandShake
#define PS_HandShake (0x35)
/// ? ָ����룺35H
/// ? ���ܣ�����ָ��
/// 39) PS_CheckSensor
#define PS_CheckSensor (0x36)
/// ? ָ����룺36H
/// ? ���ܣ�У�鴫����

int32_t build_cmd_packet(
            as60x_cmd_packet_t *pkt,
            uint32_t dev_addr, uint8_t type, 
            uint8_t cmd, uint8_t *para, uint8_t para_len) {
    memset(pkt, 0, sizeof(as60x_cmd_packet_t));
    pkt->dev_addr = dev_addr;
    pkt->type = type;
    pkt->cmd = cmd;
    if(para && para_len>0) {
        pkt->cmd_para.data = para;
        pkt->cmd_para.len = para_len;
    }
    pkt->length = PKT_COMMAND_SIZE + para_len + PKT_CHKSUM_SIZE;
}

int32_t free_cmd_packet(as60x_cmd_packet_t *pkt) {
    if(pkt->cmd_para.data && pkt->cmd_para.len) {
        mem_free(pkt->cmd_para.data);
    }
    mem_free(pkt);
    return 0;
}

int32_t as60x_ps_handshake() {
    as60x_cmd_packet_t *pkt;

    dbg_printf("as60x_ps_handshake\n");
    pkt = mem_alloc(sizeof(as60x_cmd_packet_t));
    if(pkt) {
        build_cmd_packet(pkt, 
                AS60X_DEVICE_ADDR, 
                PACKET_TYPE_COMMAND, 
                PS_HandShake,
                NULL,
                0);
        as60x_transport_enqueue_pkt(pkt);
    }
}

int32_t as60x_ps_sleep() {
    as60x_cmd_packet_t *pkt;
    
    dbg_printf("as60x_ps_sleep\n");
    pkt = mem_alloc(sizeof(as60x_cmd_packet_t));
    if(pkt) {
        build_cmd_packet(pkt, 
                AS60X_DEVICE_ADDR, 
                PACKET_TYPE_COMMAND, 
                PS_Sleep,
                NULL,
                0);
        as60x_transport_enqueue_pkt(pkt);
    }
}

int32_t as60x_ps_set_addr(uint32_t addr) {
}

int32_t as60x_ps_auto_enroll(
            uint16_t pos,
            uint8_t num,
            uint8_t led,
            uint8_t prep,
            uint8_t allow_override,
            uint8_t disallow_dup,
            uint8_t non_leave
            ) {
    uint16_t para16;
    uint8_t *pkt_para;
    as60x_cmd_packet_t *pkt;

    dbg_printf("as60x_ps_auto_enroll %d %d %d %d %d %d %d\n",
        pos, num, led, prep, allow_override, allow_dup, leave);
    pkt = mem_alloc(sizeof(as60x_cmd_packet_t));
    if(pkt) {
        pkt_para = mem_alloc(5);
        if(!pkt_para) {
            dbg_printf("as60x_ps_auto_enroll alloc para failed!\n");
            return -2;
        }
        pkt_para[0] = pos>>8;
        pkt_para[1] = pos&0xFF;
        pkt_para[2] = num;
        para16 = (led&0x1) | (prep&0x1)<<1 | (0<<2) | (allow_override&0x1)<<3 |
                 (disallow_dup&0x1)<<4 | (non_leave&0x1)<<5;
        pkt_para[3] = para16>>8;
        pkt_para[4] = para16&0xFF;

        build_cmd_packet(pkt, 
                AS60X_DEVICE_ADDR, 
                PACKET_TYPE_COMMAND, 
                PS_AutoEnroll,
                pkt_para,
                5);
        as60x_transport_enqueue_pkt(pkt);
    } else {
        dbg_printf("as60x_ps_auto_enroll alloc packet failed!\n");
        return -1;
    }
}

int32_t as60x_ps_auto_identify(
            uint8_t sec_level,
            uint16_t pos,
            uint8_t led,
            uint8_t prep
            ) {
    uint16_t para16;
    uint8_t *pkt_para;
    as60x_cmd_packet_t *pkt;

    dbg_printf("as60x_ps_auto_identify %d %d %d %d\n", sec_level, pos, led, prep);
    pkt = mem_alloc(sizeof(as60x_cmd_packet_t));
    if(pkt) {
        pkt_para = mem_alloc(5);
        if(!pkt_para) {
            dbg_printf("as60x_ps_auto_identify alloc para failed!\n");
            return -2;
        }
        pkt_para[0] = sec_level;
        pkt_para[1] = pos>>8;
        pkt_para[2] = pos&0xFF;
        para16 = (led&0x1) | (prep&0x1)<<1 | (0<<2);
        pkt_para[3] = para16>>8;
        pkt_para[4] = para16&0xFF;

        build_cmd_packet(pkt, 
                AS60X_DEVICE_ADDR, 
                PACKET_TYPE_COMMAND, 
                PS_AutoIdentify,
                pkt_para,
                5);
        as60x_transport_enqueue_pkt(pkt);
    } else {
        dbg_printf("as60x_ps_auto_identify alloc packet failed!\n");
        return -1;
    }
}

