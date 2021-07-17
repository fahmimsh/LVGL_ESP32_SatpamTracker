#ifndef __HTTP_FUNCTION_H__
#define __HTTP_FUNCTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#define HTTP_ABSEN "http://202.157.176.228/fahmi/api_absen.php?id=%zu"
#define HTTP_TUGAS "http://202.157.176.228/fahmi/api_tugas.php?nip=%zu"
#define HTTP_RUANG "http://202.157.176.228/fahmi/api_cekruang.php?rfid=%zu&status=%zu"
#define HTTP_SUMMARY "http://202.157.176.228/fahmi/api_summary.php?nip=%zu"
#define HTTP_STATUS_RUANGAN "http://202.157.176.228/fahmi/api_data.php"

const char* httpGETRequest(const char* serverName);
const char* httpGETLokasi();

typedef struct {
    const char* nama_lokasi;
} Lokasi_t;

#ifdef __cplusplus
}
#endif

#endif