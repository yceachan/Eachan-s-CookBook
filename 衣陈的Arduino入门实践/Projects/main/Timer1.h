extern void (*Timer1_callback) ();
void Timer1_setup(int hz);
ISR(TIMER1_COMPA_vect);
void Timeroff();
void Timer1on();