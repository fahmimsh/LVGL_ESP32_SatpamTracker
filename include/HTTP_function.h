#ifndef __HTTP_FUNCTION_H__
#define __HTTP_FUNCTION_H__

#ifdef __cplusplus
extern "C" {
#endif

#define HTTP_ABSEN "http://202.157.176.228/fahmi/api_absen.php?id=%zu"
#define HTTP_TUGAS "http://202.157.176.228/fahmi/api_tugas.php?nip=%zu"
#define HTTP_RUANG "http://202.157.176.228/fahmi/api_cekruang.php?rfid=%zu&status=%s"
#define HTTP_SUMMARY "http://202.157.176.228/fahmi/api_summary.php?nip=%zu"
#define HTTP_STATUS_RUANGAN "http://202.157.176.228/fahmi/api_data.php"

typedef struct {
    const char* nama_lokasi;
    const char* status;
} Lokasi_t;


const char* httpGETRequest(const char* serverName);
const char* httpGETLokasi();
uint16_t httpGETHistory(Lokasi_t *lokasi);

#ifdef __cplusplus
}
#endif

#endif