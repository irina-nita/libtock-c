#ifndef COAP_CONFIG_H_
#define COAP_CONFIG_H_

#include <lwip/opt.h>
#include <lwip/debug.h>
#include <lwip/def.h>
#include <stdlib.h>

#define WITH_LWIP 1
#define NO_SYS 1
#define LWIP_RAND() ((uint32_t)rand())

/* Define to 1 if libcoap supports client mode code. */
#define COAP_CLIENT_SUPPORT 1

/* Define to 1 if libcoap supports server mode code. */
#define COAP_SERVER_SUPPORT 0

#if LWIP_IPV4
#define COAP_IPV4_SUPPORT 1
#endif /* LWIP_IPV4 */

#if LWIP_IPV6
#define COAP_IPV6_SUPPORT 1
#endif /* LWIP_IPV6 */

#ifndef COAP_CONSTRAINED_STACK
/* Define to 1 to minimize stack usage. */
#define COAP_CONSTRAINED_STACK 1
#endif

#define COAP_DISABLE_TCP 0

/* Similar to how Contiki handles mutexes */
#define _DTLS_MUTEX_H_
typedef int dtls_mutex_t;
#define DTLS_MUTEX_INITIALIZER 0
#define dtls_mutex_lock(a) *(a) = 1
#define dtls_mutex_trylock(a) *(a) = 1
#define dtls_mutex_unlock(a) *(a) = 0

#define LOCK_TCPIP_CORE()
#define UNLOCK_TCPIP_CORE()

#ifndef COAP_ASYNC_SUPPORT
/* Define to 1 to build with support for async separate responses. */
#define COAP_ASYNC_SUPPORT 1
#endif

#ifndef COAP_WITH_OBSERVE_PERSIST
/* Define to 1 to build support for persisting observes. */
#define COAP_WITH_OBSERVE_PERSIST 0
#endif

#ifndef COAP_WS_SUPPORT
/* Define to 1 to build with WebSockets support. */
#define COAP_WS_SUPPORT 0
#endif

#ifndef COAP_Q_BLOCK_SUPPORT
/* Define to 1 to build with Q-Block (RFC9177) support. */
#define COAP_Q_BLOCK_SUPPORT 0
#endif

#ifndef COAP_THREAD_SAFE
/* Define to 1 if libcoap has thread safe support. */
#define COAP_THREAD_SAFE 0
#endif

#ifndef COAP_THREAD_RECURSIVE_CHECK
/* Define to 1 to build with thread recursive lock detection support. */
#define COAP_THREAD_RECURSIVE_CHECK 0
#endif

#ifndef PACKAGE_NAME
/* Define to the full name of this package. */
#define PACKAGE_NAME "libcoap"
#endif /* PACKAGE_NAME */

#ifndef PACKAGE_STRING
/* Define to the full name and version of this package. */
#define PACKAGE_STRING "libcoap 4.3.5"
#endif /* PACKAGE_STRING */

#ifndef PACKAGE_VERSION
/* Define to the version of this package. */
#define PACKAGE_VERSION "4.3.5"
#endif /* PACKAGE_VERSION */

#ifndef assert
#define assert(x) LWIP_ASSERT("CoAP assert failed", x)
#endif /* assert */

/* Standard library features */
#define HAVE_STRNLEN 1
#define HAVE_LIMITS_H 1
#define HAVE_SNPRINTF 1
#define HAVE_ERRNO_H 1
#define HAVE_RANDOM 1
#define HAVE_MALLOC 1
#define HAVE_SYS_TYPES_H 1

/* Enable TinyDTLS as the DTLS backend */
#define COAP_WITH_LIBTINYDTLS 1
#define DTLS_PSK
#define WITH_SHA256 1

/* Disable other DTLS backends */
#define COAP_WITH_LIBOPENSSL 0
#define COAP_WITH_LIBGNUTLS 0
#define COAP_WITH_LIBMBEDTLS 0
#define COAP_WITH_LIBWOLFSSL 0

#endif /* COAP_CONFIG_H_ */
