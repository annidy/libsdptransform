#ifndef TRANSFORM_H
#define TRANSFORM_H
#ifdef __cplusplus
extern "C" {
#endif

// caller free return char *
char *sdptransform_write(const char *json);

char *sdptransform_parse(const char *sdp);

char *sdptransform_parse_params(const char *params);

int spdctransform_parse_payloads(const char *payloads, int *payloads_out, int payloads_size);

#ifdef __cplusplus
}
#endif
#endif // TRANSFORM_H