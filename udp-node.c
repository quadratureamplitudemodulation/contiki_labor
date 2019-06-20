#include "contiki.h"
#include "contiki-net.h"
#include "servreg-hack.h"
#include "simple-udp.h"
#include "net/ip/uip-debug.h"
#include "dev/button-sensor.h"
#include "dev/leds.h"
#include "net/rpl/rpl.h"

static uip_ipaddr_t *set_global_address(void);

/***************************************************************************************************
 * 1. TO-DO: Sinnvolle Portnummern für UDP definieren
 ***************************************************************************************************/
#define
#define

/***************************************************************************************************
 * 2. TO-DO: Makros für Service ID (eigene und Target) anlegen
 ***************************************************************************************************/
#define
#define


PROCESS(init_system_proc, "Init system process");
AUTOSTART_PROCESSES(&init_system_proc);

/***************************************************************************************************
 * 10. TO-DO: Parameterliste für UDP Receive Int Handler anlegen
 ***************************************************************************************************/

void cb_receive_udp() {
	leds_toggle(LEDS_ALL);
}

PROCESS_THREAD(init_system_proc, ev, data){
        PROCESS_BEGIN();

		static uip_ipaddr_t *ip_addr;											// IP Address of this device
        static uip_ipaddr_t *ip_dest_p;											// Can be used to store the IP Address of a destination

/***************************************************************************************************
* 3. TO-DO: Eigene IP-Adresse anlegen
***************************************************************************************************/
		ip_addr =

/***************************************************************************************************
* 4. TO-DO: Device in RPL als Leaf definieren
***************************************************************************************************/
        rpl_set_mode

/***************************************************************************************************
* 5. TO-DO: Einen Service bereitstellen
***************************************************************************************************/
		servreg_hack_

/***************************************************************************************************
* 6. TO-DO: UDP-Socket registrieren
***************************************************************************************************/
        simple_udp_
        button_init(&init_system_proc);
		leds_init();

        while (1) {
/***************************************************************************************************
* 7. TO-DO: Prozess unterbrechen, bis der Button gedrückt wurde
***************************************************************************************************/
        	PROCESS_
/***************************************************************************************************
*8. TO-DO: Über Target-ID IP-Adresse finden
***************************************************************************************************/
        	servreg_
/***************************************************************************************************
*9. TO-DO: UDP-Paket versenden
***************************************************************************************************/
        	simple_udp_

        }
        PROCESS_END();
}

/**
 *@brief Set global IPv6 Address
 *
 *Create an IPv6 address based on the MAC address of the device. Modified based on several Contiki examples.
 *@return Global IPv6 address as calculated by the function.
 */
static uip_ipaddr_t *set_global_address(void)
{
  static uip_ipaddr_t ipaddr;

  uip_ip6addr(&ipaddr, UIP_DS6_DEFAULT_PREFIX, 0, 0, 0, 0, 0, 0, 0);
  uip_ds6_set_addr_iid(&ipaddr, &uip_lladdr);
  uip_ds6_addr_add(&ipaddr, 0, ADDR_AUTOCONF);

  return &ipaddr;
}
