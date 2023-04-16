void Timer1_setup(int hz);
extern void (*Timer1_callback) ();
ISR(TIMER1_COMPA_vect);
unsigned long T1millis();
void Timeroff();
void Timer1on();