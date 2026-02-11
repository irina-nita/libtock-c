# Base library definitions
TOCK_USERLAND_BASE_DIR ?= ..
LIBNAME := libcoap

# This Makefile's directory, library is actually located in the `libcoap`
# submodule under this directory
$(LIBNAME)_DIR := $(TOCK_USERLAND_BASE_DIR)/$(LIBNAME)

$(LIBNAME)_COAP_SRC_DIR := $($(LIBNAME)_DIR)/$(LIBNAME)/src

$(LIBNAME)_COAP_SRCS := \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_address.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_asn1.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_async.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_block.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_cache.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_debug.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_dgrm_lwip.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_dtls.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_encode.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_event.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_hashkey.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_io.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_io_lwip.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_layers.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_mem.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_mbedtls.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_net.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_netif.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_option.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_pdu.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_prng.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_resource.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_session.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_str.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_strm_lwip.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_subscribe.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_threadsafe.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_time.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_uri.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_ws.c

$(LIBNAME)_MBEDTLS_DIR := $(TOCK_USERLAND_BASE_DIR)/libopenthread/libmbedtls
$(LIBNAME)_MBEDTLS_SRC_ROOT := $(TOCK_USERLAND_BASE_DIR)/libopenthread/openthread/third_party/mbedtls

# List all C and Assembly files
$(LIBNAME)_MBEDTLS_SRCS  += $(wildcard $($(LIBNAME)_MBEDTLS_SRC_ROOT)/repo/library/*.c)

$(LIBNAME)_SRCS := $($(LIBNAME)_COAP_SRCS) $($(LIBNAME)_MBEDTLS_SRCS)

# Add include paths for libcoap

# Lwip headers
override CPPFLAGS += -I$(TOCK_USERLAND_BASE_DIR)/lwip/lwip/src/include
override CPPFLAGS += -I$(TOCK_USERLAND_BASE_DIR)/lwip/include
# Configuration for libcoap including specifying the lwip backend
override CPPFLAGS += -I$($(LIBNAME)_DIR)/include
# Public headers from the libcoap submodule
override CPPFLAGS += -I$($(LIBNAME)_DIR)/$(LIBNAME)/include

# MbedTLS headers
override CPPFLAGS += -I$($(LIBNAME)_MBEDTLS_SRC_ROOT)/../../src/core
override CPPFLAGS += -I$($(LIBNAME)_MBEDTLS_SRC_ROOT)/../../include
override CPPFLAGS += -I$($(LIBNAME)_MBEDTLS_SRC_ROOT)/repo/include
override CPPFLAGS += -I$($(LIBNAME)_MBEDTLS_SRC_ROOT)
override CPPFLAGS += -I$($(LIBNAME)_MBEDTLS_DIR)

# Include the config file already existing in libtock-c
override CPPFLAGS += -DMBEDTLS_CONFIG_FILE=\"libtock-mbedtls-config.h\"

# Enable mbedtls modules required by libcoap's DTLS backend (coap_mbedtls.c)
# that are not enabled by the OpenThread mbedtls-config.h.
override CPPFLAGS += -DMBEDTLS_ERROR_C
override CPPFLAGS += -DMBEDTLS_SSL_COOKIE_C
override CPPFLAGS += -DMBEDTLS_DEBUG_C
override CPPFLAGS += -DMBEDTLS_SSL_SRV_C
override CPPFLAGS += -DMBEDTLS_VERSION_C

# Tock stub for the timing.h functions
$(LIBNAME)_SRCS += $($(LIBNAME)_DIR)/mbedtls_timing.c

# Avoid failing in CI due to warnings in the library.
override CPPFLAGS_$(LIBNAME) += -Wno-error
override CPPFLAGS_$(LIBNAME) += -Wno-unused-macros -Wno-redundant-decls

# Avoid failing in CI due to warnings in the library.
override CPPFLAGS_$(LIBNAME) += -Wno-error
override CPPFLAGS_$(LIBNAME) += -Wno-unused-macros -Wno-redundant-decls

# Avoid failing in CI due to warnings in the library.
override CPPFLAGS_$(LIBNAME) += -Wno-error

# Include config
override CFLAGS += -include $($(LIBNAME)_DIR)/include/coap_config.h

# Include the rules to build the library
include $(TOCK_USERLAND_BASE_DIR)/TockLibrary.mk

