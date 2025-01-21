#include "transform.h"
#include "sdptransform.hpp"
#include <iostream>

char *sdptransform_write(const char *json) {
    try {
        auto sdp = sdptransform::parse(json);
        return strdup(sdptransform::write(sdp).c_str());
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

char *sdptransform_parse(const char *sdp) {
    try {
        return strdup(sdptransform::parse(sdp).dump().c_str());
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

char *sdptransform_parse_params(const char *params) {
    try {
        return strdup(sdptransform::parseParams(params).dump().c_str());
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return nullptr;
    }
}

int spdctransform_parse_payloads(const char *payloads, int *payloads_out, int payloads_size) {
    try {
        std::vector<int> ret = sdptransform::parsePayloads(payloads);
        if (ret.size() <= payloads_size) {
            memcpy(payloads_out, ret.data(), ret.size()*sizeof(int));
        }
        return ret.size();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}