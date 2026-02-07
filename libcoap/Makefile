# Base library definitions
TOCK_USERLAND_BASE_DIR ?= ..
LIBNAME := libcoap

# This Makefile's directory, library is actually located in the `libcoap`
# submodule under this directory
$(LIBNAME)_DIR := $(TOCK_USERLAND_BASE_DIR)/$(LIBNAME)

$(LIBNAME)_COAP_SRC_DIR := $($(LIBNAME)_DIR)/$(LIBNAME)/src

# $($(LIBNAME)_COAP_SRC_DIR)/coap_proxy.c \
# $($(LIBNAME)_COAP_SRC_DIR)/coap_sha1.c \

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
	$($(LIBNAME)_COAP_SRC_DIR)/coap_tinydtls.c \
	$($(LIBNAME)_COAP_SRC_DIR)/coap_uri.c

# Build tinyDTLS for DTLS support
# NOTE: This could be done in a separate Makefile (I guess) but tinyDTLS is already a submodule
# of the `libcoap` repository...
$(LIBNAME)_TDTLS_SRC_DIR := $($(LIBNAME)_DIR)/$(LIBNAME)/ext/tinydtls

$(LIBNAME)_TDTLS_SRCS := \
	$($(LIBNAME)_TDTLS_SRC_DIR)/ccm.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/crypto.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/dtls.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/dtls_debug.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/dtls_prng.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/dtls_time.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/hmac.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/netq.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/peer.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/session.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/sha2/sha2.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/ecc/ecc.c \
	$($(LIBNAME)_TDTLS_SRC_DIR)/aes/rijndael.c

$(LIBNAME)_SRCS := $($(LIBNAME)_COAP_SRCS) $($(LIBNAME)_TDTLS_SRCS)

# Add include paths for libcoap

# Lwip headers
override CPPFLAGS += -I$(TOCK_USERLAND_BASE_DIR)/lwip/lwip/src/include
override CPPFLAGS += -I$(TOCK_USERLAND_BASE_DIR)/lwip/include
# Configuration for libcoap including specifying the lwip backend
override CPPFLAGS += -I$($(LIBNAME)_DIR)/include
# Public headers from the libcoap submodule
override CPPFLAGS += -I$($(LIBNAME)_DIR)/$(LIBNAME)/include
# Tiny DTLS headers
override CPPFLAGS += -I$($(LIBNAME)_DIR)/$(LIBNAME)/ext
override CPPFLAGS += -I$($(LIBNAME)_TDTLS_SRC_DIR)
override CPPFLAGS += -I$($(LIBNAME)_TDTLS_SRC_DIR)/sha2
override CPPFLAGS += -I$($(LIBNAME)_TDTLS_SRC_DIR)/ecc
override CPPFLAGS += -I$($(LIBNAME)_TDTLS_SRC_DIR)/aes

# Avoid failing in CI due to warnings in the library.
override CPPFLAGS_$(LIBNAME) += -Wno-error

# Include config for Tiny DTLS
override CFLAGS += -include $($(LIBNAME)_DIR)/include/coap_config.h

# Include the rules to build the library
include $(TOCK_USERLAND_BASE_DIR)/TockLibrary.mk
