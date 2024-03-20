#include "mbed.h"
#define T 1000



class LED
{
public:
    DigitalOut m_pin;
    uint8_t m_jas_proc;     // nastav jas v %
    uint32_t m_T;          // T1 nebo T0, čas sviceni/nesviceni

    LED( PinName t_pin ) : m_pin( t_pin )
    {
    // inicializace instancnich promennych
    	m_jas_proc = 0;
    	m_T = 0;
    }

    void nastav_jas_proc( uint8_t t_jas_proc )
    {
        m_jas_proc = t_jas_proc;
        m_T = (m_jas_proc * T) / 100;
    }

    void set_on_off( uint32_t t_on_off ){   m_pin = t_on_off; }
};

class PWMControl
{
public:
    LED *mp_leds;             // pole rizenych LED
    uint32_t m_num_leds;      // pocet rizenych LED
    uint32_t m_ticks;         // aktualni cas periody T
    Ticker m_ticker;          // ridici Ticker

    PWMControl( LED *tp_leds, uint32_t t_num_leds )
    {
    // inicializace instancnich promennch
        m_ticker.attach(callback(this, &PWMControl::pridej_sam_sebe), 1ms);
    }

    void pwm_control()
    {
        // for ( pro_vsechny_LED )
    	for(uint32_t i = 0; i < m_num_leds; i++)
        {
            // if ( ma_nema_svitit_LED[ i ] )
                // mp_leds[ led ].set_on_off( ON/OFF );
    		if(m_ticks < mp_leds[i].m_T){
    			mp_leds[i].set_on_off(1);
    		}else{
    			mp_leds[i].set_on_off(0);
    		}
        }

    // rizeni m_ticks dle ukazky
    	m_ticks = (m_ticks + 1) % T;
    }
private:
    void pridej_sam_sebe(){
    	pwm_control();
    }
};


LED g_red_leds[] = {
			{ PTC0 },
			{ PTC1 }
	};
int main()
{

    g_red_leds[ 1 ].nastav_jas_proc( 5 );
    g_red_leds[ 2 ].nastav_jas_proc( 35 );

    PWMControl my_pwm( g_red_leds, 2 );

    while ( 1 ) __WFI();
};

